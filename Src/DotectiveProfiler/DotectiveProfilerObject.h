// DotectiveProfilerObject.h : Declaration of the CDotectiveProfilerObject

#pragma once
#include "resource.h"       // main symbols



#include "DotectiveProfiler_i.h"
#include "CorProfilerCallbackImpl.h"
#include "DotectiveLink.h"
#include "DotectiveMessage.h"
#include "CallbackType.h"


#if defined(_WIN32_WCE) && !defined(_CE_DCOM) && !defined(_CE_ALLOW_SINGLE_THREADED_OBJECTS_IN_MTA)
#error "Single-threaded COM objects are not properly supported on Windows CE platform, such as the Windows Mobile platforms that do not include full DCOM support. Define _CE_ALLOW_SINGLE_THREADED_OBJECTS_IN_MTA to force ATL to support creating single-thread COM object's and allow use of it's single-threaded COM object implementations. The threading model in your rgs file was set to 'Free' as that is the only threading model supported in non DCOM Windows CE platforms."
#endif

using namespace ATL;


// CDotectiveProfilerObject

class ATL_NO_VTABLE CDotectiveProfilerObject :
	public CComObjectRootEx<CComSingleThreadModel>,
	public CComCoClass<CDotectiveProfilerObject, &CLSID_DotectiveProfilerObject>,
	public IDispatchImpl<IDotectiveProfilerObject, &IID_IDotectiveProfilerObject, &LIBID_DotectiveProfilerLib, /*wMajor =*/ 1, /*wMinor =*/ 0>,
	public CorProfilerCallbackImpl
{
private:
	DotectiveLink dotectiveLink;

public:
	CDotectiveProfilerObject()
	{
	}

DECLARE_REGISTRY_RESOURCEID(106)


BEGIN_COM_MAP(CDotectiveProfilerObject)
	COM_INTERFACE_ENTRY(IDotectiveProfilerObject)
	COM_INTERFACE_ENTRY(IDispatch)
	COM_INTERFACE_ENTRY(ICorProfilerCallback)
	COM_INTERFACE_ENTRY(ICorProfilerCallback2)
	COM_INTERFACE_ENTRY(ICorProfilerCallback3)
END_COM_MAP()



	DECLARE_PROTECT_FINAL_CONSTRUCT()

	HRESULT FinalConstruct();
	void FinalRelease();

public:

	STDMETHOD(Initialize)(IUnknown* pICorProfilerInfoUnk);
	STDMETHOD(Shutdown)();

private:
	DotectiveMessage* HandleCallback(CallbackType callbackType, DotectiveMessage* message);
	DotectiveMessage* CreateCallbackMessage();
};

OBJECT_ENTRY_AUTO(__uuidof(DotectiveProfilerObject), CDotectiveProfilerObject)
