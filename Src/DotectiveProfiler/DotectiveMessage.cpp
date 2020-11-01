#include "pch.h"
#include "DotectiveMessage.h"

#define MESSAGE_SIZE 10240

DotectiveMessage::DotectiveMessage()
{
	offset = 0;
	pBuffer = new unsigned char[MESSAGE_SIZE];
}

DotectiveMessage::~DotectiveMessage()
{
	delete[] pBuffer;
}

int DotectiveMessage::getLength()
{
	return offset;
}

void DotectiveMessage::addLength(int offset)
{
	this->offset += offset;
}

unsigned char* DotectiveMessage::getBuffer()
{
	return pBuffer;
}

void DotectiveMessage::Write(void* buffer, int length)
{
	memcpy(pBuffer + offset, buffer, length);

	offset += length;
}

void DotectiveMessage::Write(int value)
{
	*((int*)(pBuffer + offset)) = value;

	offset += sizeof(int);
}

void DotectiveMessage::Write(unsigned char value)
{
	*(pBuffer + offset) = value;

	offset += sizeof(unsigned char);
}

void DotectiveMessage::Dispose()
{
	offset = 0;
	messagePool.push_back(this);
}

DotectiveMessage* DotectiveMessage::Create()
{
	if (messagePool.size() == 0)
	{
		return new DotectiveMessage();
	}

	auto message = messagePool.back();

	messagePool.pop_back();

	return message;
}