#include "IP2LocationCom.h"

void writestuff( char * Message )
{
	FILE *f = fopen("C:\\ActiveX.log" ,"a+");
	fprintf(f, "%s\n", Message);
	fclose(f);
}

#ifdef WIN32
#include <winsock2.h>
#include <ws2tcpip.h>
#else
#include <stdint.h>
#include <strings.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#endif

#include <string.h>
//#include <stdio.h>
//#include <stdafx.h>

//#include "imath.h"

uint8_t COUNTRY_POSITION[25]             = {0, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2};
uint8_t REGION_POSITION[25]              = {0, 0, 0, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3};
uint8_t CITY_POSITION[25]                = {0, 0, 0, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4};
uint8_t ISP_POSITION[25]                 = {0, 0, 3, 0, 5, 0, 7, 5, 7, 0, 8, 0, 9, 0, 9, 0, 9, 0, 9, 7, 9, 0, 9, 7, 9};
uint8_t LATITUDE_POSITION[25]            = {0, 0, 0, 0, 0, 5, 5, 0, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5};
uint8_t LONGITUDE_POSITION[25]           = {0, 0, 0, 0, 0, 6, 6, 0, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6};
uint8_t DOMAIN_POSITION[25]              = {0, 0, 0, 0, 0, 0, 0, 6, 8, 0, 9, 0, 10,0, 10, 0, 10, 0, 10, 8, 10, 0, 10, 8, 10};
uint8_t ZIPCODE_POSITION[25]             = {0, 0, 0, 0, 0, 0, 0, 0, 0, 7, 7, 7, 7, 0, 7, 7, 7, 0, 7, 0, 7, 7, 7, 0, 7};
uint8_t TIMEZONE_POSITION[25]            = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 8, 8, 7, 8, 8, 8, 7, 8, 0, 8, 8, 8, 0, 8};
uint8_t NETSPEED_POSITION[25]            = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 8, 11,0, 11,8, 11, 0, 11, 0, 11, 0, 11};
uint8_t IDDCODE_POSITION[25]             = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 9, 12, 0, 12, 0, 12, 9, 12, 0, 12};
uint8_t AREACODE_POSITION[25]            = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 10 ,13 ,0, 13, 0, 13, 10, 13, 0, 13};
uint8_t WEATHERSTATIONCODE_POSITION[25]  = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 9, 14, 0, 14, 0, 14, 0, 14};
uint8_t WEATHERSTATIONNAME_POSITION[25]  = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 10, 15, 0, 15, 0, 15, 0, 15};
uint8_t MCC_POSITION[25]                 = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 9, 16, 0, 16, 9, 16};
uint8_t MNC_POSITION[25]                 = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 10,17, 0, 17, 10, 17};
uint8_t MOBILEBRAND_POSITION[25]         = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 11,18, 0, 18, 11, 18};
uint8_t ELEVATION_POSITION[25]           = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 11, 19, 0, 19};
uint8_t USAGETYPE_POSITION[25]           = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 12, 20};

IP2Location *IP2Location_open(char *db)
{
	FILE *f;
	IP2Location *loc;

	if ((f=fopen(db,"rb")) == NULL)
	{
		//printf("IP2Location library error in opening database %s.\n", db);
		return NULL;
	}

	loc = (IP2Location *) malloc(sizeof(IP2Location));
	memset(loc, 0, sizeof(IP2Location));

	loc->filehandle = f;

	IP2Location_initialize(loc);
	
	return loc;
}


uint32_t IP2Location_close(IP2Location *loc)
{
	if (loc->filehandle != NULL) {
		fclose(loc->filehandle);
	}
	if (loc != NULL) {
		free(loc);
	}
	return 0;
}

int IP2Location_initialize(IP2Location *loc)
{
    loc->databasetype   = IP2Location_read8(loc->filehandle, 1);
	loc->databasecolumn = IP2Location_read8(loc->filehandle, 2);
	loc->databaseyear    = IP2Location_read8(loc->filehandle, 3);
	loc->databasemonth  = IP2Location_read8(loc->filehandle, 4);
	loc->databaseday   = IP2Location_read8(loc->filehandle, 5);

	loc->databasecount  = IP2Location_read32(loc->filehandle, 6);
	loc->databaseaddr   = IP2Location_read32(loc->filehandle, 10);
	loc->ipversion      = IP2Location_read32(loc->filehandle, 14);

	loc->ipv4databasecount  = IP2Location_read32(loc->filehandle, 6);
	loc->ipv4databaseaddr   = IP2Location_read32(loc->filehandle, 10);
	loc->ipv6databasecount  = IP2Location_read32(loc->filehandle, 14);
	loc->ipv6databaseaddr   = IP2Location_read32(loc->filehandle, 18);

	loc->ipv4indexbaseaddr = IP2Location_read32(loc->filehandle, 22);
	loc->ipv6indexbaseaddr = IP2Location_read32(loc->filehandle, 26);

	return 0;
}

// Description: Compare to ipv6 address
int ipv6_compare(struct in6_addr_local *addr1, struct in6_addr_local *addr2)
{
	int i, ret = 0;
	for(i = 0 ; i < 16 ; i++ )
	{
		if (addr1->u.addr8[i] > addr2->u.addr8[i])
		{
			ret = 1;
			break;
		}
		else if (addr1->u.addr8[i] < addr2->u.addr8[i])
		{
			ret = -1;
			break;
		}
	}
	return ret;
}

