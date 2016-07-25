# Microsoft Developer Studio Project File - Name="WordPad" - Package Owner=<4>
# Microsoft Developer Studio Generated Build File, Format Version 6.00
# ** DO NOT EDIT **

# TARGTYPE "Win32 (x86) Application" 0x0101

CFG=WordPad - Win32 Release
!MESSAGE This is not a valid makefile. To build this project using NMAKE,
!MESSAGE use the Export Makefile command and run
!MESSAGE 
!MESSAGE NMAKE /f "wordpad.mak".
!MESSAGE 
!MESSAGE You can specify a configuration when running NMAKE
!MESSAGE by defining the macro CFG on the command line. For example:
!MESSAGE 
!MESSAGE NMAKE /f "wordpad.mak" CFG="WordPad - Win32 Release"
!MESSAGE 
!MESSAGE Possible choices for configuration are:
!MESSAGE 
!MESSAGE "WordPad - Win32 Release" (based on "Win32 (x86) Application")
!MESSAGE "WordPad - Win32 Debug" (based on "Win32 (x86) Application")
!MESSAGE "WordPad - Win32 Unicode Release" (based on "Win32 (x86) Application")
!MESSAGE "WordPad - Win32 Unicode Debug" (based on "Win32 (x86) Application")
!MESSAGE 

# Begin Project
# PROP AllowPerConfigDependencies 0
# PROP Scc_ProjName ""
# PROP Scc_LocalPath ""
CPP=cl.exe
MTL=midl.exe
RSC=rc.exe

!IF  "$(CFG)" == "WordPad - Win32 Release"

# PROP BASE Use_MFC 6
# PROP BASE Use_Debug_Libraries 0
# PROP BASE Output_Dir ".\Release"
# PROP BASE Intermediate_Dir ".\Release"
# PROP BASE Target_Dir ""
# PROP Use_MFC 6
# PROP Use_Debug_Libraries 0
# PROP Output_Dir ".\Release"
# PROP Intermediate_Dir ".\Release"
# PROP Target_Dir ""
# ADD BASE CPP /nologo /MD /W3 /GX /O2 /D "WIN32" /D "NDEBUG" /D "_WINDOWS" /D "_AFXDLL" /D "_MBCS" /FR /Yu"stdafx.h" /c
# ADD CPP /nologo /MD /W4 /GX /O2 /D "WIN32" /D "NDEBUG" /D "_WINDOWS" /D "_AFXDLL" /D "_MBCS" /FR /Yu"stdafx.h" /FD /c
# ADD BASE MTL /nologo /D "NDEBUG" /win32
# ADD MTL /nologo /D "NDEBUG" /mktyplib203 /win32
# ADD BASE RSC /l 0x409 /d "NDEBUG" /d "_AFXDLL"
# ADD RSC /l 0x409 /d "NDEBUG" /d "_VC60" /d "_AFXDLL"
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
LINK32=link.exe
# ADD BASE LINK32 /nologo /subsystem:windows /machine:I386
# ADD LINK32 /nologo /subsystem:windows /machine:I386

!ELSEIF  "$(CFG)" == "WordPad - Win32 Debug"

# PROP BASE Use_MFC 6
# PROP BASE Use_Debug_Libraries 1
# PROP BASE Output_Dir ".\Debug"
# PROP BASE Intermediate_Dir ".\Debug"
# PROP BASE Target_Dir ""
# PROP Use_MFC 6
# PROP Use_Debug_Libraries 1
# PROP Output_Dir ".\Debug"
# PROP Intermediate_Dir ".\Debug"
# PROP Target_Dir ""
# ADD BASE CPP /nologo /MDd /W3 /Gm /GX /Zi /Od /D "WIN32" /D "_DEBUG" /D "_WINDOWS" /D "_AFXDLL" /D "_MBCS" /FR /Yu"stdafx.h" /c
# ADD CPP /nologo /MDd /W4 /Gm /GX /ZI /Od /D "WIN32" /D "_DEBUG" /D "_WINDOWS" /D "_AFXDLL" /D "_MBCS" /FR /Yu"stdafx.h" /FD /c
# ADD BASE MTL /nologo /D "_DEBUG" /win32
# ADD MTL /nologo /D "_DEBUG" /mktyplib203 /win32
# ADD BASE RSC /l 0x409 /d "_DEBUG" /d "_AFXDLL"
# ADD RSC /l 0x409 /d "_DEBUG" /d "_AFXDLL" /d "_VC60"
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
LINK32=link.exe
# ADD BASE LINK32 /nologo /subsystem:windows /debug /machine:I386
# ADD LINK32 /nologo /subsystem:windows /debug /machine:I386

!ELSEIF  "$(CFG)" == "WordPad - Win32 Unicode Release"

