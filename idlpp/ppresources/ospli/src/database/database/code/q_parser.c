
/* A Bison parser, made by GNU Bison 2.4.1.  */

/* Skeleton implementation for Bison's Yacc-like parsers in C
   
      Copyright (C) 1984, 1989, 1990, 2000, 2001, 2002, 2003, 2004, 2005, 2006
   Free Software Foundation, Inc.
   
   This program is free software: you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation, either version 3 of the License, or
   (at your option) any later version.
   
   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.
   
   You should have received a copy of the GNU General Public License
   along with this program.  If not, see <http://www.gnu.org/licenses/>.  */

/* As a special exception, you may create a larger work that contains
   part or all of the Bison parser skeleton and distribute that work
   under terms of your choice, so long as that work isn't itself a
   parser generator using the skeleton or a modified version thereof
   as a parser skeleton.  Alternatively, if you modify or redistribute
   the parser skeleton itself, you may (at your option) remove this
   special exception, which will cause the skeleton and the resulting
   Bison output files to be licensed under the GNU General Public
   License without this special exception.
   
   This special exception was added by the Free Software Foundation in
   version 2.2 of Bison.  */

/* C LALR(1) parser skeleton written by Richard Stallman, by
   simplifying the original so-called "semantic" parser.  */

/* All symbols defined below should begin with yy or YY, to avoid
   infringing on user name space.  This should be done even for local
   variables, as they might otherwise be expanded by user macros.
   There are some unavoidable exceptions within include files to
   define necessary library symbols; they are noted "INFRINGES ON
   USER NAME SPACE" below.  */

/* Identify Bison output.  */
#define YYBISON 1

/* Bison version.  */
#define YYBISON_VERSION "2.4.1"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1

/* Using locations.  */
#define YYLSP_NEEDED 0



/* Copy the first part of user declarations.  */

/* Line 189 of yacc.c  */
#line 1 "/home/dds/Lite/vlite/build/ospli/src/database/database/code/q_parser.y"

#include "os_stdlib.h"
#include "c_base.h"
#include "c_collection.h"
#include "q_expr.h"
#include "q_helper.h"

#ifdef _WIN32
#define YY_NO_UNISTD_H
#define YYMALLOC malloc
#define YYFREE free
#endif

/* This define is needed for Win32, but also applies to other platforms */
#define YY_NEVER_INTERACTIVE 1

#define yyin                 q_parser_yyin
#define yyout                q_parser_yyout
#define yyparse              q_parser_yyparse
#define yychar               q_parser_yychar
#define yyerror              q_parser_yyerror
#define yylex                q_parser_yylex
#define yylval               q_parser_yylval
#define yyrestart            q_parser_yyrestart
#define yywrap               q_parser_yywrap
#define yytext               q_parser_yytext
#define yynerrs              q_parser_yynerrs
#define yyleng               q_parser_yyleng
#define yy_scan_string       q_parser_yy_scan_string
#define yy_scan_buffer       q_parser_yy_scan_buffer
#define yy_init_buffer       q_parser_yy_init_buffer
#define yy_flush_buffer      q_parser_yy_flush_buffer 
#define yy_switch_to_buffer  q_parser_yy_switch_to_buffer
#define yy_delete_buffer     q_parser_yy_delete_buffer
#define yy_create_buffer     q_parser_yy_create_buffer
#define yy_load_buffer_state q_parser_yy_load_buffer_state
#define yy_scan_bytes        q_parser_yy_scan_bytes

#define ResolveType(s,t) c_type(c_metaResolve(c_metaObject(s),#t))

#define ToBeImplemented NULL

#define c_dateNew(a,b,c,d) ToBeImplemented
#define c_timeNew(a,b,c,d) ToBeImplemented
#define c_timestampNew(a,b,c,d,e,f,g) ToBeImplemented

q_expr expr, exprError;

int q_parser_line = 1;
int q_parser_column = 0;
int q_parser_state = 0;

int yylex();
int yyerror ( char* text );
void dollar_warning();

/***********************************************************************
 *
 * Static function prototypes
 *
 ***********************************************************************/



/* Line 189 of yacc.c  */
#line 138 "q_parser.c"

/* Enabling traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif

/* Enabling verbose error messages.  */
#ifdef YYERROR_VERBOSE
# undef YYERROR_VERBOSE
# define YYERROR_VERBOSE 1
#else
# define YYERROR_VERBOSE 0
#endif

/* Enabling the token table.  */
#ifndef YYTOKEN_TABLE
# define YYTOKEN_TABLE 0
#endif


/* Tokens.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
   /* Put the tokens into the symbol table, so that GDB and other debuggers
      know about them.  */
   enum yytokentype {
     DEFINE = 258,
     AS_KEYWORD = 259,
     NIL = 260,
     TRUET = 261,
     FALSET = 262,
     LRPAR = 263,
     RRPAR = 264,
     MUL = 265,
     LIKE = 266,
     BETWEEN = 267,
     EQUAL = 268,
     NOTEQUAL = 269,
     GREATER = 270,
     LESS = 271,
     GREATEREQUAL = 272,
     LESSEQUAL = 273,
     NOT = 274,
     AND = 275,
     OR = 276,
     REF = 277,
     DOT = 278,
     ALL = 279,
     SELECT = 280,
     UNDEFINED = 281,
     FROM = 282,
     WHERE = 283,
     COLON = 284,
     COMMA = 285,
     DOUBLECOLON = 286,
     DOLLAR = 287,
     PERCENT = 288,
     SELECT_DISTINCT = 289,
     JOIN = 290,
     identifier = 291,
     stringLiteral = 292,
     queryId = 293,
     charLiteral = 294,
     longLiteral = 295,
     doubleLiteral = 296
   };
#endif



#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef union YYSTYPE
{

/* Line 214 of yacc.c  */
#line 65 "/home/dds/Lite/vlite/build/ospli/src/database/database/code/q_parser.y"

    c_char    *String;
    c_char     Char;
    c_longlong Integer;
    c_double   Float;
    c_type     Type;
    q_list     List;
    q_expr     Expr;
    q_tag      Tag;



/* Line 214 of yacc.c  */
#line 228 "q_parser.c"
} YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
#endif


/* Copy the second part of user declarations.  */


/* Line 264 of yacc.c  */
#line 240 "q_parser.c"

#ifdef short
# undef short
#endif

#ifdef YYTYPE_UINT8
typedef YYTYPE_UINT8 yytype_uint8;
#else
typedef unsigned char yytype_uint8;
#endif

#ifdef YYTYPE_INT8
typedef YYTYPE_INT8 yytype_int8;
#elif (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
typedef signed char yytype_int8;
#else
typedef short int yytype_int8;
#endif

#ifdef YYTYPE_UINT16
typedef YYTYPE_UINT16 yytype_uint16;
#else
typedef unsigned short int yytype_uint16;
#endif

#ifdef YYTYPE_INT16
typedef YYTYPE_INT16 yytype_int16;
#else
typedef short int yytype_int16;
#endif

#ifndef YYSIZE_T
# ifdef __SIZE_TYPE__
#  define YYSIZE_T __SIZE_TYPE__
# elif defined size_t
#  define YYSIZE_T size_t
# elif ! defined YYSIZE_T && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
#  include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  define YYSIZE_T size_t
# else
#  define YYSIZE_T unsigned int
# endif
#endif

#define YYSIZE_MAXIMUM ((YYSIZE_T) -1)

#ifndef YY_
# if YYENABLE_NLS
#  if ENABLE_NLS
#   include <libintl.h> /* INFRINGES ON USER NAME SPACE */
#   define YY_(msgid) dgettext ("bison-runtime", msgid)
#  endif
# endif
# ifndef YY_
#  define YY_(msgid) msgid
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YYUSE(e) ((void) (e))
#else
# define YYUSE(e) /* empty */
#endif

/* Identity function, used to suppress warnings about constant conditions.  */
#ifndef lint
# define YYID(n) (n)
#else
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static int
YYID (int yyi)
#else
static int
YYID (yyi)
    int yyi;
#endif
{
  return yyi;
}
#endif

#if ! defined yyoverflow || YYERROR_VERBOSE

/* The parser invokes alloca or malloc; define the necessary symbols.  */

# ifdef YYSTACK_USE_ALLOCA
#  if YYSTACK_USE_ALLOCA
#   ifdef __GNUC__
#    define YYSTACK_ALLOC __builtin_alloca
#   elif defined __BUILTIN_VA_ARG_INCR
#    include <alloca.h> /* INFRINGES ON USER NAME SPACE */
#   elif defined _AIX
#    define YYSTACK_ALLOC __alloca
#   elif defined _MSC_VER
#    include <malloc.h> /* INFRINGES ON USER NAME SPACE */
#    define alloca _alloca
#   else
#    define YYSTACK_ALLOC alloca
#    if ! defined _ALLOCA_H && ! defined _STDLIB_H && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
#     include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#     ifndef _STDLIB_H
#      define _STDLIB_H 1
#     endif
#    endif
#   endif
#  endif
# endif

# ifdef YYSTACK_ALLOC
   /* Pacify GCC's `empty if-body' warning.  */
#  define YYSTACK_FREE(Ptr) do { /* empty */; } while (YYID (0))
#  ifndef YYSTACK_ALLOC_MAXIMUM
    /* The OS might guarantee only one guard page at the bottom of the stack,
       and a page size can be as small as 4096 bytes.  So we cannot safely
       invoke alloca (N) if N exceeds 4096.  Use a slightly smaller number
       to allow for a few compiler-allocated temporary stack slots.  */
