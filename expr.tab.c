/* A Bison parser, made by GNU Bison 3.0.4.  */

/* Bison implementation for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2015 Free Software Foundation, Inc.

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
#define YYBISON_VERSION "3.0.4"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1




/* Copy the first part of user declarations.  */
#line 1 "expr.y" /* yacc.c:339  */

#include <stdio.h>
#include <stdlib.h>
#include "funcoes.h"
#define YYSTYPE struct Atributos
int linha = 1;
int pos = 1;
int posF = 0;
int inFunction = 0;

#line 77 "expr.tab.c" /* yacc.c:339  */

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
    TADD = 258,
    TMUL = 259,
    TSUB = 260,
    TDIV = 261,
    TAPAR = 262,
    TFPAR = 263,
    TNUM = 264,
    TMENOR = 265,
    TMAIOR = 266,
    TMENORIG = 267,
    TMAIORIG = 268,
    TIGUAL = 269,
    TDIF = 270,
    TAND = 271,
    TOR = 272,
    TNOT = 273,
    TID = 274,
    TACH = 275,
    TFCH = 276,
    TVOID = 277,
    TINT = 278,
    TSTRING = 279,
    TFLOAT = 280,
    TRETURN = 281,
    TPEV = 282,
    TATRIB = 283,
    TIF = 284,
    TWHILE = 285,
    TELSE = 286,
    TPRINT = 287,
    TREAD = 288,
    TLITERAL = 289,
    TVIR = 290,
    TSINC = 291,
    TSDEC = 292,
    TSMUL = 293,
    TSDIV = 294,
    TAADD = 295,
    TSSUB = 296,
    TFOR = 297
  };
#endif

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef int YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);



/* Copy the second part of user declarations.  */

#line 168 "expr.tab.c" /* yacc.c:358  */

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
#define YYFINAL  35
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   231

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  43
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  33
/* YYNRULES -- Number of rules.  */
#define YYNRULES  83
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  164

