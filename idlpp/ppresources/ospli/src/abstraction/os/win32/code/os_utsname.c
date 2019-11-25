/*
 *                         OpenSplice DDS
 *
 *   This software and documentation are Copyright 2006 to 2015 PrismTech
 *   Limited and its licensees. All rights reserved. See file:
 *
 *                     $OSPL_HOME/LICENSE 
 *
 *   for full copyright notice and license terms. 
 *
 */

#include <os_utsname.h>
#include <os_stdlib.h>
#include "os_win32incs.h"

os_int32 os_uname(os_utsname *name)
{
   OSVERSIONINFO verInf;
   SYSTEM_INFO sysInf;
   char hostname[255];

   verInf.dwOSVersionInfoSize = sizeof(OSVERSIONINFO);
   GetVersionEx(&verInf);
   GetSystemInfo(&sysInf);

   switch(sysInf.wProcessorArchitecture)
   {
      case PROCESSOR_ARCHITECTURE_AMD64:
         os_sprintf (name->machine, "x86_64");
         break;
      case PROCESSOR_ARCHITECTURE_INTEL:
         os_sprintf (name->machine, "x86");
         break;
      default:
         os_sprintf (name->machine, "unknown");
   }

   os_gethostname (hostname, 255);

   os_sprintf (name->sysname, "Windows");
   os_strcpy (name->nodename, hostname);
   os_sprintf (name->release, "Build #%d", verInf.dwBuildNumber);
   os_sprintf (name->version, "%2d.%2d", verInf.dwMajorVersion, verInf.dwMinorVersion);

    return 0;
}