#   define YYSTACK_ALLOC_MAXIMUM 4032 /* reasonable circa 2006 */
#  endif
# else
#  define YYSTACK_ALLOC YYMALLOC
#  define YYSTACK_FREE YYFREE
#  ifndef YYSTACK_ALLOC_MAXIMUM
#   define YYSTACK_ALLOC_MAXIMUM YYSIZE_MAXIMUM
#  endif
#  if (defined __cplusplus && ! defined _STDLIB_H \
       && ! ((defined YYMALLOC || defined malloc) \
	     && (defined YYFREE || defined free)))
#   include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#   ifndef _STDLIB_H
#    define _STDLIB_H 1
#   endif
#  endif
#  ifndef YYMALLOC
#   define YYMALLOC malloc
#   if ! defined malloc && ! defined _STDLIB_H && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
void *malloc (YYSIZE_T); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
#  ifndef YYFREE
#   define YYFREE free
#   if ! defined free && ! defined _STDLIB_H && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
void free (void *); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
# endif
#endif /* ! defined yyoverflow || YYERROR_VERBOSE */


#if (! defined yyoverflow \
     && (! defined __cplusplus \
	 || (defined YYSTYPE_IS_TRIVIAL && YYSTYPE_IS_TRIVIAL)))

/* A type that is properly aligned for any stack member.  */
union yyalloc
{
  yytype_int16 yyss_alloc;
  YYSTYPE yyvs_alloc;
};

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (sizeof (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (sizeof (yytype_int16) + sizeof (YYSTYPE)) \
      + YYSTACK_GAP_MAXIMUM)

/* Copy COUNT objects from FROM to TO.  The source and destination do
   not overlap.  */
# ifndef YYCOPY
#  if defined __GNUC__ && 1 < __GNUC__
#   define YYCOPY(To, From, Count) \
      __builtin_memcpy (To, From, (Count) * sizeof (*(From)))
#  else
#   define YYCOPY(To, From, Count)		\
      do					\
	{					\
	  YYSIZE_T yyi;				\
	  for (yyi = 0; yyi < (Count); yyi++)	\
	    (To)[yyi] = (From)[yyi];		\
	}					\
      while (YYID (0))
#  endif
# endif

/* Relocate STACK from its old location to the new one.  The
   local variables YYSIZE and YYSTACKSIZE give the old and new number of
   elements in the stack, and YYPTR gives the new location of the
   stack.  Advance YYPTR to a properly aligned location for the next
   stack.  */
# define YYSTACK_RELOCATE(Stack_alloc, Stack)				\
    do									\
      {									\
	YYSIZE_T yynewbytes;						\
	YYCOPY (&yyptr->Stack_alloc, Stack, yysize);			\
	Stack = &yyptr->Stack_alloc;					\
	yynewbytes = yystacksize * sizeof (*Stack) + YYSTACK_GAP_MAXIMUM; \
	yyptr += yynewbytes / sizeof (*yyptr);				\
      }									\
    while (YYID (0))

#endif

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  44
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   200

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  42
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  25
/* YYNRULES -- Number of rules.  */
#define YYNRULES  65
/* YYNRULES -- Number of states.  */
#define YYNSTATES  103

/* YYTRANSLATE(YYLEX) -- Bison symbol number corresponding to YYLEX.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   296

#define YYTRANSLATE(YYX)						\
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[YYLEX] -- Bison symbol number corresponding to YYLEX.  */
static const yytype_uint8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     1,     2,     3,     4,
       5,     6,     7,     8,     9,    10,    11,    12,    13,    14,
      15,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      25,    26,    27,    28,    29,    30,    31,    32,    33,    34,
      35,    36,    37,    38,    39,    40,    41
};

#if YYDEBUG
/* YYPRHS[YYN] -- Index of the first RHS symbol of rule number YYN in
   YYRHS.  */
static const yytype_uint8 yyprhs[] =
{
       0,     0,     3,     4,     6,     8,    10,    15,    20,    22,
      24,    26,    28,    33,    35,    39,    43,    47,    49,    52,
      54,    58,    59,    62,    64,    66,    70,    72,    76,    78,
      81,    83,    87,    91,    95,    97,   101,   107,   114,   116,
     119,   121,   123,   126,   130,   132,   134,   136,   138,   141,
     145,   147,   149,   151,   153,   155,   157,   159,   161,   163,
     165,   168,   171,   173,   175,   177
};

/* YYRHS -- A `-1'-separated list of the rules' RHS.  */
static const yytype_int8 yyrhs[] =
{
      43,     0,    -1,    -1,    44,    -1,    45,    -1,    53,    -1,
      25,    46,    50,    52,    -1,    34,    46,    50,    52,    -1,
      10,    -1,    59,    -1,    48,    -1,    47,    -1,    63,     8,
      48,     9,    -1,    49,    -1,    48,    30,    49,    -1,    59,
      29,    59,    -1,    59,     4,    59,    -1,    59,    -1,    27,
      51,    -1,    62,    -1,    62,    35,    51,    -1,    -1,    28,
      53,    -1,    54,    -1,    55,    -1,    55,    21,    54,    -1,
      56,    -1,    56,    20,    55,    -1,    57,    -1,    19,    56,
      -1,    58,    -1,    59,    64,    57,    -1,    59,    11,    57,
      -1,     8,    53,     9,    -1,    59,    -1,    59,    65,    58,
      -1,    62,    12,    59,    20,    59,    -1,    62,    19,    12,
      59,    20,    59,    -1,    62,    -1,    62,    60,    -1,    66,
      -1,    63,    -1,    61,    62,    -1,    60,    61,    62,    -1,
      23,    -1,    22,    -1,    36,    -1,    36,    -1,    31,    36,
      -1,    63,    31,    36,    -1,    13,    -1,    14,    -1,    16,
      -1,    18,    -1,    15,    -1,    17,    -1,    40,    -1,    41,
      -1,    39,    -1,    37,    -1,    32,    40,    -1,    33,    40,
      -1,     6,    -1,     7,    -1,     5,    -1,    26,    -1
};

/* YYRLINE[YYN] -- source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,   126,   126,   127,   132,   134,   145,   147,   152,   154,
     156,   158,   163,   168,   170,   175,   177,   179,   190,   195,
     197,   208,   209,   220,   235,   237,   250,   252,   257,   259,
     270,   272,   274,   276,   281,   283,   285,   287,   292,   294,
     296,   298,   303,   305,   310,   311,   315,   325,   332,   339,
     349,   351,   356,   358,   360,   362,   367,   369,   371,   373,
     380,   384,   386,   388,   390,   392
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || YYTOKEN_TABLE
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "DEFINE", "AS_KEYWORD", "NIL", "TRUET",
  "FALSET", "LRPAR", "RRPAR", "MUL", "LIKE", "BETWEEN", "EQUAL",
  "NOTEQUAL", "GREATER", "LESS", "GREATEREQUAL", "LESSEQUAL", "NOT", "AND",
  "OR", "REF", "DOT", "ALL", "SELECT", "UNDEFINED", "FROM", "WHERE",
  "COLON", "COMMA", "DOUBLECOLON", "DOLLAR", "PERCENT", "SELECT_DISTINCT",
  "JOIN", "identifier", "stringLiteral", "queryId", "charLiteral",
  "longLiteral", "doubleLiteral", "$accept", "program", "query",
  "selectExpr", "projectionAttributes", "objectConstruction", "fieldList",
  "field", "fromClause", "joinExpr", "whereClauseOpt", "expr", "orExpr",
  "andExpr", "notExpr", "equalityExpr", "relationalExpr", "postfixExpr",
  "propertyList", "propertyOper", "ID", "scopedName", "equalityOper",
  "relationalOper", "literal", 0
};
#endif

# ifdef YYPRINT
/* YYTOKNUM[YYLEX-NUM] -- Internal token number corresponding to
   token YYLEX-NUM.  */
static const yytype_uint16 yytoknum[] =
{
       0,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   277,   278,   279,   280,   281,   282,   283,   284,
     285,   286,   287,   288,   289,   290,   291,   292,   293,   294,
     295,   296
};
# endif

/* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    42,    43,    43,    44,    44,    45,    45,    46,    46,
      46,    46,    47,    48,    48,    49,    49,    49,    50,    51,
      51,    52,    52,    53,    54,    54,    55,    55,    56,    56,
      57,    57,    57,    57,    58,    58,    58,    58,    59,    59,
      59,    59,    60,    60,    61,    61,    62,    63,    63,    63,
      64,    64,    65,    65,    65,    65,    66,    66,    66,    66,
      66,    66,    66,    66,    66,    66
};

/* YYR2[YYN] -- Number of symbols composing right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     0,     1,     1,     1,     4,     4,     1,     1,
       1,     1,     4,     1,     3,     3,     3,     1,     2,     1,
       3,     0,     2,     1,     1,     3,     1,     3,     1,     2,
       1,     3,     3,     3,     1,     3,     5,     6,     1,     2,
       1,     1,     2,     3,     1,     1,     1,     1,     2,     3,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       2,     2,     1,     1,     1,     1
};

/* YYDEFACT[STATE-NAME] -- Default rule to reduce with in state
   STATE-NUM when YYTABLE doesn't specify something else to do.  Zero
   means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       2,    64,    62,    63,     0,     0,     0,    65,     0,     0,
       0,     0,    46,    59,    58,    56,    57,     0,     3,     4,
       5,    23,    24,    26,    28,    30,    34,    38,    41,    40,
       0,    29,     8,     0,    11,    10,    13,     9,    38,    41,
      48,    60,    61,     0,     1,     0,     0,     0,    50,    51,
      54,    52,    55,    53,     0,     0,     0,     0,    45,    44,
      39,     0,     0,    33,     0,    21,     0,     0,     0,     0,
      21,    25,    27,    32,    31,    35,    34,     0,     0,     0,
      46,    42,    49,    18,    19,     0,     6,    14,    17,    16,
      15,     0,     7,     0,     0,    43,     0,    22,    12,    36,
       0,    20,    37
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int8 yydefgoto[] =
{
      -1,    17,    18,    19,    33,    34,    35,    36,    65,    83,
      86,    20,    21,    22,    23,    24,    25,    26,    60,    61,
      38,    28,    54,    55,    29
};

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
#define YYPACT_NINF -39
static const yytype_int16 yypact[] =
{
      67,   -39,   -39,   -39,   104,   104,   121,   -39,   -30,   -25,
     -23,   121,    -5,   -39,   -39,   -39,   -39,    20,   -39,   -39,
     -39,   -39,    12,     5,   -39,   -39,    23,    -1,    -8,   -39,
      15,   -39,   -39,    16,   -39,    14,   -39,    -2,     7,     4,
     -39,   -39,   -39,    16,   -39,   104,   104,   143,   -39,   -39,
     -39,   -39,   -39,   -39,   143,   159,   159,    30,   -39,   -39,
       7,    17,    24,   -39,    17,    28,   159,   159,   159,   159,
      28,   -39,   -39,   -39,   -39,   -39,    33,    32,   159,    17,
     -39,   -39,   -39,   -39,    27,   104,   -39,   -39,     3,   -39,
     -39,     1,   -39,   159,    39,   -39,    17,   -39,   -39,   -39,
     159,   -39,   -39
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int8 yypgoto[] =
{
     -39,   -39,   -39,   -39,    52,   -39,    -4,    10,    34,   -29,
      11,    -3,    21,    37,    73,   -38,    29,     2,   -39,    31,
       0,     8,   -39,   -39,   -39
};

/* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule which
   number is the opposite.  If zero, do what YYDEFACT says.
   If YYTABLE_NINF, syntax error.  */
#define YYTABLE_NINF -48
static const yytype_int8 yytable[] =
{
      27,    30,    67,   -47,    27,    27,    40,    67,    37,    73,
      98,    56,    69,    37,    39,    41,    74,    42,    57,    39,
      44,    58,    59,    62,    63,    46,   -47,    68,   -17,    58,
      59,    66,    68,    45,    47,    62,    48,    49,    50,    51,
      52,    53,    78,    64,    66,    27,    27,    27,    50,    51,
      52,    53,    93,    80,    27,    27,    85,    76,    77,   100,
      82,    81,    96,    43,    84,    91,    71,   101,    88,    89,
      90,    88,     1,     2,     3,     4,    87,    70,    31,    95,
      94,    92,    97,    72,    75,    27,     5,     0,     0,     0,
       0,    79,     6,     7,     0,    99,    84,     0,     8,     9,
      10,    11,   102,    12,    13,     0,    14,    15,    16,     1,
       2,     3,     4,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     5,     0,     0,     1,     2,     3,     0,
       7,    32,     0,     0,     0,     8,     9,    10,     0,     0,
      12,    13,     0,    14,    15,    16,     0,     7,     1,     2,
       3,     4,     8,     9,    10,     0,     0,    12,    13,     0,
      14,    15,    16,     0,     1,     2,     3,     0,     0,     7,
       0,     0,     0,     0,     8,     9,    10,     0,     0,    12,
      13,     0,    14,    15,    16,     7,     0,     0,     0,     0,
       8,     9,    10,     0,     0,    12,    13,     0,    14,    15,
      16
};

static const yytype_int8 yycheck[] =
{
       0,     4,     4,     8,     4,     5,    36,     4,     6,    47,
       9,    12,     8,    11,     6,    40,    54,    40,    19,    11,
       0,    22,    23,    31,     9,    20,    31,    29,    30,    22,
      23,    30,    29,    21,    11,    31,    13,    14,    15,    16,
      17,    18,    12,    27,    30,    45,    46,    47,    15,    16,
      17,    18,    20,    36,    54,    55,    28,    55,    56,    20,
      36,    61,    35,    11,    64,    69,    45,    96,    66,    67,
      68,    69,     5,     6,     7,     8,    66,    43,     5,    79,
      78,    70,    85,    46,    55,    85,    19,    -1,    -1,    -1,
      -1,    60,    25,    26,    -1,    93,    96,    -1,    31,    32,
      33,    34,   100,    36,    37,    -1,    39,    40,    41,     5,
       6,     7,     8,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    19,    -1,    -1,     5,     6,     7,    -1,
      26,    10,    -1,    -1,    -1,    31,    32,    33,    -1,    -1,
      36,    37,    -1,    39,    40,    41,    -1,    26,     5,     6,
       7,     8,    31,    32,    33,    -1,    -1,    36,    37,    -1,
      39,    40,    41,    -1,     5,     6,     7,    -1,    -1,    26,
      -1,    -1,    -1,    -1,    31,    32,    33,    -1,    -1,    36,
      37,    -1,    39,    40,    41,    26,    -1,    -1,    -1,    -1,
      31,    32,    33,    -1,    -1,    36,    37,    -1,    39,    40,
      41
};

/* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
   symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,     5,     6,     7,     8,    19,    25,    26,    31,    32,
      33,    34,    36,    37,    39,    40,    41,    43,    44,    45,
      53,    54,    55,    56,    57,    58,    59,    62,    63,    66,
      53,    56,    10,    46,    47,    48,    49,    59,    62,    63,
      36,    40,    40,    46,     0,    21,    20,    11,    13,    14,
      15,    16,    17,    18,    64,    65,    12,    19,    22,    23,
      60,    61,    31,     9,    27,    50,    30,     4,    29,     8,
      50,    54,    55,    57,    57,    58,    59,    59,    12,    61,
      36,    62,    36,    51,    62,    28,    52,    49,    59,    59,
      59,    48,    52,    20,    59,    62,    35,    53,     9,    59,
      20,    51,    59
};

#define yyerrok		(yyerrstatus = 0)
#define yyclearin	(yychar = YYEMPTY)
#define YYEMPTY		(-2)
#define YYEOF		0

#define YYACCEPT	goto yyacceptlab
#define YYABORT		goto yyabortlab
#define YYERROR		goto yyerrorlab


/* Like YYERROR except do call yyerror.  This remains here temporarily
   to ease the transition to the new meaning of YYERROR, for GCC.
   Once GCC version 2 has supplanted version 1, this can go.  */

#define YYFAIL		goto yyerrlab

#define YYRECOVERING()  (!!yyerrstatus)

#define YYBACKUP(Token, Value)					\
do								\
  if (yychar == YYEMPTY && yylen == 1)				\
    {								\
      yychar = (Token);						\
      yylval = (Value);						\
      yytoken = YYTRANSLATE (yychar);				\
      YYPOPSTACK (1);						\
      goto yybackup;						\
    }								\
  else								\
    {								\
      yyerror (YY_("syntax error: cannot back up")); \
      YYERROR;							\
    }								\
while (YYID (0))


#define YYTERROR	1
#define YYERRCODE	256


/* YYLLOC_DEFAULT -- Set CURRENT to span from RHS[1] to RHS[N].
   If N is 0, then set CURRENT to the empty location which ends
   the previous symbol: RHS[0] (always defined).  */

#define YYRHSLOC(Rhs, K) ((Rhs)[K])
#ifndef YYLLOC_DEFAULT
# define YYLLOC_DEFAULT(Current, Rhs, N)				\
    do									\
      if (YYID (N))                                                    \
	{								\
	  (Current).first_line   = YYRHSLOC (Rhs, 1).first_line;	\
	  (Current).first_column = YYRHSLOC (Rhs, 1).first_column;	\
	  (Current).last_line    = YYRHSLOC (Rhs, N).last_line;		\
	  (Current).last_column  = YYRHSLOC (Rhs, N).last_column;	\
	}								\
      else								\
	{								\
	  (Current).first_line   = (Current).last_line   =		\
	    YYRHSLOC (Rhs, 0).last_line;				\
	  (Current).first_column = (Current).last_column =		\
	    YYRHSLOC (Rhs, 0).last_column;				\
	}								\
    while (YYID (0))
#endif


/* YY_LOCATION_PRINT -- Print the location on the stream.
   This macro was not mandated originally: define only if we know
   we won't break user code: when these are the locations we know.  */

#ifndef YY_LOCATION_PRINT
# if YYLTYPE_IS_TRIVIAL
#  define YY_LOCATION_PRINT(File, Loc)			\
     fprintf (File, "%d.%d-%d.%d",			\
	      (Loc).first_line, (Loc).first_column,	\
	      (Loc).last_line,  (Loc).last_column)
# else
#  define YY_LOCATION_PRINT(File, Loc) ((void) 0)
# endif
#endif


