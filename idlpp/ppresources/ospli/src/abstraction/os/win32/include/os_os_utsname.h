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

#ifndef OS_WIN32_UTSNAME_H
#define OS_WIN32_UTSNAME_H


#define OS_OS_SYS_NMLN       257     /* 4.0 size of utsname elements */
                                     /* Must be at least 257 to      */
                                     /* support Internet hostnames.  */

typedef struct os_os_utsname {
        char    sysname[OS_OS_SYS_NMLN];
        char    nodename[OS_OS_SYS_NMLN];
        char    release[OS_OS_SYS_NMLN];
        char    version[OS_OS_SYS_NMLN];
        char    machine[OS_OS_SYS_NMLN];
} os_os_utsname;

#undef OS_OS_SYS_NMLN

#endif
