#include "stdafx.h"
#include "IP2Location.h"
#include "Country.h"
#include "IPData.h"
#define DELAY 2500

#ifdef WIN32
#include <winsock2.h>
#include <ws2tcpip.h>
int inet_pton(int af, const char* src, void* dst) {
	struct sockaddr_storage ss;
	int size = sizeof(ss);
	char src_copy[INET6_ADDRSTRLEN + 1];
	WORD wVersionRequested;
	WSADATA wsaData;
	int err;
	int retval = 0;

	ZeroMemory(&ss, sizeof(ss));
	/* stupid non-const API */
	strncpy(src_copy, src, INET6_ADDRSTRLEN + 1);
	src_copy[INET6_ADDRSTRLEN] = 0;

	wVersionRequested = MAKEWORD(2, 2);

	// had error earlier in hosted COM when winsock didn't initialise itself so manually initialise here
	err = WSAStartup(wVersionRequested, &wsaData);
	if (err != 0) {
		/* Tell the user that we could not find a usable */
		/* Winsock DLL.                                  */
		//printf("WSAStartup failed with error: %d\n", err);
		return 0;
	}
	if (WSAStringToAddress(src_copy, af, NULL, (struct sockaddr*)&ss, &size) == 0) {
		switch (af) {
		case AF_INET:
			*(struct in_addr*)dst = ((struct sockaddr_in*)&ss)->sin_addr;
			retval = 1;
			break;
		case AF_INET6:
			*(struct in6_addr*)dst = ((struct sockaddr_in6*)&ss)->sin6_addr;
			retval = 1;
			break;
		}
	}
	WSACleanup();

	return retval;
}

#else
#include <stdint.h>
#include <strings.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#endif

STDMETHODIMP CCountry::InterfaceSupportsErrorInfo(REFIID riid)
{
	static const IID* arr[] = 
	{
		&IID_ICountry
	};
	for (int i=0; i < sizeof(arr) / sizeof(arr[0]); i++)
	{
		if (InlineIsEqualGUID(*arr[i],riid))
			return S_OK;
	}
	return S_FALSE;
}

STDMETHODIMP CCountry::LookUpShortName(BSTR ipaddr, BSTR *retval)
{
	//CComBSTR bstrResult(A2BSTR(CCountry::GetCodeByIPAddress(ipaddr,1)));
	CComBSTR bstrResult(CCountry::GetCodeByIPAddress(ipaddr,1));
	*retval = bstrResult.Detach();
	if (!registered) {
		Sleep(DELAY);
	}
	return S_OK;
}

STDMETHODIMP CCountry::LookUpLongName(BSTR ipaddr, BSTR *retval)
{
	//	CComBSTR bstrResult(A2BSTR(CCountry::GetCodeByIPAddress(ipaddr,2)));
	CComBSTR bstrResult(CCountry::GetCodeByIPAddress(ipaddr,2));
	*retval = bstrResult.Detach();
	if (!registered) {
		Sleep(DELAY);
	}
	return S_OK;
}

STDMETHODIMP CCountry::LookUpFullName(BSTR ipaddr, BSTR *retval)
{
	//CComBSTR bstrResult(A2BSTR(CCountry::GetCodeByIPAddress(ipaddr,2)));
	CComBSTR bstrResult(CCountry::GetCodeByIPAddress(ipaddr,2));
	*retval = bstrResult.Detach();
	if (!registered) {
		Sleep(DELAY);
	}
	return S_OK;
}

STDMETHODIMP CCountry::CountryCodeToName(BSTR code, BSTR *retval)
{
	//CComBSTR name(A2BSTR(CCountry::GetFullNameByCode(code)));
	CComBSTR name(CCountry::GetFullNameByCode(code));
	*retval = name.Detach();
	return S_OK;
}

STDMETHODIMP CCountry::Initialize(BSTR regcode, BSTR *retval)
{
	try {
		if(SysStringLen(regcode) > 100){
			CComBSTR bstrResult("ERROR");
			return S_FALSE;
		}

		CComBSTR ver(CCountry::GetAuthorization(regcode));
		*retval = ver.Detach();
		if (!registered) {
			Sleep(DELAY);
		}
	}
	catch (...)
	{
		//CComBSTR bstrResult(A2BSTR("ERROR"));
		CComBSTR bstrResult("ERROR");
		*retval = bstrResult.Detach();
	}
	return S_OK;
}

STDMETHODIMP CCountry::Version(BSTR *retval)
{
	CComBSTR ver(VERSION);
	*retval = ver.Detach();
	return S_OK;
}