/* YYLEX -- calling `yylex' with the right arguments.  */

#ifdef YYLEX_PARAM
# define YYLEX yylex (YYLEX_PARAM)
#else
# define YYLEX yylex ()
#endif

/* Enable debugging if requested.  */
#if YYDEBUG

# ifndef YYFPRINTF
#  include <stdio.h> /* INFRINGES ON USER NAME SPACE */
#  define YYFPRINTF fprintf
# endif

# define YYDPRINTF(Args)			\
do {						\
  if (yydebug)					\
    YYFPRINTF Args;				\
} while (YYID (0))

# define YY_SYMBOL_PRINT(Title, Type, Value, Location)			  \
do {									  \
  if (yydebug)								  \
    {									  \
      YYFPRINTF (stderr, "%s ", Title);					  \
      yy_symbol_print (stderr,						  \
		  Type, Value); \
      YYFPRINTF (stderr, "\n");						  \
    }									  \
} while (YYID (0))


/*--------------------------------.
| Print this symbol on YYOUTPUT.  |
`--------------------------------*/

/*ARGSUSED*/
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_symbol_value_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
#else
static void
yy_symbol_value_print (yyoutput, yytype, yyvaluep)
    FILE *yyoutput;
    int yytype;
    YYSTYPE const * const yyvaluep;
#endif
{
  if (!yyvaluep)
    return;
# ifdef YYPRINT
  if (yytype < YYNTOKENS)
    YYPRINT (yyoutput, yytoknum[yytype], *yyvaluep);
# else
  YYUSE (yyoutput);
# endif
  switch (yytype)
    {
      default:
	break;
    }
}


/*--------------------------------.
| Print this symbol on YYOUTPUT.  |
`--------------------------------*/

#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_symbol_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
#else
static void
yy_symbol_print (yyoutput, yytype, yyvaluep)
    FILE *yyoutput;
    int yytype;
    YYSTYPE const * const yyvaluep;
#endif
{
  if (yytype < YYNTOKENS)
    YYFPRINTF (yyoutput, "token %s (", yytname[yytype]);
  else
    YYFPRINTF (yyoutput, "nterm %s (", yytname[yytype]);

  yy_symbol_value_print (yyoutput, yytype, yyvaluep);
  YYFPRINTF (yyoutput, ")");
}

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_stack_print (yytype_int16 *yybottom, yytype_int16 *yytop)
#else
static void
yy_stack_print (yybottom, yytop)
    yytype_int16 *yybottom;
    yytype_int16 *yytop;
#endif
{
  YYFPRINTF (stderr, "Stack now");
  for (; yybottom <= yytop; yybottom++)
    {
      int yybot = *yybottom;
      YYFPRINTF (stderr, " %d", yybot);
    }
  YYFPRINTF (stderr, "\n");
}

# define YY_STACK_PRINT(Bottom, Top)				\
do {								\
  if (yydebug)							\
    yy_stack_print ((Bottom), (Top));				\
} while (YYID (0))


/*------------------------------------------------.
| Report that the YYRULE is going to be reduced.  |
`------------------------------------------------*/

#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_reduce_print (YYSTYPE *yyvsp, int yyrule)
#else
static void
yy_reduce_print (yyvsp, yyrule)
    YYSTYPE *yyvsp;
    int yyrule;
#endif
{
  int yynrhs = yyr2[yyrule];
  int yyi;
  unsigned long int yylno = yyrline[yyrule];
  YYFPRINTF (stderr, "Reducing stack by rule %d (line %lu):\n",
	     yyrule - 1, yylno);
  /* The symbols being reduced.  */
  for (yyi = 0; yyi < yynrhs; yyi++)
    {
      YYFPRINTF (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr, yyrhs[yyprhs[yyrule] + yyi],
		       &(yyvsp[(yyi + 1) - (yynrhs)])
		       		       );
      YYFPRINTF (stderr, "\n");
    }
}

# define YY_REDUCE_PRINT(Rule)		\
do {					\
  if (yydebug)				\
    yy_reduce_print (yyvsp, Rule); \
} while (YYID (0))

/* Nonzero means print parse trace.  It is left uninitialized so that
   multiple parsers can coexist.  */
int yydebug;
#else /* !YYDEBUG */
# define YYDPRINTF(Args)
# define YY_SYMBOL_PRINT(Title, Type, Value, Location)
# define YY_STACK_PRINT(Bottom, Top)
# define YY_REDUCE_PRINT(Rule)
#endif /* !YYDEBUG */


/* YYINITDEPTH -- initial size of the parser's stacks.  */
#ifndef	YYINITDEPTH
# define YYINITDEPTH 200
#endif

/* YYMAXDEPTH -- maximum size the stacks can grow to (effective only
   if the built-in stack extension method is used).

   Do not make this value too large; the results are undefined if
   YYSTACK_ALLOC_MAXIMUM < YYSTACK_BYTES (YYMAXDEPTH)
   evaluated with infinite-precision integer arithmetic.  */

#ifndef YYMAXDEPTH
# define YYMAXDEPTH 10000
#endif



#if YYERROR_VERBOSE

# ifndef yystrlen
#  if defined __GLIBC__ && defined _STRING_H
#   define yystrlen strlen
#  else
/* Return the length of YYSTR.  */
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static YYSIZE_T
yystrlen (const char *yystr)
#else
static YYSIZE_T
yystrlen (yystr)
    const char *yystr;
#endif
{
  YYSIZE_T yylen;
  for (yylen = 0; yystr[yylen]; yylen++)
    continue;
  return yylen;
}
#  endif
# endif

# ifndef yystpcpy
#  if defined __GLIBC__ && defined _STRING_H && defined _GNU_SOURCE
#   define yystpcpy stpcpy
#  else
/* Copy YYSRC to YYDEST, returning the address of the terminating '\0' in
   YYDEST.  */
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static char *
yystpcpy (char *yydest, const char *yysrc)
#else
static char *
yystpcpy (yydest, yysrc)
    char *yydest;
    const char *yysrc;
#endif
{
  char *yyd = yydest;
  const char *yys = yysrc;

  while ((*yyd++ = *yys++) != '\0')
    continue;

  return yyd - 1;
}
#  endif
# endif

# ifndef yytnamerr
/* Copy to YYRES the contents of YYSTR after stripping away unnecessary
   quotes and backslashes, so that it's suitable for yyerror.  The
   heuristic is that double-quoting is unnecessary unless the string
   contains an apostrophe, a comma, or backslash (other than
   backslash-backslash).  YYSTR is taken from yytname.  If YYRES is
   null, do not copy; instead, return the length of what the result
   would have been.  */
static YYSIZE_T
yytnamerr (char *yyres, const char *yystr)
{
  if (*yystr == '"')
    {
      YYSIZE_T yyn = 0;
      char const *yyp = yystr;

      for (;;)
	switch (*++yyp)
	  {
	  case '\'':
	  case ',':
	    goto do_not_strip_quotes;

	  case '\\':
	    if (*++yyp != '\\')
	      goto do_not_strip_quotes;
	    /* Fall through.  */
	  default:
	    if (yyres)
	      yyres[yyn] = *yyp;
	    yyn++;
	    break;

	  case '"':
	    if (yyres)
	      yyres[yyn] = '\0';
	    return yyn;
	  }
    do_not_strip_quotes: ;
    }

  if (! yyres)
    return yystrlen (yystr);

  return yystpcpy (yyres, yystr) - yyres;
}
# endif

/* Copy into YYRESULT an error message about the unexpected token
   YYCHAR while in state YYSTATE.  Return the number of bytes copied,
   including the terminating null byte.  If YYRESULT is null, do not
   copy anything; just return the number of bytes that would be
   copied.  As a special case, return 0 if an ordinary "syntax error"
   message will do.  Return YYSIZE_MAXIMUM if overflow occurs during
   size calculation.  */
