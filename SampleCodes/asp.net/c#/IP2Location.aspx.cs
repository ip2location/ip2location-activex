using System;
using System.Collections;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Web;
using System.Web.SessionState;
using System.Web.UI;
using System.Web.UI.WebControls;
using System.Web.UI.HtmlControls;

namespace IP2LocationActiveXSampleCSharp
{
	/// <summary>
	/// Summary description for IP2Location.
	/// </summary>
	public class IP2Location : System.Web.UI.Page
	{
		protected System.Web.UI.WebControls.Literal litResult;
		protected System.Web.UI.WebControls.Button btnSubmit;
		protected System.Web.UI.WebControls.TextBox txtIPAddress;
	
		private void Page_Load(object sender, System.EventArgs e)
		{
			// Put user code to initialize the page here
		}
		private void Lookup()
		{
			string IP = "";
			string str = "";
			string line = "";
			IP2LOCATIONLib.Country obj = new IP2LOCATIONLib.CountryClass();
			IP = this.txtIPAddress.Text.Trim();
			line += "<h1><u>Lookup Result</u></h1>";
			
			str = obj.LookUp(System.AppDomain.CurrentDomain.BaseDirectory + "IP2LOCATION-LITE-DB1.BIN", IP);
			if (str == "OK")
			{
				line += "<table>";
				line += "<tr><td>CountryShort = " + obj.CountryShort + "</td></tr>";
				line += "<tr><td>CountryLong = " + obj.CountryLong + "</td></tr>";
				line += "<tr><td>Region = " + obj.Region + "</td></tr>";
				line += "<tr><td>City = " + obj.City + "</td></tr>";
				line += "<tr><td>Latitude = " + obj.Latitude + "</td></tr>";
				line += "<tr><td>Longitude = " + obj.Longitude + "</td></tr>";
				line += "<tr><td>ZIPCode = " + obj.ZIPCode + "</td></tr>";
				line += "<tr><td>Timezone = " + obj.TimeZone + "</td></tr>";
				line += "<tr><td>ISP = " + obj.ISP + "</td></tr>";
				line += "<tr><td>Domain = " + obj.Domain + "</td></tr>";
				line += "<tr><td>Netspeed = " + obj.NetSpeed + "</td></tr>";
				line += "<tr><td>IDDCode = " + obj.IDDCode + "</td></tr>";
				line += "<tr><td>AreaCode = " + obj.AreaCode + "</td></tr>";
				line += "<tr><td>WeatherStationCode = " + obj.WeatherStationCode + "</td></tr>";
				line += "<tr><td>WeatherStationName = " + obj.WeatherStationName + "</td></tr>";
				line += "<tr><td>MCC = " + obj.MCC + "</td></tr>";
				line += "<tr><td>MNC = " + obj.MNC + "</td></tr>";
				line += "<tr><td>MobileBrand = " + obj.MobileBrand + "</td></tr>";
				line += "<tr><td>Elevation = " + obj.Elevation + "</td></tr>";
				line += "<tr><td>UsageType = " + obj.UsageType + "</td></tr>";
				line += "<tr><td>AddressType = " + obj.AddressType + "</td></tr>";
				line += "<tr><td>Category = " + obj.Category + "</td></tr>";
				line += "</table>";
			}
			else
			{
				line += "Error : " + str + "<br>";
			}
			this.litResult.Text = line;
			obj = null;
		}

		#region Web Form Designer generated code
		override protected void OnInit(EventArgs e)
		{
			//
			// CODEGEN: This call is required by the ASP.NET Web Form Designer.
			//
			InitializeComponent();
			base.OnInit(e);
		}
		
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		private void InitializeComponent()
		{    
			this.btnSubmit.Click += new System.EventHandler(this.btnSubmit_Click);
			this.Load += new System.EventHandler(this.Page_Load);

		}
		#endregion

		private void btnSubmit_Click(object sender, System.EventArgs e)
		{
			this.Lookup();
		}
	}
}