# PROP BASE Use_MFC 6
# PROP BASE Use_Debug_Libraries 0
# PROP BASE Output_Dir ".\WordPad_"
# PROP BASE Intermediate_Dir ".\WordPad_"
# PROP BASE Target_Dir ""
# PROP Use_MFC 6
# PROP Use_Debug_Libraries 0
# PROP Output_Dir ".\UniRelease"
# PROP Intermediate_Dir ".\UniRelease"
# PROP Target_Dir ""
# ADD BASE CPP /nologo /MD /W3 /GX /O2 /D "WIN32" /D "NDEBUG" /D "_WINDOWS" /D "_AFXDLL" /D "_MBCS" /FR /Yu"stdafx.h" /c
# ADD CPP /nologo /MD /W4 /GX /O2 /D "NDEBUG" /D "WIN32" /D "_WINDOWS" /D "_AFXDLL" /D "_MBCS" /D "_UNICODE" /D "UNICODE" /FR /Yu"stdafx.h" /FD /c
# ADD BASE MTL /nologo /D "NDEBUG" /win32
# ADD MTL /nologo /D "NDEBUG" /mktyplib203 /win32
# ADD BASE RSC /l 0x409 /d "NDEBUG" /d "_AFXDLL"
# ADD RSC /l 0x409 /d "NDEBUG" /d "_VC60" /d "_AFXDLL"
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
LINK32=link.exe
# ADD BASE LINK32 /nologo /subsystem:windows /machine:I386
# ADD LINK32 /nologo /entry:"wWinMainCRTStartup" /subsystem:windows /machine:I386

!ELSEIF  "$(CFG)" == "WordPad - Win32 Unicode Debug"

# PROP BASE Use_MFC 6
# PROP BASE Use_Debug_Libraries 1
# PROP BASE Output_Dir ".\WordPad0"
# PROP BASE Intermediate_Dir ".\WordPad0"
# PROP BASE Target_Dir ""
# PROP Use_MFC 6
# PROP Use_Debug_Libraries 1
# PROP Output_Dir ".\UniDebug"
# PROP Intermediate_Dir ".\UniDebug"
# PROP Target_Dir ""
# ADD BASE CPP /nologo /MDd /W3 /Gm /GX /Zi /Od /D "WIN32" /D "_DEBUG" /D "_WINDOWS" /D "_AFXDLL" /D "_MBCS" /FR /Yu"stdafx.h" /c
# ADD CPP /nologo /MDd /W4 /Gm /GX /ZI /Od /D "_DEBUG" /D "WIN32" /D "_WINDOWS" /D "_AFXDLL" /D "_MBCS" /D "_UNICODE" /D "UNICODE" /FR /Yu"stdafx.h" /FD /c
# ADD BASE MTL /nologo /D "_DEBUG" /win32
# ADD MTL /nologo /D "_DEBUG" /mktyplib203 /win32
# ADD BASE RSC /l 0x409 /d "_DEBUG" /d "_AFXDLL"
# ADD RSC /l 0x409 /d "_DEBUG" /d "_VC60" /d "_AFXDLL"
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
LINK32=link.exe
# ADD BASE LINK32 /nologo /subsystem:windows /debug /machine:I386
# ADD LINK32 /nologo /entry:"wWinMainCRTStartup" /subsystem:windows /debug /machine:I386

!ENDIF 

# Begin Target

# Name "WordPad - Win32 Release"
# Name "WordPad - Win32 Debug"
# Name "WordPad - Win32 Unicode Release"
# Name "WordPad - Win32 Unicode Debug"
# Begin Group "Source Files"

# PROP Default_Filter "cpp;c;cxx;rc;def;r;odl;hpj;bat;for;f90"
# Begin Source File

SOURCE=..\src\buttondi.cpp
# End Source File
# Begin Source File

SOURCE=..\src\chicdial.cpp
# End Source File
# Begin Source File

SOURCE=..\src\cntritem.cpp
# End Source File
# Begin Source File

SOURCE=..\src\colorlis.cpp
# End Source File
# Begin Source File

SOURCE=..\src\datedial.cpp
# End Source File
# Begin Source File

SOURCE=..\src\ddxm.cpp
# End Source File
# Begin Source File

SOURCE=..\src\docopt.cpp
# End Source File
# Begin Source File

SOURCE=..\src\doctype.cpp
# End Source File
# Begin Source File

SOURCE=..\src\filenewd.cpp
# End Source File
# Begin Source File

SOURCE=..\src\formatba.cpp
# End Source File
# Begin Source File

SOURCE=..\src\formatpa.cpp
# End Source File
# Begin Source File

SOURCE=..\src\formatta.cpp
# End Source File
# Begin Source File

SOURCE=..\src\ipframe.cpp
# End Source File
# Begin Source File

SOURCE=..\src\key.cpp
# End Source File
# Begin Source File

SOURCE=..\src\listdlg.cpp
# End Source File
# Begin Source File

SOURCE=..\src\mainfrm.cpp
# End Source File
# Begin Source File