/* YYTRANSLATE[YYX] -- Symbol number corresponding to YYX as returned
   by yylex, with out-of-bounds checking.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   297

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
      35,    36,    37,    38,    39,    40,    41,    42
};

#if YYDEBUG
  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_uint8 yyrline[] =
{
       0,    17,    17,    20,    21,    24,    25,    28,    31,    32,
      35,    36,    39,    40,    43,    47,    48,    51,    52,    55,
      58,    59,    60,    63,    64,    67,    70,    71,    74,    75,
      76,    77,    78,    79,    80,    81,    84,    85,    88,    89,
      92,    95,    98,    99,   100,   101,   102,   103,   104,   105,
     106,   109,   110,   113,   116,   119,   120,   123,   124,   125,
     126,   129,   130,   131,   134,   135,   136,   139,   140,   141,
     142,   145,   146,   147,   148,   149,   150,   153,   154,   155,
     158,   159,   160,   161
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || 0
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "TADD", "TMUL", "TSUB", "TDIV", "TAPAR",
  "TFPAR", "TNUM", "TMENOR", "TMAIOR", "TMENORIG", "TMAIORIG", "TIGUAL",
  "TDIF", "TAND", "TOR", "TNOT", "TID", "TACH", "TFCH", "TVOID", "TINT",
  "TSTRING", "TFLOAT", "TRETURN", "TPEV", "TATRIB", "TIF", "TWHILE",
  "TELSE", "TPRINT", "TREAD", "TLITERAL", "TVIR", "TSINC", "TSDEC",
  "TSMUL", "TSDIV", "TAADD", "TSSUB", "TFOR", "$accept", "Linha",
  "Programa", "ListaFuncoes", "Funcao", "DeclFuncao", "TipoRetorno",
  "DeclParametros", "Parametro", "BlocoPrincipal", "Declaracoes",
  "Declaracao", "Tipo", "ListaId", "Bloco", "ListaCmd", "Comando",
  "Retorno", "CmdSe", "CmdEnquanto", "CmdFor", "CmdAtrib", "CmdEscrita",
  "CmdLeitura", "ChamadaProc", "ChamadaFuncao", "ListaParametros",
  "ExprAritmetica", "Termo", "Fator", "ExprRelacional", "ExprLogica",
  "ExprLogicaT2", YY_NULLPTR
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
     295,   296,   297
};
# endif

#define YYPACT_NINF -122

#define yypact_value_is_default(Yystate) \
  (!!((Yystate) == (-122)))

#define YYTABLE_NINF -1

#define yytable_value_is_error(Yytable_value) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
     200,    99,  -122,  -122,  -122,  -122,    15,  -122,   200,  -122,
      23,    30,  -122,  -122,    14,    56,    50,    61,    93,    97,
     106,    99,  -122,    67,   116,  -122,  -122,  -122,  -122,  -122,
      89,  -122,  -122,  -122,  -122,  -122,  -122,  -122,  -122,   113,
      51,    57,   180,   180,   180,   180,  -122,  -122,   180,   180,
    -122,  -122,   117,     7,    68,  -122,    96,    96,    64,   107,
     121,  -122,   131,  -122,    -8,  -122,  -122,  -122,     1,  -122,
    -122,     0,    90,   129,  -122,  -122,    90,    90,    90,    90,
      90,  -122,    79,  -122,   180,   180,  -122,   180,   180,    96,
      96,   216,  -122,     6,  -122,   122,   135,   163,   143,   164,
     126,  -122,  -122,   140,  -122,     5,  -122,   150,  -122,    87,
    -122,    68,    68,  -122,  -122,   203,   139,   216,  -122,   180,
     180,   180,   180,   180,   180,   134,    96,    96,   134,   147,
     155,   159,    96,  -122,  -122,    -7,  -122,  -122,    90,  -122,
      90,    90,    90,    90,    90,    90,   151,   160,  -122,  -122,
    -122,  -122,  -122,  -122,    72,  -122,   146,   134,   121,  -122,
    -122,   154,   134,  -122
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       0,     0,    11,    20,    21,    22,     0,     2,     0,     6,
       0,     0,     4,    10,     0,     0,     0,     0,     0,     0,
       0,     0,    18,     0,     0,    27,    35,    28,    29,    30,
       0,    32,    33,    34,    54,     1,     5,     3,     7,     0,
       0,     0,     0,     0,     0,     0,    49,    50,     0,     0,
      67,    68,     0,     0,    63,    66,     0,     0,     0,     0,
       0,    17,     0,    24,     0,    16,    26,    31,     0,    56,
      60,     0,    59,    68,    43,    44,    42,    45,    46,    47,
      48,    70,     0,    37,     0,     0,    36,     0,     0,     0,
       0,     0,    83,     0,    79,     0,     0,     0,     0,     0,
       0,    15,    19,     0,     9,     0,    13,     0,    55,     0,
      69,    61,    62,    64,    65,     0,     0,    82,    81,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    23,     8,     0,    14,    58,    57,    80,
      71,    72,    73,    74,    75,    76,     0,    38,    77,    78,
      40,    52,    51,    53,     0,    12,     0,     0,     0,    25,
      39,     0,     0,    41
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -122,  -122,  -122,  -122,   182,  -122,  -122,  -122,    59,   109,
    -122,   174,    -1,  -122,  -121,   -19,   -23,  -122,  -122,  -122,
    -122,   -56,  -122,  -122,   156,  -122,  -122,   -12,    -5,   -43,
    -122,   -51,   -79
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     6,     7,     8,     9,    10,    11,   105,   106,    12,
      21,    22,    13,    64,   147,    24,    25,    26,    27,    28,
      29,    30,    31,    32,    33,    34,    71,    91,    54,    55,
      92,    93,    94
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_uint8 yytable[] =
{
      23,    66,    62,    53,   100,    81,    95,   150,   108,   104,
      84,   118,    85,   134,   125,    35,     3,     4,     5,   102,
      23,    40,   126,   127,     3,     4,     5,   103,    72,    76,
      77,    78,    79,    80,    86,   109,   160,    82,   116,    66,
     135,   163,    41,     1,   113,   114,    97,   148,   149,    39,
      42,    43,    44,    45,    46,    47,    48,    56,    49,    69,
      50,    48,    48,    49,    49,    50,    50,   107,    57,    48,
      51,    49,    87,    50,    88,    51,    73,   115,   117,   111,
     112,   154,    84,    51,    85,    70,    63,   110,   126,   127,
      52,    74,    48,    84,    49,    85,    50,   138,    96,   158,
      58,    48,   161,    89,    59,    50,    51,   140,   141,   142,
     143,   144,   145,    60,    90,    51,    67,    37,    14,    38,
      68,   137,     3,     4,     5,    15,    98,   156,    16,    17,
     128,    18,    19,    66,   107,    14,    40,    65,   126,   127,
      99,    20,    15,   129,    83,    16,    17,   139,    18,    19,
      14,   131,   101,   132,   146,   126,   127,    15,    20,   133,
      16,    17,   162,    18,    19,    14,    84,   159,    85,   136,
      14,   130,    15,    20,   151,    16,    17,    15,    18,    19,
      16,    17,   152,    18,    19,    48,   153,    49,    20,    50,
      36,   157,    41,    20,   155,    61,     0,    75,     0,    51,
      42,    43,    44,    45,    46,    47,    84,     0,    85,     0,
       0,   110,     0,   119,   120,   121,   122,   123,   124,    84,
       1,    85,     2,     3,     4,     5,   119,   120,   121,   122,
     123,   124
};

static const yytype_int16 yycheck[] =
{
       1,    24,    21,    15,    60,    48,    57,   128,     8,     8,
       3,    90,     5,     8,     8,     0,    23,    24,    25,    27,
      21,     7,    16,    17,    23,    24,    25,    35,    40,    41,
      42,    43,    44,    45,    27,    35,   157,    49,    89,    62,
      35,   162,    28,    20,    87,    88,    58,   126,   127,    19,
      36,    37,    38,    39,    40,    41,     5,     7,     7,     8,
       9,     5,     5,     7,     7,     9,     9,    68,     7,     5,
      19,     7,     4,     9,     6,    19,    19,    89,    90,    84,
      85,   132,     3,    19,     5,    34,    19,     8,    16,    17,
      34,    34,     5,     3,     7,     5,     9,   109,    34,    27,
       7,     5,   158,     7,     7,     9,    19,   119,   120,   121,
     122,   123,   124,     7,    18,    19,    27,     8,    19,    10,
       7,    34,    23,    24,    25,    26,    19,   146,    29,    30,
       8,    32,    33,   156,   135,    19,     7,    21,    16,    17,
      19,    42,    26,     8,    27,    29,    30,     8,    32,    33,
      19,     8,    21,    27,    20,    16,    17,    26,    42,    19,
      29,    30,     8,    32,    33,    19,     3,    21,     5,    19,
      19,     8,    26,    42,    27,    29,    30,    26,    32,    33,
      29,    30,    27,    32,    33,     5,    27,     7,    42,     9,
       8,    31,    28,    42,   135,    21,    -1,    41,    -1,    19,
      36,    37,    38,    39,    40,    41,     3,    -1,     5,    -1,
      -1,     8,    -1,    10,    11,    12,    13,    14,    15,     3,
      20,     5,    22,    23,    24,    25,    10,    11,    12,    13,
      14,    15
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,    20,    22,    23,    24,    25,    44,    45,    46,    47,
      48,    49,    52,    55,    19,    26,    29,    30,    32,    33,
      42,    53,    54,    55,    58,    59,    60,    61,    62,    63,
      64,    65,    66,    67,    68,     0,    47,    52,    52,    19,
       7,    28,    36,    37,    38,    39,    40,    41,     5,     7,
       9,    19,    34,    70,    71,    72,     7,     7,     7,     7,
       7,    54,    58,    19,    56,    21,    59,    27,     7,     8,
      34,    69,    70,    19,    34,    67,    70,    70,    70,    70,
      70,    72,    70,    27,     3,     5,    27,     4,     6,     7,
      18,    70,    73,    74,    75,    74,    34,    70,    19,    19,
      64,    21,    27,    35,     8,    50,    51,    55,     8,    35,
       8,    71,    71,    72,    72,    70,    74,    70,    75,    10,
      11,    12,    13,    14,    15,     8,    16,    17,     8,     8,
       8,     8,    27,    19,     8,    35,    19,    34,    70,     8,
      70,    70,    70,    70,    70,    70,    20,    57,    75,    75,
      57,    27,    27,    27,    74,    51,    58,    31,    27,    21,
      57,    64,     8,    57
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    43,    44,    45,    45,    46,    46,    47,    48,    48,
      49,    49,    50,    50,    51,    52,    52,    53,    53,    54,
      55,    55,    55,    56,    56,    57,    58,    58,    59,    59,
      59,    59,    59,    59,    59,    59,    60,    60,    61,    61,
      62,    63,    64,    64,    64,    64,    64,    64,    64,    64,
      64,    65,    65,    66,    67,    68,    68,    69,    69,    69,
      69,    70,    70,    70,    71,    71,    71,    72,    72,    72,
      72,    73,    73,    73,    73,    73,    73,    74,    74,    74,
      75,    75,    75,    75
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     1,     2,     1,     2,     1,     2,     5,     4,
       1,     1,     3,     1,     2,     4,     3,     2,     1,     3,
       1,     1,     1,     3,     1,     3,     2,     1,     1,     1,
       1,     2,     1,     1,     1,     1,     3,     3,     5,     7,
       5,     9,     3,     3,     3,     3,     3,     3,     3,     2,
       2,     5,     5,     5,     1,     4,     3,     3,     3,     1,
       1,     3,     3,     1,     3,     3,     1,     1,     1,     3,
       2,     3,     3,     3,     3,     3,     3,     3,     3,     1,
       3,     2,     2,     1
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
        case 2:
#line 17 "expr.y" /* yacc.c:1646  */
    {printTabSimb(); printf("\n\n"); buildJVM((yyvsp[0]).arvSint); createGraphviz((yyvsp[0]).arvSint); printf("\n\n\tSUCESSO\n"); exit(0);}
