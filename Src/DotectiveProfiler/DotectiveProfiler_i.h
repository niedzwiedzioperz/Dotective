

/* this ALWAYS GENERATED file contains the definitions for the interfaces */


 /* File created by MIDL compiler version 8.01.0622 */
/* at Tue Jan 19 04:14:07 2038
 */
/* Compiler settings for DotectiveProfiler.idl:
    Oicf, W1, Zp8, env=Win32 (32b run), target_arch=X86 8.01.0622 
    protocol : dce , ms_ext, c_ext, robust
    error checks: allocation ref bounds_check enum stub_data 
    VC __declspec() decoration level: 
         __declspec(uuid()), __declspec(selectany), __declspec(novtable)
         DECLSPEC_UUID(), MIDL_INTERFACE()
*/
/* @@MIDL_FILE_HEADING(  ) */



/* verify that the <rpcndr.h> version is high enough to compile this file*/
#ifndef __REQUIRED_RPCNDR_H_VERSION__
#define __REQUIRED_RPCNDR_H_VERSION__ 500
#endif

#include "rpc.h"
#include "rpcndr.h"

#ifndef __RPCNDR_H_VERSION__
#error this stub requires an updated version of <rpcndr.h>
#endif /* __RPCNDR_H_VERSION__ */

#ifndef COM_NO_WINDOWS_H
#include "windows.h"
#include "ole2.h"
#endif /*COM_NO_WINDOWS_H*/

#ifndef __DotectiveProfiler_i_h__
#define __DotectiveProfiler_i_h__

#if defined(_MSC_VER) && (_MSC_VER >= 1020)
#pragma once
#endif

/* Forward Declarations */ 

#ifndef __IDotectiveProfilerObject_FWD_DEFINED__
#define __IDotectiveProfilerObject_FWD_DEFINED__
typedef interface IDotectiveProfilerObject IDotectiveProfilerObject;

#endif 	/* __IDotectiveProfilerObject_FWD_DEFINED__ */


#ifndef __DotectiveProfilerObject_FWD_DEFINED__
#define __DotectiveProfilerObject_FWD_DEFINED__

#ifdef __cplusplus
typedef class DotectiveProfilerObject DotectiveProfilerObject;
#else
typedef struct DotectiveProfilerObject DotectiveProfilerObject;
#endif /* __cplusplus */

#endif 	/* __DotectiveProfilerObject_FWD_DEFINED__ */


/* header files for imported files */
#include "oaidl.h"
#include "ocidl.h"
#include "shobjidl.h"

#ifdef __cplusplus
extern "C"{
#endif 


#ifndef __IDotectiveProfilerObject_INTERFACE_DEFINED__
#define __IDotectiveProfilerObject_INTERFACE_DEFINED__

/* interface IDotectiveProfilerObject */
/* [unique][nonextensible][dual][uuid][object] */ 


EXTERN_C const IID IID_IDotectiveProfilerObject;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("49bd1c5e-de09-4150-855e-3a2c55f6fd97")
    IDotectiveProfilerObject : public IDispatch
    {
    public:
    };
    
    
#else 	/* C style interface */

    typedef struct IDotectiveProfilerObjectVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IDotectiveProfilerObject * This,
            /* [in] */ REFIID riid,
            /* [annotation][iid_is][out] */ 
            _COM_Outptr_  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IDotectiveProfilerObject * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IDotectiveProfilerObject * This);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfoCount )( 
            IDotectiveProfilerObject * This,
            /* [out] */ UINT *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfo )( 
            IDotectiveProfilerObject * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo **ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetIDsOfNames )( 
            IDotectiveProfilerObject * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR *rgszNames,
            /* [range][in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE *Invoke )( 
            IDotectiveProfilerObject * This,
            /* [annotation][in] */ 
            _In_  DISPID dispIdMember,
            /* [annotation][in] */ 
            _In_  REFIID riid,
            /* [annotation][in] */ 
            _In_  LCID lcid,
            /* [annotation][in] */ 
            _In_  WORD wFlags,
            /* [annotation][out][in] */ 
            _In_  DISPPARAMS *pDispParams,
            /* [annotation][out] */ 
            _Out_opt_  VARIANT *pVarResult,
            /* [annotation][out] */ 
            _Out_opt_  EXCEPINFO *pExcepInfo,
            /* [annotation][out] */ 
            _Out_opt_  UINT *puArgErr);
        
        END_INTERFACE
    } IDotectiveProfilerObjectVtbl;

    interface IDotectiveProfilerObject
    {
        CONST_VTBL struct IDotectiveProfilerObjectVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IDotectiveProfilerObject_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define IDotectiveProfilerObject_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define IDotectiveProfilerObject_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define IDotectiveProfilerObject_GetTypeInfoCount(This,pctinfo)	\
    ( (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo) ) 

#define IDotectiveProfilerObject_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    ( (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo) ) 

#define IDotectiveProfilerObject_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    ( (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId) ) 

#define IDotectiveProfilerObject_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    ( (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr) ) 


#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __IDotectiveProfilerObject_INTERFACE_DEFINED__ */



#ifndef __DotectiveProfilerLib_LIBRARY_DEFINED__
#define __DotectiveProfilerLib_LIBRARY_DEFINED__

/* library DotectiveProfilerLib */
/* [version][uuid] */ 


EXTERN_C const IID LIBID_DotectiveProfilerLib;

EXTERN_C const CLSID CLSID_DotectiveProfilerObject;

#ifdef __cplusplus

class DECLSPEC_UUID("8bae2cc3-5f66-4981-82e8-e47ba7eb08bf")
DotectiveProfilerObject;
#endif
#endif /* __DotectiveProfilerLib_LIBRARY_DEFINED__ */

/* Additional Prototypes for ALL interfaces */

/* end of Additional Prototypes */

#ifdef __cplusplus
}
#endif

#endif