// Parses IPv[46] addresses and returns both the version of address
// and binary address used for searching
// You can implement domain name lookup here as well
// ipversion will be -1 on error (or something other than 4 or 6)
ipv_t parse_addr(const char *addr) {
	ipv_t parsed;
	if (IP2Location_ip_is_ipv6((char *)addr)) {
		// Convert ::FFFF:x.y.z.w to IPv4
		// if (strlen(addr) > 7 &&
			// addr[0] == ':' &&
			// addr[1] == ':' &&
			// (addr[2] == 'F' || addr[2] == 'f') &&
			// (addr[3] == 'F' || addr[3] == 'f') &&
			// (addr[4] == 'F' || addr[4] == 'f') &&
			// (addr[5] == 'F' || addr[5] == 'f') &&
			// addr[6] == ':' && IP2Location_ip_is_ipv4((char *)addr + 7)) {
			// parsed.ipversion = 4;
			// parsed.ipv4 = IP2Location_ip2no((char *)addr + 7);
		// }
		// else {
			parsed.ipversion = 6;
			inet_pton(AF_INET6, addr, &parsed.ipv6);
			if (parsed.ipv6.u.addr8[0] == 0 && parsed.ipv6.u.addr8[1] == 0 && parsed.ipv6.u.addr8[2] == 0 &&
				parsed.ipv6.u.addr8[3] == 0 && parsed.ipv6.u.addr8[4] == 0 && parsed.ipv6.u.addr8[5] == 0 &&
				parsed.ipv6.u.addr8[6] == 0 && parsed.ipv6.u.addr8[7] == 0 && parsed.ipv6.u.addr8[8] == 0 &&
				parsed.ipv6.u.addr8[9] == 0 && parsed.ipv6.u.addr8[10] == 255 && parsed.ipv6.u.addr8[11] == 255)
			{
				// IPv4 address in IPv6 format (::ffff:0.0.0.0 or ::ffff:00:00)
				parsed.ipversion = 4;
				parsed.ipv4 = (parsed.ipv6.u.addr8[12] << 24) + (parsed.ipv6.u.addr8[13] << 16) + (parsed.ipv6.u.addr8[14] << 8) + parsed.ipv6.u.addr8[15];
			}
		// }
		
	}
	else if (IP2Location_ip_is_ipv4((char *)addr)) {
		parsed.ipversion = 4;
		parsed.ipv4 = IP2Location_ip2no((char *)addr);
	}
	else {
		parsed.ipversion = -1;
	}
	return parsed;
}

struct in6_addr_local IP2Location_readIPv6Address(FILE *handle, uint32_t position) 
{
	int i,j;
	struct in6_addr_local addr6;
	for( i = 0, j = 15; i < 16; i++, j-- )
	{
		addr6.u.addr8[i] = IP2Location_read8(handle, position + j);
	}
	return addr6; 
}

IP2LocationRecord *IP2Location_get_country_short(IP2Location *loc, char *ip)
{
	if (IP2Location_ip_is_ipv6(ip)) {
		return IP2Location_get_ipv6_record(loc, ip, COUNTRYSHORT);
	} else {
		return IP2Location_get_record(loc, ip, COUNTRYSHORT);
	}
}


IP2LocationRecord *IP2Location_get_country_long(IP2Location *loc, char *ip)
{
	if (IP2Location_ip_is_ipv6(ip)) {
		return IP2Location_get_ipv6_record(loc, ip, COUNTRYLONG);
	} else {
		return IP2Location_get_record(loc, ip, COUNTRYLONG);
	}
}


IP2LocationRecord *IP2Location_get_region(IP2Location *loc, char *ip)
{
	if (IP2Location_ip_is_ipv6(ip)) {
		return IP2Location_get_ipv6_record(loc, ip, REGION);
	} else {
		return IP2Location_get_record(loc, ip, REGION);
	}
}


IP2LocationRecord *IP2Location_get_city (IP2Location *loc, char *ip)
{
	if (IP2Location_ip_is_ipv6(ip)) {
		return IP2Location_get_ipv6_record(loc, ip, CITY);
	} else {
		return IP2Location_get_record(loc, ip, CITY);
	}
}


IP2LocationRecord *IP2Location_get_isp(IP2Location *loc, char *ip)
{
	if (IP2Location_ip_is_ipv6(ip)) {
		return IP2Location_get_ipv6_record(loc, ip, ISP);
	} else {
		return IP2Location_get_record(loc, ip, ISP);
	}
}


IP2LocationRecord *IP2Location_get_latitude(IP2Location *loc, char *ip)
{
	if (IP2Location_ip_is_ipv6(ip)) {
		return IP2Location_get_ipv6_record(loc, ip, LATITUDE);
	} else {
		return IP2Location_get_record(loc, ip, LATITUDE);
	}
}


IP2LocationRecord *IP2Location_get_longitude(IP2Location *loc, char *ip)
{
	if (IP2Location_ip_is_ipv6(ip)) {
		return IP2Location_get_ipv6_record(loc, ip, LONGITUDE);
	} else {
		return IP2Location_get_record(loc, ip, LONGITUDE);
	}
}