#line 1376 "expr.tab.c" /* yacc.c:1646  */
    break;

  case 3:
#line 20 "expr.y" /* yacc.c:1646  */
    {printTabFunc(); printf("\n"); (yyval).arvSint = criaNo(OP_RAIZ, (yyvsp[-1]).arvSint, (yyvsp[0]).arvSint, NULL);}
#line 1382 "expr.tab.c" /* yacc.c:1646  */
    break;

  case 4:
#line 21 "expr.y" /* yacc.c:1646  */
    {(yyval).arvSint = (yyvsp[0]).arvSint;}
#line 1388 "expr.tab.c" /* yacc.c:1646  */
    break;

  case 5:
#line 24 "expr.y" /* yacc.c:1646  */
    {(yyval).arvSint = criaNo(OP_FUNC, (yyvsp[-1]).arvSint, (yyvsp[0]).arvSint, NULL); printTabFunc(); printf("\n");}
#line 1394 "expr.tab.c" /* yacc.c:1646  */
    break;

  case 6:
#line 25 "expr.y" /* yacc.c:1646  */
    {(yyval).arvSint = criaNo(OP_FUNC, (yyvsp[0]).arvSint, NULL, NULL);}
#line 1400 "expr.tab.c" /* yacc.c:1646  */
    break;

  case 7:
#line 28 "expr.y" /* yacc.c:1646  */
    {(yyval).arvSint = (yyvsp[0]).arvSint; printTabSimbTmp(); clearTabSimbTmp(); posF = 0; inFunction = 0; printf("\n");}
#line 1406 "expr.tab.c" /* yacc.c:1646  */
    break;

  case 8:
#line 31 "expr.y" /* yacc.c:1646  */
    {insereTabFuncao((yyvsp[-4]).tipo, (yyvsp[-3]).value.id, (yyvsp[-1]).listaTipos);}
#line 1412 "expr.tab.c" /* yacc.c:1646  */
    break;

  case 9:
#line 32 "expr.y" /* yacc.c:1646  */
    {insereTabFuncao((yyvsp[-3]).tipo, (yyvsp[-2]).value.id, NULL);}
#line 1418 "expr.tab.c" /* yacc.c:1646  */
    break;

  case 10:
#line 35 "expr.y" /* yacc.c:1646  */
    {(yyval).tipo = (yyvsp[0]).tipo; inFunction = 1;}
#line 1424 "expr.tab.c" /* yacc.c:1646  */
    break;

  case 11:
#line 36 "expr.y" /* yacc.c:1646  */
    {(yyval).tipo = TIPO_VOID; inFunction = 1;}
#line 1430 "expr.tab.c" /* yacc.c:1646  */
    break;

  case 12:
#line 39 "expr.y" /* yacc.c:1646  */
    {(yyval).listaTipos = listaInserir2((yyvsp[-2]).listaTipos, (void *)&(yyvsp[0]).tipo);}
#line 1436 "expr.tab.c" /* yacc.c:1646  */
    break;

  case 13:
#line 40 "expr.y" /* yacc.c:1646  */
    {(yyval).listaTipos = listaCriar(sizeof(int)); (yyval).listaTipos = listaInserir2((yyval).listaTipos, (void *)&(yyvsp[0]).tipo);}
#line 1442 "expr.tab.c" /* yacc.c:1646  */
    break;

  case 14:
#line 43 "expr.y" /* yacc.c:1646  */
    {(yyval).listaID = listaCriar(sizeof(stf)); (yyval).listaID = listaInserir((yyval).listaID, (void *)(yyvsp[0]).value.id, posF++); insereTabSimboloTmp((yyval).listaID, (yyvsp[-1]).tipo);
					 (yyval).tipo = (yyvsp[-1]).tipo;}
#line 1449 "expr.tab.c" /* yacc.c:1646  */
    break;

  case 15:
#line 47 "expr.y" /* yacc.c:1646  */
    {(yyval).arvSint = (yyvsp[-1]).arvSint;}
