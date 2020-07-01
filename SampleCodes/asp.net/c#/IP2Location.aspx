<%@ Page language="c#" Codebehind="IP2Location.aspx.cs" AutoEventWireup="false" Inherits="IP2LocationActiveXSampleCSharp.IP2Location" %>
<!DOCTYPE HTML PUBLIC "-//W3C//DTD HTML 4.0 Transitional//EN" >
<HTML>
	<HEAD>
		<title>IP2Location™ ActiveX/COM DLL Demo in ASP.NET</title>
	</HEAD>
	<body>
		<FORM id="Form1" method="post" runat="server">
			<H1><B><U>Lookup Country by IP Address using IP2Location™ ActiveX/COM DLL</U></H1>
			<P></B>Enter an IPv4 or IPv6 address.<BR>
				<asp:TextBox id="txtIPAddress" runat="server"></asp:TextBox>
				<asp:Button id="btnSubmit" runat="server" Text="Submit"></asp:Button></P>
			<P>
				<asp:Literal id="litResult" runat="server"></asp:Literal></P>
		</FORM>
	</body>
</HTML>
