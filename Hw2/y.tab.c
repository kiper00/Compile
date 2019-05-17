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
#line 1 "parse.y" /* yacc.c:339  */

#include "SymbolTable.h"
#define Trace(t)     if(debug){printf(t); printf("\n");}
int debug = 0;


#line 73 "y.tab.c" /* yacc.c:339  */

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

/* In a future release of Bison, this section will be replaced
   by #include "y.tab.h".  */
#ifndef YY_YY_Y_TAB_H_INCLUDED
# define YY_YY_Y_TAB_H_INCLUDED
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
    SET = 258,
    RAL = 259,
    LE = 260,
    GE = 261,
    AND = 262,
    OR = 263,
    ID = 264,
    ARRAY = 265,
    BOOLEAN = 266,
    BEG = 267,
    BREAK = 268,
    CHAR = 269,
    CASE = 270,
    CONST = 271,
    CONTINUE = 272,
    DO = 273,
    ELSE = 274,
    END = 275,
    EXIT = 276,
    FALSE = 277,
    FOR = 278,
    FN = 279,
    IF = 280,
    IN = 281,
    INTEGER = 282,
    OF = 283,
    READ = 284,
    LOOP = 285,
    MODULE = 286,
    PRINT = 287,
    PRINTLN = 288,
    PROCEDURE = 289,
    REPEAT = 290,
    RETURN = 291,
    REAL = 292,
    STRING = 293,
    RECORD = 294,
    THEN = 295,
    TRUE = 296,
    TYPE = 297,
    USE = 298,
    VAR = 299,
    UTIL = 300,
    WHILE = 301,
    INT_CON = 302,
    STR_CON = 303,
    REAL_CON = 304,
    BOOL_CON = 305,
    EQ = 306,
    UMINUS = 307
  };
#endif
/* Tokens.  */
#define SET 258
#define RAL 259
#define LE 260
#define GE 261
#define AND 262
#define OR 263
#define ID 264
#define ARRAY 265
#define BOOLEAN 266
#define BEG 267
#define BREAK 268
#define CHAR 269
#define CASE 270
#define CONST 271
#define CONTINUE 272
#define DO 273
#define ELSE 274
#define END 275
#define EXIT 276
#define FALSE 277
#define FOR 278
#define FN 279
#define IF 280
#define IN 281
#define INTEGER 282
#define OF 283
#define READ 284
#define LOOP 285
#define MODULE 286
#define PRINT 287
#define PRINTLN 288
#define PROCEDURE 289
#define REPEAT 290
#define RETURN 291
#define REAL 292
#define STRING 293
#define RECORD 294
#define THEN 295
#define TRUE 296
#define TYPE 297
#define USE 298
#define VAR 299
#define UTIL 300
#define WHILE 301
#define INT_CON 302
#define STR_CON 303
#define REAL_CON 304
#define BOOL_CON 305
#define EQ 306
#define UMINUS 307

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED

union YYSTYPE
{
#line 9 "parse.y" /* yacc.c:355  */

	int ival;
	double dval;
	int bval;
	char* cval;
	struct SymbolTable* tval;

#line 225 "y.tab.c" /* yacc.c:355  */
};

typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_Y_TAB_H_INCLUDED  */

/* Copy the second part of user declarations.  */

#line 242 "y.tab.c" /* yacc.c:358  */

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
#define YYFINAL  4
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   619

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  69
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  23
/* YYNRULES -- Number of rules.  */
#define YYNRULES  83
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  194

/* YYTRANSLATE[YYX] -- Symbol number corresponding to YYX as returned
   by yylex, with out-of-bounds checking.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   307

#define YYTRANSLATE(YYX)                                                \
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[TOKEN-NUM] -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex, without out-of-bounds checking.  */
static const yytype_uint8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,    63,     2,     2,
      66,    67,    57,    55,    65,    56,     2,    58,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,    68,    60,
      52,    64,    54,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,    61,     2,    62,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,    51,     2,     2,     2,
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
      45,    46,    47,    48,    49,    50,    53,    59
};

