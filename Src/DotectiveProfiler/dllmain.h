// dllmain.h : Declaration of module class.

class CDotectiveProfilerModule : public ATL::CAtlDllModuleT< CDotectiveProfilerModule >
{
public :
	DECLARE_LIBID(LIBID_DotectiveProfilerLib)
	DECLARE_REGISTRY_APPID_RESOURCEID(IDR_DOTECTIVEPROFILER, "{15aa8c6f-ef6b-45fe-9142-25907eeb0370}")
};

extern class CDotectiveProfilerModule _AtlModule;
