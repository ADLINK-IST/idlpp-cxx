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

/****************************************************************
 * Initialization / Deinitialization                            *
 ****************************************************************/

/** \file os/darwin/code/os_init.c
 *  \brief Initialization / Deinitialization
 */

#include <sys/utsname.h>
#include "code/os__process.h"
#include "code/os__thread.h"
#include "code/os__sharedmem.h"
#include "os_abstract.h"
#include "os_report.h"
#include "../posix/code/os__mutex.h"
#include "os_atomics.h"

/** \brief Counter that keeps track of number of times os-layer is initialized */
static pa_uint32_t _ospl_osInitCount = PA_UINT32_INIT(0);

/** \brief OS layer initialization
 *
 * \b os_osInit calls:
 * - \b os_sharedMemoryInit
 * - \b os_threadInit
 */
void os_osInit (void)
{
  os_uint32 initCount;

  initCount = pa_inc32_nv(&_ospl_osInitCount);

  if (initCount == 1) {
    os_mutexModuleInit();
    os_threadModuleInit();
    os_reportInit(OS_FALSE);
    /*os_processModuleInit();*/
#ifndef LITE
    os_sharedMemoryInit();
#endif
  }

  return;
}

/** \brief OS layer deinitialization
 *
 * \b os_osExit calls:
 * - \b os_sharedMemoryExit
 * - \b os_threadExit
 */
void os_osExit (void)
{
  os_uint32 initCount;

  initCount = pa_dec32_nv(&_ospl_osInitCount);

  if (initCount == 0) {
#ifndef LITE
    os_sharedMemoryExit();
#endif
    /*os_processModuleExit();*/
    os_reportExit();
    os_threadModuleExit();
    os_mutexModuleExit();
  } else if ((initCount + 1) < initCount){
    /* The 0 boundary is passed, so os_osExit is called more often than
     * os_osInit. Therefore undo decrement as nothing happened and warn. */
    pa_inc32(&_ospl_osInitCount);
    OS_REPORT(OS_WARNING, "os_osExit", 1, "OS-layer not initialized");
    /* Fail in case of DEV, as it is incorrect API usage */
    assert(0);
  }
  return;
}

#ifndef LITE

/* This constructor is invoked when the library is loaded into a process. */
void __attribute__ ((constructor))
os__osInit(
        void)
{
    os_osInit();
}

/* This destructor is invoked when the library is unloaded from a process. */
void __attribute__ ((destructor))
os__osExit(
        void)
{
    os_osExit();
}

#endif

#include <../common/code/os_service.c>