#if YYDEBUG
  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_uint8 yyrline[] =
{
       0,    43,    43,    44,    46,    47,    48,    50,    51,    52,
      53,    55,    56,    57,    58,    61,    62,    63,    64,    65,
      67,    68,    69,    70,    71,    72,    73,    76,    77,    78,
      79,    80,    81,    82,    83,    84,    85,    86,    87,    88,
      89,    90,    91,    92,    93,    94,    96,    97,    99,   100,
     102,   103,   105,   106,   108,   109,   110,   111,   113,   114,
     116,   117,   118,   119,   120,   121,   123,   124,   126,   127,
     129,   131,   132,   137,   138,   144,   154,   155,   156,   157,
     159,   160,   161,   162
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || 0
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "SET", "RAL", "LE", "GE", "AND", "OR",
  "ID", "ARRAY", "BOOLEAN", "BEG", "BREAK", "CHAR", "CASE", "CONST",
  "CONTINUE", "DO", "ELSE", "END", "EXIT", "FALSE", "FOR", "FN", "IF",
  "IN", "INTEGER", "OF", "READ", "LOOP", "MODULE", "PRINT", "PRINTLN",
  "PROCEDURE", "REPEAT", "RETURN", "REAL", "STRING", "RECORD", "THEN",
  "TRUE", "TYPE", "USE", "VAR", "UTIL", "WHILE", "INT_CON", "STR_CON",
  "REAL_CON", "BOOL_CON", "'~'", "'<'", "EQ", "'>'", "'+'", "'-'", "'*'",
  "'/'", "UMINUS", "';'", "'['", "']'", "'%'", "'='", "','", "'('", "')'",
  "':'", "$accept", "program", "program_decl", "var_delc_glo",
  "var_delc_loc", "statement", "simple", "expression", "comma_exp",
  "proc_invo", "fun_invo", "fun", "fun_var", "loop", "condition",
  "const_glo", "const_loc", "array", "var_glo", "var_loc", "var_decl",
  "var_type", "con_Var", YY_NULLPTR
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
     305,   126,    60,   306,    62,    43,    45,    42,    47,   307,
      59,    91,    93,    37,    61,    44,    40,    41,    58
};
# endif

#define YYPACT_NINF -139

#define yypact_value_is_default(Yystate) \
  (!!((Yystate) == (-139)))

#define YYTABLE_NINF -1

