#pragma once
#include <vector>

class DotectiveMessage
{
private:
	unsigned char* pBuffer;
	int offset;
	
private:
	DotectiveMessage();
	~DotectiveMessage();

public:
	int getLength();
	void addLength(int offset);
	unsigned char* getBuffer();

	void Write(void* buffer, int length);
	void Write(int value);
	void Write(unsigned char value);

	void Dispose();

	static DotectiveMessage* Create();
};

static std::vector<DotectiveMessage*> messagePool;
