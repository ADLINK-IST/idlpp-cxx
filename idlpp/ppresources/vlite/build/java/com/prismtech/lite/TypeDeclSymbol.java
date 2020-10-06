package com.prismtech.lite;

import java.util.List;

import com.prismtech.lite.parser.IDLParser;

public class TypeDeclSymbol extends TypeDefSymbol
{
  public TypeDeclSymbol
  (
    ScopedName name,
    IDLParser.Type_specContext definition,
    List<IDLParser.Fixed_array_sizeContext> dimensions,
    boolean isint,
    boolean isnonint
  )
  {
    super (name);
    if (definition.simple_type_spec () != null)
    {
      def = definition.getText ();
    }
    else
    {
      IDLParser.Constr_type_specContext cts = (IDLParser.Constr_type_specContext) definition.constr_type_spec ();
      if (cts.struct_type () != null) {
        def = cts.struct_type ().ID ().getText ();
      } else if (cts.union_type () != null) {
        def = cts.union_type ().ID ().getText ();
      } else {
        def = cts.enum_type ().ID ().getText ();
      }
    }
    this.isint = isint;
    this.isnonint = isnonint;
  }

  public String toString ()
  {
    return "Typedef = " + def;
  }

  public ScopedName definition ()
  {
    return new ScopedName(def);
  }

  public boolean isRelative ()
  {
    return !def.startsWith("::");
  }

  public boolean isInteger ()
  {
    return isint;
  }
  public boolean isNonintConst ()
  {
    return isnonint;
  }

  private String def;
  private boolean isint;
  private boolean isnonint;
}
