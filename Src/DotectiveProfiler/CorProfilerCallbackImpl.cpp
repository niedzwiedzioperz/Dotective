#include "pch.h"
#include "CorProfilerCallbackImpl.h"

CorProfilerCallbackImpl::CorProfilerCallbackImpl()
{
}

STDMETHODIMP CorProfilerCallbackImpl::Initialize(IUnknown* pICorProfilerInfoUnk)
{
	return S_OK;
}

STDMETHODIMP CorProfilerCallbackImpl::Shutdown()
{
	return S_OK;
}

STDMETHODIMP CorProfilerCallbackImpl::AppDomainCreationStarted(AppDomainID appDomainID)
{
	return S_OK;
}

STDMETHODIMP CorProfilerCallbackImpl::AppDomainCreationFinished(AppDomainID appDomainID, HRESULT hrStatus)
{
	return S_OK;
}

STDMETHODIMP CorProfilerCallbackImpl::AppDomainShutdownStarted(AppDomainID appDomainID)
{
	return S_OK;
}

STDMETHODIMP CorProfilerCallbackImpl::AppDomainShutdownFinished(AppDomainID appDomainID, HRESULT hrStatus)
{
	return S_OK;
}

STDMETHODIMP CorProfilerCallbackImpl::AssemblyLoadStarted(AssemblyID assemblyID)
{
	return S_OK;
}

STDMETHODIMP CorProfilerCallbackImpl::AssemblyLoadFinished(AssemblyID assemblyID, HRESULT hrStatus)
{
	return S_OK;
}

STDMETHODIMP CorProfilerCallbackImpl::AssemblyUnloadStarted(AssemblyID assemblyID)
{
	return S_OK;
}

STDMETHODIMP CorProfilerCallbackImpl::AssemblyUnloadFinished(AssemblyID assemblyID, HRESULT hrStatus)
{
	return S_OK;
}

STDMETHODIMP CorProfilerCallbackImpl::ModuleLoadStarted(ModuleID moduleID)
{
	return S_OK;
}

STDMETHODIMP CorProfilerCallbackImpl::ModuleLoadFinished(ModuleID moduleID, HRESULT hrStatus)
{
	return S_OK;
}

STDMETHODIMP CorProfilerCallbackImpl::ModuleUnloadStarted(ModuleID moduleID)
{
	return S_OK;
}

STDMETHODIMP CorProfilerCallbackImpl::ModuleUnloadFinished(ModuleID moduleID, HRESULT hrStatus)
{
	return S_OK;
}

STDMETHODIMP CorProfilerCallbackImpl::ModuleAttachedToAssembly(ModuleID moduleID, AssemblyID assemblyID)
{
	return S_OK;
}

STDMETHODIMP CorProfilerCallbackImpl::ClassLoadStarted(ClassID classID)
{
	return S_OK;
}

STDMETHODIMP CorProfilerCallbackImpl::ClassLoadFinished(ClassID classID, HRESULT hrStatus)
{
	return S_OK;
}

STDMETHODIMP CorProfilerCallbackImpl::ClassUnloadStarted(ClassID classID)
{
	return S_OK;
}

STDMETHODIMP CorProfilerCallbackImpl::ClassUnloadFinished(ClassID classID, HRESULT hrStatus)
{
	return S_OK;
}

STDMETHODIMP CorProfilerCallbackImpl::FunctionUnloadStarted(FunctionID functionID)
{
	return S_OK;
}

STDMETHODIMP CorProfilerCallbackImpl::JITCompilationStarted(FunctionID functionID, BOOL fIsSafeToBlock)
{
	return S_OK;
}

STDMETHODIMP CorProfilerCallbackImpl::JITCompilationFinished(FunctionID functionID, HRESULT hrStatus, BOOL fIsSafeToBlock)
{
	return S_OK;
}

STDMETHODIMP CorProfilerCallbackImpl::JITCachedFunctionSearchStarted(FunctionID functionID, BOOL* pbUseCachedFunction)
{
	return S_OK;
}

STDMETHODIMP CorProfilerCallbackImpl::JITCachedFunctionSearchFinished(FunctionID functionID, COR_PRF_JIT_CACHE result)
{
	return S_OK;
}

STDMETHODIMP CorProfilerCallbackImpl::JITFunctionPitched(FunctionID functionID)
{
	return S_OK;
}

