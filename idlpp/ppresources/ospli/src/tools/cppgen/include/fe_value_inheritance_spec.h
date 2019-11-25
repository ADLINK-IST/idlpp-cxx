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
#ifndef _FE_VALUE_INHERITANCE_SPEC_HH
#define _FE_VALUE_INHERITANCE_SPEC_HH


// FE_ValueInheritance_Spec
//
// Internal class for FE to describe value inheritance_specs

/*
** DEPENDENCIES: utl_scoped_name.hh, ast_value.hh, utl_scope.hh,
**   ast_decl.hh
**
** USE: Included from fe.hh
*/

class FE_ValueInheritanceSpec
{

public:
   // Operations

   // Constructor(s)
   FE_ValueInheritanceSpec
   (
      bool truncatable,
      UTL_NameList *ihl,
      UTL_NameList *supl
   );

   virtual ~FE_ValueInheritanceSpec()
   {   
      if (pd_supports)
      {
         delete pd_supports;
      }
      if (pd_inherits)
      {
         delete pd_inherits;
      }
   }

   // Data Accessors
   AST_Value **inherits();
   long n_inherits();
   AST_Interface **supports();
   long n_supports();
   bool truncatable();

private:
   // Data
   AST_Value **pd_inherits;  // Inherited values
   long pd_n_inherits;  // How many
   AST_Interface **pd_supports;  // Supported Interfaces
   long pd_n_supports;  // How many
   bool pd_truncatable;

   // Operations

   // Compile the flattened unique list of values which this
   // value inherits from
   void compile_value_inheritance(UTL_NameList *l);
   void compile_inheritance(UTL_NameList *l);
};

#endif           // _FE_VALUE_INHERITANCE_SPEC_HH
