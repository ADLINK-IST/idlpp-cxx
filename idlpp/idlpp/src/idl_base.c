/* A Bison parser, made by GNU Bison 3.0.2.  */

/* Bison implementation for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2013 Free Software Foundation, Inc.

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
#define YYBISON_VERSION "3.0.2"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1




/* Copy the first part of user declarations.  */
#line 1 "idl_base.y" /* yacc.c:339  */

#include <os_stdlib.h>
#include <os_heap.h>
#include <c_typebase.h>
#include <c_metabase.h>
#include <c_metafactory.h>
#include <c_iterator.h>
#include <c_collection.h>
#include "c_module.h"
#include "idl_fileMap.h"
#include "idl_keyDef.h"
#include "idl_catsDef.h"
#include "idl_stacDef.h"
#include "idl_streamsDef.h"
#include "idl_sematicRules.h"
#include "idl_unsupported.h"
#include "dds_cpp.h"

#ifdef _WIN32
#define YY_NO_UNISTD_H
#endif

#define yyin                 idl_base_yyin
#define yyout                idl_base_yyout
#define yyparse              idl_base_yyparse
#define yychar               idl_base_yychar
#define yyerror              idl_base_yyerror
#define yylex                idl_base_yylex
#define yylval               idl_base_yylval
#define yyrestart            idl_base_yyrestart
/*#define yywrap               idl_base_yywrap*/
#define yytext               idl_base_yytext
#define yynerrs              idl_base_yynerrs
#define yyleng               idl_base_yyleng
#define yy_scan_string       idl_base_yy_scan_string
#define yy_scan_buffer       idl_base_yy_scan_buffer
#define yy_init_buffer       idl_base_yy_init_buffer
#define yy_flush_buffer      idl_base_yy_flush_buffer
#define yy_switch_to_buffer  idl_base_yy_switch_to_buffer
#define yy_delete_buffer     idl_base_yy_delete_buffer
#define yy_create_buffer     idl_base_yy_create_buffer
#define yy_load_buffer_state idl_base_yy_load_buffer_state
#define yy_scan_bytes        idl_base_yy_scan_bytes

#define YY_INPUT(buf,result,max_size)\
  {\
    int c;\
    c = preprocess_getc();\
    if (c != EOF) {\
      buf[0] = c;\
      result = 1;\
    } else {\
      result = YY_NULL;\
    }\
  }

void *object;
void *topLevel;
c_metaObject scope;
c_metaObject scopeInternal;
c_metaObject annotationScope;

#define P_OBJECT  (c_type)metaResolve(scope, "c_object")
#define P_INTEGER (c_type)metaResolve(scope, "c_longlong")
#define P_FLOAT   (c_type)metaResolve(scope, "c_double")
/*#define P_CHAR    (c_type)metaResolve(scope, "c_char")*/
#define P_BOOL    (c_type)metaResolve(scope, "c_bool")
#define P_STRING  (c_type)metaResolve(scope, "c_string")
#define P_VOID    (NULL)

#define MAX_FILENAME_LENGTH 256
char file_name[MAX_FILENAME_LENGTH];

typedef enum c_scopeWhen {
    C_SCOPE_ALWAYS,
    C_SCOPE_NEVER,
    C_SCOPE_SMART
} c_scopeWhen;

int parser_line = 1;
int parser_column = 0;
int parser_state = 0;
int parser_error = 0;
char typeName[256];

int yylex();
int yyerror(char* text);

static void
support_warning(
    char *text);

static c_metaObject
getCollectionScope(
    c_metaObject current,
    c_metaObject subType);

static c_collectionType
declareCollection(
    c_metaObject scope,
    c_collectionType c);

static void
declareMembers(
    c_metaObject scope,
    c_iter members);

static void
declareTypeDefs(
    c_metaObject scope,
    c_iter typeDefs);

#if 0
static void
declareAttributes(
    c_metaObject scope,
    c_iter attributes);
#endif

static void
declareType(
    c_metaObject scope,
    c_type type);

static c_metaObject
declareMetaObject(
    c_metaObject scope,
    c_char *name,
    c_metaKind kind);

static c_metaObject
declareUnsupportedType(
    c_metaObject scope,
    char *name,
    enum idl_unsupported_type unsupportedType);

static int
checkTypeDefs(
    c_metaObject scope,
    c_iter declarations);

static c_metaObject
metaResolve(
    c_metaObject scope,
    const char *name);

static c_metaObject
metaResolveAnnotation(
        c_metaObject scope,
        const char* name);

static c_result
metaFinalize(
    c_metaObject o);

static c_char *
getScopedTypeName(
    const c_metaObject scope,
    const c_type type,
    const char *separator,
    c_scopeWhen scopeWhen);

extern FILE *yyin;


#line 232 "idl_base.c" /* yacc.c:339  */

# ifndef YY_NULLPTR
#  if defined __cplusplus && 201103L <= __cplusplus
#   define YY_NULLPTR nullptr
#  else
#   define YY_NULLPTR 0
#  endif
# endif

/* Enabling verbose error messages.  */
#ifdef YYERROR_VERBOSE
# undef YYERROR_VERBOSE
# define YYERROR_VERBOSE 1
#else
# define YYERROR_VERBOSE 0
#endif


/* Debug traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif
#if YYDEBUG
extern int yydebug;
#endif

/* Token type.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
  enum yytokentype
  {
    IntegerLiteral = 258,
    FloatingPtLiteral = 259,
    FixedPtLiteral = 260,
    Identifier = 261,
    StringLiteral = 262,
    WideStringLiteral = 263,
    CharacterLiteral = 264,
    WideCharacterLiteral = 265,
    IDLTOK_AMPER = 266,
    IDLTOK_ANY = 267,
    IDLTOK_ATTRIBUTE = 268,
    IDLTOK_ABSTRACT = 269,
    IDLTOK_ANNOTATION = 270,
    IDLTOK_AT = 271,
    IDLTOK_AT_POST = 272,
    IDLTOK_BOOLEAN = 273,
    IDLTOK_COLON = 274,
    IDLTOK_CONST = 275,
    IDLTOK_CONTEXT = 276,
    IDLTOK_CASE = 277,
    IDLTOK_COMMA = 278,
    IDLTOK_CHAR = 279,
    IDLTOK_COMPONENT = 280,
    IDLTOK_CONSUMES = 281,
    IDLTOK_CUSTOM = 282,
    IDLTOK_DOUBLE_COLON = 283,
    IDLTOK_DOUBLE_LEFT = 284,
    IDLTOK_DOUBLE_RIGHT = 285,
    IDLTOK_DOUBLE = 286,
    IDLTOK_DEFAULT = 287,
    IDLTOK_EQUAL = 288,
    IDLTOK_ENUM = 289,
    IDLTOK_EXCEPTION = 290,
    IDLTOK_EMITS = 291,
    IDLTOK_EVENTTYPE = 292,
    IDLTOK_FLOAT = 293,
    IDLTOK_FALSE = 294,
    IDLTOK_FACTORY = 295,
    IDLTOK_FINDER = 296,
    IDLTOK_FIXED = 297,
    IDLTOK_GETRAISES = 298,
    IDLTOK_HAT = 299,
    IDLTOK_HOME = 300,
    IDLTOK_IMPORT = 301,
    IDLTOK_INTERFACE = 302,
    IDLTOK_IN = 303,
    IDLTOK_INOUT = 304,
    IDLTOK_LONG = 305,
    IDLTOK_LPAR = 306,
    IDLTOK_LRPAR = 307,
    IDLTOK_LEPAR = 308,
    IDLTOK_LEFT = 309,
    IDLTOK_LIST = 310,
    IDLTOK_LOCAL = 311,
    IDLTOK_MINUS = 312,
    IDLTOK_MODULE = 313,
    IDLTOK_MULTIPLE = 314,
    IDLTOK_MANAGES = 315,
    IDLTOK_MAP = 316,
    IDLTOK_NATIVE = 317,
    IDLTOK_OCTET = 318,
    IDLTOK_ONEWAY = 319,
    IDLTOK_OUT = 320,
    IDLTOK_OBJECT = 321,
    IDLTOK_PLUS = 322,
    IDLTOK_PERCENT = 323,
    IDLTOK_PRIMARYKEY = 324,
    IDLTOK_PRIVATE = 325,
    IDLTOK_PROVIDES = 326,
    IDLTOK_PUBLIC = 327,
    IDLTOK_PUBLISHES = 328,
    IDLTOK_REPAR = 329,
    IDLTOK_RRPAR = 330,
    IDLTOK_RPAR = 331,
    IDLTOK_READONLY = 332,
    IDLTOK_RIGHT = 333,
    IDLTOK_RAISES = 334,
    IDLTOK_SEQUENCE = 335,
    IDLTOK_STRUCT = 336,
    IDLTOK_SWITCH = 337,
    IDLTOK_SHORT = 338,
    IDLTOK_SEMI = 339,
    IDLTOK_SLASH = 340,
    IDLTOK_STRING = 341,
    IDLTOK_SETRAISES = 342,
    IDLTOK_SUPPORTS = 343,
    IDLTOK_TIME = 344,
    IDLTOK_TIMES = 345,
    IDLTOK_TILDE = 346,
    IDLTOK_TIMESTAMP = 347,
    IDLTOK_TYPEDEF = 348,
    IDLTOK_TRUE = 349,
    IDLTOK_TRUNCATABLE = 350,
    IDLTOK_TYPEID = 351,
    IDLTOK_TYPEPREFIX = 352,
    IDLTOK_UNION = 353,
    IDLTOK_UNSIGNED = 354,
    IDLTOK_USES = 355,
    IDLTOK_VOID = 356,
    IDLTOK_VALUEBASE = 357,
    IDLTOK_VALUETYPE = 358,
    IDLTOK_VERT = 359,
    IDLTOK_WCHAR = 360,
    IDLTOK_WSTRING = 361
  };
#endif

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef union YYSTYPE YYSTYPE;
union YYSTYPE
{
#line 167 "idl_base.y" /* yacc.c:355  */

    c_longlong   Integer;
    c_string     String;
    c_char       Char;
    c_string     Fixed;
    c_double     Float;
    c_direction  Mode;
    c_literal    Value;
    c_iter       List;
    void        *Object;

#line 388 "idl_base.c" /* yacc.c:355  */
};
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);



/* Copy the second part of user declarations.  */

#line 403 "idl_base.c" /* yacc.c:358  */

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
#else
typedef signed char yytype_int8;
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
# elif ! defined YYSIZE_T
#  include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  define YYSIZE_T size_t
# else
#  define YYSIZE_T unsigned int
# endif
#endif

#define YYSIZE_MAXIMUM ((YYSIZE_T) -1)

#ifndef YY_
# if defined YYENABLE_NLS && YYENABLE_NLS
#  if ENABLE_NLS
#   include <libintl.h> /* INFRINGES ON USER NAME SPACE */
#   define YY_(Msgid) dgettext ("bison-runtime", Msgid)
#  endif
# endif
# ifndef YY_
#  define YY_(Msgid) Msgid
# endif
#endif

#ifndef YY_ATTRIBUTE
# if (defined __GNUC__                                               \
      && (2 < __GNUC__ || (__GNUC__ == 2 && 96 <= __GNUC_MINOR__)))  \
     || defined __SUNPRO_C && 0x5110 <= __SUNPRO_C
#  define YY_ATTRIBUTE(Spec) __attribute__(Spec)
# else
#  define YY_ATTRIBUTE(Spec) /* empty */
# endif
#endif

#ifndef YY_ATTRIBUTE_PURE
# define YY_ATTRIBUTE_PURE   YY_ATTRIBUTE ((__pure__))
#endif

#ifndef YY_ATTRIBUTE_UNUSED
# define YY_ATTRIBUTE_UNUSED YY_ATTRIBUTE ((__unused__))
#endif

#if !defined _Noreturn \
     && (!defined __STDC_VERSION__ || __STDC_VERSION__ < 201112)
# if defined _MSC_VER && 1200 <= _MSC_VER
#  define _Noreturn __declspec (noreturn)
# else
#  define _Noreturn YY_ATTRIBUTE ((__noreturn__))
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YYUSE(E) ((void) (E))
#else
# define YYUSE(E) /* empty */
#endif

#if defined __GNUC__ && 407 <= __GNUC__ * 100 + __GNUC_MINOR__
/* Suppress an incorrect diagnostic about yylval being uninitialized.  */
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN \
    _Pragma ("GCC diagnostic push") \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")\
    _Pragma ("GCC diagnostic ignored \"-Wmaybe-uninitialized\"")
# define YY_IGNORE_MAYBE_UNINITIALIZED_END \
    _Pragma ("GCC diagnostic pop")
#else
# define YY_INITIAL_VALUE(Value) Value
#endif
#ifndef YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_END
#endif
#ifndef YY_INITIAL_VALUE
# define YY_INITIAL_VALUE(Value) /* Nothing. */
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
#    if ! defined _ALLOCA_H && ! defined EXIT_SUCCESS
#     include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
      /* Use EXIT_SUCCESS as a witness for stdlib.h.  */
#     ifndef EXIT_SUCCESS
#      define EXIT_SUCCESS 0
#     endif
#    endif
#   endif
#  endif
# endif

# ifdef YYSTACK_ALLOC
   /* Pacify GCC's 'empty if-body' warning.  */
#  define YYSTACK_FREE(Ptr) do { /* empty */; } while (0)
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
#  if (defined __cplusplus && ! defined EXIT_SUCCESS \
       && ! ((defined YYMALLOC || defined malloc) \
             && (defined YYFREE || defined free)))
#   include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#   ifndef EXIT_SUCCESS
#    define EXIT_SUCCESS 0
#   endif
#  endif
#  ifndef YYMALLOC
#   define YYMALLOC malloc
#   if ! defined malloc && ! defined EXIT_SUCCESS
void *malloc (YYSIZE_T); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
#  ifndef YYFREE
#   define YYFREE free
#   if ! defined free && ! defined EXIT_SUCCESS
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

# define YYCOPY_NEEDED 1

/* Relocate STACK from its old location to the new one.  The
   local variables YYSIZE and YYSTACKSIZE give the old and new number of
   elements in the stack, and YYPTR gives the new location of the
   stack.  Advance YYPTR to a properly aligned location for the next
   stack.  */
# define YYSTACK_RELOCATE(Stack_alloc, Stack)                           \
    do                                                                  \
      {                                                                 \
        YYSIZE_T yynewbytes;                                            \
        YYCOPY (&yyptr->Stack_alloc, Stack, yysize);                    \
        Stack = &yyptr->Stack_alloc;                                    \
        yynewbytes = yystacksize * sizeof (*Stack) + YYSTACK_GAP_MAXIMUM; \
        yyptr += yynewbytes / sizeof (*yyptr);                          \
      }                                                                 \
    while (0)

#endif

#if defined YYCOPY_NEEDED && YYCOPY_NEEDED
/* Copy COUNT objects from SRC to DST.  The source and destination do
   not overlap.  */
# ifndef YYCOPY
#  if defined __GNUC__ && 1 < __GNUC__
#   define YYCOPY(Dst, Src, Count) \
      __builtin_memcpy (Dst, Src, (Count) * sizeof (*(Src)))
#  else
#   define YYCOPY(Dst, Src, Count)              \
      do                                        \
        {                                       \
          YYSIZE_T yyi;                         \
          for (yyi = 0; yyi < (Count); yyi++)   \
            (Dst)[yyi] = (Src)[yyi];            \
        }                                       \
      while (0)
#  endif
# endif
#endif /* !YYCOPY_NEEDED */

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  165
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   1251

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  107
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  198
/* YYNRULES -- Number of rules.  */
#define YYNRULES  417
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  684

/* YYTRANSLATE[YYX] -- Symbol number corresponding to YYX as returned
   by yylex, with out-of-bounds checking.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   361

#define YYTRANSLATE(YYX)                                                \
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[TOKEN-NUM] -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex, without out-of-bounds checking.  */
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
      35,    36,    37,    38,    39,    40,    41,    42,    43,    44,
      45,    46,    47,    48,    49,    50,    51,    52,    53,    54,
      55,    56,    57,    58,    59,    60,    61,    62,    63,    64,
      65,    66,    67,    68,    69,    70,    71,    72,    73,    74,
      75,    76,    77,    78,    79,    80,    81,    82,    83,    84,
      85,    86,    87,    88,    89,    90,    91,    92,    93,    94,
      95,    96,    97,    98,    99,   100,   101,   102,   103,   104,
     105,   106
};