IP2LocationRecord *IP2Location_get_domain(IP2Location *loc, char *ip)
{
	if (IP2Location_ip_is_ipv6(ip)) {
		return IP2Location_get_ipv6_record(loc, ip, DOMAINNAME);
	} else {
		return IP2Location_get_record(loc, ip, DOMAINNAME);
	}
}


IP2LocationRecord *IP2Location_get_zipcode(IP2Location *loc, char *ip)
{
	if (IP2Location_ip_is_ipv6(ip)) {
		return IP2Location_get_ipv6_record(loc, ip, ZIPCODE);
	} else {
		return IP2Location_get_record(loc, ip, ZIPCODE);
	}
}

IP2LocationRecord *IP2Location_get_timezone(IP2Location *loc, char *ip)
{
	if (IP2Location_ip_is_ipv6(ip)) {
		return IP2Location_get_ipv6_record(loc, ip, TIMEZONE);
	} else {
		return IP2Location_get_record(loc, ip, TIMEZONE);
	}
}

IP2LocationRecord *IP2Location_get_netspeed(IP2Location *loc, char *ip)
{
	if (IP2Location_ip_is_ipv6(ip)) {
		return IP2Location_get_ipv6_record(loc, ip, NETSPEED);
	} else {
		return IP2Location_get_record(loc, ip, NETSPEED);
	}
}

IP2LocationRecord *IP2Location_get_iddcode(IP2Location *loc, char *ip)
{
	if (IP2Location_ip_is_ipv6(ip)) {
		return IP2Location_get_ipv6_record(loc, ip, IDDCODE);
	} else {
		return IP2Location_get_record(loc, ip, IDDCODE);
	}
}

IP2LocationRecord *IP2Location_get_areacode(IP2Location *loc, char *ip)
{
	if (IP2Location_ip_is_ipv6(ip)) {
		return IP2Location_get_ipv6_record(loc, ip, AREACODE);
	} else {
		return IP2Location_get_record(loc, ip, AREACODE);
	}
}

IP2LocationRecord *IP2Location_get_weatherstationcode(IP2Location *loc, char *ip)
{
	if (IP2Location_ip_is_ipv6(ip)) {
		return IP2Location_get_ipv6_record(loc, ip, WEATHERSTATIONCODE);
	} else {
		return IP2Location_get_record(loc, ip, WEATHERSTATIONCODE);
	}
}

IP2LocationRecord *IP2Location_get_weatherstationname(IP2Location *loc, char *ip)
{
	if (IP2Location_ip_is_ipv6(ip)) {
		return IP2Location_get_ipv6_record(loc, ip, WEATHERSTATIONNAME);
	} else {
		return IP2Location_get_record(loc, ip, WEATHERSTATIONNAME);
	}
}

IP2LocationRecord *IP2Location_get_mcc(IP2Location *loc, char *ip)
{
	if (IP2Location_ip_is_ipv6(ip)) {
		return IP2Location_get_ipv6_record(loc, ip, MCC);
	} else {
		return IP2Location_get_record(loc, ip, MCC);
	}
}

IP2LocationRecord *IP2Location_get_mnc(IP2Location *loc, char *ip)
{
	if (IP2Location_ip_is_ipv6(ip)) {
		return IP2Location_get_ipv6_record(loc, ip, MNC);
	} else {
		return IP2Location_get_record(loc, ip, MNC);
	}
}

IP2LocationRecord *IP2Location_get_mobilebrand(IP2Location *loc, char *ip)
{
	if (IP2Location_ip_is_ipv6(ip)) {
		return IP2Location_get_ipv6_record(loc, ip, MOBILEBRAND);
	} else {
		return IP2Location_get_record(loc, ip, MOBILEBRAND);
	}
}

IP2LocationRecord *IP2Location_get_elevation(IP2Location *loc, char *ip)
{
	if (IP2Location_ip_is_ipv6(ip)) {
		return IP2Location_get_ipv6_record(loc, ip, ELEVATION);
	} else {
		return IP2Location_get_record(loc, ip, ELEVATION);
	}
}

IP2LocationRecord *IP2Location_get_usagetype(IP2Location *loc, char *ip)
{
	if (IP2Location_ip_is_ipv6(ip)) {
		return IP2Location_get_ipv6_record(loc, ip, USAGETYPE);
	} else {
		return IP2Location_get_record(loc, ip, USAGETYPE);
	}
}

IP2LocationRecord *IP2Location_get_all(IP2Location *loc, char *ip)
{
	if (IP2Location_ip_is_ipv6(ip)) {
		return IP2Location_get_ipv6_record(loc, ip, ALL);
	} else {
		return IP2Location_get_record(loc, ip, ALL);
	}
}