STDMETHODIMP CorProfilerCallbackImpl::JITInlining(FunctionID callerID, FunctionID calleeID, BOOL* pfShouldInline)
{
	return S_OK;
}

STDMETHODIMP CorProfilerCallbackImpl::ThreadCreated(ThreadID threadID)
{
	return S_OK;
}

STDMETHODIMP CorProfilerCallbackImpl::ThreadDestroyed(ThreadID threadID)
{
	return S_OK;
}

STDMETHODIMP CorProfilerCallbackImpl::ThreadAssignedToOSThread(ThreadID managedThreadID, DWORD osThreadID)
{
	return S_OK;
}

STDMETHODIMP CorProfilerCallbackImpl::RemotingClientInvocationStarted()
{
	return S_OK;
}

STDMETHODIMP CorProfilerCallbackImpl::RemotingClientSendingMessage(GUID* pCookie, BOOL fIsAsync)
{
	return S_OK;
}

STDMETHODIMP CorProfilerCallbackImpl::RemotingClientReceivingReply(GUID* pCookie, BOOL fIsAsync)
{
	return S_OK;
}

STDMETHODIMP CorProfilerCallbackImpl::RemotingClientInvocationFinished()
{
	return S_OK;
}

STDMETHODIMP CorProfilerCallbackImpl::RemotingServerReceivingMessage(GUID* pCookie, BOOL fIsAsync)
{
	return S_OK;
}

STDMETHODIMP CorProfilerCallbackImpl::RemotingServerInvocationStarted()
{
	return S_OK;
}

STDMETHODIMP CorProfilerCallbackImpl::RemotingServerInvocationReturned()
{
	return S_OK;
}

STDMETHODIMP CorProfilerCallbackImpl::RemotingServerSendingReply(GUID* pCookie, BOOL fIsAsync)
{
	return S_OK;
}

STDMETHODIMP CorProfilerCallbackImpl::UnmanagedToManagedTransition(FunctionID functionID, COR_PRF_TRANSITION_REASON reason)
{
	return S_OK;
}

STDMETHODIMP CorProfilerCallbackImpl::ManagedToUnmanagedTransition(FunctionID functionID, COR_PRF_TRANSITION_REASON reason)
{
	return S_OK;
}

STDMETHODIMP CorProfilerCallbackImpl::RuntimeSuspendStarted(COR_PRF_SUSPEND_REASON suspendReason)
{
	return S_OK;
}

STDMETHODIMP CorProfilerCallbackImpl::RuntimeSuspendFinished()
{
	return S_OK;
}

STDMETHODIMP CorProfilerCallbackImpl::RuntimeSuspendAborted()
{
	return S_OK;
}

STDMETHODIMP CorProfilerCallbackImpl::RuntimeResumeStarted()
{
	return S_OK;
}

STDMETHODIMP CorProfilerCallbackImpl::RuntimeResumeFinished()
{
	return S_OK;
}

STDMETHODIMP CorProfilerCallbackImpl::RuntimeThreadSuspended(ThreadID threadid)
{
	return S_OK;
}

STDMETHODIMP CorProfilerCallbackImpl::RuntimeThreadResumed(ThreadID threadid)
{
	return S_OK;
}

STDMETHODIMP CorProfilerCallbackImpl::MovedReferences(ULONG cmovedObjectIDRanges, ObjectID oldObjectIDRangeStart[], ObjectID newObjectIDRangeStart[], ULONG cObjectIDRangeLength[])
{
	return S_OK;
}

STDMETHODIMP CorProfilerCallbackImpl::ObjectAllocated(ObjectID objectID, ClassID classID)
{
	return S_OK;
}

STDMETHODIMP CorProfilerCallbackImpl::ObjectsAllocatedByClass(ULONG classCount, ClassID classIDs[], ULONG objects[])
{
	return S_OK;
}

STDMETHODIMP CorProfilerCallbackImpl::ObjectReferences(ObjectID objectID, ClassID classID, ULONG cObjectRefs, ObjectID objectRefIDs[])
{
	return S_OK;
}

STDMETHODIMP CorProfilerCallbackImpl::RootReferences(ULONG cRootRefs, ObjectID rootRefIDs[])
{
	return S_OK;
}

STDMETHODIMP CorProfilerCallbackImpl::ExceptionThrown(ObjectID thrownObjectID)
{
	return S_OK;
}

STDMETHODIMP CorProfilerCallbackImpl::ExceptionSearchFunctionEnter(FunctionID functionID)
{
	return S_OK;
}

