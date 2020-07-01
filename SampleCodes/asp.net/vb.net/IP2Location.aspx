<%@ Page Language="vb" AutoEventWireup="false" Codebehind="IP2Location.aspx.vb" Inherits="IP2LocationActiveXSampleVB.IP2Location"%>
<!DOCTYPE HTML PUBLIC "-//W3C//DTD HTML 4.0 Transitional//EN">
<HTML>
	<HEAD>
		<title>IP2Location™ ActiveX/COM DLL Demo in ASP.NET</title>
	</HEAD>
	<body>
		<form id="Form1" method="post" runat="server">
			<H1><B><U>Lookup Country by IP Address using IP2Location™ ActiveX/COM DLL</U></H1>
			<P></B>Enter an IPv4 or IPv6 address.<BR>
				<asp:textbox id="txtIPAddress" runat="server"></asp:textbox><asp:button id="btnSubmit" runat="server" Text="Submit"></asp:button></P>
			<P><asp:literal id="litResult" runat="server"></asp:literal></P>
		</form>
	</body>
</HTML>