#line 1455 "expr.tab.c" /* yacc.c:1646  */
    break;

  case 16:
#line 48 "expr.y" /* yacc.c:1646  */
    {(yyval).arvSint = (yyvsp[-1]).arvSint;}
#line 1461 "expr.tab.c" /* yacc.c:1646  */
    break;

  case 19:
#line 55 "expr.y" /* yacc.c:1646  */
    {if(inFunction){insereTabSimboloTmp((yyvsp[-1]).listaID, (yyvsp[-2]).tipo);} else {insereTabSimbolo((yyvsp[-1]).listaID, (yyvsp[-2]).tipo);}}
#line 1467 "expr.tab.c" /* yacc.c:1646  */
    break;

  case 20:
#line 58 "expr.y" /* yacc.c:1646  */
    {(yyval).tipo = TIPO_INT;}
#line 1473 "expr.tab.c" /* yacc.c:1646  */
    break;

  case 21:
#line 59 "expr.y" /* yacc.c:1646  */
    {(yyval).tipo = TIPO_STRING;}
#line 1479 "expr.tab.c" /* yacc.c:1646  */
    break;

  case 22:
#line 60 "expr.y" /* yacc.c:1646  */
    {(yyval).tipo = TIPO_FLOAT;}
#line 1485 "expr.tab.c" /* yacc.c:1646  */
    break;

  case 23:
#line 63 "expr.y" /* yacc.c:1646  */
    {(yyval).listaID = listaInserir((yyvsp[-2]).listaID, (void *)(yyvsp[0]).value.id, (inFunction ? posF++ : pos++));}
#line 1491 "expr.tab.c" /* yacc.c:1646  */
    break;

  case 24:
#line 64 "expr.y" /* yacc.c:1646  */
    {(yyval).listaID = listaCriar(sizeof(stf)); (yyval).listaID = listaInserir((yyval).listaID, (void *)(yyvsp[0]).value.id, (inFunction ? posF++ : pos++));}
#line 1497 "expr.tab.c" /* yacc.c:1646  */
    break;

  case 25:
#line 67 "expr.y" /* yacc.c:1646  */
    {(yyval).arvSint = (yyvsp[-1]).arvSint;}
#line 1503 "expr.tab.c" /* yacc.c:1646  */
    break;

  case 26:
#line 70 "expr.y" /* yacc.c:1646  */
    {(yyval).arvSint = criaNo(OP_ALEA, (yyvsp[0]).arvSint, (yyvsp[-1]).arvSint, NULL);}
#line 1509 "expr.tab.c" /* yacc.c:1646  */
    break;

  case 27:
#line 71 "expr.y" /* yacc.c:1646  */
    {(yyval).arvSint = (yyvsp[0]).arvSint;}
#line 1515 "expr.tab.c" /* yacc.c:1646  */
    break;

  case 28:
#line 74 "expr.y" /* yacc.c:1646  */
    {(yyval).arvSint = (yyvsp[0]).arvSint;}
#line 1521 "expr.tab.c" /* yacc.c:1646  */
    break;

  case 29:
#line 75 "expr.y" /* yacc.c:1646  */
    {(yyval).arvSint = (yyvsp[0]).arvSint;}
#line 1527 "expr.tab.c" /* yacc.c:1646  */
    break;

  case 30:
#line 76 "expr.y" /* yacc.c:1646  */
    {(yyval).arvSint = (yyvsp[0]).arvSint;}
#line 1533 "expr.tab.c" /* yacc.c:1646  */
    break;

  case 31:
#line 77 "expr.y" /* yacc.c:1646  */
    {(yyval).arvSint = (yyvsp[-1]).arvSint;}
#line 1539 "expr.tab.c" /* yacc.c:1646  */
    break;

  case 32:
#line 78 "expr.y" /* yacc.c:1646  */
    {(yyval).arvSint = (yyvsp[0]).arvSint;}
#line 1545 "expr.tab.c" /* yacc.c:1646  */
    break;

  case 33:
#line 79 "expr.y" /* yacc.c:1646  */
    {(yyval).arvSint = (yyvsp[0]).arvSint;}
#line 1551 "expr.tab.c" /* yacc.c:1646  */
    break;

  case 35:
#line 81 "expr.y" /* yacc.c:1646  */
    {(yyval).arvSint = (yyvsp[0]).arvSint;}
#line 1557 "expr.tab.c" /* yacc.c:1646  */
    break;

  case 36:
#line 84 "expr.y" /* yacc.c:1646  */
    {(yyval).arvSint = criaNo(OP_RETURN, (yyvsp[-1]).arvSint, NULL, NULL);}
