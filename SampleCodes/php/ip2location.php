<HTML>
<HEAD>
	<TITLE>IP2Location&#153; ActiveX/COM DLL Demo in PHP Hypertext Preprocessor</TITLE>
</HEAD>
<BODY bgcolor="#FFFFFF">
<h1><b><u>Lookup Country by IP Address using IP2Location&#153; ActiveX/COM DLL</u></h1></b>
Enter an IPv4 or IPv6 address.
<?php
	# create server-side object
	echo	"  <form action=\"" . $_SERVER['PHP_SELF'] . "\" method=\"POST\">\n";
	echo	"    <input type=\"text\" name=\"ipaddress\">\n";
	echo	"    <input type=\"submit\" name=\"submit\" value=\"submit\">\n";
	echo	"  </form>\n";
	if (isset($_POST["ipaddress"])) 
	{
		$ipaddress = $_POST["ipaddress"];
		$Obj = new COM("IP2Location.Country") or die("Cannot start IP2Location.Country component."); 
		echo "<h1><u>Lookup Result</u></h1>";
		
		$str = $Obj->LookUp("IP2LOCATION-LITE-DB1.BIN", $ipaddress);
		if ( $str == "OK")
		{
			echo "<table>";
			$line = "<tr><td>CountryShort = " . $Obj->CountryShort . "</td></tr>";
			$line = $line . "<tr><td>CountryLong = " . $Obj->CountryLong . "</td></tr>";
			$line = $line . "<tr><td>Region = " . $Obj->Region . "</td></tr>";
			$line = $line . "<tr><td>City = " . $Obj->City . "</td></tr>";
			$line = $line . "<tr><td>Latitude = " . $Obj->Latitude . "</td></tr>";
			$line = $line . "<tr><td>Longitude = " . $Obj->Longitude . "</td></tr>";
			$line = $line . "<tr><td>ZIPCode = " . $Obj->ZIPCode . "</td></tr>";
			$line = $line . "<tr><td>Timezone = " . $Obj->TimeZone . "</td></tr>";
			$line = $line . "<tr><td>ISP = " . $Obj->ISP . "</td></tr>";
			$line = $line . "<tr><td>Domain = " . $Obj->Domain . "</td></tr>";
			$line = $line . "<tr><td>Netspeed = " . $Obj->NetSpeed . "</td></tr>";
			$line = $line . "<tr><td>IDDCode = " . $Obj->IDDCode . "</td></tr>";
			$line = $line . "<tr><td>AreaCode = " . $Obj->AreaCode . "</td></tr>";
			$line = $line . "<tr><td>WeatherStationCode = " . $Obj->WeatherStationCode . "</td></tr>";
			$line = $line . "<tr><td>WeatherStationName = " . $Obj->WeatherStationName . "</td></tr>";
			$line = $line . "<tr><td>MCC = " . $Obj->MCC . "</td></tr>";
			$line = $line . "<tr><td>MNC = " . $Obj->MNC . "</td></tr>";
			$line = $line . "<tr><td>MobileBrand = " . $Obj->MobileBrand . "</td></tr>";
			$line = $line . "<tr><td>Elevation = " . $Obj->Elevation . "</td></tr>";
			$line = $line . "<tr><td>UsageType = " . $Obj->UsageType . "</td></tr>";
			$line = $line . "<tr><td>AddressType = " . $Obj->AddressType . "</td></tr>";
			$line = $line . "<tr><td>Category = " . $Obj->Category . "</td></tr>";
			$line = $line . "<tr><td>District = " . $Obj->District . "</td></tr>";
			$line = $line . "<tr><td>ASN = " . $Obj->ASN . "</td></tr>";
			$line = $line . "<tr><td>AS = " . $Obj->AS . "</td></tr>";
			$line = $line . "<tr><td>ASDomain = " . $Obj->ASDomain . "</td></tr>";
			$line = $line . "<tr><td>ASUsageType = " . $Obj->ASUsageType . "</td></tr>";
			$line = $line . "<tr><td>ASCIDR = " . $Obj->ASCIDR . "</td></tr>";
			echo $line;
			echo "</table>";
		}
		else
		{
			echo "Error : " . $str . "<br>";
		}
		echo	"</p>";
		$ipObj = null;
	}
?>
</BODY>
</HTML>