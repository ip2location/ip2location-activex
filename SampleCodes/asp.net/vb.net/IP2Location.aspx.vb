
Public Class IP2Location
    Inherits System.Web.UI.Page

#Region " Web Form Designer Generated Code "

    'This call is required by the Web Form Designer.
    <System.Diagnostics.DebuggerStepThrough()> Private Sub InitializeComponent()

    End Sub
    Protected WithEvents txtIPAddress As System.Web.UI.WebControls.TextBox
    Protected WithEvents btnSubmit As System.Web.UI.WebControls.Button
    Protected WithEvents litResult As System.Web.UI.WebControls.Literal

    'NOTE: The following placeholder declaration is required by the Web Form Designer.
    'Do not delete or move it.
    Private designerPlaceholderDeclaration As System.Object

    Private Sub Page_Init(ByVal sender As System.Object, ByVal e As System.EventArgs) Handles MyBase.Init
        'CODEGEN: This method call is required by the Web Form Designer
        'Do not modify it using the code editor.
        InitializeComponent()
    End Sub

#End Region

    Private Sub Page_Load(ByVal sender As System.Object, ByVal e As System.EventArgs) Handles MyBase.Load
        'Put user code to initialize the page here
    End Sub
    Private Sub Lookup()
        Dim IP As String = ""
        Dim str As String = ""
        Dim obj As New IP2LOCATIONLib.Country
        Dim line As String = ""
        IP = Me.txtIPAddress.Text.Trim
        line += "<h1><u>Lookup Result</u></h1>"
        str = obj.LookUp(System.AppDomain.CurrentDomain.BaseDirectory & "IP2LOCATION-LITE-DB1.BIN", IP)
        If str = "OK" Then
            line += "<table>"
            line += "<tr><td>CountryShort = " & obj.CountryShort & "</td></tr>"
            line += "<tr><td>CountryLong = " & obj.CountryLong & "</td></tr>"
            line += "<tr><td>Region = " & obj.Region & "</td></tr>"
            line += "<tr><td>City = " & obj.City & "</td></tr>"
            line += "<tr><td>Latitude = " & obj.Latitude & "</td></tr>"
            line += "<tr><td>Longitude = " & obj.Longitude & "</td></tr>"
            line += "<tr><td>ZIPCode = " & obj.ZIPCode & "</td></tr>"
            line += "<tr><td>Timezone = " & obj.TimeZone & "</td></tr>"
            line += "<tr><td>ISP = " & obj.ISP & "</td></tr>"
            line += "<tr><td>Domain = " & obj.Domain & "</td></tr>"
            line += "<tr><td>Netspeed = " & obj.NetSpeed & "</td></tr>"
            line += "<tr><td>IDDCode = " & obj.IDDCode & "</td></tr>"
            line += "<tr><td>AreaCode = " & obj.AreaCode & "</td></tr>"
            line += "<tr><td>WeatherStationCode = " & obj.WeatherStationCode & "</td></tr>"
            line += "<tr><td>WeatherStationName = " & obj.WeatherStationName & "</td></tr>"
            line += "<tr><td>MCC = " & obj.MCC & "</td></tr>"
            line += "<tr><td>MNC = " & obj.MNC & "</td></tr>"
            line += "<tr><td>MobileBrand = " & obj.MobileBrand & "</td></tr>"
            line += "<tr><td>Elevation = " & obj.Elevation & "</td></tr>"
            line += "<tr><td>UsageType = " & obj.UsageType & "</td></tr>"
            line += "<tr><td>AddressType = " & obj.AddressType & "</td></tr>"
            line += "<tr><td>Category = " & obj.Category & "</td></tr>"
            line += "<tr><td>District = " & obj.District & "</td></tr>"
            line += "<tr><td>ASN = " & obj.ASN & "</td></tr>"
            line += "<tr><td>AS = " & obj.AS & "</td></tr>"
            line += "</table>"
        Else
            line += "Error : " & str & "<br>"
        End If
        Me.litResult.Text = line
        obj = Nothing
    End Sub

    Private Sub btnSubmit_Click(ByVal sender As System.Object, ByVal e As System.EventArgs) Handles btnSubmit.Click
        Me.Lookup()
    End Sub
End Class
