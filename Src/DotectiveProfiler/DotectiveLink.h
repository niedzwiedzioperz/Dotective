#pragma once

#include "DotectiveMessage.h"

class DotectiveLink
{
private:
	HANDLE hFileMap;
	unsigned char* pBuffer;
	unsigned char* pMessageBuffer;
	int* pWriteOffset;
	int writeOffset;
	int* pReadOffset;
	HANDLE hPipe;

public:
	DotectiveLink();
	void Connect();
	void Disconnect();

	void SendELT(void* message, int length);
	void Send(DotectiveMessage* message);
	DotectiveMessage* Receive();
};

