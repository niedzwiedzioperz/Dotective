// DotectiveProfilerObject.cpp : Implementation of CDotectiveProfilerObject

#include "pch.h"
#include "DotectiveProfilerObject.h"
#define MESSAGE_HEADER_SIZE 1

// CDotectiveProfilerObject

HRESULT CDotectiveProfilerObject::FinalConstruct()
{
	dotectiveLink.Connect();

	return S_OK;
}

void CDotectiveProfilerObject::FinalRelease()
{
	dotectiveLink.Disconnect();
}

STDMETHODIMP CDotectiveProfilerObject::Initialize(IUnknown* pICorProfilerInfoUnk)
{
	HandleCallback(CallbackType::InitializeCallback, CreateCallbackMessage())->Dispose();

	return S_OK;
}

STDMETHODIMP CDotectiveProfilerObject::Shutdown()
{
	HandleCallback(CallbackType::ShutdownCallback, CreateCallbackMessage())->Dispose();

	return S_OK;
}

DotectiveMessage* CDotectiveProfilerObject::HandleCallback(CallbackType callbackType, DotectiveMessage* message)
{
	auto buffer = message->getBuffer();
	buffer[0] = (unsigned char)callbackType;

	dotectiveLink.Send(message);

	message->Dispose();

	return dotectiveLink.Receive();
}

DotectiveMessage* CDotectiveProfilerObject::CreateCallbackMessage()
{
	auto message = DotectiveMessage::Create();

	message->addLength(MESSAGE_HEADER_SIZE);

	return message;
}