#define yytable_value_is_error(Yytable_value) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
     -19,    -1,    19,     5,  -139,   -32,   573,    29,    33,    39,
      40,     9,  -139,  -139,    41,    10,   -10,    49,    93,    93,
     360,    11,   423,  -139,  -139,  -139,  -139,    23,    29,    30,
      21,    39,    15,   573,    13,  -139,    36,    93,    53,    71,
      93,    47,   -51,  -139,  -139,  -139,  -139,    93,   147,  -139,
    -139,   171,  -139,   208,    93,    92,   573,   119,    29,     7,
     339,    17,    39,  -139,   438,    61,   232,    54,    57,   129,
     -56,    27,  -139,    77,   290,   -23,    93,    93,    93,    93,
      93,    93,    93,    93,    93,    93,    93,    93,  -139,    93,
      93,  -139,  -139,   107,  -139,    66,  -139,  -139,   573,   121,
      39,    39,    60,   113,  -139,  -139,  -139,  -139,  -139,  -139,
     122,    80,  -139,   141,  -139,    93,    93,    86,   108,    94,
    -139,   -41,   133,   133,   133,   324,   307,   337,   133,   133,
      46,    46,   -23,   -23,   269,   269,   155,  -139,   453,   118,
     121,    39,   135,  -139,    17,   573,    79,  -139,   153,    93,
     269,   269,  -139,   393,  -139,  -139,   468,   197,   119,   121,
      39,  -139,  -139,   483,   146,   246,   498,  -139,   408,   149,
     513,   157,   158,   210,   192,  -139,  -139,   528,   543,  -139,
    -139,   161,  -139,  -139,   164,    17,  -139,  -139,   558,  -139,
    -139,   170,  -139,  -139
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       0,     0,     0,     0,     1,     0,     0,     0,     0,     0,
       0,     5,     4,     9,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    16,    19,    17,    18,     0,     7,     0,
       0,     8,     0,     0,    10,     6,     0,     0,     0,     0,
       0,     0,    27,    80,    82,    81,    83,     0,     0,    29,
      28,     0,    25,     0,     0,     0,    15,     0,    66,     0,
       0,     0,    71,    72,     0,     0,     0,     0,     0,     0,
       0,     0,    22,     0,     0,    31,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    23,     0,
       0,    24,    26,     0,     2,     0,    54,    55,     0,     0,
       0,     0,     0,     0,    13,    79,    76,    77,    78,    75,
       0,     0,    20,     0,    48,     0,     0,     0,     0,     0,
      50,     0,    45,    41,    42,    43,    44,    40,    39,    38,
      32,    33,    34,    35,    36,    37,     0,    67,     0,     0,
      11,    12,     0,    56,     0,     0,    14,     3,     0,     0,
      46,    47,    49,     0,    30,    51,     0,     0,     0,    68,
      73,    74,    57,     0,     0,     0,     0,    60,     0,     0,
       0,     0,     0,     0,     0,    21,    62,     0,     0,    61,
      58,     0,    52,    69,     0,     0,    64,    63,     0,    59,
      53,     0,    65,    70
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -139,  -139,  -139,   229,   173,    -6,  -139,   -17,   167,  -139,
    -139,   231,  -139,  -139,  -139,   236,   145,   -53,   237,   148,
     -55,  -138,   -52
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     2,    10,    34,   146,    56,    23,    69,    70,    24,
      49,    12,    60,    25,    26,    58,   159,    13,    62,   160,
      32,   109,    50
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_uint8 yytable[] =
{
      22,    48,    51,    53,    97,    95,   162,   104,     3,   116,
      73,   117,     1,    37,     5,    74,    30,     6,     5,     4,
      66,     7,     5,    71,   116,     7,   155,    64,   105,     7,
      75,    76,    77,    78,    79,    80,    14,    93,    27,     8,
      89,    90,    29,     8,   106,   142,   143,   191,    30,     9,
     104,    36,    33,     9,   107,   108,    40,     9,    41,   122,
     123,   124,   125,   126,   127,   128,   129,   130,   131,   132,
     133,    38,   134,   135,    96,    63,    39,    54,    81,    82,
      42,    83,    84,    85,    86,    87,   142,    57,     5,    61,
      89,    90,   138,   104,   118,    99,    59,    65,   150,   151,
      67,    94,    42,    86,    87,   142,   172,    72,   111,    89,
      90,    76,    77,    78,    79,    80,   113,   114,    43,    44,
      45,    46,     5,   100,   119,   145,   137,    47,   144,    99,
     139,   147,   165,    76,    77,    78,    79,    80,    68,   163,
      43,    44,    45,    46,   149,   148,   152,   168,   153,    47,
     170,    76,    77,    78,    79,    80,   154,   100,    81,    82,
     177,    83,    84,    85,    86,    87,    43,    44,    45,    46,
      89,    90,   188,   156,   136,    76,    77,    78,    79,    80,
      81,    82,   158,    83,    84,    85,    86,    87,    84,    85,
      86,    87,    89,    90,   115,   161,    89,    90,    81,    82,
     164,    83,    84,    85,    86,    87,   171,    88,   174,   180,
      89,    90,    76,    77,    78,    79,    80,   182,   183,   184,
     185,   189,    81,    82,   190,    83,    84,    85,    86,    87,
     193,    91,    11,   103,    89,    90,    76,    77,    78,    79,
      80,   121,    35,    28,   140,     0,    31,     0,   141,     0,
      76,    77,    78,    79,    80,     0,     0,     0,     0,    81,
      82,     0,    83,    84,    85,    86,    87,     0,    92,     0,
       0,    89,    90,    76,    77,    78,    79,    80,     0,     0,
       0,     0,     0,    81,    82,     0,    83,    84,    85,    86,
      87,     0,   112,     0,     0,    89,    90,    81,    82,    42,
      83,    84,    85,    86,    87,     0,   175,     0,     0,    89,
      90,    76,    77,    78,    79,     0,     0,     0,     0,     0,
      81,    82,     0,    83,    84,    85,    86,    87,    76,    77,
      78,     0,    89,    90,     0,     0,     0,    43,    44,    45,
      46,    76,    77,    78,     0,     0,    47,     0,     5,     0,
       0,    98,     0,     0,     0,    99,     0,   120,    81,    82,
       0,    83,    84,    85,    86,    87,     0,     0,     0,    42,
      89,    90,     0,     0,     0,    81,    82,     0,    83,    84,
      85,    86,    87,   100,     0,     0,     0,    89,    90,    82,
       0,    83,    84,    85,    86,    87,     0,     0,     0,     0,
      89,    90,    15,     0,   101,     0,   102,    43,    44,    45,
      46,     0,   166,   167,     0,     0,    47,    15,    16,     0,
      52,     0,    17,     0,     0,    18,    19,   178,   179,    20,
       0,     0,    15,    16,     0,     0,     0,    17,     0,    21,
      18,    19,     0,    55,    20,     0,     0,    15,    16,     0,
       0,     0,    17,     0,    21,    18,    19,     0,   110,    20,
       0,     0,    15,    16,     0,     0,     0,    17,     0,    21,
      18,    19,     0,   157,    20,     0,     0,    15,    16,     0,
       0,     0,    17,     0,    21,    18,    19,     0,   169,    20,
       0,     0,    15,    16,     0,     0,     0,    17,     0,    21,
      18,    19,     0,   173,    20,     0,     0,    15,    16,     0,
       0,     0,    17,     0,    21,    18,    19,     0,   176,    20,
       0,     0,    15,    16,     0,     0,     0,    17,     0,    21,
      18,    19,     0,   181,    20,     0,     0,    15,    16,     0,
       0,     0,    17,     0,    21,    18,    19,     0,   186,    20,
       0,     0,    15,    16,     0,     0,     0,    17,     0,    21,
      18,    19,     0,   187,    20,     0,     0,    15,    16,     0,
       0,     0,    17,     0,    21,    18,    19,     0,   192,    20,
       0,     0,    15,    16,     0,     0,     0,    17,     0,    21,
      18,    19,     0,     0,    20,     0,     0,     0,    16,     0,
       0,     0,    17,     0,    21,    18,    19,     0,     0,    20,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    21
};

