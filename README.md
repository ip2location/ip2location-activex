# IP2Location ActiveX Component

This component allows user to query an IP address for its geolocation info such as country, region or state, city, latitude and longitude, ZIP/Postal code, time zone, Internet Service Provider (ISP) or company name, domain name, net speed, area code, weather station code, weather station name, mobile country code (MCC), mobile network code (MNC) and carrier brand, elevation, and usage type. It lookup the IP address from **IP2Location BIN Data** file. This data file can be downloaded at

* Free IP2Location BIN Data: https://lite.ip2location.com
* Commercial IP2Location BIN Data: https://www.ip2location.com/database/ip2location

## Requirements

Microsoft Visual Studio 2019 or later.

## Functions
Below are the functions supported in this class.

|Function Name|Description|
|---|---|
|LookUp(BINFile, IP)|Query IP address with the specified BIN file. This function returns the status for the query.|

## Result fields
Below are the result fields.

|Field Name|Description|
|---|---|
|CountryShort|Two-character country code based on ISO 3166.|
|CountryLong|Country name based on ISO 3166.|
|Region|Region or state name.|
|City|City name.|
|Latitude|City level latitude.|
|Longitude|City level longitude.|
|ZIPCode|ZIP code or postal code.|
|TimeZone|Time zone in UTC (Coordinated Universal Time).|
|ISP|Internet Service Provider (ISP) name.|
|Domain|Domain name associated to IP address range.|
|NetSpeed|Internet connection speed <ul><li>(DIAL) Dial-up</li><li>(DSL) DSL/Cable</li><li>(COMP) Company/T1</li></ul>|
|IDDCode|The IDD prefix to call the city from another country.|
|AreaCode|A varying length number assigned to geographic areas for call between cities.|
|WeatherStationCode|Special code to identify the nearest weather observation station.|
|WeatherStationName|Name of the nearest weather observation station.|
|MCC|Mobile country code.|
|MNC|Mobile network code.|
|MobileBrand|Mobile carrier brand.|
|Elevation|Average height of city above sea level in meters (m).|
|UsageType|Usage type classification of ISP or company:<ul><li>(COM) Commercial</li><li>(ORG) Organization</li><li>(GOV) Government</li><li>(MIL) Military</li><li>(EDU) University/College/School</li><li>(LIB) Library</li><li>(CDN) Content Delivery Network</li><li>(ISP) Fixed Line ISP</li><li>(MOB) Mobile ISP</li><li>(DCH) Data Center/Web Hosting/Transit</li><li>(SES) Search Engine Spider</li><li>(RSV) Reserved</li></ul>|

## Usage
See the SampleCodes folder.