IP2LocationRecord *IP2Location_get_ipv6_record(IP2Location *loc, char *ipstring, uint32_t mode)
{
	uint8_t dbtype = loc->databasetype;
	FILE *handle = loc->filehandle;
	uint32_t baseaddr = loc->ipv6databaseaddr;
	uint32_t dbcount = loc->ipv6databasecount;
	uint32_t dbcolumn = loc->databasecolumn;
	uint32_t ipv6indexbaseaddr = loc->ipv6indexbaseaddr;
	uint32_t low = 0;
	uint32_t high = dbcount;
	uint32_t mid = 0;
	uint32_t columnoffset = dbcolumn * 4 + 12;
	uint32_t columnoffsetA = 0;
	uint32_t columnoffsetB = 0;
	uint32_t columnoffsetC = 0;
	IP2LocationRecord *record = IP2Location_new_record();
	struct in6_addr_local ipfrom;
	struct in6_addr_local ipto;
	struct in6_addr_local ipno;
	struct in6_addr_local ipmax;
	ipv_t parsed_ipv;
	
	char *maxIP = "FFFF:FFFF:FFFF:FFFF:FFFF:FFFF:FFFF:FFFF";
	char *maxIP2 = "FFFF:FFFF:FFFF:FFFF:FFFF:FFFF:FFFF:FFFE";
	if (strcmp(ipstring, maxIP) == 0) {
		strcpy(ipstring, maxIP2);
	}
	parsed_ipv = parse_addr(ipstring);
	
	if (parsed_ipv.ipversion == 4) {
		return IP2Location_get_record(loc, ipstring, mode);
	}
	
	if (parsed_ipv.ipversion != 6) {
		record->country_short = strdup(INVALID_IPV6_ADDRESS);
		record->country_long = strdup(INVALID_IPV6_ADDRESS);
		record->region = strdup(INVALID_IPV6_ADDRESS);
		record->city = strdup(INVALID_IPV6_ADDRESS);
		record->isp = strdup(INVALID_IPV6_ADDRESS);
		record->latitude = 0;
		record->longitude = 0;
		record->domain = strdup(INVALID_IPV6_ADDRESS);
		record->zipcode = strdup(INVALID_IPV6_ADDRESS);
		record->timezone = strdup(INVALID_IPV6_ADDRESS);
		record->netspeed = strdup(INVALID_IPV6_ADDRESS);
		record->iddcode = strdup(INVALID_IPV6_ADDRESS);
		record->areacode = strdup(INVALID_IPV6_ADDRESS);
		record->weatherstationcode = strdup(INVALID_IPV6_ADDRESS);
		record->weatherstationname = strdup(INVALID_IPV6_ADDRESS);
		record->mcc = strdup(INVALID_IPV6_ADDRESS);
		record->mnc = strdup(INVALID_IPV6_ADDRESS);
		record->mobilebrand = strdup(INVALID_IPV6_ADDRESS);
		record->elevation = 0;
		record->usagetype = strdup(INVALID_IPV6_ADDRESS);
		return record;
	}
	
	ipno = parsed_ipv.ipv6;
	
	if (ipv6indexbaseaddr > 0) {
		/* use the index table */
		uint32_t ipnum1 = (ipno.u.addr8[0] * 256) + ipno.u.addr8[1];
		uint32_t indexpos = ipv6indexbaseaddr + (ipnum1 << 3);
		
		low = IP2Location_read32(handle, indexpos);
		high = IP2Location_read32(handle, indexpos + 4);
	}
	
	while (low <= high) {
		mid = (uint32_t)((low + high)/2);
		columnoffsetA = mid * columnoffset;
		columnoffsetB = columnoffsetA + columnoffset;
		columnoffsetC = columnoffsetA + 12;
		ipfrom = IP2Location_readIPv6Address(handle, baseaddr + columnoffsetA); 
		ipto = IP2Location_readIPv6Address(handle, baseaddr + columnoffsetB); 
		
		if ((ipv6_compare(&ipno, &ipfrom) >= 0) && (ipv6_compare(&ipno, &ipto) < 0)) {
			if ((mode & COUNTRYSHORT) && (COUNTRY_POSITION[dbtype] != 0)) {
				/* $ip, $baseaddr + $mid *($dbcolumn * 4 + 12) + 12 + 4 * */
				record->country_short = IP2Location_readStr(handle, IP2Location_read32(handle, baseaddr + columnoffsetC + 4 * (COUNTRY_POSITION[dbtype]-1)));
			}
			else {
				record->country_short = strdup(NOT_SUPPORTED);
			}
			
			if ((mode & COUNTRYLONG) && (COUNTRY_POSITION[dbtype] != 0)) {
				record->country_long = IP2Location_readStr(handle, IP2Location_read32(handle, baseaddr + columnoffsetC + 4 * (COUNTRY_POSITION[dbtype]-1))+3);
			}
			else {
				record->country_long = strdup(NOT_SUPPORTED);
			}

			if ((mode & REGION) && (REGION_POSITION[dbtype] != 0)) {
				record->region = IP2Location_readStr(handle, IP2Location_read32(handle, baseaddr + columnoffsetC + 4 * (REGION_POSITION[dbtype]-1)));
			}
			else {
				record->region = strdup(NOT_SUPPORTED);
			}

			if ((mode & CITY) && (CITY_POSITION[dbtype] != 0)) {
				record->city = IP2Location_readStr(handle, IP2Location_read32(handle, baseaddr + columnoffsetC + 4 * (CITY_POSITION[dbtype]-1)));
			}
			else {
				record->city = strdup(NOT_SUPPORTED);
			}

			if ((mode & ISP) && (ISP_POSITION[dbtype] != 0)) {
				record->isp = IP2Location_readStr(handle, IP2Location_read32(handle, baseaddr + columnoffsetC + 4 * (ISP_POSITION[dbtype]-1)));
			}
			else {
				record->isp = strdup(NOT_SUPPORTED);
			}

			if ((mode & LATITUDE) && (LATITUDE_POSITION[dbtype] != 0)) {
				record->latitude = IP2Location_readFloat(handle, baseaddr + columnoffsetC + 4 * (LATITUDE_POSITION[dbtype]-1));
			}
			else {
				record->latitude = 0.0;
			}

			if ((mode & LONGITUDE) && (LONGITUDE_POSITION[dbtype] != 0)) {
				record->longitude = IP2Location_readFloat(handle, baseaddr + columnoffsetC + 4 * (LONGITUDE_POSITION[dbtype]-1));
			}
			else {
				record->longitude = 0.0;
			}

			if ((mode & DOMAINNAME) && (DOMAIN_POSITION[dbtype] != 0)) {
				record->domain = IP2Location_readStr(handle, IP2Location_read32(handle, baseaddr + columnoffsetC + 4 * (DOMAIN_POSITION[dbtype]-1)));
			}
			else {
				record->domain = strdup(NOT_SUPPORTED);
			}

			if ((mode & ZIPCODE) && (ZIPCODE_POSITION[dbtype] != 0)) {
				record->zipcode = IP2Location_readStr(handle, IP2Location_read32(handle, baseaddr + columnoffsetC + 4 * (ZIPCODE_POSITION[dbtype]-1)));
			}
			else {
				record->zipcode = strdup(NOT_SUPPORTED);
			}
			
			if ((mode & TIMEZONE) && (TIMEZONE_POSITION[dbtype] != 0)) {
				record->timezone = IP2Location_readStr(handle, IP2Location_read32(handle, baseaddr + columnoffsetC + 4 * (TIMEZONE_POSITION[dbtype]-1)));
			}
			else {
				record->timezone = strdup(NOT_SUPPORTED);
			}

			if ((mode & NETSPEED) && (NETSPEED_POSITION[dbtype] != 0)) {
				record->netspeed = IP2Location_readStr(handle, IP2Location_read32(handle, baseaddr + columnoffsetC + 4 * (NETSPEED_POSITION[dbtype]-1)));
			}
			else {
				record->netspeed = strdup(NOT_SUPPORTED);
			}
	
			if ((mode & IDDCODE) && (IDDCODE_POSITION[dbtype] != 0)) {
				record->iddcode = IP2Location_readStr(handle, IP2Location_read32(handle, baseaddr + columnoffsetC + 4 * (IDDCODE_POSITION[dbtype]-1)));
			}
			else {
				record->iddcode = strdup(NOT_SUPPORTED);
			}

			if ((mode & AREACODE) && (AREACODE_POSITION[dbtype] != 0)) {
				record->areacode = IP2Location_readStr(handle, IP2Location_read32(handle, baseaddr + columnoffsetC + 4 * (AREACODE_POSITION[dbtype]-1)));
			}
			else {
				record->areacode = strdup(NOT_SUPPORTED);
			}

			if ((mode & WEATHERSTATIONCODE) && (WEATHERSTATIONCODE_POSITION[dbtype] != 0)) {
				record->weatherstationcode = IP2Location_readStr(handle, IP2Location_read32(handle, baseaddr + columnoffsetC + 4 * (WEATHERSTATIONCODE_POSITION[dbtype]-1)));
			}
			else {
				record->weatherstationcode = strdup(NOT_SUPPORTED);
			}

			if ((mode & WEATHERSTATIONNAME) && (WEATHERSTATIONNAME_POSITION[dbtype] != 0)) {
				record->weatherstationname = IP2Location_readStr(handle, IP2Location_read32(handle, baseaddr + columnoffsetC + 4 * (WEATHERSTATIONNAME_POSITION[dbtype]-1)));
			}
			else {
				record->weatherstationname = strdup(NOT_SUPPORTED);
			}

			if ((mode & MCC) && (MCC_POSITION[dbtype] != 0)) {
				record->mcc = IP2Location_readStr(handle, IP2Location_read32(handle, baseaddr + columnoffsetC + 4 * (MCC_POSITION[dbtype]-1)));
			}
			else {
				record->mcc = strdup(NOT_SUPPORTED);
			}

			if ((mode & MNC) && (MNC_POSITION[dbtype] != 0)) {
				record->mnc = IP2Location_readStr(handle, IP2Location_read32(handle, baseaddr + columnoffsetC + 4 * (MNC_POSITION[dbtype]-1)));
			}
			else {
				record->mnc = strdup(NOT_SUPPORTED);
			}

			if ((mode & MOBILEBRAND) && (MOBILEBRAND_POSITION[dbtype] != 0)) {
				record->mobilebrand = IP2Location_readStr(handle, IP2Location_read32(handle, baseaddr + columnoffsetC + 4 * (MOBILEBRAND_POSITION[dbtype]-1)));
			}
			else {
				record->mobilebrand = strdup(NOT_SUPPORTED);
			}
			
			// this one stored as string but output as float
			if ((mode & ELEVATION) && (ELEVATION_POSITION[dbtype] != 0)) {
				__try {
					record->elevation = atof(IP2Location_readStr(handle, IP2Location_read32(handle, baseaddr + columnoffsetC + 4 * (ELEVATION_POSITION[dbtype]-1))));
				}__except(EXCEPTION_EXECUTE_HANDLER) {
					record->elevation = 0.0;
				}
			}
			else {
				record->elevation = 0.0;
			}
			
			if ((mode & USAGETYPE) && (USAGETYPE_POSITION[dbtype] != 0)) {
				record->usagetype = IP2Location_readStr(handle, IP2Location_read32(handle, baseaddr + columnoffsetC + 4 * (USAGETYPE_POSITION[dbtype]-1)));
			}
			else {
				record->usagetype = strdup(NOT_SUPPORTED);
			}
			return record;
		}
		else {
			if (ipv6_compare(&ipno, &ipfrom) < 0) {
				high = mid - 1;
			}
			else {
				low = mid + 1;
			}
		}
	}
	IP2Location_free_record(record);
	return NULL;
}

