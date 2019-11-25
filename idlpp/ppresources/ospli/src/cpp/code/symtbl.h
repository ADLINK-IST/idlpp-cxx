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
#include "dds_cpp.h"

#ifndef _SYMTBL_
#define _SYMTBL_

#define DEF_PREDEF  0
#define DEF_CMDLINE 1
#define DEF_DEFINE  2

#ifdef __cplusplus
extern "C" {
#endif

typedef struct _def
{
  struct _def *link;
  char *name;
  int nargs;
  unsigned char *repl;
  int how;
} DEF;

extern DEF ** symtbl;
extern int symtbl_size;
extern int n_in_table;

extern DEF * find_def (char *);
extern void init_symtbl (void);
extern void define (const char *, int, unsigned char *, int);
extern void undef (const char *);
extern void defd (char *, int);
extern void undef_predefs (void);
extern void expand_def (DEF *);

#ifdef __cplusplus
}
#endif

#endif
