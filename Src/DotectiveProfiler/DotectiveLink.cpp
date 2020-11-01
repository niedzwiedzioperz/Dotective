#include "pch.h"
#include "DotectiveLink.h"
#include <thread>

#define BUFFER_SIZE 1048576
#define HEADER_SIZE 2 * sizeof(int)

DotectiveLink::DotectiveLink()
{
	hFileMap = NULL;
	pBuffer = NULL;
	pMessageBuffer = NULL;
	pWriteOffset = NULL;
	pReadOffset = NULL;
	writeOffset = BUFFER_SIZE;
	hPipe = NULL;
}

void DotectiveLink::Connect()
{
	hFileMap = OpenFileMapping(FILE_MAP_ALL_ACCESS, FALSE, L"Global\\DotectiveMemory");

	if (hFileMap != NULL)
	{
		pBuffer = (unsigned char*)MapViewOfFile(hFileMap, FILE_MAP_ALL_ACCESS, 0, 0, BUFFER_SIZE + HEADER_SIZE);
		if (pBuffer != NULL)
		{
			pMessageBuffer = pBuffer + HEADER_SIZE;
			pWriteOffset = (int*)pBuffer;
			pReadOffset = (int*)(pBuffer + sizeof(int));
			*pWriteOffset = BUFFER_SIZE;
			*pReadOffset = BUFFER_SIZE;
		}
	}

	hPipe = CreateFile(TEXT("\\\\.\\pipe\\DotectivePipe"), GENERIC_READ | GENERIC_WRITE, 0, NULL, OPEN_EXISTING, 0, NULL);
}

void DotectiveLink::Disconnect()
{
	if (pBuffer != NULL)
	{
		UnmapViewOfFile(pBuffer);
		pBuffer = NULL;
		pMessageBuffer = NULL;
		pWriteOffset = NULL;
		pReadOffset = NULL;
	}

	if (hFileMap != NULL)
	{
		CloseHandle(hFileMap);
		hFileMap = NULL;
	}

	if (hPipe != NULL)
	{
		CloseHandle(hPipe);
	}
}

void DotectiveLink::SendELT(void* buffer, int length)
{
	if (BUFFER_SIZE < length + writeOffset)
	{
		while (*pReadOffset < *pWriteOffset)
		{
			Sleep(0);
		}

		writeOffset = 0;
	}

	memcpy(pMessageBuffer + writeOffset, buffer, length);
	*pWriteOffset = writeOffset;

	writeOffset += length;
}

void DotectiveLink::Send(DotectiveMessage* message)
{
	int length = message->getLength();

	DWORD bytesWritten = 0;
	if (WriteFile(hPipe, &length, sizeof(int), &bytesWritten, NULL))
	{
		WriteFile(hPipe, message->getBuffer(), length, &bytesWritten, NULL);
	}
}

DotectiveMessage* DotectiveLink::Receive()
{
	DWORD bytesRead = 0;
	int length = 0;
	if (ReadFile(hPipe, &length, sizeof(int), &bytesRead, NULL))
	{
		auto message = DotectiveMessage::Create();
		if (length == 0)
		{
			return message;
		}

		if (ReadFile(hPipe, message->getBuffer(), length, &bytesRead, NULL))
		{
			message->addLength(length);

			return message;
		}
		else
		{
			message->Dispose();

			return NULL;
		}
	}
}