static YYSIZE_T
yysyntax_error (char *yyresult, int yystate, int yychar)
{
  int yyn = yypact[yystate];

  if (! (YYPACT_NINF < yyn && yyn <= YYLAST))
    return 0;
  else
    {
      int yytype = YYTRANSLATE (yychar);
      YYSIZE_T yysize0 = yytnamerr (0, yytname[yytype]);
      YYSIZE_T yysize = yysize0;
      YYSIZE_T yysize1;
      int yysize_overflow = 0;
      enum { YYERROR_VERBOSE_ARGS_MAXIMUM = 5 };
      char const *yyarg[YYERROR_VERBOSE_ARGS_MAXIMUM];
      int yyx;

# if 0
      /* This is so xgettext sees the translatable formats that are
	 constructed on the fly.  */
      YY_("syntax error, unexpected %s");
      YY_("syntax error, unexpected %s, expecting %s");
      YY_("syntax error, unexpected %s, expecting %s or %s");
      YY_("syntax error, unexpected %s, expecting %s or %s or %s");
      YY_("syntax error, unexpected %s, expecting %s or %s or %s or %s");
# endif
      char *yyfmt;
      char const *yyf;
      static char const yyunexpected[] = "syntax error, unexpected %s";
      static char const yyexpecting[] = ", expecting %s";
      static char const yyor[] = " or %s";
      char yyformat[sizeof yyunexpected
		    + sizeof yyexpecting - 1
		    + ((YYERROR_VERBOSE_ARGS_MAXIMUM - 2)
		       * (sizeof yyor - 1))];
      char const *yyprefix = yyexpecting;

      /* Start YYX at -YYN if negative to avoid negative indexes in
	 YYCHECK.  */
      int yyxbegin = yyn < 0 ? -yyn : 0;

      /* Stay within bounds of both yycheck and yytname.  */
      int yychecklim = YYLAST - yyn + 1;
      int yyxend = yychecklim < YYNTOKENS ? yychecklim : YYNTOKENS;
      int yycount = 1;

      yyarg[0] = yytname[yytype];
      yyfmt = yystpcpy (yyformat, yyunexpected);

      for (yyx = yyxbegin; yyx < yyxend; ++yyx)
	if (yycheck[yyx + yyn] == yyx && yyx != YYTERROR)
	  {
	    if (yycount == YYERROR_VERBOSE_ARGS_MAXIMUM)
	      {
		yycount = 1;
		yysize = yysize0;
		yyformat[sizeof yyunexpected - 1] = '\0';
		break;
	      }
	    yyarg[yycount++] = yytname[yyx];
	    yysize1 = yysize + yytnamerr (0, yytname[yyx]);
	    yysize_overflow |= (yysize1 < yysize);
	    yysize = yysize1;
	    yyfmt = yystpcpy (yyfmt, yyprefix);
	    yyprefix = yyor;
	  }

      yyf = YY_(yyformat);
      yysize1 = yysize + yystrlen (yyf);
      yysize_overflow |= (yysize1 < yysize);
      yysize = yysize1;

      if (yysize_overflow)
	return YYSIZE_MAXIMUM;

      if (yyresult)
	{
	  /* Avoid sprintf, as that infringes on the user's name space.
	     Don't have undefined behavior even if the translation
	     produced a string with the wrong number of "%s"s.  */
	  char *yyp = yyresult;
	  int yyi = 0;
	  while ((*yyp = *yyf) != '\0')
	    {
	      if (*yyp == '%' && yyf[1] == 's' && yyi < yycount)
		{
		  yyp += yytnamerr (yyp, yyarg[yyi++]);
		  yyf += 2;
		}
	      else
		{
		  yyp++;
		  yyf++;
		}
	    }
	}
      return yysize;
    }
}
#endif /* YYERROR_VERBOSE */


/*-----------------------------------------------.
| Release the memory associated to this symbol.  |
`-----------------------------------------------*/

/*ARGSUSED*/
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yydestruct (const char *yymsg, int yytype, YYSTYPE *yyvaluep)
#else
static void
yydestruct (yymsg, yytype, yyvaluep)
    const char *yymsg;
    int yytype;
    YYSTYPE *yyvaluep;
#endif
{
  YYUSE (yyvaluep);

  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yytype, yyvaluep, yylocationp);

  switch (yytype)
    {

      default:
	break;
    }
}

/* Prevent warnings from -Wmissing-prototypes.  */
#ifdef YYPARSE_PARAM
#if defined __STDC__ || defined __cplusplus
int yyparse (void *YYPARSE_PARAM);
#else
int yyparse ();
#endif
#else /* ! YYPARSE_PARAM */
#if defined __STDC__ || defined __cplusplus
int yyparse (void);
#else
int yyparse ();
#endif
#endif /* ! YYPARSE_PARAM */


/* The lookahead symbol.  */
int yychar;

/* The semantic value of the lookahead symbol.  */
YYSTYPE yylval;

/* Number of syntax errors so far.  */
int yynerrs;



/*-------------------------.
| yyparse or yypush_parse.  |
`-------------------------*/

#ifdef YYPARSE_PARAM
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
int
yyparse (void *YYPARSE_PARAM)
#else
int
yyparse (YYPARSE_PARAM)
    void *YYPARSE_PARAM;
#endif
#else /* ! YYPARSE_PARAM */
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
int
yyparse (void)
#else
int
yyparse ()