#if YYDEBUG
  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,   295,   295,   299,   300,   304,   305,   309,   310,   314,
     318,   319,   323,   324,   325,   326,   327,   328,   329,   330,
     331,   332,   333,   334,   335,   336,   340,   341,   345,   349,
     353,   360,   361,   365,   366,   370,   375,   384,   393,   406,
     410,   411,   415,   416,   420,   422,   426,   427,   431,   435,
     441,   442,   443,   447,   448,   452,   453,   457,   472,   476,
     479,   481,   484,   486,   490,   491,   495,   496,   500,   501,
     502,   506,   507,   508,   509,   513,   514,   515,   516,   520,
     521,   525,   529,   533,   534,   535,   539,   543,   547,   549,
     553,   554,   558,   559,   560,   561,   562,   563,   567,   571,
     573,   578,   579,   583,   587,   591,   595,   596,   597,   601,
     602,   606,   607,   611,   615,   616,   617,   618,   622,   626,
     630,   631,   632,   633,   637,   641,   648,   655,   657,   662,
     663,   667,   668,   672,   674,   676,   678,   683,   684,   685,
     686,   687,   691,   695,   697,   702,   706,   708,   713,   717,
     718,   719,   723,   727,   728,   732,   733,   734,   735,   739,
     740,   744,   748,   751,   753,   757,   762,   773,   774,   778,
     783,   791,   799,   807,   818,   827,   839,   840,   843,   844,
     848,   849,   853,   854,   855,   856,   857,   858,   859,   863,
     865,   870,   879,   888,   900,   915,   916,   917,   918,   919,
     920,   921,   922,   923,   924,   928,   932,   933,   945,   946,
     958,   959,   971,   972,   981,   993,   994,  1003,  1015,  1016,
    1025,  1034,  1046,  1054,  1062,  1070,  1074,  1075,  1076,  1081,
    1087,  1093,  1095,  1101,  1103,  1110,  1116,  1122,  1131,  1141,
    1153,  1154,  1155,  1156,  1157,  1161,  1165,  1172,  1173,  1177,
    1178,  1179,  1180,  1184,  1185,  1186,  1190,  1191,  1192,  1193,
    1194,  1195,  1196,  1197,  1198,  1202,  1203,  1204,  1205,  1206,
    1210,  1211,  1212,  1219,  1221,  1230,  1231,  1235,  1240,  1244,
    1246,  1248,  1253,  1254,  1258,  1259,  1260,  1264,  1269,  1274,
    1279,  1280,  1281,  1285,  1290,  1295,  1300,  1305,  1310,  1315,
    1320,  1325,  1330,  1335,  1340,  1357,  1358,  1362,  1369,  1376,
    1377,  1382,  1383,  1387,  1388,  1392,  1405,  1406,  1410,  1428,
    1438,  1440,  1442,  1444,  1446,  1448,  1450,  1455,  1456,  1460,
    1461,  1465,  1467,  1488,  1489,  1493,  1501,  1503,  1509,  1511,
    1508,  1517,  1530,  1543,  1544,  1548,  1550,  1557,  1567,  1568,
    1572,  1583,  1593,  1606,  1611,  1618,  1619,  1623,  1624,  1628,
    1638,  1643,  1645,  1650,  1655,  1660,  1661,  1665,  1666,  1670,
    1672,  1677,  1703,  1704,  1708,  1712,  1712,  1714,  1718,  1719,
    1719,  1724,  1728,  1728,  1730,  1734,  1735,  1736,  1740,  1744,
    1748,  1749,  1749,  1760,  1774,  1775,  1780,  1795,  1796,  1800,
    1802,  1807,  1809,  1814,  1816,  1821,  1833,  1835,  1837,  1841,
    1842,  1846,  1848,  1852,  1853,  1857,  1862,  1864
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || 0
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "IntegerLiteral", "FloatingPtLiteral",
  "FixedPtLiteral", "Identifier", "StringLiteral", "WideStringLiteral",
  "CharacterLiteral", "WideCharacterLiteral", "IDLTOK_AMPER", "IDLTOK_ANY",
  "IDLTOK_ATTRIBUTE", "IDLTOK_ABSTRACT", "IDLTOK_ANNOTATION", "IDLTOK_AT",
  "IDLTOK_AT_POST", "IDLTOK_BOOLEAN", "IDLTOK_COLON", "IDLTOK_CONST",
  "IDLTOK_CONTEXT", "IDLTOK_CASE", "IDLTOK_COMMA", "IDLTOK_CHAR",
  "IDLTOK_COMPONENT", "IDLTOK_CONSUMES", "IDLTOK_CUSTOM",
  "IDLTOK_DOUBLE_COLON", "IDLTOK_DOUBLE_LEFT", "IDLTOK_DOUBLE_RIGHT",
  "IDLTOK_DOUBLE", "IDLTOK_DEFAULT", "IDLTOK_EQUAL", "IDLTOK_ENUM",
  "IDLTOK_EXCEPTION", "IDLTOK_EMITS", "IDLTOK_EVENTTYPE", "IDLTOK_FLOAT",
  "IDLTOK_FALSE", "IDLTOK_FACTORY", "IDLTOK_FINDER", "IDLTOK_FIXED",
  "IDLTOK_GETRAISES", "IDLTOK_HAT", "IDLTOK_HOME", "IDLTOK_IMPORT",
  "IDLTOK_INTERFACE", "IDLTOK_IN", "IDLTOK_INOUT", "IDLTOK_LONG",
  "IDLTOK_LPAR", "IDLTOK_LRPAR", "IDLTOK_LEPAR", "IDLTOK_LEFT",
  "IDLTOK_LIST", "IDLTOK_LOCAL", "IDLTOK_MINUS", "IDLTOK_MODULE",
  "IDLTOK_MULTIPLE", "IDLTOK_MANAGES", "IDLTOK_MAP", "IDLTOK_NATIVE",
  "IDLTOK_OCTET", "IDLTOK_ONEWAY", "IDLTOK_OUT", "IDLTOK_OBJECT",
  "IDLTOK_PLUS", "IDLTOK_PERCENT", "IDLTOK_PRIMARYKEY", "IDLTOK_PRIVATE",
  "IDLTOK_PROVIDES", "IDLTOK_PUBLIC", "IDLTOK_PUBLISHES", "IDLTOK_REPAR",
  "IDLTOK_RRPAR", "IDLTOK_RPAR", "IDLTOK_READONLY", "IDLTOK_RIGHT",
  "IDLTOK_RAISES", "IDLTOK_SEQUENCE", "IDLTOK_STRUCT", "IDLTOK_SWITCH",
  "IDLTOK_SHORT", "IDLTOK_SEMI", "IDLTOK_SLASH", "IDLTOK_STRING",
  "IDLTOK_SETRAISES", "IDLTOK_SUPPORTS", "IDLTOK_TIME", "IDLTOK_TIMES",
  "IDLTOK_TILDE", "IDLTOK_TIMESTAMP", "IDLTOK_TYPEDEF", "IDLTOK_TRUE",
  "IDLTOK_TRUNCATABLE", "IDLTOK_TYPEID", "IDLTOK_TYPEPREFIX",
  "IDLTOK_UNION", "IDLTOK_UNSIGNED", "IDLTOK_USES", "IDLTOK_VOID",
  "IDLTOK_VALUEBASE", "IDLTOK_VALUETYPE", "IDLTOK_VERT", "IDLTOK_WCHAR",
  "IDLTOK_WSTRING", "$accept", "start", "Specification", "Definitions",
  "Imports", "Import", "ImportedScope", "Definition", "Annotation",
  "AnnDcl", "AnnFwdDcl", "AnnHeader", "AnnBody", "AnnInheritanceSpec",
  "AnnotationScopedName", "AnnotationName", "AnnAttr", "AnnAttr_noAnnPost",
  "AnnAttr_noAnn", "AnnAppl", "AnnApplPost", "AnnotationDclName",
  "AnnApplDcl", "AnnApplParams", "AnnApplParamsList", "AnnApplParam",
  "HomeDcl", "HomeHeader", "HomeInheritanceSpec", "PrimaryKeySpec",
  "HomeBody", "HomeExports", "HomeExport", "FactoryDcl", "FinderDcl",
  "Component", "ComponentForwardDcl", "ComponentDcl", "ComponentHeader",
  "SupportedInterfaceSpec", "ComponentInheritanceSpec", "ComponentBody",
  "ComponentExportList", "ComponentExport", "ProvidesDcl", "InterfaceType",
  "UsesDcl", "EmitsDcl", "PublishesDcl", "ConsumesDcl", "Event",
  "EventForwardDcl", "EventAbsDcl", "EventDcl", "EventHeader",
  "TypePrefixDcl", "TypeIdDcl", "Value", "ValueForwardDcl", "ValueBoxDcl",
  "ValueAbsDcl", "ValueDcl", "ValueElements", "ValueHeader",
  "ValueInheritanceSpec", "ValueInheritanceSpecSupports",
  "InterfaceNameList", "InterfaceName", "ValueNameList", "ValueName",
  "ValueElement", "StateMember", "StateAttribute", "InitDcl",
  "InitParamDcls", "InitParamDcl", "InitParamAttribute", "Exports",
  "Module", "ModuleHeader", "Interface", "InterfaceDcl", "InterfaceHeader",
  "ForwardDcl", "InterfaceAttribute", "OptInterfaceBody", "InterfaceBody",
  "Export", "InheritanceSpec", "ScopedName", "ConstDcl", "ConstType",
  "ConstExp", "OrExpr", "XOrExpr", "AndExpr", "ShiftExpr", "AddExpr",
  "MultExpr", "UnaryExpr", "PrimaryExpr", "Literal", "PositiveIntConst",
  "TypeDcl", "ConstrForwardDcl", "TypeSpec", "ParamTypeSpec",
  "SimpleTypeSpec", "BaseTypeSpec", "TemplateTypeSpec", "ConstrTypeSpec",
  "Declarators", "Declarator", "SimpleDeclarator", "ComplexDeclarator",
  "FloatingPtType", "IntegerType", "SignedInt", "SignedShortInt",
  "SignedLongInt", "SignedLongLongInt", "UnsignedInt", "UnsignedShortInt",
  "UnsignedLongInt", "UnsignedLongLongInt", "CharType", "WideCharType",
  "BooleanType", "OctetType", "AnyType", "ObjectType", "ValueBaseType",
  "FixedPtType", "StructType", "StructHeader", "StructHeader_noAnn",
  "MemberList", "Member", "Member_noAnnPost", "Member_noAnn", "UnionType",
  "UnionType_noAnn", "UnionHeader", "SwitchTypeName",
  "SwitchTypeSpec_noAnnPost", "SwitchTypeSpec", "SwitchBody", "Case",
  "Case_noAnnPost", "CaseLabelList", "CaseLabel", "@1", "$@2", "EnumType",
  "EnumeratorList", "EnumeratorList_noAnnPost", "Enumerator",
  "Enumerator_noAnn", "SequenceType", "MapType", "ElementTypeSpec",
  "ElementTypeSpec_noAnnPost", "StringType", "WideStringType",
  "FixedPtConstType", "ArrayDeclarator", "ArrayIdentifier",
  "ArrayIdentifier_noAnnPost", "ArraySizeList", "FixedArraySize",
  "AttrDcl", "ReadonlyAttrSpec", "ReadonlyAttrDeclarator", "$@3",
  "SimpleDeclaratorList", "$@4", "AttrSpec", "AttrDeclarator", "$@5",
  "AttrRaisesExpr", "GetExcepExpr", "SetExcepExpr", "ExceptionList", "$@6",
  "ExceptDcl", "OptMemberList", "OpDcl", "OpAttribute", "OpTypeSpec",
  "ParameterDcls", "ParamDclList", "ParamDcl", "ParamAttribute",
  "RaisesExpr", "ScopedNameList", "ContextExpr", "SL", "StringLiteralList", YY_NULLPTR
};
#endif

# ifdef YYPRINT
/* YYTOKNUM[NUM] -- (External) token number corresponding to the
   (internal) symbol number NUM (which must be that of a token).  */
static const yytype_uint16 yytoknum[] =
{
       0,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   277,   278,   279,   280,   281,   282,   283,   284,
     285,   286,   287,   288,   289,   290,   291,   292,   293,   294,
     295,   296,   297,   298,   299,   300,   301,   302,   303,   304,
     305,   306,   307,   308,   309,   310,   311,   312,   313,   314,
     315,   316,   317,   318,   319,   320,   321,   322,   323,   324,
     325,   326,   327,   328,   329,   330,   331,   332,   333,   334,
     335,   336,   337,   338,   339,   340,   341,   342,   343,   344,
     345,   346,   347,   348,   349,   350,   351,   352,   353,   354,
     355,   356,   357,   358,   359,   360,   361
};
# endif

#define YYPACT_NINF -559

#define yypact_value_is_default(Yystate) \
  (!!((Yystate) == (-559)))

#define YYTABLE_NINF -392

