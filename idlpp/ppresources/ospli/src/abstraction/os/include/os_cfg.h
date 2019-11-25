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
#ifndef OS_CFG_H
#define OS_CFG_H

typedef struct os_cfg_handle
{
   char *ptr;
   int isStatic;
   size_t size;
} os_cfg_handle;

typedef FILE os_cfg_file; 

os_cfg_file *os_fileOpenURI(const char *uri);
os_cfg_handle *os_fileReadURI(const char *uri);

os_cfg_handle *os_cfgRead(const char *uri);

void os_cfgRelease(os_cfg_handle *cfg);

#endif