STDMETHODIMP CCountry::LookUp(BSTR binpath, BSTR ipaddr, BSTR *retval)
{
	IP2LocationRecord * record = NULL;

	try {
		if(SysStringLen(binpath) > 255){
			CComBSTR bstrResult("ERROR");
			return S_FALSE;
		}

		if(SysStringLen(ipaddr) > 40){
			CComBSTR bstrResult("ERROR");
			return S_FALSE;
		}

		USES_CONVERSION;
		m_pIPDBPath = OLE2A(binpath);
		char* addr = OLE2A(ipaddr);

		m_IP2LocationObj = IP2Location_open(m_pIPDBPath);
		if (m_IP2LocationObj != NULL)
		{
			if (CCountry::ProcessIP(&record, addr))
			{
				strcpy(m_CountryShort, record->country_short);
				strcpy(m_CountryLong, record->country_long);
				strcpy(m_Region, record->region);
				strcpy(m_City, record->city);
				sprintf(m_Latitude,"%f", record->latitude);
				sprintf(m_Longitude,"%f", record->longitude);
				strcpy(m_ZIPCode, record->zipcode);
				strcpy(m_TimeZone, record->timezone);
				strcpy(m_ISP, record->isp);
				strcpy(m_Domain, record->domain);
				strcpy(m_NetSpeed, record->netspeed);
				strcpy(m_IDDCode, record->iddcode);
				strcpy(m_AreaCode, record->areacode);
				strcpy(m_WeatherStationCode, record->weatherstationcode);
				strcpy(m_WeatherStationName, record->weatherstationname);
				strcpy(m_MCC, record->mcc);
				strcpy(m_MNC, record->mnc);
				strcpy(m_MobileBrand, record->mobilebrand);
				sprintf(m_Elevation,"%f", record->elevation);
				strcpy(m_UsageType, record->usagetype);
			}
			IP2Location_close(m_IP2LocationObj);
			//CComBSTR bstrResult(A2BSTR("OK"));
			CComBSTR bstrResult("OK");
			*retval = bstrResult.Detach();
		}
		else
		{
			strcpy(m_CountryShort, INVALID_DBPATH);
			strcpy(m_CountryLong, INVALID_DBPATH);
			strcpy(m_Region, INVALID_DBPATH);
			strcpy(m_City, INVALID_DBPATH);
			strcpy(m_Latitude, INVALID_DBPATH);
			strcpy(m_Longitude, INVALID_DBPATH);
			strcpy(m_ZIPCode, INVALID_DBPATH);
			strcpy(m_TimeZone, INVALID_DBPATH);
			strcpy(m_ISP, INVALID_DBPATH);
			strcpy(m_Domain, INVALID_DBPATH);
			strcpy(m_NetSpeed, INVALID_DBPATH);
			strcpy(m_IDDCode, INVALID_DBPATH);
			strcpy(m_AreaCode, INVALID_DBPATH);
			strcpy(m_WeatherStationCode, INVALID_DBPATH);
			strcpy(m_WeatherStationName, INVALID_DBPATH);
			strcpy(m_MCC, INVALID_DBPATH);
			strcpy(m_MNC, INVALID_DBPATH);
			strcpy(m_MobileBrand, INVALID_DBPATH);
			strcpy(m_Elevation, INVALID_DBPATH);
			strcpy(m_UsageType, INVALID_DBPATH);

			sprintf(m_Message, "%s at %s.", INVALID_DBPATH, m_pIPDBPath);
			//CComBSTR bstrResult(A2BSTR(m_Message));
			CComBSTR bstrResult(m_Message);
			*retval = bstrResult.Detach();
		}

		if (!registered) {
			Sleep(DELAY);
		}
	}
	catch (...)
	{
		//CComBSTR bstrResult(A2BSTR("ERROR"));
		CComBSTR bstrResult("ERROR");
		*retval = bstrResult.Detach();
	}

	IP2Location_free_record(record);

	return S_OK;
}

bool CCountry::ProcessIP(IP2LocationRecord ** record, char* IP )
{
	if (m_IP2LocationObj != NULL)
	{
		*record = IP2Location_get_all(m_IP2LocationObj, IP);
		if (*record != NULL) {
			return true ;
		}
		else {
			return false;
		}	
	}
	return false;
}