#endif
#endif
{


    int yystate;
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus;

    /* The stacks and their tools:
       `yyss': related to states.
       `yyvs': related to semantic values.

       Refer to the stacks thru separate pointers, to allow yyoverflow
       to reallocate them elsewhere.  */

    /* The state stack.  */
    yytype_int16 yyssa[YYINITDEPTH];
    yytype_int16 *yyss;
    yytype_int16 *yyssp;

    /* The semantic value stack.  */
    YYSTYPE yyvsa[YYINITDEPTH];
    YYSTYPE *yyvs;
    YYSTYPE *yyvsp;

    YYSIZE_T yystacksize;

  int yyn;
  int yyresult;
  /* Lookahead token as an internal (translated) token number.  */
  int yytoken;
  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;

#if YYERROR_VERBOSE
  /* Buffer for error messages, and its allocated size.  */
  char yymsgbuf[128];
  char *yymsg = yymsgbuf;
  YYSIZE_T yymsg_alloc = sizeof yymsgbuf;
#endif

#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N))

  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  yytoken = 0;
  yyss = yyssa;
  yyvs = yyvsa;
  yystacksize = YYINITDEPTH;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yystate = 0;
  yyerrstatus = 0;
  yynerrs = 0;
  yychar = YYEMPTY; /* Cause a token to be read.  */

  /* Initialize stack pointers.
     Waste one element of value and location stack
     so that they stay on the same level as the state stack.
     The wasted elements are never initialized.  */
  yyssp = yyss;
  yyvsp = yyvs;

  goto yysetstate;

/*------------------------------------------------------------.
| yynewstate -- Push a new state, which is found in yystate.  |
`------------------------------------------------------------*/
 yynewstate:
  /* In all cases, when you get here, the value and location stacks
     have just been pushed.  So pushing a state here evens the stacks.  */
  yyssp++;

 yysetstate:
  *yyssp = yystate;

  if (yyss + yystacksize - 1 <= yyssp)
    {
      /* Get the current used size of the three stacks, in elements.  */
      YYSIZE_T yysize = yyssp - yyss + 1;

#ifdef yyoverflow
      {
	/* Give user a chance to reallocate the stack.  Use copies of
	   these so that the &'s don't force the real ones into
	   memory.  */
	YYSTYPE *yyvs1 = yyvs;
	yytype_int16 *yyss1 = yyss;

	/* Each stack pointer address is followed by the size of the
	   data in use in that stack, in bytes.  This used to be a
	   conditional around just the two extra args, but that might
	   be undefined if yyoverflow is a macro.  */
	yyoverflow (YY_("memory exhausted"),
		    &yyss1, yysize * sizeof (*yyssp),
		    &yyvs1, yysize * sizeof (*yyvsp),
		    &yystacksize);

	yyss = yyss1;
	yyvs = yyvs1;
      }
#else /* no yyoverflow */
# ifndef YYSTACK_RELOCATE
      goto yyexhaustedlab;
# else
      /* Extend the stack our own way.  */
      if (YYMAXDEPTH <= yystacksize)
	goto yyexhaustedlab;
      yystacksize *= 2;
      if (YYMAXDEPTH < yystacksize)
	yystacksize = YYMAXDEPTH;

      {
	yytype_int16 *yyss1 = yyss;
	union yyalloc *yyptr =
	  (union yyalloc *) YYSTACK_ALLOC (YYSTACK_BYTES (yystacksize));
	if (! yyptr)
	  goto yyexhaustedlab;
	YYSTACK_RELOCATE (yyss_alloc, yyss);
	YYSTACK_RELOCATE (yyvs_alloc, yyvs);
#  undef YYSTACK_RELOCATE
	if (yyss1 != yyssa)
	  YYSTACK_FREE (yyss1);
      }
# endif
#endif /* no yyoverflow */

      yyssp = yyss + yysize - 1;
      yyvsp = yyvs + yysize - 1;

      YYDPRINTF ((stderr, "Stack size increased to %lu\n",
		  (unsigned long int) yystacksize));

      if (yyss + yystacksize - 1 <= yyssp)
	YYABORT;
    }

  YYDPRINTF ((stderr, "Entering state %d\n", yystate));

  if (yystate == YYFINAL)
    YYACCEPT;

  goto yybackup;

/*-----------.
| yybackup.  |
`-----------*/
yybackup:

  /* Do appropriate processing given the current state.  Read a
     lookahead token if we need one and don't already have one.  */

  /* First try to decide what to do without reference to lookahead token.  */
  yyn = yypact[yystate];
  if (yyn == YYPACT_NINF)
    goto yydefault;

  /* Not known => get a lookahead token if don't already have one.  */

  /* YYCHAR is either YYEMPTY or YYEOF or a valid lookahead symbol.  */
  if (yychar == YYEMPTY)
    {
      YYDPRINTF ((stderr, "Reading a token: "));
      yychar = YYLEX;
    }

  if (yychar <= YYEOF)
    {
      yychar = yytoken = YYEOF;
      YYDPRINTF ((stderr, "Now at end of input.\n"));
    }
  else
    {
      yytoken = YYTRANSLATE (yychar);
      YY_SYMBOL_PRINT ("Next token is", yytoken, &yylval, &yylloc);
    }

  /* If the proper action on seeing token YYTOKEN is to reduce or to
     detect an error, take that action.  */
  yyn += yytoken;
  if (yyn < 0 || YYLAST < yyn || yycheck[yyn] != yytoken)
    goto yydefault;
  yyn = yytable[yyn];
  if (yyn <= 0)
    {
      if (yyn == 0 || yyn == YYTABLE_NINF)
	goto yyerrlab;
      yyn = -yyn;
      goto yyreduce;
    }

  /* Count tokens shifted since error; after three, turn off error
     status.  */
  if (yyerrstatus)
    yyerrstatus--;

  /* Shift the lookahead token.  */
  YY_SYMBOL_PRINT ("Shifting", yytoken, &yylval, &yylloc);

  /* Discard the shifted token.  */
  yychar = YYEMPTY;

  yystate = yyn;
  *++yyvsp = yylval;

  goto yynewstate;


/*-----------------------------------------------------------.
| yydefault -- do the default action for the current state.  |
`-----------------------------------------------------------*/
yydefault:
  yyn = yydefact[yystate];
  if (yyn == 0)
    goto yyerrlab;
  goto yyreduce;


/*-----------------------------.
| yyreduce -- Do a reduction.  |
`-----------------------------*/
yyreduce:
  /* yyn is the number of a rule to reduce with.  */
  yylen = yyr2[yyn];

  /* If YYLEN is nonzero, implement the default value of the action:
     `$$ = $1'.

     Otherwise, the following line sets YYVAL to garbage.
     This behavior is undocumented and Bison
     users should not rely upon it.  Assigning to YYVAL
     unconditionally makes the parser a bit smaller, and it avoids a
     GCC warning that YYVAL may be used uninitialized.  */
  yyval = yyvsp[1-yylen];


  YY_REDUCE_PRINT (yyn);
  switch (yyn)
    {
        case 3:

/* Line 1455 of yacc.c  */
#line 128 "/home/dds/Lite/vlite/build/ospli/src/database/database/code/q_parser.y"
    { expr = F1(Q_EXPR_PROGRAM,(yyvsp[(1) - (1)].Expr)); ;}
    break;

  case 4:

/* Line 1455 of yacc.c  */
#line 133 "/home/dds/Lite/vlite/build/ospli/src/database/database/code/q_parser.y"
    { (yyval.Expr) = (yyvsp[(1) - (1)].Expr); ;}
    break;

  case 5:

/* Line 1455 of yacc.c  */
#line 135 "/home/dds/Lite/vlite/build/ospli/src/database/database/code/q_parser.y"
    { (yyval.Expr) = (yyvsp[(1) - (1)].Expr); ;}
    break;

  case 6:

/* Line 1455 of yacc.c  */
#line 146 "/home/dds/Lite/vlite/build/ospli/src/database/database/code/q_parser.y"
    { (yyval.Expr) = F3(Q_EXPR_SELECT,(yyvsp[(2) - (4)].Expr),(yyvsp[(3) - (4)].Expr),(yyvsp[(4) - (4)].Expr)); ;}
    break;

  case 7:

/* Line 1455 of yacc.c  */
#line 148 "/home/dds/Lite/vlite/build/ospli/src/database/database/code/q_parser.y"
    { (yyval.Expr) = F3(Q_EXPR_SELECTDISTINCT,(yyvsp[(2) - (4)].Expr),(yyvsp[(3) - (4)].Expr),(yyvsp[(4) - (4)].Expr)); ;}
    break;

  case 8:

/* Line 1455 of yacc.c  */
#line 153 "/home/dds/Lite/vlite/build/ospli/src/database/database/code/q_parser.y"
    { (yyval.Expr) = L0(Q_EXPR_PROJECTION); ;}
    break;

  case 9:

/* Line 1455 of yacc.c  */
#line 155 "/home/dds/Lite/vlite/build/ospli/src/database/database/code/q_parser.y"
    { (yyval.Expr) = F1(Q_EXPR_PROJECTION,(yyvsp[(1) - (1)].Expr)); ;}
    break;

  case 10:

/* Line 1455 of yacc.c  */
#line 157 "/home/dds/Lite/vlite/build/ospli/src/database/database/code/q_parser.y"
    { (yyval.Expr) = L1(Q_EXPR_PROJECTION,(yyvsp[(1) - (1)].List)); ;}
    break;

  case 11:

/* Line 1455 of yacc.c  */
#line 159 "/home/dds/Lite/vlite/build/ospli/src/database/database/code/q_parser.y"
    { (yyval.Expr) = F1(Q_EXPR_PROJECTION,(yyvsp[(1) - (1)].Expr)); ;}
    break;

  case 12:

/* Line 1455 of yacc.c  */
#line 164 "/home/dds/Lite/vlite/build/ospli/src/database/database/code/q_parser.y"
    { (yyval.Expr) = L2(Q_EXPR_CLASS,q_newFnc(Q_EXPR_SCOPEDNAME,(yyvsp[(1) - (4)].List)),(yyvsp[(3) - (4)].List)); ;}
    break;

  case 13:

/* Line 1455 of yacc.c  */
#line 169 "/home/dds/Lite/vlite/build/ospli/src/database/database/code/q_parser.y"
    { (yyval.List) = List1((yyvsp[(1) - (1)].Expr)); ;}
    break;

  case 14:

/* Line 1455 of yacc.c  */
#line 171 "/home/dds/Lite/vlite/build/ospli/src/database/database/code/q_parser.y"
    { (yyval.List) = q_append((yyvsp[(1) - (3)].List),(yyvsp[(3) - (3)].Expr)); ;}
    break;

  case 15:

/* Line 1455 of yacc.c  */
#line 176 "/home/dds/Lite/vlite/build/ospli/src/database/database/code/q_parser.y"
    { (yyval.Expr) = F2(Q_EXPR_BIND,(yyvsp[(3) - (3)].Expr),(yyvsp[(1) - (3)].Expr)); ;}
    break;

  case 16:

/* Line 1455 of yacc.c  */
#line 178 "/home/dds/Lite/vlite/build/ospli/src/database/database/code/q_parser.y"
    { (yyval.Expr) = F2(Q_EXPR_BIND,(yyvsp[(1) - (3)].Expr),(yyvsp[(3) - (3)].Expr)); ;}
    break;

  case 17:

/* Line 1455 of yacc.c  */
#line 180 "/home/dds/Lite/vlite/build/ospli/src/database/database/code/q_parser.y"
    { (yyval.Expr) = (yyvsp[(1) - (1)].Expr); ;}
    break;

  case 18:

/* Line 1455 of yacc.c  */
#line 191 "/home/dds/Lite/vlite/build/ospli/src/database/database/code/q_parser.y"
    { (yyval.Expr) = F1(Q_EXPR_FROM,(yyvsp[(2) - (2)].Expr)); ;}
    break;

  case 19:

/* Line 1455 of yacc.c  */
#line 196 "/home/dds/Lite/vlite/build/ospli/src/database/database/code/q_parser.y"
    { (yyval.Expr) = (yyvsp[(1) - (1)].Expr); ;}
    break;

  case 20:

/* Line 1455 of yacc.c  */
#line 198 "/home/dds/Lite/vlite/build/ospli/src/database/database/code/q_parser.y"
    { (yyval.Expr) = F2(Q_EXPR_JOIN,(yyvsp[(1) - (3)].Expr),(yyvsp[(3) - (3)].Expr)); ;}
    break;

  case 21:

/* Line 1455 of yacc.c  */
#line 208 "/home/dds/Lite/vlite/build/ospli/src/database/database/code/q_parser.y"
    { (yyval.Expr) = L0(Q_EXPR_WHERE); ;}
    break;

  case 22:

/* Line 1455 of yacc.c  */
#line 210 "/home/dds/Lite/vlite/build/ospli/src/database/database/code/q_parser.y"
    { (yyval.Expr) = F1(Q_EXPR_WHERE,(yyvsp[(2) - (2)].Expr)); ;}
    break;

  case 23:

/* Line 1455 of yacc.c  */
#line 221 "/home/dds/Lite/vlite/build/ospli/src/database/database/code/q_parser.y"
    { (yyval.Expr) = (yyvsp[(1) - (1)].Expr); ;}
    break;

  case 24:

/* Line 1455 of yacc.c  */
#line 236 "/home/dds/Lite/vlite/build/ospli/src/database/database/code/q_parser.y"
    { (yyval.Expr) = (yyvsp[(1) - (1)].Expr); ;}
    break;

  case 25:

/* Line 1455 of yacc.c  */
#line 238 "/home/dds/Lite/vlite/build/ospli/src/database/database/code/q_parser.y"
    { (yyval.Expr) = F2(Q_EXPR_OR,(yyvsp[(1) - (3)].Expr),(yyvsp[(3) - (3)].Expr)); ;}
    break;

  case 26:

/* Line 1455 of yacc.c  */
#line 251 "/home/dds/Lite/vlite/build/ospli/src/database/database/code/q_parser.y"
    { (yyval.Expr) = (yyvsp[(1) - (1)].Expr); ;}
    break;

  case 27:

/* Line 1455 of yacc.c  */
#line 253 "/home/dds/Lite/vlite/build/ospli/src/database/database/code/q_parser.y"
    { (yyval.Expr) = F2(Q_EXPR_AND,(yyvsp[(1) - (3)].Expr),(yyvsp[(3) - (3)].Expr)); ;}
    break;

  case 28:

/* Line 1455 of yacc.c  */
#line 258 "/home/dds/Lite/vlite/build/ospli/src/database/database/code/q_parser.y"
    { (yyval.Expr) = (yyvsp[(1) - (1)].Expr); ;}
    break;

  case 29:

/* Line 1455 of yacc.c  */
#line 260 "/home/dds/Lite/vlite/build/ospli/src/database/database/code/q_parser.y"
    { (yyval.Expr) = F1(Q_EXPR_NOT,(yyvsp[(2) - (2)].Expr)); ;}
    break;

  case 30:

/* Line 1455 of yacc.c  */
#line 271 "/home/dds/Lite/vlite/build/ospli/src/database/database/code/q_parser.y"
    { (yyval.Expr) = (yyvsp[(1) - (1)].Expr); ;}
    break;

  case 31:

/* Line 1455 of yacc.c  */
#line 273 "/home/dds/Lite/vlite/build/ospli/src/database/database/code/q_parser.y"
    { (yyval.Expr) = F2((yyvsp[(2) - (3)].Tag),(yyvsp[(1) - (3)].Expr),(yyvsp[(3) - (3)].Expr)); ;}
    break;

  case 32:

/* Line 1455 of yacc.c  */
#line 275 "/home/dds/Lite/vlite/build/ospli/src/database/database/code/q_parser.y"
    { (yyval.Expr) = F2(Q_EXPR_LIKE,(yyvsp[(1) - (3)].Expr),(yyvsp[(3) - (3)].Expr)); ;}
    break;

  case 33:

/* Line 1455 of yacc.c  */
#line 277 "/home/dds/Lite/vlite/build/ospli/src/database/database/code/q_parser.y"
    { (yyval.Expr) = (yyvsp[(2) - (3)].Expr); ;}
    break;

  case 34:

/* Line 1455 of yacc.c  */
#line 282 "/home/dds/Lite/vlite/build/ospli/src/database/database/code/q_parser.y"
    { (yyval.Expr) = (yyvsp[(1) - (1)].Expr); ;}
    break;

  case 35:

/* Line 1455 of yacc.c  */
#line 284 "/home/dds/Lite/vlite/build/ospli/src/database/database/code/q_parser.y"
    { (yyval.Expr) = F2((yyvsp[(2) - (3)].Tag),(yyvsp[(1) - (3)].Expr),(yyvsp[(3) - (3)].Expr)); ;}
    break;

  case 36:

/* Line 1455 of yacc.c  */
#line 286 "/home/dds/Lite/vlite/build/ospli/src/database/database/code/q_parser.y"
    { (yyval.Expr) = F2(Q_EXPR_AND,F2(Q_EXPR_GE,(yyvsp[(1) - (5)].Expr),(yyvsp[(3) - (5)].Expr)),F2(Q_EXPR_LE,q_newId(q_getId((yyvsp[(1) - (5)].Expr))),(yyvsp[(5) - (5)].Expr))); ;}
    break;

  case 37:

/* Line 1455 of yacc.c  */
#line 288 "/home/dds/Lite/vlite/build/ospli/src/database/database/code/q_parser.y"
    { (yyval.Expr) = F2(Q_EXPR_OR,F2(Q_EXPR_LT,(yyvsp[(1) - (6)].Expr),(yyvsp[(4) - (6)].Expr)),F2(Q_EXPR_GT,q_newId(q_getId((yyvsp[(1) - (6)].Expr))),(yyvsp[(6) - (6)].Expr))); ;}
    break;

  case 38:

/* Line 1455 of yacc.c  */
#line 293 "/home/dds/Lite/vlite/build/ospli/src/database/database/code/q_parser.y"
    { (yyval.Expr) = (yyvsp[(1) - (1)].Expr); ;}
    break;

  case 39:

/* Line 1455 of yacc.c  */
#line 295 "/home/dds/Lite/vlite/build/ospli/src/database/database/code/q_parser.y"
    { (yyval.Expr) = L2(Q_EXPR_PROPERTY,(yyvsp[(1) - (2)].Expr),(yyvsp[(2) - (2)].List)); ;}
    break;

  case 40:

/* Line 1455 of yacc.c  */
#line 297 "/home/dds/Lite/vlite/build/ospli/src/database/database/code/q_parser.y"
    { (yyval.Expr) = (yyvsp[(1) - (1)].Expr); ;}
    break;

  case 41:

/* Line 1455 of yacc.c  */
#line 299 "/home/dds/Lite/vlite/build/ospli/src/database/database/code/q_parser.y"
    { (yyval.Expr) = q_newFnc(Q_EXPR_SCOPEDNAME,(yyvsp[(1) - (1)].List)); ;}
    break;

  case 42:

/* Line 1455 of yacc.c  */
#line 304 "/home/dds/Lite/vlite/build/ospli/src/database/database/code/q_parser.y"
    { (yyval.List) = List1((yyvsp[(2) - (2)].Expr)); ;}
    break;

  case 43:

/* Line 1455 of yacc.c  */
#line 306 "/home/dds/Lite/vlite/build/ospli/src/database/database/code/q_parser.y"
    { (yyval.List) = q_append((yyvsp[(1) - (3)].List),(yyvsp[(3) - (3)].Expr)); ;}
    break;

  case 46:

/* Line 1455 of yacc.c  */
#line 316 "/home/dds/Lite/vlite/build/ospli/src/database/database/code/q_parser.y"
    { (yyval.Expr) = q_newId((yyvsp[(1) - (1)].String));
          /* frees dynamically malloced variable length string value
             allocated by the lexical scanner.
          */
          free((yyvsp[(1) - (1)].String));
        ;}
    break;

  case 47:

/* Line 1455 of yacc.c  */
#line 326 "/home/dds/Lite/vlite/build/ospli/src/database/database/code/q_parser.y"
    { (yyval.List) = List1(q_newId((yyvsp[(1) - (1)].String)));
          /* frees dynamically malloced variable length string value
             allocated by the lexical scanner.
          */
          free((yyvsp[(1) - (1)].String));
        ;}
    break;

  case 48:

/* Line 1455 of yacc.c  */
#line 333 "/home/dds/Lite/vlite/build/ospli/src/database/database/code/q_parser.y"
    { (yyval.List) = List1(q_newId((yyvsp[(2) - (2)].String)));
          /* frees dynamically malloced variable length string value
             allocated by the lexical scanner.
          */
          free((yyvsp[(2) - (2)].String));
        ;}
    break;

  case 49:

/* Line 1455 of yacc.c  */
#line 340 "/home/dds/Lite/vlite/build/ospli/src/database/database/code/q_parser.y"
    { (yyval.List) = q_append((yyvsp[(1) - (3)].List),q_newId((yyvsp[(3) - (3)].String)));
          /* frees dynamically malloced variable length string value
             allocated by the lexical scanner.
          */
          free((yyvsp[(3) - (3)].String));
        ;}
    break;

  case 50:

/* Line 1455 of yacc.c  */
#line 350 "/home/dds/Lite/vlite/build/ospli/src/database/database/code/q_parser.y"
    { (yyval.Tag) = Q_EXPR_EQ; ;}
    break;

  case 51:

/* Line 1455 of yacc.c  */
#line 352 "/home/dds/Lite/vlite/build/ospli/src/database/database/code/q_parser.y"
    { (yyval.Tag) = Q_EXPR_NE; ;}
    break;

  case 52:

/* Line 1455 of yacc.c  */
#line 357 "/home/dds/Lite/vlite/build/ospli/src/database/database/code/q_parser.y"
    { (yyval.Tag) = Q_EXPR_LT; ;}
    break;

  case 53:

/* Line 1455 of yacc.c  */
#line 359 "/home/dds/Lite/vlite/build/ospli/src/database/database/code/q_parser.y"
    { (yyval.Tag) = Q_EXPR_LE; ;}
    break;

  case 54:

/* Line 1455 of yacc.c  */
#line 361 "/home/dds/Lite/vlite/build/ospli/src/database/database/code/q_parser.y"
    { (yyval.Tag) = Q_EXPR_GT; ;}
    break;

  case 55:

/* Line 1455 of yacc.c  */
#line 363 "/home/dds/Lite/vlite/build/ospli/src/database/database/code/q_parser.y"
    { (yyval.Tag) = Q_EXPR_GE; ;}
    break;

  case 56:

/* Line 1455 of yacc.c  */
#line 368 "/home/dds/Lite/vlite/build/ospli/src/database/database/code/q_parser.y"
    { (yyval.Expr) = q_newInt((yyvsp[(1) - (1)].Integer)); ;}
    break;

  case 57:

/* Line 1455 of yacc.c  */
#line 370 "/home/dds/Lite/vlite/build/ospli/src/database/database/code/q_parser.y"
    { (yyval.Expr) = q_newDbl((yyvsp[(1) - (1)].Float)); ;}
    break;

  case 58:

/* Line 1455 of yacc.c  */
#line 372 "/home/dds/Lite/vlite/build/ospli/src/database/database/code/q_parser.y"
    { (yyval.Expr) = q_newChr((yyvsp[(1) - (1)].Char)); ;}
    break;

  case 59:

/* Line 1455 of yacc.c  */
#line 374 "/home/dds/Lite/vlite/build/ospli/src/database/database/code/q_parser.y"
    { (yyval.Expr) = q_newStr((yyvsp[(1) - (1)].String));
          /* frees dynamically malloced variable length string value
             allocated by the lexical scanner.
          */
          free((yyvsp[(1) - (1)].String));
        ;}
    break;

  case 60:

/* Line 1455 of yacc.c  */
#line 381 "/home/dds/Lite/vlite/build/ospli/src/database/database/code/q_parser.y"
    { (yyval.Expr) = q_newVar((yyvsp[(2) - (2)].Integer));
          dollar_warning();
        ;}
    break;

  case 61:

/* Line 1455 of yacc.c  */
#line 385 "/home/dds/Lite/vlite/build/ospli/src/database/database/code/q_parser.y"
    { (yyval.Expr) = q_newVar((yyvsp[(2) - (2)].Integer)); ;}
    break;

  case 62:

/* Line 1455 of yacc.c  */
#line 387 "/home/dds/Lite/vlite/build/ospli/src/database/database/code/q_parser.y"
    { (yyval.Expr) = q_newInt(TRUE); ;}
    break;

  case 63:

/* Line 1455 of yacc.c  */
#line 389 "/home/dds/Lite/vlite/build/ospli/src/database/database/code/q_parser.y"
    { (yyval.Expr) = q_newInt(FALSE); ;}
    break;

  case 64:

/* Line 1455 of yacc.c  */
#line 391 "/home/dds/Lite/vlite/build/ospli/src/database/database/code/q_parser.y"
    { (yyval.Expr) = NULL; ;}
    break;

  case 65:

/* Line 1455 of yacc.c  */
#line 393 "/home/dds/Lite/vlite/build/ospli/src/database/database/code/q_parser.y"
    { (yyval.Expr) = NULL; ;}
    break;



/* Line 1455 of yacc.c  */
#line 2004 "q_parser.c"
      default: break;
    }
  YY_SYMBOL_PRINT ("-> $$ =", yyr1[yyn], &yyval, &yyloc);

  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);

  *++yyvsp = yyval;

  /* Now `shift' the result of the reduction.  Determine what state
     that goes to, based on the state we popped back to and the rule
     number reduced by.  */

  yyn = yyr1[yyn];

  yystate = yypgoto[yyn - YYNTOKENS] + *yyssp;
  if (0 <= yystate && yystate <= YYLAST && yycheck[yystate] == *yyssp)
    yystate = yytable[yystate];
  else
    yystate = yydefgoto[yyn - YYNTOKENS];

  goto yynewstate;