SOURCE=..\src\multconv.cpp
# End Source File
# Begin Source File

SOURCE=..\src\options.cpp
# End Source File
# Begin Source File

SOURCE=..\src\optionsh.cpp
# End Source File
# Begin Source File

SOURCE=..\src\pageset.cpp
# End Source File
# Begin Source File

SOURCE=..\src\ruler.cpp
# End Source File
# Begin Source File

SOURCE=..\src\srvritem.cpp
# End Source File
# Begin Source File

SOURCE=..\src\stdafx.cpp
# ADD CPP /Yc"stdafx.h"
# End Source File
# Begin Source File

SOURCE=..\src\strings.cpp
# End Source File
# Begin Source File

SOURCE=..\src\unitspag.cpp
# End Source File
# Begin Source File

SOURCE=..\src\wordpad.cpp
# End Source File
# Begin Source File

SOURCE=..\src\WordPad.rc
# End Source File
# Begin Source File

SOURCE=..\src\wordpdoc.cpp
# End Source File
# Begin Source File

SOURCE=..\src\wordpvw.cpp
# End Source File
# Begin Source File

SOURCE=..\src\XTrueColorToolBar.cpp

!IF  "$(CFG)" == "WordPad - Win32 Release"

# ADD CPP /W4

!ELSEIF  "$(CFG)" == "WordPad - Win32 Debug"

# ADD CPP /W4 /Yu

!ELSEIF  "$(CFG)" == "WordPad - Win32 Unicode Release"

# ADD CPP /W4

!ELSEIF  "$(CFG)" == "WordPad - Win32 Unicode Debug"

# ADD CPP /W4

!ENDIF 

# End Source File
# End Group
# Begin Group "Header Files"

# PROP Default_Filter "h;hpp;hxx;inl;fi;fd"
# Begin Source File

SOURCE=..\src\buttondi.h
# End Source File
# Begin Source File

SOURCE=..\src\chicdial.h
# End Source File
# Begin Source File

SOURCE=..\src\cntritem.h
# End Source File
# Begin Source File

SOURCE=..\src\colorlis.h
# End Source File
# Begin Source File

SOURCE=..\src\datedial.h
# End Source File
# Begin Source File

SOURCE=..\src\ddxm.h
# End Source File
# Begin Source File

SOURCE=..\src\docopt.h
# End Source File
# Begin Source File

SOURCE=..\src\doctype.h
# End Source File
# Begin Source File

SOURCE=..\src\filenewd.h
# End Source File
# Begin Source File

SOURCE=..\src\formatba.h
# End Source File
# Begin Source File

SOURCE=..\src\formatpa.h
# End Source File
# Begin Source File

SOURCE=..\src\formatta.h
# End Source File
# Begin Source File

SOURCE=..\src\helpids.h
# End Source File
# Begin Source File

SOURCE=..\src\ipframe.h
# End Source File
# Begin Source File

SOURCE=..\src\key.h
# End Source File
# Begin Source File

SOURCE=..\src\listdlg.h
# End Source File
# Begin Source File

SOURCE=..\src\mainfrm.h
# End Source File
# Begin Source File

SOURCE=..\src\mswd6_32.h
# End Source File
# Begin Source File

SOURCE=..\src\multconv.h
# End Source File
# Begin Source File

SOURCE=..\src\options.h
# End Source File
# Begin Source File

SOURCE=..\src\optionsh.h
# End Source File
# Begin Source File

SOURCE=..\src\pageset.h
# End Source File
# Begin Source File

SOURCE=..\src\resource.h
# End Source File
# Begin Source File

SOURCE=..\src\ruler.h
# End Source File
# Begin Source File

SOURCE=..\src\srvritem.h
# End Source File
# Begin Source File

SOURCE=..\src\stdafx.h
# End Source File
# Begin Source File

SOURCE=..\src\strings.h
# End Source File
# Begin Source File

SOURCE=..\src\unitspag.h
# End Source File
# Begin Source File

SOURCE=..\src\wordpad.h
# End Source File
# Begin Source File

SOURCE=..\src\wordpdoc.h
# End Source File
# Begin Source File

SOURCE=..\src\wordpvw.h
# End Source File
# Begin Source File

SOURCE=..\src\XTrueColorToolBar.h
# End Source File
# End Group
# Begin Group "Resource Files"

# PROP Default_Filter "ico;cur;bmp;dlg;rc2;rct;cnt;rtf;gif;jpg;jpeg;jpe"
# Begin Source File

SOURCE=..\src\res\rtfdoc.ico
# End Source File
# Begin Source File

SOURCE=..\src\res\textdoc.ico
# End Source File
# Begin Source File

SOURCE=..\src\res\wordpad.ico
# End Source File
# Begin Source File

SOURCE=..\src\res\write.ico
# End Source File
# End Group
# End Target
# End Project