#define yytable_value_is_error(Yytable_value) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
     860,    19,   321,    77,   711,    84,    21,    87,   258,   264,
     284,   229,   288,  -559,   328,   335,   341,   500,   186,   186,
     350,   370,   327,  -559,  -559,   915,   337,   915,   304,  -559,
      25,   339,   228,   310,   347,   316,  -559,  -559,   361,   333,
    -559,  -559,  -559,   371,   340,   343,   355,  -559,  -559,  -559,
    -559,   372,   358,   915,   363,  -559,   380,  -559,   383,   364,
     365,  -559,  -559,   382,  -559,  -559,  -559,   369,  -559,   373,
     439,   447,   384,   408,  -559,   452,  -559,   409,   410,   449,
     438,  -559,  -559,  -559,   461,  -559,  -559,  -559,   219,  -559,
    -559,   422,    34,  -559,   423,   450,   473,  -559,  -559,  -559,
    -559,  -559,  -559,  -559,  -559,  -559,  -559,  -559,  -559,  -559,
    -559,  -559,  -559,  -559,    56,   474,   475,   431,   432,    51,
     466,  -559,   402,   450,  -559,    46,   437,  -559,  -559,   157,
    -559,   440,   441,  -559,   451,   485,   486,  -559,   450,    81,
    -559,  -559,  -559,  -559,  -559,  -559,  -559,  -559,  -559,  -559,
    -559,  -559,  -559,  -559,  -559,  -559,  -559,  -559,  -559,  -559,
    -559,   163,   226,   411,    35,  -559,  -559,  -559,  -559,   484,
      77,  -559,   379,  -559,  -559,  -559,  1004,  -559,  -559,    36,
    -559,  1014,  -559,  -559,  -559,   904,  -559,   427,  -559,  1083,
     498,  -559,   484,   500,   455,  -559,    60,    91,   453,   502,
    -559,   795,  -559,   504,  -559,  -559,  -559,   821,   463,  -559,
     821,   508,   482,   186,   186,  -559,   429,    72,    72,   346,
     500,    33,   186,  -559,  -559,   186,   429,  -559,   186,  -559,
     186,   821,   682,   606,   501,  -559,    47,   513,  -559,   499,
    -559,  -559,  -559,   468,   484,  -559,  -559,  -559,  -559,    77,
    -559,  -559,   330,    44,  -559,   484,  -559,   510,   330,   519,
     520,  -559,  -559,   514,   454,  1074,  -559,  -559,   445,   448,
    -559,   456,   457,   459,  -559,  -559,   460,   462,   635,   186,
     186,   160,   186,   175,   469,  -559,    36,   464,   465,   467,
     470,   471,   472,   527,  -559,  -559,   476,   959,  -559,   500,
    -559,  -559,  -559,   477,  -559,   481,  -559,  1128,    63,  -559,
     500,    81,   483,   500,   484,  -559,   351,  1153,   488,  1153,
     496,   489,  -559,  -559,  -559,  -559,   525,  -559,  -559,  -559,
    -559,  -559,   821,   192,   192,  -559,   192,  -559,   487,   512,
    -559,   450,  -559,   433,   516,   553,   194,   296,   261,  -559,
    -559,  -559,  -559,  -559,   490,  -559,   491,  -559,   821,   450,
     300,  -559,  -559,  -559,  -559,  -559,   559,   494,   484,   544,
    -559,  -559,   495,   186,   497,   550,   450,  -559,   551,   450,
     450,   517,  -559,   332,   450,   556,   561,   682,   509,   297,
    -559,  -559,    81,   821,  -559,   468,  -559,  -559,   450,   335,
    -559,  -559,  -559,  -559,  -559,  -559,  -559,   335,   530,   539,
     330,  -559,  -559,  -559,  -559,  -559,  -559,  -559,  -559,  -559,
    -559,  -559,   586,   245,   265,  -559,   587,   450,   291,   160,
     588,  -559,  -559,  -559,  -559,  -559,  -559,  -559,  -559,   543,
    -559,  -559,    81,  -559,  -559,  -559,   186,  -559,  -559,  -559,
     523,  -559,  -559,  -559,   546,   391,   450,  -559,  -559,  -559,
    -559,  -559,  -559,   484,   522,  -559,   528,  1153,  1153,   532,
    1153,   595,   821,   534,  -559,  -559,  -559,  -559,   597,   821,
     821,   821,   821,   821,   821,   821,   821,   821,   821,  -559,
    -559,  -559,   186,  -559,  -559,  -559,   250,  -559,   497,  -559,
     186,   186,   186,   186,   821,   606,  -559,  -559,   821,  -559,
    -559,   536,  -559,    80,    71,  -559,  -559,    20,   146,   335,
     564,  -559,  -559,  -559,  -559,   605,  -559,   164,   535,  -559,
    -559,  -559,  -559,   569,  -559,  -559,   547,  -559,   552,  -559,
    -559,  -559,   525,  -559,   516,   553,   194,   296,   296,   261,
     261,  -559,  -559,  -559,  -559,   346,  -559,  -559,  -559,  -559,
      39,  -559,   548,  -559,    57,   549,  -559,   821,  -559,   608,
      76,  -559,   557,   554,   615,   330,   557,   565,   616,  -559,
    -559,   268,   557,  -559,   105,   567,  -559,   349,  -559,  -559,
    -559,   186,  -559,  -559,   821,  -559,  -559,   562,   335,   591,
     593,  -559,   563,  -559,   599,  -559,   557,   601,   335,  -559,
     557,   557,  -559,  -559,  -559,  -559,   577,   631,   682,   634,
    -559,   573,   256,  -559,   639,   161,  -559,   484,   500,   349,
     450,   582,  -559,   616,  -559,   186,   186,  -559,   186,  -559,
    -559,  -559,  -559,  -559,  -559,   301,    81,   609,  -559,  -559,
    -559,   578,   821,  -559,  -559,  -559,  -559,    81,  -559,  -559,
     336,   589,   590,   596,  -559,  -559,   661,  -559,  -559,   592,
     647,  -559,  -559,  -559,   651,   603,   660,  -559,   186,   661,
    -559,  -559,  -559,  -559
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_uint16 yydefact[] =
{
       0,   176,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   177,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     2,     4,     0,     7,     5,     0,    26,
      27,     0,     0,     0,     0,     0,    80,    79,     0,     0,
     108,   107,   106,     0,     0,     0,     0,   123,   122,   121,
     120,     0,     0,     0,     0,   167,     0,   168,     0,     0,
       0,   244,   240,     0,   305,   241,   316,     0,   242,     0,
       0,     0,     0,     0,    36,     0,    39,    50,     0,    46,
       0,   191,   298,   296,     0,   280,   279,   363,   288,   299,
     287,   360,     0,   297,   362,   204,     0,   200,   195,   282,
     284,   285,   286,   283,   290,   291,   292,   196,   197,   199,
     198,   201,   202,   203,    81,     0,     0,     0,     0,   110,
      60,   415,     0,    10,    11,   170,     0,   277,   243,   245,
     300,     0,     0,   301,     0,     0,     0,   302,   255,     0,
     247,   253,   254,   248,   256,   257,   258,   259,   260,   261,
     262,   263,   264,   269,   270,   271,   272,   265,   266,   267,
     268,     0,     0,   246,   125,     1,     3,     8,     6,    24,
       0,    32,     0,   306,   317,    23,   397,    58,    22,    88,
      21,   397,    20,    19,    18,   397,    17,     0,    16,   397,
       0,    14,    12,     0,     0,    15,   109,   124,     0,     0,
      37,     0,    47,     0,   192,   281,   289,     0,   294,   293,
       0,     0,     0,     0,     0,    85,    84,   115,   134,     0,
     394,     0,     0,   116,   141,     0,     0,     9,     0,   166,
       0,     0,     0,     0,   307,   319,   277,     0,   239,   273,
     275,   276,   278,     0,   365,   119,   118,   135,   126,     0,
      25,    35,     0,     0,    33,    40,    42,     0,     0,     0,
       0,   398,    65,     0,     0,   397,    69,    70,     0,     0,
      68,     0,     0,     0,   372,   373,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    89,    90,     0,     0,     0,
       0,     0,     0,     0,   154,   153,     0,   397,   150,     0,
     151,   149,   130,     0,   165,     0,   179,   397,   172,    13,
       0,     0,     0,   309,   311,   313,     0,   397,     0,   397,
       0,     0,    29,   229,   235,   234,   191,   230,   231,   232,
     233,   237,     0,     0,     0,    51,     0,   236,     0,    54,
      55,   226,    53,   205,   206,   208,   210,   212,   215,   218,
     225,   227,    38,   238,     0,   295,     0,   193,     0,    87,
     411,    86,    83,   114,   133,   350,     0,     0,   343,   345,
     348,   395,     0,     0,   139,   146,   148,   142,   143,   145,
      61,     0,   171,   189,   308,     0,     0,     0,   357,     0,
     355,   368,     0,     0,   364,   369,   366,    48,   252,     0,
     249,   250,   251,    28,    34,    41,    43,     0,     0,     0,
       0,    64,    67,   188,   187,   183,   182,   185,   184,   186,
     400,   399,     0,     0,     0,   100,     0,    99,     0,     0,
       0,    82,    91,    92,    93,    94,    95,    96,    97,     0,
     113,   132,     0,   129,   169,   181,     0,   305,   314,   316,
       0,   304,   310,   312,   288,     0,   326,   320,   321,   322,
     323,   325,   327,   329,     0,   324,     0,   397,   397,     0,
     397,     0,     0,     0,   222,   223,   224,    52,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   359,
     361,   194,     0,   349,   342,   344,     0,   393,   137,   140,
       0,     0,     0,     0,     0,     0,   358,   352,     0,   356,
     274,     0,   370,     0,   382,   384,   381,     0,     0,     0,
       0,   105,   103,    98,   104,     0,   102,     0,     0,   173,
     315,   328,   330,     0,   112,   164,     0,   127,     0,    30,
      57,   228,     0,    56,   207,   209,   211,   214,   213,   217,
     216,   221,   220,   219,   412,     0,   346,   138,   147,   144,
      62,   190,     0,   357,     0,     0,   371,     0,    44,     0,
       0,   162,    74,     0,   159,     0,    78,     0,   375,   374,
     377,     0,   409,   101,     0,     0,   152,     0,   111,   128,
     347,     0,    59,   303,     0,   354,   351,     0,     0,     0,
       0,   383,   385,   387,     0,    73,    72,     0,     0,    77,
      76,   409,   406,   408,   407,   402,     0,   403,     0,   413,
     158,     0,     0,   338,     0,     0,   331,   333,     0,   336,
      63,     0,    45,   378,   380,     0,     0,   386,     0,    71,
     160,   161,    75,   376,   401,     0,     0,     0,   396,   156,
     157,     0,     0,   341,   318,   332,   334,     0,   337,   353,
     390,     0,     0,     0,   404,   405,     0,   155,   339,     0,
       0,   388,   389,   410,   416,     0,     0,   335,     0,     0,
     414,   340,   392,   417
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -559,  -559,  -559,   179,   654,  -559,  -559,  -559,  -559,  -559,
    -559,  -559,  -559,  -559,  -559,   511,   430,  -559,   425,   -68,
    -152,  -559,   435,  -559,  -559,   209,  -559,  -559,  -559,  -559,
    -559,   426,  -559,  -559,  -559,  -559,  -559,  -559,  -559,   156,
    -559,  -559,   404,  -559,  -559,  -254,  -559,  -559,  -559,  -559,
    -559,  -559,  -559,  -559,  -559,   215,   238,  -559,  -559,  -559,
    -559,  -559,  -151,  -559,    64,  -339,   196,  -559,  -346,  -559,
    -559,  -559,  -559,  -559,  -475,  -559,  -559,  -296,  -559,  -559,
    -559,  -559,  -559,  -559,  -559,  -559,   386,  -139,  -365,    -3,
     247,  -559,  -189,  -559,   216,   222,   218,   -77,   -64,   -84,
      53,  -559,  -186,   262,  -559,   -14,  -237,  -200,  -230,  -559,
    -559,  -286,  -558,    -8,  -559,   699,     5,  -559,  -559,  -559,
    -559,  -559,  -559,  -559,  -559,     9,    14,    15,    16,  -559,
    -559,  -559,  -559,   -11,  -559,    -6,  -184,  -559,  -559,   394,
      -7,    -2,  -559,   252,  -559,  -559,  -559,    89,  -559,    90,
    -559,  -559,  -559,   -15,  -441,  -559,  -559,   356,  -559,  -559,
     204,  -559,     0,     1,  -559,  -559,  -559,  -559,   331,  -559,
    -141,  -559,  -559,  -559,  -471,  -559,  -559,  -559,  -559,  -559,
    -559,   114,  -547,  -559,   312,  -559,  -559,  -559,  -559,  -559,
      78,  -559,  -559,  -138,  -461,  -559,   714,    48
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,    22,    23,    24,    25,    26,   122,    27,    28,    29,
      30,    31,   253,   171,    76,    77,   254,   255,   256,    32,
     509,    78,    79,   338,   339,   340,    33,    34,   226,   592,
     177,   264,   265,   266,   267,    35,    36,    37,    38,   215,
     216,   284,   285,   286,   287,   426,   288,   289,   290,   291,
      39,    40,    41,    42,    43,   268,   269,    46,    47,    48,
      49,    50,   296,    51,   223,   224,   377,   378,   374,   375,
     297,   298,   299,   300,   573,   574,   575,   466,    52,    53,
      54,    55,    56,    57,    58,   305,   306,   467,   382,   341,
     271,    96,   353,   343,   344,   345,   346,   347,   348,   349,
     350,   351,   354,   272,    61,   311,   399,   140,   141,   142,
     143,   238,   239,   240,   241,   144,   145,    99,   100,   101,
     102,   103,   104,   105,   106,   146,   147,   148,   149,   150,
     151,   152,   153,    62,    63,    64,   312,   313,   314,   315,
      65,    66,    67,   462,   463,   464,   625,   626,   627,   628,
     629,   652,   676,    68,   367,   368,   369,   370,   157,   158,
     389,   390,   159,   160,   113,   242,   243,   244,   394,   395,
     273,   274,   579,   611,   515,   569,   275,   516,   570,   601,
     602,   603,   661,   670,   276,   372,   277,   278,   422,   582,
     616,   617,   618,   605,   361,   648,   674,   675
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
      80,    95,   156,   139,   111,   112,   154,   128,   123,    98,
     155,   202,   342,   107,   138,   161,   162,   250,   108,   109,
     110,   407,   400,   469,   356,   450,   173,   498,   400,   430,
     174,   554,   386,   388,   303,   499,   371,   270,   292,    81,
     309,    81,   301,   577,   170,   385,   301,   130,   580,   258,
     307,     3,   585,    82,   221,   556,    70,   252,   115,    83,
       3,    84,   279,    84,  -367,   228,    85,   211,   571,     7,
     221,   237,   280,    86,   249,   213,   -31,   131,   421,   221,
     594,   529,   446,    74,   208,    88,  -136,   236,   665,   662,
     114,   221,   396,   117,  -379,   572,   132,     3,    89,   669,
    -367,   133,  -117,   405,   257,    75,   510,   281,   591,   282,
     221,   317,   567,   263,   590,   134,   135,   209,    90,   599,
     403,    91,    71,   222,   116,   310,   270,   634,   373,   452,
    -174,   682,   640,   136,    92,   595,   283,   137,   561,   222,
      93,    94,   319,   473,   214,   292,   441,  -175,   222,   156,
     248,   366,   310,   154,   558,  -378,   528,   155,   301,   557,
     222,   138,   453,   600,   568,   387,    81,    80,   307,   491,
     245,   535,   536,   519,   538,   525,   230,   663,   156,   222,
     400,    81,   154,   623,   604,   257,   155,   506,    84,   620,
     138,   211,    81,   624,   571,   323,   324,   325,    81,   327,
     328,   329,   330,    84,   166,   156,   168,   511,  -307,   154,
     359,   360,   571,   155,    84,    44,   495,   138,   376,   379,
      84,   576,   380,   482,   483,   383,   425,   384,   247,   138,
     138,   331,   187,   246,   429,    81,   121,   654,    45,   584,
      44,   425,    44,   237,   332,   310,    80,    59,   455,   398,
     205,   521,   401,   402,   211,   398,   365,    84,   401,   402,
     318,   320,    60,    45,   118,    45,     3,   249,    44,   206,
     119,   522,    59,   211,    59,   138,   423,   424,   427,   428,
     427,   363,   364,   540,   156,   442,   337,    60,   154,    60,
     120,    45,   155,   211,   125,   156,   138,   524,   156,   154,
      59,   465,   154,   155,   447,   563,   155,   138,   449,   135,
     138,   532,    69,   456,   249,    60,   612,   613,   562,   211,
     508,   457,   565,   492,   237,   458,   136,   165,   211,   486,
     459,   460,   461,   614,   126,   604,    81,    69,   608,    69,
     650,   127,   130,   615,   555,   400,   487,   129,    82,   612,
     613,   488,   365,   484,    83,   503,   163,    81,    84,  -391,
     211,    85,     3,   485,   211,    69,   614,     3,    86,    82,
     376,   623,   362,    72,   237,    83,   164,    73,   597,    84,
      88,   624,   381,    11,   138,     7,   474,   475,   169,   476,
     172,   513,   252,    89,   175,     3,   133,    81,   176,   514,
     178,   454,   551,   552,   553,   547,   548,   398,   631,    82,
     401,   402,   179,    90,    89,    83,    91,   180,   646,    84,
     549,   550,   181,   185,   182,     7,   427,   183,   366,    92,
     190,   189,   137,   193,    90,    93,    94,   387,   609,   184,
     465,   454,   186,   383,   619,   196,   621,   188,   191,   192,
      92,   194,   456,   197,    89,   199,    93,   195,   200,   198,
     457,   -49,   201,   668,   458,     3,   203,   204,   639,   459,
     460,   461,   642,   643,    90,   656,   207,   210,   211,   212,
     217,   218,   219,   220,   651,   225,   227,   366,   229,   360,
      92,   234,   235,  -319,   231,   232,    93,   376,   379,   560,
     383,   249,   138,   304,   308,   233,    81,   316,   322,   321,
     352,   578,   130,   355,   357,   358,     3,   214,    82,   391,
     230,   393,   392,   252,    83,   408,   409,   410,    84,   413,
     411,    85,   414,   439,     7,   478,   471,   479,    86,   468,
     415,   416,   131,   417,   418,   431,   419,   470,   433,   434,
      88,   435,   440,   443,   436,   437,   438,   444,   472,   451,
     480,   132,   477,    89,   481,   365,   133,   496,   489,   490,
     494,   497,   398,   500,   501,   401,   402,   502,   237,   504,
     134,   135,   517,    90,   505,   222,    91,   507,   630,   237,
     633,   518,   520,   523,   526,   527,   206,   533,   136,    92,
     641,   539,   137,   542,   534,    93,    94,   530,   537,   541,
     566,   583,    81,   156,   657,   138,   581,   154,   130,   586,
     587,   155,     3,   588,    82,   138,   593,   596,   589,   606,
      83,   598,   660,   660,    84,   360,   604,    85,   607,  -379,
     610,    81,   622,   635,    86,   636,   632,   130,   131,   571,
     600,   638,   644,    82,   645,   647,    88,   649,   653,    83,
     659,   666,   667,    84,   671,   672,    85,   132,   121,    89,
     678,   673,   133,    86,   679,   660,   677,   131,   680,   681,
     167,   251,   406,   404,   397,    88,   134,   543,    81,    90,
     432,   412,    91,   445,   130,   544,   132,   559,    89,   546,
      82,   133,   545,    97,   448,    92,    83,   531,   137,   564,
      84,    93,    94,    85,   655,   134,   637,    81,    90,   658,
      86,    91,   493,   664,   131,   124,   512,   683,     0,    82,
       0,     0,    88,     0,    92,    83,   420,   137,     0,    84,
      93,    94,    85,   132,     0,    89,     0,     0,   133,    86,
       0,     0,     0,    87,     0,     0,     0,     0,     0,     0,
       0,    88,   134,     0,     0,    90,     0,     0,    91,     0,
       0,     0,     0,     0,    89,     0,     0,     0,     0,     0,
       0,    92,     0,     0,   137,     0,     0,    93,    94,     0,
       0,     0,     0,     0,    90,     0,     0,    91,   323,   324,
     325,   326,   327,   328,   329,   330,     0,     0,     0,     0,
      92,     0,     0,     0,     0,     0,    93,    94,     0,     0,
       0,     0,     0,    84,   323,   324,   325,    81,   327,   328,
     329,   330,     0,     0,   331,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   332,     0,    84,
       0,     0,   333,     0,     0,     0,     0,     0,     0,     0,
     331,     0,   334,     0,     0,     0,     0,     0,     0,     0,
     335,     0,     0,   332,     1,     2,     3,     0,   333,     0,
       4,     0,     0,     0,     0,     5,   336,     6,   334,   337,
       0,     0,     0,     0,     7,     8,     0,     9,     0,     0,
       0,     0,     0,     0,     0,    10,    11,    12,     0,     0,
       0,     0,   336,     0,     0,   337,    13,   258,    14,     0,
       3,     0,    15,     0,     4,     0,     0,     0,     0,     1,
       2,     3,     0,     0,     0,     4,     0,     0,     7,     8,
       5,    16,     6,     0,   293,     0,     0,     0,     0,     7,
       8,     0,     9,    17,     0,     0,    18,    19,    20,     0,
      10,     0,    12,    21,     0,     0,    15,     0,   261,     0,
       0,    13,   258,    14,   294,     3,   295,    15,     0,     4,
     302,   263,     0,     0,     0,    16,     0,     0,     0,     0,
       0,     0,     0,     7,     8,     0,    16,    17,     0,   293,
      18,    19,    20,     0,     0,     0,     0,     0,    17,     0,
       0,    18,    19,    20,     0,     0,     0,   258,    21,     0,
       3,    15,     0,   261,     4,     0,     0,   258,     0,   294,
       3,   295,     0,     0,     4,  -131,   263,     0,     7,     8,
      16,     0,     0,     0,   259,   260,     0,     0,     7,     8,
       0,     0,    17,     0,   293,    18,    19,    20,     0,     0,
       0,     0,     0,     0,     0,     0,    15,     0,   261,     0,
       0,     0,     0,     0,     0,     0,    15,     0,   261,     0,
     262,   263,     0,     0,   294,    16,   295,   258,     0,     0,
       3,   263,     0,     0,     4,    16,   258,    17,     0,     3,
      18,    19,    20,     4,     0,     0,     0,    17,     7,     8,
      18,    19,    20,     0,   259,   260,     0,     7,     8,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    15,     0,   261,     0,
       0,   258,     0,     0,     3,    15,     0,   261,     4,     0,
     -66,   263,     0,     0,     0,    16,     0,     0,     0,  -178,
     263,     0,     7,     8,    16,     0,   258,    17,     0,     3,
      18,    19,    20,     4,     0,     0,    17,     0,     0,    18,
      19,    20,     0,     0,     0,     0,     0,     7,     8,     0,
      15,     0,   261,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,  -180,   263,     0,     0,     0,    16,
       0,     0,     0,     0,     0,    15,     0,   261,     0,     0,
       0,    17,     0,     0,    18,    19,    20,     0,     0,  -163,
     263,     0,     0,     0,    16,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    17,     0,     0,    18,
      19,    20
};