#line 1563 "expr.tab.c" /* yacc.c:1646  */
    break;

  case 37:
#line 85 "expr.y" /* yacc.c:1646  */
    {(yyval).arvSint = criaNo(OP_RETURN, criaNoV(TIPO_STRING, (yyvsp[-1]).value), NULL, NULL);}
#line 1569 "expr.tab.c" /* yacc.c:1646  */
    break;

  case 38:
#line 88 "expr.y" /* yacc.c:1646  */
    {(yyval).arvSint = criaNo(OP_IF, (yyvsp[-2]).arvSint, (yyvsp[0]).arvSint, NULL);}
#line 1575 "expr.tab.c" /* yacc.c:1646  */
    break;

  case 39:
#line 89 "expr.y" /* yacc.c:1646  */
    {(yyval).arvSint = criaNo(OP_IF, (yyvsp[-4]).arvSint, (yyvsp[-2]).arvSint, (yyvsp[0]).arvSint);}
#line 1581 "expr.tab.c" /* yacc.c:1646  */
    break;

  case 40:
#line 92 "expr.y" /* yacc.c:1646  */
    {(yyval).arvSint = criaNo(OP_WHILE, (yyvsp[-2]).arvSint, (yyvsp[0]).arvSint, NULL);}
#line 1587 "expr.tab.c" /* yacc.c:1646  */
    break;

  case 41:
#line 95 "expr.y" /* yacc.c:1646  */
    {(yyval).arvSint = cria4No(OP_FOR, (yyvsp[-6]).arvSint, (yyvsp[-4]).arvSint, (yyvsp[-2]).arvSint, (yyvsp[0]).arvSint);}
#line 1593 "expr.tab.c" /* yacc.c:1646  */
    break;

  case 42:
#line 98 "expr.y" /* yacc.c:1646  */
    {(yyval).arvSint = criaNo(OP_ATRIB, criaNoV((inFunction ? TIPO_IDFUNCAO : (yyvsp[-2]).tipo), (yyvsp[-2]).value), (yyvsp[0]).arvSint, NULL); if(inFunction){(yyval).arvSint -> ptr1 -> posicaoFuncao = consultaPosiTabSimbFunc((yyvsp[-2]).value.id);};}
#line 1599 "expr.tab.c" /* yacc.c:1646  */
    break;

  case 43:
#line 99 "expr.y" /* yacc.c:1646  */
    {(yyval).arvSint = criaNo(OP_ATRIB, criaNoV((inFunction ? TIPO_IDFUNCAO : (yyvsp[-2]).tipo), (yyvsp[-2]).value), criaNoV(TIPO_STRING, (yyvsp[0]).value), NULL); if(inFunction){(yyval).arvSint -> ptr1 -> posicaoFuncao = consultaPosiTabSimbFunc((yyvsp[-2]).value.id);};}
#line 1605 "expr.tab.c" /* yacc.c:1646  */
    break;

  case 45:
#line 101 "expr.y" /* yacc.c:1646  */
    {(yyval).arvSint = criaNo(OP_ATRIB, criaNoV((yyvsp[-2]).tipo, (yyvsp[-2]).value), criaNo(OP_ADD, criaNoV((yyvsp[-2]).tipo, (yyvsp[-2]).value), (yyvsp[0]).arvSint, NULL), NULL);}
#line 1611 "expr.tab.c" /* yacc.c:1646  */
    break;

  case 46:
#line 102 "expr.y" /* yacc.c:1646  */
    {(yyval).arvSint = criaNo(OP_ATRIB, criaNoV((yyvsp[-2]).tipo, (yyvsp[-2]).value), criaNo(OP_SUB, criaNoV((yyvsp[-2]).tipo, (yyvsp[-2]).value), (yyvsp[0]).arvSint, NULL), NULL);}
#line 1617 "expr.tab.c" /* yacc.c:1646  */
    break;

  case 47:
#line 103 "expr.y" /* yacc.c:1646  */
    {(yyval).arvSint = criaNo(OP_ATRIB, criaNoV((yyvsp[-2]).tipo, (yyvsp[-2]).value), criaNo(OP_MULT, criaNoV((yyvsp[-2]).tipo, (yyvsp[-2]).value), (yyvsp[0]).arvSint, NULL), NULL);}
#line 1623 "expr.tab.c" /* yacc.c:1646  */
    break;

  case 48:
#line 104 "expr.y" /* yacc.c:1646  */
    {(yyval).arvSint = criaNo(OP_ATRIB, criaNoV((yyvsp[-2]).tipo, (yyvsp[-2]).value), criaNo(OP_DIV, criaNoV((yyvsp[-2]).tipo, (yyvsp[-2]).value), (yyvsp[0]).arvSint, NULL), NULL);}