STDMETHODIMP CorProfilerCallbackImpl::ExceptionSearchFunctionLeave()
{
	return S_OK;
}

STDMETHODIMP CorProfilerCallbackImpl::ExceptionSearchFilterEnter(FunctionID functionID)
{
	return S_OK;
}

STDMETHODIMP CorProfilerCallbackImpl::ExceptionSearchFilterLeave()
{
	return S_OK;
}

STDMETHODIMP CorProfilerCallbackImpl::ExceptionSearchCatcherFound(FunctionID functionID)
{
	return S_OK;
}

STDMETHODIMP CorProfilerCallbackImpl::ExceptionCLRCatcherFound()
{
	return S_OK;
}

STDMETHODIMP CorProfilerCallbackImpl::ExceptionCLRCatcherExecute()
{
	return S_OK;
}

STDMETHODIMP CorProfilerCallbackImpl::ExceptionOSHandlerEnter(FunctionID functionID)
{
	return S_OK;
}

STDMETHODIMP CorProfilerCallbackImpl::ExceptionOSHandlerLeave(FunctionID functionID)
{
	return S_OK;
}

STDMETHODIMP CorProfilerCallbackImpl::ExceptionUnwindFunctionEnter(FunctionID functionID)
{
	return S_OK;
}

STDMETHODIMP CorProfilerCallbackImpl::ExceptionUnwindFunctionLeave()
{
	return S_OK;
}

STDMETHODIMP CorProfilerCallbackImpl::ExceptionUnwindFinallyEnter(FunctionID functionID)
{
	return S_OK;
}

STDMETHODIMP CorProfilerCallbackImpl::ExceptionUnwindFinallyLeave()
{
	return S_OK;
}

STDMETHODIMP CorProfilerCallbackImpl::ExceptionCatcherEnter(FunctionID functionID, ObjectID objectID)
{
	return S_OK;
}

STDMETHODIMP CorProfilerCallbackImpl::ExceptionCatcherLeave()
{
	return S_OK;
}

STDMETHODIMP CorProfilerCallbackImpl::COMClassicVTableCreated(ClassID wrappedClassID, REFGUID implementedIID, void* pVTable, ULONG cSlots)
{
	return S_OK;
}

STDMETHODIMP CorProfilerCallbackImpl::COMClassicVTableDestroyed(ClassID wrappedClassID, REFGUID implementedIID, void* pVTable)
{
	return S_OK;
}

STDMETHODIMP CorProfilerCallbackImpl::ThreadNameChanged(ThreadID threadId, ULONG cchName, WCHAR name[])
{
	return S_OK;
}

STDMETHODIMP CorProfilerCallbackImpl::GarbageCollectionStarted(int cGenerations, BOOL generationCollected[], COR_PRF_GC_REASON reason)
{
	return S_OK;
}

STDMETHODIMP CorProfilerCallbackImpl::SurvivingReferences(ULONG cSurvivingObjectIDRanges, ObjectID objectIDRangeStart[], ULONG cObjectIDRangeLength[])
{
	return S_OK;
}

STDMETHODIMP CorProfilerCallbackImpl::GarbageCollectionFinished()
{
	return S_OK;
}

STDMETHODIMP CorProfilerCallbackImpl::FinalizeableObjectQueued(DWORD finalizerFlags, ObjectID objectID)
{
	return S_OK;
}

STDMETHODIMP CorProfilerCallbackImpl::RootReferences2(ULONG cRootRefs, ObjectID rootRefIds[], COR_PRF_GC_ROOT_KIND rootKinds[], COR_PRF_GC_ROOT_FLAGS rootFlags[], UINT_PTR rootIds[])
{
	return S_OK;
}

STDMETHODIMP CorProfilerCallbackImpl::HandleCreated(GCHandleID handleId, ObjectID initialObjectId)
{
	return S_OK;
}

STDMETHODIMP CorProfilerCallbackImpl::HandleDestroyed(GCHandleID handleId)
{
	return S_OK;
}

STDMETHODIMP CorProfilerCallbackImpl::InitializeForAttach(IUnknown* pCorProfilerInfoUnk, void* pvClientData, UINT cbClientData)
{
	return S_OK;
}

STDMETHODIMP CorProfilerCallbackImpl::ProfilerAttachComplete()
{
	return S_OK;
}

STDMETHODIMP CorProfilerCallbackImpl::ProfilerDetachSucceeded()
{
	return S_OK;
}