char* CCountry::GetCodeByIPAddress(BSTR ipaddr, short mode)
{
	USES_CONVERSION;
	char* ipaddr2 = OLE2A(ipaddr);
	ipv_t parsed_ipv = parse_addr(ipaddr2);
	uint32_t low = 0;
	uint32_t mid = 0;
	uint32_t high = 0;
	
	if (parsed_ipv.ipversion == 4) {
		high = MAXRECORD;
		uint32_t ipno = parsed_ipv.ipv4;
		if (ipno == MAX_IPV4_RANGE) {
			return (char*) countrySHORT[ipcountry[MAXRECORD].co];
		}
		else {
			while (low <= high) {
				mid = (uint32_t)((low + high)/2);
				if ((ipno >= ipcountry[mid].ip) && (ipno < ipcountry[mid+1].ip)) {
					if (mode == 1) {
						return (char*) countrySHORT[ipcountry[mid].co];
					} else {
						return (char*) countryLONG[ipcountry[mid].co];
					}
				}
				else if (ipno < ipcountry[mid].ip) {
					high = mid - 1;
				}
				else {
					low = mid + 1;
				}
			}
		}
	}
	else if (parsed_ipv.ipversion == 6) {
		high = MAXRECORDIPV6;
		struct in6_addr_local ipno;
		struct in6_addr_local ipfrom;
		struct in6_addr_local ipto;
		struct in6_addr_local ipmax;
		ipno = parsed_ipv.ipv6;
		inet_pton(AF_INET6, "FFFF:FFFF:FFFF:FFFF:FFFF:FFFF:FFFF:FFFF", &ipmax);
		
		if (ipv6_compare(&ipno, &ipmax) == 0) {
			return (char*) countrySHORT[ipcountryIPv6[MAXRECORDIPV6].co];
		}
		else {
			while (low <= high) {
				mid = (uint32_t)((low + high)/2);
				// IPv6 from the data file should be in address form as a string so we can use inet_pton to get byte array
				inet_pton(AF_INET6, ipcountryIPv6[mid].ip, &ipfrom);
				inet_pton(AF_INET6, ipcountryIPv6[mid+1].ip, &ipto);
				if ((ipv6_compare(&ipno, &ipfrom) >= 0) && (ipv6_compare(&ipno, &ipto) < 0)) {
					if (mode == 1) {
						return (char*) countrySHORT[ipcountryIPv6[mid].co];
					}
					else {
						return (char*) countryLONG[ipcountryIPv6[mid].co];
					}
				} 
				else if (ipv6_compare(&ipno, &ipfrom) < 0) {
					high = mid - 1;
				}
				else {
					low = mid + 1;
				}
			}
		}
	}
	return (char*) countrySHORT[0];
}

unsigned long CCountry::GetIPNoByIPAddress(BSTR ipaddr)
{
	unsigned int i;
	char tok[4];
	unsigned int octet;
	int j = 0, k = 0;
	unsigned long ipnum = 0;
	char c = 0;
	USES_CONVERSION;
	char* addr = OLE2A(ipaddr);
	
	for (i=0; i<4; i++) {
		while (1) {
			c = (char) addr[k++];
			if (c == '.' || c == '\0') {
				tok[j] = '\0';
				octet = atoi(tok);
				if (octet > 255) {
					return -1;
				}
				ipnum += (octet << ((3-i)*8));
				j = 0;
				break;
			} else if (c >= '0' && c<= '9') {
				if (j > 2) {
					return -1;
				}
				tok[j++] = c;
			} else {
				return -1;
			}
		}
		if(c == '\0' && i<3) {
			return -1;
		}
	}
	return ipnum;
}


char* CCountry::GetFullNameByCode (BSTR code)
{
	int i = 0;

	USES_CONVERSION;
	for(i=1; i<=MAXCOUNTRY; i++)
	{
		if(!stricmp(OLE2A(code),countrySHORT[i])){
			return (char*) countryLONG[i];
		}
	}
	return (char*) countryLONG[0];
}

char* CCountry::GetAuthorization (BSTR code)
{
	// no longer needed but keep for legacy users
	CCountry::registered = true;
	return (char*) "OK";
}

void CCountry::doLogging( char * Message )
{
	m_fLogger = fopen("C:\\ActiveX.log" ,"a+");
	fprintf(m_fLogger, "%s\n", Message);
	fclose(m_fLogger);
}

STDMETHODIMP CCountry::get_CountryShort(BSTR* pVal)
{
	//CComBSTR bstrResult(A2BSTR(m_CountryShort));
	CComBSTR bstrResult(m_CountryShort);
	*pVal = bstrResult.Detach();
	return S_OK;
}

STDMETHODIMP CCountry::get_CountryLong(BSTR* pVal)
{
	//CComBSTR bstrResult(A2BSTR(m_CountryLong));
	CComBSTR bstrResult(m_CountryLong);
	*pVal = bstrResult.Detach();
	return S_OK;
}

STDMETHODIMP CCountry::get_Region(BSTR* pVal)
{
	//CComBSTR bstrResult(A2BSTR(m_Region));
	CComBSTR bstrResult(m_Region);
	*pVal = bstrResult.Detach();
	return S_OK;
}

STDMETHODIMP CCountry::get_City(BSTR* pVal)
{
	//CComBSTR bstrResult(A2BSTR(m_City));
	CComBSTR bstrResult(m_City);
	*pVal = bstrResult.Detach();
	return S_OK;
}

