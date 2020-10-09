package com.prismtech.lite.generator;

import java.util.*;
import com.prismtech.lite.ScopedName;

public class SequenceType extends AbstractType
{
  public SequenceType (Type subtype, long bound)
  {
    this.subtype = subtype;
    realsub = subtype;
    while (realsub instanceof TypedefType)
    {
      realsub = ((TypedefType)realsub).getRef ();
    }
    ctype = "dds_sequence_t";
    this.xmlbound = bound;
    this.bound = 0;
  }

  private SequenceType (Type subtype, String ctype, long bound)
  {
    this.subtype = subtype;
    realsub = subtype;
    while (realsub instanceof TypedefType)
    {
      realsub = ((TypedefType)realsub).getRef ();
    }
    this.ctype = ctype;
    this.xmlbound = bound;
    this.bound = 0;
  }

  public Type dup ()
  {
    return new SequenceType (subtype.dup (), ctype, bound);
  }

  public SequenceType clone (String name)
  {
    return new SequenceType (subtype.dup (), name, bound);
  }

  public boolean containsUnion ()
  {
    Type t = subtype;
    while (t instanceof TypedefType)
    {
      t = ((TypedefType)t).getRef ();
    }
    return t.containsUnion ();
  }

  public ArrayList <String> getMetaOp (String myname, String structname)
  {
    ArrayList <String> result = new ArrayList <String> ();
    String offset;

    if (myname != null)
    {
      offset = "offsetof (" + structname + ", " + myname + ")";
    }
    else
    {
      offset = "0u";
    }

    // Bounded sequences were added in an incompatible manner in this fork of the IDL
    // compiler, the correct way would have been to add a new opcode because the encoding
    // understood by the serializer doesn't have room for a bound
    //
    // Given that this compiler is end-of-life and bounded sequences currently have no
    // effect anyway on the type or the encoding, only on the handling of samples
    // containing oversize sequences (and no application should ever generate those), the
    // pragmatic fix is to ignore the sequence bound.
    if (bound == 0)
    {
      result.add (new String
      (
        "DDS_OP_ADR | DDS_OP_TYPE_SEQ | " + realsub.getSubOp () + ", " +
        offset
      ));
    }
    else
    {
      result.add (new String
      (
        "DDS_OP_ADR | DDS_OP_TYPE_BSQ | " + realsub.getSubOp () + ", " +
        offset + ", " + Long.toString (bound)
      ));
    }

    if (!(realsub instanceof BasicType))
    {
      if (realsub instanceof BoundedStringType)
      {
        if (bound != 0)
        {
          result.add ("0, ");
        }
        result.add (Long.toString (((BoundedStringType)realsub).getBound () + 1));
      }
      else
      {
        if (bound != 0)
        {
          result.add (new String ("(" + new Integer (getMetaOpSize ()) + "u << 16u) + 5u, sizeof (" + realsub.getCType () + ")"));
        }
        else
        {
          result.add (new String ("sizeof (" + realsub.getCType () + "), (" + new Integer (getMetaOpSize ()) + "u << 16u) + 4u"));
        }
        result.addAll (realsub.getMetaOp (null, null));
        result.add (new String ("DDS_OP_RTS"));
      }
    }
    return result;
  }

  public String getSubOp ()
  {
    return "DDS_OP_SUBTYPE_SEQ";
  }

  public String getOp ()
  {
    return "DDS_OP_TYPE_SEQ";
  }

  public String getCType ()
  {
    return ctype;
  }

  public long getKeySize ()
  {
    return -1;
  }

  public int getMetaOpSize ()
  {
    if (realsub instanceof BasicType)
    {
      return (bound == 0) ? 2 : 3;
    }
    else
    {
      if (realsub instanceof BoundedStringType)
      {
        return (bound == 0) ? 3 : 5;
      }
      else
      {
        return ((bound == 0) ? 5 : 6) + realsub.getMetaOpSize ();
      }
    }
  }

  public Alignment getAlignment ()
  {
    return Alignment.PTR;
  }

  public void getXML (StringBuffer str, ModuleContext mod)
  {
    str.append ("<Sequence");
    if (xmlbound != 0)
    {
      str.append (" size=\\\"" + Long.toString (xmlbound) + "\\\"");
    }
    str.append (">");
    subtype.getXML (str, mod);
    str.append ("</Sequence>");
  }

  public void populateDeps (Set <ScopedName> depset, NamedType current)
  {
    subtype.populateDeps (depset, current);
  }

  public boolean depsOK (Set <ScopedName> deps)
  {
    return TypeUtil.deptest (subtype, deps, null);
  }

  private final Type subtype;
  private Type realsub;
  private final String ctype;
  private final long xmlbound;
  private final long bound;
}