#line 1629 "expr.tab.c" /* yacc.c:1646  */
    break;

  case 49:
#line 105 "expr.y" /* yacc.c:1646  */
    {(yyval).arvSint = criaNo(OP_ATRIB, criaNoV((yyvsp[-1]).tipo, (yyvsp[-1]).value), criaNo(OP_ADD, criaNoV((yyvsp[-1]).tipo, (yyvsp[-1]).value), criaConstNum(TIPO_INT, 1), NULL), NULL);}
#line 1635 "expr.tab.c" /* yacc.c:1646  */
    break;

  case 50:
#line 106 "expr.y" /* yacc.c:1646  */
    {(yyval).arvSint = criaNo(OP_ATRIB, criaNoV((yyvsp[-1]).tipo, (yyvsp[-1]).value), criaNo(OP_SUB, criaNoV((yyvsp[-1]).tipo, (yyvsp[-1]).value), criaConstNum(TIPO_INT, 1), NULL), NULL);}
#line 1641 "expr.tab.c" /* yacc.c:1646  */
    break;

  case 51:
#line 109 "expr.y" /* yacc.c:1646  */
    {(yyval).arvSint = criaNo(OP_PRINT, (yyvsp[-2]).arvSint, NULL, NULL);}
#line 1647 "expr.tab.c" /* yacc.c:1646  */
    break;

  case 52:
#line 110 "expr.y" /* yacc.c:1646  */
    {(yyval).arvSint = criaNo(OP_PRINT, criaNoV(TIPO_STRING, (yyvsp[-2]).value), NULL, NULL);}
#line 1653 "expr.tab.c" /* yacc.c:1646  */
    break;

  case 53:
#line 113 "expr.y" /* yacc.c:1646  */
    {(yyval).arvSint = criaNo(OP_READ, criaNoV(TIPO_ID, (yyvsp[-2]).value), NULL, NULL);}
#line 1659 "expr.tab.c" /* yacc.c:1646  */
    break;

  case 61:
#line 129 "expr.y" /* yacc.c:1646  */
    {(yyval).arvSint = criaNo(OP_ADD, (yyvsp[-2]).arvSint, (yyvsp[0]).arvSint, NULL);}
#line 1665 "expr.tab.c" /* yacc.c:1646  */
    break;

  case 62:
#line 130 "expr.y" /* yacc.c:1646  */
    {(yyval).arvSint = criaNo(OP_SUB, (yyvsp[-2]).arvSint, (yyvsp[0]).arvSint, NULL);}
#line 1671 "expr.tab.c" /* yacc.c:1646  */
    break;

  case 63:
#line 131 "expr.y" /* yacc.c:1646  */
    {(yyval).arvSint = (yyvsp[0]).arvSint;}
#line 1677 "expr.tab.c" /* yacc.c:1646  */
    break;

  case 64:
#line 134 "expr.y" /* yacc.c:1646  */
    {(yyval).arvSint = criaNo(OP_MULT, (yyvsp[-2]).arvSint, (yyvsp[0]).arvSint, NULL);}
#line 1683 "expr.tab.c" /* yacc.c:1646  */
    break;

  case 65:
#line 135 "expr.y" /* yacc.c:1646  */
    {(yyval).arvSint = criaNo(OP_DIV, (yyvsp[-2]).arvSint, (yyvsp[0]).arvSint, NULL);}
#line 1689 "expr.tab.c" /* yacc.c:1646  */
    break;

  case 66:
#line 136 "expr.y" /* yacc.c:1646  */
    {(yyval).arvSint = (yyvsp[0]).arvSint;}
#line 1695 "expr.tab.c" /* yacc.c:1646  */
    break;

  case 67:
#line 139 "expr.y" /* yacc.c:1646  */
    {(yyval).arvSint = criaNoV((yyvsp[0]).tipo, (yyvsp[0]).value);}
#line 1701 "expr.tab.c" /* yacc.c:1646  */
    break;

  case 68:
#line 140 "expr.y" /* yacc.c:1646  */
    {(yyval).arvSint = criaNoV((inFunction ? TIPO_IDFUNCAO : (yyvsp[0]).tipo), (yyvsp[0]).value); if(inFunction){(yyval).arvSint -> posicaoFuncao = consultaPosiTabSimbFunc((yyvsp[0]).value.id);};}
#line 1707 "expr.tab.c" /* yacc.c:1646  */
    break;

  case 69:
