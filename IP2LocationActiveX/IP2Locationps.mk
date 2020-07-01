
IP2Locationps.dll: dlldata.obj IP2Location_p.obj IP2Location_i.obj
	link /dll /out:IP2Locationps.dll /def:IP2Locationps.def /entry:DllMain dlldata.obj IP2Location_p.obj IP2Location_i.obj \
		kernel32.lib rpcndr.lib rpcns4.lib rpcrt4.lib oleaut32.lib uuid.lib \

.c.obj:
	cl /c /Ox /DWIN32 /D_WIN32_WINNT=0x0400 /DREGISTER_PROXY_DLL \
		$<

clean:
	@del IP2Locationps.dll
	@del IP2Locationps.lib
	@del IP2Locationps.exp
	@del dlldata.obj
	@del IP2Location_p.obj
	@del IP2Location_i.obj
