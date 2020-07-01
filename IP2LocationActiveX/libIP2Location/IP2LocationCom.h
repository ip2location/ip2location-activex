#ifndef HAVE_IP2LOCATION_H
#define HAVE_IP2LOCATION_H

#ifdef __cplusplus
extern "C" {
#endif

#include <stdio.h>
#include <stdlib.h> 
#include <malloc.h>
#ifndef WIN32
#include <stdint.h>
#else
#ifndef uint16_t
#define uint16_t short
#endif
#ifndef int64_t
#define int64_t long long int
#endif
#ifndef uint8_t
#define uint8_t unsigned char
#endif
#ifndef uint32_t
#ifndef WIN32
#define uint32_t int
#else
#define uint32_t unsigned int
#endif
#endif
#endif

#define API_VERSION   8.2.0
#define MAX_IPV4_RANGE  4294967295U
#define MAX_IPV6_RANGE  "340282366920938463463374607431768211455"
#define IPV4 0
#define IPV6 1

#define  COUNTRYSHORT           0x00001
#define  COUNTRYLONG            0x00002
#define  REGION                 0x00004
#define  CITY                   0x00008
#define  ISP                    0x00010
#define  LATITUDE               0x00020
#define  LONGITUDE              0x00040
#define  DOMAINNAME             0x00080
#define  ZIPCODE                0x00100
#define  TIMEZONE               0x00200
#define  NETSPEED               0x00400 
#define  IDDCODE                0x00800
#define  AREACODE               0x01000
#define  WEATHERSTATIONCODE     0x02000
#define  WEATHERSTATIONNAME     0x04000
#define  MCC                    0x08000
#define  MNC                    0x10000
#define  MOBILEBRAND            0x20000
#define  ELEVATION              0x40000
#define  USAGETYPE              0x80000
#define  ALL          COUNTRYSHORT | COUNTRYLONG | REGION | CITY | ISP | LATITUDE | LONGITUDE | DOMAINNAME | ZIPCODE | TIMEZONE | NETSPEED | IDDCODE | AREACODE | WEATHERSTATIONCODE | WEATHERSTATIONNAME | MCC | MNC | MOBILEBRAND | ELEVATION | USAGETYPE

#define  DEFAULT	     0x0001
#define  NO_EMPTY_STRING 0x0002
#define  NO_LEADING      0x0004
#define  NO_TRAILING     0x0008

#define INVALID_IPV6_ADDRESS "INVALID IPV6 ADDRESS"
#define INVALID_IPV4_ADDRESS "INVALID IPV4 ADDRESS"
#define  NOT_SUPPORTED "This parameter is unavailable for selected data file. Please upgrade the data file."

typedef struct
{
	FILE *filehandle;
	uint8_t databasetype;
	uint8_t databasecolumn;
	uint8_t databaseday;
	uint8_t databasemonth;
	uint8_t databaseyear;
	uint32_t databasecount;
	uint32_t databaseaddr;
	uint32_t ipversion;
	uint32_t ipv4databasecount;
	uint32_t ipv4databaseaddr;
	uint32_t ipv6databasecount;
	uint32_t ipv6databaseaddr;
	uint32_t ipv4indexbaseaddr;
	uint32_t ipv6indexbaseaddr;
} IP2Location;

typedef struct 
{
	char *country_short;
	char *country_long;
	char *region;
	char *city;
	char *isp;
	float latitude;
	float longitude;
	char *domain;
	char *zipcode;
	char *timezone;
	char *netspeed;
	char *iddcode;
	char *areacode;
	char *weatherstationcode;
	char *weatherstationname;
	char *mcc;
	char *mnc;
	char *mobilebrand;
	float elevation;
	char *usagetype;
} IP2LocationRecord;

struct in6_addr_local
{
	union {
		uint8_t addr8[16];
		uint8_t addr16[8];
	}u;
};

typedef struct ipv_t {
	uint32_t ipversion;
	uint32_t ipv4;
	struct in6_addr_local ipv6;
} ipv_t;

/*##################
# Public Functions
##################*/
IP2Location *IP2Location_open(char *db);
uint32_t IP2Location_close(IP2Location *loc);
IP2LocationRecord *IP2Location_get_country_short(IP2Location *loc, char *ip);
IP2LocationRecord *IP2Location_get_country_long(IP2Location *loc, char *ip);
IP2LocationRecord *IP2Location_get_region(IP2Location *loc, char *ip);
IP2LocationRecord *IP2Location_get_city (IP2Location *loc, char *ip);
IP2LocationRecord *IP2Location_get_isp(IP2Location *loc, char *ip);
IP2LocationRecord *IP2Location_get_latitude(IP2Location *loc, char *ip);
IP2LocationRecord *IP2Location_get_longitude(IP2Location *loc, char *ip);
IP2LocationRecord *IP2Location_get_domain(IP2Location *loc, char *ip);
IP2LocationRecord *IP2Location_get_zipcode(IP2Location *loc, char *ip);
IP2LocationRecord *IP2Location_get_timezone(IP2Location *loc, char *ip);
IP2LocationRecord *IP2Location_get_netspeed(IP2Location *loc, char *ip);
IP2LocationRecord *IP2Location_get_iddcode(IP2Location *loc, char *ip);
IP2LocationRecord *IP2Location_get_areacode(IP2Location *loc, char *ip);
IP2LocationRecord *IP2Location_get_weatherstationcode(IP2Location *loc, char *ip);
IP2LocationRecord *IP2Location_get_weatherstationname(IP2Location *loc, char *ip);
IP2LocationRecord *IP2Location_get_mcc(IP2Location *loc, char *ip);
IP2LocationRecord *IP2Location_get_mnc(IP2Location *loc, char *ip);
IP2LocationRecord *IP2Location_get_mobilebrand(IP2Location *loc, char *ip);
IP2LocationRecord *IP2Location_get_elevation(IP2Location *loc, char *ip);
IP2LocationRecord *IP2Location_get_usagetype(IP2Location *loc, char *ip);
IP2LocationRecord *IP2Location_get_all(IP2Location *loc, char *ip);
void IP2Location_free_record(IP2LocationRecord *record);

/*###################
# Private Functions
###################*/

int IP2Location_initialize(IP2Location *loc);
IP2LocationRecord *IP2Location_new_record();
uint32_t IP2Location_read32(FILE *handle, uint32_t position);
uint8_t IP2Location_read8(FILE *handle, uint32_t position);
char *IP2Location_readStr(FILE *handle, uint32_t position);
float IP2Location_readFloat(FILE *handle, uint32_t position);
uint32_t IP2Location_ip2no(char* ip);
//struct in6_addr_local IP2Location_ipv6_to_no(char* ipaddr);
int IP2Location_ip_is_ipv4 (char* ipaddr);
int IP2Location_ip_is_ipv6 (char* ipaddr);
IP2LocationRecord *IP2Location_get_record(IP2Location *loc, char *ip, uint32_t mode);
IP2LocationRecord *IP2Location_get_ipv6_record(IP2Location *loc, char *ipstring, uint32_t mode);
int ipv6_compare(struct in6_addr_local *addr1, struct in6_addr_local *addr2);
ipv_t parse_addr(const char *addr);
//#ifdef WIN32
//int inet_pton(int af, const char *src, void *dst);
//#endif

#ifdef __cplusplus
}
#endif

#endif