IP2LocationRecord *IP2Location_get_record(IP2Location *loc, char *ipstring, uint32_t mode)
{
	uint8_t dbtype = loc->databasetype;
	FILE *handle = loc->filehandle;
	uint32_t baseaddr = loc->ipv4databaseaddr;
	uint32_t dbcount = loc->ipv4databasecount;
	uint32_t dbcolumn = loc->databasecolumn;
	uint32_t ipv4indexbaseaddr = loc->ipv4indexbaseaddr;
	uint32_t low = 0;
	uint32_t high = dbcount;
	uint32_t mid = 0;
	uint32_t ipfrom = 0;
	uint32_t ipto = 0;
	uint32_t ipno = 0;
	ipv_t parsed_ipv = parse_addr(ipstring);
	uint32_t columnoffset = dbcolumn * 4;
	uint32_t columnoffsetA = 0;
	uint32_t columnoffsetB = 0;
	IP2LocationRecord *record = IP2Location_new_record();
	
	if (parsed_ipv.ipversion == 6) {
		return IP2Location_get_ipv6_record(loc, ipstring, mode);
	}
	
	if (parsed_ipv.ipversion != 4) {
		record->country_short = strdup(INVALID_IPV4_ADDRESS);
		record->country_long = strdup(INVALID_IPV4_ADDRESS);
		record->region = strdup(INVALID_IPV4_ADDRESS);
		record->city = strdup(INVALID_IPV4_ADDRESS);
		record->isp = strdup(INVALID_IPV4_ADDRESS);
		record->latitude = 0;
		record->longitude = 0;
		record->domain = strdup(INVALID_IPV4_ADDRESS);
		record->zipcode = strdup(INVALID_IPV4_ADDRESS);
		record->timezone = strdup(INVALID_IPV4_ADDRESS);
		record->netspeed = strdup(INVALID_IPV4_ADDRESS);
		record->iddcode = strdup(INVALID_IPV4_ADDRESS);
		record->areacode = strdup(INVALID_IPV4_ADDRESS);
		record->weatherstationcode = strdup(INVALID_IPV4_ADDRESS);
		record->weatherstationname = strdup(INVALID_IPV4_ADDRESS);
		record->mcc = strdup(INVALID_IPV4_ADDRESS);
		record->mnc = strdup(INVALID_IPV4_ADDRESS);
		record->mobilebrand = strdup(INVALID_IPV4_ADDRESS);
		record->elevation = 0;
		record->usagetype = strdup(INVALID_IPV4_ADDRESS);
		return record;
	}

	ipno = parsed_ipv.ipv4;
	if (ipno == (uint32_t) MAX_IPV4_RANGE) {
		ipno = ipno - 1;
	}
	
	if (ipv4indexbaseaddr > 0) {
		/* use the index table */
		uint32_t ipnum1n2 = (uint32_t) ipno >> 16;
		uint32_t indexpos = ipv4indexbaseaddr + (ipnum1n2 << 3);
		
		low = IP2Location_read32(handle, indexpos);
		high = IP2Location_read32(handle, indexpos + 4);
	}
	
	while (low <= high) 
	{
		mid = (uint32_t)((low + high)/2);
		columnoffsetA = mid * columnoffset;
		columnoffsetB = columnoffsetA + columnoffset;
		ipfrom = IP2Location_read32(handle, baseaddr + columnoffsetA);
		ipto = IP2Location_read32(handle, baseaddr + columnoffsetB);

		if ((ipno >= ipfrom) && (ipno < ipto)) 
		{
			if ((mode & COUNTRYSHORT) && (COUNTRY_POSITION[dbtype] != 0)) {
				record->country_short = IP2Location_readStr(handle, IP2Location_read32(handle, baseaddr + columnoffsetA + 4 * (COUNTRY_POSITION[dbtype]-1)));
			} else {
				record->country_short = strdup(NOT_SUPPORTED);
			}
			
			if ((mode & COUNTRYLONG) && (COUNTRY_POSITION[dbtype] != 0)) {
				record->country_long = IP2Location_readStr(handle, IP2Location_read32(handle, baseaddr + columnoffsetA + 4 * (COUNTRY_POSITION[dbtype]-1))+3);
			} else {
				record->country_long = strdup(NOT_SUPPORTED);
			}

			if ((mode & REGION) && (REGION_POSITION[dbtype] != 0)) {
				record->region = IP2Location_readStr(handle, IP2Location_read32(handle, baseaddr + columnoffsetA + 4 * (REGION_POSITION[dbtype]-1)));
			} else {
				record->region = strdup(NOT_SUPPORTED);
			}

			if ((mode & CITY) && (CITY_POSITION[dbtype] != 0)) {
				record->city = IP2Location_readStr(handle, IP2Location_read32(handle, baseaddr + columnoffsetA + 4 * (CITY_POSITION[dbtype]-1)));
			} else {
				record->city = strdup(NOT_SUPPORTED);
			}

			if ((mode & ISP) && (ISP_POSITION[dbtype] != 0)) {
				record->isp = IP2Location_readStr(handle, IP2Location_read32(handle, baseaddr + columnoffsetA + 4 * (ISP_POSITION[dbtype]-1)));
			} else {
				record->isp = strdup(NOT_SUPPORTED);
			}

			if ((mode & LATITUDE) && (LATITUDE_POSITION[dbtype] != 0)) {
				record->latitude = IP2Location_readFloat(handle, baseaddr + columnoffsetA + 4 * (LATITUDE_POSITION[dbtype]-1));
			} else {
				record->latitude = 0.0;
			}

			if ((mode & LONGITUDE) && (LONGITUDE_POSITION[dbtype] != 0)) {
				record->longitude = IP2Location_readFloat(handle, baseaddr + columnoffsetA + 4 * (LONGITUDE_POSITION[dbtype]-1));
			} else {
				record->longitude = 0.0;
			}

			if ((mode & DOMAINNAME) && (DOMAIN_POSITION[dbtype] != 0)) {
				record->domain = IP2Location_readStr(handle, IP2Location_read32(handle, baseaddr + columnoffsetA + 4 * (DOMAIN_POSITION[dbtype]-1)));
			} else {
				record->domain = strdup(NOT_SUPPORTED);
			}

			if ((mode & ZIPCODE) && (ZIPCODE_POSITION[dbtype] != 0)) {
				record->zipcode = IP2Location_readStr(handle, IP2Location_read32(handle, baseaddr + columnoffsetA + 4 * (ZIPCODE_POSITION[dbtype]-1)));
			} else {
				record->zipcode = strdup(NOT_SUPPORTED);
			}
			
			if ((mode & TIMEZONE) && (TIMEZONE_POSITION[dbtype] != 0)) {
				record->timezone = IP2Location_readStr(handle, IP2Location_read32(handle, baseaddr + columnoffsetA + 4 * (TIMEZONE_POSITION[dbtype]-1)));
			} else {
				record->timezone = strdup(NOT_SUPPORTED);
			}
			
			if ((mode & NETSPEED) && (NETSPEED_POSITION[dbtype] != 0)) {
				record->netspeed = IP2Location_readStr(handle, IP2Location_read32(handle, baseaddr + columnoffsetA + 4 * (NETSPEED_POSITION[dbtype]-1)));
			} else {
				record->netspeed = strdup(NOT_SUPPORTED);
			}
	
			if ((mode & IDDCODE) && (IDDCODE_POSITION[dbtype] != 0)) {
				record->iddcode = IP2Location_readStr(handle, IP2Location_read32(handle, baseaddr + columnoffsetA + 4 * (IDDCODE_POSITION[dbtype]-1)));
			} else {
				record->iddcode = strdup(NOT_SUPPORTED);
			}
	
			if ((mode & AREACODE) && (AREACODE_POSITION[dbtype] != 0)) {
				record->areacode = IP2Location_readStr(handle, IP2Location_read32(handle, baseaddr + columnoffsetA + 4 * (AREACODE_POSITION[dbtype]-1)));
			} else {
				record->areacode = strdup(NOT_SUPPORTED);
			}
	
			if ((mode & WEATHERSTATIONCODE) && (WEATHERSTATIONCODE_POSITION[dbtype] != 0)) {
				record->weatherstationcode = IP2Location_readStr(handle, IP2Location_read32(handle, baseaddr + columnoffsetA + 4 * (WEATHERSTATIONCODE_POSITION[dbtype]-1)));
			} else {
				record->weatherstationcode = strdup(NOT_SUPPORTED);
			}
	
			if ((mode & WEATHERSTATIONNAME) && (WEATHERSTATIONNAME_POSITION[dbtype] != 0)) {
				record->weatherstationname = IP2Location_readStr(handle, IP2Location_read32(handle, baseaddr + columnoffsetA + 4 * (WEATHERSTATIONNAME_POSITION[dbtype]-1)));
			} else {
				record->weatherstationname = strdup(NOT_SUPPORTED);
			}

			if ((mode & MCC) && (MCC_POSITION[dbtype] != 0)) {
				record->mcc = IP2Location_readStr(handle, IP2Location_read32(handle, baseaddr + columnoffsetA + 4 * (MCC_POSITION[dbtype]-1)));
			} else {
				record->mcc = strdup(NOT_SUPPORTED);
			}

			if ((mode & MNC) && (MNC_POSITION[dbtype] != 0)) {
				record->mnc = IP2Location_readStr(handle, IP2Location_read32(handle, baseaddr + columnoffsetA + 4 * (MNC_POSITION[dbtype]-1)));
			} else {
				record->mnc = strdup(NOT_SUPPORTED);
			}

			if ((mode & MOBILEBRAND) && (MOBILEBRAND_POSITION[dbtype] != 0)) {
				record->mobilebrand = IP2Location_readStr(handle, IP2Location_read32(handle, baseaddr + columnoffsetA + 4 * (MOBILEBRAND_POSITION[dbtype]-1)));
			} else {
				record->mobilebrand = strdup(NOT_SUPPORTED);
			}
	
			// this one stored as string but output as float
			if ((mode & ELEVATION) && (ELEVATION_POSITION[dbtype] != 0)) {
				__try {
					record->elevation = atof(IP2Location_readStr(handle, IP2Location_read32(handle, baseaddr + columnoffsetA + 4 * (ELEVATION_POSITION[dbtype]-1))));
				}__except(EXCEPTION_EXECUTE_HANDLER) {
					record->elevation = 0.0;
				}
			} else {
				record->elevation = 0.0;
			}
			
			if ((mode & USAGETYPE) && (USAGETYPE_POSITION[dbtype] != 0)) {
				record->usagetype = IP2Location_readStr(handle, IP2Location_read32(handle, baseaddr + columnoffsetA + 4 * (USAGETYPE_POSITION[dbtype]-1)));
			} else {
				record->usagetype = strdup(NOT_SUPPORTED);
			}
			return record;
		} else {
			if ( ipno < ipfrom ) {
				high = mid - 1;
			} else {
				low = mid + 1;
			}
		}
	}
	IP2Location_free_record(record);
	return NULL;
}