/*------------------------------------.
| yyerrlab -- here on detecting error |
`------------------------------------*/
yyerrlab:
  /* If not already recovering from an error, report this error.  */
  if (!yyerrstatus)
    {
      ++yynerrs;
#if ! YYERROR_VERBOSE
      yyerror (YY_("syntax error"));
#else
      {
	YYSIZE_T yysize = yysyntax_error (0, yystate, yychar);
	if (yymsg_alloc < yysize && yymsg_alloc < YYSTACK_ALLOC_MAXIMUM)
	  {
	    YYSIZE_T yyalloc = 2 * yysize;
	    if (! (yysize <= yyalloc && yyalloc <= YYSTACK_ALLOC_MAXIMUM))
	      yyalloc = YYSTACK_ALLOC_MAXIMUM;
	    if (yymsg != yymsgbuf)
	      YYSTACK_FREE (yymsg);
	    yymsg = (char *) YYSTACK_ALLOC (yyalloc);
	    if (yymsg)
	      yymsg_alloc = yyalloc;
	    else
	      {
		yymsg = yymsgbuf;
		yymsg_alloc = sizeof yymsgbuf;
	      }
	  }

	if (0 < yysize && yysize <= yymsg_alloc)
	  {
	    (void) yysyntax_error (yymsg, yystate, yychar);
	    yyerror (yymsg);
	  }
	else
	  {
	    yyerror (YY_("syntax error"));
	    if (yysize != 0)
	      goto yyexhaustedlab;
	  }
      }
#endif
    }



  if (yyerrstatus == 3)
    {
      /* If just tried and failed to reuse lookahead token after an
	 error, discard it.  */

      if (yychar <= YYEOF)
	{
	  /* Return failure if at end of input.  */
	  if (yychar == YYEOF)
	    YYABORT;
	}
      else
	{
	  yydestruct ("Error: discarding",
		      yytoken, &yylval);
	  yychar = YYEMPTY;
	}
    }

  /* Else will try to reuse lookahead token after shifting the error
     token.  */
  goto yyerrlab1;


