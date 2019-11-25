/*
 *                         Vortex Lite
 *
 *   This software and documentation are Copyright 2006 to 2017 ADLINK
 *   Technology Limited, its affiliated companies and licensors. 
 *   All rights reserved. See file:
 *
 *                     $LITE_HOME/LICENSE
 *
 *   for full copyright notice and license terms.
 *
 */

#ifndef SACPP_DDS_BASIC_TYPES_H
#define SACPP_DDS_BASIC_TYPES_H

#include <stdint.h>
#include <cstring>
#include "cpp_dcps_if.h"
#include <string>
/**
 * @file
 * @bug OSPL-2272 We've no business/should have no need to define NULL, TRUE, & FALSE. Wrongly. */
#if !defined NULL
#define NULL ((void *)0)
#endif

#if !defined FALSE
#define FALSE (0)
#endif

#if !defined TRUE
#define TRUE (!FALSE)
#endif

/* Compiler Silencing macros
 * Some compilers complain about parameters that are not used.
 */
#if !defined (OS_UNUSED_ARG)
#define OS_UNUSED_ARG(a) (void) (a)
#endif

class OS_API DDS_DCPSUStrSeq;
template <class T = DDS_DCPSUStrSeq> class DDS_DCPSUStrSeq_var;
template <class T = DDS_DCPSUStrSeq> class DDS_DCPSUStrSeq_out;
template <class T, typename X = T> class DDS_DCPSUVLSeq;
template <class T, typename X = T> class DDS_DCPSUFLSeq;
template <class T, typename X = T> class DDS_DCPSUObjSeq;
template <typename X> class DDS_DCPSUStrSeqT;
template <class T> class DDS_DCPSSequence_var;
template <class T> class DDS_DCPSSequence_out;
template <class T> class DDS_DCPSInterface_var;
template <class T> class DDS_DCPSInterface_out;
template <class T> class DDS_DCPSInterface_mgr;
template <class T> class DDSValueBase_mgr;
template <class T> class DDS_DCPS_var;
template <class T> class DDS_DCPS_out;
template <class T> class DDS_DCPS_mgr;

namespace DDS
{
   // Primitive types
   /**
    * @bug OSPL-918 This should be bool */
   typedef unsigned char Boolean;
   typedef Boolean& Boolean_out;
   typedef Boolean* Boolean_ptr;

   typedef char Char;
   typedef Char& Char_out;
   typedef Char* Char_ptr;

   typedef unsigned char Octet;
   typedef Octet& Octet_out;
   typedef Octet* Octet_ptr;

   typedef short Short;
   typedef Short& Short_out;
   typedef Short* Short_ptr;

   typedef unsigned short UShort;
   typedef UShort& UShort_out;
   typedef UShort* UShort_ptr;

   typedef int32_t Long;
   typedef Long& Long_out;
   typedef Long* Long_ptr;

   typedef uint32_t ULong;
   typedef ULong& ULong_out;
   typedef ULong* ULong_ptr;

   typedef float Float;
   typedef Float& Float_out;
   typedef Float* Float_ptr;

   typedef double Double;
   typedef Double& Double_out;
   typedef Double* Double_ptr;

   typedef void* Opaque;

   typedef int64_t LongLong;
   typedef LongLong& LongLong_out;
   typedef LongLong* LongLong_ptr;

   typedef uint64_t ULongLong;
   typedef ULongLong& ULongLong_out;
   typedef ULongLong* ULongLong_ptr;

   typedef Char* String;
   class OS_API String_var;
   class OS_API String_mgr;
   class OS_API String_inout;
   class OS_API String_out;
   class OS_API String_for_seq;

   enum { enum32 = 0x7ffffff };

   enum CompletionStatus { COMPLETED_YES, COMPLETED_NO, COMPLETED_MAYBE };

   typedef String ObjectId;

   enum TCKind
   {
      tk_null, tk_void, tk_short, tk_long,
      tk_ushort, tk_ulong, tk_float, tk_double,
      tk_boolean, tk_char, tk_octet, tk_any,
      tk_TypeCode, tk_Principal, tk_objref, tk_struct,
      tk_union, tk_enum, tk_string, tk_sequence,
      tk_array, tk_alias, tk_except, tk_longlong,
      tk_ulonglong, tk_longdouble, tk_wchar, tk_wstring,
      tk_fixed, tk_local_interface, _TCKind = enum32
   };

   class OS_API Object;
   typedef Object* Object_ptr;
   typedef DDS_DCPSInterface_var<Object> Object_var;
   typedef DDS_DCPSInterface_out<Object> Object_out;
   typedef DDS_DCPSInterface_mgr<Object> Object_mgr;
   OS_API void release(Object_ptr p);
   OS_API Boolean is_nil(Object_ptr p);

   class OS_API LocalObject;
   typedef LocalObject* LocalObject_ptr;
   typedef DDS_DCPSInterface_var<LocalObject> LocalObject_var;
   typedef DDS_DCPSInterface_out<LocalObject> LocalObject_out;
   typedef DDS_DCPSInterface_mgr<LocalObject> LocalObject_mgr;
   OS_API void release(LocalObject_ptr p);

   class OS_API Exception;
   typedef Exception* Exception_ptr;

   class OS_API UserException;
   typedef UserException* UserException_ptr;

   class OS_API SystemException;
   typedef SystemException* SystemException_ptr;

   class OS_API ExceptionInitializer;

   // Standard string functions
   OS_API char * string_alloc (ULong len);
   OS_API char * string_dup   (const char* str);
   OS_API void string_free  (char * str);
   OS_API Long string_cmp (const char * str1, const char * str2);
   OS_API Boolean is_nil (Object_ptr ptr);

   class OS_API ValueBase;
   OS_API void add_ref(ValueBase* vb);
   OS_API void remove_ref(ValueBase* vb);

   //   class OS_API Counter;
}

/* ************************************************************************** */
/*                           Inline Implementations                           */
/* ************************************************************************** */

OS_API inline char * DDS::string_alloc (DDS::ULong len)
{
   char * ret = new char [len + 1];
   ret[0] = '\0';
   return ret;
}

OS_API inline void DDS::string_free (char * str)
{
   delete [] str;
}

OS_API inline char * DDS::string_dup (const char * s)
{
   char * ret = 0;

   if (s)
   {
      ret = DDS::string_alloc ((DDS::ULong)strlen (s));
      strcpy(ret, s);
      /** @todo swaped with std function
      os_strcpy (ret, s);*/
   }

   return ret;
}

OS_API inline DDS::Long DDS::string_cmp (const char* str1, const char* str2)
{
   DDS::Long ret = 0;

   if ((str1 != 0) || (str2 != 0))
   {
      if ((str1 == 0) && (str2 != 0))
      {
         ret = 1;
      }
      else
      {
         if ((str1 != 0) && (str2 == 0))
         {
            ret = -1;
         }
         else
         {
            ret = strcmp (str1, str2);
         }
      }
   }

   return ret;
}

OS_API inline DDS::Boolean DDS::is_nil(DDS::Object_ptr ptr)
{
    return (ptr == NULL);
}

#undef OS_API

#endif  /* SACPP_DDS_BASIC_TYPES_H */
