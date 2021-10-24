/* A Bison parser, made by GNU Bison 3.5.1.  */

/* Bison implementation for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2015, 2018-2020 Free Software Foundation,
   Inc.

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

/* Undocumented macros, especially those whose name start with YY_,
   are private implementation details.  Do not rely on them.  */

/* Identify Bison output.  */
#define YYBISON 1

/* Bison version.  */
#define YYBISON_VERSION "3.5.1"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1




/* First part of user prologue.  */
#line 16 "/home/jnstaursky/Desktop/Personal-Projects/coronium/parse/slghparse.y"

#include "slgh_compile.hh"

#define YYERROR_VERBOSE

  extern SleighCompile *slgh;
  extern int4 actionon;
  extern FILE *yyin;
  extern int yydebug;
  extern int yylex(void);
  extern int yyerror(const char *str );

#line 83 "/home/jnstaursky/Desktop/Personal-Projects/coronium/src/slghparse.cc"

# ifndef YY_CAST
#  ifdef __cplusplus
#   define YY_CAST(Type, Val) static_cast<Type> (Val)
#   define YY_REINTERPRET_CAST(Type, Val) reinterpret_cast<Type> (Val)
#  else
#   define YY_CAST(Type, Val) ((Type) (Val))
#   define YY_REINTERPRET_CAST(Type, Val) ((Type) (Val))
#  endif
# endif
# ifndef YY_NULLPTR
#  if defined __cplusplus
#   if 201103L <= __cplusplus
#    define YY_NULLPTR nullptr
#   else
#    define YY_NULLPTR 0
#   endif
#  else
#   define YY_NULLPTR ((void*)0)
#  endif
# endif

/* Enabling verbose error messages.  */
#ifdef YYERROR_VERBOSE
# undef YYERROR_VERBOSE
# define YYERROR_VERBOSE 1
#else
# define YYERROR_VERBOSE 0
#endif

/* Use api.header.include to #include this header
   instead of duplicating it here.  */
#ifndef YY_YY_HOME_JNSTAURSKY_DESKTOP_PERSONAL_PROJECTS_CORONIUM_SRC_SLGHPARSE_TAB_HH_INCLUDED
# define YY_YY_HOME_JNSTAURSKY_DESKTOP_PERSONAL_PROJECTS_CORONIUM_SRC_SLGHPARSE_TAB_HH_INCLUDED
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
    OP_BOOL_OR = 258,
    OP_BOOL_AND = 259,
    OP_BOOL_XOR = 260,
    OP_OR = 261,
    OP_XOR = 262,
    OP_AND = 263,
    OP_EQUAL = 264,
    OP_NOTEQUAL = 265,
    OP_FEQUAL = 266,
    OP_FNOTEQUAL = 267,
    OP_GREATEQUAL = 268,
    OP_LESSEQUAL = 269,
    OP_SLESS = 270,
    OP_SGREATEQUAL = 271,
    OP_SLESSEQUAL = 272,
    OP_SGREAT = 273,
    OP_FLESS = 274,
    OP_FGREAT = 275,
    OP_FLESSEQUAL = 276,
    OP_FGREATEQUAL = 277,
    OP_LEFT = 278,
    OP_RIGHT = 279,
    OP_SRIGHT = 280,
    OP_FADD = 281,
    OP_FSUB = 282,
    OP_SDIV = 283,
    OP_SREM = 284,
    OP_FMULT = 285,
    OP_FDIV = 286,
    OP_ZEXT = 287,
    OP_CARRY = 288,
    OP_BORROW = 289,
    OP_SEXT = 290,
    OP_SCARRY = 291,
    OP_SBORROW = 292,
    OP_NAN = 293,
    OP_ABS = 294,
    OP_SQRT = 295,
    OP_CEIL = 296,
    OP_FLOOR = 297,
    OP_ROUND = 298,
    OP_INT2FLOAT = 299,
    OP_FLOAT2FLOAT = 300,
    OP_TRUNC = 301,
    OP_CPOOLREF = 302,
    OP_NEW = 303,
    OP_POPCOUNT = 304,
    BADINTEGER = 305,
    GOTO_KEY = 306,
    CALL_KEY = 307,
    RETURN_KEY = 308,
    IF_KEY = 309,
    DEFINE_KEY = 310,
    ATTACH_KEY = 311,
    MACRO_KEY = 312,
    SPACE_KEY = 313,
    TYPE_KEY = 314,
    RAM_KEY = 315,
    DEFAULT_KEY = 316,
    REGISTER_KEY = 317,
    ENDIAN_KEY = 318,
    WITH_KEY = 319,
    ALIGN_KEY = 320,
    OP_UNIMPL = 321,
    TOKEN_KEY = 322,
    SIGNED_KEY = 323,
    NOFLOW_KEY = 324,
    HEX_KEY = 325,
    DEC_KEY = 326,
    BIG_KEY = 327,
    LITTLE_KEY = 328,
    SIZE_KEY = 329,
    WORDSIZE_KEY = 330,
    OFFSET_KEY = 331,
    NAMES_KEY = 332,
    VALUES_KEY = 333,
    VARIABLES_KEY = 334,
    PCODEOP_KEY = 335,
    IS_KEY = 336,
    LOCAL_KEY = 337,
    DELAYSLOT_KEY = 338,
    CROSSBUILD_KEY = 339,
    EXPORT_KEY = 340,
    BUILD_KEY = 341,
    CONTEXT_KEY = 342,
    ELLIPSIS_KEY = 343,
    GLOBALSET_KEY = 344,
    BITRANGE_KEY = 345,
    CHAR = 346,
    INTEGER = 347,
    INTB = 348,
    STRING = 349,
    SYMBOLSTRING = 350,
    SPACESYM = 351,
    SECTIONSYM = 352,
    TOKENSYM = 353,
    USEROPSYM = 354,
    VALUESYM = 355,
    VALUEMAPSYM = 356,
    CONTEXTSYM = 357,
    NAMESYM = 358,
    VARSYM = 359,
    BITSYM = 360,
    SPECSYM = 361,
    VARLISTSYM = 362,
    OPERANDSYM = 363,
    STARTSYM = 364,
    ENDSYM = 365,
    MACROSYM = 366,
    LABELSYM = 367,
    SUBTABLESYM = 368
  };
#endif

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
union YYSTYPE
{
#line 29 "/home/jnstaursky/Desktop/Personal-Projects/coronium/parse/slghparse.y"

  char ch;
  uintb *i;
  intb *big;
  string *str;
  vector<string> *strlist;
  vector<intb> *biglist;
  vector<ExprTree *> *param;
  SpaceQuality *spacequal;
  FieldQuality *fieldqual;
  StarQuality *starqual;
  VarnodeTpl *varnode;
  ExprTree *tree;
  vector<OpTpl *> *stmt;
  ConstructTpl *sem;
  SectionVector *sectionstart;
  Constructor *construct;
  PatternEquation *pateq;
  PatternExpression *patexp;

  vector<SleighSymbol *> *symlist;
  vector<ContextChange *> *contop;
  SleighSymbol *anysym;
  SpaceSymbol *spacesym;
  SectionSymbol *sectionsym;
  TokenSymbol *tokensym;
  UserOpSymbol *useropsym;
  MacroSymbol *macrosym;
  LabelSymbol *labelsym;
  SubtableSymbol *subtablesym;
  StartSymbol *startsym;
  EndSymbol *endsym;
  OperandSymbol *operandsym;
  VarnodeListSymbol *varlistsym;
  VarnodeSymbol *varsym;
  BitrangeSymbol *bitsym;
  NameSymbol *namesym;
  ValueSymbol *valuesym;
  ValueMapSymbol *valuemapsym;
  ContextSymbol *contextsym;
  FamilySymbol *famsym;
  SpecificSymbol *specsym;

#line 293 "/home/jnstaursky/Desktop/Personal-Projects/coronium/src/slghparse.cc"

};
typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_HOME_JNSTAURSKY_DESKTOP_PERSONAL_PROJECTS_CORONIUM_SRC_SLGHPARSE_TAB_HH_INCLUDED  */



#ifdef short
# undef short
#endif

/* On compilers that do not define __PTRDIFF_MAX__ etc., make sure
   <limits.h> and (if available) <stdint.h> are included
   so that the code can choose integer types of a good width.  */

#ifndef __PTRDIFF_MAX__
# include <limits.h> /* INFRINGES ON USER NAME SPACE */
# if defined __STDC_VERSION__ && 199901 <= __STDC_VERSION__
#  include <stdint.h> /* INFRINGES ON USER NAME SPACE */
#  define YY_STDINT_H
# endif
#endif

/* Narrow types that promote to a signed type and that can represent a
   signed or unsigned integer of at least N bits.  In tables they can
   save space and decrease cache pressure.  Promoting to a signed type
   helps avoid bugs in integer arithmetic.  */

#ifdef __INT_LEAST8_MAX__
typedef __INT_LEAST8_TYPE__ yytype_int8;
#elif defined YY_STDINT_H
typedef int_least8_t yytype_int8;
#else
typedef signed char yytype_int8;
#endif

#ifdef __INT_LEAST16_MAX__
typedef __INT_LEAST16_TYPE__ yytype_int16;
#elif defined YY_STDINT_H
typedef int_least16_t yytype_int16;
#else
typedef short yytype_int16;
#endif

#if defined __UINT_LEAST8_MAX__ && __UINT_LEAST8_MAX__ <= __INT_MAX__
typedef __UINT_LEAST8_TYPE__ yytype_uint8;
#elif (!defined __UINT_LEAST8_MAX__ && defined YY_STDINT_H \
       && UINT_LEAST8_MAX <= INT_MAX)
typedef uint_least8_t yytype_uint8;
#elif !defined __UINT_LEAST8_MAX__ && UCHAR_MAX <= INT_MAX
typedef unsigned char yytype_uint8;
#else
typedef short yytype_uint8;
#endif

#if defined __UINT_LEAST16_MAX__ && __UINT_LEAST16_MAX__ <= __INT_MAX__
typedef __UINT_LEAST16_TYPE__ yytype_uint16;
#elif (!defined __UINT_LEAST16_MAX__ && defined YY_STDINT_H \
       && UINT_LEAST16_MAX <= INT_MAX)
typedef uint_least16_t yytype_uint16;
#elif !defined __UINT_LEAST16_MAX__ && USHRT_MAX <= INT_MAX
typedef unsigned short yytype_uint16;
#else
typedef int yytype_uint16;
#endif

#ifndef YYPTRDIFF_T
# if defined __PTRDIFF_TYPE__ && defined __PTRDIFF_MAX__
#  define YYPTRDIFF_T __PTRDIFF_TYPE__
#  define YYPTRDIFF_MAXIMUM __PTRDIFF_MAX__
# elif defined PTRDIFF_MAX
#  ifndef ptrdiff_t
#   include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  endif
#  define YYPTRDIFF_T ptrdiff_t
#  define YYPTRDIFF_MAXIMUM PTRDIFF_MAX
# else
#  define YYPTRDIFF_T long
#  define YYPTRDIFF_MAXIMUM LONG_MAX
# endif
#endif

#ifndef YYSIZE_T
# ifdef __SIZE_TYPE__
#  define YYSIZE_T __SIZE_TYPE__
# elif defined size_t
#  define YYSIZE_T size_t
# elif defined __STDC_VERSION__ && 199901 <= __STDC_VERSION__
#  include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  define YYSIZE_T size_t
# else
#  define YYSIZE_T unsigned
# endif
#endif

#define YYSIZE_MAXIMUM                                  \
  YY_CAST (YYPTRDIFF_T,                                 \
           (YYPTRDIFF_MAXIMUM < YY_CAST (YYSIZE_T, -1)  \
            ? YYPTRDIFF_MAXIMUM                         \
            : YY_CAST (YYSIZE_T, -1)))

#define YYSIZEOF(X) YY_CAST (YYPTRDIFF_T, sizeof (X))

/* Stored state numbers (used for stacks). */
typedef yytype_int16 yy_state_t;

/* State numbers in computations.  */
typedef int yy_state_fast_t;

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

#ifndef YY_ATTRIBUTE_PURE
# if defined __GNUC__ && 2 < __GNUC__ + (96 <= __GNUC_MINOR__)
#  define YY_ATTRIBUTE_PURE __attribute__ ((__pure__))
# else
#  define YY_ATTRIBUTE_PURE
# endif
#endif

#ifndef YY_ATTRIBUTE_UNUSED
# if defined __GNUC__ && 2 < __GNUC__ + (7 <= __GNUC_MINOR__)
#  define YY_ATTRIBUTE_UNUSED __attribute__ ((__unused__))
# else
#  define YY_ATTRIBUTE_UNUSED
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YYUSE(E) ((void) (E))
#else
# define YYUSE(E) /* empty */
#endif

#if defined __GNUC__ && ! defined __ICC && 407 <= __GNUC__ * 100 + __GNUC_MINOR__
/* Suppress an incorrect diagnostic about yylval being uninitialized.  */
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN                            \
    _Pragma ("GCC diagnostic push")                                     \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")              \
    _Pragma ("GCC diagnostic ignored \"-Wmaybe-uninitialized\"")
# define YY_IGNORE_MAYBE_UNINITIALIZED_END      \
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

#if defined __cplusplus && defined __GNUC__ && ! defined __ICC && 6 <= __GNUC__
# define YY_IGNORE_USELESS_CAST_BEGIN                          \
    _Pragma ("GCC diagnostic push")                            \
    _Pragma ("GCC diagnostic ignored \"-Wuseless-cast\"")
# define YY_IGNORE_USELESS_CAST_END            \
    _Pragma ("GCC diagnostic pop")
#endif
#ifndef YY_IGNORE_USELESS_CAST_BEGIN
# define YY_IGNORE_USELESS_CAST_BEGIN
# define YY_IGNORE_USELESS_CAST_END
#endif