STDMETHODIMP CCountry::get_Latitude(BSTR* pVal)
{
	//CComBSTR bstrResult(A2BSTR(m_Latitude));
	CComBSTR bstrResult(m_Latitude);
	*pVal = bstrResult.Detach();
	return S_OK;
}

STDMETHODIMP CCountry::get_Longitude(BSTR* pVal)
{
	//CComBSTR bstrResult(A2BSTR(m_Longitude));
	CComBSTR bstrResult(m_Longitude);
	*pVal = bstrResult.Detach();
	return S_OK;
}

STDMETHODIMP CCountry::get_ZIPCode(BSTR* pVal)
{
	//CComBSTR bstrResult(A2BSTR(m_ZIPCode));
	CComBSTR bstrResult(m_ZIPCode);
	*pVal = bstrResult.Detach();
	return S_OK;
}

STDMETHODIMP CCountry::get_TimeZone(BSTR* pVal)
{
	//CComBSTR bstrResult(A2BSTR(m_TimeZone));
	CComBSTR bstrResult(m_TimeZone);
	*pVal = bstrResult.Detach();
	return S_OK;
}

STDMETHODIMP CCountry::get_ISP(BSTR* pVal)
{
	//CComBSTR bstrResult(A2BSTR(m_ISP));
	CComBSTR bstrResult(m_ISP);
	*pVal = bstrResult.Detach();
	return S_OK;
}

STDMETHODIMP CCountry::get_Domain(BSTR* pVal)
{
	//CComBSTR bstrResult(A2BSTR(m_Domain));
	CComBSTR bstrResult(m_Domain);
	*pVal = bstrResult.Detach();
	return S_OK;
}

STDMETHODIMP CCountry::get_NetSpeed(BSTR* pVal)
{
	//CComBSTR bstrResult(A2BSTR(m_NetSpeed));
	CComBSTR bstrResult(m_NetSpeed);
	*pVal = bstrResult.Detach();
	return S_OK;
}
STDMETHODIMP CCountry::get_IDDCode(BSTR* pVal)
{
	//CComBSTR bstrResult(A2BSTR(m_IDDCode));
	CComBSTR bstrResult(m_IDDCode);
	*pVal = bstrResult.Detach();
	return S_OK;
}
STDMETHODIMP CCountry::get_AreaCode(BSTR* pVal)
{
	//CComBSTR bstrResult(A2BSTR(m_AreaCode));
	CComBSTR bstrResult(m_AreaCode);
	*pVal = bstrResult.Detach();
	return S_OK;
}
STDMETHODIMP CCountry::get_WeatherStationCode(BSTR* pVal)
{
	//CComBSTR bstrResult(A2BSTR(m_WeatherStationCode));
	CComBSTR bstrResult(m_WeatherStationCode);
	*pVal = bstrResult.Detach();
	return S_OK;
}
STDMETHODIMP CCountry::get_WeatherStationName(BSTR* pVal)
{
	//CComBSTR bstrResult(A2BSTR(m_WeatherStationName));
	CComBSTR bstrResult(m_WeatherStationName);
	*pVal = bstrResult.Detach();
	return S_OK;
}
STDMETHODIMP CCountry::get_MCC(BSTR* pVal)
{
	//CComBSTR bstrResult(A2BSTR(m_MCC));
	CComBSTR bstrResult(m_MCC);
	*pVal = bstrResult.Detach();
	return S_OK;
}
STDMETHODIMP CCountry::get_MNC(BSTR* pVal)
{
	//CComBSTR bstrResult(A2BSTR(m_MNC));
	CComBSTR bstrResult(m_MNC);
	*pVal = bstrResult.Detach();
	return S_OK;
}
STDMETHODIMP CCountry::get_MobileBrand(BSTR* pVal)
{
	//CComBSTR bstrResult(A2BSTR(m_MobileBrand));
	CComBSTR bstrResult(m_MobileBrand);
	*pVal = bstrResult.Detach();
	return S_OK;
}
STDMETHODIMP CCountry::get_Elevation(BSTR* pVal)
{
	//CComBSTR bstrResult(A2BSTR(m_Elevation));
	CComBSTR bstrResult(m_Elevation);
	*pVal = bstrResult.Detach();
	return S_OK;
}
STDMETHODIMP CCountry::get_UsageType(BSTR* pVal)
{
	//CComBSTR bstrResult(A2BSTR(m_UsageType));
	CComBSTR bstrResult(m_UsageType);
	*pVal = bstrResult.Detach();
	return S_OK;
}
STDMETHODIMP CCountry::get_IsRegistered(VARIANT_BOOL* pVal)
{
	//*pVal = (VARIANT_BOOL) CCountry::registered;
	if (CCountry::registered) {
		*pVal = VARIANT_TRUE;
	}
	else {
		*pVal = VARIANT_FALSE;
	}
	return S_OK;
}
