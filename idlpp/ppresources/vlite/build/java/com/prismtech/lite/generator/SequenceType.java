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
    this.bound = bound;
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
    this.bound = bound;
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

    result.add (new String
    (
      "DDS_OP_ADR | DDS_OP_TYPE_SEQ | " + realsub.getSubOp () + ", " +
      offset + ", " + Long.toString (bound)
    ));

    if (!(realsub instanceof BasicType))
    {
      if (realsub instanceof BoundedStringType)
      {
        result.add ("0, " + Long.toString (((BoundedStringType)realsub).getBound () + 1));
      }
      else
      {
        result.add (new String ("(" + new Integer (getMetaOpSize ()) + "u << 16u) + 5u, sizeof (" + realsub.getCType () + ")"));
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
      return 3;
    }
    else
    {
      if (realsub instanceof BoundedStringType)
      {
        return 5;
      }
      else
      {
        return 6 + realsub.getMetaOpSize ();
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
    if (bound != 0)
    {
      str.append (" size=\\\"" + Long.toString (bound) + "\\\"");
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
  private final long bound;
}