IP2LocationRecord *IP2Location_new_record()
{
	IP2LocationRecord *record = (IP2LocationRecord *) malloc(sizeof(IP2LocationRecord));
	memset(record, 0, sizeof(IP2LocationRecord));
	return record;
}


void IP2Location_free_record(IP2LocationRecord *record)
{
	if (record->city != NULL)
		free(record->city);

	if (record->country_long != NULL)
		free(record->country_long);

	if (record->country_short != NULL)
		free(record->country_short);

	if (record->domain != NULL)
		free(record->domain);

	if (record->isp != NULL)
		free(record->isp);

	if (record->region != NULL)
		free(record->region);

	if (record->zipcode != NULL)
		free(record->zipcode);
		
	if (record->timezone != NULL)
		free(record->timezone);  
		
	if (record->netspeed != NULL)
		free(record->netspeed);  
	
	if (record->iddcode != NULL)
		free(record->iddcode);  

	if (record->areacode != NULL)
		free(record->areacode);  

	if (record->weatherstationcode != NULL)
		free(record->weatherstationcode);  

	if (record->weatherstationname != NULL)
		free(record->weatherstationname);  

	if (record->mcc != NULL)
		free(record->mcc);  

	if (record->mnc != NULL)
		free(record->mnc);  

	if (record->mobilebrand != NULL)
		free(record->mobilebrand);  
	
	// if (record->elevation != NULL)
		// free(record->elevation);  
	
	if (record->usagetype != NULL)
		free(record->usagetype);  
	
	free(record);
}

