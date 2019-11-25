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
#include "os.h"

extern char * fe_cpp_keyword (const char * id);

static const char * fe_cpp_keywords [] =
{
   "asm",
   "auto",
   "bool",
   "break",
   "case",
   "catch",
   "char",
   "class",
   "const",
   "const_cast",
   "continue",
   "default",
   "delete",
   "do",
   "double",
   "dynamic_cast",
   "else",
   "enum",
   "explicit",
   "extern",
   "false",
   "float",
   "for",
   "friend",
   "goto",
   "if",
   "inline",
   "int",
   "long",
   "mutable",
   "namespace",
   "new",
   "operator",
   "private",
   "protected",
   "public",
   "register",
   "reinterpret_cast",
   "return",
   "short",
   "signed",
   "sizeof",
   "static",
   "static_cast",
   "struct",
   "switch",
   "template",
   "this",
   "throw",
   "true",
   "try",
   "typedef",
   "typeid",
   "typename",
   "union",
   "unsigned",
   "using",
   "virtual",
   "void",
   "volatile",
   "wchar_t",
   "while",
   0
};

char * fe_cpp_keyword (const char * id)
{
   static const char * prefix = "__cxx_";
   static const char escape = '_';

   unsigned long i = 0;
   char * ret = 0;
   const char * test = id;

   if (id)
   {
      /* Remove identifier escaping */

      if (test[0] == escape)
      {
         test++;
      }

      /* Prefix C++ keywords with _cxx_ */

      while (fe_cpp_keywords[i])
      {
         if (strcmp (test, fe_cpp_keywords[i]) == 0)
         {
            ret = (char*) os_malloc (strlen (test) + strlen (prefix) + 1);
            strcpy (ret, prefix);
            strcat (ret, test);
            break;
         }
         i++;
      }

      if (ret == 0)
      {
         ret = (char*) os_malloc (strlen (id) + 1);
         strcpy (ret, id);
      }
   }

   return ret;
}
