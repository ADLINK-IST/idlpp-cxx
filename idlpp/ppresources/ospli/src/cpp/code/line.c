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
#include "cpp_io.h"
#include "if.h"

extern void do_line (void)
{
   char c;

   outputc('#');
   while ((c = Get()) != '\n')
   {
      outputc(c);
   }
}
