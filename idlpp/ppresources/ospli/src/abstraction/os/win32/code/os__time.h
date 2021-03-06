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
#ifndef OS_WIN32__TIME_H
#define OS_WIN32__TIME_H

void os_timeModuleInit(void);
void os_timeModuleExit(void);
void os_timeModuleReinit(const char* domainName);

#endif /*OS_WIN32__TIME_H*/