/*---------------------------------------------------.
| yyerrorlab -- error raised explicitly by YYERROR.  |
`---------------------------------------------------*/
yyerrorlab:

  /* Pacify compilers like GCC when the user code never invokes
     YYERROR and the label yyerrorlab therefore never appears in user
     code.  */
  if (/*CONSTCOND*/ 0)
     goto yyerrorlab;

  /* Do not reclaim the symbols of the rule which action triggered
     this YYERROR.  */
  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);
  yystate = *yyssp;
  goto yyerrlab1;


/*-------------------------------------------------------------.
| yyerrlab1 -- common code for both syntax error and YYERROR.  |
`-------------------------------------------------------------*/
yyerrlab1:
  yyerrstatus = 3;	/* Each real token shifted decrements this.  */

  for (;;)
    {
      yyn = yypact[yystate];
      if (yyn != YYPACT_NINF)
	{
	  yyn += YYTERROR;
	  if (0 <= yyn && yyn <= YYLAST && yycheck[yyn] == YYTERROR)
	    {
	      yyn = yytable[yyn];
	      if (0 < yyn)
		break;
	    }
	}

      /* Pop the current state because it cannot handle the error token.  */
      if (yyssp == yyss)
	YYABORT;


      yydestruct ("Error: popping",
		  yystos[yystate], yyvsp);
      YYPOPSTACK (1);
      yystate = *yyssp;
      YY_STACK_PRINT (yyss, yyssp);
    }

  *++yyvsp = yylval;


  /* Shift the error token.  */
  YY_SYMBOL_PRINT ("Shifting", yystos[yyn], yyvsp, yylsp);

  yystate = yyn;
  goto yynewstate;


/*-------------------------------------.
| yyacceptlab -- YYACCEPT comes here.  |
`-------------------------------------*/
yyacceptlab:
  yyresult = 0;
  goto yyreturn;

/*-----------------------------------.
| yyabortlab -- YYABORT comes here.  |
`-----------------------------------*/
yyabortlab:
  yyresult = 1;
  goto yyreturn;

#if !defined(yyoverflow) || YYERROR_VERBOSE
/*-------------------------------------------------.
| yyexhaustedlab -- memory exhaustion comes here.  |
`-------------------------------------------------*/
yyexhaustedlab:
  yyerror (YY_("memory exhausted"));
  yyresult = 2;
  /* Fall through.  */
#endif

yyreturn:
  if (yychar != YYEMPTY)
     yydestruct ("Cleanup: discarding lookahead",
		 yytoken, &yylval);
  /* Do not reclaim the symbols of the rule which action triggered
     this YYABORT or YYACCEPT.  */
  YYPOPSTACK (yylen);
  YY_STACK_PRINT (yyss, yyssp);
  while (yyssp != yyss)
    {
      yydestruct ("Cleanup: popping",
		  yystos[*yyssp], yyvsp);
      YYPOPSTACK (1);
    }
#ifndef yyoverflow
  if (yyss != yyssa)
    YYSTACK_FREE (yyss);
#endif
#if YYERROR_VERBOSE
  if (yymsg != yymsgbuf)
    YYSTACK_FREE (yymsg);
#endif
  /* Make sure YYID is used.  */
  return YYID (yyresult);
}



/* Line 1675 of yacc.c  */
#line 396 "/home/dds/Lite/vlite/build/ospli/src/database/database/code/q_parser.y"


#include "q_parser.h"
#include "q__parser.h"
#include "os_report.h"
#include "os.h"

static os_mutex q_mtx;
static os_int32 initialise = 1; /* reset by q_parserInit */

int
yyerror (
    char* text )
{
    q_list params = NULL;

    OS_REPORT(OS_ERROR,"SQL parse failed",0,"%s near %s at line: %d, column: %d",
              text, yytext, q_parser_line, q_parser_column);
    yyclearin;

    q_dispose(expr);
    expr = NULL;
    params = q_insert(params,q_newStr(text));
    params = q_insert(params,q_newStr(yytext));
    params = q_insert(params,q_newInt(q_parser_line));
    params = q_insert(params,q_newInt(q_parser_column));
    exprError = q_newFnc(Q_EXPR_ERROR,params);

    return 0;
}

void
dollar_warning()
{
    OS_REPORT(OS_WARNING,"SQL parser",0,"The use of '$' is deprecated, use '%%' instead");
}

int
yywrap()
{
    return 1;
}

q_expr
q_parse (
    const c_char *expression)
{
    q_expr e;

    if (expression) {
        os_mutexLock(&q_mtx);
        q_parser_line = 1;
        q_parser_column = 0;
        q_parser_state = 0;
        expr = NULL;
        yy_scan_string((char *) expression);
        yyparse();
        e = expr;
        yy_delete_buffer(YY_CURRENT_BUFFER);
        q_exprSetText(e, expression);
        os_mutexUnlock(&q_mtx);
    } else {
        e = NULL;
    }
    return e;
}

void
q_parserInit()
{
    os_mutexAttr attr;

    if (initialise) {
        initialise = 0;

        os_mutexAttrInit(&attr);
	attr.scopeAttr = OS_SCOPE_PRIVATE;
	if ( os_mutexInit(&q_mtx, &attr) != os_resultSuccess )
	{
           OS_REPORT(OS_ERROR, "SQL parser", 0, "mutex init failed");
        }
    }
}