#define YY_ASSERT(E) ((void) (0 && (E)))

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
  yy_state_t yyss_alloc;
  YYSTYPE yyvs_alloc;
};

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (YYSIZEOF (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (YYSIZEOF (yy_state_t) + YYSIZEOF (YYSTYPE)) \
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
        YYPTRDIFF_T yynewbytes;                                         \
        YYCOPY (&yyptr->Stack_alloc, Stack, yysize);                    \
        Stack = &yyptr->Stack_alloc;                                    \
        yynewbytes = yystacksize * YYSIZEOF (*Stack) + YYSTACK_GAP_MAXIMUM; \
        yyptr += yynewbytes / YYSIZEOF (*yyptr);                        \
      }                                                                 \
    while (0)

#endif

#if defined YYCOPY_NEEDED && YYCOPY_NEEDED
/* Copy COUNT objects from SRC to DST.  The source and destination do
   not overlap.  */
# ifndef YYCOPY
#  if defined __GNUC__ && 1 < __GNUC__
#   define YYCOPY(Dst, Src, Count) \
      __builtin_memcpy (Dst, Src, YY_CAST (YYSIZE_T, (Count)) * sizeof (*(Src)))
#  else
#   define YYCOPY(Dst, Src, Count)              \
      do                                        \
        {                                       \
          YYPTRDIFF_T yyi;                      \
          for (yyi = 0; yyi < (Count); yyi++)   \
            (Dst)[yyi] = (Src)[yyi];            \
        }                                       \
      while (0)
#  endif
# endif
#endif /* !YYCOPY_NEEDED */

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  5
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   2654

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  137
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  71
/* YYNRULES -- Number of rules.  */
#define YYNRULES  338
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  713

#define YYUNDEFTOK  2
#define YYMAXUTOK   368


/* YYTRANSLATE(TOKEN-NUM) -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex, with out-of-bounds checking.  */
#define YYTRANSLATE(YYX)                                                \
  (0 <= (YYX) && (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[TOKEN-NUM] -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex.  */
static const yytype_uint8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,   136,    43,     2,     2,     2,    38,    11,     2,
     129,   130,    36,    32,   131,    33,     2,    37,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,   135,     8,
      17,   128,    18,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,   132,     2,   133,     9,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,   134,     6,   127,    44,     2,     2,     2,
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
       5,     7,    10,    12,    13,    14,    15,    16,    19,    20,
      21,    22,    23,    24,    25,    26,    27,    28,    29,    30,
      31,    34,    35,    39,    40,    41,    42,    45,    46,    47,
      48,    49,    50,    51,    52,    53,    54,    55,    56,    57,
      58,    59,    60,    61,    62,    63,    64,    65,    66,    67,
      68,    69,    70,    71,    72,    73,    74,    75,    76,    77,
      78,    79,    80,    81,    82,    83,    84,    85,    86,    87,
      88,    89,    90,    91,    92,    93,    94,    95,    96,    97,
      98,    99,   100,   101,   102,   103,   104,   105,   106,   107,
     108,   109,   110,   111,   112,   113,   114,   115,   116,   117,
     118,   119,   120,   121,   122,   123,   124,   125,   126
};

#if YYDEBUG
  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_int16 yyrline[] =
{
       0,   156,   156,   157,   158,   159,   161,   162,   163,   164,
     165,   166,   167,   168,   169,   170,   172,   173,   174,   175,
     177,   178,   180,   182,   184,   185,   186,   187,   188,   190,
     192,   193,   196,   197,   198,   199,   200,   202,   203,   204,
     205,   206,   207,   209,   211,   212,   213,   214,   215,   216,
     217,   219,   221,   223,   225,   226,   228,   231,   233,   235,
     237,   239,   242,   244,   245,   246,   248,   250,   251,   252,
     255,   256,   259,   261,   262,   263,   265,   266,   268,   269,
     270,   271,   272,   273,   274,   275,   276,   278,   279,   280,
     281,   283,   285,   288,   289,   290,   291,   292,   293,   294,
     295,   296,   297,   298,   299,   300,   302,   303,   304,   305,
     307,   308,   310,   311,   313,   314,   316,   317,   318,   319,
     320,   321,   322,   325,   326,   327,   328,   330,   331,   333,
     334,   335,   336,   337,   338,   340,   341,   343,   345,   346,
     348,   349,   350,   351,   352,   354,   355,   356,   357,   359,
     360,   361,   362,   363,   364,   365,   366,   367,   368,   369,
     370,   371,   372,   373,   374,   375,   376,   377,   378,   379,
     380,   381,   382,   383,   385,   386,   387,   388,   389,   390,
     391,   392,   393,   394,   395,   396,   397,   398,   399,   400,
     401,   402,   403,   404,   405,   406,   407,   408,   409,   410,
     411,   412,   413,   414,   415,   416,   417,   418,   419,   420,
     421,   422,   423,   424,   425,   426,   427,   428,   429,   430,
     431,   432,   433,   434,   435,   436,   437,   438,   439,   440,
     441,   442,   443,   444,   445,   446,   447,   448,   449,   450,
     452,   453,   454,   455,   457,   458,   459,   460,   461,   462,
     463,   464,   466,   467,   468,   469,   471,   472,   473,   474,
     475,   477,   478,   479,   481,   482,   484,   485,   486,   487,
     488,   489,   491,   492,   493,   494,   495,   497,   498,   499,
     500,   501,   503,   504,   506,   507,   508,   510,   511,   512,
     514,   515,   516,   519,   520,   522,   523,   524,   526,   528,
     529,   530,   531,   533,   534,   535,   537,   538,   539,   540,
     541,   543,   544,   546,   547,   549,   550,   553,   554,   555,
     557,   558,   559,   561,   562,   563,   564,   565,   566,   567,
     568,   569,   570,   571,   572,   573,   574,   575,   576
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || 0
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "OP_BOOL_OR", "OP_BOOL_AND",
  "OP_BOOL_XOR", "'|'", "OP_OR", "';'", "'^'", "OP_XOR", "'&'", "OP_AND",
  "OP_EQUAL", "OP_NOTEQUAL", "OP_FEQUAL", "OP_FNOTEQUAL", "'<'", "'>'",
  "OP_GREATEQUAL", "OP_LESSEQUAL", "OP_SLESS", "OP_SGREATEQUAL",
  "OP_SLESSEQUAL", "OP_SGREAT", "OP_FLESS", "OP_FGREAT", "OP_FLESSEQUAL",
  "OP_FGREATEQUAL", "OP_LEFT", "OP_RIGHT", "OP_SRIGHT", "'+'", "'-'",
  "OP_FADD", "OP_FSUB", "'*'", "'/'", "'%'", "OP_SDIV", "OP_SREM",
  "OP_FMULT", "OP_FDIV", "'!'", "'~'", "OP_ZEXT", "OP_CARRY", "OP_BORROW",
  "OP_SEXT", "OP_SCARRY", "OP_SBORROW", "OP_NAN", "OP_ABS", "OP_SQRT",
  "OP_CEIL", "OP_FLOOR", "OP_ROUND", "OP_INT2FLOAT", "OP_FLOAT2FLOAT",
  "OP_TRUNC", "OP_CPOOLREF", "OP_NEW", "OP_POPCOUNT", "BADINTEGER",
  "GOTO_KEY", "CALL_KEY", "RETURN_KEY", "IF_KEY", "DEFINE_KEY",
  "ATTACH_KEY", "MACRO_KEY", "SPACE_KEY", "TYPE_KEY", "RAM_KEY",
  "DEFAULT_KEY", "REGISTER_KEY", "ENDIAN_KEY", "WITH_KEY", "ALIGN_KEY",
  "OP_UNIMPL", "TOKEN_KEY", "SIGNED_KEY", "NOFLOW_KEY", "HEX_KEY",
  "DEC_KEY", "BIG_KEY", "LITTLE_KEY", "SIZE_KEY", "WORDSIZE_KEY",
  "OFFSET_KEY", "NAMES_KEY", "VALUES_KEY", "VARIABLES_KEY", "PCODEOP_KEY",
  "IS_KEY", "LOCAL_KEY", "DELAYSLOT_KEY", "CROSSBUILD_KEY", "EXPORT_KEY",
  "BUILD_KEY", "CONTEXT_KEY", "ELLIPSIS_KEY", "GLOBALSET_KEY",
  "BITRANGE_KEY", "CHAR", "INTEGER", "INTB", "STRING", "SYMBOLSTRING",
  "SPACESYM", "SECTIONSYM", "TOKENSYM", "USEROPSYM", "VALUESYM",
  "VALUEMAPSYM", "CONTEXTSYM", "NAMESYM", "VARSYM", "BITSYM", "SPECSYM",
  "VARLISTSYM", "OPERANDSYM", "STARTSYM", "ENDSYM", "MACROSYM", "LABELSYM",
  "SUBTABLESYM", "'}'", "'='", "'('", "')'", "','", "'['", "']'", "'{'",
  "':'", "' '", "$accept", "spec", "definition", "constructorlike",
  "endiandef", "aligndef", "tokendef", "tokenprop", "contextdef",
  "contextprop", "fielddef", "contextfielddef", "spacedef", "spaceprop",
  "varnodedef", "bitrangedef", "bitrangelist", "bitrangesingle",
  "pcodeopdef", "valueattach", "nameattach", "varattach", "macrodef",
  "withblockstart", "withblockmid", "withblock", "id_or_nil",
  "bitpat_or_nil", "macrostart", "rtlbody", "constructor",
  "constructprint", "subtablestart", "pexpression", "pequation", "elleq",
  "ellrt", "atomic", "constraint", "contextblock", "contextlist",
  "section_def", "rtlfirstsection", "rtlcontinue", "rtl", "rtlmid",
  "statement", "expr", "sizedstar", "jumpdest", "varnode",
  "integervarnode", "lhsvarnode", "label", "exportvarnode", "familysymbol",
  "specificsymbol", "charstring", "intblist", "intbpart", "stringlist",
  "stringpart", "anystringlist", "anystringpart", "valuelist", "valuepart",
  "varlist", "varpart", "paramlist", "oplist", "anysymbol", YY_NULLPTR
};
#endif

# ifdef YYPRINT
/* YYTOKNUM[NUM] -- (External) token number corresponding to the
   (internal) symbol number NUM (which must be that of a token).  */
static const yytype_int16 yytoknum[] =
{
       0,   256,   257,   258,   259,   260,   124,   261,    59,    94,
     262,    38,   263,   264,   265,   266,   267,    60,    62,   268,
     269,   270,   271,   272,   273,   274,   275,   276,   277,   278,
     279,   280,    43,    45,   281,   282,    42,    47,    37,   283,
     284,   285,   286,    33,   126,   287,   288,   289,   290,   291,
     292,   293,   294,   295,   296,   297,   298,   299,   300,   301,
     302,   303,   304,   305,   306,   307,   308,   309,   310,   311,
     312,   313,   314,   315,   316,   317,   318,   319,   320,   321,
     322,   323,   324,   325,   326,   327,   328,   329,   330,   331,
     332,   333,   334,   335,   336,   337,   338,   339,   340,   341,
     342,   343,   344,   345,   346,   347,   348,   349,   350,   351,
     352,   353,   354,   355,   356,   357,   358,   359,   360,   361,
     362,   363,   364,   365,   366,   367,   368,   125,    61,    40,
      41,    44,    91,    93,   123,    58,    32
};
# endif

#define YYPACT_NINF (-313)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-271)

#define yytable_value_is_error(Yyn) \
  ((Yyn) == YYTABLE_NINF)

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
     -42,    58,     3,  -313,   -37,  -313,     5,   -41,    -5,    42,
      50,    25,    44,  -313,  -313,  -313,  -313,  -313,   388,  -313,
     419,  -313,   317,  -313,  -313,  -313,  -313,  -313,  -313,  -313,
    -313,    37,  -313,    59,  -313,    23,    87,   -45,  -313,  -313,
    2492,    71,  2510,   -78,    90,   172,   197,    33,    33,    33,
     163,  -313,  -313,   182,  -313,  -313,  -313,   200,  -313,  -313,
    -313,  -313,  -313,  -313,  -313,  -313,  -313,  -313,  -313,  -313,
    -313,  -313,  -313,  -313,   351,   254,  -313,   256,   291,   267,
    -313,   269,  -313,   290,   293,   308,  -313,  -313,  -313,  -313,
    -313,  2336,  -313,  -313,  -313,  -313,   276,  -313,  2336,  -313,
    -313,  -313,   276,   417,   423,  -313,  -313,   331,   310,  -313,
    -313,   330,   444,  -313,   327,     8,  -313,   328,  -313,  -313,
     159,   322,   -12,   -84,   350,  2336,   329,  -313,  -313,  -313,
     333,   334,  -313,  -313,  -313,  -313,   336,   249,   361,   362,
     341,  1662,  1481,  -313,  -313,  -313,  -313,  -313,  -313,   349,
    -313,  2336,     4,  -313,  -313,   368,  -313,    64,  -313,     4,
    -313,  -313,   472,   376,  -313,  2362,  -313,   365,  -313,  -313,
     -44,  -313,  -313,   -57,  2528,   476,   381,  -313,    16,   482,
    -313,    54,   485,  -313,   -32,   364,   315,   389,   408,   418,
     420,  -313,  -313,  -313,  -313,  -313,   264,   -30,   179,  -313,
     271,  1668,     1,  1530,   353,   393,  1561,   366,   406,   409,
     141,   428,  -313,   430,  -313,  -313,  -313,  -313,   431,    74,
    -313,  1530,   -65,  -313,   157,  -313,   166,  -313,  1689,    17,
    2336,  2336,  2336,  -313,   -59,  -313,  1689,  1689,  1689,  1689,
    1689,  1689,   -59,  -313,   429,  -313,  -313,  -313,   438,  -313,
     474,  -313,  -313,  -313,  -313,  -313,  2387,  -313,  -313,  -313,
     466,  -313,  -313,   -15,  -313,  -313,  -313,    45,  -313,  -313,
     468,   439,   480,   484,   519,   520,  -313,  -313,   505,  -313,
    -313,   595,   635,   546,   581,  -313,   559,  -313,  -313,  -313,
    -313,  1530,   686,  -313,  1530,   723,  -313,  1530,  1530,  1530,
    1530,  1530,   605,   638,   639,   647,   649,   680,   685,   688,
     690,   725,   728,   730,   765,   770,   805,   806,   810,   845,
    -313,  1530,  1810,  1530,  -313,   -10,     0,   564,   627,   764,
     307,   840,   971,  -313,   161,  1006,  -313,  1011,   910,  1530,
     949,  1530,  1530,  1530,  1487,   950,   954,  1530,   989,  1689,
    1689,  -313,  1689,  2369,  -313,  -313,  -313,   325,  1084,  -313,
      75,  -313,  -313,  -313,  2369,  2369,  2369,  2369,  2369,  2369,
    -313,  1023,  1029,  1046,  -313,  -313,  -313,  -313,  1030,  -313,
    -313,  -313,  -313,  -313,  -313,  -313,  -313,  1034,  1070,  1074,
    1109,  1561,  -313,  -313,  1082,  -313,  1110,   326,  -313,   563,
    -313,   603,  -313,  -313,  -313,  -313,  1530,  1530,  1530,  1530,
    1530,  1530,  1530,  1530,  1530,  1530,  1530,  1530,  1530,  1530,
    1530,  1530,  1530,  1530,   807,  1530,  1530,  1530,  1530,  1530,
    1530,  1530,  1530,  1530,  1530,  1530,  1530,  1530,  1530,  1530,
    1530,  1530,  1530,  1530,  1530,  1530,  1530,  1530,  1530,  1530,
    1530,  1530,  1530,  1530,  1530,  1530,  1530,  1530,  1530,  1530,
    1530,  1627,  -313,    11,  1149,  1150,  -313,  1530,  1154,  -313,
    1164,   299,  1190,  -313,  1194,  1326,  -313,  1331,  -313,  -313,
    -313,  -313,  1862,  1246,  2182,    36,  1902,    43,  1530,  1205,
    1251,  1942,  1244,  -313,  -313,   283,  1689,  1689,  1689,  1689,
    1689,  1689,  1689,  1689,  1689,  1285,  -313,  1291,  1366,  -313,
    -313,  -313,   -18,  1371,  1284,  1349,  -313,  1325,  1329,  1365,
    1402,  -313,  1399,  1403,  1531,  1532,  1534,   847,   684,   887,
     724,   766,   927,   967,  1007,  1047,  1087,  1127,  1167,  1207,
    1247,    96,   643,  1287,   136,  -313,  2221,  2258,  2258,  2292,
    2324,  2394,  2504,  2504,  2504,  2504,  2530,  2530,  2530,  2530,
    2530,  2530,  2530,  2530,  2530,  2530,  2530,  2530,   514,   514,
     514,   479,   479,   479,   479,  -313,  -313,  -313,  -313,  -313,
    -313,  -313,  1535,  1408,  1413,  -313,  1982,     9,  1537,  1538,
    1539,  1561,  -313,  -313,  -313,  1530,  1540,  1530,  -313,  1541,
    2022,  -313,  -313,  -313,  1445,  -313,  2431,  2561,   168,   383,
     383,    29,    29,  -313,  -313,  1622,  1689,  1689,  1597,   300,
    -313,  -313,    27,  1446,   -78,  -313,  -313,  -313,  -313,  1449,
    -313,  -313,  -313,  -313,  -313,  1530,  -313,  1530,  1530,  -313,
    -313,  -313,  -313,  -313,  -313,  -313,  -313,  -313,  -313,  -313,
    1530,  -313,  -313,  -313,  -313,  1452,  -313,  -313,  1530,  -313,
    -313,  -313,  -313,  2062,  -313,  2182,  -313,  -313,  1425,  1430,
    1431,  1523,  2360,  -313,  -313,  1568,  1569,  -313,  -313,  1434,
    1556,  -313,  1327,  1367,  1407,  1447,  1435,  2102,  -313,  1441,
    1455,  1456,  -313,  -313,  -313,  -313,  -313,  -313,  -313,  -313,
    -313,  -313,  -313,  -313,  1530,  1473,  1474,  2142,  1598,  1601,
    -313,  -313,  -313
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_int16 yydefact[] =
{
       0,     0,     0,     2,     0,     1,     0,     0,     0,     0,
      67,     0,     0,    89,     4,     5,     3,     6,     0,     7,
       0,     8,     0,     9,    10,    11,    12,    13,    14,    17,
      63,     0,    18,     0,    16,     0,     0,     0,    15,    19,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    69,    68,     0,    88,    87,    23,     0,   323,   324,
     325,   326,   329,   330,   331,   332,   333,   338,   334,   335,
     336,   337,   327,   328,    27,     0,    29,     0,    31,     0,
      43,     0,    50,     0,     0,     0,    66,    64,    65,   145,
      82,     0,   282,    83,    86,    85,    84,    81,     0,    78,
      80,    90,    79,     0,     0,    44,    45,     0,     0,    28,
     294,     0,     0,    30,     0,     0,    54,     0,   304,   305,
       0,     0,     0,     0,   320,    70,     0,    34,    35,    36,
       0,     0,    39,    40,    41,    42,     0,     0,     0,     0,
       0,   140,     0,   272,   273,   274,   275,   124,   276,   123,
     126,     0,   127,   106,   111,   113,   114,   125,   283,   127,
      20,    21,     0,     0,   295,     0,    57,     0,    53,    55,
       0,   306,   307,     0,     0,     0,     0,   285,     0,     0,
     312,     0,     0,   321,     0,   127,    71,     0,     0,     0,
       0,    46,    47,    48,    49,    61,     0,     0,   243,   257,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   256,
     254,     0,   277,     0,   278,   279,   280,   281,     0,   255,
     146,     0,     0,   253,     0,   173,   252,   110,     0,     0,
       0,     0,     0,   129,     0,   112,     0,     0,     0,     0,
       0,     0,     0,    22,     0,   296,   293,   297,     0,    52,
       0,   310,   308,   309,   303,   299,     0,   300,    59,   286,
       0,   287,   289,     0,    58,   314,   313,     0,    60,    72,
       0,     0,     0,     0,     0,     0,   254,   255,     0,   259,
     252,     0,     0,     0,     0,   247,   246,   251,   248,   244,
     245,     0,     0,   250,     0,     0,   170,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     237,     0,     0,     0,   174,   252,     0,     0,     0,     0,
       0,     0,   143,   271,     0,     0,   266,     0,     0,     0,
       0,   317,     0,   317,     0,     0,     0,     0,     0,     0,
       0,    91,     0,   122,    92,    93,   115,   108,   109,   107,
       0,    75,   145,    76,   117,   118,   120,   121,   119,   116,
      77,    24,     0,     0,   301,   298,   302,   288,     0,   290,
     292,   284,   316,   315,   311,   322,    62,     0,     0,     0,
       0,     0,   265,   264,     0,   242,     0,     0,   165,     0,
     168,     0,   189,   216,   202,   190,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     317,     0,     0,   317,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   175,     0,     0,     0,   147,     0,     0,   154,
       0,     0,     0,   267,     0,   144,   263,     0,   261,   141,
     161,   258,     0,     0,   318,     0,     0,     0,     0,     0,
       0,     0,     0,   104,   105,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   134,     0,     0,   128,
     138,   145,     0,     0,     0,     0,   291,     0,     0,     0,
       0,   260,   241,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   176,   205,   204,   203,   193,
     191,   192,   179,   180,   206,   207,   181,   184,   182,   183,
     185,   186,   187,   188,   208,   209,   210,   211,   194,   195,
     196,   177,   178,   212,   213,   197,   198,   200,   199,   201,
     214,   215,     0,     0,     0,   235,     0,     0,     0,     0,
       0,     0,   269,   142,   151,     0,     0,     0,   158,     0,
       0,   160,   159,   149,     0,    94,   101,   102,   100,    98,
      99,    95,    96,    97,   103,     0,     0,     0,     0,     0,
      73,   137,     0,     0,     0,    32,    33,    37,    38,     0,
     249,   167,   169,   171,   220,     0,   219,     0,     0,   226,
     217,   218,   228,   229,   230,   225,   224,   227,   239,   231,
       0,   233,   238,   166,   234,     0,   150,   148,     0,   164,
     163,   162,   268,     0,   156,   319,   172,   155,     0,     0,
       0,     0,     0,    74,   139,     0,     0,    26,    25,     0,
       0,   240,     0,     0,     0,     0,     0,     0,   153,     0,
       0,     0,   130,   133,   135,   136,    56,    51,   221,   222,
     223,   232,   236,   152,     0,     0,     0,     0,     0,     0,
     157,   131,   132
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -313,  -313,  1574,  1580,  -313,  -313,  -313,  -313,  -313,  -313,
    -313,  -313,  -313,  -313,  -313,  -313,  -313,  1497,  -313,  -313,
    -313,  -313,  -313,  -313,  -313,  -313,  -313,  -313,  -313,  1374,
    -313,  -313,  -313,  -194,   -62,  -313,  1471,  -313,  -313,  -132,
    -313,   999,  -313,  -313,  1256,  1108,  -313,  -197,  -140,  -196,
    -127,  1157,  1288,  -139,  -313,   -91,   -53,  1585,  -313,  -313,
    1001,  -313,  -313,  -313,   252,  -313,  -313,  -313,  -312,  -313,
      15
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     2,    14,    15,     3,    16,    17,    18,    19,    20,
      74,    78,    21,    22,    23,    24,   115,   116,    25,    26,
      27,    28,    29,    30,    31,    32,    53,   185,    33,   363,
      34,    35,    36,   353,   152,   153,   154,   155,   156,   234,
     360,   621,   510,   511,   140,   141,   220,   484,   323,   292,
     324,   223,   224,   293,   335,   354,   325,    96,   179,   263,
     112,   165,   175,   256,   121,   173,   182,   267,   485,   184,
      75
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
     157,   221,   225,     5,     6,   295,   322,   157,   466,   296,
     230,   619,   231,    38,   222,   232,   168,   657,   378,   249,
     361,   176,   196,   230,   344,   231,     1,   242,   232,   110,
      40,   487,    90,   180,   157,    79,   159,    41,     6,    42,
     103,   104,   364,   365,   366,   367,   368,   369,   181,   260,
     251,   157,    43,   271,   111,   106,   252,   109,   253,    44,
     157,   250,    45,   186,   345,   503,   504,   334,    46,   279,
     346,     7,     8,     9,   199,   362,   254,   281,   236,   329,
      10,   237,   238,   239,   240,    47,    48,    49,   226,   229,
     379,    37,   380,   177,   397,   282,    97,   399,   269,   270,
     401,   402,   403,   404,   405,    85,     8,     9,   541,   620,
      11,   544,   677,   678,    10,   114,   209,    91,   381,   463,
     178,   261,   464,   262,   424,   465,   462,    92,   467,    12,
      93,    94,    39,   297,     4,   468,   233,   658,    13,   157,
     157,   157,   482,   280,    11,   486,   118,   356,   119,    50,
     491,   327,   382,   280,   336,   493,   494,    51,   495,    95,
      54,   265,   383,    12,    86,   120,   596,   597,   357,   358,
     359,   266,    13,   599,   597,   355,    52,   505,   384,    55,
     247,    98,   506,   355,   355,   355,   355,   355,   355,   257,
     507,    92,   241,    89,    99,   100,   508,   499,   500,   107,
     501,   502,  -263,   473,   503,   504,  -263,   113,   509,   527,
     528,   529,   530,   531,   532,   533,   534,   535,   536,   537,
     538,   539,   540,   101,   542,   543,   648,   597,   546,   547,
     548,   549,   550,   551,   552,   553,   554,   555,   556,   557,
     558,   559,   560,   561,   562,   563,   564,   565,   566,   567,
     568,   569,   570,   571,   572,   573,   574,   575,   576,   577,
     578,   579,   580,   581,   521,   582,   652,   597,   475,   339,
     586,   376,   171,  -262,   172,   196,   340,   280,   212,   114,
     214,   478,   215,   216,   217,   347,   117,   476,   197,   348,
     496,   600,   124,   497,  -261,   498,   355,   355,  -261,   355,
     122,   123,   606,   607,   608,   609,   610,   611,   612,   613,
     614,   283,   499,   500,   284,   501,   502,   125,   196,   503,
     504,   230,   191,   231,   192,    80,   232,   199,   126,   425,
     426,   427,   428,   231,   285,   429,   232,   430,   280,   431,
     432,   433,   434,   435,   436,   437,   438,   439,   440,   441,
     442,   443,   444,   445,   446,   447,   448,   449,   450,   451,
     452,   453,   454,   455,   456,   457,   458,   459,   460,   209,
     199,   276,   132,   133,   134,   135,   286,   330,   287,    40,
     158,   212,   130,   214,   131,   215,   216,   217,    42,    81,
     277,    82,   288,   289,   290,   136,    56,   137,   663,   278,
     665,    43,   198,   291,    83,    84,   589,   675,    44,   590,
     676,    45,   209,   605,   276,   501,   502,    46,   138,   503,
     504,   139,   671,   672,   212,   160,   214,    76,   215,   216,
     217,   161,   127,   277,   128,   129,   162,   164,   682,   163,
     683,   684,   472,   355,   355,   355,   355,   355,   355,   355,
     355,   355,   166,   685,   174,   167,   170,   183,   187,   524,
     326,   687,   188,   189,   662,   190,   193,   194,   195,   235,
     212,   331,   214,   332,   215,   216,   217,   228,   221,   225,
     243,   244,   248,   212,   258,   214,   259,   215,   216,   217,
     264,   222,   333,   268,   272,    57,   233,    58,    59,    60,
      61,    62,    63,    64,    65,    66,    67,   707,    68,    69,
      70,    71,    72,   273,    73,   454,   455,   456,   457,   458,
     459,   460,   328,   274,   669,   275,    77,   337,    58,    59,
      60,    61,    62,    63,    64,    65,    66,    67,   280,    68,
      69,    70,    71,    72,   338,    73,   450,   451,   452,   453,
     454,   455,   456,   457,   458,   459,   460,   341,   342,   371,
     343,   373,   670,   355,   355,   226,   425,   426,   427,   428,
     372,   377,   429,   386,   430,   385,   431,   432,   433,   434,
     435,   436,   437,   438,   439,   440,   441,   442,   443,   444,
     445,   446,   447,   448,   449,   450,   451,   452,   453,   454,
     455,   456,   457,   458,   459,   460,   425,   426,   427,   428,
     391,   387,   429,   392,   430,   388,   431,   432,   433,   434,
     435,   436,   437,   438,   439,   440,   441,   442,   443,   444,
     445,   446,   447,   448,   449,   450,   451,   452,   453,   454,
     455,   456,   457,   458,   459,   460,   425,   426,   427,   428,
     389,   390,   429,   393,   430,   394,   431,   432,   433,   434,
     435,   436,   437,   438,   439,   440,   441,   442,   443,   444,
     445,   446,   447,   448,   449,   450,   451,   452,   453,   454,
     455,   456,   457,   458,   459,   460,   395,   425,   426,   427,
     428,   396,   469,   429,   398,   430,   525,   431,   432,   433,
     434,   435,   436,   437,   438,   439,   440,   441,   442,   443,
     444,   445,   446,   447,   448,   449,   450,   451,   452,   453,
     454,   455,   456,   457,   458,   459,   460,   425,   426,   427,
     428,   400,   470,   429,   406,   430,   526,   431,   432,   433,
     434,   435,   436,   437,   438,   439,   440,   441,   442,   443,
     444,   445,   446,   447,   448,   449,   450,   451,   452,   453,
     454,   455,   456,   457,   458,   459,   460,   407,   408,   425,
     426,   427,   428,   649,   650,   429,   409,   430,   410,   431,
     432,   433,   434,   435,   436,   437,   438,   439,   440,   441,
     442,   443,   444,   445,   446,   447,   448,   449,   450,   451,
     452,   453,   454,   455,   456,   457,   458,   459,   460,   411,
     425,   426,   427,   428,   412,   635,   429,   413,   430,   414,
     431,   432,   433,   434,   435,   436,   437,   438,   439,   440,
     441,   442,   443,   444,   445,   446,   447,   448,   449,   450,
     451,   452,   453,   454,   455,   456,   457,   458,   459,   460,
     425,   426,   427,   428,   415,   637,   429,   416,   430,   417,
     431,   432,   433,   434,   435,   436,   437,   438,   439,   440,
     441,   442,   443,   444,   445,   446,   447,   448,   449,   450,
     451,   452,   453,   454,   455,   456,   457,   458,   459,   460,
     425,   426,   427,   428,   418,   471,   429,   638,   430,   419,
     431,   432,   433,   434,   435,   436,   437,   438,   439,   440,
     441,   442,   443,   444,   445,   446,   447,   448,   449,   450,
     451,   452,   453,   454,   455,   456,   457,   458,   459,   460,
     425,   426,   427,   428,   420,   421,   429,   545,   430,   422,
     431,   432,   433,   434,   435,   436,   437,   438,   439,   440,
     441,   442,   443,   444,   445,   446,   447,   448,   449,   450,
     451,   452,   453,   454,   455,   456,   457,   458,   459,   460,
     425,   426,   427,   428,   423,   474,   429,   634,   430,  -270,
     431,   432,   433,   434,   435,   436,   437,   438,   439,   440,
     441,   442,   443,   444,   445,   446,   447,   448,   449,   450,
     451,   452,   453,   454,   455,   456,   457,   458,   459,   460,
     425,   426,   427,   428,   479,   481,   429,   636,   430,   480,
     431,   432,   433,   434,   435,   436,   437,   438,   439,   440,
     441,   442,   443,   444,   445,   446,   447,   448,   449,   450,
     451,   452,   453,   454,   455,   456,   457,   458,   459,   460,
     425,   426,   427,   428,   483,   489,   429,   639,   430,   490,
     431,   432,   433,   434,   435,   436,   437,   438,   439,   440,
     441,   442,   443,   444,   445,   446,   447,   448,   449,   450,
     451,   452,   453,   454,   455,   456,   457,   458,   459,   460,
     425,   426,   427,   428,   492,   232,   429,   640,   430,   513,
     431,   432,   433,   434,   435,   436,   437,   438,   439,   440,
     441,   442,   443,   444,   445,   446,   447,   448,   449,   450,
     451,   452,   453,   454,   455,   456,   457,   458,   459,   460,
     425,   426,   427,   428,   514,   516,   429,   641,   430,   517,
     431,   432,   433,   434,   435,   436,   437,   438,   439,   440,
     441,   442,   443,   444,   445,   446,   447,   448,   449,   450,
     451,   452,   453,   454,   455,   456,   457,   458,   459,   460,
     425,   426,   427,   428,   515,   518,   429,   642,   430,   519,
     431,   432,   433,   434,   435,   436,   437,   438,   439,   440,
     441,   442,   443,   444,   445,   446,   447,   448,   449,   450,
     451,   452,   453,   454,   455,   456,   457,   458,   459,   460,
     425,   426,   427,   428,   520,   522,   429,   643,   430,   523,
     431,   432,   433,   434,   435,   436,   437,   438,   439,   440,
     441,   442,   443,   444,   445,   446,   447,   448,   449,   450,
     451,   452,   453,   454,   455,   456,   457,   458,   459,   460,
     425,   426,   427,   428,   584,   585,   429,   644,   430,   587,
     431,   432,   433,   434,   435,   436,   437,   438,   439,   440,
     441,   442,   443,   444,   445,   446,   447,   448,   449,   450,
     451,   452,   453,   454,   455,   456,   457,   458,   459,   460,
     425,   426,   427,   428,   588,   591,   429,   645,   430,   592,
     431,   432,   433,   434,   435,   436,   437,   438,   439,   440,
     441,   442,   443,   444,   445,   446,   447,   448,   449,   450,
     451,   452,   453,   454,   455,   456,   457,   458,   459,   460,
     425,   426,   427,   428,  -262,   601,   429,   646,   430,   593,
     431,   432,   433,   434,   435,   436,   437,   438,   439,   440,
     441,   442,   443,   444,   445,   446,   447,   448,   449,   450,
     451,   452,   453,   454,   455,   456,   457,   458,   459,   460,
     425,   426,   427,   428,   595,   604,   429,   647,   430,   602,
     431,   432,   433,   434,   435,   436,   437,   438,   439,   440,
     441,   442,   443,   444,   445,   446,   447,   448,   449,   450,
     451,   452,   453,   454,   455,   456,   457,   458,   459,   460,
     425,   426,   427,   428,   615,   623,   429,   651,   430,   616,
     431,   432,   433,   434,   435,   436,   437,   438,   439,   440,
     441,   442,   443,   444,   445,   446,   447,   448,   449,   450,
     451,   452,   453,   454,   455,   456,   457,   458,   459,   460,
     425,   426,   427,   428,   624,   625,   429,   698,   430,   626,
     431,   432,   433,   434,   435,   436,   437,   438,   439,   440,
     441,   442,   443,   444,   445,   446,   447,   448,   449,   450,
     451,   452,   453,   454,   455,   456,   457,   458,   459,   460,
     425,   426,   427,   428,   617,   627,   429,   699,   430,   622,
     431,   432,   433,   434,   435,   436,   437,   438,   439,   440,
     441,   442,   443,   444,   445,   446,   447,   448,   449,   450,
     451,   452,   453,   454,   455,   456,   457,   458,   459,   460,
     496,   692,   628,   497,   629,   498,   630,   700,   654,   631,
     632,   196,   633,   653,   655,   659,   660,   661,   664,   666,
     668,   679,   499,   500,   681,   501,   502,   686,   689,   503,
     504,   690,   691,   298,   697,   299,   198,   696,   702,   704,
     705,   706,   196,   300,   301,   302,   303,   701,   304,   305,
     306,   307,   308,   309,   310,   311,   312,   313,   314,   315,
     316,   317,   318,   199,   143,   144,   145,   146,   694,   695,
     147,   148,   149,   708,   709,    87,   711,   150,   196,   712,
     151,    88,   169,   227,   197,   488,   370,   674,   512,   618,
     583,   102,   477,     0,   199,   680,   619,     0,     0,     0,
       0,     0,     0,   198,     0,   209,     0,   276,     0,     0,
       0,     0,   319,     0,   197,     0,     0,   212,   320,   214,
       0,   215,   216,   217,     0,     0,   277,     0,     0,   321,
     199,   200,   201,   202,   203,     0,   209,     0,   276,     0,
       0,     0,     0,   196,     0,     0,     0,     0,   212,   197,
     214,     0,   215,   216,   217,   197,     0,   277,     0,     0,
     285,     0,   204,   205,   206,     0,   208,     0,   198,     0,
       0,     0,   209,     0,   210,     0,     0,     0,     0,   211,
       0,     0,     0,     0,   212,   213,   214,     0,   215,   216,
     217,   218,   349,   219,   673,   199,   200,   201,   202,   203,
       0,   285,   286,   350,   287,   143,   144,   145,   146,   212,
       0,   214,   148,   215,   216,   217,     0,     0,   288,   289,
     290,     0,     0,     0,     0,     0,     0,   204,   205,   206,
     207,   208,     0,     0,     0,     0,     0,   209,     0,   210,
       0,     0,     0,   286,   211,   287,     0,     0,     0,   212,
     213,   214,     0,   215,   216,   217,   218,     0,   219,   288,
     289,   290,     0,     0,     0,   351,     0,     0,     0,     0,
     294,     0,   143,   144,   145,   146,   212,     0,   214,   148,
     215,   216,   217,   425,   426,   427,   428,     0,   352,   429,
       0,   430,     0,   431,   432,   433,   434,   435,   436,   437,
     438,   439,   440,   441,   442,   443,   444,   445,   446,   447,
     448,   449,   450,   451,   452,   453,   454,   455,   456,   457,
     458,   459,   460,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   425,   426,   427,   428,     0,
     594,   429,     0,   430,   461,   431,   432,   433,   434,   435,
     436,   437,   438,   439,   440,   441,   442,   443,   444,   445,
     446,   447,   448,   449,   450,   451,   452,   453,   454,   455,
     456,   457,   458,   459,   460,   425,   426,   427,   428,     0,
     598,   429,     0,   430,     0,   431,   432,   433,   434,   435,
     436,   437,   438,   439,   440,   441,   442,   443,   444,   445,
     446,   447,   448,   449,   450,   451,   452,   453,   454,   455,
     456,   457,   458,   459,   460,   425,   426,   427,   428,     0,
     603,   429,     0,   430,     0,   431,   432,   433,   434,   435,
     436,   437,   438,   439,   440,   441,   442,   443,   444,   445,
     446,   447,   448,   449,   450,   451,   452,   453,   454,   455,
     456,   457,   458,   459,   460,   425,   426,   427,   428,     0,
     656,   429,     0,   430,     0,   431,   432,   433,   434,   435,
     436,   437,   438,   439,   440,   441,   442,   443,   444,   445,
     446,   447,   448,   449,   450,   451,   452,   453,   454,   455,
     456,   457,   458,   459,   460,   425,   426,   427,   428,     0,
     667,   429,     0,   430,     0,   431,   432,   433,   434,   435,
     436,   437,   438,   439,   440,   441,   442,   443,   444,   445,
     446,   447,   448,   449,   450,   451,   452,   453,   454,   455,
     456,   457,   458,   459,   460,   425,   426,   427,   428,     0,
     688,   429,     0,   430,     0,   431,   432,   433,   434,   435,
     436,   437,   438,   439,   440,   441,   442,   443,   444,   445,
     446,   447,   448,   449,   450,   451,   452,   453,   454,   455,
     456,   457,   458,   459,   460,   425,   426,   427,   428,     0,
     703,   429,     0,   430,     0,   431,   432,   433,   434,   435,
     436,   437,   438,   439,   440,   441,   442,   443,   444,   445,
     446,   447,   448,   449,   450,   451,   452,   453,   454,   455,
     456,   457,   458,   459,   460,   425,   426,   427,   428,     0,
     710,   429,     0,   430,     0,   431,   432,   433,   434,   435,
     436,   437,   438,   439,   440,   441,   442,   443,   444,   445,
     446,   447,   448,   449,   450,   451,   452,   453,   454,   455,
     456,   457,   458,   459,   460,   425,   426,   427,   428,     0,
       0,   429,     0,   430,     0,   431,   432,   433,   434,   435,
     436,   437,   438,   439,   440,   441,   442,   443,   444,   445,
     446,   447,   448,   449,   450,   451,   452,   453,   454,   455,
     456,   457,   458,   459,   460,   426,   427,   428,     0,     0,
     429,     0,   430,     0,   431,   432,   433,   434,   435,   436,
     437,   438,   439,   440,   441,   442,   443,   444,   445,   446,
     447,   448,   449,   450,   451,   452,   453,   454,   455,   456,
     457,   458,   459,   460,   428,     0,     0,   429,     0,   430,
       0,   431,   432,   433,   434,   435,   436,   437,   438,   439,
     440,   441,   442,   443,   444,   445,   446,   447,   448,   449,
     450,   451,   452,   453,   454,   455,   456,   457,   458,   459,
     460,   429,     0,   430,     0,   431,   432,   433,   434,   435,
     436,   437,   438,   439,   440,   441,   442,   443,   444,   445,
     446,   447,   448,   449,   450,   451,   452,   453,   454,   455,
     456,   457,   458,   459,   460,   430,     0,   431,   432,   433,
     434,   435,   436,   437,   438,   439,   440,   441,   442,   443,
     444,   445,   446,   447,   448,   449,   450,   451,   452,   453,
     454,   455,   456,   457,   458,   459,   460,   496,   693,     0,
     497,     0,   498,     0,     0,     0,   496,     0,     0,   497,
       0,   498,     0,     0,     0,     0,     0,     0,     0,   499,
     500,     0,   501,   502,     0,     0,   503,   504,   499,   500,
       0,   501,   502,     0,     0,   503,   504,   431,   432,   433,
     434,   435,   436,   437,   438,   439,   440,   441,   442,   443,
     444,   445,   446,   447,   448,   449,   450,   451,   452,   453,
     454,   455,   456,   457,   458,   459,   460,   142,     0,     0,
       0,   497,     0,   498,     0,     0,     0,     0,     0,   143,
     144,   145,   146,     0,     0,   147,   148,   149,     0,     0,
     499,   500,   150,   501,   502,   151,     0,   503,   504,   245,
       0,    58,    59,    60,    61,    62,    63,    64,    65,    66,
      67,     0,    68,    69,    70,    71,    72,     0,    73,     0,
       0,     0,     0,     0,   374,   246,    58,    59,    60,    61,
      62,    63,    64,    65,    66,    67,     0,    68,    69,    70,
      71,    72,     0,    73,     0,     0,     0,     0,     0,     0,
     375,   435,   436,   437,   438,   439,   440,   441,   442,   443,
     444,   445,   446,   447,   448,   449,   450,   451,   452,   453,
     454,   455,   456,   457,   458,   459,   460,  -271,  -271,  -271,
    -271,  -271,  -271,  -271,  -271,  -271,  -271,  -271,  -271,   447,
     448,   449,   450,   451,   452,   453,   454,   455,   456,   457,
     458,   459,   460,   498,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     499,   500,     0,   501,   502,     0,     0,   503,   504,   105,
       0,    58,    59,    60,    61,    62,    63,    64,    65,    66,
      67,     0,    68,    69,    70,    71,    72,   108,    73,    58,
      59,    60,    61,    62,    63,    64,    65,    66,    67,     0,
      68,    69,    70,    71,    72,   255,    73,    58,    59,    60,
      61,    62,    63,    64,    65,    66,    67,     0,    68,    69,
      70,    71,    72,     0,    73
};

static const yytype_int16 yycheck[] =
{
      91,   141,   141,     0,     1,   201,   203,    98,     8,     8,
       6,    29,     8,     8,   141,    11,     8,     8,    33,    63,
      79,    33,    11,     6,   221,     8,    68,   159,    11,   107,
      71,   343,     9,   117,   125,    20,    98,    78,     1,    80,
      85,    86,   236,   237,   238,   239,   240,   241,   132,    33,
     107,   142,    93,   185,   132,    40,   113,    42,   115,   100,
     151,   105,   103,   125,   129,    36,    37,   207,   109,   196,
     135,    68,    69,    70,    63,   134,   133,   107,    14,   206,
      77,    17,    18,    19,    20,    90,    91,    92,   141,   151,
     105,   128,   107,   105,   291,   125,     9,   294,   130,   131,
     297,   298,   299,   300,   301,    68,    69,    70,   420,   127,
     107,   423,    85,    86,    77,   107,   105,    94,   133,   129,
     132,   105,   132,   107,   321,   135,   323,   104,   128,   126,
     107,   108,   127,   132,    76,   135,   132,   128,   135,   230,
     231,   232,   339,   196,   107,   342,   113,   130,   115,   107,
     347,   204,   107,   206,   207,   349,   350,   107,   352,   136,
     135,   107,   117,   126,   127,   132,   130,   131,   230,   231,
     232,   117,   135,   130,   131,   228,   126,   102,   133,   135,
     165,    94,   107,   236,   237,   238,   239,   240,   241,   174,
     115,   104,   128,   134,   107,   108,   121,    29,    30,   128,
      32,    33,   128,   330,    36,    37,   132,   117,   133,   406,
     407,   408,   409,   410,   411,   412,   413,   414,   415,   416,
     417,   418,   419,   136,   421,   422,   130,   131,   425,   426,
     427,   428,   429,   430,   431,   432,   433,   434,   435,   436,
     437,   438,   439,   440,   441,   442,   443,   444,   445,   446,
     447,   448,   449,   450,   451,   452,   453,   454,   455,   456,
     457,   458,   459,   460,   391,   461,   130,   131,   107,   128,
     467,   256,   113,   132,   115,    11,   135,   330,   117,   107,
     119,   334,   121,   122,   123,   128,    89,   126,    17,   132,
       7,   488,   129,    10,   128,    12,   349,   350,   132,   352,
      48,    49,   496,   497,   498,   499,   500,   501,   502,   503,
     504,   132,    29,    30,   135,    32,    33,   135,    11,    36,
      37,     6,    73,     8,    75,     8,    11,    63,   128,     3,
       4,     5,     6,     8,    63,     9,    11,    11,   391,    13,
      14,    15,    16,    17,    18,    19,    20,    21,    22,    23,
      24,    25,    26,    27,    28,    29,    30,    31,    32,    33,
      34,    35,    36,    37,    38,    39,    40,    41,    42,   105,
      63,   107,    81,    82,    83,    84,   105,    11,   107,    71,
     104,   117,   128,   119,   128,   121,   122,   123,    80,    72,
     126,    74,   121,   122,   123,   128,     8,   128,   595,   135,
     597,    93,    36,   132,    87,    88,   107,   107,   100,   110,
     110,   103,   105,   130,   107,    32,    33,   109,   128,    36,
      37,   128,   616,   617,   117,     8,   119,     8,   121,   122,
     123,     8,    81,   126,    83,    84,   105,   107,   635,   129,
     637,   638,   135,   496,   497,   498,   499,   500,   501,   502,
     503,   504,     8,   650,   132,   128,   128,   107,   129,   133,
     107,   658,   129,   129,   591,   129,   105,   105,   127,   101,
     117,   105,   119,   107,   121,   122,   123,   128,   618,   618,
       8,   105,   117,   117,     8,   119,   105,   121,   122,   123,
       8,   618,   126,     8,   105,   107,   132,   109,   110,   111,
     112,   113,   114,   115,   116,   117,   118,   704,   120,   121,
     122,   123,   124,   105,   126,    36,    37,    38,    39,    40,
      41,    42,   129,   105,   615,   105,   107,   121,   109,   110,
     111,   112,   113,   114,   115,   116,   117,   118,   591,   120,
     121,   122,   123,   124,   135,   126,    32,    33,    34,    35,
      36,    37,    38,    39,    40,    41,    42,   129,   128,   130,
     129,    87,   615,   616,   617,   618,     3,     4,     5,     6,
     132,   105,     9,   134,    11,   107,    13,    14,    15,    16,
      17,    18,    19,    20,    21,    22,    23,    24,    25,    26,
      27,    28,    29,    30,    31,    32,    33,    34,    35,    36,
      37,    38,    39,    40,    41,    42,     3,     4,     5,     6,
     105,   131,     9,    18,    11,   131,    13,    14,    15,    16,
      17,    18,    19,    20,    21,    22,    23,    24,    25,    26,
      27,    28,    29,    30,    31,    32,    33,    34,    35,    36,
      37,    38,    39,    40,    41,    42,     3,     4,     5,     6,
     131,   131,     9,    18,    11,   109,    13,    14,    15,    16,
      17,    18,    19,    20,    21,    22,    23,    24,    25,    26,
      27,    28,    29,    30,    31,    32,    33,    34,    35,    36,
      37,    38,    39,    40,    41,    42,   105,     3,     4,     5,
       6,   132,   128,     9,     8,    11,   133,    13,    14,    15,
      16,    17,    18,    19,    20,    21,    22,    23,    24,    25,
      26,    27,    28,    29,    30,    31,    32,    33,    34,    35,
      36,    37,    38,    39,    40,    41,    42,     3,     4,     5,
       6,     8,   105,     9,   129,    11,   133,    13,    14,    15,
      16,    17,    18,    19,    20,    21,    22,    23,    24,    25,
      26,    27,    28,    29,    30,    31,    32,    33,    34,    35,
      36,    37,    38,    39,    40,    41,    42,   129,   129,     3,
       4,     5,     6,   130,   131,     9,   129,    11,   129,    13,
      14,    15,    16,    17,    18,    19,    20,    21,    22,    23,
      24,    25,    26,    27,    28,    29,    30,    31,    32,    33,
      34,    35,    36,    37,    38,    39,    40,    41,    42,   129,
       3,     4,     5,     6,   129,   131,     9,   129,    11,   129,
      13,    14,    15,    16,    17,    18,    19,    20,    21,    22,
      23,    24,    25,    26,    27,    28,    29,    30,    31,    32,
      33,    34,    35,    36,    37,    38,    39,    40,    41,    42,
       3,     4,     5,     6,   129,   131,     9,   129,    11,   129,
      13,    14,    15,    16,    17,    18,    19,    20,    21,    22,
      23,    24,    25,    26,    27,    28,    29,    30,    31,    32,
      33,    34,    35,    36,    37,    38,    39,    40,    41,    42,
       3,     4,     5,     6,   129,   131,     9,   131,    11,   129,
      13,    14,    15,    16,    17,    18,    19,    20,    21,    22,
      23,    24,    25,    26,    27,    28,    29,    30,    31,    32,
      33,    34,    35,    36,    37,    38,    39,    40,    41,    42,
       3,     4,     5,     6,   129,   129,     9,   130,    11,   129,
      13,    14,    15,    16,    17,    18,    19,    20,    21,    22,
      23,    24,    25,    26,    27,    28,    29,    30,    31,    32,
      33,    34,    35,    36,    37,    38,    39,    40,    41,    42,
       3,     4,     5,     6,   129,   135,     9,   130,    11,     8,
      13,    14,    15,    16,    17,    18,    19,    20,    21,    22,
      23,    24,    25,    26,    27,    28,    29,    30,    31,    32,
      33,    34,    35,    36,    37,    38,    39,    40,    41,    42,
       3,     4,     5,     6,     8,   105,     9,   130,    11,     8,
      13,    14,    15,    16,    17,    18,    19,    20,    21,    22,
      23,    24,    25,    26,    27,    28,    29,    30,    31,    32,
      33,    34,    35,    36,    37,    38,    39,    40,    41,    42,
       3,     4,     5,     6,   105,   105,     9,   130,    11,   105,
      13,    14,    15,    16,    17,    18,    19,    20,    21,    22,
      23,    24,    25,    26,    27,    28,    29,    30,    31,    32,
      33,    34,    35,    36,    37,    38,    39,    40,    41,    42,
       3,     4,     5,     6,   105,    11,     9,   130,    11,    76,
      13,    14,    15,    16,    17,    18,    19,    20,    21,    22,
      23,    24,    25,    26,    27,    28,    29,    30,    31,    32,
      33,    34,    35,    36,    37,    38,    39,    40,    41,    42,
       3,     4,     5,     6,   105,   105,     9,   130,    11,   105,
      13,    14,    15,    16,    17,    18,    19,    20,    21,    22,
      23,    24,    25,    26,    27,    28,    29,    30,    31,    32,
      33,    34,    35,    36,    37,    38,    39,    40,    41,    42,
       3,     4,     5,     6,   128,   105,     9,   130,    11,   105,
      13,    14,    15,    16,    17,    18,    19,    20,    21,    22,
      23,    24,    25,    26,    27,    28,    29,    30,    31,    32,
      33,    34,    35,    36,    37,    38,    39,    40,    41,    42,
       3,     4,     5,     6,   105,   133,     9,   130,    11,   109,
      13,    14,    15,    16,    17,    18,    19,    20,    21,    22,
      23,    24,    25,    26,    27,    28,    29,    30,    31,    32,
      33,    34,    35,    36,    37,    38,    39,    40,    41,    42,
       3,     4,     5,     6,   105,   105,     9,   130,    11,   105,
      13,    14,    15,    16,    17,    18,    19,    20,    21,    22,
      23,    24,    25,    26,    27,    28,    29,    30,    31,    32,
      33,    34,    35,    36,    37,    38,    39,    40,    41,    42,
       3,     4,     5,     6,   130,   105,     9,   130,    11,   105,
      13,    14,    15,    16,    17,    18,    19,    20,    21,    22,
      23,    24,    25,    26,    27,    28,    29,    30,    31,    32,
      33,    34,    35,    36,    37,    38,    39,    40,    41,    42,
       3,     4,     5,     6,     8,   130,     9,   130,    11,     8,
      13,    14,    15,    16,    17,    18,    19,    20,    21,    22,
      23,    24,    25,    26,    27,    28,    29,    30,    31,    32,
      33,    34,    35,    36,    37,    38,    39,    40,    41,    42,
       3,     4,     5,     6,   128,   131,     9,   130,    11,   128,
      13,    14,    15,    16,    17,    18,    19,    20,    21,    22,
      23,    24,    25,    26,    27,    28,    29,    30,    31,    32,
      33,    34,    35,    36,    37,    38,    39,    40,    41,    42,
       3,     4,     5,     6,   129,   131,     9,   130,    11,   128,
      13,    14,    15,    16,    17,    18,    19,    20,    21,    22,
      23,    24,    25,    26,    27,    28,    29,    30,    31,    32,
      33,    34,    35,    36,    37,    38,    39,    40,    41,    42,
       3,     4,     5,     6,   105,   130,     9,   130,    11,   130,
      13,    14,    15,    16,    17,    18,    19,    20,    21,    22,
      23,    24,    25,    26,    27,    28,    29,    30,    31,    32,
      33,    34,    35,    36,    37,    38,    39,    40,    41,    42,
       3,     4,     5,     6,   128,   130,     9,   130,    11,   128,
      13,    14,    15,    16,    17,    18,    19,    20,    21,    22,
      23,    24,    25,    26,    27,    28,    29,    30,    31,    32,
      33,    34,    35,    36,    37,    38,    39,    40,    41,    42,
       7,     8,   130,    10,   135,    12,   133,   130,   130,     8,
       8,    11,     8,     8,   131,     8,     8,     8,     8,     8,
     105,   105,    29,    30,   105,    32,    33,   105,   133,    36,
      37,   131,   131,    33,     8,    35,    36,   133,   133,   128,
     115,   115,    11,    43,    44,    45,    46,   130,    48,    49,
      50,    51,    52,    53,    54,    55,    56,    57,    58,    59,
      60,    61,    62,    63,   113,   114,   115,   116,    30,    30,
     119,   120,   121,   130,   130,    31,     8,   126,    11,     8,
     129,    31,   115,   142,    17,   128,   242,   618,   362,   511,
     463,    36,   334,    -1,    63,   624,    29,    -1,    -1,    -1,
      -1,    -1,    -1,    36,    -1,   105,    -1,   107,    -1,    -1,
      -1,    -1,   112,    -1,    17,    -1,    -1,   117,   118,   119,
      -1,   121,   122,   123,    -1,    -1,   126,    -1,    -1,   129,
      63,    64,    65,    66,    67,    -1,   105,    -1,   107,    -1,
      -1,    -1,    -1,    11,    -1,    -1,    -1,    -1,   117,    17,
     119,    -1,   121,   122,   123,    17,    -1,   126,    -1,    -1,
      63,    -1,    95,    96,    97,    -1,    99,    -1,    36,    -1,
      -1,    -1,   105,    -1,   107,    -1,    -1,    -1,    -1,   112,
      -1,    -1,    -1,    -1,   117,   118,   119,    -1,   121,   122,
     123,   124,    33,   126,   127,    63,    64,    65,    66,    67,
      -1,    63,   105,    44,   107,   113,   114,   115,   116,   117,
      -1,   119,   120,   121,   122,   123,    -1,    -1,   121,   122,
     123,    -1,    -1,    -1,    -1,    -1,    -1,    95,    96,    97,
      98,    99,    -1,    -1,    -1,    -1,    -1,   105,    -1,   107,
      -1,    -1,    -1,   105,   112,   107,    -1,    -1,    -1,   117,
     118,   119,    -1,   121,   122,   123,   124,    -1,   126,   121,
     122,   123,    -1,    -1,    -1,   106,    -1,    -1,    -1,    -1,
     132,    -1,   113,   114,   115,   116,   117,    -1,   119,   120,
     121,   122,   123,     3,     4,     5,     6,    -1,   129,     9,
      -1,    11,    -1,    13,    14,    15,    16,    17,    18,    19,
      20,    21,    22,    23,    24,    25,    26,    27,    28,    29,
      30,    31,    32,    33,    34,    35,    36,    37,    38,    39,
      40,    41,    42,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,     3,     4,     5,     6,    -1,
       8,     9,    -1,    11,    64,    13,    14,    15,    16,    17,
      18,    19,    20,    21,    22,    23,    24,    25,    26,    27,
      28,    29,    30,    31,    32,    33,    34,    35,    36,    37,
      38,    39,    40,    41,    42,     3,     4,     5,     6,    -1,
       8,     9,    -1,    11,    -1,    13,    14,    15,    16,    17,
      18,    19,    20,    21,    22,    23,    24,    25,    26,    27,
      28,    29,    30,    31,    32,    33,    34,    35,    36,    37,
      38,    39,    40,    41,    42,     3,     4,     5,     6,    -1,
       8,     9,    -1,    11,    -1,    13,    14,    15,    16,    17,
      18,    19,    20,    21,    22,    23,    24,    25,    26,    27,
      28,    29,    30,    31,    32,    33,    34,    35,    36,    37,
      38,    39,    40,    41,    42,     3,     4,     5,     6,    -1,
       8,     9,    -1,    11,    -1,    13,    14,    15,    16,    17,
      18,    19,    20,    21,    22,    23,    24,    25,    26,    27,
      28,    29,    30,    31,    32,    33,    34,    35,    36,    37,
      38,    39,    40,    41,    42,     3,     4,     5,     6,    -1,
       8,     9,    -1,    11,    -1,    13,    14,    15,    16,    17,
      18,    19,    20,    21,    22,    23,    24,    25,    26,    27,
      28,    29,    30,    31,    32,    33,    34,    35,    36,    37,
      38,    39,    40,    41,    42,     3,     4,     5,     6,    -1,
       8,     9,    -1,    11,    -1,    13,    14,    15,    16,    17,
      18,    19,    20,    21,    22,    23,    24,    25,    26,    27,
      28,    29,    30,    31,    32,    33,    34,    35,    36,    37,
      38,    39,    40,    41,    42,     3,     4,     5,     6,    -1,
       8,     9,    -1,    11,    -1,    13,    14,    15,    16,    17,
      18,    19,    20,    21,    22,    23,    24,    25,    26,    27,
      28,    29,    30,    31,    32,    33,    34,    35,    36,    37,
      38,    39,    40,    41,    42,     3,     4,     5,     6,    -1,
       8,     9,    -1,    11,    -1,    13,    14,    15,    16,    17,
      18,    19,    20,    21,    22,    23,    24,    25,    26,    27,
      28,    29,    30,    31,    32,    33,    34,    35,    36,    37,
      38,    39,    40,    41,    42,     3,     4,     5,     6,    -1,
      -1,     9,    -1,    11,    -1,    13,    14,    15,    16,    17,
      18,    19,    20,    21,    22,    23,    24,    25,    26,    27,
      28,    29,    30,    31,    32,    33,    34,    35,    36,    37,
      38,    39,    40,    41,    42,     4,     5,     6,    -1,    -1,
       9,    -1,    11,    -1,    13,    14,    15,    16,    17,    18,
      19,    20,    21,    22,    23,    24,    25,    26,    27,    28,
      29,    30,    31,    32,    33,    34,    35,    36,    37,    38,
      39,    40,    41,    42,     6,    -1,    -1,     9,    -1,    11,
      -1,    13,    14,    15,    16,    17,    18,    19,    20,    21,
      22,    23,    24,    25,    26,    27,    28,    29,    30,    31,
      32,    33,    34,    35,    36,    37,    38,    39,    40,    41,
      42,     9,    -1,    11,    -1,    13,    14,    15,    16,    17,
      18,    19,    20,    21,    22,    23,    24,    25,    26,    27,
      28,    29,    30,    31,    32,    33,    34,    35,    36,    37,
      38,    39,    40,    41,    42,    11,    -1,    13,    14,    15,
      16,    17,    18,    19,    20,    21,    22,    23,    24,    25,
      26,    27,    28,    29,    30,    31,    32,    33,    34,    35,
      36,    37,    38,    39,    40,    41,    42,     7,     8,    -1,
      10,    -1,    12,    -1,    -1,    -1,     7,    -1,    -1,    10,
      -1,    12,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    29,
      30,    -1,    32,    33,    -1,    -1,    36,    37,    29,    30,
      -1,    32,    33,    -1,    -1,    36,    37,    13,    14,    15,
      16,    17,    18,    19,    20,    21,    22,    23,    24,    25,
      26,    27,    28,    29,    30,    31,    32,    33,    34,    35,
      36,    37,    38,    39,    40,    41,    42,   101,    -1,    -1,
      -1,    10,    -1,    12,    -1,    -1,    -1,    -1,    -1,   113,
     114,   115,   116,    -1,    -1,   119,   120,   121,    -1,    -1,
      29,    30,   126,    32,    33,   129,    -1,    36,    37,   107,
      -1,   109,   110,   111,   112,   113,   114,   115,   116,   117,
     118,    -1,   120,   121,   122,   123,   124,    -1,   126,    -1,
      -1,    -1,    -1,    -1,   107,   133,   109,   110,   111,   112,
     113,   114,   115,   116,   117,   118,    -1,   120,   121,   122,
     123,   124,    -1,   126,    -1,    -1,    -1,    -1,    -1,    -1,
     133,    17,    18,    19,    20,    21,    22,    23,    24,    25,
      26,    27,    28,    29,    30,    31,    32,    33,    34,    35,
      36,    37,    38,    39,    40,    41,    42,    17,    18,    19,
      20,    21,    22,    23,    24,    25,    26,    27,    28,    29,
      30,    31,    32,    33,    34,    35,    36,    37,    38,    39,
      40,    41,    42,    12,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      29,    30,    -1,    32,    33,    -1,    -1,    36,    37,   107,
      -1,   109,   110,   111,   112,   113,   114,   115,   116,   117,
     118,    -1,   120,   121,   122,   123,   124,   107,   126,   109,
     110,   111,   112,   113,   114,   115,   116,   117,   118,    -1,
     120,   121,   122,   123,   124,   107,   126,   109,   110,   111,
     112,   113,   114,   115,   116,   117,   118,    -1,   120,   121,
     122,   123,   124,    -1,   126
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,    68,   138,   141,    76,     0,     1,    68,    69,    70,
      77,   107,   126,   135,   139,   140,   142,   143,   144,   145,
     146,   149,   150,   151,   152,   155,   156,   157,   158,   159,
     160,   161,   162,   165,   167,   168,   169,   128,     8,   127,
      71,    78,    80,    93,   100,   103,   109,    90,    91,    92,
     107,   107,   126,   163,   135,   135,     8,   107,   109,   110,
     111,   112,   113,   114,   115,   116,   117,   118,   120,   121,
     122,   123,   124,   126,   147,   207,     8,   107,   148,   207,
       8,    72,    74,    87,    88,    68,   127,   139,   140,   134,
       9,    94,   104,   107,   108,   136,   194,     9,    94,   107,
     108,   136,   194,    85,    86,   107,   207,   128,   107,   207,
     107,   132,   197,   117,   107,   153,   154,    89,   113,   115,
     132,   201,   201,   201,   129,   135,   128,    81,    83,    84,
     128,   128,    81,    82,    83,    84,   128,   128,   128,   128,
     181,   182,   101,   113,   114,   115,   116,   119,   120,   121,
     126,   129,   171,   172,   173,   174,   175,   192,   104,   171,
       8,     8,   105,   129,   107,   198,     8,   128,     8,   154,
     128,   113,   115,   202,   132,   199,    33,   105,   132,   195,
     117,   132,   203,   107,   206,   164,   171,   129,   129,   129,
     129,    73,    75,   105,   105,   127,    11,    17,    36,    63,
      64,    65,    66,    67,    95,    96,    97,    98,    99,   105,
     107,   112,   117,   118,   119,   121,   122,   123,   124,   126,
     183,   185,   187,   188,   189,   190,   193,   173,   128,   171,
       6,     8,    11,   132,   176,   101,    14,    17,    18,    19,
      20,   128,   176,     8,   105,   107,   133,   207,   117,    63,
     105,   107,   113,   115,   133,   107,   200,   207,     8,   105,
      33,   105,   107,   196,     8,   107,   117,   204,     8,   130,
     131,   176,   105,   105,   105,   105,   107,   126,   135,   187,
     193,   107,   125,   132,   135,    63,   105,   107,   121,   122,
     123,   132,   186,   190,   132,   186,     8,   132,    33,    35,
      43,    44,    45,    46,    48,    49,    50,    51,    52,    53,
      54,    55,    56,    57,    58,    59,    60,    61,    62,   112,
     118,   129,   184,   185,   187,   193,   107,   193,   129,   187,
      11,   105,   107,   126,   185,   191,   193,   121,   135,   128,
     135,   129,   128,   129,   184,   129,   135,   128,   132,    33,
      44,   106,   129,   170,   192,   193,   130,   171,   171,   171,
     177,    79,   134,   166,   170,   170,   170,   170,   170,   170,
     166,   130,   132,    87,   107,   133,   207,   105,    33,   105,
     107,   133,   107,   117,   133,   107,   134,   131,   131,   131,
     131,   105,    18,    18,   109,   105,   132,   184,     8,   184,
       8,   184,   184,   184,   184,   184,   129,   129,   129,   129,
     129,   129,   129,   129,   129,   129,   129,   129,   129,   129,
     129,   129,   129,   129,   184,     3,     4,     5,     6,     9,
      11,    13,    14,    15,    16,    17,    18,    19,    20,    21,
      22,    23,    24,    25,    26,    27,    28,    29,    30,    31,
      32,    33,    34,    35,    36,    37,    38,    39,    40,    41,
      42,    64,   184,   129,   132,   135,     8,   128,   135,   128,
     105,   131,   135,   187,   135,   107,   126,   189,   193,     8,
       8,   105,   184,   105,   184,   205,   184,   205,   128,   105,
     105,   184,   105,   170,   170,   170,     7,    10,    12,    29,
      30,    32,    33,    36,    37,   102,   107,   115,   121,   133,
     179,   180,   181,    76,   105,   128,   105,   105,   105,   105,
     105,   187,   133,   109,   133,   133,   133,   184,   184,   184,
     184,   184,   184,   184,   184,   184,   184,   184,   184,   184,
     184,   205,   184,   184,   205,   130,   184,   184,   184,   184,
     184,   184,   184,   184,   184,   184,   184,   184,   184,   184,
     184,   184,   184,   184,   184,   184,   184,   184,   184,   184,
     184,   184,   184,   184,   184,   184,   184,   184,   184,   184,
     184,   184,   186,   188,   105,   105,   184,   105,   130,   107,
     110,   105,   105,     8,     8,   128,   130,   131,     8,   130,
     184,   130,   128,     8,   131,   130,   170,   170,   170,   170,
     170,   170,   170,   170,   170,   129,   128,   128,   182,    29,
     127,   178,   128,   131,   105,   130,   130,   130,   130,   135,
     133,     8,     8,     8,   130,   131,   130,   131,   131,   130,
     130,   130,   130,   130,   130,   130,   130,   130,   130,   130,
     131,   130,   130,     8,   130,   131,     8,     8,   128,     8,
       8,     8,   187,   184,     8,   184,     8,     8,   105,   192,
     193,   170,   170,   127,   178,   107,   110,    85,    86,   105,
     197,   105,   184,   184,   184,   184,   105,   184,     8,   133,
     131,   131,     8,     8,    30,    30,   133,     8,   130,   130,
     130,   130,   133,     8,   128,   115,   115,   184,   130,   130,
       8,     8,     8
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,   137,   138,   138,   138,   138,   139,   139,   139,   139,
     139,   139,   139,   139,   139,   139,   140,   140,   140,   140,
     141,   141,   142,   143,   144,   144,   144,   144,   144,   145,
     146,   146,   147,   147,   147,   147,   147,   148,   148,   148,
     148,   148,   148,   149,   150,   150,   150,   150,   150,   150,
     150,   151,   151,   152,   153,   153,   154,   155,   156,   157,
     158,   159,   160,   161,   161,   161,   162,   163,   163,   163,
     164,   164,   165,   166,   166,   166,   167,   167,   168,   168,
     168,   168,   168,   168,   168,   168,   168,   169,   169,   169,
     169,   170,   170,   170,   170,   170,   170,   170,   170,   170,
     170,   170,   170,   170,   170,   170,   171,   171,   171,   171,
     172,   172,   173,   173,   174,   174,   175,   175,   175,   175,
     175,   175,   175,   175,   175,   175,   175,   176,   176,   177,
     177,   177,   177,   177,   177,   178,   178,   179,   180,   180,
     181,   181,   181,   181,   181,   182,   182,   182,   182,   183,
     183,   183,   183,   183,   183,   183,   183,   183,   183,   183,
     183,   183,   183,   183,   183,   183,   183,   183,   183,   183,
     183,   183,   183,   183,   184,   184,   184,   184,   184,   184,
     184,   184,   184,   184,   184,   184,   184,   184,   184,   184,
     184,   184,   184,   184,   184,   184,   184,   184,   184,   184,
     184,   184,   184,   184,   184,   184,   184,   184,   184,   184,
     184,   184,   184,   184,   184,   184,   184,   184,   184,   184,
     184,   184,   184,   184,   184,   184,   184,   184,   184,   184,
     184,   184,   184,   184,   184,   184,   184,   184,   184,   184,
     185,   185,   185,   185,   186,   186,   186,   186,   186,   186,
     186,   186,   187,   187,   187,   187,   188,   188,   188,   188,
     188,   189,   189,   189,   190,   190,   191,   191,   191,   191,
     191,   191,   192,   192,   192,   192,   192,   193,   193,   193,
     193,   193,   194,   194,   195,   195,   195,   196,   196,   196,
     196,   196,   196,   197,   197,   198,   198,   198,   199,   200,
     200,   200,   200,   201,   201,   201,   202,   202,   202,   202,
     202,   203,   203,   204,   204,   204,   204,   205,   205,   205,
     206,   206,   206,   207,   207,   207,   207,   207,   207,   207,
     207,   207,   207,   207,   207,   207,   207,   207,   207
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     1,     2,     2,     2,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     2,     1,     1,     1,     2,
       5,     5,     5,     2,     6,     9,     9,     2,     3,     2,
       3,     2,     7,     7,     2,     2,     2,     7,     7,     2,
       2,     2,     2,     2,     3,     3,     4,     4,     4,     4,
       2,    10,     5,     4,     1,     2,     8,     4,     5,     5,
       5,     4,     6,     1,     2,     2,     2,     0,     1,     1,
       0,     1,     5,     3,     4,     1,     5,     5,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     1,
       2,     1,     1,     1,     3,     3,     3,     3,     3,     3,
       3,     3,     3,     3,     2,     2,     1,     3,     3,     3,
       2,     1,     2,     1,     1,     3,     3,     3,     3,     3,
       3,     3,     3,     1,     1,     1,     1,     0,     3,     0,
       5,     8,     8,     5,     2,     3,     3,     2,     1,     3,
       1,     4,     5,     3,     4,     0,     2,     4,     6,     4,
       5,     4,     7,     6,     3,     5,     5,     9,     4,     4,
       4,     3,     5,     5,     5,     3,     5,     5,     3,     5,
       2,     5,     5,     1,     1,     2,     3,     3,     3,     3,
       3,     3,     3,     3,     3,     3,     3,     3,     3,     2,
       2,     3,     3,     3,     3,     3,     3,     3,     3,     3,
       3,     3,     2,     3,     3,     3,     3,     3,     3,     3,
       3,     3,     3,     3,     3,     3,     2,     4,     4,     4,
       4,     6,     6,     6,     4,     4,     4,     4,     4,     4,
       4,     4,     6,     4,     4,     3,     6,     1,     4,     4,
       6,     4,     3,     1,     1,     1,     1,     1,     1,     4,
       1,     1,     1,     1,     1,     1,     1,     1,     3,     2,
       4,     1,     1,     1,     3,     3,     1,     2,     4,     3,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     2,     3,     1,     2,     1,     2,     1,
       2,     3,     2,     3,     1,     1,     2,     2,     3,     1,
       1,     2,     2,     3,     1,     1,     1,     1,     2,     2,
       2,     3,     1,     1,     1,     2,     2,     0,     1,     3,
       0,     1,     3,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1
};


#define yyerrok         (yyerrstatus = 0)
#define yyclearin       (yychar = YYEMPTY)
#define YYEMPTY         (-2)
#define YYEOF           0

#define YYACCEPT        goto yyacceptlab
#define YYABORT         goto yyabortlab
#define YYERROR         goto yyerrorlab


#define YYRECOVERING()  (!!yyerrstatus)

#define YYBACKUP(Token, Value)                                    \
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


/*-----------------------------------.
| Print this symbol's value on YYO.  |
`-----------------------------------*/

static void
yy_symbol_value_print (FILE *yyo, int yytype, YYSTYPE const * const yyvaluep)
{
  FILE *yyoutput = yyo;
  YYUSE (yyoutput);
  if (!yyvaluep)
    return;
# ifdef YYPRINT
  if (yytype < YYNTOKENS)
    YYPRINT (yyo, yytoknum[yytype], *yyvaluep);
# endif
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YYUSE (yytype);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}


/*---------------------------.
| Print this symbol on YYO.  |
`---------------------------*/

static void
yy_symbol_print (FILE *yyo, int yytype, YYSTYPE const * const yyvaluep)
{
  YYFPRINTF (yyo, "%s %s (",
             yytype < YYNTOKENS ? "token" : "nterm", yytname[yytype]);

  yy_symbol_value_print (yyo, yytype, yyvaluep);
  YYFPRINTF (yyo, ")");
}

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

static void
yy_stack_print (yy_state_t *yybottom, yy_state_t *yytop)
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
yy_reduce_print (yy_state_t *yyssp, YYSTYPE *yyvsp, int yyrule)
{
  int yylno = yyrline[yyrule];
  int yynrhs = yyr2[yyrule];
  int yyi;
  YYFPRINTF (stderr, "Reducing stack by rule %d (line %d):\n",
             yyrule - 1, yylno);
  /* The symbols being reduced.  */
  for (yyi = 0; yyi < yynrhs; yyi++)
    {
      YYFPRINTF (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr,
                       yystos[+yyssp[yyi + 1 - yynrhs]],
                       &yyvsp[(yyi + 1) - (yynrhs)]
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
#   define yystrlen(S) (YY_CAST (YYPTRDIFF_T, strlen (S)))
#  else
/* Return the length of YYSTR.  */
static YYPTRDIFF_T
yystrlen (const char *yystr)
{
  YYPTRDIFF_T yylen;
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
static YYPTRDIFF_T
yytnamerr (char *yyres, const char *yystr)
{
  if (*yystr == '"')
    {
      YYPTRDIFF_T yyn = 0;
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
            else
              goto append;

          append:
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

  if (yyres)
    return yystpcpy (yyres, yystr) - yyres;
  else
    return yystrlen (yystr);
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
yysyntax_error (YYPTRDIFF_T *yymsg_alloc, char **yymsg,
                yy_state_t *yyssp, int yytoken)
{
  enum { YYERROR_VERBOSE_ARGS_MAXIMUM = 5 };
  /* Internationalized format string. */
  const char *yyformat = YY_NULLPTR;
  /* Arguments of yyformat: reported tokens (one for the "unexpected",
     one per "expected"). */
  char const *yyarg[YYERROR_VERBOSE_ARGS_MAXIMUM];
  /* Actual size of YYARG. */
  int yycount = 0;
  /* Cumulated lengths of YYARG.  */
  YYPTRDIFF_T yysize = 0;

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
      int yyn = yypact[+*yyssp];
      YYPTRDIFF_T yysize0 = yytnamerr (YY_NULLPTR, yytname[yytoken]);
      yysize = yysize0;
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
                  YYPTRDIFF_T yysize1
                    = yysize + yytnamerr (YY_NULLPTR, yytname[yyx]);
                  if (yysize <= yysize1 && yysize1 <= YYSTACK_ALLOC_MAXIMUM)
                    yysize = yysize1;
                  else
                    return 2;
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
    default: /* Avoid compiler warnings. */
      YYCASE_(0, YY_("syntax error"));
      YYCASE_(1, YY_("syntax error, unexpected %s"));
      YYCASE_(2, YY_("syntax error, unexpected %s, expecting %s"));
      YYCASE_(3, YY_("syntax error, unexpected %s, expecting %s or %s"));
      YYCASE_(4, YY_("syntax error, unexpected %s, expecting %s or %s or %s"));
      YYCASE_(5, YY_("syntax error, unexpected %s, expecting %s or %s or %s or %s"));
# undef YYCASE_
    }

  {
    /* Don't count the "%s"s in the final size, but reserve room for
       the terminator.  */
    YYPTRDIFF_T yysize1 = yysize + (yystrlen (yyformat) - 2 * yycount) + 1;
    if (yysize <= yysize1 && yysize1 <= YYSTACK_ALLOC_MAXIMUM)
      yysize = yysize1;
    else
      return 2;
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
          ++yyp;
          ++yyformat;
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
    yy_state_fast_t yystate;
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus;

    /* The stacks and their tools:
       'yyss': related to states.
       'yyvs': related to semantic values.

       Refer to the stacks through separate pointers, to allow yyoverflow
       to reallocate them elsewhere.  */

    /* The state stack.  */
    yy_state_t yyssa[YYINITDEPTH];
    yy_state_t *yyss;
    yy_state_t *yyssp;

    /* The semantic value stack.  */
    YYSTYPE yyvsa[YYINITDEPTH];
    YYSTYPE *yyvs;
    YYSTYPE *yyvsp;

    YYPTRDIFF_T yystacksize;

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
  YYPTRDIFF_T yymsg_alloc = sizeof yymsgbuf;
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
| yynewstate -- push a new state, which is found in yystate.  |
`------------------------------------------------------------*/
yynewstate:
  /* In all cases, when you get here, the value and location stacks
     have just been pushed.  So pushing a state here evens the stacks.  */
  yyssp++;


/*--------------------------------------------------------------------.
| yysetstate -- set current state (the top of the stack) to yystate.  |
`--------------------------------------------------------------------*/
yysetstate:
  YYDPRINTF ((stderr, "Entering state %d\n", yystate));
  YY_ASSERT (0 <= yystate && yystate < YYNSTATES);
  YY_IGNORE_USELESS_CAST_BEGIN
  *yyssp = YY_CAST (yy_state_t, yystate);
  YY_IGNORE_USELESS_CAST_END

  if (yyss + yystacksize - 1 <= yyssp)
#if !defined yyoverflow && !defined YYSTACK_RELOCATE
    goto yyexhaustedlab;
#else
    {
      /* Get the current used size of the three stacks, in elements.  */
      YYPTRDIFF_T yysize = yyssp - yyss + 1;

# if defined yyoverflow
      {
        /* Give user a chance to reallocate the stack.  Use copies of
           these so that the &'s don't force the real ones into
           memory.  */
        yy_state_t *yyss1 = yyss;
        YYSTYPE *yyvs1 = yyvs;

        /* Each stack pointer address is followed by the size of the
           data in use in that stack, in bytes.  This used to be a
           conditional around just the two extra args, but that might
           be undefined if yyoverflow is a macro.  */
        yyoverflow (YY_("memory exhausted"),
                    &yyss1, yysize * YYSIZEOF (*yyssp),
                    &yyvs1, yysize * YYSIZEOF (*yyvsp),
                    &yystacksize);
        yyss = yyss1;
        yyvs = yyvs1;
      }
# else /* defined YYSTACK_RELOCATE */
      /* Extend the stack our own way.  */
      if (YYMAXDEPTH <= yystacksize)
        goto yyexhaustedlab;
      yystacksize *= 2;
      if (YYMAXDEPTH < yystacksize)
        yystacksize = YYMAXDEPTH;

      {
        yy_state_t *yyss1 = yyss;
        union yyalloc *yyptr =
          YY_CAST (union yyalloc *,
                   YYSTACK_ALLOC (YY_CAST (YYSIZE_T, YYSTACK_BYTES (yystacksize))));
        if (! yyptr)
          goto yyexhaustedlab;
        YYSTACK_RELOCATE (yyss_alloc, yyss);
        YYSTACK_RELOCATE (yyvs_alloc, yyvs);
# undef YYSTACK_RELOCATE
        if (yyss1 != yyssa)
          YYSTACK_FREE (yyss1);
      }
# endif

      yyssp = yyss + yysize - 1;
      yyvsp = yyvs + yysize - 1;

      YY_IGNORE_USELESS_CAST_BEGIN
      YYDPRINTF ((stderr, "Stack size increased to %ld\n",
                  YY_CAST (long, yystacksize)));
      YY_IGNORE_USELESS_CAST_END

      if (yyss + yystacksize - 1 <= yyssp)
        YYABORT;
    }
#endif /* !defined yyoverflow && !defined YYSTACK_RELOCATE */

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
  yystate = yyn;
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END

  /* Discard the shifted token.  */
  yychar = YYEMPTY;
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
| yyreduce -- do a reduction.  |
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
  case 19:
#line 175 "/home/jnstaursky/Desktop/Personal-Projects/coronium/parse/slghparse.y"
                                       { slgh->resetConstructors(); }
#line 2372 "/home/jnstaursky/Desktop/Personal-Projects/coronium/src/slghparse.cc"
    break;

  case 20:
#line 177 "/home/jnstaursky/Desktop/Personal-Projects/coronium/parse/slghparse.y"
                                                 { slgh->setEndian(1); }
#line 2378 "/home/jnstaursky/Desktop/Personal-Projects/coronium/src/slghparse.cc"
    break;

  case 21:
#line 178 "/home/jnstaursky/Desktop/Personal-Projects/coronium/parse/slghparse.y"
                                             { slgh->setEndian(0); }
#line 2384 "/home/jnstaursky/Desktop/Personal-Projects/coronium/src/slghparse.cc"
    break;

  case 22:
#line 180 "/home/jnstaursky/Desktop/Personal-Projects/coronium/parse/slghparse.y"
                                               { slgh->setAlignment(*(yyvsp[-1].i)); delete (yyvsp[-1].i); }
#line 2390 "/home/jnstaursky/Desktop/Personal-Projects/coronium/src/slghparse.cc"
    break;

  case 23:
#line 182 "/home/jnstaursky/Desktop/Personal-Projects/coronium/parse/slghparse.y"
                                       {}
#line 2396 "/home/jnstaursky/Desktop/Personal-Projects/coronium/src/slghparse.cc"
    break;

  case 24:
#line 184 "/home/jnstaursky/Desktop/Personal-Projects/coronium/parse/slghparse.y"
                                                       { (yyval.tokensym) = slgh->defineToken((yyvsp[-3].str),(yyvsp[-1].i),0); }
#line 2402 "/home/jnstaursky/Desktop/Personal-Projects/coronium/src/slghparse.cc"
    break;

  case 25:
#line 185 "/home/jnstaursky/Desktop/Personal-Projects/coronium/parse/slghparse.y"
                                                                          { (yyval.tokensym) = slgh->defineToken((yyvsp[-6].str),(yyvsp[-4].i),-1); }
#line 2408 "/home/jnstaursky/Desktop/Personal-Projects/coronium/src/slghparse.cc"
    break;

  case 26:
#line 186 "/home/jnstaursky/Desktop/Personal-Projects/coronium/parse/slghparse.y"
                                                                       { (yyval.tokensym) = slgh->defineToken((yyvsp[-6].str),(yyvsp[-4].i),1); }
#line 2414 "/home/jnstaursky/Desktop/Personal-Projects/coronium/src/slghparse.cc"
    break;

  case 27:
#line 187 "/home/jnstaursky/Desktop/Personal-Projects/coronium/parse/slghparse.y"
                                       { (yyval.tokensym) = (yyvsp[-1].tokensym); slgh->addTokenField((yyvsp[-1].tokensym),(yyvsp[0].fieldqual)); }
#line 2420 "/home/jnstaursky/Desktop/Personal-Projects/coronium/src/slghparse.cc"
    break;

  case 28:
#line 188 "/home/jnstaursky/Desktop/Personal-Projects/coronium/parse/slghparse.y"
                                       { string errmsg=(yyvsp[0].anysym)->getName()+": redefined as a token"; yyerror(errmsg.c_str()); YYERROR; }
#line 2426 "/home/jnstaursky/Desktop/Personal-Projects/coronium/src/slghparse.cc"
    break;

  case 29:
#line 190 "/home/jnstaursky/Desktop/Personal-Projects/coronium/parse/slghparse.y"
                                       {}
#line 2432 "/home/jnstaursky/Desktop/Personal-Projects/coronium/src/slghparse.cc"
    break;

  case 30:
#line 192 "/home/jnstaursky/Desktop/Personal-Projects/coronium/parse/slghparse.y"
                                           { (yyval.varsym) = (yyvsp[0].varsym); }
#line 2438 "/home/jnstaursky/Desktop/Personal-Projects/coronium/src/slghparse.cc"
    break;

  case 31:
#line 193 "/home/jnstaursky/Desktop/Personal-Projects/coronium/parse/slghparse.y"
                                         { (yyval.varsym) = (yyvsp[-1].varsym); if (!slgh->addContextField( (yyvsp[-1].varsym), (yyvsp[0].fieldqual) ))
                                            { yyerror("All context definitions must come before constructors"); YYERROR; } }
#line 2445 "/home/jnstaursky/Desktop/Personal-Projects/coronium/src/slghparse.cc"
    break;

  case 32:
#line 196 "/home/jnstaursky/Desktop/Personal-Projects/coronium/parse/slghparse.y"
                                                 { (yyval.fieldqual) = new FieldQuality((yyvsp[-6].str),(yyvsp[-3].i),(yyvsp[-1].i)); }
#line 2451 "/home/jnstaursky/Desktop/Personal-Projects/coronium/src/slghparse.cc"
    break;

  case 33:
#line 197 "/home/jnstaursky/Desktop/Personal-Projects/coronium/parse/slghparse.y"
                                              { delete (yyvsp[-3].i); delete (yyvsp[-1].i); string errmsg = (yyvsp[-6].anysym)->getName()+": redefined as field"; yyerror(errmsg.c_str()); YYERROR; }
#line 2457 "/home/jnstaursky/Desktop/Personal-Projects/coronium/src/slghparse.cc"
    break;

  case 34:
#line 198 "/home/jnstaursky/Desktop/Personal-Projects/coronium/parse/slghparse.y"
                                        { (yyval.fieldqual) = (yyvsp[-1].fieldqual); (yyval.fieldqual)->signext = true; }
#line 2463 "/home/jnstaursky/Desktop/Personal-Projects/coronium/src/slghparse.cc"
    break;

  case 35:
#line 199 "/home/jnstaursky/Desktop/Personal-Projects/coronium/parse/slghparse.y"
                                        { (yyval.fieldqual) = (yyvsp[-1].fieldqual); (yyval.fieldqual)->hex = true; }
#line 2469 "/home/jnstaursky/Desktop/Personal-Projects/coronium/src/slghparse.cc"
    break;

  case 36:
#line 200 "/home/jnstaursky/Desktop/Personal-Projects/coronium/parse/slghparse.y"
                                        { (yyval.fieldqual) = (yyvsp[-1].fieldqual); (yyval.fieldqual)->hex = false; }
#line 2475 "/home/jnstaursky/Desktop/Personal-Projects/coronium/src/slghparse.cc"
    break;

  case 37:
#line 202 "/home/jnstaursky/Desktop/Personal-Projects/coronium/parse/slghparse.y"
                                                        { (yyval.fieldqual) = new FieldQuality((yyvsp[-6].str),(yyvsp[-3].i),(yyvsp[-1].i)); }
#line 2481 "/home/jnstaursky/Desktop/Personal-Projects/coronium/src/slghparse.cc"
    break;

  case 38:
#line 203 "/home/jnstaursky/Desktop/Personal-Projects/coronium/parse/slghparse.y"
                                              { delete (yyvsp[-3].i); delete (yyvsp[-1].i); string errmsg = (yyvsp[-6].anysym)->getName()+": redefined as field"; yyerror(errmsg.c_str()); YYERROR; }
#line 2487 "/home/jnstaursky/Desktop/Personal-Projects/coronium/src/slghparse.cc"
    break;

  case 39:
#line 204 "/home/jnstaursky/Desktop/Personal-Projects/coronium/parse/slghparse.y"
                                                { (yyval.fieldqual) = (yyvsp[-1].fieldqual); (yyval.fieldqual)->signext = true; }
#line 2493 "/home/jnstaursky/Desktop/Personal-Projects/coronium/src/slghparse.cc"
    break;

  case 40:
#line 205 "/home/jnstaursky/Desktop/Personal-Projects/coronium/parse/slghparse.y"
                                                { (yyval.fieldqual) = (yyvsp[-1].fieldqual); (yyval.fieldqual)->flow = false; }
#line 2499 "/home/jnstaursky/Desktop/Personal-Projects/coronium/src/slghparse.cc"
    break;

  case 41:
#line 206 "/home/jnstaursky/Desktop/Personal-Projects/coronium/parse/slghparse.y"
                                                { (yyval.fieldqual) = (yyvsp[-1].fieldqual); (yyval.fieldqual)->hex = true; }
#line 2505 "/home/jnstaursky/Desktop/Personal-Projects/coronium/src/slghparse.cc"
    break;

  case 42:
#line 207 "/home/jnstaursky/Desktop/Personal-Projects/coronium/parse/slghparse.y"
                                                { (yyval.fieldqual) = (yyvsp[-1].fieldqual); (yyval.fieldqual)->hex = false; }
#line 2511 "/home/jnstaursky/Desktop/Personal-Projects/coronium/src/slghparse.cc"
    break;

  case 43:
#line 209 "/home/jnstaursky/Desktop/Personal-Projects/coronium/parse/slghparse.y"
                                        { slgh->newSpace((yyvsp[-1].spacequal)); }
#line 2517 "/home/jnstaursky/Desktop/Personal-Projects/coronium/src/slghparse.cc"
    break;

  case 44:
#line 211 "/home/jnstaursky/Desktop/Personal-Projects/coronium/parse/slghparse.y"
                                        { (yyval.spacequal) = new SpaceQuality(*(yyvsp[0].str)); delete (yyvsp[0].str); }
#line 2523 "/home/jnstaursky/Desktop/Personal-Projects/coronium/src/slghparse.cc"
    break;

  case 45:
#line 212 "/home/jnstaursky/Desktop/Personal-Projects/coronium/parse/slghparse.y"
                                        { string errmsg = (yyvsp[0].anysym)->getName()+": redefined as space"; yyerror(errmsg.c_str()); YYERROR; }
#line 2529 "/home/jnstaursky/Desktop/Personal-Projects/coronium/src/slghparse.cc"
    break;

  case 46:
#line 213 "/home/jnstaursky/Desktop/Personal-Projects/coronium/parse/slghparse.y"
                                        { (yyval.spacequal) = (yyvsp[-3].spacequal); (yyval.spacequal)->type = SpaceQuality::ramtype; }
#line 2535 "/home/jnstaursky/Desktop/Personal-Projects/coronium/src/slghparse.cc"
    break;

  case 47:
#line 214 "/home/jnstaursky/Desktop/Personal-Projects/coronium/parse/slghparse.y"
                                        { (yyval.spacequal) = (yyvsp[-3].spacequal); (yyval.spacequal)->type = SpaceQuality::registertype; }
#line 2541 "/home/jnstaursky/Desktop/Personal-Projects/coronium/src/slghparse.cc"
    break;

  case 48:
#line 215 "/home/jnstaursky/Desktop/Personal-Projects/coronium/parse/slghparse.y"
                                        { (yyval.spacequal) = (yyvsp[-3].spacequal); (yyval.spacequal)->size = *(yyvsp[0].i); delete (yyvsp[0].i); }
#line 2547 "/home/jnstaursky/Desktop/Personal-Projects/coronium/src/slghparse.cc"
    break;

  case 49:
#line 216 "/home/jnstaursky/Desktop/Personal-Projects/coronium/parse/slghparse.y"
                                        { (yyval.spacequal) = (yyvsp[-3].spacequal); (yyval.spacequal)->wordsize = *(yyvsp[0].i); delete (yyvsp[0].i); }
#line 2553 "/home/jnstaursky/Desktop/Personal-Projects/coronium/src/slghparse.cc"
    break;

  case 50:
#line 217 "/home/jnstaursky/Desktop/Personal-Projects/coronium/parse/slghparse.y"
                                        { (yyval.spacequal) = (yyvsp[-1].spacequal); (yyval.spacequal)->isdefault = true; }
#line 2559 "/home/jnstaursky/Desktop/Personal-Projects/coronium/src/slghparse.cc"
    break;

  case 51:
#line 219 "/home/jnstaursky/Desktop/Personal-Projects/coronium/parse/slghparse.y"
                                                                                           {
               slgh->defineVarnodes((yyvsp[-8].spacesym),(yyvsp[-5].i),(yyvsp[-2].i),(yyvsp[-1].strlist)); }
#line 2566 "/home/jnstaursky/Desktop/Personal-Projects/coronium/src/slghparse.cc"
    break;

  case 52:
#line 221 "/home/jnstaursky/Desktop/Personal-Projects/coronium/parse/slghparse.y"
                                                  { yyerror("Parsed integer is too big (overflow)"); YYERROR; }
#line 2572 "/home/jnstaursky/Desktop/Personal-Projects/coronium/src/slghparse.cc"
    break;

  case 56:
#line 228 "/home/jnstaursky/Desktop/Personal-Projects/coronium/parse/slghparse.y"
                                                              {
               slgh->defineBitrange((yyvsp[-7].str),(yyvsp[-5].varsym),(uint4)*(yyvsp[-3].i),(uint4)*(yyvsp[-1].i)); delete (yyvsp[-3].i); delete (yyvsp[-1].i); }
#line 2579 "/home/jnstaursky/Desktop/Personal-Projects/coronium/src/slghparse.cc"
    break;

  case 57:
#line 231 "/home/jnstaursky/Desktop/Personal-Projects/coronium/parse/slghparse.y"
                                                  { slgh->addUserOp((yyvsp[-1].strlist)); }
#line 2585 "/home/jnstaursky/Desktop/Personal-Projects/coronium/src/slghparse.cc"
    break;

  case 58:
#line 233 "/home/jnstaursky/Desktop/Personal-Projects/coronium/parse/slghparse.y"
                                                          { slgh->attachValues((yyvsp[-2].symlist),(yyvsp[-1].biglist)); }
#line 2591 "/home/jnstaursky/Desktop/Personal-Projects/coronium/src/slghparse.cc"
    break;

  case 59:
#line 235 "/home/jnstaursky/Desktop/Personal-Projects/coronium/parse/slghparse.y"
                                                             { slgh->attachNames((yyvsp[-2].symlist),(yyvsp[-1].strlist)); }
#line 2597 "/home/jnstaursky/Desktop/Personal-Projects/coronium/src/slghparse.cc"
    break;

  case 60:
#line 237 "/home/jnstaursky/Desktop/Personal-Projects/coronium/parse/slghparse.y"
                                                          { slgh->attachVarnodes((yyvsp[-2].symlist),(yyvsp[-1].symlist)); }
#line 2603 "/home/jnstaursky/Desktop/Personal-Projects/coronium/src/slghparse.cc"
    break;

  case 61:
#line 239 "/home/jnstaursky/Desktop/Personal-Projects/coronium/parse/slghparse.y"
                                        { slgh->buildMacro((yyvsp[-3].macrosym),(yyvsp[-1].sem)); }
#line 2609 "/home/jnstaursky/Desktop/Personal-Projects/coronium/src/slghparse.cc"
    break;

  case 62:
#line 242 "/home/jnstaursky/Desktop/Personal-Projects/coronium/parse/slghparse.y"
                                                                       {  slgh->pushWith((yyvsp[-4].subtablesym),(yyvsp[-2].pateq),(yyvsp[-1].contop)); }
#line 2615 "/home/jnstaursky/Desktop/Personal-Projects/coronium/src/slghparse.cc"
    break;

  case 66:
#line 248 "/home/jnstaursky/Desktop/Personal-Projects/coronium/parse/slghparse.y"
                             { slgh->popWith(); }
#line 2621 "/home/jnstaursky/Desktop/Personal-Projects/coronium/src/slghparse.cc"
    break;

  case 67:
#line 250 "/home/jnstaursky/Desktop/Personal-Projects/coronium/parse/slghparse.y"
                        { (yyval.subtablesym) = (SubtableSymbol *)0; }
#line 2627 "/home/jnstaursky/Desktop/Personal-Projects/coronium/src/slghparse.cc"
    break;

  case 68:
#line 251 "/home/jnstaursky/Desktop/Personal-Projects/coronium/parse/slghparse.y"
                        { (yyval.subtablesym) = (yyvsp[0].subtablesym); }
#line 2633 "/home/jnstaursky/Desktop/Personal-Projects/coronium/src/slghparse.cc"
    break;

  case 69:
#line 252 "/home/jnstaursky/Desktop/Personal-Projects/coronium/parse/slghparse.y"
                        { (yyval.subtablesym) = slgh->newTable((yyvsp[0].str)); }
#line 2639 "/home/jnstaursky/Desktop/Personal-Projects/coronium/src/slghparse.cc"
    break;

  case 70:
#line 255 "/home/jnstaursky/Desktop/Personal-Projects/coronium/parse/slghparse.y"
                           { (yyval.pateq) = (PatternEquation *)0; }
#line 2645 "/home/jnstaursky/Desktop/Personal-Projects/coronium/src/slghparse.cc"
    break;

  case 71:
#line 256 "/home/jnstaursky/Desktop/Personal-Projects/coronium/parse/slghparse.y"
                           { (yyval.pateq) = (yyvsp[0].pateq); }
#line 2651 "/home/jnstaursky/Desktop/Personal-Projects/coronium/src/slghparse.cc"
    break;

  case 72:
#line 259 "/home/jnstaursky/Desktop/Personal-Projects/coronium/parse/slghparse.y"
                                            { (yyval.macrosym) = slgh->createMacro((yyvsp[-3].str),(yyvsp[-1].strlist)); }
#line 2657 "/home/jnstaursky/Desktop/Personal-Projects/coronium/src/slghparse.cc"
    break;

  case 73:
#line 261 "/home/jnstaursky/Desktop/Personal-Projects/coronium/parse/slghparse.y"
                     { (yyval.sectionstart) = slgh->standaloneSection((yyvsp[-1].sem)); }
#line 2663 "/home/jnstaursky/Desktop/Personal-Projects/coronium/src/slghparse.cc"
    break;

  case 74:
#line 262 "/home/jnstaursky/Desktop/Personal-Projects/coronium/parse/slghparse.y"
                               { (yyval.sectionstart) = slgh->finalNamedSection((yyvsp[-2].sectionstart),(yyvsp[-1].sem)); }
#line 2669 "/home/jnstaursky/Desktop/Personal-Projects/coronium/src/slghparse.cc"
    break;

  case 75:
#line 263 "/home/jnstaursky/Desktop/Personal-Projects/coronium/parse/slghparse.y"
                     { (yyval.sectionstart) = (SectionVector *)0; }
#line 2675 "/home/jnstaursky/Desktop/Personal-Projects/coronium/src/slghparse.cc"
    break;

  case 76:
#line 265 "/home/jnstaursky/Desktop/Personal-Projects/coronium/parse/slghparse.y"
                                                                  { slgh->buildConstructor((yyvsp[-4].construct),(yyvsp[-2].pateq),(yyvsp[-1].contop),(yyvsp[0].sectionstart)); }
#line 2681 "/home/jnstaursky/Desktop/Personal-Projects/coronium/src/slghparse.cc"
    break;

  case 77:
#line 266 "/home/jnstaursky/Desktop/Personal-Projects/coronium/parse/slghparse.y"
                                                                  { slgh->buildConstructor((yyvsp[-4].construct),(yyvsp[-2].pateq),(yyvsp[-1].contop),(yyvsp[0].sectionstart)); }
#line 2687 "/home/jnstaursky/Desktop/Personal-Projects/coronium/src/slghparse.cc"
    break;

  case 78:
#line 268 "/home/jnstaursky/Desktop/Personal-Projects/coronium/parse/slghparse.y"
                                        { (yyval.construct) = (yyvsp[-1].construct); (yyval.construct)->addSyntax(*(yyvsp[0].str)); delete (yyvsp[0].str); }
#line 2693 "/home/jnstaursky/Desktop/Personal-Projects/coronium/src/slghparse.cc"
    break;

  case 79:
#line 269 "/home/jnstaursky/Desktop/Personal-Projects/coronium/parse/slghparse.y"
                                        { (yyval.construct) = (yyvsp[-1].construct); (yyval.construct)->addSyntax(*(yyvsp[0].str)); delete (yyvsp[0].str); }
#line 2699 "/home/jnstaursky/Desktop/Personal-Projects/coronium/src/slghparse.cc"
    break;

  case 80:
#line 270 "/home/jnstaursky/Desktop/Personal-Projects/coronium/parse/slghparse.y"
                                        { (yyval.construct) = (yyvsp[-1].construct); if (slgh->isInRoot((yyvsp[-1].construct))) { (yyval.construct)->addSyntax(*(yyvsp[0].str)); delete (yyvsp[0].str); } else slgh->newOperand((yyvsp[-1].construct),(yyvsp[0].str)); }
#line 2705 "/home/jnstaursky/Desktop/Personal-Projects/coronium/src/slghparse.cc"
    break;

  case 81:
#line 271 "/home/jnstaursky/Desktop/Personal-Projects/coronium/parse/slghparse.y"
                                                { (yyval.construct) = (yyvsp[-1].construct); if (!slgh->isInRoot((yyvsp[-1].construct))) { yyerror("Unexpected '^' at start of print pieces");  YYERROR; } }
#line 2711 "/home/jnstaursky/Desktop/Personal-Projects/coronium/src/slghparse.cc"
    break;

  case 82:
#line 272 "/home/jnstaursky/Desktop/Personal-Projects/coronium/parse/slghparse.y"
                                                { (yyval.construct) = (yyvsp[-1].construct); }
#line 2717 "/home/jnstaursky/Desktop/Personal-Projects/coronium/src/slghparse.cc"
    break;

  case 83:
#line 273 "/home/jnstaursky/Desktop/Personal-Projects/coronium/parse/slghparse.y"
                                                { (yyval.construct) = (yyvsp[-1].construct); (yyval.construct)->addSyntax(*(yyvsp[0].str)); delete (yyvsp[0].str); }
#line 2723 "/home/jnstaursky/Desktop/Personal-Projects/coronium/src/slghparse.cc"
    break;

  case 84:
#line 274 "/home/jnstaursky/Desktop/Personal-Projects/coronium/parse/slghparse.y"
                                        { (yyval.construct) = (yyvsp[-1].construct); (yyval.construct)->addSyntax(*(yyvsp[0].str)); delete (yyvsp[0].str); }
#line 2729 "/home/jnstaursky/Desktop/Personal-Projects/coronium/src/slghparse.cc"
    break;

  case 85:
#line 275 "/home/jnstaursky/Desktop/Personal-Projects/coronium/parse/slghparse.y"
                                                { (yyval.construct) = (yyvsp[-1].construct); (yyval.construct)->addSyntax(string(" ")); }
#line 2735 "/home/jnstaursky/Desktop/Personal-Projects/coronium/src/slghparse.cc"
    break;

  case 86:
#line 276 "/home/jnstaursky/Desktop/Personal-Projects/coronium/parse/slghparse.y"
                                        { (yyval.construct) = (yyvsp[-1].construct); slgh->newOperand((yyvsp[-1].construct),(yyvsp[0].str)); }
#line 2741 "/home/jnstaursky/Desktop/Personal-Projects/coronium/src/slghparse.cc"
    break;

  case 87:
#line 278 "/home/jnstaursky/Desktop/Personal-Projects/coronium/parse/slghparse.y"
                                { (yyval.construct) = slgh->createConstructor((yyvsp[-1].subtablesym)); }
#line 2747 "/home/jnstaursky/Desktop/Personal-Projects/coronium/src/slghparse.cc"
    break;

  case 88:
#line 279 "/home/jnstaursky/Desktop/Personal-Projects/coronium/parse/slghparse.y"
                                                { SubtableSymbol *sym=slgh->newTable((yyvsp[-1].str)); (yyval.construct) = slgh->createConstructor(sym); }
#line 2753 "/home/jnstaursky/Desktop/Personal-Projects/coronium/src/slghparse.cc"
    break;

  case 89:
#line 280 "/home/jnstaursky/Desktop/Personal-Projects/coronium/parse/slghparse.y"
                                                        { (yyval.construct) = slgh->createConstructor((SubtableSymbol *)0); }
#line 2759 "/home/jnstaursky/Desktop/Personal-Projects/coronium/src/slghparse.cc"
    break;

  case 90:
#line 281 "/home/jnstaursky/Desktop/Personal-Projects/coronium/parse/slghparse.y"
                                        { (yyval.construct) = (yyvsp[-1].construct); }
#line 2765 "/home/jnstaursky/Desktop/Personal-Projects/coronium/src/slghparse.cc"
    break;

  case 91:
#line 283 "/home/jnstaursky/Desktop/Personal-Projects/coronium/parse/slghparse.y"
                                        { (yyval.patexp) = new ConstantValue(*(yyvsp[0].big)); delete (yyvsp[0].big); }
#line 2771 "/home/jnstaursky/Desktop/Personal-Projects/coronium/src/slghparse.cc"
    break;

  case 92:
#line 285 "/home/jnstaursky/Desktop/Personal-Projects/coronium/parse/slghparse.y"
                                        { if ((actionon==1)&&((yyvsp[0].famsym)->getType() != SleighSymbol::context_symbol))
                                             { string errmsg="Global symbol "+(yyvsp[0].famsym)->getName(); errmsg += " is not allowed in action expression"; yyerror(errmsg.c_str()); } (yyval.patexp) = (yyvsp[0].famsym)->getPatternValue(); }
#line 2778 "/home/jnstaursky/Desktop/Personal-Projects/coronium/src/slghparse.cc"
    break;

  case 93:
#line 288 "/home/jnstaursky/Desktop/Personal-Projects/coronium/parse/slghparse.y"
                                        { (yyval.patexp) = (yyvsp[0].specsym)->getPatternExpression(); }
#line 2784 "/home/jnstaursky/Desktop/Personal-Projects/coronium/src/slghparse.cc"
    break;

  case 94:
#line 289 "/home/jnstaursky/Desktop/Personal-Projects/coronium/parse/slghparse.y"
                                        { (yyval.patexp) = (yyvsp[-1].patexp); }
#line 2790 "/home/jnstaursky/Desktop/Personal-Projects/coronium/src/slghparse.cc"
    break;

  case 95:
#line 290 "/home/jnstaursky/Desktop/Personal-Projects/coronium/parse/slghparse.y"
                                        { (yyval.patexp) = new PlusExpression((yyvsp[-2].patexp),(yyvsp[0].patexp)); }
#line 2796 "/home/jnstaursky/Desktop/Personal-Projects/coronium/src/slghparse.cc"
    break;

  case 96:
#line 291 "/home/jnstaursky/Desktop/Personal-Projects/coronium/parse/slghparse.y"
                                        { (yyval.patexp) = new SubExpression((yyvsp[-2].patexp),(yyvsp[0].patexp)); }
#line 2802 "/home/jnstaursky/Desktop/Personal-Projects/coronium/src/slghparse.cc"
    break;

  case 97:
#line 292 "/home/jnstaursky/Desktop/Personal-Projects/coronium/parse/slghparse.y"
                                        { (yyval.patexp) = new MultExpression((yyvsp[-2].patexp),(yyvsp[0].patexp)); }
#line 2808 "/home/jnstaursky/Desktop/Personal-Projects/coronium/src/slghparse.cc"
    break;

  case 98:
#line 293 "/home/jnstaursky/Desktop/Personal-Projects/coronium/parse/slghparse.y"
                                        { (yyval.patexp) = new LeftShiftExpression((yyvsp[-2].patexp),(yyvsp[0].patexp)); }
#line 2814 "/home/jnstaursky/Desktop/Personal-Projects/coronium/src/slghparse.cc"
    break;

  case 99:
#line 294 "/home/jnstaursky/Desktop/Personal-Projects/coronium/parse/slghparse.y"
                                        { (yyval.patexp) = new RightShiftExpression((yyvsp[-2].patexp),(yyvsp[0].patexp)); }
#line 2820 "/home/jnstaursky/Desktop/Personal-Projects/coronium/src/slghparse.cc"
    break;

  case 100:
#line 295 "/home/jnstaursky/Desktop/Personal-Projects/coronium/parse/slghparse.y"
                                        { (yyval.patexp) = new AndExpression((yyvsp[-2].patexp),(yyvsp[0].patexp)); }
#line 2826 "/home/jnstaursky/Desktop/Personal-Projects/coronium/src/slghparse.cc"
    break;

  case 101:
#line 296 "/home/jnstaursky/Desktop/Personal-Projects/coronium/parse/slghparse.y"
                                        { (yyval.patexp) = new OrExpression((yyvsp[-2].patexp),(yyvsp[0].patexp)); }
#line 2832 "/home/jnstaursky/Desktop/Personal-Projects/coronium/src/slghparse.cc"
    break;

  case 102:
#line 297 "/home/jnstaursky/Desktop/Personal-Projects/coronium/parse/slghparse.y"
                                        { (yyval.patexp) = new XorExpression((yyvsp[-2].patexp),(yyvsp[0].patexp)); }
#line 2838 "/home/jnstaursky/Desktop/Personal-Projects/coronium/src/slghparse.cc"
    break;

  case 103:
#line 298 "/home/jnstaursky/Desktop/Personal-Projects/coronium/parse/slghparse.y"
                                        { (yyval.patexp) = new DivExpression((yyvsp[-2].patexp),(yyvsp[0].patexp)); }
#line 2844 "/home/jnstaursky/Desktop/Personal-Projects/coronium/src/slghparse.cc"
    break;

  case 104:
#line 299 "/home/jnstaursky/Desktop/Personal-Projects/coronium/parse/slghparse.y"
                                        { (yyval.patexp) = new MinusExpression((yyvsp[0].patexp)); }
#line 2850 "/home/jnstaursky/Desktop/Personal-Projects/coronium/src/slghparse.cc"
    break;

  case 105:
#line 300 "/home/jnstaursky/Desktop/Personal-Projects/coronium/parse/slghparse.y"
                                        { (yyval.patexp) = new NotExpression((yyvsp[0].patexp)); }
#line 2856 "/home/jnstaursky/Desktop/Personal-Projects/coronium/src/slghparse.cc"
    break;

  case 107:
#line 303 "/home/jnstaursky/Desktop/Personal-Projects/coronium/parse/slghparse.y"
                                        { (yyval.pateq) = new EquationAnd((yyvsp[-2].pateq),(yyvsp[0].pateq)); }
#line 2862 "/home/jnstaursky/Desktop/Personal-Projects/coronium/src/slghparse.cc"
    break;

  case 108:
#line 304 "/home/jnstaursky/Desktop/Personal-Projects/coronium/parse/slghparse.y"
                                        { (yyval.pateq) = new EquationOr((yyvsp[-2].pateq),(yyvsp[0].pateq)); }
#line 2868 "/home/jnstaursky/Desktop/Personal-Projects/coronium/src/slghparse.cc"
    break;

  case 109:
#line 305 "/home/jnstaursky/Desktop/Personal-Projects/coronium/parse/slghparse.y"
                                        { (yyval.pateq) = new EquationCat((yyvsp[-2].pateq),(yyvsp[0].pateq)); }
#line 2874 "/home/jnstaursky/Desktop/Personal-Projects/coronium/src/slghparse.cc"
    break;

  case 110:
#line 307 "/home/jnstaursky/Desktop/Personal-Projects/coronium/parse/slghparse.y"
                                        { (yyval.pateq) = new EquationLeftEllipsis((yyvsp[0].pateq)); }
#line 2880 "/home/jnstaursky/Desktop/Personal-Projects/coronium/src/slghparse.cc"
    break;

  case 112:
#line 310 "/home/jnstaursky/Desktop/Personal-Projects/coronium/parse/slghparse.y"
                                        { (yyval.pateq) = new EquationRightEllipsis((yyvsp[-1].pateq)); }
#line 2886 "/home/jnstaursky/Desktop/Personal-Projects/coronium/src/slghparse.cc"
    break;

  case 115:
#line 314 "/home/jnstaursky/Desktop/Personal-Projects/coronium/parse/slghparse.y"
                                        { (yyval.pateq) = (yyvsp[-1].pateq); }
#line 2892 "/home/jnstaursky/Desktop/Personal-Projects/coronium/src/slghparse.cc"
    break;

  case 116:
#line 316 "/home/jnstaursky/Desktop/Personal-Projects/coronium/parse/slghparse.y"
                                         { (yyval.pateq) = new EqualEquation((yyvsp[-2].famsym)->getPatternValue(),(yyvsp[0].patexp)); }
#line 2898 "/home/jnstaursky/Desktop/Personal-Projects/coronium/src/slghparse.cc"
    break;

  case 117:
#line 317 "/home/jnstaursky/Desktop/Personal-Projects/coronium/parse/slghparse.y"
                                         { (yyval.pateq) = new NotEqualEquation((yyvsp[-2].famsym)->getPatternValue(),(yyvsp[0].patexp)); }
#line 2904 "/home/jnstaursky/Desktop/Personal-Projects/coronium/src/slghparse.cc"
    break;

  case 118:
#line 318 "/home/jnstaursky/Desktop/Personal-Projects/coronium/parse/slghparse.y"
                                        { (yyval.pateq) = new LessEquation((yyvsp[-2].famsym)->getPatternValue(),(yyvsp[0].patexp)); }
#line 2910 "/home/jnstaursky/Desktop/Personal-Projects/coronium/src/slghparse.cc"
    break;

  case 119:
#line 319 "/home/jnstaursky/Desktop/Personal-Projects/coronium/parse/slghparse.y"
                                          { (yyval.pateq) = new LessEqualEquation((yyvsp[-2].famsym)->getPatternValue(),(yyvsp[0].patexp)); }
#line 2916 "/home/jnstaursky/Desktop/Personal-Projects/coronium/src/slghparse.cc"
    break;

  case 120:
#line 320 "/home/jnstaursky/Desktop/Personal-Projects/coronium/parse/slghparse.y"
                                        { (yyval.pateq) = new GreaterEquation((yyvsp[-2].famsym)->getPatternValue(),(yyvsp[0].patexp)); }
#line 2922 "/home/jnstaursky/Desktop/Personal-Projects/coronium/src/slghparse.cc"
    break;

  case 121:
#line 321 "/home/jnstaursky/Desktop/Personal-Projects/coronium/parse/slghparse.y"
                                           { (yyval.pateq) = new GreaterEqualEquation((yyvsp[-2].famsym)->getPatternValue(),(yyvsp[0].patexp)); }
#line 2928 "/home/jnstaursky/Desktop/Personal-Projects/coronium/src/slghparse.cc"
    break;

  case 122:
#line 322 "/home/jnstaursky/Desktop/Personal-Projects/coronium/parse/slghparse.y"
                                        { (yyval.pateq) = slgh->constrainOperand((yyvsp[-2].operandsym),(yyvsp[0].patexp)); 
                                          if ((yyval.pateq) == (PatternEquation *)0) 
                                            { string errmsg="Constraining currently undefined operand "+(yyvsp[-2].operandsym)->getName(); yyerror(errmsg.c_str()); } }
#line 2936 "/home/jnstaursky/Desktop/Personal-Projects/coronium/src/slghparse.cc"
    break;

  case 123:
#line 325 "/home/jnstaursky/Desktop/Personal-Projects/coronium/parse/slghparse.y"
                                        { (yyval.pateq) = new OperandEquation((yyvsp[0].operandsym)->getIndex()); slgh->selfDefine((yyvsp[0].operandsym)); }
#line 2942 "/home/jnstaursky/Desktop/Personal-Projects/coronium/src/slghparse.cc"
    break;

  case 124:
#line 326 "/home/jnstaursky/Desktop/Personal-Projects/coronium/parse/slghparse.y"
                                        { (yyval.pateq) = new UnconstrainedEquation((yyvsp[0].specsym)->getPatternExpression()); }
#line 2948 "/home/jnstaursky/Desktop/Personal-Projects/coronium/src/slghparse.cc"
    break;

  case 125:
#line 327 "/home/jnstaursky/Desktop/Personal-Projects/coronium/parse/slghparse.y"
                                        { (yyval.pateq) = slgh->defineInvisibleOperand((yyvsp[0].famsym)); }
#line 2954 "/home/jnstaursky/Desktop/Personal-Projects/coronium/src/slghparse.cc"
    break;

  case 126:
#line 328 "/home/jnstaursky/Desktop/Personal-Projects/coronium/parse/slghparse.y"
                                        { (yyval.pateq) = slgh->defineInvisibleOperand((yyvsp[0].subtablesym)); }
#line 2960 "/home/jnstaursky/Desktop/Personal-Projects/coronium/src/slghparse.cc"
    break;

  case 127:
#line 330 "/home/jnstaursky/Desktop/Personal-Projects/coronium/parse/slghparse.y"
                                        { (yyval.contop) = (vector<ContextChange *> *)0; }
#line 2966 "/home/jnstaursky/Desktop/Personal-Projects/coronium/src/slghparse.cc"
    break;

  case 128:
#line 331 "/home/jnstaursky/Desktop/Personal-Projects/coronium/parse/slghparse.y"
                                        { (yyval.contop) = (yyvsp[-1].contop); }
#line 2972 "/home/jnstaursky/Desktop/Personal-Projects/coronium/src/slghparse.cc"
    break;

  case 129:
#line 333 "/home/jnstaursky/Desktop/Personal-Projects/coronium/parse/slghparse.y"
                                        { (yyval.contop) = new vector<ContextChange *>; }
#line 2978 "/home/jnstaursky/Desktop/Personal-Projects/coronium/src/slghparse.cc"
    break;

  case 130:
#line 334 "/home/jnstaursky/Desktop/Personal-Projects/coronium/parse/slghparse.y"
                                                { (yyval.contop) = (yyvsp[-4].contop); if (!slgh->contextMod((yyvsp[-4].contop),(yyvsp[-3].contextsym),(yyvsp[-1].patexp))) { string errmsg="Cannot use 'inst_next' to set context variable: "+(yyvsp[-3].contextsym)->getName(); yyerror(errmsg.c_str()); YYERROR; } }
#line 2984 "/home/jnstaursky/Desktop/Personal-Projects/coronium/src/slghparse.cc"
    break;

  case 131:
#line 335 "/home/jnstaursky/Desktop/Personal-Projects/coronium/parse/slghparse.y"
                                                                      { (yyval.contop) = (yyvsp[-7].contop); slgh->contextSet((yyvsp[-7].contop),(yyvsp[-4].famsym),(yyvsp[-2].contextsym)); }
#line 2990 "/home/jnstaursky/Desktop/Personal-Projects/coronium/src/slghparse.cc"
    break;

  case 132:
#line 336 "/home/jnstaursky/Desktop/Personal-Projects/coronium/parse/slghparse.y"
                                                                        { (yyval.contop) = (yyvsp[-7].contop); slgh->contextSet((yyvsp[-7].contop),(yyvsp[-4].specsym),(yyvsp[-2].contextsym)); }
#line 2996 "/home/jnstaursky/Desktop/Personal-Projects/coronium/src/slghparse.cc"
    break;

  case 133:
#line 337 "/home/jnstaursky/Desktop/Personal-Projects/coronium/parse/slghparse.y"
                                               { (yyval.contop) = (yyvsp[-4].contop); slgh->defineOperand((yyvsp[-3].operandsym),(yyvsp[-1].patexp)); }
#line 3002 "/home/jnstaursky/Desktop/Personal-Projects/coronium/src/slghparse.cc"
    break;

  case 134:
#line 338 "/home/jnstaursky/Desktop/Personal-Projects/coronium/parse/slghparse.y"
                                        { string errmsg="Expecting context symbol, not "+*(yyvsp[0].str); delete (yyvsp[0].str); yyerror(errmsg.c_str()); YYERROR; }
#line 3008 "/home/jnstaursky/Desktop/Personal-Projects/coronium/src/slghparse.cc"
    break;

  case 135:
#line 340 "/home/jnstaursky/Desktop/Personal-Projects/coronium/parse/slghparse.y"
                                        { (yyval.sectionsym) = slgh->newSectionSymbol( *(yyvsp[-1].str) ); delete (yyvsp[-1].str); }
#line 3014 "/home/jnstaursky/Desktop/Personal-Projects/coronium/src/slghparse.cc"
    break;

  case 136:
#line 341 "/home/jnstaursky/Desktop/Personal-Projects/coronium/parse/slghparse.y"
                                        { (yyval.sectionsym) = (yyvsp[-1].sectionsym); }
#line 3020 "/home/jnstaursky/Desktop/Personal-Projects/coronium/src/slghparse.cc"
    break;

  case 137:
#line 343 "/home/jnstaursky/Desktop/Personal-Projects/coronium/parse/slghparse.y"
                                        { (yyval.sectionstart) = slgh->firstNamedSection((yyvsp[-1].sem),(yyvsp[0].sectionsym)); }
#line 3026 "/home/jnstaursky/Desktop/Personal-Projects/coronium/src/slghparse.cc"
    break;

  case 138:
#line 345 "/home/jnstaursky/Desktop/Personal-Projects/coronium/parse/slghparse.y"
                             { (yyval.sectionstart) = (yyvsp[0].sectionstart); }
#line 3032 "/home/jnstaursky/Desktop/Personal-Projects/coronium/src/slghparse.cc"
    break;

  case 139:
#line 346 "/home/jnstaursky/Desktop/Personal-Projects/coronium/parse/slghparse.y"
                                        { (yyval.sectionstart) = slgh->nextNamedSection((yyvsp[-2].sectionstart),(yyvsp[-1].sem),(yyvsp[0].sectionsym)); }
#line 3038 "/home/jnstaursky/Desktop/Personal-Projects/coronium/src/slghparse.cc"
    break;

  case 140:
#line 348 "/home/jnstaursky/Desktop/Personal-Projects/coronium/parse/slghparse.y"
            { (yyval.sem) = (yyvsp[0].sem); if ((yyval.sem)->getOpvec().empty() && ((yyval.sem)->getResult() == (HandleTpl *)0)) slgh->recordNop(); }
#line 3044 "/home/jnstaursky/Desktop/Personal-Projects/coronium/src/slghparse.cc"
    break;

  case 141:
#line 349 "/home/jnstaursky/Desktop/Personal-Projects/coronium/parse/slghparse.y"
                                        { (yyval.sem) = slgh->setResultVarnode((yyvsp[-3].sem),(yyvsp[-1].varnode)); }
#line 3050 "/home/jnstaursky/Desktop/Personal-Projects/coronium/src/slghparse.cc"
    break;

  case 142:
#line 350 "/home/jnstaursky/Desktop/Personal-Projects/coronium/parse/slghparse.y"
                                               { (yyval.sem) = slgh->setResultStarVarnode((yyvsp[-4].sem),(yyvsp[-2].starqual),(yyvsp[-1].varnode)); }
#line 3056 "/home/jnstaursky/Desktop/Personal-Projects/coronium/src/slghparse.cc"
    break;

  case 143:
#line 351 "/home/jnstaursky/Desktop/Personal-Projects/coronium/parse/slghparse.y"
                                        { string errmsg="Unknown export varnode: "+*(yyvsp[0].str); delete (yyvsp[0].str); yyerror(errmsg.c_str()); YYERROR; }
#line 3062 "/home/jnstaursky/Desktop/Personal-Projects/coronium/src/slghparse.cc"
    break;

  case 144:
#line 352 "/home/jnstaursky/Desktop/Personal-Projects/coronium/parse/slghparse.y"
                                        { string errmsg="Unknown pointer varnode: "+*(yyvsp[0].str); delete (yyvsp[-1].starqual); delete (yyvsp[0].str); yyerror(errmsg.c_str()); YYERROR; }
#line 3068 "/home/jnstaursky/Desktop/Personal-Projects/coronium/src/slghparse.cc"
    break;

  case 145:
#line 354 "/home/jnstaursky/Desktop/Personal-Projects/coronium/parse/slghparse.y"
                                        { (yyval.sem) = new ConstructTpl(); }
#line 3074 "/home/jnstaursky/Desktop/Personal-Projects/coronium/src/slghparse.cc"
    break;

  case 146:
#line 355 "/home/jnstaursky/Desktop/Personal-Projects/coronium/parse/slghparse.y"
                                        { (yyval.sem) = (yyvsp[-1].sem); if (!(yyval.sem)->addOpList(*(yyvsp[0].stmt))) { delete (yyvsp[0].stmt); yyerror("Multiple delayslot declarations"); YYERROR; } delete (yyvsp[0].stmt); }
#line 3080 "/home/jnstaursky/Desktop/Personal-Projects/coronium/src/slghparse.cc"
    break;

  case 147:
#line 356 "/home/jnstaursky/Desktop/Personal-Projects/coronium/parse/slghparse.y"
                                { (yyval.sem) = (yyvsp[-3].sem); slgh->pcode.newLocalDefinition((yyvsp[-1].str)); }
#line 3086 "/home/jnstaursky/Desktop/Personal-Projects/coronium/src/slghparse.cc"
    break;

  case 148:
#line 357 "/home/jnstaursky/Desktop/Personal-Projects/coronium/parse/slghparse.y"
                                            { (yyval.sem) = (yyvsp[-5].sem); slgh->pcode.newLocalDefinition((yyvsp[-3].str),*(yyvsp[-1].i)); delete (yyvsp[-1].i); }
#line 3092 "/home/jnstaursky/Desktop/Personal-Projects/coronium/src/slghparse.cc"
    break;

  case 149:
#line 359 "/home/jnstaursky/Desktop/Personal-Projects/coronium/parse/slghparse.y"
                                        { (yyvsp[-1].tree)->setOutput((yyvsp[-3].varnode)); (yyval.stmt) = ExprTree::toVector((yyvsp[-1].tree)); }
#line 3098 "/home/jnstaursky/Desktop/Personal-Projects/coronium/src/slghparse.cc"
    break;

  case 150:
#line 360 "/home/jnstaursky/Desktop/Personal-Projects/coronium/parse/slghparse.y"
                                        { (yyval.stmt) = slgh->pcode.newOutput(true,(yyvsp[-1].tree),(yyvsp[-3].str)); }
#line 3104 "/home/jnstaursky/Desktop/Personal-Projects/coronium/src/slghparse.cc"
    break;

  case 151:
#line 361 "/home/jnstaursky/Desktop/Personal-Projects/coronium/parse/slghparse.y"
                                        { (yyval.stmt) = slgh->pcode.newOutput(false,(yyvsp[-1].tree),(yyvsp[-3].str)); }
#line 3110 "/home/jnstaursky/Desktop/Personal-Projects/coronium/src/slghparse.cc"
    break;

  case 152:
#line 362 "/home/jnstaursky/Desktop/Personal-Projects/coronium/parse/slghparse.y"
                                                { (yyval.stmt) = slgh->pcode.newOutput(true,(yyvsp[-1].tree),(yyvsp[-5].str),*(yyvsp[-3].i)); delete (yyvsp[-3].i); }
#line 3116 "/home/jnstaursky/Desktop/Personal-Projects/coronium/src/slghparse.cc"
    break;

  case 153:
#line 363 "/home/jnstaursky/Desktop/Personal-Projects/coronium/parse/slghparse.y"
                                        { (yyval.stmt) = slgh->pcode.newOutput(true,(yyvsp[-1].tree),(yyvsp[-5].str),*(yyvsp[-3].i)); delete (yyvsp[-3].i); }
#line 3122 "/home/jnstaursky/Desktop/Personal-Projects/coronium/src/slghparse.cc"
    break;

  case 154:
#line 364 "/home/jnstaursky/Desktop/Personal-Projects/coronium/parse/slghparse.y"
                                 { (yyval.stmt) = (vector<OpTpl *> *)0; string errmsg = "Redefinition of symbol: "+(yyvsp[-1].specsym)->getName(); yyerror(errmsg.c_str()); YYERROR; }
#line 3128 "/home/jnstaursky/Desktop/Personal-Projects/coronium/src/slghparse.cc"
    break;

  case 155:
#line 365 "/home/jnstaursky/Desktop/Personal-Projects/coronium/parse/slghparse.y"
                                        { (yyval.stmt) = slgh->pcode.createStore((yyvsp[-4].starqual),(yyvsp[-3].tree),(yyvsp[-1].tree)); }
#line 3134 "/home/jnstaursky/Desktop/Personal-Projects/coronium/src/slghparse.cc"
    break;

  case 156:
#line 366 "/home/jnstaursky/Desktop/Personal-Projects/coronium/parse/slghparse.y"
                                        { (yyval.stmt) = slgh->pcode.createUserOpNoOut((yyvsp[-4].useropsym),(yyvsp[-2].param)); }
#line 3140 "/home/jnstaursky/Desktop/Personal-Projects/coronium/src/slghparse.cc"
    break;

  case 157:
#line 367 "/home/jnstaursky/Desktop/Personal-Projects/coronium/parse/slghparse.y"
                                                        { (yyval.stmt) = slgh->pcode.assignBitRange((yyvsp[-8].varnode),(uint4)*(yyvsp[-6].i),(uint4)*(yyvsp[-4].i),(yyvsp[-1].tree)); delete (yyvsp[-6].i), delete (yyvsp[-4].i); }
#line 3146 "/home/jnstaursky/Desktop/Personal-Projects/coronium/src/slghparse.cc"
    break;

  case 158:
#line 368 "/home/jnstaursky/Desktop/Personal-Projects/coronium/parse/slghparse.y"
                                        { (yyval.stmt)=slgh->pcode.assignBitRange((yyvsp[-3].bitsym)->getParentSymbol()->getVarnode(),(yyvsp[-3].bitsym)->getBitOffset(),(yyvsp[-3].bitsym)->numBits(),(yyvsp[-1].tree)); }
#line 3152 "/home/jnstaursky/Desktop/Personal-Projects/coronium/src/slghparse.cc"
    break;

  case 159:
#line 369 "/home/jnstaursky/Desktop/Personal-Projects/coronium/parse/slghparse.y"
                                        { delete (yyvsp[-3].varnode); delete (yyvsp[-1].i); yyerror("Illegal truncation on left-hand side of assignment"); YYERROR; }
#line 3158 "/home/jnstaursky/Desktop/Personal-Projects/coronium/src/slghparse.cc"
    break;

  case 160:
#line 370 "/home/jnstaursky/Desktop/Personal-Projects/coronium/parse/slghparse.y"
                                        { delete (yyvsp[-3].varnode); delete (yyvsp[-1].i); yyerror("Illegal subpiece on left-hand side of assignment"); YYERROR; }
#line 3164 "/home/jnstaursky/Desktop/Personal-Projects/coronium/src/slghparse.cc"
    break;

  case 161:
#line 371 "/home/jnstaursky/Desktop/Personal-Projects/coronium/parse/slghparse.y"
                                        { (yyval.stmt) = slgh->pcode.createOpConst(BUILD,(yyvsp[-1].operandsym)->getIndex()); }
#line 3170 "/home/jnstaursky/Desktop/Personal-Projects/coronium/src/slghparse.cc"
    break;

  case 162:
#line 372 "/home/jnstaursky/Desktop/Personal-Projects/coronium/parse/slghparse.y"
                                              { (yyval.stmt) = slgh->createCrossBuild((yyvsp[-3].varnode),(yyvsp[-1].sectionsym)); }
#line 3176 "/home/jnstaursky/Desktop/Personal-Projects/coronium/src/slghparse.cc"
    break;

  case 163:
#line 373 "/home/jnstaursky/Desktop/Personal-Projects/coronium/parse/slghparse.y"
                                            { (yyval.stmt) = slgh->createCrossBuild((yyvsp[-3].varnode),slgh->newSectionSymbol(*(yyvsp[-1].str))); delete (yyvsp[-1].str); }
#line 3182 "/home/jnstaursky/Desktop/Personal-Projects/coronium/src/slghparse.cc"
    break;

  case 164:
#line 374 "/home/jnstaursky/Desktop/Personal-Projects/coronium/parse/slghparse.y"
                                        { (yyval.stmt) = slgh->pcode.createOpConst(DELAY_SLOT,*(yyvsp[-2].i)); delete (yyvsp[-2].i); }
#line 3188 "/home/jnstaursky/Desktop/Personal-Projects/coronium/src/slghparse.cc"
    break;

  case 165:
#line 375 "/home/jnstaursky/Desktop/Personal-Projects/coronium/parse/slghparse.y"
                                        { (yyval.stmt) = slgh->pcode.createOpNoOut(CPUI_BRANCH,new ExprTree((yyvsp[-1].varnode))); }
#line 3194 "/home/jnstaursky/Desktop/Personal-Projects/coronium/src/slghparse.cc"
    break;

  case 166:
#line 376 "/home/jnstaursky/Desktop/Personal-Projects/coronium/parse/slghparse.y"
                                        { (yyval.stmt) = slgh->pcode.createOpNoOut(CPUI_CBRANCH,new ExprTree((yyvsp[-1].varnode)),(yyvsp[-3].tree)); }
#line 3200 "/home/jnstaursky/Desktop/Personal-Projects/coronium/src/slghparse.cc"
    break;

  case 167:
#line 377 "/home/jnstaursky/Desktop/Personal-Projects/coronium/parse/slghparse.y"
                                        { (yyval.stmt) = slgh->pcode.createOpNoOut(CPUI_BRANCHIND,(yyvsp[-2].tree)); }
#line 3206 "/home/jnstaursky/Desktop/Personal-Projects/coronium/src/slghparse.cc"
    break;

  case 168:
#line 378 "/home/jnstaursky/Desktop/Personal-Projects/coronium/parse/slghparse.y"
                                        { (yyval.stmt) = slgh->pcode.createOpNoOut(CPUI_CALL,new ExprTree((yyvsp[-1].varnode))); }
#line 3212 "/home/jnstaursky/Desktop/Personal-Projects/coronium/src/slghparse.cc"
    break;

  case 169:
#line 379 "/home/jnstaursky/Desktop/Personal-Projects/coronium/parse/slghparse.y"
                                        { (yyval.stmt) = slgh->pcode.createOpNoOut(CPUI_CALLIND,(yyvsp[-2].tree)); }
#line 3218 "/home/jnstaursky/Desktop/Personal-Projects/coronium/src/slghparse.cc"
    break;

  case 170:
#line 380 "/home/jnstaursky/Desktop/Personal-Projects/coronium/parse/slghparse.y"
                                        { yyerror("Must specify an indirect parameter for return"); YYERROR; }
#line 3224 "/home/jnstaursky/Desktop/Personal-Projects/coronium/src/slghparse.cc"
    break;

  case 171:
#line 381 "/home/jnstaursky/Desktop/Personal-Projects/coronium/parse/slghparse.y"
                                        { (yyval.stmt) = slgh->pcode.createOpNoOut(CPUI_RETURN,(yyvsp[-2].tree)); }
#line 3230 "/home/jnstaursky/Desktop/Personal-Projects/coronium/src/slghparse.cc"
    break;

  case 172:
#line 382 "/home/jnstaursky/Desktop/Personal-Projects/coronium/parse/slghparse.y"
                                        { (yyval.stmt) = slgh->createMacroUse((yyvsp[-4].macrosym),(yyvsp[-2].param)); }
#line 3236 "/home/jnstaursky/Desktop/Personal-Projects/coronium/src/slghparse.cc"
    break;

  case 173:
#line 383 "/home/jnstaursky/Desktop/Personal-Projects/coronium/parse/slghparse.y"
                                        { (yyval.stmt) = slgh->pcode.placeLabel( (yyvsp[0].labelsym) ); }
#line 3242 "/home/jnstaursky/Desktop/Personal-Projects/coronium/src/slghparse.cc"
    break;

  case 174:
#line 385 "/home/jnstaursky/Desktop/Personal-Projects/coronium/parse/slghparse.y"
              { (yyval.tree) = new ExprTree((yyvsp[0].varnode)); }
#line 3248 "/home/jnstaursky/Desktop/Personal-Projects/coronium/src/slghparse.cc"
    break;

  case 175:
#line 386 "/home/jnstaursky/Desktop/Personal-Projects/coronium/parse/slghparse.y"
                                { (yyval.tree) = slgh->pcode.createLoad((yyvsp[-1].starqual),(yyvsp[0].tree)); }
#line 3254 "/home/jnstaursky/Desktop/Personal-Projects/coronium/src/slghparse.cc"
    break;

  case 176:
#line 387 "/home/jnstaursky/Desktop/Personal-Projects/coronium/parse/slghparse.y"
                                { (yyval.tree) = (yyvsp[-1].tree); }
#line 3260 "/home/jnstaursky/Desktop/Personal-Projects/coronium/src/slghparse.cc"
    break;

  case 177:
#line 388 "/home/jnstaursky/Desktop/Personal-Projects/coronium/parse/slghparse.y"
                                { (yyval.tree) = slgh->pcode.createOp(CPUI_INT_ADD,(yyvsp[-2].tree),(yyvsp[0].tree)); }
#line 3266 "/home/jnstaursky/Desktop/Personal-Projects/coronium/src/slghparse.cc"
    break;

  case 178:
#line 389 "/home/jnstaursky/Desktop/Personal-Projects/coronium/parse/slghparse.y"
                                { (yyval.tree) = slgh->pcode.createOp(CPUI_INT_SUB,(yyvsp[-2].tree),(yyvsp[0].tree)); }
#line 3272 "/home/jnstaursky/Desktop/Personal-Projects/coronium/src/slghparse.cc"
    break;

  case 179:
#line 390 "/home/jnstaursky/Desktop/Personal-Projects/coronium/parse/slghparse.y"
                                { (yyval.tree) = slgh->pcode.createOp(CPUI_INT_EQUAL,(yyvsp[-2].tree),(yyvsp[0].tree)); }
#line 3278 "/home/jnstaursky/Desktop/Personal-Projects/coronium/src/slghparse.cc"
    break;

  case 180:
#line 391 "/home/jnstaursky/Desktop/Personal-Projects/coronium/parse/slghparse.y"
                                { (yyval.tree) = slgh->pcode.createOp(CPUI_INT_NOTEQUAL,(yyvsp[-2].tree),(yyvsp[0].tree)); }
#line 3284 "/home/jnstaursky/Desktop/Personal-Projects/coronium/src/slghparse.cc"
    break;

  case 181:
#line 392 "/home/jnstaursky/Desktop/Personal-Projects/coronium/parse/slghparse.y"
                                { (yyval.tree) = slgh->pcode.createOp(CPUI_INT_LESS,(yyvsp[-2].tree),(yyvsp[0].tree)); }
#line 3290 "/home/jnstaursky/Desktop/Personal-Projects/coronium/src/slghparse.cc"
    break;

  case 182:
#line 393 "/home/jnstaursky/Desktop/Personal-Projects/coronium/parse/slghparse.y"
                                { (yyval.tree) = slgh->pcode.createOp(CPUI_INT_LESSEQUAL,(yyvsp[0].tree),(yyvsp[-2].tree)); }
#line 3296 "/home/jnstaursky/Desktop/Personal-Projects/coronium/src/slghparse.cc"
    break;

  case 183:
#line 394 "/home/jnstaursky/Desktop/Personal-Projects/coronium/parse/slghparse.y"
                                { (yyval.tree) = slgh->pcode.createOp(CPUI_INT_LESSEQUAL,(yyvsp[-2].tree),(yyvsp[0].tree)); }
#line 3302 "/home/jnstaursky/Desktop/Personal-Projects/coronium/src/slghparse.cc"
    break;

  case 184:
#line 395 "/home/jnstaursky/Desktop/Personal-Projects/coronium/parse/slghparse.y"
                                { (yyval.tree) = slgh->pcode.createOp(CPUI_INT_LESS,(yyvsp[0].tree),(yyvsp[-2].tree)); }
#line 3308 "/home/jnstaursky/Desktop/Personal-Projects/coronium/src/slghparse.cc"
    break;

  case 185:
#line 396 "/home/jnstaursky/Desktop/Personal-Projects/coronium/parse/slghparse.y"
                                { (yyval.tree) = slgh->pcode.createOp(CPUI_INT_SLESS,(yyvsp[-2].tree),(yyvsp[0].tree)); }
#line 3314 "/home/jnstaursky/Desktop/Personal-Projects/coronium/src/slghparse.cc"
    break;

  case 186:
#line 397 "/home/jnstaursky/Desktop/Personal-Projects/coronium/parse/slghparse.y"
                                { (yyval.tree) = slgh->pcode.createOp(CPUI_INT_SLESSEQUAL,(yyvsp[0].tree),(yyvsp[-2].tree)); }
#line 3320 "/home/jnstaursky/Desktop/Personal-Projects/coronium/src/slghparse.cc"
    break;

  case 187:
#line 398 "/home/jnstaursky/Desktop/Personal-Projects/coronium/parse/slghparse.y"
                                { (yyval.tree) = slgh->pcode.createOp(CPUI_INT_SLESSEQUAL,(yyvsp[-2].tree),(yyvsp[0].tree)); }
#line 3326 "/home/jnstaursky/Desktop/Personal-Projects/coronium/src/slghparse.cc"
    break;

  case 188:
#line 399 "/home/jnstaursky/Desktop/Personal-Projects/coronium/parse/slghparse.y"
                                { (yyval.tree) = slgh->pcode.createOp(CPUI_INT_SLESS,(yyvsp[0].tree),(yyvsp[-2].tree)); }
#line 3332 "/home/jnstaursky/Desktop/Personal-Projects/coronium/src/slghparse.cc"
    break;

  case 189:
#line 400 "/home/jnstaursky/Desktop/Personal-Projects/coronium/parse/slghparse.y"
                                { (yyval.tree) = slgh->pcode.createOp(CPUI_INT_2COMP,(yyvsp[0].tree)); }
#line 3338 "/home/jnstaursky/Desktop/Personal-Projects/coronium/src/slghparse.cc"
    break;

  case 190:
#line 401 "/home/jnstaursky/Desktop/Personal-Projects/coronium/parse/slghparse.y"
                                { (yyval.tree) = slgh->pcode.createOp(CPUI_INT_NEGATE,(yyvsp[0].tree)); }
#line 3344 "/home/jnstaursky/Desktop/Personal-Projects/coronium/src/slghparse.cc"
    break;

  case 191:
#line 402 "/home/jnstaursky/Desktop/Personal-Projects/coronium/parse/slghparse.y"
                                { (yyval.tree) = slgh->pcode.createOp(CPUI_INT_XOR,(yyvsp[-2].tree),(yyvsp[0].tree)); }
#line 3350 "/home/jnstaursky/Desktop/Personal-Projects/coronium/src/slghparse.cc"
    break;

  case 192:
#line 403 "/home/jnstaursky/Desktop/Personal-Projects/coronium/parse/slghparse.y"
                                { (yyval.tree) = slgh->pcode.createOp(CPUI_INT_AND,(yyvsp[-2].tree),(yyvsp[0].tree)); }
#line 3356 "/home/jnstaursky/Desktop/Personal-Projects/coronium/src/slghparse.cc"
    break;

  case 193:
#line 404 "/home/jnstaursky/Desktop/Personal-Projects/coronium/parse/slghparse.y"
                                { (yyval.tree) = slgh->pcode.createOp(CPUI_INT_OR,(yyvsp[-2].tree),(yyvsp[0].tree)); }
#line 3362 "/home/jnstaursky/Desktop/Personal-Projects/coronium/src/slghparse.cc"
    break;

  case 194:
#line 405 "/home/jnstaursky/Desktop/Personal-Projects/coronium/parse/slghparse.y"
                                { (yyval.tree) = slgh->pcode.createOp(CPUI_INT_LEFT,(yyvsp[-2].tree),(yyvsp[0].tree)); }
#line 3368 "/home/jnstaursky/Desktop/Personal-Projects/coronium/src/slghparse.cc"
    break;

  case 195:
#line 406 "/home/jnstaursky/Desktop/Personal-Projects/coronium/parse/slghparse.y"
                                { (yyval.tree) = slgh->pcode.createOp(CPUI_INT_RIGHT,(yyvsp[-2].tree),(yyvsp[0].tree)); }
#line 3374 "/home/jnstaursky/Desktop/Personal-Projects/coronium/src/slghparse.cc"
    break;

  case 196:
#line 407 "/home/jnstaursky/Desktop/Personal-Projects/coronium/parse/slghparse.y"
                                { (yyval.tree) = slgh->pcode.createOp(CPUI_INT_SRIGHT,(yyvsp[-2].tree),(yyvsp[0].tree)); }
#line 3380 "/home/jnstaursky/Desktop/Personal-Projects/coronium/src/slghparse.cc"
    break;

  case 197:
#line 408 "/home/jnstaursky/Desktop/Personal-Projects/coronium/parse/slghparse.y"
                                { (yyval.tree) = slgh->pcode.createOp(CPUI_INT_MULT,(yyvsp[-2].tree),(yyvsp[0].tree)); }
#line 3386 "/home/jnstaursky/Desktop/Personal-Projects/coronium/src/slghparse.cc"
    break;

  case 198:
#line 409 "/home/jnstaursky/Desktop/Personal-Projects/coronium/parse/slghparse.y"
                                { (yyval.tree) = slgh->pcode.createOp(CPUI_INT_DIV,(yyvsp[-2].tree),(yyvsp[0].tree)); }
#line 3392 "/home/jnstaursky/Desktop/Personal-Projects/coronium/src/slghparse.cc"
    break;

  case 199:
#line 410 "/home/jnstaursky/Desktop/Personal-Projects/coronium/parse/slghparse.y"
                                { (yyval.tree) = slgh->pcode.createOp(CPUI_INT_SDIV,(yyvsp[-2].tree),(yyvsp[0].tree)); }
#line 3398 "/home/jnstaursky/Desktop/Personal-Projects/coronium/src/slghparse.cc"
    break;

  case 200:
#line 411 "/home/jnstaursky/Desktop/Personal-Projects/coronium/parse/slghparse.y"
                                { (yyval.tree) = slgh->pcode.createOp(CPUI_INT_REM,(yyvsp[-2].tree),(yyvsp[0].tree)); }
#line 3404 "/home/jnstaursky/Desktop/Personal-Projects/coronium/src/slghparse.cc"
    break;

  case 201:
#line 412 "/home/jnstaursky/Desktop/Personal-Projects/coronium/parse/slghparse.y"
                                { (yyval.tree) = slgh->pcode.createOp(CPUI_INT_SREM,(yyvsp[-2].tree),(yyvsp[0].tree)); }
#line 3410 "/home/jnstaursky/Desktop/Personal-Projects/coronium/src/slghparse.cc"
    break;

  case 202:
#line 413 "/home/jnstaursky/Desktop/Personal-Projects/coronium/parse/slghparse.y"
                                { (yyval.tree) = slgh->pcode.createOp(CPUI_BOOL_NEGATE,(yyvsp[0].tree)); }
#line 3416 "/home/jnstaursky/Desktop/Personal-Projects/coronium/src/slghparse.cc"
    break;

  case 203:
#line 414 "/home/jnstaursky/Desktop/Personal-Projects/coronium/parse/slghparse.y"
                                { (yyval.tree) = slgh->pcode.createOp(CPUI_BOOL_XOR,(yyvsp[-2].tree),(yyvsp[0].tree)); }
#line 3422 "/home/jnstaursky/Desktop/Personal-Projects/coronium/src/slghparse.cc"
    break;

  case 204:
#line 415 "/home/jnstaursky/Desktop/Personal-Projects/coronium/parse/slghparse.y"
                                { (yyval.tree) = slgh->pcode.createOp(CPUI_BOOL_AND,(yyvsp[-2].tree),(yyvsp[0].tree)); }
#line 3428 "/home/jnstaursky/Desktop/Personal-Projects/coronium/src/slghparse.cc"
    break;

  case 205:
#line 416 "/home/jnstaursky/Desktop/Personal-Projects/coronium/parse/slghparse.y"
                                { (yyval.tree) = slgh->pcode.createOp(CPUI_BOOL_OR,(yyvsp[-2].tree),(yyvsp[0].tree)); }
#line 3434 "/home/jnstaursky/Desktop/Personal-Projects/coronium/src/slghparse.cc"
    break;

  case 206:
#line 417 "/home/jnstaursky/Desktop/Personal-Projects/coronium/parse/slghparse.y"
                                { (yyval.tree) = slgh->pcode.createOp(CPUI_FLOAT_EQUAL,(yyvsp[-2].tree),(yyvsp[0].tree)); }
#line 3440 "/home/jnstaursky/Desktop/Personal-Projects/coronium/src/slghparse.cc"
    break;

  case 207:
#line 418 "/home/jnstaursky/Desktop/Personal-Projects/coronium/parse/slghparse.y"
                                { (yyval.tree) = slgh->pcode.createOp(CPUI_FLOAT_NOTEQUAL,(yyvsp[-2].tree),(yyvsp[0].tree)); }
#line 3446 "/home/jnstaursky/Desktop/Personal-Projects/coronium/src/slghparse.cc"
    break;

  case 208:
#line 419 "/home/jnstaursky/Desktop/Personal-Projects/coronium/parse/slghparse.y"
                                { (yyval.tree) = slgh->pcode.createOp(CPUI_FLOAT_LESS,(yyvsp[-2].tree),(yyvsp[0].tree)); }
#line 3452 "/home/jnstaursky/Desktop/Personal-Projects/coronium/src/slghparse.cc"
    break;

  case 209:
#line 420 "/home/jnstaursky/Desktop/Personal-Projects/coronium/parse/slghparse.y"
                                { (yyval.tree) = slgh->pcode.createOp(CPUI_FLOAT_LESS,(yyvsp[0].tree),(yyvsp[-2].tree)); }
#line 3458 "/home/jnstaursky/Desktop/Personal-Projects/coronium/src/slghparse.cc"
    break;

  case 210:
#line 421 "/home/jnstaursky/Desktop/Personal-Projects/coronium/parse/slghparse.y"
                                { (yyval.tree) = slgh->pcode.createOp(CPUI_FLOAT_LESSEQUAL,(yyvsp[-2].tree),(yyvsp[0].tree)); }
#line 3464 "/home/jnstaursky/Desktop/Personal-Projects/coronium/src/slghparse.cc"
    break;

  case 211:
#line 422 "/home/jnstaursky/Desktop/Personal-Projects/coronium/parse/slghparse.y"
                                { (yyval.tree) = slgh->pcode.createOp(CPUI_FLOAT_LESSEQUAL,(yyvsp[0].tree),(yyvsp[-2].tree)); }
#line 3470 "/home/jnstaursky/Desktop/Personal-Projects/coronium/src/slghparse.cc"
    break;

  case 212:
#line 423 "/home/jnstaursky/Desktop/Personal-Projects/coronium/parse/slghparse.y"
                                { (yyval.tree) = slgh->pcode.createOp(CPUI_FLOAT_ADD,(yyvsp[-2].tree),(yyvsp[0].tree)); }
#line 3476 "/home/jnstaursky/Desktop/Personal-Projects/coronium/src/slghparse.cc"
    break;

  case 213:
#line 424 "/home/jnstaursky/Desktop/Personal-Projects/coronium/parse/slghparse.y"
                                { (yyval.tree) = slgh->pcode.createOp(CPUI_FLOAT_SUB,(yyvsp[-2].tree),(yyvsp[0].tree)); }
#line 3482 "/home/jnstaursky/Desktop/Personal-Projects/coronium/src/slghparse.cc"
    break;

  case 214:
#line 425 "/home/jnstaursky/Desktop/Personal-Projects/coronium/parse/slghparse.y"
                                { (yyval.tree) = slgh->pcode.createOp(CPUI_FLOAT_MULT,(yyvsp[-2].tree),(yyvsp[0].tree)); }
#line 3488 "/home/jnstaursky/Desktop/Personal-Projects/coronium/src/slghparse.cc"
    break;

  case 215:
#line 426 "/home/jnstaursky/Desktop/Personal-Projects/coronium/parse/slghparse.y"
                                { (yyval.tree) = slgh->pcode.createOp(CPUI_FLOAT_DIV,(yyvsp[-2].tree),(yyvsp[0].tree)); }
#line 3494 "/home/jnstaursky/Desktop/Personal-Projects/coronium/src/slghparse.cc"
    break;

  case 216:
#line 427 "/home/jnstaursky/Desktop/Personal-Projects/coronium/parse/slghparse.y"
                                { (yyval.tree) = slgh->pcode.createOp(CPUI_FLOAT_NEG,(yyvsp[0].tree)); }
#line 3500 "/home/jnstaursky/Desktop/Personal-Projects/coronium/src/slghparse.cc"
    break;

  case 217:
#line 428 "/home/jnstaursky/Desktop/Personal-Projects/coronium/parse/slghparse.y"
                                { (yyval.tree) = slgh->pcode.createOp(CPUI_FLOAT_ABS,(yyvsp[-1].tree)); }
#line 3506 "/home/jnstaursky/Desktop/Personal-Projects/coronium/src/slghparse.cc"
    break;

  case 218:
#line 429 "/home/jnstaursky/Desktop/Personal-Projects/coronium/parse/slghparse.y"
                                { (yyval.tree) = slgh->pcode.createOp(CPUI_FLOAT_SQRT,(yyvsp[-1].tree)); }
#line 3512 "/home/jnstaursky/Desktop/Personal-Projects/coronium/src/slghparse.cc"
    break;

  case 219:
#line 430 "/home/jnstaursky/Desktop/Personal-Projects/coronium/parse/slghparse.y"
                                { (yyval.tree) = slgh->pcode.createOp(CPUI_INT_SEXT,(yyvsp[-1].tree)); }
#line 3518 "/home/jnstaursky/Desktop/Personal-Projects/coronium/src/slghparse.cc"
    break;

  case 220:
#line 431 "/home/jnstaursky/Desktop/Personal-Projects/coronium/parse/slghparse.y"
                                { (yyval.tree) = slgh->pcode.createOp(CPUI_INT_ZEXT,(yyvsp[-1].tree)); }
#line 3524 "/home/jnstaursky/Desktop/Personal-Projects/coronium/src/slghparse.cc"
    break;

  case 221:
#line 432 "/home/jnstaursky/Desktop/Personal-Projects/coronium/parse/slghparse.y"
                                   { (yyval.tree) = slgh->pcode.createOp(CPUI_INT_CARRY,(yyvsp[-3].tree),(yyvsp[-1].tree)); }
#line 3530 "/home/jnstaursky/Desktop/Personal-Projects/coronium/src/slghparse.cc"
    break;

  case 222:
#line 433 "/home/jnstaursky/Desktop/Personal-Projects/coronium/parse/slghparse.y"
                                    { (yyval.tree) = slgh->pcode.createOp(CPUI_INT_SCARRY,(yyvsp[-3].tree),(yyvsp[-1].tree)); }
#line 3536 "/home/jnstaursky/Desktop/Personal-Projects/coronium/src/slghparse.cc"
    break;

  case 223:
#line 434 "/home/jnstaursky/Desktop/Personal-Projects/coronium/parse/slghparse.y"
                                     { (yyval.tree) = slgh->pcode.createOp(CPUI_INT_SBORROW,(yyvsp[-3].tree),(yyvsp[-1].tree)); }
#line 3542 "/home/jnstaursky/Desktop/Personal-Projects/coronium/src/slghparse.cc"
    break;

  case 224:
#line 435 "/home/jnstaursky/Desktop/Personal-Projects/coronium/parse/slghparse.y"
                                { (yyval.tree) = slgh->pcode.createOp(CPUI_FLOAT_FLOAT2FLOAT,(yyvsp[-1].tree)); }
#line 3548 "/home/jnstaursky/Desktop/Personal-Projects/coronium/src/slghparse.cc"
    break;

  case 225:
#line 436 "/home/jnstaursky/Desktop/Personal-Projects/coronium/parse/slghparse.y"
                                { (yyval.tree) = slgh->pcode.createOp(CPUI_FLOAT_INT2FLOAT,(yyvsp[-1].tree)); }
#line 3554 "/home/jnstaursky/Desktop/Personal-Projects/coronium/src/slghparse.cc"
    break;

  case 226:
#line 437 "/home/jnstaursky/Desktop/Personal-Projects/coronium/parse/slghparse.y"
                                { (yyval.tree) = slgh->pcode.createOp(CPUI_FLOAT_NAN,(yyvsp[-1].tree)); }
#line 3560 "/home/jnstaursky/Desktop/Personal-Projects/coronium/src/slghparse.cc"
    break;

  case 227:
#line 438 "/home/jnstaursky/Desktop/Personal-Projects/coronium/parse/slghparse.y"
                                { (yyval.tree) = slgh->pcode.createOp(CPUI_FLOAT_TRUNC,(yyvsp[-1].tree)); }
#line 3566 "/home/jnstaursky/Desktop/Personal-Projects/coronium/src/slghparse.cc"
    break;

  case 228:
#line 439 "/home/jnstaursky/Desktop/Personal-Projects/coronium/parse/slghparse.y"
                                { (yyval.tree) = slgh->pcode.createOp(CPUI_FLOAT_CEIL,(yyvsp[-1].tree)); }
#line 3572 "/home/jnstaursky/Desktop/Personal-Projects/coronium/src/slghparse.cc"
    break;

  case 229:
#line 440 "/home/jnstaursky/Desktop/Personal-Projects/coronium/parse/slghparse.y"
                                { (yyval.tree) = slgh->pcode.createOp(CPUI_FLOAT_FLOOR,(yyvsp[-1].tree)); }
#line 3578 "/home/jnstaursky/Desktop/Personal-Projects/coronium/src/slghparse.cc"
    break;

  case 230:
#line 441 "/home/jnstaursky/Desktop/Personal-Projects/coronium/parse/slghparse.y"
                                { (yyval.tree) = slgh->pcode.createOp(CPUI_FLOAT_ROUND,(yyvsp[-1].tree)); }
#line 3584 "/home/jnstaursky/Desktop/Personal-Projects/coronium/src/slghparse.cc"
    break;

  case 231:
#line 442 "/home/jnstaursky/Desktop/Personal-Projects/coronium/parse/slghparse.y"
                            { (yyval.tree) = slgh->pcode.createOp(CPUI_NEW,(yyvsp[-1].tree)); }
#line 3590 "/home/jnstaursky/Desktop/Personal-Projects/coronium/src/slghparse.cc"
    break;

  case 232:
#line 443 "/home/jnstaursky/Desktop/Personal-Projects/coronium/parse/slghparse.y"
                                 { (yyval.tree) = slgh->pcode.createOp(CPUI_NEW,(yyvsp[-3].tree),(yyvsp[-1].tree)); }
#line 3596 "/home/jnstaursky/Desktop/Personal-Projects/coronium/src/slghparse.cc"
    break;

  case 233:
#line 444 "/home/jnstaursky/Desktop/Personal-Projects/coronium/parse/slghparse.y"
                             { (yyval.tree) = slgh->pcode.createOp(CPUI_POPCOUNT,(yyvsp[-1].tree)); }
#line 3602 "/home/jnstaursky/Desktop/Personal-Projects/coronium/src/slghparse.cc"
    break;

  case 234:
#line 445 "/home/jnstaursky/Desktop/Personal-Projects/coronium/parse/slghparse.y"
                                          { (yyval.tree) = slgh->pcode.createOp(CPUI_SUBPIECE,new ExprTree((yyvsp[-3].specsym)->getVarnode()),new ExprTree((yyvsp[-1].varnode))); }
#line 3608 "/home/jnstaursky/Desktop/Personal-Projects/coronium/src/slghparse.cc"
    break;

  case 235:
#line 446 "/home/jnstaursky/Desktop/Personal-Projects/coronium/parse/slghparse.y"
                                { (yyval.tree) = slgh->pcode.createBitRange((yyvsp[-2].specsym),0,(uint4)(*(yyvsp[0].i) * 8)); delete (yyvsp[0].i); }
#line 3614 "/home/jnstaursky/Desktop/Personal-Projects/coronium/src/slghparse.cc"
    break;

  case 236:
#line 447 "/home/jnstaursky/Desktop/Personal-Projects/coronium/parse/slghparse.y"
                                               { (yyval.tree) = slgh->pcode.createBitRange((yyvsp[-5].specsym),(uint4)*(yyvsp[-3].i),(uint4)*(yyvsp[-1].i)); delete (yyvsp[-3].i), delete (yyvsp[-1].i); }
#line 3620 "/home/jnstaursky/Desktop/Personal-Projects/coronium/src/slghparse.cc"
    break;

  case 237:
#line 448 "/home/jnstaursky/Desktop/Personal-Projects/coronium/parse/slghparse.y"
                                { (yyval.tree)=slgh->pcode.createBitRange((yyvsp[0].bitsym)->getParentSymbol(),(yyvsp[0].bitsym)->getBitOffset(),(yyvsp[0].bitsym)->numBits()); }
#line 3626 "/home/jnstaursky/Desktop/Personal-Projects/coronium/src/slghparse.cc"
    break;

  case 238:
#line 449 "/home/jnstaursky/Desktop/Personal-Projects/coronium/parse/slghparse.y"
                                { (yyval.tree) = slgh->pcode.createUserOp((yyvsp[-3].useropsym),(yyvsp[-1].param)); }
#line 3632 "/home/jnstaursky/Desktop/Personal-Projects/coronium/src/slghparse.cc"
    break;

  case 239:
#line 450 "/home/jnstaursky/Desktop/Personal-Projects/coronium/parse/slghparse.y"
                                   { if ((*(yyvsp[-1].param)).size() < 2) { string errmsg = "Must at least two inputs to cpool"; yyerror(errmsg.c_str()); YYERROR; } (yyval.tree) = slgh->pcode.createVariadic(CPUI_CPOOLREF,(yyvsp[-1].param)); }
#line 3638 "/home/jnstaursky/Desktop/Personal-Projects/coronium/src/slghparse.cc"
    break;

  case 240:
#line 452 "/home/jnstaursky/Desktop/Personal-Projects/coronium/parse/slghparse.y"
                                            { (yyval.starqual) = new StarQuality; (yyval.starqual)->size = *(yyvsp[0].i); delete (yyvsp[0].i); (yyval.starqual)->id=ConstTpl((yyvsp[-3].spacesym)->getSpace()); }
#line 3644 "/home/jnstaursky/Desktop/Personal-Projects/coronium/src/slghparse.cc"
    break;

  case 241:
#line 453 "/home/jnstaursky/Desktop/Personal-Projects/coronium/parse/slghparse.y"
                                { (yyval.starqual) = new StarQuality; (yyval.starqual)->size = 0; (yyval.starqual)->id=ConstTpl((yyvsp[-1].spacesym)->getSpace()); }
#line 3650 "/home/jnstaursky/Desktop/Personal-Projects/coronium/src/slghparse.cc"
    break;

  case 242:
#line 454 "/home/jnstaursky/Desktop/Personal-Projects/coronium/parse/slghparse.y"
                                { (yyval.starqual) = new StarQuality; (yyval.starqual)->size = *(yyvsp[0].i); delete (yyvsp[0].i); (yyval.starqual)->id=ConstTpl(slgh->getDefaultCodeSpace()); }
#line 3656 "/home/jnstaursky/Desktop/Personal-Projects/coronium/src/slghparse.cc"
    break;

  case 243:
#line 455 "/home/jnstaursky/Desktop/Personal-Projects/coronium/parse/slghparse.y"
                                { (yyval.starqual) = new StarQuality; (yyval.starqual)->size = 0; (yyval.starqual)->id=ConstTpl(slgh->getDefaultCodeSpace()); }
#line 3662 "/home/jnstaursky/Desktop/Personal-Projects/coronium/src/slghparse.cc"
    break;

  case 244:
#line 457 "/home/jnstaursky/Desktop/Personal-Projects/coronium/parse/slghparse.y"
                                { VarnodeTpl *sym = (yyvsp[0].startsym)->getVarnode(); (yyval.varnode) = new VarnodeTpl(ConstTpl(ConstTpl::j_curspace),sym->getOffset(),ConstTpl(ConstTpl::j_curspace_size)); delete sym; }
#line 3668 "/home/jnstaursky/Desktop/Personal-Projects/coronium/src/slghparse.cc"
    break;

  case 245:
#line 458 "/home/jnstaursky/Desktop/Personal-Projects/coronium/parse/slghparse.y"
                                { VarnodeTpl *sym = (yyvsp[0].endsym)->getVarnode(); (yyval.varnode) = new VarnodeTpl(ConstTpl(ConstTpl::j_curspace),sym->getOffset(),ConstTpl(ConstTpl::j_curspace_size)); delete sym; }
#line 3674 "/home/jnstaursky/Desktop/Personal-Projects/coronium/src/slghparse.cc"
    break;

  case 246:
#line 459 "/home/jnstaursky/Desktop/Personal-Projects/coronium/parse/slghparse.y"
                                { (yyval.varnode) = new VarnodeTpl(ConstTpl(ConstTpl::j_curspace),ConstTpl(ConstTpl::real,*(yyvsp[0].i)),ConstTpl(ConstTpl::j_curspace_size)); delete (yyvsp[0].i); }
#line 3680 "/home/jnstaursky/Desktop/Personal-Projects/coronium/src/slghparse.cc"
    break;

  case 247:
#line 460 "/home/jnstaursky/Desktop/Personal-Projects/coronium/parse/slghparse.y"
                                { (yyval.varnode) = new VarnodeTpl(ConstTpl(ConstTpl::j_curspace),ConstTpl(ConstTpl::real,0),ConstTpl(ConstTpl::j_curspace_size)); yyerror("Parsed integer is too big (overflow)"); }
#line 3686 "/home/jnstaursky/Desktop/Personal-Projects/coronium/src/slghparse.cc"
    break;

  case 248:
#line 461 "/home/jnstaursky/Desktop/Personal-Projects/coronium/parse/slghparse.y"
                                { (yyval.varnode) = (yyvsp[0].operandsym)->getVarnode(); (yyvsp[0].operandsym)->setCodeAddress(); }
#line 3692 "/home/jnstaursky/Desktop/Personal-Projects/coronium/src/slghparse.cc"
    break;

  case 249:
#line 462 "/home/jnstaursky/Desktop/Personal-Projects/coronium/parse/slghparse.y"
                                { AddrSpace *spc = (yyvsp[-1].spacesym)->getSpace(); (yyval.varnode) = new VarnodeTpl(ConstTpl(spc),ConstTpl(ConstTpl::real,*(yyvsp[-3].i)),ConstTpl(ConstTpl::real,spc->getAddrSize())); delete (yyvsp[-3].i); }
#line 3698 "/home/jnstaursky/Desktop/Personal-Projects/coronium/src/slghparse.cc"
    break;

  case 250:
#line 463 "/home/jnstaursky/Desktop/Personal-Projects/coronium/parse/slghparse.y"
                                { (yyval.varnode) = new VarnodeTpl(ConstTpl(slgh->getConstantSpace()),ConstTpl(ConstTpl::j_relative,(yyvsp[0].labelsym)->getIndex()),ConstTpl(ConstTpl::real,sizeof(uintm))); (yyvsp[0].labelsym)->incrementRefCount(); }
#line 3704 "/home/jnstaursky/Desktop/Personal-Projects/coronium/src/slghparse.cc"
    break;

  case 251:
#line 464 "/home/jnstaursky/Desktop/Personal-Projects/coronium/parse/slghparse.y"
                                { string errmsg = "Unknown jump destination: "+*(yyvsp[0].str); delete (yyvsp[0].str); yyerror(errmsg.c_str()); YYERROR; }
#line 3710 "/home/jnstaursky/Desktop/Personal-Projects/coronium/src/slghparse.cc"
    break;

  case 252:
#line 466 "/home/jnstaursky/Desktop/Personal-Projects/coronium/parse/slghparse.y"
                                { (yyval.varnode) = (yyvsp[0].specsym)->getVarnode(); }
#line 3716 "/home/jnstaursky/Desktop/Personal-Projects/coronium/src/slghparse.cc"
    break;

  case 253:
#line 467 "/home/jnstaursky/Desktop/Personal-Projects/coronium/parse/slghparse.y"
                                { (yyval.varnode) = (yyvsp[0].varnode); }
#line 3722 "/home/jnstaursky/Desktop/Personal-Projects/coronium/src/slghparse.cc"
    break;

  case 254:
#line 468 "/home/jnstaursky/Desktop/Personal-Projects/coronium/parse/slghparse.y"
                                { string errmsg = "Unknown varnode parameter: "+*(yyvsp[0].str); delete (yyvsp[0].str); yyerror(errmsg.c_str()); YYERROR; }
#line 3728 "/home/jnstaursky/Desktop/Personal-Projects/coronium/src/slghparse.cc"
    break;

  case 255:
#line 469 "/home/jnstaursky/Desktop/Personal-Projects/coronium/parse/slghparse.y"
                                { string errmsg = "Subtable not attached to operand: "+(yyvsp[0].subtablesym)->getName(); yyerror(errmsg.c_str()); YYERROR; }
#line 3734 "/home/jnstaursky/Desktop/Personal-Projects/coronium/src/slghparse.cc"
    break;

  case 256:
#line 471 "/home/jnstaursky/Desktop/Personal-Projects/coronium/parse/slghparse.y"
                                { (yyval.varnode) = new VarnodeTpl(ConstTpl(slgh->getConstantSpace()),ConstTpl(ConstTpl::real,*(yyvsp[0].i)),ConstTpl(ConstTpl::real,0)); delete (yyvsp[0].i); }
#line 3740 "/home/jnstaursky/Desktop/Personal-Projects/coronium/src/slghparse.cc"
    break;

  case 257:
#line 472 "/home/jnstaursky/Desktop/Personal-Projects/coronium/parse/slghparse.y"
                                { (yyval.varnode) = new VarnodeTpl(ConstTpl(slgh->getConstantSpace()),ConstTpl(ConstTpl::real,0),ConstTpl(ConstTpl::real,0)); yyerror("Parsed integer is too big (overflow)"); }
#line 3746 "/home/jnstaursky/Desktop/Personal-Projects/coronium/src/slghparse.cc"
    break;

  case 258:
#line 473 "/home/jnstaursky/Desktop/Personal-Projects/coronium/parse/slghparse.y"
                                { (yyval.varnode) = new VarnodeTpl(ConstTpl(slgh->getConstantSpace()),ConstTpl(ConstTpl::real,*(yyvsp[-2].i)),ConstTpl(ConstTpl::real,*(yyvsp[0].i))); delete (yyvsp[-2].i); delete (yyvsp[0].i); }
#line 3752 "/home/jnstaursky/Desktop/Personal-Projects/coronium/src/slghparse.cc"
    break;

  case 259:
#line 474 "/home/jnstaursky/Desktop/Personal-Projects/coronium/parse/slghparse.y"
                                { (yyval.varnode) = slgh->pcode.addressOf((yyvsp[0].varnode),0); }
#line 3758 "/home/jnstaursky/Desktop/Personal-Projects/coronium/src/slghparse.cc"
    break;

  case 260:
#line 475 "/home/jnstaursky/Desktop/Personal-Projects/coronium/parse/slghparse.y"
                                { (yyval.varnode) = slgh->pcode.addressOf((yyvsp[0].varnode),*(yyvsp[-1].i)); delete (yyvsp[-1].i); }
#line 3764 "/home/jnstaursky/Desktop/Personal-Projects/coronium/src/slghparse.cc"
    break;

  case 261:
#line 477 "/home/jnstaursky/Desktop/Personal-Projects/coronium/parse/slghparse.y"
                                { (yyval.varnode) = (yyvsp[0].specsym)->getVarnode(); }
#line 3770 "/home/jnstaursky/Desktop/Personal-Projects/coronium/src/slghparse.cc"
    break;

  case 262:
#line 478 "/home/jnstaursky/Desktop/Personal-Projects/coronium/parse/slghparse.y"
                                { string errmsg = "Unknown assignment varnode: "+*(yyvsp[0].str); delete (yyvsp[0].str); yyerror(errmsg.c_str()); YYERROR; }
#line 3776 "/home/jnstaursky/Desktop/Personal-Projects/coronium/src/slghparse.cc"
    break;

  case 263:
#line 479 "/home/jnstaursky/Desktop/Personal-Projects/coronium/parse/slghparse.y"
                                { string errmsg = "Subtable not attached to operand: "+(yyvsp[0].subtablesym)->getName(); yyerror(errmsg.c_str()); YYERROR; }
#line 3782 "/home/jnstaursky/Desktop/Personal-Projects/coronium/src/slghparse.cc"
    break;

  case 264:
#line 481 "/home/jnstaursky/Desktop/Personal-Projects/coronium/parse/slghparse.y"
                                { (yyval.labelsym) = (yyvsp[-1].labelsym); }
#line 3788 "/home/jnstaursky/Desktop/Personal-Projects/coronium/src/slghparse.cc"
    break;

  case 265:
#line 482 "/home/jnstaursky/Desktop/Personal-Projects/coronium/parse/slghparse.y"
                                { (yyval.labelsym) = slgh->pcode.defineLabel( (yyvsp[-1].str) ); }
#line 3794 "/home/jnstaursky/Desktop/Personal-Projects/coronium/src/slghparse.cc"
    break;

  case 266:
#line 484 "/home/jnstaursky/Desktop/Personal-Projects/coronium/parse/slghparse.y"
                                { (yyval.varnode) = (yyvsp[0].specsym)->getVarnode(); }
#line 3800 "/home/jnstaursky/Desktop/Personal-Projects/coronium/src/slghparse.cc"
    break;

  case 267:
#line 485 "/home/jnstaursky/Desktop/Personal-Projects/coronium/parse/slghparse.y"
                                { (yyval.varnode) = slgh->pcode.addressOf((yyvsp[0].varnode),0); }
#line 3806 "/home/jnstaursky/Desktop/Personal-Projects/coronium/src/slghparse.cc"
    break;

  case 268:
#line 486 "/home/jnstaursky/Desktop/Personal-Projects/coronium/parse/slghparse.y"
                                { (yyval.varnode) = slgh->pcode.addressOf((yyvsp[0].varnode),*(yyvsp[-1].i)); delete (yyvsp[-1].i); }
#line 3812 "/home/jnstaursky/Desktop/Personal-Projects/coronium/src/slghparse.cc"
    break;

  case 269:
#line 487 "/home/jnstaursky/Desktop/Personal-Projects/coronium/parse/slghparse.y"
                                { (yyval.varnode) = new VarnodeTpl(ConstTpl(slgh->getConstantSpace()),ConstTpl(ConstTpl::real,*(yyvsp[-2].i)),ConstTpl(ConstTpl::real,*(yyvsp[0].i))); delete (yyvsp[-2].i); delete (yyvsp[0].i); }
#line 3818 "/home/jnstaursky/Desktop/Personal-Projects/coronium/src/slghparse.cc"
    break;

  case 270:
#line 488 "/home/jnstaursky/Desktop/Personal-Projects/coronium/parse/slghparse.y"
                                { string errmsg="Unknown export varnode: "+*(yyvsp[0].str); delete (yyvsp[0].str); yyerror(errmsg.c_str()); YYERROR; }
#line 3824 "/home/jnstaursky/Desktop/Personal-Projects/coronium/src/slghparse.cc"
    break;

  case 271:
#line 489 "/home/jnstaursky/Desktop/Personal-Projects/coronium/parse/slghparse.y"
                                { string errmsg = "Subtable not attached to operand: "+(yyvsp[0].subtablesym)->getName(); yyerror(errmsg.c_str()); YYERROR; }
#line 3830 "/home/jnstaursky/Desktop/Personal-Projects/coronium/src/slghparse.cc"
    break;

  case 272:
#line 491 "/home/jnstaursky/Desktop/Personal-Projects/coronium/parse/slghparse.y"
                                { (yyval.famsym) = (yyvsp[0].valuesym); }
#line 3836 "/home/jnstaursky/Desktop/Personal-Projects/coronium/src/slghparse.cc"
    break;

  case 273:
#line 492 "/home/jnstaursky/Desktop/Personal-Projects/coronium/parse/slghparse.y"
                                { (yyval.famsym) = (yyvsp[0].valuemapsym); }
#line 3842 "/home/jnstaursky/Desktop/Personal-Projects/coronium/src/slghparse.cc"
    break;

  case 274:
#line 493 "/home/jnstaursky/Desktop/Personal-Projects/coronium/parse/slghparse.y"
                                { (yyval.famsym) = (yyvsp[0].contextsym); }
#line 3848 "/home/jnstaursky/Desktop/Personal-Projects/coronium/src/slghparse.cc"
    break;

  case 275:
#line 494 "/home/jnstaursky/Desktop/Personal-Projects/coronium/parse/slghparse.y"
                                { (yyval.famsym) = (yyvsp[0].namesym); }
#line 3854 "/home/jnstaursky/Desktop/Personal-Projects/coronium/src/slghparse.cc"
    break;

  case 276:
#line 495 "/home/jnstaursky/Desktop/Personal-Projects/coronium/parse/slghparse.y"
                                { (yyval.famsym) = (yyvsp[0].varlistsym); }
#line 3860 "/home/jnstaursky/Desktop/Personal-Projects/coronium/src/slghparse.cc"
    break;

  case 277:
#line 497 "/home/jnstaursky/Desktop/Personal-Projects/coronium/parse/slghparse.y"
                                { (yyval.specsym) = (yyvsp[0].varsym); }
#line 3866 "/home/jnstaursky/Desktop/Personal-Projects/coronium/src/slghparse.cc"
    break;

  case 278:
#line 498 "/home/jnstaursky/Desktop/Personal-Projects/coronium/parse/slghparse.y"
                                { (yyval.specsym) = (yyvsp[0].specsym); }
#line 3872 "/home/jnstaursky/Desktop/Personal-Projects/coronium/src/slghparse.cc"
    break;

  case 279:
#line 499 "/home/jnstaursky/Desktop/Personal-Projects/coronium/parse/slghparse.y"
                                { (yyval.specsym) = (yyvsp[0].operandsym); }
#line 3878 "/home/jnstaursky/Desktop/Personal-Projects/coronium/src/slghparse.cc"
    break;

  case 280:
#line 500 "/home/jnstaursky/Desktop/Personal-Projects/coronium/parse/slghparse.y"
                                { (yyval.specsym) = (yyvsp[0].startsym); }
#line 3884 "/home/jnstaursky/Desktop/Personal-Projects/coronium/src/slghparse.cc"
    break;

  case 281:
#line 501 "/home/jnstaursky/Desktop/Personal-Projects/coronium/parse/slghparse.y"
                                { (yyval.specsym) = (yyvsp[0].endsym); }
#line 3890 "/home/jnstaursky/Desktop/Personal-Projects/coronium/src/slghparse.cc"
    break;

  case 282:
#line 503 "/home/jnstaursky/Desktop/Personal-Projects/coronium/parse/slghparse.y"
                                { (yyval.str) = new string; (*(yyval.str)) += (yyvsp[0].ch); }
#line 3896 "/home/jnstaursky/Desktop/Personal-Projects/coronium/src/slghparse.cc"
    break;

  case 283:
#line 504 "/home/jnstaursky/Desktop/Personal-Projects/coronium/parse/slghparse.y"
                                { (yyval.str) = (yyvsp[-1].str); (*(yyval.str)) += (yyvsp[0].ch); }
#line 3902 "/home/jnstaursky/Desktop/Personal-Projects/coronium/src/slghparse.cc"
    break;

  case 284:
#line 506 "/home/jnstaursky/Desktop/Personal-Projects/coronium/parse/slghparse.y"
                                { (yyval.biglist) = (yyvsp[-1].biglist); }
#line 3908 "/home/jnstaursky/Desktop/Personal-Projects/coronium/src/slghparse.cc"
    break;

  case 285:
#line 507 "/home/jnstaursky/Desktop/Personal-Projects/coronium/parse/slghparse.y"
                                { (yyval.biglist) = new vector<intb>; (yyval.biglist)->push_back(intb(*(yyvsp[0].i))); delete (yyvsp[0].i); }
#line 3914 "/home/jnstaursky/Desktop/Personal-Projects/coronium/src/slghparse.cc"
    break;

  case 286:
#line 508 "/home/jnstaursky/Desktop/Personal-Projects/coronium/parse/slghparse.y"
                                { (yyval.biglist) = new vector<intb>; (yyval.biglist)->push_back(-intb(*(yyvsp[0].i))); delete (yyvsp[0].i); }
#line 3920 "/home/jnstaursky/Desktop/Personal-Projects/coronium/src/slghparse.cc"
    break;

  case 287:
#line 510 "/home/jnstaursky/Desktop/Personal-Projects/coronium/parse/slghparse.y"
                                { (yyval.biglist) = new vector<intb>; (yyval.biglist)->push_back(intb(*(yyvsp[0].i))); delete (yyvsp[0].i); }
#line 3926 "/home/jnstaursky/Desktop/Personal-Projects/coronium/src/slghparse.cc"
    break;

  case 288:
#line 511 "/home/jnstaursky/Desktop/Personal-Projects/coronium/parse/slghparse.y"
                                { (yyval.biglist) = new vector<intb>; (yyval.biglist)->push_back(-intb(*(yyvsp[0].i))); delete (yyvsp[0].i); }
#line 3932 "/home/jnstaursky/Desktop/Personal-Projects/coronium/src/slghparse.cc"
    break;

  case 289:
#line 512 "/home/jnstaursky/Desktop/Personal-Projects/coronium/parse/slghparse.y"
                                { if (*(yyvsp[0].str)!="_") { string errmsg = "Expecting integer but saw: "+*(yyvsp[0].str); delete (yyvsp[0].str); yyerror(errmsg.c_str()); YYERROR; }
                                  (yyval.biglist) = new vector<intb>; (yyval.biglist)->push_back((intb)0xBADBEEF); delete (yyvsp[0].str); }
#line 3939 "/home/jnstaursky/Desktop/Personal-Projects/coronium/src/slghparse.cc"
    break;

  case 290:
#line 514 "/home/jnstaursky/Desktop/Personal-Projects/coronium/parse/slghparse.y"
                                { (yyval.biglist) = (yyvsp[-1].biglist); (yyval.biglist)->push_back(intb(*(yyvsp[0].i))); delete (yyvsp[0].i); }
#line 3945 "/home/jnstaursky/Desktop/Personal-Projects/coronium/src/slghparse.cc"
    break;

  case 291:
#line 515 "/home/jnstaursky/Desktop/Personal-Projects/coronium/parse/slghparse.y"
                                { (yyval.biglist) = (yyvsp[-2].biglist); (yyval.biglist)->push_back(-intb(*(yyvsp[0].i))); delete (yyvsp[0].i); }
#line 3951 "/home/jnstaursky/Desktop/Personal-Projects/coronium/src/slghparse.cc"
    break;

  case 292:
#line 516 "/home/jnstaursky/Desktop/Personal-Projects/coronium/parse/slghparse.y"
                                { if (*(yyvsp[0].str)!="_") { string errmsg = "Expecting integer but saw: "+*(yyvsp[0].str); delete (yyvsp[0].str); yyerror(errmsg.c_str()); YYERROR; }
                                  (yyval.biglist) = (yyvsp[-1].biglist); (yyval.biglist)->push_back((intb)0xBADBEEF); delete (yyvsp[0].str); }
#line 3958 "/home/jnstaursky/Desktop/Personal-Projects/coronium/src/slghparse.cc"
    break;

  case 293:
#line 519 "/home/jnstaursky/Desktop/Personal-Projects/coronium/parse/slghparse.y"
                                { (yyval.strlist) = (yyvsp[-1].strlist); }
#line 3964 "/home/jnstaursky/Desktop/Personal-Projects/coronium/src/slghparse.cc"
    break;

  case 294:
#line 520 "/home/jnstaursky/Desktop/Personal-Projects/coronium/parse/slghparse.y"
                                { (yyval.strlist) = new vector<string>; (yyval.strlist)->push_back(*(yyvsp[0].str)); delete (yyvsp[0].str); }
#line 3970 "/home/jnstaursky/Desktop/Personal-Projects/coronium/src/slghparse.cc"
    break;

  case 295:
#line 522 "/home/jnstaursky/Desktop/Personal-Projects/coronium/parse/slghparse.y"
                                { (yyval.strlist) = new vector<string>; (yyval.strlist)->push_back( *(yyvsp[0].str) ); delete (yyvsp[0].str); }
#line 3976 "/home/jnstaursky/Desktop/Personal-Projects/coronium/src/slghparse.cc"
    break;

  case 296:
#line 523 "/home/jnstaursky/Desktop/Personal-Projects/coronium/parse/slghparse.y"
                                { (yyval.strlist) = (yyvsp[-1].strlist); (yyval.strlist)->push_back(*(yyvsp[0].str)); delete (yyvsp[0].str); }
#line 3982 "/home/jnstaursky/Desktop/Personal-Projects/coronium/src/slghparse.cc"
    break;

  case 297:
#line 524 "/home/jnstaursky/Desktop/Personal-Projects/coronium/parse/slghparse.y"
                                { string errmsg = (yyvsp[0].anysym)->getName()+": redefined"; yyerror(errmsg.c_str()); YYERROR; }
#line 3988 "/home/jnstaursky/Desktop/Personal-Projects/coronium/src/slghparse.cc"
    break;

  case 298:
#line 526 "/home/jnstaursky/Desktop/Personal-Projects/coronium/parse/slghparse.y"
                                     { (yyval.strlist) = (yyvsp[-1].strlist); }
#line 3994 "/home/jnstaursky/Desktop/Personal-Projects/coronium/src/slghparse.cc"
    break;

  case 299:
#line 528 "/home/jnstaursky/Desktop/Personal-Projects/coronium/parse/slghparse.y"
                                { (yyval.strlist) = new vector<string>; (yyval.strlist)->push_back( *(yyvsp[0].str) ); delete (yyvsp[0].str); }
#line 4000 "/home/jnstaursky/Desktop/Personal-Projects/coronium/src/slghparse.cc"
    break;

  case 300:
#line 529 "/home/jnstaursky/Desktop/Personal-Projects/coronium/parse/slghparse.y"
                                { (yyval.strlist) = new vector<string>; (yyval.strlist)->push_back( (yyvsp[0].anysym)->getName() ); }
#line 4006 "/home/jnstaursky/Desktop/Personal-Projects/coronium/src/slghparse.cc"
    break;

  case 301:
#line 530 "/home/jnstaursky/Desktop/Personal-Projects/coronium/parse/slghparse.y"
                                { (yyval.strlist) = (yyvsp[-1].strlist); (yyval.strlist)->push_back(*(yyvsp[0].str)); delete (yyvsp[0].str); }
#line 4012 "/home/jnstaursky/Desktop/Personal-Projects/coronium/src/slghparse.cc"
    break;

  case 302:
#line 531 "/home/jnstaursky/Desktop/Personal-Projects/coronium/parse/slghparse.y"
                                { (yyval.strlist) = (yyvsp[-1].strlist); (yyval.strlist)->push_back((yyvsp[0].anysym)->getName()); }
#line 4018 "/home/jnstaursky/Desktop/Personal-Projects/coronium/src/slghparse.cc"
    break;

  case 303:
#line 533 "/home/jnstaursky/Desktop/Personal-Projects/coronium/parse/slghparse.y"
                                { (yyval.symlist) = (yyvsp[-1].symlist); }
#line 4024 "/home/jnstaursky/Desktop/Personal-Projects/coronium/src/slghparse.cc"
    break;

  case 304:
#line 534 "/home/jnstaursky/Desktop/Personal-Projects/coronium/parse/slghparse.y"
                                { (yyval.symlist) = new vector<SleighSymbol *>; (yyval.symlist)->push_back((yyvsp[0].valuesym)); }
#line 4030 "/home/jnstaursky/Desktop/Personal-Projects/coronium/src/slghparse.cc"
    break;

  case 305:
#line 535 "/home/jnstaursky/Desktop/Personal-Projects/coronium/parse/slghparse.y"
                                { (yyval.symlist) = new vector<SleighSymbol *>; (yyval.symlist)->push_back((yyvsp[0].contextsym)); }
#line 4036 "/home/jnstaursky/Desktop/Personal-Projects/coronium/src/slghparse.cc"
    break;

  case 306:
#line 537 "/home/jnstaursky/Desktop/Personal-Projects/coronium/parse/slghparse.y"
                                { (yyval.symlist) = new vector<SleighSymbol *>; (yyval.symlist)->push_back( (yyvsp[0].valuesym) ); }
#line 4042 "/home/jnstaursky/Desktop/Personal-Projects/coronium/src/slghparse.cc"
    break;

  case 307:
#line 538 "/home/jnstaursky/Desktop/Personal-Projects/coronium/parse/slghparse.y"
                                { (yyval.symlist) = new vector<SleighSymbol *>; (yyval.symlist)->push_back((yyvsp[0].contextsym)); }
#line 4048 "/home/jnstaursky/Desktop/Personal-Projects/coronium/src/slghparse.cc"
    break;

  case 308:
#line 539 "/home/jnstaursky/Desktop/Personal-Projects/coronium/parse/slghparse.y"
                                { (yyval.symlist) = (yyvsp[-1].symlist); (yyval.symlist)->push_back((yyvsp[0].valuesym)); }
#line 4054 "/home/jnstaursky/Desktop/Personal-Projects/coronium/src/slghparse.cc"
    break;

  case 309:
#line 540 "/home/jnstaursky/Desktop/Personal-Projects/coronium/parse/slghparse.y"
                                { (yyval.symlist) = (yyvsp[-1].symlist); (yyval.symlist)->push_back((yyvsp[0].contextsym)); }
#line 4060 "/home/jnstaursky/Desktop/Personal-Projects/coronium/src/slghparse.cc"
    break;

  case 310:
#line 541 "/home/jnstaursky/Desktop/Personal-Projects/coronium/parse/slghparse.y"
                                { string errmsg = *(yyvsp[0].str)+": is not a value pattern"; delete (yyvsp[0].str); yyerror(errmsg.c_str()); YYERROR; }
#line 4066 "/home/jnstaursky/Desktop/Personal-Projects/coronium/src/slghparse.cc"
    break;

  case 311:
#line 543 "/home/jnstaursky/Desktop/Personal-Projects/coronium/parse/slghparse.y"
                                { (yyval.symlist) = (yyvsp[-1].symlist); }
#line 4072 "/home/jnstaursky/Desktop/Personal-Projects/coronium/src/slghparse.cc"
    break;

  case 312:
#line 544 "/home/jnstaursky/Desktop/Personal-Projects/coronium/parse/slghparse.y"
                                { (yyval.symlist) = new vector<SleighSymbol *>; (yyval.symlist)->push_back((yyvsp[0].varsym)); }
#line 4078 "/home/jnstaursky/Desktop/Personal-Projects/coronium/src/slghparse.cc"
    break;

  case 313:
#line 546 "/home/jnstaursky/Desktop/Personal-Projects/coronium/parse/slghparse.y"
                                { (yyval.symlist) = new vector<SleighSymbol *>; (yyval.symlist)->push_back((yyvsp[0].varsym)); }
#line 4084 "/home/jnstaursky/Desktop/Personal-Projects/coronium/src/slghparse.cc"
    break;

  case 314:
#line 547 "/home/jnstaursky/Desktop/Personal-Projects/coronium/parse/slghparse.y"
                                { if (*(yyvsp[0].str)!="_") { string errmsg = *(yyvsp[0].str)+": is not a varnode symbol"; delete (yyvsp[0].str); yyerror(errmsg.c_str()); YYERROR; }
				  (yyval.symlist) = new vector<SleighSymbol *>; (yyval.symlist)->push_back((SleighSymbol *)0); delete (yyvsp[0].str); }
#line 4091 "/home/jnstaursky/Desktop/Personal-Projects/coronium/src/slghparse.cc"
    break;

  case 315:
#line 549 "/home/jnstaursky/Desktop/Personal-Projects/coronium/parse/slghparse.y"
                                { (yyval.symlist) = (yyvsp[-1].symlist); (yyval.symlist)->push_back((yyvsp[0].varsym)); }
#line 4097 "/home/jnstaursky/Desktop/Personal-Projects/coronium/src/slghparse.cc"
    break;

  case 316:
#line 550 "/home/jnstaursky/Desktop/Personal-Projects/coronium/parse/slghparse.y"
                                { if (*(yyvsp[0].str)!="_") { string errmsg = *(yyvsp[0].str)+": is not a varnode symbol"; delete (yyvsp[0].str); yyerror(errmsg.c_str()); YYERROR; }
                                  (yyval.symlist) = (yyvsp[-1].symlist); (yyval.symlist)->push_back((SleighSymbol *)0); delete (yyvsp[0].str); }
#line 4104 "/home/jnstaursky/Desktop/Personal-Projects/coronium/src/slghparse.cc"
    break;

  case 317:
#line 553 "/home/jnstaursky/Desktop/Personal-Projects/coronium/parse/slghparse.y"
                                { (yyval.param) = new vector<ExprTree *>; }
#line 4110 "/home/jnstaursky/Desktop/Personal-Projects/coronium/src/slghparse.cc"
    break;

  case 318:
#line 554 "/home/jnstaursky/Desktop/Personal-Projects/coronium/parse/slghparse.y"
                                { (yyval.param) = new vector<ExprTree *>; (yyval.param)->push_back((yyvsp[0].tree)); }
#line 4116 "/home/jnstaursky/Desktop/Personal-Projects/coronium/src/slghparse.cc"
    break;

  case 319:
#line 555 "/home/jnstaursky/Desktop/Personal-Projects/coronium/parse/slghparse.y"
                                { (yyval.param) = (yyvsp[-2].param); (yyval.param)->push_back((yyvsp[0].tree)); }
#line 4122 "/home/jnstaursky/Desktop/Personal-Projects/coronium/src/slghparse.cc"
    break;

  case 320:
#line 557 "/home/jnstaursky/Desktop/Personal-Projects/coronium/parse/slghparse.y"
                                { (yyval.strlist) = new vector<string>; }
#line 4128 "/home/jnstaursky/Desktop/Personal-Projects/coronium/src/slghparse.cc"
    break;

  case 321:
#line 558 "/home/jnstaursky/Desktop/Personal-Projects/coronium/parse/slghparse.y"
                                { (yyval.strlist) = new vector<string>; (yyval.strlist)->push_back(*(yyvsp[0].str)); delete (yyvsp[0].str); }
#line 4134 "/home/jnstaursky/Desktop/Personal-Projects/coronium/src/slghparse.cc"
    break;

  case 322:
#line 559 "/home/jnstaursky/Desktop/Personal-Projects/coronium/parse/slghparse.y"
                                { (yyval.strlist) = (yyvsp[-2].strlist); (yyval.strlist)->push_back(*(yyvsp[0].str)); delete (yyvsp[0].str); }
#line 4140 "/home/jnstaursky/Desktop/Personal-Projects/coronium/src/slghparse.cc"
    break;

  case 323:
#line 561 "/home/jnstaursky/Desktop/Personal-Projects/coronium/parse/slghparse.y"
                                { (yyval.anysym) = (yyvsp[0].spacesym); }
#line 4146 "/home/jnstaursky/Desktop/Personal-Projects/coronium/src/slghparse.cc"
    break;

  case 324:
#line 562 "/home/jnstaursky/Desktop/Personal-Projects/coronium/parse/slghparse.y"
                                { (yyval.anysym) = (yyvsp[0].sectionsym); }
#line 4152 "/home/jnstaursky/Desktop/Personal-Projects/coronium/src/slghparse.cc"
    break;

  case 325:
#line 563 "/home/jnstaursky/Desktop/Personal-Projects/coronium/parse/slghparse.y"
                                { (yyval.anysym) = (yyvsp[0].tokensym); }
#line 4158 "/home/jnstaursky/Desktop/Personal-Projects/coronium/src/slghparse.cc"
    break;

  case 326:
#line 564 "/home/jnstaursky/Desktop/Personal-Projects/coronium/parse/slghparse.y"
                                { (yyval.anysym) = (yyvsp[0].useropsym); }
#line 4164 "/home/jnstaursky/Desktop/Personal-Projects/coronium/src/slghparse.cc"
    break;

  case 327:
#line 565 "/home/jnstaursky/Desktop/Personal-Projects/coronium/parse/slghparse.y"
                                { (yyval.anysym) = (yyvsp[0].macrosym); }
#line 4170 "/home/jnstaursky/Desktop/Personal-Projects/coronium/src/slghparse.cc"
    break;

  case 328:
#line 566 "/home/jnstaursky/Desktop/Personal-Projects/coronium/parse/slghparse.y"
                                { (yyval.anysym) = (yyvsp[0].subtablesym); }
#line 4176 "/home/jnstaursky/Desktop/Personal-Projects/coronium/src/slghparse.cc"
    break;

  case 329:
#line 567 "/home/jnstaursky/Desktop/Personal-Projects/coronium/parse/slghparse.y"
                                { (yyval.anysym) = (yyvsp[0].valuesym); }
#line 4182 "/home/jnstaursky/Desktop/Personal-Projects/coronium/src/slghparse.cc"
    break;

  case 330:
#line 568 "/home/jnstaursky/Desktop/Personal-Projects/coronium/parse/slghparse.y"
                                { (yyval.anysym) = (yyvsp[0].valuemapsym); }
#line 4188 "/home/jnstaursky/Desktop/Personal-Projects/coronium/src/slghparse.cc"
    break;

  case 331:
#line 569 "/home/jnstaursky/Desktop/Personal-Projects/coronium/parse/slghparse.y"
                                { (yyval.anysym) = (yyvsp[0].contextsym); }
#line 4194 "/home/jnstaursky/Desktop/Personal-Projects/coronium/src/slghparse.cc"
    break;

  case 332:
#line 570 "/home/jnstaursky/Desktop/Personal-Projects/coronium/parse/slghparse.y"
                                { (yyval.anysym) = (yyvsp[0].namesym); }
#line 4200 "/home/jnstaursky/Desktop/Personal-Projects/coronium/src/slghparse.cc"
    break;

  case 333:
#line 571 "/home/jnstaursky/Desktop/Personal-Projects/coronium/parse/slghparse.y"
                                { (yyval.anysym) = (yyvsp[0].varsym); }
#line 4206 "/home/jnstaursky/Desktop/Personal-Projects/coronium/src/slghparse.cc"
    break;

  case 334:
#line 572 "/home/jnstaursky/Desktop/Personal-Projects/coronium/parse/slghparse.y"
                                { (yyval.anysym) = (yyvsp[0].varlistsym); }
#line 4212 "/home/jnstaursky/Desktop/Personal-Projects/coronium/src/slghparse.cc"
    break;

  case 335:
#line 573 "/home/jnstaursky/Desktop/Personal-Projects/coronium/parse/slghparse.y"
                                { (yyval.anysym) = (yyvsp[0].operandsym); }
#line 4218 "/home/jnstaursky/Desktop/Personal-Projects/coronium/src/slghparse.cc"
    break;

  case 336:
#line 574 "/home/jnstaursky/Desktop/Personal-Projects/coronium/parse/slghparse.y"
                                { (yyval.anysym) = (yyvsp[0].startsym); }
#line 4224 "/home/jnstaursky/Desktop/Personal-Projects/coronium/src/slghparse.cc"
    break;

  case 337:
#line 575 "/home/jnstaursky/Desktop/Personal-Projects/coronium/parse/slghparse.y"
                                { (yyval.anysym) = (yyvsp[0].endsym); }
#line 4230 "/home/jnstaursky/Desktop/Personal-Projects/coronium/src/slghparse.cc"
    break;

  case 338:
#line 576 "/home/jnstaursky/Desktop/Personal-Projects/coronium/parse/slghparse.y"
                                { (yyval.anysym) = (yyvsp[0].bitsym); }
#line 4236 "/home/jnstaursky/Desktop/Personal-Projects/coronium/src/slghparse.cc"
    break;


#line 4240 "/home/jnstaursky/Desktop/Personal-Projects/coronium/src/slghparse.cc"

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
  {
    const int yylhs = yyr1[yyn] - YYNTOKENS;
    const int yyi = yypgoto[yylhs] + *yyssp;
    yystate = (0 <= yyi && yyi <= YYLAST && yycheck[yyi] == *yyssp
               ? yytable[yyi]
               : yydefgoto[yylhs]);
  }

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
            yymsg = YY_CAST (char *, YYSTACK_ALLOC (YY_CAST (YYSIZE_T, yymsg_alloc)));
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
  /* Pacify compilers when the user code never invokes YYERROR and the
     label yyerrorlab therefore never appears in user code.  */
  if (0)
    YYERROR;

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


/*-----------------------------------------------------.
| yyreturn -- parsing is finished, return the result.  |
`-----------------------------------------------------*/
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
                  yystos[+*yyssp], yyvsp);
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
#line 578 "/home/jnstaursky/Desktop/Personal-Projects/coronium/parse/slghparse.y"


int yyerror(const char *s)

{
  slgh->reportError(s);
  return 0;
}