static const yytype_int16 yycheck[] =
{
       3,     4,    17,    17,     4,     4,    17,    15,    11,     4,
      17,    79,   201,     4,    17,    18,    19,   169,     4,     4,
       4,   258,   252,   319,   210,   311,    32,   373,   258,   283,
      32,   492,   232,   233,   185,   374,   220,   176,   179,     6,
     192,     6,   181,   518,    19,   231,   185,    12,   519,    13,
     189,    16,   527,    18,    19,   496,    37,    13,    37,    24,
      16,    28,    26,    28,    17,    19,    31,    28,    48,    34,
      19,   139,    36,    38,    17,    19,    51,    42,   278,    19,
      23,   446,    19,     6,    50,    50,    51,     6,   646,   636,
       6,    19,   244,     6,    23,    75,    61,    16,    63,   657,
      53,    66,    51,   255,   172,    28,   392,    71,    69,    73,
      19,    51,    32,    77,   555,    80,    81,    83,    83,    43,
      76,    86,   103,    88,   103,   193,   265,   598,    95,   313,
      84,   678,   607,    98,    99,    78,   100,   102,   503,    88,
     105,   106,    51,   332,    88,   286,   297,    84,    88,   164,
     164,   219,   220,   164,   500,    84,   442,   164,   297,   498,
      88,   164,   314,    87,    84,   233,     6,   170,   307,   358,
       7,   467,   468,   410,   470,   429,    19,   638,   193,    88,
     410,     6,   193,    22,    79,   253,   193,   387,    28,    84,
     193,    28,     6,    32,    48,     3,     4,     5,     6,     7,
       8,     9,    10,    28,    25,   220,    27,   393,    51,   220,
     213,   214,    48,   220,    28,     0,   368,   220,   221,   222,
      28,    75,   225,    29,    30,   228,    66,   230,   164,   232,
     233,    39,    53,     7,    59,     6,     7,    76,     0,    75,
      25,    66,    27,   311,    52,   313,   249,     0,   316,   252,
      31,     6,   252,   252,    28,   258,     6,    28,   258,   258,
     196,   197,     0,    25,     6,    27,    16,    17,    53,    50,
       6,     6,    25,    28,    27,   278,   279,   280,   281,   282,
     283,   217,   218,   472,   299,   299,    94,    25,   299,    27,
       6,    53,   299,    28,     6,   310,   299,     6,   313,   310,
      53,   316,   313,   310,   310,   505,   313,   310,   310,    81,
     313,   463,     0,   316,    17,    53,    48,    49,   504,    28,
      23,   316,   508,    23,   392,   316,    98,     0,    28,    68,
     316,   316,   316,    65,     6,    79,     6,    25,   575,    27,
      84,     6,    12,    75,   496,   575,    85,     6,    18,    48,
      49,    90,     6,    57,    24,    23,     6,     6,    28,    23,
      28,    31,    16,    67,    28,    53,    65,    16,    38,    18,
     373,    22,   216,    52,   442,    24,     6,    56,   567,    28,
      50,    32,   226,    46,   387,    34,   333,   334,    84,   336,
      51,   399,    13,    63,    84,    16,    66,     6,    51,   407,
      84,    50,   486,   487,   488,   482,   483,   410,   594,    18,
     410,   410,    51,    83,    63,    24,    86,    84,   618,    28,
     484,   485,    51,    51,    84,    34,   429,    84,   496,    99,
      47,    51,   102,    51,    83,   105,   106,   505,   576,    84,
     455,    50,    84,   446,   582,     6,   584,    84,    84,    84,
      99,    82,   455,     6,    63,    47,   105,    84,     6,    75,
     455,    52,    52,   652,   455,    16,    28,     6,   606,   455,
     455,   455,   610,   611,    83,   627,    54,    54,    28,     6,
       6,     6,    51,    51,   622,    19,    84,   555,    51,   492,
      99,     6,     6,    82,    54,    54,   105,   500,   501,   502,
     503,    17,   505,    76,     6,    54,     6,    52,     6,    56,
       6,   519,    12,    50,     6,    33,    16,    88,    18,     6,
      19,    53,    23,    13,    24,     6,     6,    13,    28,    84,
      76,    31,    84,     6,    34,    23,    47,   104,    38,    51,
      84,    84,    42,    84,    84,    76,    84,    51,    84,    84,
      50,    84,    76,    76,    84,    84,    84,    76,    33,    76,
      44,    61,    75,    63,    11,     6,    66,    23,    78,    78,
      76,    76,   575,    23,    23,   575,   575,    60,   646,    23,
      80,    81,    52,    83,    23,    88,    86,    78,   591,   657,
     598,    52,     6,     6,     6,    52,    50,    75,    98,    99,
     608,     6,   102,     6,    76,   105,   106,    84,    76,    75,
      74,     6,     6,   628,   628,   618,    52,   628,    12,    84,
      51,   628,    16,    76,    18,   628,    78,    78,    76,    75,
      24,    23,   635,   636,    28,   638,    79,    31,    23,    23,
      75,     6,    75,    52,    38,    52,    84,    12,    42,    48,
      87,    52,    75,    18,    23,    21,    50,    84,    19,    24,
      78,    52,    84,    28,    75,    75,    31,    61,     7,    63,
      23,    75,    66,    38,    23,   678,    84,    42,    75,    19,
      26,   170,   257,   253,   249,    50,    80,   478,     6,    83,
     286,   265,    86,   307,    12,   479,    61,   501,    63,   481,
      18,    66,   480,     4,   310,    99,    24,   455,   102,   505,
      28,   105,   106,    31,   625,    80,   602,     6,    83,   629,
      38,    86,   366,   645,    42,    11,   395,   679,    -1,    18,
      -1,    -1,    50,    -1,    99,    24,   101,   102,    -1,    28,
     105,   106,    31,    61,    -1,    63,    -1,    -1,    66,    38,
      -1,    -1,    -1,    42,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    50,    80,    -1,    -1,    83,    -1,    -1,    86,    -1,
      -1,    -1,    -1,    -1,    63,    -1,    -1,    -1,    -1,    -1,
      -1,    99,    -1,    -1,   102,    -1,    -1,   105,   106,    -1,
      -1,    -1,    -1,    -1,    83,    -1,    -1,    86,     3,     4,
       5,     6,     7,     8,     9,    10,    -1,    -1,    -1,    -1,
      99,    -1,    -1,    -1,    -1,    -1,   105,   106,    -1,    -1,
      -1,    -1,    -1,    28,     3,     4,     5,     6,     7,     8,
       9,    10,    -1,    -1,    39,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    52,    -1,    28,
      -1,    -1,    57,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      39,    -1,    67,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      75,    -1,    -1,    52,    14,    15,    16,    -1,    57,    -1,
      20,    -1,    -1,    -1,    -1,    25,    91,    27,    67,    94,
      -1,    -1,    -1,    -1,    34,    35,    -1,    37,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    45,    46,    47,    -1,    -1,
      -1,    -1,    91,    -1,    -1,    94,    56,    13,    58,    -1,
      16,    -1,    62,    -1,    20,    -1,    -1,    -1,    -1,    14,
      15,    16,    -1,    -1,    -1,    20,    -1,    -1,    34,    35,
      25,    81,    27,    -1,    40,    -1,    -1,    -1,    -1,    34,
      35,    -1,    37,    93,    -1,    -1,    96,    97,    98,    -1,
      45,    -1,    47,   103,    -1,    -1,    62,    -1,    64,    -1,
      -1,    56,    13,    58,    70,    16,    72,    62,    -1,    20,
      76,    77,    -1,    -1,    -1,    81,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    34,    35,    -1,    81,    93,    -1,    40,
      96,    97,    98,    -1,    -1,    -1,    -1,    -1,    93,    -1,
      -1,    96,    97,    98,    -1,    -1,    -1,    13,   103,    -1,
      16,    62,    -1,    64,    20,    -1,    -1,    13,    -1,    70,
      16,    72,    -1,    -1,    20,    76,    77,    -1,    34,    35,
      81,    -1,    -1,    -1,    40,    41,    -1,    -1,    34,    35,
      -1,    -1,    93,    -1,    40,    96,    97,    98,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    62,    -1,    64,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    62,    -1,    64,    -1,
      76,    77,    -1,    -1,    70,    81,    72,    13,    -1,    -1,
      16,    77,    -1,    -1,    20,    81,    13,    93,    -1,    16,
      96,    97,    98,    20,    -1,    -1,    -1,    93,    34,    35,
      96,    97,    98,    -1,    40,    41,    -1,    34,    35,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    62,    -1,    64,    -1,
      -1,    13,    -1,    -1,    16,    62,    -1,    64,    20,    -1,
      76,    77,    -1,    -1,    -1,    81,    -1,    -1,    -1,    76,
      77,    -1,    34,    35,    81,    -1,    13,    93,    -1,    16,
      96,    97,    98,    20,    -1,    -1,    93,    -1,    -1,    96,
      97,    98,    -1,    -1,    -1,    -1,    -1,    34,    35,    -1,
      62,    -1,    64,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    76,    77,    -1,    -1,    -1,    81,
      -1,    -1,    -1,    -1,    -1,    62,    -1,    64,    -1,    -1,
      -1,    93,    -1,    -1,    96,    97,    98,    -1,    -1,    76,
      77,    -1,    -1,    -1,    81,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    93,    -1,    -1,    96,
      97,    98
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_uint16 yystos[] =
{
       0,    14,    15,    16,    20,    25,    27,    34,    35,    37,
      45,    46,    47,    56,    58,    62,    81,    93,    96,    97,
      98,   103,   108,   109,   110,   111,   112,   114,   115,   116,
     117,   118,   126,   133,   134,   142,   143,   144,   145,   157,
     158,   159,   160,   161,   162,   163,   164,   165,   166,   167,
     168,   170,   185,   186,   187,   188,   189,   190,   191,   197,
     210,   211,   240,   241,   242,   247,   248,   249,   260,   291,
      37,   103,    52,    56,     6,    28,   121,   122,   128,   129,
     196,     6,    18,    24,    28,    31,    38,    42,    50,    63,
      83,    86,    99,   105,   106,   196,   198,   222,   223,   224,
     225,   226,   227,   228,   229,   230,   231,   232,   233,   234,
     235,   269,   270,   271,     6,    37,   103,     6,     6,     6,
       6,     7,   113,   196,   303,     6,     6,     6,   220,     6,
      12,    42,    61,    66,    80,    81,    98,   102,   196,   212,
     214,   215,   216,   217,   222,   223,   232,   233,   234,   235,
     236,   237,   238,   239,   240,   247,   260,   265,   266,   269,
     270,   196,   196,     6,     6,     0,   110,   111,   110,    84,
      19,   120,    51,   242,   248,    84,    51,   137,    84,    51,
      84,    51,    84,    84,    84,    51,    84,   110,    84,    51,
      47,    84,    84,    51,    82,    84,     6,     6,    75,    47,
       6,    52,   126,    28,     6,    31,    50,    54,    50,    83,
      54,    28,     6,    19,    88,   146,   147,     6,     6,    51,
      51,    19,    88,   171,   172,    19,   135,    84,    19,    51,
      19,    54,    54,    54,     6,     6,     6,   126,   218,   219,
     220,   221,   272,   273,   274,     7,     7,   171,   212,    17,
     127,   122,    13,   119,   123,   124,   125,   126,    13,    40,
      41,    64,    76,    77,   138,   139,   140,   141,   162,   163,
     194,   197,   210,   277,   278,   283,   291,   293,   294,    26,
      36,    71,    73,   100,   148,   149,   150,   151,   153,   154,
     155,   156,   277,    40,    70,    72,   169,   177,   178,   179,
     180,   194,    76,   169,    76,   192,   193,   194,     6,   127,
     126,   212,   243,   244,   245,   246,    52,    51,   171,    51,
     171,    56,     6,     3,     4,     5,     6,     7,     8,     9,
      10,    39,    52,    57,    67,    75,    91,    94,   130,   131,
     132,   196,   199,   200,   201,   202,   203,   204,   205,   206,
     207,   208,     6,   199,   209,    50,   209,     6,    33,   196,
     196,   301,   146,   171,   171,     6,   126,   261,   262,   263,
     264,   243,   292,    95,   175,   176,   196,   173,   174,   196,
     196,   146,   195,   196,   196,   209,   214,   126,   214,   267,
     268,     6,    23,    53,   275,   276,   127,   129,   196,   213,
     215,   269,   270,    76,   123,   127,   125,   213,     6,     6,
      13,    76,   138,    84,    84,    84,    84,    84,    84,    84,
     101,   214,   295,   196,   196,    66,   152,   196,   196,    59,
     152,    76,   149,    84,    84,    84,    84,    84,    84,     6,
      76,   169,   212,    76,    76,   193,    19,   242,   246,   248,
     218,    76,   243,   127,    50,   126,   196,   223,   232,   233,
     234,   235,   250,   251,   252,   260,   184,   194,    51,   184,
      51,    47,    33,   199,   207,   207,   207,    75,    23,   104,
      44,    11,    29,    30,    57,    67,    68,    85,    90,    78,
      78,   199,    23,   264,    76,   127,    23,    76,   175,   172,
      23,    23,    60,    23,    23,    23,   214,    78,    23,   127,
     218,   209,   275,   220,   220,   281,   284,    52,    52,   213,
       6,     6,     6,     6,     6,   152,     6,    52,   218,   195,
      84,   250,   127,    75,    76,   184,   184,    76,   184,     6,
     199,    75,     6,   132,   201,   202,   203,   204,   204,   205,
     205,   206,   206,   206,   301,   127,   261,   172,   175,   173,
     196,   195,   209,   214,   267,   209,    74,    32,    84,   282,
     285,    48,    75,   181,   182,   183,    75,   181,   220,   279,
     281,    52,   296,     6,    75,   181,    84,    51,    76,    76,
     261,    69,   136,    78,    23,    78,    78,   199,    23,    43,
      87,   286,   287,   288,    79,   300,    75,    23,   213,   300,
      75,   280,    48,    49,    65,    75,   297,   298,   299,   300,
      84,   300,    75,    22,    32,   253,   254,   255,   256,   257,
     196,   209,    84,   220,   281,    52,    52,   288,    52,   300,
     181,   220,   300,   300,    75,    23,   214,    21,   302,    84,
      84,   300,   258,    19,    76,   254,   127,   212,   256,    78,
     196,   289,   289,   301,   297,   219,    52,    84,   199,   219,
     290,    75,    75,    75,   303,   304,   259,    84,    23,    23,
      75,    19,   289,   304
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint16 yyr1[] =
{
       0,   107,   108,   109,   109,   110,   110,   111,   111,   112,
     113,   113,   114,   114,   114,   114,   114,   114,   114,   114,
     114,   114,   114,   114,   114,   114,   115,   115,   116,   117,
     117,   118,   118,   119,   119,   120,   121,   121,   121,   122,
     123,   123,   124,   124,   125,   125,   126,   126,   127,   128,
     129,   129,   129,   130,   130,   131,   131,   132,   133,   134,
     135,   135,   136,   136,   137,   137,   138,   138,   139,   139,
     139,   140,   140,   140,   140,   141,   141,   141,   141,   142,
     142,   143,   144,   145,   145,   145,   146,   147,   148,   148,
     149,   149,   150,   150,   150,   150,   150,   150,   151,   152,
     152,   153,   153,   154,   155,   156,   157,   157,   157,   158,
     158,   159,   159,   160,   161,   161,   161,   161,   162,   163,
     164,   164,   164,   164,   165,   165,   166,   167,   167,   168,
     168,   169,   169,   170,   170,   170,   170,   171,   171,   171,
     171,   171,   172,   173,   173,   174,   175,   175,   176,   177,
     177,   177,   178,   179,   179,   180,   180,   180,   180,   181,
     181,   182,   183,   184,   184,   185,   186,   187,   187,   188,
     189,   189,   189,   189,   190,   190,   191,   191,   192,   192,
     193,   193,   194,   194,   194,   194,   194,   194,   194,   195,
     195,   196,   196,   196,   197,   198,   198,   198,   198,   198,
     198,   198,   198,   198,   198,   199,   200,   200,   201,   201,
     202,   202,   203,   203,   203,   204,   204,   204,   205,   205,
     205,   205,   206,   206,   206,   206,   207,   207,   207,   208,
     208,   208,   208,   208,   208,   208,   208,   208,   209,   210,
     210,   210,   210,   210,   210,   211,   211,   212,   212,   213,
     213,   213,   213,   214,   214,   214,   215,   215,   215,   215,
     215,   215,   215,   215,   215,   216,   216,   216,   216,   216,
     217,   217,   217,   218,   218,   219,   219,   220,   221,   222,
     222,   222,   223,   223,   224,   224,   224,   225,   226,   227,
     228,   228,   228,   229,   230,   231,   232,   233,   234,   235,
     236,   237,   238,   239,   240,   241,   241,   242,   242,   243,
     243,   244,   244,   245,   245,   246,   247,   247,   248,   249,
     250,   250,   250,   250,   250,   250,   250,   251,   251,   252,
     252,   253,   253,   254,   254,   255,   256,   256,   258,   259,
     257,   257,   260,   261,   261,   262,   262,   262,   263,   263,
     264,   265,   265,   266,   266,   267,   267,   268,   268,   269,
     269,   270,   270,   271,   272,   273,   273,   274,   274,   275,
     275,   276,   277,   277,   278,   280,   279,   279,   281,   282,
     281,   283,   285,   284,   284,   286,   286,   286,   287,   288,
     289,   290,   289,   291,   292,   292,   293,   294,   294,   295,
     295,   296,   296,   297,   297,   298,   299,   299,   299,   300,
     300,   301,   301,   302,   302,   303,   304,   304
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     1,     2,     1,     1,     2,     1,     2,     3,
       1,     1,     2,     3,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     3,     1,     1,     4,     4,
       6,     1,     2,     1,     2,     2,     1,     2,     3,     1,
       1,     2,     1,     2,     4,     6,     2,     3,     2,     1,
       1,     3,     4,     1,     1,     1,     3,     3,     2,     7,
       0,     2,     0,     2,     3,     2,     1,     2,     1,     1,
       1,     6,     5,     5,     4,     6,     5,     5,     4,     1,
       1,     2,     4,     4,     3,     3,     2,     2,     0,     1,
       1,     2,     2,     2,     2,     2,     2,     2,     3,     1,
       1,     4,     3,     3,     3,     3,     1,     1,     1,     3,
       2,     7,     6,     4,     4,     3,     3,     2,     3,     3,
       1,     1,     1,     1,     3,     2,     3,     6,     7,     4,
       3,     1,     2,     4,     3,     3,     2,     3,     4,     2,
       3,     1,     2,     1,     3,     1,     1,     3,     1,     1,
       1,     1,     4,     1,     1,     7,     6,     6,     5,     1,
       3,     3,     1,     0,     2,     3,     3,     1,     1,     4,
       2,     4,     3,     5,     2,     3,     1,     1,     0,     1,
       1,     2,     2,     2,     2,     2,     2,     2,     2,     1,
       3,     1,     2,     3,     5,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     3,     1,     3,
       1,     3,     1,     3,     3,     1,     3,     3,     1,     3,
       3,     3,     2,     2,     2,     1,     1,     1,     3,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     3,
       1,     1,     1,     2,     1,     2,     2,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     3,     1,     1,     1,     1,     1,
       1,     2,     1,     1,     1,     1,     1,     1,     1,     2,
       1,     1,     1,     2,     2,     3,     1,     1,     1,     1,
       1,     1,     1,     6,     4,     1,     2,     2,     4,     1,
       2,     1,     2,     1,     2,     3,     1,     2,     8,     2,
       1,     1,     1,     1,     1,     1,     1,     1,     2,     1,
       2,     1,     2,     1,     2,     4,     1,     2,     0,     0,
       5,     2,     5,     1,     2,     1,     3,     4,     1,     2,
       1,     6,     4,     8,     6,     1,     2,     1,     2,     4,
       1,     4,     1,     1,     2,     1,     2,     1,     2,     1,
       2,     3,     1,     1,     4,     0,     3,     1,     1,     0,
       4,     3,     0,     3,     1,     1,     2,     1,     4,     4,
       1,     0,     4,     5,     0,     1,     6,     0,     1,     1,
       1,     3,     2,     1,     3,     3,     1,     1,     1,     0,
       4,     1,     3,     0,     4,     1,     1,     3
};


#define yyerrok         (yyerrstatus = 0)
#define yyclearin       (yychar = YYEMPTY)
#define YYEMPTY         (-2)
#define YYEOF           0

#define YYACCEPT        goto yyacceptlab
#define YYABORT         goto yyabortlab
#define YYERROR         goto yyerrorlab


#define YYRECOVERING()  (!!yyerrstatus)

#define YYBACKUP(Token, Value)                                  \
do                                                              \
  if (yychar == YYEMPTY)                                        \
    {                                                           \
      yychar = (Token);                                         \
      yylval = (Value);                                         \
      YYPOPSTACK (yylen);                                       \
      yystate = *yyssp;                                         \
      goto yybackup;                                            \
    }                                                           \
  else                                                          \
    {                                                           \
      yyerror (YY_("syntax error: cannot back up")); \
      YYERROR;                                                  \
    }                                                           \
while (0)

/* Error token number */
#define YYTERROR        1
#define YYERRCODE       256



/* Enable debugging if requested.  */
#if YYDEBUG

# ifndef YYFPRINTF
#  include <stdio.h> /* INFRINGES ON USER NAME SPACE */
#  define YYFPRINTF fprintf
# endif

# define YYDPRINTF(Args)                        \
do {                                            \
  if (yydebug)                                  \
    YYFPRINTF Args;                             \
} while (0)

/* This macro is provided for backward compatibility. */
#ifndef YY_LOCATION_PRINT
# define YY_LOCATION_PRINT(File, Loc) ((void) 0)
#endif


# define YY_SYMBOL_PRINT(Title, Type, Value, Location)                    \
do {                                                                      \
  if (yydebug)                                                            \
    {                                                                     \
      YYFPRINTF (stderr, "%s ", Title);                                   \
      yy_symbol_print (stderr,                                            \
                  Type, Value); \
      YYFPRINTF (stderr, "\n");                                           \
    }                                                                     \
} while (0)


/*----------------------------------------.
| Print this symbol's value on YYOUTPUT.  |
`----------------------------------------*/

static void
yy_symbol_value_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
{
  FILE *yyo = yyoutput;
  YYUSE (yyo);
  if (!yyvaluep)
    return;
# ifdef YYPRINT
  if (yytype < YYNTOKENS)
    YYPRINT (yyoutput, yytoknum[yytype], *yyvaluep);
# endif
  YYUSE (yytype);
}


/*--------------------------------.
| Print this symbol on YYOUTPUT.  |
`--------------------------------*/

static void
yy_symbol_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
{
  YYFPRINTF (yyoutput, "%s %s (",
             yytype < YYNTOKENS ? "token" : "nterm", yytname[yytype]);

  yy_symbol_value_print (yyoutput, yytype, yyvaluep);
  YYFPRINTF (yyoutput, ")");
}

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

static void
yy_stack_print (yytype_int16 *yybottom, yytype_int16 *yytop)
{
  YYFPRINTF (stderr, "Stack now");
  for (; yybottom <= yytop; yybottom++)
    {
      int yybot = *yybottom;
      YYFPRINTF (stderr, " %d", yybot);
    }
  YYFPRINTF (stderr, "\n");
}

# define YY_STACK_PRINT(Bottom, Top)                            \
do {                                                            \
  if (yydebug)                                                  \
    yy_stack_print ((Bottom), (Top));                           \
} while (0)


/*------------------------------------------------.
| Report that the YYRULE is going to be reduced.  |
`------------------------------------------------*/

static void
yy_reduce_print (yytype_int16 *yyssp, YYSTYPE *yyvsp, int yyrule)
{
  unsigned long int yylno = yyrline[yyrule];
  int yynrhs = yyr2[yyrule];
  int yyi;
  YYFPRINTF (stderr, "Reducing stack by rule %d (line %lu):\n",
             yyrule - 1, yylno);
  /* The symbols being reduced.  */
  for (yyi = 0; yyi < yynrhs; yyi++)
    {
      YYFPRINTF (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr,
                       yystos[yyssp[yyi + 1 - yynrhs]],
                       &(yyvsp[(yyi + 1) - (yynrhs)])
                                              );
      YYFPRINTF (stderr, "\n");
    }
}

# define YY_REDUCE_PRINT(Rule)          \
do {                                    \
  if (yydebug)                          \
    yy_reduce_print (yyssp, yyvsp, Rule); \
} while (0)

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
#ifndef YYINITDEPTH
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
static YYSIZE_T
yystrlen (const char *yystr)
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
static char *
yystpcpy (char *yydest, const char *yysrc)
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

/* Copy into *YYMSG, which is of size *YYMSG_ALLOC, an error message
   about the unexpected token YYTOKEN for the state stack whose top is
   YYSSP.

   Return 0 if *YYMSG was successfully written.  Return 1 if *YYMSG is
   not large enough to hold the message.  In that case, also set
   *YYMSG_ALLOC to the required number of bytes.  Return 2 if the
   required number of bytes is too large to store.  */
static int
yysyntax_error (YYSIZE_T *yymsg_alloc, char **yymsg,
                yytype_int16 *yyssp, int yytoken)
{
  YYSIZE_T yysize0 = yytnamerr (YY_NULLPTR, yytname[yytoken]);
  YYSIZE_T yysize = yysize0;
  enum { YYERROR_VERBOSE_ARGS_MAXIMUM = 5 };
  /* Internationalized format string. */
  const char *yyformat = YY_NULLPTR;
  /* Arguments of yyformat. */
  char const *yyarg[YYERROR_VERBOSE_ARGS_MAXIMUM];
  /* Number of reported tokens (one for the "unexpected", one per
     "expected"). */
  int yycount = 0;

  /* There are many possibilities here to consider:
     - If this state is a consistent state with a default action, then
       the only way this function was invoked is if the default action
       is an error action.  In that case, don't check for expected
       tokens because there are none.
     - The only way there can be no lookahead present (in yychar) is if
       this state is a consistent state with a default action.  Thus,
       detecting the absence of a lookahead is sufficient to determine
       that there is no unexpected or expected token to report.  In that
       case, just report a simple "syntax error".
     - Don't assume there isn't a lookahead just because this state is a
       consistent state with a default action.  There might have been a
       previous inconsistent state, consistent state with a non-default
       action, or user semantic action that manipulated yychar.
     - Of course, the expected token list depends on states to have
       correct lookahead information, and it depends on the parser not
       to perform extra reductions after fetching a lookahead from the
       scanner and before detecting a syntax error.  Thus, state merging
       (from LALR or IELR) and default reductions corrupt the expected
       token list.  However, the list is correct for canonical LR with
       one exception: it will still contain any token that will not be
       accepted due to an error action in a later state.
  */
  if (yytoken != YYEMPTY)
    {
      int yyn = yypact[*yyssp];
      yyarg[yycount++] = yytname[yytoken];
      if (!yypact_value_is_default (yyn))
        {
          /* Start YYX at -YYN if negative to avoid negative indexes in
             YYCHECK.  In other words, skip the first -YYN actions for
             this state because they are default actions.  */
          int yyxbegin = yyn < 0 ? -yyn : 0;
          /* Stay within bounds of both yycheck and yytname.  */
          int yychecklim = YYLAST - yyn + 1;
          int yyxend = yychecklim < YYNTOKENS ? yychecklim : YYNTOKENS;
          int yyx;

          for (yyx = yyxbegin; yyx < yyxend; ++yyx)
            if (yycheck[yyx + yyn] == yyx && yyx != YYTERROR
                && !yytable_value_is_error (yytable[yyx + yyn]))
              {
                if (yycount == YYERROR_VERBOSE_ARGS_MAXIMUM)
                  {
                    yycount = 1;
                    yysize = yysize0;
                    break;
                  }
                yyarg[yycount++] = yytname[yyx];
                {
                  YYSIZE_T yysize1 = yysize + yytnamerr (YY_NULLPTR, yytname[yyx]);
                  if (! (yysize <= yysize1
                         && yysize1 <= YYSTACK_ALLOC_MAXIMUM))
                    return 2;
                  yysize = yysize1;
                }
              }
        }
    }

  switch (yycount)
    {
# define YYCASE_(N, S)                      \
      case N:                               \
        yyformat = S;                       \
      break
      YYCASE_(0, YY_("syntax error"));
      YYCASE_(1, YY_("syntax error, unexpected %s"));
      YYCASE_(2, YY_("syntax error, unexpected %s, expecting %s"));
      YYCASE_(3, YY_("syntax error, unexpected %s, expecting %s or %s"));
      YYCASE_(4, YY_("syntax error, unexpected %s, expecting %s or %s or %s"));
      YYCASE_(5, YY_("syntax error, unexpected %s, expecting %s or %s or %s or %s"));
# undef YYCASE_
    }

  {
    YYSIZE_T yysize1 = yysize + yystrlen (yyformat);
    if (! (yysize <= yysize1 && yysize1 <= YYSTACK_ALLOC_MAXIMUM))
      return 2;
    yysize = yysize1;
  }

  if (*yymsg_alloc < yysize)
    {
      *yymsg_alloc = 2 * yysize;
      if (! (yysize <= *yymsg_alloc
             && *yymsg_alloc <= YYSTACK_ALLOC_MAXIMUM))
        *yymsg_alloc = YYSTACK_ALLOC_MAXIMUM;
      return 1;
    }

  /* Avoid sprintf, as that infringes on the user's name space.
     Don't have undefined behavior even if the translation
     produced a string with the wrong number of "%s"s.  */
  {
    char *yyp = *yymsg;
    int yyi = 0;
    while ((*yyp = *yyformat) != '\0')
      if (*yyp == '%' && yyformat[1] == 's' && yyi < yycount)
        {
          yyp += yytnamerr (yyp, yyarg[yyi++]);
          yyformat += 2;
        }
      else
        {
          yyp++;
          yyformat++;
        }
  }
  return 0;
}
#endif /* YYERROR_VERBOSE */

/*-----------------------------------------------.
| Release the memory associated to this symbol.  |
`-----------------------------------------------*/

static void
yydestruct (const char *yymsg, int yytype, YYSTYPE *yyvaluep)
{
  YYUSE (yyvaluep);
  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yytype, yyvaluep, yylocationp);

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YYUSE (yytype);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}




/* The lookahead symbol.  */
int yychar;

/* The semantic value of the lookahead symbol.  */
YYSTYPE yylval;
/* Number of syntax errors so far.  */
int yynerrs;


/*----------.
| yyparse.  |
`----------*/

int
yyparse (void)
{
    int yystate;
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus;

    /* The stacks and their tools:
       'yyss': related to states.
       'yyvs': related to semantic values.

       Refer to the stacks through separate pointers, to allow yyoverflow
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
  int yytoken = 0;
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

  yyssp = yyss = yyssa;
  yyvsp = yyvs = yyvsa;
  yystacksize = YYINITDEPTH;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yystate = 0;
  yyerrstatus = 0;
  yynerrs = 0;
  yychar = YYEMPTY; /* Cause a token to be read.  */
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
  if (yypact_value_is_default (yyn))
    goto yydefault;

  /* Not known => get a lookahead token if don't already have one.  */

  /* YYCHAR is either YYEMPTY or YYEOF or a valid lookahead symbol.  */
  if (yychar == YYEMPTY)
    {
      YYDPRINTF ((stderr, "Reading a token: "));
      yychar = yylex ();
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
      if (yytable_value_is_error (yyn))
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
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END

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
     '$$ = $1'.

     Otherwise, the following line sets YYVAL to garbage.
     This behavior is undocumented and Bison
     users should not rely upon it.  Assigning to YYVAL
     unconditionally makes the parser a bit smaller, and it avoids a
     GCC warning that YYVAL may be used uninitialized.  */
  yyval = yyvsp[1-yylen];


  YY_REDUCE_PRINT (yyn);
  switch (yyn)
    {
        case 28:
#line 346 "idl_base.y" /* yacc.c:1646  */
    { scope = scope->definedIn;}
#line 2176 "idl_base.c" /* yacc.c:1646  */
    break;

  case 29:
#line 350 "idl_base.y" /* yacc.c:1646  */
    {
        scope = declareMetaObject(scope,(yyvsp[0].String),M_ENUMERATION);
}
#line 2184 "idl_base.c" /* yacc.c:1646  */
    break;

  case 30:
#line 354 "idl_base.y" /* yacc.c:1646  */
    {
        scope = declareMetaObject(scope,(yyvsp[0].String),M_ENUMERATION);
}
#line 2192 "idl_base.c" /* yacc.c:1646  */
    break;

  case 36:
#line 376 "idl_base.y" /* yacc.c:1646  */
    {
          idl_checkReferencedIdentifier(scope,(yyvsp[0].String),yyerror);
          (yyval.Object) = (void *)metaResolveAnnotation(scope,(yyvsp[0].String));
          if ((yyval.Object) == NULL) {
            yyerror("Undefined identifier");
            YYABORT;
          }
        }
#line 2205 "idl_base.c" /* yacc.c:1646  */
    break;

  case 37:
#line 385 "idl_base.y" /* yacc.c:1646  */
    {
          idl_checkReferencedIdentifier(topLevel,(yyvsp[0].String),yyerror);
          (yyval.Object) = (void *)metaResolveAnnotation(topLevel,(yyvsp[0].String));
          if ((yyval.Object) == NULL) {
            yyerror("Undefined identifier");
            YYABORT;
          }
        }
#line 2218 "idl_base.c" /* yacc.c:1646  */
    break;

  case 38:
#line 394 "idl_base.y" /* yacc.c:1646  */
    {
          idl_checkReferencedIdentifier((yyvsp[-2].Object),(yyvsp[0].String),yyerror);
          (yyval.Object) = (void *)metaResolveAnnotation((yyvsp[-2].Object),(yyvsp[0].String));
          if ((yyval.Object) == NULL) {
            yyerror("Undefined identifier");
            YYABORT;
          }
        }
#line 2231 "idl_base.c" /* yacc.c:1646  */
    break;

  case 44:
#line 421 "idl_base.y" /* yacc.c:1646  */
    {       (yyval.Object) = c_metaDeclare(scope, c_declaratorName((yyvsp[-1].Object)), M_ATTRIBUTE);}
#line 2237 "idl_base.c" /* yacc.c:1646  */
    break;

  case 45:
#line 423 "idl_base.y" /* yacc.c:1646  */
    {       (yyval.Object) = c_metaDeclare(scope, c_declaratorName((yyvsp[-3].Object)), M_ATTRIBUTE);}
#line 2243 "idl_base.c" /* yacc.c:1646  */
    break;

  case 49:
#line 436 "idl_base.y" /* yacc.c:1646  */
    {
        annotationScope = c_metaObject((yyvsp[0].Object));
}
#line 2251 "idl_base.c" /* yacc.c:1646  */
    break;

  case 51:
#line 442 "idl_base.y" /* yacc.c:1646  */
    {annotationScope = NULL;}
#line 2257 "idl_base.c" /* yacc.c:1646  */
    break;

  case 52:
#line 443 "idl_base.y" /* yacc.c:1646  */
    {annotationScope = NULL;}
#line 2263 "idl_base.c" /* yacc.c:1646  */
    break;

  case 57:
#line 458 "idl_base.y" /* yacc.c:1646  */
    {
        c_metaObject o;
        if(!(o = c_metaResolve(annotationScope, (yyvsp[-2].String)))) {
                yyerror("Unresolved annotation parameter");
                YYABORT;
        }

        if(o->definedIn != annotationScope) {
                yyerror("Resolved parameter identifier not in annotation scope");
                YYABORT;
        }
}
#line 2280 "idl_base.c" /* yacc.c:1646  */
    break;

  case 87:
#line 544 "idl_base.y" /* yacc.c:1646  */
    { (yyval.Object) = NULL; }
#line 2286 "idl_base.c" /* yacc.c:1646  */
    break;

  case 99:
#line 572 "idl_base.y" /* yacc.c:1646  */
    { (yyval.Object) = NULL; }
#line 2292 "idl_base.c" /* yacc.c:1646  */
    break;

  case 100:
#line 574 "idl_base.y" /* yacc.c:1646  */
    { (yyval.Object) = NULL; }
#line 2298 "idl_base.c" /* yacc.c:1646  */
    break;

  case 124:
#line 638 "idl_base.y" /* yacc.c:1646  */
    {
          (yyval.Object) = declareUnsupportedType(scope, (yyvsp[0].String), IDL_UNSUP_VALUETYPE);
        }
#line 2306 "idl_base.c" /* yacc.c:1646  */
    break;

  case 125:
#line 642 "idl_base.y" /* yacc.c:1646  */
    {
          (yyval.Object) = declareUnsupportedType(scope, (yyvsp[0].String), IDL_UNSUP_VALUETYPE);
        }
#line 2314 "idl_base.c" /* yacc.c:1646  */
    break;

  case 126:
#line 649 "idl_base.y" /* yacc.c:1646  */
    {
          (yyval.Object) = declareUnsupportedType(scope, (yyvsp[-1].String), IDL_UNSUP_VALUETYPE);
        }
#line 2322 "idl_base.c" /* yacc.c:1646  */
    break;

  case 127:
#line 656 "idl_base.y" /* yacc.c:1646  */
    { (yyval.Object) = declareUnsupportedType(scope, (yyvsp[-3].String), IDL_UNSUP_VALUETYPE); }
#line 2328 "idl_base.c" /* yacc.c:1646  */
    break;

  case 128:
#line 658 "idl_base.y" /* yacc.c:1646  */
    { (yyval.Object) = declareUnsupportedType(scope, (yyvsp[-4].String), IDL_UNSUP_VALUETYPE); }
#line 2334 "idl_base.c" /* yacc.c:1646  */
    break;

  case 133:
#line 673 "idl_base.y" /* yacc.c:1646  */
    { (yyval.Object) = declareUnsupportedType(scope, (yyvsp[-1].String), IDL_UNSUP_VALUETYPE); }
#line 2340 "idl_base.c" /* yacc.c:1646  */
    break;

  case 134:
#line 675 "idl_base.y" /* yacc.c:1646  */
    { (yyval.Object) = declareUnsupportedType(scope, (yyvsp[0].String), IDL_UNSUP_VALUETYPE); }
#line 2346 "idl_base.c" /* yacc.c:1646  */
    break;

  case 135:
#line 677 "idl_base.y" /* yacc.c:1646  */
    { (yyval.Object) = declareUnsupportedType(scope, (yyvsp[-1].String), IDL_UNSUP_VALUETYPE); }
#line 2352 "idl_base.c" /* yacc.c:1646  */
    break;

  case 136:
#line 679 "idl_base.y" /* yacc.c:1646  */
    { (yyval.Object) = declareUnsupportedType(scope, (yyvsp[0].String), IDL_UNSUP_VALUETYPE); }
#line 2358 "idl_base.c" /* yacc.c:1646  */
    break;

  case 143:
#line 696 "idl_base.y" /* yacc.c:1646  */
    { (yyval.List) = NULL; }
#line 2364 "idl_base.c" /* yacc.c:1646  */
    break;

  case 144:
#line 698 "idl_base.y" /* yacc.c:1646  */
    { (yyval.List) = NULL; }
#line 2370 "idl_base.c" /* yacc.c:1646  */
    break;

  case 146:
#line 707 "idl_base.y" /* yacc.c:1646  */
    { (yyval.List) = NULL; }
#line 2376 "idl_base.c" /* yacc.c:1646  */
    break;

  case 147:
#line 709 "idl_base.y" /* yacc.c:1646  */
    { (yyval.List) = NULL; }
#line 2382 "idl_base.c" /* yacc.c:1646  */
    break;

  case 165:
#line 758 "idl_base.y" /* yacc.c:1646  */
    { scope = scope->definedIn; }
#line 2388 "idl_base.c" /* yacc.c:1646  */
    break;

  case 166:
#line 763 "idl_base.y" /* yacc.c:1646  */
    {
          if (idl_checkModuleDefinition (scope, (yyvsp[-1].String),yyerror)) {
            YYABORT;
          }
          scope = c_metaObject(declareMetaObject(scope,(yyvsp[-1].String),M_MODULE));
          idl_fileMapAssociation(idl_fileMapDefGet(), c_object(scope), file_name);
        }
#line 2400 "idl_base.c" /* yacc.c:1646  */
    break;

  case 169:
#line 779 "idl_base.y" /* yacc.c:1646  */
    { scope = scope->definedIn; }
#line 2406 "idl_base.c" /* yacc.c:1646  */
    break;

  case 170:
#line 784 "idl_base.y" /* yacc.c:1646  */
    {
          if (idl_checkInterfaceDefinition(scope, (yyvsp[0].String), yyerror)) {
            YYABORT;
          }
          scope = c_metaObject(declareMetaObject(scope,(yyvsp[0].String),M_INTERFACE));
          idl_fileMapAssociation(idl_fileMapDefGet(), c_object(scope), file_name);
        }
#line 2418 "idl_base.c" /* yacc.c:1646  */
    break;

  case 171:
#line 792 "idl_base.y" /* yacc.c:1646  */
    {
          if (idl_checkInterfaceDefinition(scope, (yyvsp[-2].String), yyerror)) {
            YYABORT;
          }
          scope = c_metaObject(declareMetaObject(scope,(yyvsp[-2].String),M_INTERFACE));
          idl_fileMapAssociation(idl_fileMapDefGet(), c_object(scope), file_name);
        }
#line 2430 "idl_base.c" /* yacc.c:1646  */
    break;

  case 172:
#line 800 "idl_base.y" /* yacc.c:1646  */
    {
          if (idl_checkInterfaceDefinition(scope, (yyvsp[0].String), yyerror)) {
            YYABORT;
          }
          scope = c_metaObject(declareMetaObject(scope,(yyvsp[0].String),M_INTERFACE));
          idl_fileMapAssociation(idl_fileMapDefGet(), c_object(scope), file_name);
        }
#line 2442 "idl_base.c" /* yacc.c:1646  */
    break;

  case 173:
#line 808 "idl_base.y" /* yacc.c:1646  */
    {
          if (idl_checkInterfaceDefinition(scope, (yyvsp[-2].String), yyerror)) {
            YYABORT;
          }
          scope = c_metaObject(declareMetaObject(scope,(yyvsp[-2].String),M_INTERFACE));
          idl_fileMapAssociation(idl_fileMapDefGet(), c_object(scope), file_name);
        }
#line 2454 "idl_base.c" /* yacc.c:1646  */
    break;

  case 174:
#line 819 "idl_base.y" /* yacc.c:1646  */
    {
          if (idl_checkInterfaceDefinition(scope, (yyvsp[0].String), yyerror)) {
              YYABORT;
          }
          idl_fileMapAssociation(idl_fileMapDefGet(),
                                 c_object(declareMetaObject(scope,(yyvsp[0].String),M_INTERFACE)),
                                 file_name);
        }
#line 2467 "idl_base.c" /* yacc.c:1646  */
    break;

  case 175:
#line 828 "idl_base.y" /* yacc.c:1646  */
    {
          if (idl_checkInterfaceDefinition(scope, (yyvsp[0].String), yyerror)) {
              YYABORT;
          }
          idl_fileMapAssociation(idl_fileMapDefGet(),
                                 c_object(declareMetaObject(scope,(yyvsp[0].String),M_INTERFACE)),
                                 file_name);
        }
#line 2480 "idl_base.c" /* yacc.c:1646  */
    break;

  case 189:
#line 864 "idl_base.y" /* yacc.c:1646  */
    { (yyval.List) = c_iterNew((yyvsp[0].Object)); }
#line 2486 "idl_base.c" /* yacc.c:1646  */
    break;

  case 190:
#line 866 "idl_base.y" /* yacc.c:1646  */
    { (yyval.List) = c_iterInsert((yyvsp[0].List),(yyvsp[-2].Object)); }
#line 2492 "idl_base.c" /* yacc.c:1646  */
    break;

  case 191:
#line 871 "idl_base.y" /* yacc.c:1646  */
    {
          idl_checkReferencedIdentifier(scope,(yyvsp[0].String),yyerror);
          (yyval.Object) = (void *)metaResolve(scope,(yyvsp[0].String));
          if ((yyval.Object) == NULL) {
            yyerror("Undefined identifier");
            YYABORT;
          }
        }
#line 2505 "idl_base.c" /* yacc.c:1646  */
    break;

  case 192:
#line 880 "idl_base.y" /* yacc.c:1646  */
    {
          idl_checkReferencedIdentifier(topLevel,(yyvsp[0].String),yyerror);
          (yyval.Object) = (void *)metaResolve(topLevel,(yyvsp[0].String));
          if ((yyval.Object) == NULL) {
            yyerror("Undefined identifier");
            YYABORT;
          }
        }
#line 2518 "idl_base.c" /* yacc.c:1646  */
    break;

  case 193:
#line 889 "idl_base.y" /* yacc.c:1646  */
    {
          idl_checkReferencedIdentifier((yyvsp[-2].Object),(yyvsp[0].String),yyerror);
          (yyval.Object) = (void *)metaResolve((yyvsp[-2].Object),(yyvsp[0].String));
          if ((yyval.Object) == NULL) {
            yyerror("Undefined identifier");
            YYABORT;
          }
        }
#line 2531 "idl_base.c" /* yacc.c:1646  */
    break;

  case 194:
#line 901 "idl_base.y" /* yacc.c:1646  */
    {
          if (idl_checkConstantDefinition(scope,(yyvsp[-2].String),yyerror)) {
                YYABORT;
          }
          object = declareMetaObject(scope,(yyvsp[-2].String),M_CONSTANT);
          c_constant(object)->type = (yyvsp[-3].Object);
          c_constant(object)->operand = (yyvsp[0].Object);
          metaFinalize(object);
          idl_checkConstantDeclaration(scope,(yyvsp[-3].Object),object,yyerror);
          idl_fileMapAssociation(idl_fileMapDefGet(), object, file_name);
        }
#line 2547 "idl_base.c" /* yacc.c:1646  */
    break;

  case 207:
#line 934 "idl_base.y" /* yacc.c:1646  */
    {
          (yyval.Object) = c_metaDefine(scope,M_EXPRESSION);
          c_expression((yyval.Object))->kind = E_OR;
          c_expression((yyval.Object))->operands = c_arrayNew(P_OBJECT,2);
          c_expression((yyval.Object))->operands[0] = (yyvsp[-2].Object);
          c_expression((yyval.Object))->operands[1] = (yyvsp[0].Object);
          idl_fileMapAssociation(idl_fileMapDefGet(), (yyval.Object), file_name);
        }
#line 2560 "idl_base.c" /* yacc.c:1646  */
    break;

  case 209:
#line 947 "idl_base.y" /* yacc.c:1646  */
    {
          (yyval.Object) = c_metaDefine(scope,M_EXPRESSION);
          c_expression((yyval.Object))->kind = E_XOR;
          c_expression((yyval.Object))->operands = c_arrayNew(P_OBJECT,2);
          c_expression((yyval.Object))->operands[0] = (yyvsp[-2].Object);
          c_expression((yyval.Object))->operands[1] = (yyvsp[0].Object);
          idl_fileMapAssociation(idl_fileMapDefGet(), (yyval.Object), file_name);
        }
#line 2573 "idl_base.c" /* yacc.c:1646  */
    break;

  case 211:
#line 960 "idl_base.y" /* yacc.c:1646  */
    {
          (yyval.Object) = c_metaDefine(scope,M_EXPRESSION);
          c_expression((yyval.Object))->kind = E_AND;
          c_expression((yyval.Object))->operands = c_arrayNew(P_OBJECT,2);
          c_expression((yyval.Object))->operands[0] = (yyvsp[-2].Object);
          c_expression((yyval.Object))->operands[1] = (yyvsp[0].Object);
          idl_fileMapAssociation(idl_fileMapDefGet(), (yyval.Object), file_name);
        }
#line 2586 "idl_base.c" /* yacc.c:1646  */
    break;

  case 213:
#line 973 "idl_base.y" /* yacc.c:1646  */
    {
        (yyval.Object) = c_metaDefine(scope,M_EXPRESSION);
        c_expression((yyval.Object))->kind = E_SHIFTRIGHT;
        c_expression((yyval.Object))->operands = c_arrayNew(P_OBJECT,2);
        c_expression((yyval.Object))->operands[0] = (yyvsp[-2].Object);
        c_expression((yyval.Object))->operands[1] = (yyvsp[0].Object);
        idl_fileMapAssociation(idl_fileMapDefGet(), (yyval.Object), file_name);
      }
#line 2599 "idl_base.c" /* yacc.c:1646  */
    break;

  case 214:
#line 982 "idl_base.y" /* yacc.c:1646  */
    {
        (yyval.Object) = c_metaDefine(scope,M_EXPRESSION);
        c_expression((yyval.Object))->kind = E_SHIFTLEFT;
        c_expression((yyval.Object))->operands = c_arrayNew(P_OBJECT,2);
        c_expression((yyval.Object))->operands[0] = (yyvsp[-2].Object);
        c_expression((yyval.Object))->operands[1] = (yyvsp[0].Object);
        idl_fileMapAssociation(idl_fileMapDefGet(), (yyval.Object), file_name);
      }
#line 2612 "idl_base.c" /* yacc.c:1646  */
    break;

  case 216:
#line 995 "idl_base.y" /* yacc.c:1646  */
    {
        (yyval.Object) = c_metaDefine(scope,M_EXPRESSION);
        c_expression((yyval.Object))->kind = E_PLUS;
        c_expression((yyval.Object))->operands = c_arrayNew(P_OBJECT,2);
        c_expression((yyval.Object))->operands[0] = (yyvsp[-2].Object);
        c_expression((yyval.Object))->operands[1] = (yyvsp[0].Object);
        idl_fileMapAssociation(idl_fileMapDefGet(), (yyval.Object), file_name);
      }
#line 2625 "idl_base.c" /* yacc.c:1646  */
    break;

  case 217:
#line 1004 "idl_base.y" /* yacc.c:1646  */
    {
        (yyval.Object) = c_metaDefine(scope,M_EXPRESSION);
        c_expression((yyval.Object))->kind = E_MINUS;
        c_expression((yyval.Object))->operands = c_arrayNew(P_OBJECT,2);
        c_expression((yyval.Object))->operands[0] = (yyvsp[-2].Object);
        c_expression((yyval.Object))->operands[1] = (yyvsp[0].Object);
        idl_fileMapAssociation(idl_fileMapDefGet(), (yyval.Object), file_name);
      }
#line 2638 "idl_base.c" /* yacc.c:1646  */
    break;

  case 219:
#line 1017 "idl_base.y" /* yacc.c:1646  */
    {
          (yyval.Object) = c_metaDefine(scope,M_EXPRESSION);
          c_expression((yyval.Object))->kind = E_MUL;
          c_expression((yyval.Object))->operands = c_arrayNew(P_OBJECT,2);
          c_expression((yyval.Object))->operands[0] = (yyvsp[-2].Object);
          c_expression((yyval.Object))->operands[1] = (yyvsp[0].Object);
          idl_fileMapAssociation(idl_fileMapDefGet(), (yyval.Object), file_name);
        }
#line 2651 "idl_base.c" /* yacc.c:1646  */
    break;

  case 220:
#line 1026 "idl_base.y" /* yacc.c:1646  */
    {
          (yyval.Object) = c_metaDefine(scope,M_EXPRESSION);
          c_expression((yyval.Object))->kind = E_DIV;
          c_expression((yyval.Object))->operands = c_arrayNew(P_OBJECT,2);
          c_expression((yyval.Object))->operands[0] = (yyvsp[-2].Object);
          c_expression((yyval.Object))->operands[1] = (yyvsp[0].Object);
          idl_fileMapAssociation(idl_fileMapDefGet(), (yyval.Object), file_name);
        }
#line 2664 "idl_base.c" /* yacc.c:1646  */
    break;

  case 221:
#line 1035 "idl_base.y" /* yacc.c:1646  */
    {
          (yyval.Object) = c_metaDefine(scope,M_EXPRESSION);
          c_expression((yyval.Object))->kind = E_MOD;
          c_expression((yyval.Object))->operands = c_arrayNew(P_OBJECT,2);
          c_expression((yyval.Object))->operands[0] = (yyvsp[-2].Object);
          c_expression((yyval.Object))->operands[1] = (yyvsp[0].Object);
          idl_fileMapAssociation(idl_fileMapDefGet(), (yyval.Object), file_name);
        }
#line 2677 "idl_base.c" /* yacc.c:1646  */
    break;

  case 222:
#line 1047 "idl_base.y" /* yacc.c:1646  */
    {
          (yyval.Object) = c_metaDefine(scope,M_EXPRESSION);
          c_expression((yyval.Object))->kind = E_MINUS;
          c_expression((yyval.Object))->operands = c_arrayNew(P_OBJECT,1);
          c_expression((yyval.Object))->operands[0] = (yyvsp[0].Object);
          idl_fileMapAssociation(idl_fileMapDefGet(), (yyval.Object), file_name);
        }
#line 2689 "idl_base.c" /* yacc.c:1646  */
    break;

  case 223:
#line 1055 "idl_base.y" /* yacc.c:1646  */
    {
          (yyval.Object) = c_metaDefine(scope,M_EXPRESSION);
          c_expression((yyval.Object))->kind = E_PLUS;
          c_expression((yyval.Object))->operands = c_arrayNew(P_OBJECT,1);
          c_expression((yyval.Object))->operands[0] = (yyvsp[0].Object);
          idl_fileMapAssociation(idl_fileMapDefGet(), (yyval.Object), file_name);
        }
#line 2701 "idl_base.c" /* yacc.c:1646  */
    break;

  case 224:
#line 1063 "idl_base.y" /* yacc.c:1646  */
    {
          (yyval.Object) = c_metaDefine(scope,M_EXPRESSION);
          c_expression((yyval.Object))->kind = E_NOT;
          c_expression((yyval.Object))->operands = c_arrayNew(P_OBJECT,1);
          c_expression((yyval.Object))->operands[0] = (yyvsp[0].Object);
          idl_fileMapAssociation(idl_fileMapDefGet(), (yyval.Object), file_name);
        }
#line 2713 "idl_base.c" /* yacc.c:1646  */
    break;

  case 228:
#line 1077 "idl_base.y" /* yacc.c:1646  */
    { (yyval.Object) = (yyvsp[-1].Object); }
#line 2719 "idl_base.c" /* yacc.c:1646  */
    break;

  case 229:
#line 1082 "idl_base.y" /* yacc.c:1646  */
    {
          (yyval.Object) = c_metaDefine(scope,M_LITERAL);
          c_literal((yyval.Object))->value = c_longlongValue((yyvsp[0].Integer));
          idl_fileMapAssociation(idl_fileMapDefGet(), (yyval.Object), file_name);
        }
#line 2729 "idl_base.c" /* yacc.c:1646  */
    break;

  case 230:
#line 1088 "idl_base.y" /* yacc.c:1646  */
    {
          (yyval.Object) = c_metaDefine(scope,M_LITERAL);
          c_literal((yyval.Object))->value = c_stringValue((yyvsp[0].String));
          idl_fileMapAssociation(idl_fileMapDefGet(), (yyval.Object), file_name);
        }
#line 2739 "idl_base.c" /* yacc.c:1646  */
    break;

  case 231:
#line 1094 "idl_base.y" /* yacc.c:1646  */
    { support_warning("wstring literal"); (yyval.Object) = NULL; }
#line 2745 "idl_base.c" /* yacc.c:1646  */
    break;

  case 232:
#line 1096 "idl_base.y" /* yacc.c:1646  */
    {
          (yyval.Object) = c_metaDefine(scope,M_LITERAL);
          c_literal((yyval.Object))->value = c_charValue((yyvsp[0].Char));
          idl_fileMapAssociation(idl_fileMapDefGet(), (yyval.Object), file_name);
        }
#line 2755 "idl_base.c" /* yacc.c:1646  */
    break;

  case 233:
#line 1102 "idl_base.y" /* yacc.c:1646  */
    { support_warning("wchar type"); (yyval.Object) = NULL; }
#line 2761 "idl_base.c" /* yacc.c:1646  */
    break;

  case 234:
#line 1104 "idl_base.y" /* yacc.c:1646  */
    {
          (yyval.Object) = c_metaDefine(scope,M_LITERAL);
          /* Fixed point not yet supported, translate to string */
          c_literal((yyval.Object))->value = c_stringValue((yyvsp[0].Fixed));
          idl_fileMapAssociation(idl_fileMapDefGet(), (yyval.Object), file_name);
        }
#line 2772 "idl_base.c" /* yacc.c:1646  */
    break;

  case 235:
#line 1111 "idl_base.y" /* yacc.c:1646  */
    {
          (yyval.Object) = c_metaDefine(scope,M_LITERAL);
          c_literal((yyval.Object))->value = c_doubleValue((yyvsp[0].Float));
          idl_fileMapAssociation(idl_fileMapDefGet(), (yyval.Object), file_name);
        }
#line 2782 "idl_base.c" /* yacc.c:1646  */
    break;

  case 236:
#line 1117 "idl_base.y" /* yacc.c:1646  */
    {
          (yyval.Object) = c_metaDefine(scope,M_LITERAL);
          c_literal((yyval.Object))->value = c_boolValue(TRUE);
          idl_fileMapAssociation(idl_fileMapDefGet(), (yyval.Object), file_name);
        }
#line 2792 "idl_base.c" /* yacc.c:1646  */
    break;

  case 237:
#line 1123 "idl_base.y" /* yacc.c:1646  */
    {
          (yyval.Object) = c_metaDefine(scope,M_LITERAL);
          c_literal((yyval.Object))->value = c_boolValue(FALSE);
          idl_fileMapAssociation(idl_fileMapDefGet(), (yyval.Object), file_name);
        }
#line 2802 "idl_base.c" /* yacc.c:1646  */
    break;

  case 238:
#line 1132 "idl_base.y" /* yacc.c:1646  */
    {
          if (idl_checkPositiveInt(scope,(yyvsp[0].Object),yyerror)) {
            YYABORT;
          }
          (yyval.Value) = c_operandValue((yyvsp[0].Object));
        }
#line 2813 "idl_base.c" /* yacc.c:1646  */
    break;

  case 239:
#line 1142 "idl_base.y" /* yacc.c:1646  */
    {
          c_iter typeDefs;
          if (idl_checkTypeReference (scope,(yyvsp[-1].Object),yyerror)) {
            YYABORT;
          }
          if (checkTypeDefs(scope,(yyvsp[0].List))) {
              YYABORT;
          }
          typeDefs = c_bindTypes(scope,(yyvsp[0].List),(yyvsp[-1].Object));
          declareTypeDefs(scope, typeDefs);
        }
#line 2829 "idl_base.c" /* yacc.c:1646  */
    break;

  case 240:
#line 1153 "idl_base.y" /* yacc.c:1646  */
    { }
#line 2835 "idl_base.c" /* yacc.c:1646  */
    break;

  case 241:
#line 1154 "idl_base.y" /* yacc.c:1646  */
    { }
#line 2841 "idl_base.c" /* yacc.c:1646  */
    break;

  case 242:
#line 1155 "idl_base.y" /* yacc.c:1646  */
    { }
#line 2847 "idl_base.c" /* yacc.c:1646  */
    break;

  case 245:
#line 1162 "idl_base.y" /* yacc.c:1646  */
    {
        idl_fileMapAssociation(idl_fileMapDefGet(), c_baseObject(declareMetaObject(scope, (yyvsp[0].String), M_STRUCTURE)), file_name);
      }
#line 2855 "idl_base.c" /* yacc.c:1646  */
    break;

  case 246:
#line 1166 "idl_base.y" /* yacc.c:1646  */
    {
        idl_fileMapAssociation(idl_fileMapDefGet(), c_baseObject(declareMetaObject(scope, (yyvsp[0].String), M_STRUCTURE)), file_name);
      }
#line 2863 "idl_base.c" /* yacc.c:1646  */
    break;

  case 273:
#line 1220 "idl_base.y" /* yacc.c:1646  */
    { (yyval.List) = c_iterNew((yyvsp[0].Object)); }
#line 2869 "idl_base.c" /* yacc.c:1646  */
    break;

  case 274:
#line 1222 "idl_base.y" /* yacc.c:1646  */
    { (yyval.List) = c_iterInsert((yyvsp[0].List),(yyvsp[-2].Object)); }
#line 2875 "idl_base.c" /* yacc.c:1646  */
    break;

  case 277:
#line 1236 "idl_base.y" /* yacc.c:1646  */
    { (yyval.Object) = c_declaratorNew((yyvsp[0].String),NULL); }
#line 2881 "idl_base.c" /* yacc.c:1646  */
    break;

  case 279:
#line 1245 "idl_base.y" /* yacc.c:1646  */
    { (yyval.Object) = metaResolve(scope, "c_float"); }
#line 2887 "idl_base.c" /* yacc.c:1646  */
    break;

  case 280:
#line 1247 "idl_base.y" /* yacc.c:1646  */
    { (yyval.Object) = metaResolve(scope, "c_double"); }
#line 2893 "idl_base.c" /* yacc.c:1646  */
    break;

  case 281:
#line 1249 "idl_base.y" /* yacc.c:1646  */
    { (yyval.Object) = idl_unsupportedTypeGetMetadata(IDL_UNSUP_LONGDOUBLE); }
#line 2899 "idl_base.c" /* yacc.c:1646  */
    break;

  case 287:
#line 1265 "idl_base.y" /* yacc.c:1646  */
    { (yyval.Object) = metaResolve(scope, "c_short"); }
#line 2905 "idl_base.c" /* yacc.c:1646  */
    break;

  case 288:
#line 1270 "idl_base.y" /* yacc.c:1646  */
    { (yyval.Object) = metaResolve(scope, "c_long"); }
#line 2911 "idl_base.c" /* yacc.c:1646  */
    break;

  case 289:
#line 1275 "idl_base.y" /* yacc.c:1646  */
    { (yyval.Object) = metaResolve(scope, "c_longlong"); }
#line 2917 "idl_base.c" /* yacc.c:1646  */
    break;

  case 293:
#line 1286 "idl_base.y" /* yacc.c:1646  */
    { (yyval.Object) = metaResolve(scope, "c_ushort"); }
#line 2923 "idl_base.c" /* yacc.c:1646  */
    break;

  case 294:
#line 1291 "idl_base.y" /* yacc.c:1646  */
    { (yyval.Object) = metaResolve(scope, "c_ulong"); }
#line 2929 "idl_base.c" /* yacc.c:1646  */
    break;

  case 295:
#line 1296 "idl_base.y" /* yacc.c:1646  */
    { (yyval.Object) = metaResolve(scope, "c_ulonglong"); }
#line 2935 "idl_base.c" /* yacc.c:1646  */
    break;

  case 296:
#line 1301 "idl_base.y" /* yacc.c:1646  */
    { (yyval.Object) = metaResolve(scope, "c_char"); }
#line 2941 "idl_base.c" /* yacc.c:1646  */
    break;

  case 297:
#line 1306 "idl_base.y" /* yacc.c:1646  */
    { (yyval.Object) = idl_unsupportedTypeGetMetadata(IDL_UNSUP_WCHAR); }
#line 2947 "idl_base.c" /* yacc.c:1646  */
    break;

  case 298:
#line 1311 "idl_base.y" /* yacc.c:1646  */
    { (yyval.Object) = metaResolve(scope, "c_bool"); }
#line 2953 "idl_base.c" /* yacc.c:1646  */
    break;

  case 299:
#line 1316 "idl_base.y" /* yacc.c:1646  */
    { (yyval.Object) = metaResolve(scope, "c_octet"); }
#line 2959 "idl_base.c" /* yacc.c:1646  */
    break;

  case 300:
#line 1321 "idl_base.y" /* yacc.c:1646  */
    { (yyval.Object) = idl_unsupportedTypeGetMetadata(IDL_UNSUP_ANY); }
#line 2965 "idl_base.c" /* yacc.c:1646  */
    break;

  case 301:
#line 1326 "idl_base.y" /* yacc.c:1646  */
    { (yyval.Object) = idl_unsupportedTypeGetMetadata(IDL_UNSUP_OBJECT); }
#line 2971 "idl_base.c" /* yacc.c:1646  */
    break;

  case 302:
#line 1331 "idl_base.y" /* yacc.c:1646  */
    { (yyval.Object) = idl_unsupportedTypeGetMetadata(IDL_UNSUP_VALUEBASE); }
#line 2977 "idl_base.c" /* yacc.c:1646  */
    break;

  case 303:
#line 1336 "idl_base.y" /* yacc.c:1646  */
    { (yyval.Object) = idl_unsupportedTypeGetMetadata(IDL_UNSUP_FIXED); }
#line 2983 "idl_base.c" /* yacc.c:1646  */
    break;

  case 304:
#line 1341 "idl_base.y" /* yacc.c:1646  */
    {
          if (idl_checkStructDeclaratorDefinition(scope,(yyvsp[-1].List),yyerror)) {
            YYABORT;
          }
          c_structure(scope)->members = c_metaArray(scope,(yyvsp[-1].List),M_MEMBER);
          if (metaFinalize(scope) == S_ILLEGALRECURSION) {
              yyerror("Illegal recursion in struct");
              YYABORT;
          }
          (yyval.Object) = scope;
          scope = scope->definedIn;
          idl_fileMapAssociation(idl_fileMapDefGet(), (yyval.Object), file_name);
        }
#line 3001 "idl_base.c" /* yacc.c:1646  */
    break;

  case 306:
#line 1358 "idl_base.y" /* yacc.c:1646  */
    {(yyval.List) = (yyvsp[0].List);}
#line 3007 "idl_base.c" /* yacc.c:1646  */
    break;

  case 307:
#line 1363 "idl_base.y" /* yacc.c:1646  */
    {
          if (idl_checkTypeDefinition(scope,(yyvsp[0].String),yyerror)) {
            YYABORT;
          }
          scope = declareMetaObject(scope,(yyvsp[0].String),M_STRUCTURE);
        }
#line 3018 "idl_base.c" /* yacc.c:1646  */
    break;

  case 308:
#line 1370 "idl_base.y" /* yacc.c:1646  */
    {
                yyerror("Structure inheritance will be supported in a future version.");
                YYABORT;
        }
#line 3027 "idl_base.c" /* yacc.c:1646  */
    break;

  case 310:
#line 1378 "idl_base.y" /* yacc.c:1646  */
    { (yyval.List) = c_iterConcat((yyvsp[-1].List),(yyvsp[0].List)); }
#line 3033 "idl_base.c" /* yacc.c:1646  */
    break;

  case 314:
#line 1388 "idl_base.y" /* yacc.c:1646  */
    {(yyval.List) = (yyvsp[0].List);}
#line 3039 "idl_base.c" /* yacc.c:1646  */
    break;

  case 315:
#line 1393 "idl_base.y" /* yacc.c:1646  */
    {
                if(c_isFinal((yyvsp[-2].Object))) {
                        (yyval.List) = c_bindMembers(scope,(yyvsp[-1].List),(yyvsp[-2].Object));
                        declareMembers(scope, (yyval.List));
                }else {
                        yyerror("Illegal use of incomplete type (see 3.11.2.3 in OMG IDL specification).");
                        YYABORT;
                }
        }
#line 3053 "idl_base.c" /* yacc.c:1646  */
    break;

  case 317:
#line 1406 "idl_base.y" /* yacc.c:1646  */
    {(yyval.Object) = (yyvsp[0].Object);}
#line 3059 "idl_base.c" /* yacc.c:1646  */
    break;

  case 318:
#line 1411 "idl_base.y" /* yacc.c:1646  */
    {
          if (idl_checkUnionDeclaratorDefinition(scope,(yyvsp[-4].Object),(yyvsp[-1].List),yyerror)) {
            YYABORT;
          }
          idl_checkUnionCaseDefinition(scope,(yyvsp[-4].Object),(yyvsp[-1].List),yyerror);
          c_union(scope)->cases = c_metaArray(scope,(yyvsp[-1].List),M_UNIONCASE);
          if (metaFinalize(scope) == S_ILLEGALRECURSION) {
             yyerror("Illegal recursion in union");
             YYABORT;
          }
          (yyval.Object) = scope;
          scope = scope->definedIn;
          idl_fileMapAssociation(idl_fileMapDefGet(), (yyval.Object), file_name);
        }
#line 3078 "idl_base.c" /* yacc.c:1646  */
    break;

  case 319:
#line 1429 "idl_base.y" /* yacc.c:1646  */
    {
          if (idl_checkTypeDefinition (scope,(yyvsp[0].String),yyerror)) {
            YYABORT;
          }
          scope = declareMetaObject(scope,(yyvsp[0].String),M_UNION);
        }
#line 3089 "idl_base.c" /* yacc.c:1646  */
    break;

  case 320:
#line 1439 "idl_base.y" /* yacc.c:1646  */
    { c_union(scope)->switchType = (yyvsp[0].Object); }
#line 3095 "idl_base.c" /* yacc.c:1646  */
    break;

  case 321:
#line 1441 "idl_base.y" /* yacc.c:1646  */
    { c_union(scope)->switchType = (yyvsp[0].Object); }
#line 3101 "idl_base.c" /* yacc.c:1646  */
    break;

  case 322:
#line 1443 "idl_base.y" /* yacc.c:1646  */
    { c_union(scope)->switchType = (yyvsp[0].Object); }
#line 3107 "idl_base.c" /* yacc.c:1646  */
    break;

  case 323:
#line 1445 "idl_base.y" /* yacc.c:1646  */
    { c_union(scope)->switchType = (yyvsp[0].Object); }
#line 3113 "idl_base.c" /* yacc.c:1646  */
    break;

  case 324:
#line 1447 "idl_base.y" /* yacc.c:1646  */
    { c_union(scope)->switchType = (yyvsp[0].Object); }
#line 3119 "idl_base.c" /* yacc.c:1646  */
    break;

  case 325:
#line 1449 "idl_base.y" /* yacc.c:1646  */
    { c_union(scope)->switchType = (yyvsp[0].Object); }
#line 3125 "idl_base.c" /* yacc.c:1646  */
    break;

  case 326:
#line 1451 "idl_base.y" /* yacc.c:1646  */
    { c_union(scope)->switchType = (yyvsp[0].Object); }
#line 3131 "idl_base.c" /* yacc.c:1646  */
    break;

  case 328:
#line 1456 "idl_base.y" /* yacc.c:1646  */
    { (yyval.Object) = (yyvsp[0].Object); }
#line 3137 "idl_base.c" /* yacc.c:1646  */
    break;

  case 331:
#line 1466 "idl_base.y" /* yacc.c:1646  */
    { (yyval.List) = c_iterNew((yyvsp[0].Object)); }
#line 3143 "idl_base.c" /* yacc.c:1646  */
    break;

  case 332:
#line 1468 "idl_base.y" /* yacc.c:1646  */
    { (yyval.List) = c_iterAppend((yyvsp[-1].List),(yyvsp[0].Object)); }
#line 3149 "idl_base.c" /* yacc.c:1646  */
    break;

  case 335:
#line 1494 "idl_base.y" /* yacc.c:1646  */
    {
          (yyval.Object) = c_unionCaseNew(scope, c_declaratorName((yyvsp[-1].Object)), c_declaratorType((yyvsp[-1].Object),(yyvsp[-2].Object)), (yyvsp[-3].List));
          declareType(scope, (yyvsp[-2].Object));
        }
#line 3158 "idl_base.c" /* yacc.c:1646  */
    break;

  case 336:
#line 1502 "idl_base.y" /* yacc.c:1646  */
    { (yyval.List) = c_iterNew((yyvsp[0].Object)); }
#line 3164 "idl_base.c" /* yacc.c:1646  */
    break;

  case 337:
#line 1504 "idl_base.y" /* yacc.c:1646  */
    { (yyval.List) = c_iterInsert((yyvsp[0].List),(yyvsp[-1].Object)); }
#line 3170 "idl_base.c" /* yacc.c:1646  */
    break;

  case 338:
#line 1509 "idl_base.y" /* yacc.c:1646  */
    {(yyval.Object) = scope; scope = c_metaObject(c_union(scope)->switchType)->definedIn;}
#line 3176 "idl_base.c" /* yacc.c:1646  */
    break;

  case 339:
#line 1511 "idl_base.y" /* yacc.c:1646  */
    {scope = (yyvsp[-1].Object);}
#line 3182 "idl_base.c" /* yacc.c:1646  */
    break;

  case 340:
#line 1513 "idl_base.y" /* yacc.c:1646  */
    {
          idl_checkConstantOperand (scope, c_union(scope)->switchType,c_operand((yyvsp[-2].Object)),yyerror);
          (yyval.Object) = c_operandValue((yyvsp[-2].Object));
        }
#line 3191 "idl_base.c" /* yacc.c:1646  */
    break;

  case 341:
#line 1518 "idl_base.y" /* yacc.c:1646  */
    { (yyval.Object) = NULL; }
#line 3197 "idl_base.c" /* yacc.c:1646  */
    break;

  case 342:
#line 1531 "idl_base.y" /* yacc.c:1646  */
    {
          if (idl_checkTypeDefinition (scope,(yyvsp[-3].String),yyerror)) {
            YYABORT;
          }
          (yyval.Object) = declareMetaObject(scope,(yyvsp[-3].String),M_ENUMERATION);
          c_enumeration((yyval.Object))->elements = c_metaArray(scope,(yyvsp[-1].List),M_CONSTANT);
          metaFinalize((yyval.Object));
          idl_fileMapAssociation(idl_fileMapDefGet(), (yyval.Object), file_name);
        }
#line 3211 "idl_base.c" /* yacc.c:1646  */
    break;

  case 345:
#line 1549 "idl_base.y" /* yacc.c:1646  */
    { (yyval.List) = c_iterNew((yyvsp[0].Object)); }
#line 3217 "idl_base.c" /* yacc.c:1646  */
    break;

  case 346:
#line 1551 "idl_base.y" /* yacc.c:1646  */
    {
          (yyval.List) = c_iterInsert((yyvsp[0].List),(yyvsp[-2].Object));
          if (idl_checkEnumerationElementCount((yyval.List),yyerror)) {
            YYABORT;
          }
        }
#line 3228 "idl_base.c" /* yacc.c:1646  */
    break;

  case 347:
#line 1558 "idl_base.y" /* yacc.c:1646  */
    {
          (yyval.List) = c_iterInsert((yyvsp[0].List),(yyvsp[-3].Object));
          if (idl_checkEnumerationElementCount((yyval.List),yyerror)) {
            YYABORT;
          }
        }
#line 3239 "idl_base.c" /* yacc.c:1646  */
    break;

  case 349:
#line 1568 "idl_base.y" /* yacc.c:1646  */
    {(yyval.Object) = (yyvsp[0].Object);}
#line 3245 "idl_base.c" /* yacc.c:1646  */
    break;

  case 350:
#line 1573 "idl_base.y" /* yacc.c:1646  */
    {
          if (idl_checkEnumerationElementDefinition (scope,(yyvsp[0].String),yyerror)) {
            YYABORT;
          }
          (yyval.Object) = (void *)declareMetaObject(scope,(yyvsp[0].String),M_CONSTANT);
          idl_fileMapAssociation(idl_fileMapDefGet(), (yyval.Object), file_name);
        }
#line 3257 "idl_base.c" /* yacc.c:1646  */
    break;

  case 351:
#line 1584 "idl_base.y" /* yacc.c:1646  */
    {
          (yyval.Object) = c_metaDefine(getCollectionScope(scope,(yyvsp[-3].Object)),M_COLLECTION);
          c_collectionType((yyval.Object))->kind = OSPL_C_SEQUENCE;
          c_collectionType((yyval.Object))->maxSize = (c_long)(yyvsp[-1].Value)->value.is.LongLong;
          c_collectionType((yyval.Object))->subType = (yyvsp[-3].Object);
          metaFinalize((yyval.Object));
          (yyval.Object) = declareCollection(scope, c_collectionType((yyval.Object)));
          idl_fileMapAssociation(idl_fileMapDefGet(), (yyval.Object), file_name);
        }
#line 3271 "idl_base.c" /* yacc.c:1646  */
    break;

  case 352:
#line 1594 "idl_base.y" /* yacc.c:1646  */
    {
          (yyval.Object) = c_metaDefine(getCollectionScope(scope,(yyvsp[-1].Object)),M_COLLECTION);
          c_collectionType((yyval.Object))->kind = OSPL_C_SEQUENCE;
          c_collectionType((yyval.Object))->maxSize = 0;
          c_collectionType((yyval.Object))->subType = (yyvsp[-1].Object);
          metaFinalize((yyval.Object));
          (yyval.Object) = declareCollection(scope, c_collectionType((yyval.Object)));
          idl_fileMapAssociation(idl_fileMapDefGet(), (yyval.Object), file_name);
        }
#line 3285 "idl_base.c" /* yacc.c:1646  */
    break;

  case 353:
#line 1607 "idl_base.y" /* yacc.c:1646  */
    {
        yyerror("Maptypes will be supported in a future version.");
        YYABORT;
}
#line 3294 "idl_base.c" /* yacc.c:1646  */
    break;

  case 354:
#line 1612 "idl_base.y" /* yacc.c:1646  */
    {
        yyerror("Maptypes will be supported in a future version.");
        YYABORT;
}
#line 3303 "idl_base.c" /* yacc.c:1646  */
    break;

  case 358:
#line 1624 "idl_base.y" /* yacc.c:1646  */
    {(yyval.Object) = (yyvsp[0].Object);}
#line 3309 "idl_base.c" /* yacc.c:1646  */
    break;

  case 359:
#line 1629 "idl_base.y" /* yacc.c:1646  */
    {
          (yyval.Object) = c_metaDefine(scope,M_COLLECTION);
          c_collectionType((yyval.Object))->kind = OSPL_C_STRING;
          c_collectionType((yyval.Object))->maxSize = (c_long)(yyvsp[-1].Value)->value.is.LongLong;
          c_collectionType((yyval.Object))->subType = (c_type)metaResolve(scope,"c_char");
          metaFinalize((yyval.Object));
          (yyval.Object) = declareCollection(scope, c_collectionType((yyval.Object)));
          idl_fileMapAssociation(idl_fileMapDefGet(), (yyval.Object), file_name);
        }
#line 3323 "idl_base.c" /* yacc.c:1646  */
    break;

  case 360:
#line 1639 "idl_base.y" /* yacc.c:1646  */
    { (yyval.Object) = P_STRING; }
#line 3329 "idl_base.c" /* yacc.c:1646  */
    break;

  case 361:
#line 1644 "idl_base.y" /* yacc.c:1646  */
    { (yyval.Object) = idl_unsupportedTypeGetMetadata(IDL_UNSUP_WSTRING); }
#line 3335 "idl_base.c" /* yacc.c:1646  */
    break;

  case 362:
#line 1646 "idl_base.y" /* yacc.c:1646  */
    { (yyval.Object) = idl_unsupportedTypeGetMetadata(IDL_UNSUP_WSTRING); }
#line 3341 "idl_base.c" /* yacc.c:1646  */
    break;

  case 363:
#line 1651 "idl_base.y" /* yacc.c:1646  */
    { (yyval.Object) = NULL; }
#line 3347 "idl_base.c" /* yacc.c:1646  */
    break;

  case 364:
#line 1656 "idl_base.y" /* yacc.c:1646  */
    { (yyval.Object) = c_declaratorNew((yyvsp[-1].String),(yyvsp[0].List)); }
#line 3353 "idl_base.c" /* yacc.c:1646  */
    break;

  case 368:
#line 1666 "idl_base.y" /* yacc.c:1646  */
    {(yyval.String) = (yyvsp[0].String);}
#line 3359 "idl_base.c" /* yacc.c:1646  */
    break;

  case 369:
#line 1671 "idl_base.y" /* yacc.c:1646  */
    { (yyval.List) = c_iterNew((yyvsp[0].Value)); }
#line 3365 "idl_base.c" /* yacc.c:1646  */
    break;

  case 370:
#line 1673 "idl_base.y" /* yacc.c:1646  */
    { (yyval.List) = c_iterAppend((yyvsp[0].List),(yyvsp[-1].Value)); }
#line 3371 "idl_base.c" /* yacc.c:1646  */
    break;

  case 371:
#line 1678 "idl_base.y" /* yacc.c:1646  */
    { (yyval.Value) = (yyvsp[-1].Value); }
#line 3377 "idl_base.c" /* yacc.c:1646  */
    break;

  case 375:
#line 1712 "idl_base.y" /* yacc.c:1646  */
    {}
#line 3383 "idl_base.c" /* yacc.c:1646  */
    break;

  case 378:
#line 1718 "idl_base.y" /* yacc.c:1646  */
    {}
#line 3389 "idl_base.c" /* yacc.c:1646  */
    break;

  case 379:
#line 1719 "idl_base.y" /* yacc.c:1646  */
    {}
#line 3395 "idl_base.c" /* yacc.c:1646  */
    break;

  case 382:
#line 1728 "idl_base.y" /* yacc.c:1646  */
    {}
#line 3401 "idl_base.c" /* yacc.c:1646  */
    break;

  case 390:
#line 1748 "idl_base.y" /* yacc.c:1646  */
    {}
#line 3407 "idl_base.c" /* yacc.c:1646  */
    break;

  case 391:
#line 1749 "idl_base.y" /* yacc.c:1646  */
    {}
#line 3413 "idl_base.c" /* yacc.c:1646  */
    break;

  case 393:
#line 1761 "idl_base.y" /* yacc.c:1646  */
    {
          if (idl_checkExceptionDefinition (scope, (yyvsp[-3].String), yyerror)) {
            YYABORT;
          }
          object = declareMetaObject(scope,(yyvsp[-3].String),M_EXCEPTION);
          c_structure(object)->members = c_metaArray(scope,(yyvsp[-1].List),M_MEMBER);
          metaFinalize(object);
          idl_fileMapAssociation(idl_fileMapDefGet(), object, file_name);
        }
#line 3427 "idl_base.c" /* yacc.c:1646  */
    break;

  case 394:
#line 1774 "idl_base.y" /* yacc.c:1646  */
    { (yyval.List) = NULL; }
#line 3433 "idl_base.c" /* yacc.c:1646  */
    break;

  case 395:
#line 1776 "idl_base.y" /* yacc.c:1646  */
    { (yyval.List) = (yyvsp[0].List); }
#line 3439 "idl_base.c" /* yacc.c:1646  */
    break;

  case 399:
#line 1801 "idl_base.y" /* yacc.c:1646  */
    { (yyval.Object) = (yyvsp[0].Object); }
#line 3445 "idl_base.c" /* yacc.c:1646  */
    break;

  case 400:
#line 1803 "idl_base.y" /* yacc.c:1646  */
    { (yyval.Object) = P_VOID; }
#line 3451 "idl_base.c" /* yacc.c:1646  */
    break;

  case 401:
#line 1808 "idl_base.y" /* yacc.c:1646  */
    { (yyval.Object) = (yyvsp[-1].List); }
#line 3457 "idl_base.c" /* yacc.c:1646  */
    break;

  case 402:
#line 1810 "idl_base.y" /* yacc.c:1646  */
    { (yyval.Object) = NULL; }
#line 3463 "idl_base.c" /* yacc.c:1646  */
    break;

  case 403:
#line 1815 "idl_base.y" /* yacc.c:1646  */
    { (yyval.List) = c_iterNew((yyvsp[0].Object)); }
#line 3469 "idl_base.c" /* yacc.c:1646  */
    break;

  case 404:
#line 1817 "idl_base.y" /* yacc.c:1646  */
    { (yyval.List) = c_iterInsert((yyvsp[0].List),(yyvsp[-2].Object)); }
#line 3475 "idl_base.c" /* yacc.c:1646  */
    break;

  case 405:
#line 1822 "idl_base.y" /* yacc.c:1646  */
    {
          (yyval.Object) = c_metaDefine(scope,M_PARAMETER);
          c_specifier((yyval.Object))->name = (yyvsp[0].Object);
          c_specifier((yyval.Object))->type = (yyvsp[-1].Object);
          c_parameter((yyval.Object))->mode = (yyvsp[-2].Mode);
          declareType(scope, (yyvsp[-1].Object));
          idl_fileMapAssociation(idl_fileMapDefGet(), (yyval.Object), file_name);
        }
#line 3488 "idl_base.c" /* yacc.c:1646  */
    break;

  case 406:
#line 1834 "idl_base.y" /* yacc.c:1646  */
    { (yyval.Mode) = D_IN; }
#line 3494 "idl_base.c" /* yacc.c:1646  */
    break;

  case 407:
#line 1836 "idl_base.y" /* yacc.c:1646  */
    { (yyval.Mode) = D_OUT; }
#line 3500 "idl_base.c" /* yacc.c:1646  */
    break;

  case 408:
#line 1838 "idl_base.y" /* yacc.c:1646  */
    { (yyval.Mode) = D_INOUT; }
#line 3506 "idl_base.c" /* yacc.c:1646  */
    break;

  case 411:
#line 1847 "idl_base.y" /* yacc.c:1646  */
    { (yyval.List) = c_iterNew((yyvsp[0].Object)); }
#line 3512 "idl_base.c" /* yacc.c:1646  */
    break;

  case 412:
#line 1849 "idl_base.y" /* yacc.c:1646  */
    { (yyval.List) = c_iterInsert((yyvsp[0].List),(yyvsp[-2].Object)); }
#line 3518 "idl_base.c" /* yacc.c:1646  */
    break;

  case 415:
#line 1858 "idl_base.y" /* yacc.c:1646  */
    { (yyval.Object) = (yyvsp[0].String); }
#line 3524 "idl_base.c" /* yacc.c:1646  */
    break;

  case 416:
#line 1863 "idl_base.y" /* yacc.c:1646  */
    { (yyval.List) = c_iterNew((yyvsp[0].Object)); }
#line 3530 "idl_base.c" /* yacc.c:1646  */
    break;

  case 417:
#line 1865 "idl_base.y" /* yacc.c:1646  */
    { (yyval.List) = c_iterInsert((yyvsp[0].List),(yyvsp[-2].Object)); }
#line 3536 "idl_base.c" /* yacc.c:1646  */
    break;


#line 3540 "idl_base.c" /* yacc.c:1646  */
      default: break;
    }
  /* User semantic actions sometimes alter yychar, and that requires
     that yytoken be updated with the new translation.  We take the
     approach of translating immediately before every use of yytoken.
     One alternative is translating here after every semantic action,
     but that translation would be missed if the semantic action invokes
     YYABORT, YYACCEPT, or YYERROR immediately after altering yychar or
     if it invokes YYBACKUP.  In the case of YYABORT or YYACCEPT, an
     incorrect destructor might then be invoked immediately.  In the
     case of YYERROR or YYBACKUP, subsequent parser actions might lead
     to an incorrect destructor call or verbose syntax error message
     before the lookahead is translated.  */
  YY_SYMBOL_PRINT ("-> $$ =", yyr1[yyn], &yyval, &yyloc);

  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);

  *++yyvsp = yyval;

  /* Now 'shift' the result of the reduction.  Determine what state
     that goes to, based on the state we popped back to and the rule
     number reduced by.  */

  yyn = yyr1[yyn];

  yystate = yypgoto[yyn - YYNTOKENS] + *yyssp;
  if (0 <= yystate && yystate <= YYLAST && yycheck[yystate] == *yyssp)
    yystate = yytable[yystate];
  else
    yystate = yydefgoto[yyn - YYNTOKENS];

  goto yynewstate;


/*--------------------------------------.
| yyerrlab -- here on detecting error.  |
`--------------------------------------*/
yyerrlab:
  /* Make sure we have latest lookahead translation.  See comments at
     user semantic actions for why this is necessary.  */
  yytoken = yychar == YYEMPTY ? YYEMPTY : YYTRANSLATE (yychar);

  /* If not already recovering from an error, report this error.  */
  if (!yyerrstatus)
    {
      ++yynerrs;
#if ! YYERROR_VERBOSE
      yyerror (YY_("syntax error"));
#else
# define YYSYNTAX_ERROR yysyntax_error (&yymsg_alloc, &yymsg, \
                                        yyssp, yytoken)
      {
        char const *yymsgp = YY_("syntax error");
        int yysyntax_error_status;
        yysyntax_error_status = YYSYNTAX_ERROR;
        if (yysyntax_error_status == 0)
          yymsgp = yymsg;
        else if (yysyntax_error_status == 1)
          {
            if (yymsg != yymsgbuf)
              YYSTACK_FREE (yymsg);
            yymsg = (char *) YYSTACK_ALLOC (yymsg_alloc);
            if (!yymsg)
              {
                yymsg = yymsgbuf;
                yymsg_alloc = sizeof yymsgbuf;
                yysyntax_error_status = 2;
              }
            else
              {
                yysyntax_error_status = YYSYNTAX_ERROR;
                yymsgp = yymsg;
              }
          }
        yyerror (yymsgp);
        if (yysyntax_error_status == 2)
          goto yyexhaustedlab;
      }
# undef YYSYNTAX_ERROR
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

  /* Do not reclaim the symbols of the rule whose action triggered
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
  yyerrstatus = 3;      /* Each real token shifted decrements this.  */

  for (;;)
    {
      yyn = yypact[yystate];
      if (!yypact_value_is_default (yyn))
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

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END


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

#if !defined yyoverflow || YYERROR_VERBOSE
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
    {
      /* Make sure we have latest lookahead translation.  See comments at
         user semantic actions for why this is necessary.  */
      yytoken = YYTRANSLATE (yychar);
      yydestruct ("Cleanup: discarding lookahead",
                  yytoken, &yylval);
    }
  /* Do not reclaim the symbols of the rule whose action triggered
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
  return yyresult;
}
#line 1868 "idl_base.y" /* yacc.c:1906  */

#include "idl_base.h"
#include <os_stdlib.h>

/* option was: noyywrap */
/*
int yywrap()
{
  return (1);
}
*/

int
yyerror ( char *text )
{
    printf("*** DDS error in file %s: %s near the token %s (line: %d, column: %d)\n",
           file_name, text, yytext, parser_line, parser_column);
    parser_error = 1;
    return -1;
}

void
idl_idlinit(c_module schema)
{
    idl_fileMap fileMap;
    idl_keyDef keyDef;
    idl_catsDef catsDef;
    idl_stacDef stacDef;
    idl_streamsDef streamsDef;

    topLevel = schema;
    scope = topLevel;
    fileMap = idl_fileMapNew();
    idl_fileMapDefSet(fileMap);
    keyDef = idl_keyDefNew();
    idl_keyDefDefSet(keyDef);
    catsDef = idl_catsDefNew();
    idl_catsDefDefSet(catsDef);
    stacDef = idl_stacDefNew();
    idl_stacDefDefSet(stacDef);
    streamsDef = idl_streamsDefNew();
    idl_streamsDefDefSet(streamsDef);
}

int
idl_idlparse(
    const char *fname)
{
    char *name = NULL;

    parser_line = 1;
    parser_column = 0;
    parser_state = 0;
    parser_error = 0;

    name = os_strdup(fname);

    if (name == NULL) {
        printf("IDL parser error: out of memory:");
        parser_error = 1;
        return parser_error;
    }

    yyin = fopen(name, "r");

    if (yyin == NULL) {
        printf("IDL parser error: opening file %s\n", name);
        parser_error = 1;
        return parser_error;
    }
    preprocess(yyin, name);

    yyparse();

    fclose(yyin);

    os_free(name);

    return parser_error;
}

static void support_warning(char *text)
{
    printf("DDS warning not supported yet: %s at line %d column %d, parsing is stopped\n",
           text, parser_line, parser_column);
    exit (1);
}

static c_metaObject
getCollectionScope(
    c_metaObject current,
    c_metaObject subType)
{
    OS_UNUSED_ARG(subType);
    return current;
}

static c_collectionType
declareCollection(
    c_metaObject scope,
    c_collectionType c)
{
    c_string name;
    c_char *collName;
    c_metaObject found;

    name = c_metaName(c_metaObject(c));
    if (name == NULL) {
        collName = getScopedTypeName(scope, c_type(c), "::", C_SCOPE_ALWAYS);
        found = c_metaBind(scope, collName, c_metaObject(c));
        return c_collectionType(found);
    } else {
        c_free(name);
        return NULL;
    }
}

static void
declareIfArray(
    c_metaObject scope,
    c_type type)
{
    if (c_baseObject(type)->kind == M_COLLECTION) {
        declareIfArray(scope, c_collectionType(type)->subType);
        declareCollection(scope, c_collectionType(type));
    }
}

static void
declareMemberIfArray(
    void *o,
    c_iterActionArg arg)
{
    c_member member;
    c_metaObject scope;

    member = c_member(o);
    scope = c_metaObject(arg);

    declareIfArray(scope, c_specifier(member)->type);
}

static void
declareMembers(
    c_metaObject scope,
    c_iter members)
{
    /* Members is a special case, iter has to be reused afterwards */
    /* Therefore use walk instead of take                          */
    c_iterWalk(members, declareMemberIfArray, (void *)scope);
}

static int
checkTypeDefs(
    c_metaObject scope,
    c_iter declarations)
{
    c_ulong i;
    c_declarator d;
    int errId = 0;

    for (i = 0; i < c_iterLength(declarations); i++) {
                d = c_iterObject(declarations, i);
                errId += idl_checkTypeDefinition (scope, c_declaratorName(d), yyerror);
    }
    return errId;
}

static void
declareTypeDefs(
    c_metaObject scope,
    c_iter typeDefs)
{
    c_typeDef typeDef;

    typeDef = c_iterTakeFirst(typeDefs);
    while (typeDef != NULL) {
                idl_fileMapAssociation(idl_fileMapDefGet(), c_object(typeDef), file_name);
        declareIfArray(scope, typeDef->alias);
        c_free(typeDef);
        typeDef = c_iterTakeFirst(typeDefs);
    }
}

#if 0
static void
declareAttributes(
    c_metaObject scope,
    c_iter attributes)
{
    c_attribute attribute;

    attribute = c_iterTakeFirst(attributes);
    while (attribute != NULL) {
        declareIfArray(scope, c_property(attribute)->type);
        c_free(attribute);
        attribute = c_iterTakeFirst(attributes);
    }
}
#endif

static void
declareType(
    c_metaObject scope,
    c_type type)
{
    declareIfArray(scope, type);
}

static c_metaObject
declareMetaObject(
    c_metaObject scope,
    c_char *name,
    c_metaKind kind)
{
    c_metaObject found;

    found = c_metaObject(c_metaDeclare(scope,name,kind));
    if (found == NULL) {
        found = c_metaResolve(scope, name);
        if(c_isFinal(found)) {
                printf("***DDS parse error %s redeclared at line: %d\n", name, parser_line);
                exit(-1);
            }
    }
    return found;
}

static c_metaObject
declareUnsupportedType(
    c_metaObject scope,
    char *name,
    enum idl_unsupported_type unsupportedType)
{
    c_metaObject o;
#if 0
    os_time delay = {30,0};
printf("Attach debugger\n");
fflush(stdout);
os_nanoSleep(delay);
#endif

    o = declareMetaObject(scope, name, M_TYPEDEF);
    if (o) {
        c_typeDef(o)->alias = idl_unsupportedTypeGetMetadata(unsupportedType);
        assert(c_typeDef(o)->alias != NULL);
        metaFinalize(o);
    }
    return o;
}


static c_metaObject
metaResolve(
    c_metaObject scope,
    const char *name)
{
    c_metaObject found;
    found = c_metaResolve(scope,name);
    if (found == NULL) {
        printf("***DDS parse error %s undefined at line: %d (searching from scope '%s')\n", name, parser_line, scope->name);
        exit(-1);
    }
    return found;
}

static c_metaObject
metaResolveAnnotation(
        c_metaObject scope,
        const char *name)
{
    c_metaObject found;
    found = c_metaResolve(scope,name);
    if (found == NULL) {
        /* Lookup _ospl_internal scope */
        if(!scopeInternal) {
            scopeInternal = c_metaResolve(topLevel, "_ospl_internal");
                if(!scopeInternal) {
                printf("***DDS parse error ::_ospl_internal undefined at line: %d\n", parser_line);
                        exit(-1);
                }
        }

        /* Lookup object in <_ospl_internal> scope */
        found = c_metaResolve(scopeInternal, name);
        if(!found) {
            printf("***DDS parse error %s undefined at line: %d (searching from scope '%s')\n", name, parser_line, scope->name);
                exit(-1);
        }
    }
    return found;
}

static c_result
metaFinalize(
    c_metaObject o)
{
    c_result result;
    c_string name;

    result = c_metaFinalize(o);
    name = c_metaName(o);
    switch(result) {
    case S_ACCEPTED:
    break;
    case S_REDECLARED:
        printf("***DDS parse error %s redeclared at line: %d\n", name, parser_line);
        exit(-1);
    break;
    case S_ILLEGALOBJECT:
        printf("***DDS parse error %s illegal object at line: %d\n", name, parser_line);
        exit(-1);
    break;
    case S_REDEFINED:
        printf("***DDS parse error %s redefined at line: %d\n", name, parser_line);
        exit(-1);
    break;
    case S_ILLEGALRECURSION:
        printf("***DDS parse error %s illegal recursion at line: %d\n", name, parser_line);
        exit(-1);
    break;
    default:
        printf("***DDS internal parser error occured at line: %d\n", parser_line);
        exit(-1);
    break;
    }
    return result;
}

static c_char *
getCollKindName(
    /* QAC EXPECT 3673; No solution to the message here, but no problem either */
    const c_collectionType c)
{
    c_char *result;

#define _CASE_(k) case k: result = os_strdup(#k + 5 /* OSPL_ prefix */); break
    switch(c->kind) {
    _CASE_(OSPL_C_ARRAY);
    _CASE_(OSPL_C_SEQUENCE);
    _CASE_(OSPL_C_SET);
    _CASE_(OSPL_C_LIST);
    _CASE_(OSPL_C_BAG);
    _CASE_(OSPL_C_DICTIONARY);
    _CASE_(OSPL_C_STRING);
    _CASE_(OSPL_C_WSTRING);
    default:
        /* QAC EXPECT 3416; No side effects in this case */
        assert(FALSE);
        result = os_strdup("C_UNDEFINED");
    break;
    }
#undef _CASE_

    return result;
}

static c_char *
getCollAnonName(
    const c_metaObject scope,
    const c_collectionType c,
    const char *separator)
{
    c_char *result;
    c_char *kind;
    c_char *subTypeName;
    size_t resultSize;
    OS_UNUSED_ARG(scope);

    OS_UNUSED_ARG(scope);

    kind = getCollKindName(c);
    subTypeName = getScopedTypeName(c_metaObject(c->subType)->definedIn, c->subType,
                                      separator, C_SCOPE_ALWAYS);
    resultSize = strlen(kind) + strlen(subTypeName) + 32;
    /* QAC EXPECT 5007; will not use wrapper */
    result = (c_char *)os_malloc(resultSize);
    if (c->kind == OSPL_C_STRING) {
        if (c->maxSize > 0) {
            snprintf(result, resultSize, "%s<%u>", kind, c->maxSize);
        } else {
            snprintf(result, resultSize, "%s", kind);
        }
    } else {
        if (c->maxSize > 0) {
            snprintf(result, resultSize, "%s<%s,%u>", kind, subTypeName, c->maxSize);
        } else {
            snprintf(result, resultSize, "%s<%s>", kind, subTypeName);
        }
    }

    return result;
}

static c_char *
getScopedTypeName(
    const c_metaObject scope,
    const c_type type,
    const char *separator,
    c_scopeWhen scopeWhen)
{
    c_char *typeName, *result, *tmp;
    size_t tmpSize;
    c_metaObject scop = scope;
    OS_UNUSED_ARG(scopeWhen);

    OS_UNUSED_ARG(scopeWhen);

    typeName = c_metaName(c_metaObject(type));
    if (!typeName && (c_baseObject(type)->kind == M_COLLECTION)) {
        typeName = getCollAnonName(scope, c_collectionType(type),
                                     separator);
        result = typeName;
    } else {
        result = os_strdup(typeName);
        /* QAC EXPECT 3416; No side effects in this case, expected behaviour */
        while ((scop != NULL) && (c_metaName(scop) != NULL)) {
            tmpSize = strlen(c_metaName(scop)) + strlen(separator) + strlen(result) + 1;
            /* QAC EXPECT 5007; will not use wrapper */
            tmp = os_malloc (tmpSize);
            snprintf (tmp, tmpSize, "%s%s%s",  c_metaName(scop), separator, result);
            /* QAC EXPECT 5007; will not use wrapper */
            os_free (result);
            result = tmp;
            scop = scop->definedIn;
        }
    }
    return result;
}