uint32_t IP2Location_read32(FILE *handle, uint32_t position)
{
	uint8_t byte1 = 0;
	uint8_t byte2 = 0;
	uint8_t byte3 = 0;
	uint8_t byte4 = 0;
	
	if (handle != NULL) {
		fseek(handle, position-1, 0);
		fread(&byte1, 1, 1, handle);
		fread(&byte2, 1, 1, handle);
		fread(&byte3, 1, 1, handle);
		fread(&byte4, 1, 1, handle);
	}
	return ((byte4 << 24) | (byte3 << 16) | (byte2 << 8) | (byte1));
}

uint8_t IP2Location_read8(FILE *handle, uint32_t position)
{	
	uint8_t ret = 0;

	if (handle != NULL) {
		fseek(handle, position-1, 0);
		fread(&ret, 1, 1, handle);
	}		
	return ret;
}


char *IP2Location_readStr(FILE *handle, uint32_t position)
{
	uint8_t size = 0;
	char *str = 0;

	if (handle != NULL) {
		fseek(handle, position, 0);
		fread(&size, 1, 1, handle);
		str = (char *)malloc(size+1);
		memset(str, 0, size+1);
		fread(str, size, 1, handle);
	}	
	return str;
}


float IP2Location_readFloat(FILE *handle, uint32_t position)
{
	float ret = 0.0;

#ifdef _SUN_
	char * p = (char *) &ret;
	
	/* for SUN SPARC, have to reverse the byte order */
	if (handle != NULL) {
		fseek(handle, position-1, 0);
		fread(p+3, 1, 1, handle);
		fread(p+2, 1, 1, handle);
		fread(p+1, 1, 1, handle);
		fread(p,   1, 1, handle);
	}
#else
	if (handle != NULL) {
		fseek(handle, position-1, 0);
		fread(&ret, 4, 1, handle);
	}
#endif
	return ret;
}


uint32_t IP2Location_ip2no(char* ipstring)
{
	uint32_t ip = inet_addr(ipstring);
	uint8_t *ptr = (uint8_t *) &ip;
	uint32_t a = 0;
	
	if (ipstring != NULL) {
		a =  (uint8_t)(ptr[3]);
		a += (uint8_t)(ptr[2]) * 256;
		a += (uint8_t)(ptr[1]) * 256 * 256;
		a += (uint8_t)(ptr[0]) * 256 * 256 * 256;
	}
	return a;
}

int IP2Location_ip_is_ipv4 (char* ipaddr) {
	struct sockaddr_in sa;
	return inet_pton(AF_INET, ipaddr, &(sa.sin_addr));
}

int IP2Location_ip_is_ipv6 (char* ipaddr) {
	struct in6_addr_local ipv6;
	return inet_pton(AF_INET6, ipaddr, &ipv6);
}