#line 141 "expr.y" /* yacc.c:1646  */
    {(yyval).arvSint = (yyvsp[-1]).arvSint;}
#line 1713 "expr.tab.c" /* yacc.c:1646  */
    break;

  case 70:
#line 142 "expr.y" /* yacc.c:1646  */
    {(yyval).arvSint = criaNo(OP_SUB, (yyvsp[0]).arvSint, NULL, NULL);}
#line 1719 "expr.tab.c" /* yacc.c:1646  */
    break;

  case 71:
#line 145 "expr.y" /* yacc.c:1646  */
    {(yyval).arvSint = criaNo(OP_MENOR, (yyvsp[-2]).arvSint, (yyvsp[0]).arvSint, NULL);}
#line 1725 "expr.tab.c" /* yacc.c:1646  */
    break;

  case 72:
#line 146 "expr.y" /* yacc.c:1646  */
    {(yyval).arvSint = criaNo(OP_MAIOR, (yyvsp[-2]).arvSint, (yyvsp[0]).arvSint, NULL);}
#line 1731 "expr.tab.c" /* yacc.c:1646  */
    break;

  case 73:
#line 147 "expr.y" /* yacc.c:1646  */
    {(yyval).arvSint = criaNo(OP_MENORIG, (yyvsp[-2]).arvSint, (yyvsp[0]).arvSint, NULL);}
#line 1737 "expr.tab.c" /* yacc.c:1646  */
    break;

  case 74:
#line 148 "expr.y" /* yacc.c:1646  */
    {(yyval).arvSint = criaNo(OP_MAIORIG, (yyvsp[-2]).arvSint, (yyvsp[0]).arvSint, NULL);}
#line 1743 "expr.tab.c" /* yacc.c:1646  */
    break;

  case 75:
#line 149 "expr.y" /* yacc.c:1646  */
    {(yyval).arvSint = criaNo(OP_CMP, (yyvsp[-2]).arvSint, (yyvsp[0]).arvSint, NULL);}
#line 1749 "expr.tab.c" /* yacc.c:1646  */
    break;

  case 76:
#line 150 "expr.y" /* yacc.c:1646  */
    {(yyval).arvSint = criaNo(OP_DIF, (yyvsp[-2]).arvSint, (yyvsp[0]).arvSint, NULL);}
#line 1755 "expr.tab.c" /* yacc.c:1646  */
    break;

  case 77:
#line 153 "expr.y" /* yacc.c:1646  */
    {(yyval).arvSint = criaNo(OP_AND, (yyvsp[-2]).arvSint, (yyvsp[0]).arvSint, NULL);}
#line 1761 "expr.tab.c" /* yacc.c:1646  */
    break;

  case 78:
#line 154 "expr.y" /* yacc.c:1646  */
    {(yyval).arvSint = criaNo(OP_OR, (yyvsp[-2]).arvSint, (yyvsp[0]).arvSint, NULL);}
#line 1767 "expr.tab.c" /* yacc.c:1646  */
    break;

  case 79:
#line 155 "expr.y" /* yacc.c:1646  */
    {(yyval).arvSint = (yyvsp[0]).arvSint;}
#line 1773 "expr.tab.c" /* yacc.c:1646  */
    break;

  case 80:
#line 158 "expr.y" /* yacc.c:1646  */
    {(yyval).arvSint = (yyvsp[-1]).arvSint;}
#line 1779 "expr.tab.c" /* yacc.c:1646  */
    break;

  case 81:
#line 159 "expr.y" /* yacc.c:1646  */
    {(yyval).arvSint = criaNo(OP_NOT, (yyvsp[0]).arvSint, NULL, NULL);}
#line 1785 "expr.tab.c" /* yacc.c:1646  */
    break;

  case 82:
#line 160 "expr.y" /* yacc.c:1646  */
    {(yyval).arvSint = criaNo(OP_NOT, (yyvsp[0]).arvSint, NULL, NULL);}
#line 1791 "expr.tab.c" /* yacc.c:1646  */
    break;

  case 83:
#line 161 "expr.y" /* yacc.c:1646  */
    {(yyval).arvSint = (yyvsp[0]).arvSint;}
#line 1797 "expr.tab.c" /* yacc.c:1646  */
    break;


#line 1801 "expr.tab.c" /* yacc.c:1646  */
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
#line 164 "expr.y" /* yacc.c:1906  */

#include "lex.yy.c"

int yyerror (char *str)
{
	printf("%s - antes %s na linha %d\nFRACASSO\n", str, yytext, linha);

}

int yywrap()
{
	return 1;
}