static const yytype_int16 yycheck[] =
{
       6,    18,    19,    20,    59,    57,   144,    60,     9,    65,
      61,    67,    31,     3,     9,    66,     9,    12,     9,     0,
      37,    16,     9,    40,    65,    16,    67,    33,    11,    16,
      47,     4,     5,     6,     7,     8,    68,    54,     9,    34,
      63,    64,     9,    34,    27,   100,   101,   185,     9,    44,
     103,    10,    12,    44,    37,    38,    66,    44,     9,    76,
      77,    78,    79,    80,    81,    82,    83,    84,    85,    86,
      87,    61,    89,    90,    67,    60,    66,    66,    51,    52,
       9,    54,    55,    56,    57,    58,   141,    64,     9,    68,
      63,    64,    98,   146,    67,    16,    66,    61,   115,   116,
      47,     9,     9,    57,    58,   160,   158,    60,    47,    63,
      64,     4,     5,     6,     7,     8,    62,    60,    47,    48,
      49,    50,     9,    44,    47,    12,    60,    56,    68,    16,
       9,     9,   149,     4,     5,     6,     7,     8,    67,   145,
      47,    48,    49,    50,     3,    65,    60,   153,    40,    56,
     156,     4,     5,     6,     7,     8,    62,    44,    51,    52,
     166,    54,    55,    56,    57,    58,    47,    48,    49,    50,
      63,    64,   178,    18,    67,     4,     5,     6,     7,     8,
      51,    52,    64,    54,    55,    56,    57,    58,    55,    56,
      57,    58,    63,    64,    65,    60,    63,    64,    51,    52,
      47,    54,    55,    56,    57,    58,     9,    60,    62,    60,
      63,    64,     4,     5,     6,     7,     8,    60,    60,     9,
      28,    60,    51,    52,    60,    54,    55,    56,    57,    58,
      60,    60,     3,    60,    63,    64,     4,     5,     6,     7,
       8,    74,    11,     7,    99,    -1,     9,    -1,   100,    -1,
       4,     5,     6,     7,     8,    -1,    -1,    -1,    -1,    51,
      52,    -1,    54,    55,    56,    57,    58,    -1,    60,    -1,
      -1,    63,    64,     4,     5,     6,     7,     8,    -1,    -1,
      -1,    -1,    -1,    51,    52,    -1,    54,    55,    56,    57,
      58,    -1,    60,    -1,    -1,    63,    64,    51,    52,     9,
      54,    55,    56,    57,    58,    -1,    60,    -1,    -1,    63,
      64,     4,     5,     6,     7,    -1,    -1,    -1,    -1,    -1,
      51,    52,    -1,    54,    55,    56,    57,    58,     4,     5,
       6,    -1,    63,    64,    -1,    -1,    -1,    47,    48,    49,
      50,     4,     5,     6,    -1,    -1,    56,    -1,     9,    -1,
      -1,    12,    -1,    -1,    -1,    16,    -1,    67,    51,    52,
      -1,    54,    55,    56,    57,    58,    -1,    -1,    -1,     9,
      63,    64,    -1,    -1,    -1,    51,    52,    -1,    54,    55,
      56,    57,    58,    44,    -1,    -1,    -1,    63,    64,    52,
      -1,    54,    55,    56,    57,    58,    -1,    -1,    -1,    -1,
      63,    64,     9,    -1,    65,    -1,    67,    47,    48,    49,
      50,    -1,    19,    20,    -1,    -1,    56,     9,    25,    -1,
      60,    -1,    29,    -1,    -1,    32,    33,    19,    20,    36,
      -1,    -1,     9,    25,    -1,    -1,    -1,    29,    -1,    46,
      32,    33,    -1,    20,    36,    -1,    -1,     9,    25,    -1,
      -1,    -1,    29,    -1,    46,    32,    33,    -1,    20,    36,
      -1,    -1,     9,    25,    -1,    -1,    -1,    29,    -1,    46,
      32,    33,    -1,    20,    36,    -1,    -1,     9,    25,    -1,
      -1,    -1,    29,    -1,    46,    32,    33,    -1,    20,    36,
      -1,    -1,     9,    25,    -1,    -1,    -1,    29,    -1,    46,
      32,    33,    -1,    20,    36,    -1,    -1,     9,    25,    -1,
      -1,    -1,    29,    -1,    46,    32,    33,    -1,    20,    36,
      -1,    -1,     9,    25,    -1,    -1,    -1,    29,    -1,    46,
      32,    33,    -1,    20,    36,    -1,    -1,     9,    25,    -1,
      -1,    -1,    29,    -1,    46,    32,    33,    -1,    20,    36,
      -1,    -1,     9,    25,    -1,    -1,    -1,    29,    -1,    46,
      32,    33,    -1,    20,    36,    -1,    -1,     9,    25,    -1,
      -1,    -1,    29,    -1,    46,    32,    33,    -1,    20,    36,
      -1,    -1,     9,    25,    -1,    -1,    -1,    29,    -1,    46,
      32,    33,    -1,    -1,    36,    -1,    -1,    -1,    25,    -1,
      -1,    -1,    29,    -1,    46,    32,    33,    -1,    -1,    36,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    46
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,    31,    70,     9,     0,     9,    12,    16,    34,    44,
      71,    72,    80,    86,    68,     9,    25,    29,    32,    33,
      36,    46,    74,    75,    78,    82,    83,     9,    84,     9,
       9,    87,    89,    12,    72,    80,    10,     3,    61,    66,
      66,     9,     9,    47,    48,    49,    50,    56,    76,    79,
      91,    76,    60,    76,    66,    20,    74,    64,    84,    66,
      81,    68,    87,    60,    74,    61,    76,    47,    67,    76,
      77,    76,    60,    61,    66,    76,     4,     5,     6,     7,
       8,    51,    52,    54,    55,    56,    57,    58,    60,    63,
      64,    60,    60,    76,     9,    91,    67,    89,    12,    16,
      44,    65,    67,    73,    86,    11,    27,    37,    38,    90,
      20,    47,    60,    62,    60,    65,    65,    67,    67,    47,
      67,    77,    76,    76,    76,    76,    76,    76,    76,    76,
      76,    76,    76,    76,    76,    76,    67,    60,    74,     9,
      85,    88,    89,    89,    68,    12,    73,     9,    65,     3,
      76,    76,    60,    40,    62,    67,    18,    20,    64,    85,
      88,    60,    90,    74,    47,    76,    19,    20,    74,    20,
      74,     9,    91,    20,    62,    60,    20,    74,    19,    20,
      60,    20,    60,    60,     9,    28,    20,    20,    74,    60,
      60,    90,    20,    60
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    69,    70,    70,    71,    71,    71,    72,    72,    72,
      72,    73,    73,    73,    73,    74,    74,    74,    74,    74,
      75,    75,    75,    75,    75,    75,    75,    76,    76,    76,
      76,    76,    76,    76,    76,    76,    76,    76,    76,    76,
      76,    76,    76,    76,    76,    76,    77,    77,    78,    78,
      79,    79,    80,    80,    81,    81,    81,    81,    82,    82,
      83,    83,    83,    83,    83,    83,    84,    84,    85,    85,
      86,    87,    87,    88,    88,    89,    90,    90,    90,    90,
      91,    91,    91,    91
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     6,     7,     1,     1,     2,     2,     2,     1,
       2,     2,     2,     1,     2,     2,     1,     1,     1,     1,
       4,     7,     3,     3,     3,     2,     3,     1,     1,     1,
       4,     2,     3,     3,     3,     3,     3,     3,     3,     3,
       3,     3,     3,     3,     3,     3,     3,     3,     4,     5,
       3,     4,     8,     9,     2,     2,     3,     4,     7,     8,
       6,     7,     7,     8,     8,     9,     2,     4,     2,     4,
      11,     2,     2,     2,     2,     3,     1,     1,     1,     1,
       1,     1,     1,     1
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
#line 43 "parse.y" /* yacc.c:1646  */
    {Trace("End Parse");dump();}
#line 1536 "y.tab.c" /* yacc.c:1646  */
    break;

  case 3:
#line 44 "parse.y" /* yacc.c:1646  */
    {Trace("End Parse");dump();}
#line 1542 "y.tab.c" /* yacc.c:1646  */
    break;

  case 23:
#line 70 "parse.y" /* yacc.c:1646  */
    {Trace("PRINT ID");}
#line 1548 "y.tab.c" /* yacc.c:1646  */
    break;

  case 24:
#line 71 "parse.y" /* yacc.c:1646  */
    {Trace("PRINTLN");}
#line 1554 "y.tab.c" /* yacc.c:1646  */
    break;

  case 52:
#line 105 "parse.y" /* yacc.c:1646  */
    {Trace("PROCEDURE");}
#line 1560 "y.tab.c" /* yacc.c:1646  */
    break;

  case 53:
#line 106 "parse.y" /* yacc.c:1646  */
    {Trace("PROCEDURE");}
#line 1566 "y.tab.c" /* yacc.c:1646  */
    break;

  case 54:
#line 108 "parse.y" /* yacc.c:1646  */
    {Trace("NULL var");}
#line 1572 "y.tab.c" /* yacc.c:1646  */
    break;

  case 55:
#line 109 "parse.y" /* yacc.c:1646  */
    {Trace("1 var");}
#line 1578 "y.tab.c" /* yacc.c:1646  */
    break;

  case 56:
#line 110 "parse.y" /* yacc.c:1646  */
    {Trace("more var");}
#line 1584 "y.tab.c" /* yacc.c:1646  */
    break;

  case 57:
#line 111 "parse.y" /* yacc.c:1646  */
    {Trace("End fun Var");}
#line 1590 "y.tab.c" /* yacc.c:1646  */
    break;

  case 72:
#line 132 "parse.y" /* yacc.c:1646  */
    {
			Trace("insertVar");
			insertVar((yyvsp[-1].tval));
		}
#line 1599 "y.tab.c" /* yacc.c:1646  */
    break;

  case 74:
#line 138 "parse.y" /* yacc.c:1646  */
    {
			Trace("insertVar");
			printf("TEST");
			//insertVar($1);
		}
#line 1609 "y.tab.c" /* yacc.c:1646  */
    break;

  case 75:
#line 145 "parse.y" /* yacc.c:1646  */
    {	Trace("Announce");
			printf("Announce\n");
			if(lookup("aaa") == -1){
				(yyval.tval) = tmpVar((yyvsp[-2].cval),(yyvsp[0].ival));
}
			else
				yyerror("ID:%s conflict",(yyvsp[-2].cval));
		}
#line 1622 "y.tab.c" /* yacc.c:1646  */
    break;

  case 76:
#line 154 "parse.y" /* yacc.c:1646  */
    {Trace("int"); 	 (yyval.ival) = 0;}
#line 1628 "y.tab.c" /* yacc.c:1646  */
    break;

  case 77:
#line 155 "parse.y" /* yacc.c:1646  */
    {Trace("real");  (yyval.ival) = 1;}
#line 1634 "y.tab.c" /* yacc.c:1646  */
    break;

  case 78:
#line 156 "parse.y" /* yacc.c:1646  */
    {Trace("string");(yyval.ival) = 2;}
#line 1640 "y.tab.c" /* yacc.c:1646  */
    break;

  case 79:
#line 157 "parse.y" /* yacc.c:1646  */
    {Trace("bool");	 (yyval.ival) = 3;}
#line 1646 "y.tab.c" /* yacc.c:1646  */
    break;


#line 1650 "y.tab.c" /* yacc.c:1646  */
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
#line 163 "parse.y" /* yacc.c:1906  */


int yyerror(char *s){   
	fprintf(stderr, "%s\n", s); 
	exit(-1);  
	return 0;
}

int main(char *argv, int argc)
{

    /* open the source program file */
    //if (argc != 2) {
    //    printf ("Usage: sc filename\n");
    //    exit(1);
    //}
    //yyin = fopen(argv[1], "r");         /* open input file */

    /* perform parsing */
    //if (yyparse() == 1)                 /* parsing */
    //    yyerror("Parsing error !");     /* syntax error */

	yyparse();
}
