

/* this ALWAYS GENERATED file contains the definitions for the interfaces */


 /* File created by MIDL compiler version 8.01.0622 */
/* at Tue Jan 19 11:14:07 2038
 */
/* Compiler settings for IP2Location.idl:
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

#ifndef __IP2Location_h__
#define __IP2Location_h__

#if defined(_MSC_VER) && (_MSC_VER >= 1020)
#pragma once
#endif

/* Forward Declarations */ 

#ifndef __ICountry_FWD_DEFINED__
#define __ICountry_FWD_DEFINED__
typedef interface ICountry ICountry;

#endif 	/* __ICountry_FWD_DEFINED__ */


#ifndef __Country_FWD_DEFINED__
#define __Country_FWD_DEFINED__

#ifdef __cplusplus
typedef class Country Country;
#else
typedef struct Country Country;
#endif /* __cplusplus */

#endif 	/* __Country_FWD_DEFINED__ */


/* header files for imported files */
#include "oaidl.h"
#include "ocidl.h"

#ifdef __cplusplus
extern "C"{
#endif 


#ifndef __ICountry_INTERFACE_DEFINED__
#define __ICountry_INTERFACE_DEFINED__

/* interface ICountry */
/* [unique][helpstring][dual][uuid][object] */ 


EXTERN_C const IID IID_ICountry;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("B53BD908-F2EE-4EE7-9561-F265DCDF32DD")
    ICountry : public IDispatch
    {
    public:
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE LookUpShortName( 
            /* [in] */ BSTR ipaddr,
            /* [retval][out] */ BSTR *retval) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE LookUpLongName( 
            /* [in] */ BSTR ipaddr,
            /* [retval][out] */ BSTR *retval) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE LookUpFullName( 
            /* [in] */ BSTR ipaddr,
            /* [retval][out] */ BSTR *retval) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE CountryCodeToName( 
            /* [in] */ BSTR code,
            /* [retval][out] */ BSTR *retval) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE Initialize( 
            /* [in] */ BSTR regcode,
            /* [retval][out] */ BSTR *retval) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE Version( 
            /* [retval][out] */ BSTR *retval) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE LookUp( 
            /* [in] */ BSTR binpath,
            BSTR ipaddr,
            /* [retval][out] */ BSTR *retval) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_CountryShort( 
            /* [retval][out] */ BSTR *pVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_CountryLong( 
            /* [retval][out] */ BSTR *pVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_Region( 
            /* [retval][out] */ BSTR *pVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_City( 
            /* [retval][out] */ BSTR *pVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_Latitude( 
            /* [retval][out] */ BSTR *pVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_Longitude( 
            /* [retval][out] */ BSTR *pVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_ZIPCode( 
            /* [retval][out] */ BSTR *pVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_TimeZone( 
            /* [retval][out] */ BSTR *pVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_ISP( 
            /* [retval][out] */ BSTR *pVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_Domain( 
            /* [retval][out] */ BSTR *pVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_NetSpeed( 
            /* [retval][out] */ BSTR *pVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_IDDCode( 
            /* [retval][out] */ BSTR *pVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_AreaCode( 
            /* [retval][out] */ BSTR *pVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_WeatherStationCode( 
            /* [retval][out] */ BSTR *pVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_WeatherStationName( 
            /* [retval][out] */ BSTR *pVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_MCC( 
            /* [retval][out] */ BSTR *pVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_MNC( 
            /* [retval][out] */ BSTR *pVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_MobileBrand( 
            /* [retval][out] */ BSTR *pVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_Elevation( 
            /* [retval][out] */ BSTR *pVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_UsageType( 
            /* [retval][out] */ BSTR *pVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_IsRegistered( 
            /* [retval][out] */ VARIANT_BOOL *pVal) = 0;
        
    };
    
    
#else 	/* C style interface */

    typedef struct ICountryVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            ICountry * This,
            /* [in] */ REFIID riid,
            /* [annotation][iid_is][out] */ 
            _COM_Outptr_  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            ICountry * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            ICountry * This);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfoCount )( 
            ICountry * This,
            /* [out] */ UINT *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfo )( 
            ICountry * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo **ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetIDsOfNames )( 
            ICountry * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR *rgszNames,
            /* [range][in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE *Invoke )( 
            ICountry * This,
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
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *LookUpShortName )( 
            ICountry * This,
            /* [in] */ BSTR ipaddr,
            /* [retval][out] */ BSTR *retval);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *LookUpLongName )( 
            ICountry * This,
            /* [in] */ BSTR ipaddr,
            /* [retval][out] */ BSTR *retval);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *LookUpFullName )( 
            ICountry * This,
            /* [in] */ BSTR ipaddr,
            /* [retval][out] */ BSTR *retval);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *CountryCodeToName )( 
            ICountry * This,
            /* [in] */ BSTR code,
            /* [retval][out] */ BSTR *retval);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *Initialize )( 
            ICountry * This,
            /* [in] */ BSTR regcode,
            /* [retval][out] */ BSTR *retval);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *Version )( 
            ICountry * This,
            /* [retval][out] */ BSTR *retval);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *LookUp )( 
            ICountry * This,
            /* [in] */ BSTR binpath,
            BSTR ipaddr,
            /* [retval][out] */ BSTR *retval);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_CountryShort )( 
            ICountry * This,
            /* [retval][out] */ BSTR *pVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_CountryLong )( 
            ICountry * This,
            /* [retval][out] */ BSTR *pVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_Region )( 
            ICountry * This,
            /* [retval][out] */ BSTR *pVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_City )( 
            ICountry * This,
            /* [retval][out] */ BSTR *pVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_Latitude )( 
            ICountry * This,
            /* [retval][out] */ BSTR *pVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_Longitude )( 
            ICountry * This,
            /* [retval][out] */ BSTR *pVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_ZIPCode )( 
            ICountry * This,
            /* [retval][out] */ BSTR *pVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_TimeZone )( 
            ICountry * This,
            /* [retval][out] */ BSTR *pVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_ISP )( 
            ICountry * This,
            /* [retval][out] */ BSTR *pVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_Domain )( 
            ICountry * This,
            /* [retval][out] */ BSTR *pVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_NetSpeed )( 
            ICountry * This,
            /* [retval][out] */ BSTR *pVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_IDDCode )( 
            ICountry * This,
            /* [retval][out] */ BSTR *pVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_AreaCode )( 
            ICountry * This,
            /* [retval][out] */ BSTR *pVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_WeatherStationCode )( 
            ICountry * This,
            /* [retval][out] */ BSTR *pVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_WeatherStationName )( 
            ICountry * This,
            /* [retval][out] */ BSTR *pVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_MCC )( 
            ICountry * This,
            /* [retval][out] */ BSTR *pVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_MNC )( 
            ICountry * This,
            /* [retval][out] */ BSTR *pVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_MobileBrand )( 
            ICountry * This,
            /* [retval][out] */ BSTR *pVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_Elevation )( 
            ICountry * This,
            /* [retval][out] */ BSTR *pVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_UsageType )( 
            ICountry * This,
            /* [retval][out] */ BSTR *pVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_IsRegistered )( 
            ICountry * This,
            /* [retval][out] */ VARIANT_BOOL *pVal);
        
        END_INTERFACE
    } ICountryVtbl;

    interface ICountry
    {
        CONST_VTBL struct ICountryVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define ICountry_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define ICountry_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define ICountry_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define ICountry_GetTypeInfoCount(This,pctinfo)	\
    ( (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo) ) 

#define ICountry_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    ( (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo) ) 

#define ICountry_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    ( (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId) ) 

#define ICountry_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    ( (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr) ) 


#define ICountry_LookUpShortName(This,ipaddr,retval)	\
    ( (This)->lpVtbl -> LookUpShortName(This,ipaddr,retval) ) 

#define ICountry_LookUpLongName(This,ipaddr,retval)	\
    ( (This)->lpVtbl -> LookUpLongName(This,ipaddr,retval) ) 

#define ICountry_LookUpFullName(This,ipaddr,retval)	\
    ( (This)->lpVtbl -> LookUpFullName(This,ipaddr,retval) ) 

#define ICountry_CountryCodeToName(This,code,retval)	\
    ( (This)->lpVtbl -> CountryCodeToName(This,code,retval) ) 

#define ICountry_Initialize(This,regcode,retval)	\
    ( (This)->lpVtbl -> Initialize(This,regcode,retval) ) 

#define ICountry_Version(This,retval)	\
    ( (This)->lpVtbl -> Version(This,retval) ) 

#define ICountry_LookUp(This,binpath,ipaddr,retval)	\
    ( (This)->lpVtbl -> LookUp(This,binpath,ipaddr,retval) ) 

#define ICountry_get_CountryShort(This,pVal)	\
    ( (This)->lpVtbl -> get_CountryShort(This,pVal) ) 

#define ICountry_get_CountryLong(This,pVal)	\
    ( (This)->lpVtbl -> get_CountryLong(This,pVal) ) 

#define ICountry_get_Region(This,pVal)	\
    ( (This)->lpVtbl -> get_Region(This,pVal) ) 

#define ICountry_get_City(This,pVal)	\
    ( (This)->lpVtbl -> get_City(This,pVal) ) 

#define ICountry_get_Latitude(This,pVal)	\
    ( (This)->lpVtbl -> get_Latitude(This,pVal) ) 

#define ICountry_get_Longitude(This,pVal)	\
    ( (This)->lpVtbl -> get_Longitude(This,pVal) ) 

#define ICountry_get_ZIPCode(This,pVal)	\
    ( (This)->lpVtbl -> get_ZIPCode(This,pVal) ) 

#define ICountry_get_TimeZone(This,pVal)	\
    ( (This)->lpVtbl -> get_TimeZone(This,pVal) ) 

#define ICountry_get_ISP(This,pVal)	\
    ( (This)->lpVtbl -> get_ISP(This,pVal) ) 

#define ICountry_get_Domain(This,pVal)	\
    ( (This)->lpVtbl -> get_Domain(This,pVal) ) 

#define ICountry_get_NetSpeed(This,pVal)	\
    ( (This)->lpVtbl -> get_NetSpeed(This,pVal) ) 

#define ICountry_get_IDDCode(This,pVal)	\
    ( (This)->lpVtbl -> get_IDDCode(This,pVal) ) 

#define ICountry_get_AreaCode(This,pVal)	\
    ( (This)->lpVtbl -> get_AreaCode(This,pVal) ) 

#define ICountry_get_WeatherStationCode(This,pVal)	\
    ( (This)->lpVtbl -> get_WeatherStationCode(This,pVal) ) 

#define ICountry_get_WeatherStationName(This,pVal)	\
    ( (This)->lpVtbl -> get_WeatherStationName(This,pVal) ) 

#define ICountry_get_MCC(This,pVal)	\
    ( (This)->lpVtbl -> get_MCC(This,pVal) ) 

#define ICountry_get_MNC(This,pVal)	\
    ( (This)->lpVtbl -> get_MNC(This,pVal) ) 

#define ICountry_get_MobileBrand(This,pVal)	\
    ( (This)->lpVtbl -> get_MobileBrand(This,pVal) ) 

#define ICountry_get_Elevation(This,pVal)	\
    ( (This)->lpVtbl -> get_Elevation(This,pVal) ) 

#define ICountry_get_UsageType(This,pVal)	\
    ( (This)->lpVtbl -> get_UsageType(This,pVal) ) 

#define ICountry_get_IsRegistered(This,pVal)	\
    ( (This)->lpVtbl -> get_IsRegistered(This,pVal) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __ICountry_INTERFACE_DEFINED__ */



#ifndef __IP2LOCATIONLib_LIBRARY_DEFINED__
#define __IP2LOCATIONLib_LIBRARY_DEFINED__

/* library IP2LOCATIONLib */
/* [helpstring][version][uuid] */ 


EXTERN_C const IID LIBID_IP2LOCATIONLib;

EXTERN_C const CLSID CLSID_Country;

#ifdef __cplusplus

class DECLSPEC_UUID("A3C8BFFA-1496-4188-A2BC-355A0B3DA0A7")
Country;
#endif
#endif /* __IP2LOCATIONLib_LIBRARY_DEFINED__ */

/* Additional Prototypes for ALL interfaces */

unsigned long             __RPC_USER  BSTR_UserSize(     unsigned long *, unsigned long            , BSTR * ); 
unsigned char * __RPC_USER  BSTR_UserMarshal(  unsigned long *, unsigned char *, BSTR * ); 
unsigned char * __RPC_USER  BSTR_UserUnmarshal(unsigned long *, unsigned char *, BSTR * ); 
void                      __RPC_USER  BSTR_UserFree(     unsigned long *, BSTR * ); 

unsigned long             __RPC_USER  BSTR_UserSize64(     unsigned long *, unsigned long            , BSTR * ); 
unsigned char * __RPC_USER  BSTR_UserMarshal64(  unsigned long *, unsigned char *, BSTR * ); 
unsigned char * __RPC_USER  BSTR_UserUnmarshal64(unsigned long *, unsigned char *, BSTR * ); 
void                      __RPC_USER  BSTR_UserFree64(     unsigned long *, BSTR * ); 

/* end of Additional Prototypes */

#ifdef __cplusplus
}
#endif

#endif


