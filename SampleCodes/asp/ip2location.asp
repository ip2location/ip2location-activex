<HTML>
<HEAD><TITLE>
IP2Location&#153; ActiveX/COM DLL Demo in ASP
</TITLE></HEAD>
<BODY bgcolor="#FFFFFF">
<h1><b><u>Lookup Country by IP Address using IP2Location&#153; ActiveX/COM DLL</u></h1></b>
Enter an IPv4 or IPv6 address.
<%
	Response.Write	"  <form action=""" & Request("SCRIPT_NAME") & """ method=""POST"">" & vbCrLf
	Response.Write	"    <input type=""text"" name=""ipaddress"">" & vbCrLf
	Response.Write	"    <input type=""submit"" name=""submit"" value=""submit"">" & vbCrLf
	Response.Write	"  </form>" & vbCrLf
	
	If Not Request.Form("ipaddress") = "" Then
		
		' get the IP address from the form 
		ipaddress = Request.Form("ipaddress")
		
		Set Obj = Server.CreateObject("IP2Location.Country")
		Response.Write "<h1><u>Lookup Result</u></h1>"
		Response.Flush
		
		str = obj.LookUp(Server.MapPath("IP2LOCATION-LITE-DB1.BIN"), ipaddress)
		If str = "OK" Then
			Response.Write	"<table>"
			Dim line
			line = "<tr><td>CountryShort = " & obj.CountryShort & "</td></tr>"
			line = line & "<tr><td>CountryLong = " & obj.CountryLong & "</td></tr>"
			line = line & "<tr><td>Region = " & obj.Region & "</td></tr>"
			line = line & "<tr><td>City = " & obj.City & "</td></tr>"
			line = line & "<tr><td>Latitude = " & obj.Latitude & "</td></tr>"
			line = line & "<tr><td>Longitude = " & obj.Longitude & "</td></tr>"
			line = line & "<tr><td>ZIPCode = " & obj.ZIPCode & "</td></tr>"
			line = line & "<tr><td>Timezone = " & obj.TimeZone & "</td></tr>"
			line = line & "<tr><td>ISP = " & obj.ISP & "</td></tr>"
			line = line & "<tr><td>Domain = " & obj.Domain & "</td></tr>"
			line = line & "<tr><td>Netspeed = " & obj.NetSpeed & "</td></tr>"
			line = line & "<tr><td>IDDCode = " & obj.IDDCode & "</td></tr>"
			line = line & "<tr><td>AreaCode = " & obj.AreaCode & "</td></tr>"
			line = line & "<tr><td>WeatherStationCode = " & obj.WeatherStationCode & "</td></tr>"
			line = line & "<tr><td>WeatherStationName = " & obj.WeatherStationName & "</td></tr>"
			line = line & "<tr><td>MCC = " & obj.MCC & "</td></tr>"
			line = line & "<tr><td>MNC = " & obj.MNC & "</td></tr>"
			line = line & "<tr><td>MobileBrand = " & obj.MobileBrand & "</td></tr>"
			line = line & "<tr><td>Elevation = " & obj.Elevation & "</td></tr>"
			line = line & "<tr><td>UsageType = " & obj.UsageType & "</td></tr>"
			line = line & "<tr><td>AddressType = " & obj.AddressType & "</td></tr>"
			line = line & "<tr><td>Category = " & obj.Category & "</td></tr>"
			line = line & "<tr><td>District = " & obj.District & "</td></tr>"
			line = line & "<tr><td>ASN = " & obj.ASN & "</td></tr>"
			line = line & "<tr><td>AS = " & obj.AS & "</td></tr>"
			line = line & "<tr><td>ASDomain = " & obj.ASDomain & "</td></tr>"
			line = line & "<tr><td>ASUsageType = " & obj.ASUsageType & "</td></tr>"
			line = line & "<tr><td>ASCIDR = " & obj.ASCIDR & "</td></tr>"
			Response.Write(line)
			Response.Write	"</table>"
		Else
			Response.Write("Error : " & str & "<br>")
		End If
		Response.Write	"</p>"
		set obj = Nothing
	End If
%>
</BODY>
</HTML>