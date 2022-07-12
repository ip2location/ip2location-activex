#pragma warning(disable : 4996)

#ifndef __COUNTRY_H_
#define __COUNTRY_H_
#define INVALID_PROCEDURE "Please execute LookUp() method to initialize this property"
#define INVALID_DBPATH "Failed to open IP2Location database"
#include "IP2Location.h"
#include "resource.h"       // main symbols
#include "IP2LocationCom.h"

class ATL_NO_VTABLE CCountry :
	public CComObjectRootEx<CComMultiThreadModel>,
	public CComCoClass<CCountry, &CLSID_Country>,
	public ISupportErrorInfo,
	public IDispatchImpl<ICountry, &IID_ICountry, &LIBID_IP2LOCATIONLib>
{
private:

	bool registered;
	FILE* m_fLogger;
	char* GetCodeByIPAddress(BSTR ipaddr, short mode);
	unsigned long GetIPNoByIPAddress(BSTR ipaddr);
	char* GetFullNameByCode(BSTR code);
	char* GetAuthorization(BSTR code);
	bool ProcessIP(IP2LocationRecord** record, char* IP);
	void doLogging(char* Message);
	IP2Location* m_IP2LocationObj;
	char* m_pIPDBPath;
	char m_CountryShort[3];
	char m_CountryLong[256];
	char m_Region[256];
	char m_City[256];
	char m_Latitude[256];
	char m_Longitude[256];
	char m_ZIPCode[256];
	char m_TimeZone[256];
	char m_ISP[256];
	char m_Domain[256];
	char m_NetSpeed[256];
	char m_IDDCode[256];
	char m_AreaCode[256];
	char m_WeatherStationCode[256];
	char m_WeatherStationName[256];
	char m_MCC[256];
	char m_MNC[256];
	char m_MobileBrand[256];
	char m_Elevation[256];
	char m_UsageType[256];
	char m_AddressType[2];
	char m_Category[256];
	char m_Message[1024];

public:
	CCountry()
	{
		registered = true; // license not required anymore
		strcpy(m_CountryShort, INVALID_PROCEDURE);
		strcpy(m_CountryLong, INVALID_PROCEDURE);
		strcpy(m_Region, INVALID_PROCEDURE);
		strcpy(m_City, INVALID_PROCEDURE);
		strcpy(m_Latitude, INVALID_PROCEDURE);
		strcpy(m_Longitude, INVALID_PROCEDURE);
		strcpy(m_ZIPCode, INVALID_PROCEDURE);
		strcpy(m_TimeZone, INVALID_PROCEDURE);
		strcpy(m_ISP, INVALID_PROCEDURE);
		strcpy(m_Domain, INVALID_PROCEDURE);
		strcpy(m_NetSpeed, INVALID_PROCEDURE);
		strcpy(m_IDDCode, INVALID_PROCEDURE);
		strcpy(m_AreaCode, INVALID_PROCEDURE);
		strcpy(m_WeatherStationCode, INVALID_PROCEDURE);
		strcpy(m_WeatherStationName, INVALID_PROCEDURE);
		strcpy(m_MCC, INVALID_PROCEDURE);
		strcpy(m_MNC, INVALID_PROCEDURE);
		strcpy(m_MobileBrand, INVALID_PROCEDURE);
		strcpy(m_Elevation, INVALID_PROCEDURE);
		strcpy(m_UsageType, INVALID_PROCEDURE);
		strcpy(m_AddressType, INVALID_PROCEDURE);
		strcpy(m_Category, INVALID_PROCEDURE);
	}
	DECLARE_REGISTRY_RESOURCEID(IDR_COUNTRY)

	DECLARE_PROTECT_FINAL_CONSTRUCT()

	BEGIN_COM_MAP(CCountry)
		COM_INTERFACE_ENTRY(ICountry)
		COM_INTERFACE_ENTRY(IDispatch)
		COM_INTERFACE_ENTRY(ISupportErrorInfo)
	END_COM_MAP()

	// ISupportsErrorInfo
	STDMETHOD(InterfaceSupportsErrorInfo)(REFIID riid);

	// ICountry
public:
	STDMETHOD(Version)(/*[out, retval]*/ BSTR* retval);
	STDMETHOD(Initialize)(/*[in]*/ BSTR regcode, /*[out, retval]*/ BSTR* retval);
	STDMETHOD(CountryCodeToName)(/*[int]*/ BSTR code, /*[out,retval]*/ BSTR* retval);
	STDMETHOD(LookUpFullName)(/*[in]*/ BSTR ipaddr, /*[out,retval]*/ BSTR* retval);
	STDMETHOD(LookUpLongName)(/*[in]*/ BSTR ipaddr, /*[out,retval]*/ BSTR* retval);
	STDMETHOD(LookUpShortName)(/*[in]*/ BSTR ipaddr, /*[out,retval]*/ BSTR* retval);
	STDMETHOD(LookUp)(/*[in]*/ BSTR binpath, BSTR ipaddr, /*[out,retval]*/ BSTR* retval);
	STDMETHOD(get_CountryShort)(BSTR* pVal);
	STDMETHOD(get_CountryLong)(BSTR* pVal);
	STDMETHOD(get_Region)(BSTR* pVal);
	STDMETHOD(get_City)(BSTR* pVal);
	STDMETHOD(get_Latitude)(BSTR* pVal);
	STDMETHOD(get_Longitude)(BSTR* pVal);
	STDMETHOD(get_ZIPCode)(BSTR* pVal);
	STDMETHOD(get_TimeZone)(BSTR* pVal);
	STDMETHOD(get_ISP)(BSTR* pVal);
	STDMETHOD(get_Domain)(BSTR* pVal);
	STDMETHOD(get_NetSpeed)(BSTR* pVal);
	STDMETHOD(get_IDDCode)(BSTR* pVal);
	STDMETHOD(get_AreaCode)(BSTR* pVal);
	STDMETHOD(get_WeatherStationCode)(BSTR* pVal);
	STDMETHOD(get_WeatherStationName)(BSTR* pVal);
	STDMETHOD(get_MCC)(BSTR* pVal);
	STDMETHOD(get_MNC)(BSTR* pVal);
	STDMETHOD(get_MobileBrand)(BSTR* pVal);
	STDMETHOD(get_Elevation)(BSTR* pVal);
	STDMETHOD(get_UsageType)(BSTR* pVal);
	STDMETHOD(get_AddressType)(BSTR* pVal);
	STDMETHOD(get_Category)(BSTR* pVal);
	STDMETHOD(get_IsRegistered)(VARIANT_BOOL* pVal);
};

#endif //__COUNTRY_H_
