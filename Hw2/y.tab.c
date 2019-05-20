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
    NEQ = 259,
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
#define NEQ 259
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
	char *cval;
	struct SymbolTable* tval;
	struct 	FuncInfo* fval;

#line 226 "y.tab.c" /* yacc.c:355  */
};

typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_Y_TAB_H_INCLUDED  */

/* Copy the second part of user declarations.  */

#line 243 "y.tab.c" /* yacc.c:358  */

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
#define YYFINAL  5
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   538

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  68
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  25
/* YYNRULES -- Number of rules.  */
#define YYNRULES  90
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  231

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
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
      65,    66,    57,    55,    64,    56,     2,    58,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,    67,    60,
      52,    63,    54,     2,     2,     2,     2,     2,     2,     2,
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
static const yytype_uint16 yyrline[] =
{
       0,    45,    45,    47,    48,    49,    50,    52,    53,    54,
      55,    57,    58,    59,    60,    62,    63,    64,    65,    66,
      67,    69,    85,   102,   103,   104,   105,   113,   124,   137,
     138,   145,   153,   160,   168,   176,   184,   195,   210,   220,
     230,   237,   247,   257,   264,   271,   279,   285,   294,   303,
     309,   317,   325,   326,   333,   341,   344,   349,   354,   360,
     365,   371,   376,   380,   385,   390,   391,   395,   401,   402,
     406,   413,   414,   418,   423,   424,   428,   434,   439,   444,
     452,   458,   463,   464,   465,   466,   467,   470,   471,   472,
     473
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || 0
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "SET", "NEQ", "LE", "GE", "AND", "OR",
  "ID", "ARRAY", "BOOLEAN", "BEG", "BREAK", "CHAR", "CASE", "CONST",
  "CONTINUE", "DO", "ELSE", "END", "EXIT", "FALSE", "FOR", "FN", "IF",
  "IN", "INTEGER", "OF", "READ", "LOOP", "MODULE", "PRINT", "PRINTLN",
  "PROCEDURE", "REPEAT", "RETURN", "REAL", "STRING", "RECORD", "THEN",
  "TRUE", "TYPE", "USE", "VAR", "UTIL", "WHILE", "INT_CON", "STR_CON",
  "REAL_CON", "BOOL_CON", "'~'", "'<'", "EQ", "'>'", "'+'", "'-'", "'*'",
  "'/'", "UMINUS", "';'", "'['", "']'", "'='", "','", "'('", "')'", "':'",
  "$accept", "program", "program_decl", "var_delc_glo", "var_delc_loc",
  "statement", "simple", "expression", "comma_exp", "proc_invo",
  "fun_invo", "fun", "fun_var", "loop", "condition", "array", "const_glo",
  "const_loc", "var_glo", "var_loc", "var_com", "var_decl", "var_ID",
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
      59,    91,    93,    61,    44,    40,    41,    58
};
# endif

#define YYPACT_NINF -52

#define yypact_value_is_default(Yystate) \
  (!!((Yystate) == (-52)))

#define YYTABLE_NINF -1

#define yytable_value_is_error(Yytable_value) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
     -16,    -7,    23,   -52,   123,   -52,    -7,    -7,    -7,    19,
     123,    11,   -52,   -51,   -15,    -7,    49,   -26,    15,    -7,
     116,    10,    52,    11,    11,    -7,    50,    -7,    -7,   149,
     156,    -7,   149,    46,    -7,   149,    54,    -7,    74,    74,
       3,    61,   402,   -52,   -52,   -52,   -52,    14,   -52,    70,
     -52,   -52,   -52,   -52,   -52,   -52,    72,   -52,   -52,   -52,
     -52,    16,   -52,    88,   -52,    10,    -7,    -7,    -7,   102,
      13,   -52,    81,    74,    75,    74,    74,   300,   -52,   -21,
     -52,   310,   -52,   320,    74,    -7,    10,    74,   -52,    91,
      74,   124,   131,   -52,   149,   460,    -7,   126,   144,    -7,
     132,   -52,   149,    10,    83,   -52,   142,   209,   -52,   420,
     110,    74,    74,    74,    74,    74,    74,    74,    74,    74,
      74,    74,   -52,    74,   148,    74,   -52,   -52,   224,   -52,
     330,   157,   239,    25,   154,   158,   -52,    -7,    -7,   149,
     156,    -7,   149,   -52,   462,   159,   180,   107,   107,   107,
     420,   410,   107,   107,    71,    71,   110,   110,   400,   162,
      41,   203,   -52,   222,    74,    74,   173,   187,   188,   176,
     177,   179,   150,    -7,   190,    10,   -52,   -52,    10,    74,
     400,   400,   -52,   178,   186,   -52,   194,   -52,   -52,   195,
     189,   191,    68,   490,   340,   223,   226,   193,   196,   -52,
     227,    10,   192,   198,   -52,   149,   149,   215,   221,   149,
     492,   -52,   -52,   210,   211,   207,   212,   213,   217,   -52,
     -52,   255,   256,   -52,   -52,   149,   149,   225,   228,   -52,
     -52
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       0,     0,     0,    81,     3,     1,     0,     0,     0,     0,
       5,     4,     9,     0,    77,     7,     0,    77,    55,     8,
       0,    20,    10,     6,    52,     0,     0,     0,    65,     0,
       0,     0,     0,     0,    71,     0,     0,     0,     0,     0,
       0,     0,     0,    16,    19,    17,    18,     0,    78,     0,
      79,    86,    84,    82,    83,    85,     0,    87,    90,    88,
      89,     0,    57,     0,    56,    20,     0,     0,     0,    60,
       0,    13,     0,     0,     0,     0,     0,     0,    30,    28,
      29,     0,    26,     0,     0,     0,    15,     0,    49,     0,
       0,     0,     0,    67,     0,     0,    11,     0,    77,    12,
       0,    58,     0,    20,    14,    73,     0,     0,    23,    40,
      32,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    24,     0,     0,     0,    25,    27,     0,     2,
       0,     0,    46,     0,     0,     0,    80,     0,    68,     0,
       0,    74,     0,    59,     0,     0,     0,    45,    41,    42,
      43,    44,    39,    38,    33,    34,    35,    36,    37,     0,
       0,     0,    21,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    20,    31,    51,    20,     0,
      47,    48,    50,     0,     0,    53,     0,    70,    76,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    54,
       0,    20,     0,     0,    22,     0,     0,     0,     0,     0,
       0,    62,    61,     0,     0,     0,     0,     0,     0,    64,
      66,     0,     0,    72,    63,     0,     0,     0,     0,    69,
      75
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
     -52,   -52,   -52,   246,   253,   -17,   -52,    33,   164,   -52,
     -52,    24,   -52,   -52,   -52,   -23,   286,   233,   292,   242,
     160,   243,    -1,   -24,   -29
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     2,     9,    22,   104,    86,    43,   132,   133,    44,
      78,    24,    33,    45,    46,    12,    28,   138,    34,   141,
      13,    62,    79,    56,    80
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_uint8 yytable[] =
{
       4,    61,     3,    14,    42,    17,    18,    14,    64,    14,
      71,    72,     3,    25,    17,     1,    26,    87,    14,     3,
      47,    14,     3,     5,    48,   103,    50,    17,    11,    66,
      63,    21,    14,    14,    23,    36,    74,    30,    27,    37,
     124,    47,    38,    39,   125,     7,    40,    71,    95,    27,
      57,    58,    59,    60,    75,     3,    41,    67,    65,    76,
      49,     3,    66,    82,    47,    98,    14,    63,     6,    14,
     136,    77,    81,    83,    88,    89,    93,     3,   143,    90,
      31,    71,    32,     3,   129,    47,   144,   201,   202,   165,
      67,   166,     3,    36,    47,    98,     8,    37,    14,    66,
      38,    39,    47,    14,    40,   165,   107,   177,   109,   110,
      68,   171,    69,    25,    41,   170,    29,   128,   172,    73,
     130,    57,    58,    59,    60,    75,    84,    67,   120,   121,
      76,    91,     3,    92,   123,   108,   169,    98,   131,     6,
      14,   105,   106,    47,   147,   148,   149,   150,   151,   152,
     153,   154,   155,   156,   157,    94,   158,     7,   192,    51,
      52,   193,   118,   119,   120,   121,    16,     8,    20,   102,
     123,   134,   190,   123,    47,    16,    53,    47,   135,    20,
      25,   213,   214,    35,   210,   217,    54,    55,    16,   145,
      25,    47,    47,   139,    20,   159,    25,   180,   181,   142,
      47,   227,   228,    57,    58,    59,    60,   140,    27,    47,
     188,   189,   194,   111,   112,   113,   114,   115,   167,   163,
     175,   178,   168,   174,   176,   179,    97,   100,   111,   112,
     113,   114,   115,   182,   183,   184,   185,   191,   186,   187,
     195,   197,   198,   111,   112,   113,   114,   115,   196,   199,
      10,   205,   211,   200,   206,   209,    97,   207,   212,   100,
     208,   116,   215,   117,   118,   119,   120,   121,   216,   221,
     219,   220,   123,   223,   222,   146,   116,   224,   117,   118,
     119,   120,   121,   225,   226,   229,    70,   123,   230,   160,
     161,   116,    15,   117,   118,   119,   120,   121,    97,    96,
      19,   100,   123,   164,   111,   112,   113,   114,   115,    99,
       0,   101,     0,     0,   111,   112,   113,   114,   115,     0,
       0,     0,     0,     0,   111,   112,   113,   114,   115,     0,
       0,     0,     0,     0,   111,   112,   113,   114,   115,     0,
       0,     0,     0,     0,   111,   112,   113,   114,   115,     0,
       0,     0,   116,     0,   117,   118,   119,   120,   121,     0,
     122,     0,   116,   123,   117,   118,   119,   120,   121,     0,
     126,     0,   116,   123,   117,   118,   119,   120,   121,     0,
     127,     0,   116,   123,   117,   118,   119,   120,   121,     0,
     162,     0,   116,   123,   117,   118,   119,   120,   121,     0,
     204,     0,     0,   123,   111,   112,   113,   114,   115,     0,
       0,     3,     0,     0,   111,   112,   113,   114,     0,     0,
       0,     0,    85,     0,   111,   112,   113,    36,     0,     0,
       0,    37,     0,     0,    38,    39,     0,     0,    40,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    41,     0,
       0,     0,   116,     0,   117,   118,   119,   120,   121,     0,
       0,     0,   116,   123,   117,   118,   119,   120,   121,     3,
       0,     3,   116,   123,   117,   118,   119,   120,   121,     0,
     137,     0,   173,   123,     0,    36,     0,    36,     0,    37,
       0,    37,    38,    39,    38,    39,    40,     0,    40,     3,
       0,     3,     0,     0,     0,     0,    41,     0,    41,     0,
     203,     0,   218,     0,     0,    36,     0,    36,     0,    37,
       0,    37,    38,    39,    38,    39,    40,     0,    40,     0,
       0,     0,     0,     0,     0,     0,    41,     0,    41
};

static const yytype_int16 yycheck[] =
{
       1,    30,     9,     4,    21,     6,     7,     8,    32,    10,
      33,    35,     9,    64,    15,    31,    67,     3,    19,     9,
      21,    22,     9,     0,    25,    12,    27,    28,     4,    16,
      31,    12,    33,    34,    10,    25,    37,    63,    64,    29,
      61,    42,    32,    33,    65,    34,    36,    70,    65,    64,
      47,    48,    49,    50,    51,     9,    46,    44,    12,    56,
      10,     9,    16,    60,    65,    66,    67,    68,    16,    70,
      94,    38,    39,    40,    60,    61,    60,     9,   102,    65,
      65,   104,    67,     9,    85,    86,   103,    19,    20,    64,
      44,    66,     9,    25,    95,    96,    44,    29,    99,    16,
      32,    33,   103,   104,    36,    64,    73,    66,    75,    76,
      64,   140,    66,    64,    46,   139,    67,    84,   142,    65,
      87,    47,    48,    49,    50,    51,    65,    44,    57,    58,
      56,    61,     9,    61,    63,    60,   137,   138,    47,    16,
     141,    60,    61,   144,   111,   112,   113,   114,   115,   116,
     117,   118,   119,   120,   121,    67,   123,    34,   175,    10,
      11,   178,    55,    56,    57,    58,     6,    44,     8,    67,
      63,    47,   173,    63,   175,    15,    27,   178,    47,    19,
      64,   205,   206,    67,   201,   209,    37,    38,    28,    47,
      64,   192,   193,    67,    34,    47,    64,   164,   165,    67,
     201,   225,   226,    47,    48,    49,    50,    63,    64,   210,
      60,    61,   179,     4,     5,     6,     7,     8,    64,    62,
      40,    18,    64,    64,    62,     3,    66,    67,     4,     5,
       6,     7,     8,    60,    47,    47,    60,    47,    61,    60,
      62,    47,    47,     4,     5,     6,     7,     8,    62,    60,
       4,    28,    60,    62,    28,    28,    96,    64,    60,    99,
      64,    52,    47,    54,    55,    56,    57,    58,    47,    62,
      60,    60,    63,    60,    62,    66,    52,    60,    54,    55,
      56,    57,    58,    28,    28,    60,    33,    63,    60,   125,
      66,    52,     6,    54,    55,    56,    57,    58,   138,    66,
       8,   141,    63,    64,     4,     5,     6,     7,     8,    67,
      -1,    68,    -1,    -1,     4,     5,     6,     7,     8,    -1,
      -1,    -1,    -1,    -1,     4,     5,     6,     7,     8,    -1,
      -1,    -1,    -1,    -1,     4,     5,     6,     7,     8,    -1,
      -1,    -1,    -1,    -1,     4,     5,     6,     7,     8,    -1,
      -1,    -1,    52,    -1,    54,    55,    56,    57,    58,    -1,
      60,    -1,    52,    63,    54,    55,    56,    57,    58,    -1,
      60,    -1,    52,    63,    54,    55,    56,    57,    58,    -1,
      60,    -1,    52,    63,    54,    55,    56,    57,    58,    -1,
      60,    -1,    52,    63,    54,    55,    56,    57,    58,    -1,
      60,    -1,    -1,    63,     4,     5,     6,     7,     8,    -1,
      -1,     9,    -1,    -1,     4,     5,     6,     7,    -1,    -1,
      -1,    -1,    20,    -1,     4,     5,     6,    25,    -1,    -1,
      -1,    29,    -1,    -1,    32,    33,    -1,    -1,    36,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    46,    -1,
      -1,    -1,    52,    -1,    54,    55,    56,    57,    58,    -1,
      -1,    -1,    52,    63,    54,    55,    56,    57,    58,     9,
      -1,     9,    52,    63,    54,    55,    56,    57,    58,    -1,
      20,    -1,    20,    63,    -1,    25,    -1,    25,    -1,    29,
      -1,    29,    32,    33,    32,    33,    36,    -1,    36,     9,
      -1,     9,    -1,    -1,    -1,    -1,    46,    -1,    46,    -1,
      20,    -1,    20,    -1,    -1,    25,    -1,    25,    -1,    29,
      -1,    29,    32,    33,    32,    33,    36,    -1,    36,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    46,    -1,    46
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,    31,    69,     9,    90,     0,    16,    34,    44,    70,
      71,    79,    83,    88,    90,    84,    88,    90,    90,    86,
      88,    12,    71,    79,    79,    64,    67,    64,    84,    67,
      63,    65,    67,    80,    86,    67,    25,    29,    32,    33,
      36,    46,    73,    74,    77,    81,    82,    90,    90,    10,
      90,    10,    11,    27,    37,    38,    91,    47,    48,    49,
      50,    92,    89,    90,    91,    12,    16,    44,    64,    66,
      72,    83,    91,    65,    90,    51,    56,    75,    78,    90,
      92,    75,    60,    75,    65,    20,    73,     3,    60,    61,
      65,    61,    61,    60,    67,    73,    85,    88,    90,    87,
      88,    89,    67,    12,    72,    60,    61,    75,    60,    75,
      75,     4,     5,     6,     7,     8,    52,    54,    55,    56,
      57,    58,    60,    63,    61,    65,    60,    60,    75,    90,
      75,    47,    75,    76,    47,    47,    91,    20,    85,    67,
      63,    87,    67,    91,    73,    47,    66,    75,    75,    75,
      75,    75,    75,    75,    75,    75,    75,    75,    75,    47,
      76,    66,    60,    62,    64,    64,    66,    64,    64,    90,
      91,    92,    91,    20,    64,    40,    62,    66,    18,     3,
      75,    75,    60,    47,    47,    60,    61,    60,    60,    61,
      90,    47,    73,    73,    75,    62,    62,    47,    47,    60,
      62,    19,    20,    20,    60,    28,    28,    64,    64,    28,
      73,    60,    60,    91,    91,    47,    47,    91,    20,    60,
      60,    62,    62,    60,    60,    28,    28,    91,    91,    60,
      60
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    68,    69,    70,    70,    70,    70,    71,    71,    71,
      71,    72,    72,    72,    72,    73,    73,    73,    73,    73,
      73,    74,    74,    74,    74,    74,    74,    74,    75,    75,
      75,    75,    75,    75,    75,    75,    75,    75,    75,    75,
      75,    75,    75,    75,    75,    75,    76,    76,    76,    77,
      77,    78,    79,    79,    79,    80,    80,    80,    80,    80,
      80,    81,    82,    82,    83,    84,    84,    84,    85,    85,
      85,    86,    86,    86,    87,    87,    87,    88,    88,    88,
      89,    90,    91,    91,    91,    91,    91,    92,    92,    92,
      92
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     7,     0,     1,     1,     2,     2,     2,     1,
       2,     2,     2,     1,     2,     2,     1,     1,     1,     1,
       0,     4,     7,     3,     3,     3,     2,     3,     1,     1,
       1,     4,     2,     3,     3,     3,     3,     3,     3,     3,
       2,     3,     3,     3,     3,     3,     1,     3,     3,     2,
       5,     4,     2,     8,     9,     0,     2,     2,     3,     4,
       2,     8,     8,    10,    11,     2,    11,     4,     2,    11,
       4,     2,    11,     4,     2,    11,     4,     1,     3,     3,
       3,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1
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
#line 45 "parse.y" /* yacc.c:1646  */
    {Trace("End Parse");dump();}
#line 1536 "y.tab.c" /* yacc.c:1646  */
    break;

  case 7:
#line 52 "parse.y" /* yacc.c:1646  */
    {Trace("const 2 delc+glo");}
#line 1542 "y.tab.c" /* yacc.c:1646  */
    break;

  case 8:
#line 53 "parse.y" /* yacc.c:1646  */
    {Trace("var 2 delc+glo");}
#line 1548 "y.tab.c" /* yacc.c:1646  */
    break;

  case 9:
#line 54 "parse.y" /* yacc.c:1646  */
    {Trace("arr 2 delc+glo"); (yyvsp[0].tval)->isglobal = 0;}
#line 1554 "y.tab.c" /* yacc.c:1646  */
    break;

  case 10:
#line 55 "parse.y" /* yacc.c:1646  */
    {Trace("Combine Var glo");}
#line 1560 "y.tab.c" /* yacc.c:1646  */
    break;

  case 11:
#line 57 "parse.y" /* yacc.c:1646  */
    {Trace("const 2 delc+loc");}
#line 1566 "y.tab.c" /* yacc.c:1646  */
    break;

  case 12:
#line 58 "parse.y" /* yacc.c:1646  */
    {Trace("var 2 delc+loc");}
#line 1572 "y.tab.c" /* yacc.c:1646  */
    break;

  case 13:
#line 59 "parse.y" /* yacc.c:1646  */
    {Trace("arr 2 delc+loc"); (yyvsp[0].tval)->isglobal = 1;}
#line 1578 "y.tab.c" /* yacc.c:1646  */
    break;

  case 14:
#line 60 "parse.y" /* yacc.c:1646  */
    {Trace("Combine Var loc");}
#line 1584 "y.tab.c" /* yacc.c:1646  */
    break;

  case 15:
#line 62 "parse.y" /* yacc.c:1646  */
    {Trace("statement Combine");}
#line 1590 "y.tab.c" /* yacc.c:1646  */
    break;

  case 16:
#line 63 "parse.y" /* yacc.c:1646  */
    {Trace("statement simple");}
#line 1596 "y.tab.c" /* yacc.c:1646  */
    break;

  case 17:
#line 64 "parse.y" /* yacc.c:1646  */
    {Trace("statement loop");}
#line 1602 "y.tab.c" /* yacc.c:1646  */
    break;

  case 18:
#line 65 "parse.y" /* yacc.c:1646  */
    {Trace("statement condition");}
#line 1608 "y.tab.c" /* yacc.c:1646  */
    break;

  case 19:
#line 66 "parse.y" /* yacc.c:1646  */
    {Trace("statement proc_invo");}
#line 1614 "y.tab.c" /* yacc.c:1646  */
    break;

  case 20:
#line 67 "parse.y" /* yacc.c:1646  */
    {Trace("Null Statement");}
#line 1620 "y.tab.c" /* yacc.c:1646  */
    break;

  case 21:
#line 69 "parse.y" /* yacc.c:1646  */
    {
			Trace("ID SET exp");

			if(lookup((yyvsp[-3].tval)->id)==-1) yyerror("ID No define");
			else (yyvsp[-3].tval) = ReturnID((yyvsp[-3].tval)->id);
			if((yyvsp[-3].tval)->isvar == 1) yyerror("Const can't assign");
			if((yyvsp[-3].tval)->type != (yyvsp[-1].tval)->type) yyerror("Type Diff");
			if((yyvsp[-3].tval)->type == 0)
				(yyvsp[-3].tval)->ival = (yyvsp[-1].tval)->ival;
			else if((yyvsp[-3].tval)->type == 1)
				(yyvsp[-3].tval)->dval = (yyvsp[-1].tval)->dval;
			else if((yyvsp[-3].tval)->type == 2)
				(yyvsp[-3].tval)->bval = (yyvsp[-1].tval)->bval;
			else if((yyvsp[-3].tval)->type == 3)
				strcpy((yyvsp[-3].tval)->cval, (yyvsp[-1].tval)->cval);
		}
#line 1641 "y.tab.c" /* yacc.c:1646  */
    break;

  case 22:
#line 85 "parse.y" /* yacc.c:1646  */
    {
			Trace("ID[i] SET EXP");
			if(lookup((yyvsp[-6].tval)->id)==-1) yyerror("ID No define");
			else (yyvsp[-6].tval) = ReturnID((yyvsp[-6].tval)->id);
			if((yyvsp[-6].tval)->type != 4) yyerror("Not Array Type");
			if((yyvsp[-6].tval)->arr1 > (yyvsp[-4].ival) || (yyvsp[-4].ival) > (yyvsp[-6].tval)->arr2) yyerror("Array Out Of Range");
			if((yyvsp[-6].tval)->aval != (yyvsp[-1].tval)->type) yyerror("Type Diff");
			(yyvsp[-6].tval) = ReturnArrItem((yyvsp[-6].tval)->arr,(yyvsp[-4].ival));
			if((yyvsp[-6].tval)->type == 0)
				(yyvsp[-6].tval)->ival = (yyvsp[-1].tval)->ival;
			else if((yyvsp[-6].tval)->type == 1)
				(yyvsp[-6].tval)->dval = (yyvsp[-1].tval)->dval;
			else if((yyvsp[-6].tval)->type == 2)
				(yyvsp[-6].tval)->bval = (yyvsp[-1].tval)->bval;
			else if((yyvsp[-6].tval)->type == 3)
				strcpy((yyvsp[-6].tval)->cval, (yyvsp[-1].tval)->cval);
		}
#line 1663 "y.tab.c" /* yacc.c:1646  */
    break;

  case 23:
#line 102 "parse.y" /* yacc.c:1646  */
    {Trace("READ ID"); if(lookup((yyvsp[-1].tval)->id)==-1) yyerror("ID No define"); }
#line 1669 "y.tab.c" /* yacc.c:1646  */
    break;

  case 24:
#line 103 "parse.y" /* yacc.c:1646  */
    {Trace("PRINT");}
#line 1675 "y.tab.c" /* yacc.c:1646  */
    break;

  case 25:
#line 104 "parse.y" /* yacc.c:1646  */
    {Trace("PRINTLN");}
#line 1681 "y.tab.c" /* yacc.c:1646  */
    break;

  case 26:
#line 105 "parse.y" /* yacc.c:1646  */
    {
			Trace("RETURN");
			SymbolTable* t = (SymbolTable*)malloc(sizeof(SymbolTable));;
			t = tmpVar("tmp",-1);
			t->isvar = 5;
			t->type = 6;
			insertReturn(t);
		}
#line 1694 "y.tab.c" /* yacc.c:1646  */
    break;

  case 27:
#line 113 "parse.y" /* yacc.c:1646  */
    {
			Trace("RETURN exp");
			SymbolTable* t = (SymbolTable*)malloc(sizeof(SymbolTable));;
			t = tmpVar("tmp",-1);
			t->isvar = 5;
			printf("%d\n",(yyvsp[-1].tval)->type);
			t->type = (yyvsp[-1].tval)->type;
			insertReturn(t);
		}
#line 1708 "y.tab.c" /* yacc.c:1646  */
    break;

  case 28:
#line 124 "parse.y" /* yacc.c:1646  */
    {
			Trace("ID 2 exp");
			if(lookup((yyvsp[0].tval)->id)==-1) yyerror("ID No define");
			else (yyvsp[0].tval) = ReturnID((yyvsp[0].tval)->id);
			(yyval.tval) =  (SymbolTable*)malloc(sizeof(SymbolTable));
			copyVar((yyval.tval),(yyvsp[0].tval));
			(yyval.tval)->next == NULL;
			if((yyvsp[0].tval)->type == 5){
				if((yyvsp[0].tval)->delcNum != 0) yyerror("Delc variable numuber not correct");
				(yyval.tval)->type = (yyvsp[0].tval)->fval->returnType;
				if((yyval.tval)->type == 6) yyerror("Use void type calc");
			}
		}
#line 1726 "y.tab.c" /* yacc.c:1646  */
    break;

  case 29:
#line 137 "parse.y" /* yacc.c:1646  */
    { Trace("con 2 exp"); (yyval.tval) = (yyvsp[0].tval);}
#line 1732 "y.tab.c" /* yacc.c:1646  */
    break;

  case 30:
#line 138 "parse.y" /* yacc.c:1646  */
    { 
			Trace("fun 2 exp"); 
			(yyval.tval) =  (SymbolTable*)malloc(sizeof(SymbolTable));
			copyVar((yyval.tval),(yyvsp[0].tval));
			(yyval.tval)->next == NULL;
			(yyval.tval)->type = (yyvsp[0].tval)->fval->returnType;
		}
#line 1744 "y.tab.c" /* yacc.c:1646  */
    break;

  case 31:
#line 145 "parse.y" /* yacc.c:1646  */
    {
			Trace("arr 2 exp");
			if(lookup((yyvsp[-3].tval)->id)==-1) yyerror("ID No define");
			else (yyvsp[-3].tval) = ReturnID((yyvsp[-3].tval)->id);
			if((yyvsp[-3].tval)->type != 4) yyerror("Not Array Type");
			if((yyvsp[-3].tval)->arr1 > (yyvsp[-1].ival) || (yyvsp[-1].ival) > (yyvsp[-3].tval)->arr2) yyerror("Array Out Of Range");
			(yyval.tval) = ReturnArrItem((yyvsp[-3].tval)->arr,(yyvsp[-1].ival));
		}
#line 1757 "y.tab.c" /* yacc.c:1646  */
    break;

  case 32:
#line 153 "parse.y" /* yacc.c:1646  */
    {
			Trace("-exp");
			if((yyvsp[0].tval)->type>=2) yyerror("Unknown");
			else if((yyvsp[0].tval)->type==1) (yyvsp[0].tval)->dval = -(yyvsp[0].tval)->dval;
			else (yyvsp[0].tval)->ival = -(yyvsp[0].tval)->ival;
			(yyval.tval) = (yyvsp[0].tval);
		}
#line 1769 "y.tab.c" /* yacc.c:1646  */
    break;

  case 33:
#line 160 "parse.y" /* yacc.c:1646  */
    {
			Trace("exp + exp");
			if((yyvsp[-2].tval)->type >=2 || (yyvsp[0].tval)->type >=2) yyerror("Type Error");
			if((yyvsp[-2].tval)->type != (yyvsp[0].tval)->type) yyerror("Type Diff");
			(yyval.tval) = tmpVar("tmp",(yyvsp[-2].tval)->type);
			(yyval.tval)->ival = (yyvsp[-2].tval)->ival + (yyvsp[0].tval)->ival;
			(yyval.tval)->dval = (yyvsp[-2].tval)->dval + (yyvsp[0].tval)->dval;
		}
#line 1782 "y.tab.c" /* yacc.c:1646  */
    break;

  case 34:
#line 168 "parse.y" /* yacc.c:1646  */
    {
			Trace("exp - exp");
			if((yyvsp[-2].tval)->type >=2 || (yyvsp[0].tval)->type >=2) yyerror("Type Error");
			if((yyvsp[-2].tval)->type != (yyvsp[0].tval)->type) yyerror("Type Diff");
			(yyval.tval) = tmpVar("tmp",(yyvsp[-2].tval)->type);
			(yyval.tval)->ival = (yyvsp[-2].tval)->ival - (yyvsp[0].tval)->ival;
			(yyval.tval)->dval = (yyvsp[-2].tval)->dval - (yyvsp[0].tval)->dval;
		}
#line 1795 "y.tab.c" /* yacc.c:1646  */
    break;

  case 35:
#line 176 "parse.y" /* yacc.c:1646  */
    {
			Trace("exp * exp");
			if((yyvsp[-2].tval)->type >=2 || (yyvsp[0].tval)->type >=2) yyerror("Type Error");
			if((yyvsp[-2].tval)->type != (yyvsp[0].tval)->type) yyerror("Type Diff");
			(yyval.tval) = tmpVar("tmp",(yyvsp[-2].tval)->type);
			(yyval.tval)->ival = (yyvsp[-2].tval)->ival * (yyvsp[0].tval)->ival;
			(yyval.tval)->dval = (yyvsp[-2].tval)->dval * (yyvsp[0].tval)->dval;
		}
#line 1808 "y.tab.c" /* yacc.c:1646  */
    break;

  case 36:
#line 184 "parse.y" /* yacc.c:1646  */
    {
			Trace("exp / exp");
			if((yyvsp[-2].tval)->type >=2 || (yyvsp[0].tval)->type >=2) yyerror("Type Error");
			if((yyvsp[-2].tval)->type != (yyvsp[0].tval)->type) yyerror("Type Diff");
			(yyval.tval) = tmpVar("tmp",(yyvsp[-2].tval)->type);
			if((yyvsp[0].tval)->type == 0 && (yyvsp[0].tval)->ival != 0)
				(yyval.tval)->ival = (yyvsp[-2].tval)->ival / (yyvsp[0].tval)->ival;
			else if((yyvsp[0].tval)->type == 1 && (yyvsp[0].tval)->dval != 0)
				(yyval.tval)->dval = (yyvsp[-2].tval)->dval / (yyvsp[0].tval)->dval;
			else	yyerror("Divide 0");
		}
#line 1824 "y.tab.c" /* yacc.c:1646  */
    break;

  case 37:
#line 195 "parse.y" /* yacc.c:1646  */
    {
			Trace("exp = exp");
			if((yyvsp[-2].tval)->isvar == 1) yyerror("Const can't assign");
			if((yyvsp[-2].tval)->type != (yyvsp[0].tval)->type) yyerror("Type Diff");
			if((yyvsp[-2].tval)->type == 0 && (yyvsp[-2].tval)->ival == (yyvsp[0].tval)->ival)
				(yyval.tval) = tmpConBool(1);
			else if((yyvsp[-2].tval)->type == 1 && (yyvsp[-2].tval)->dval == (yyvsp[0].tval)->dval)
				(yyval.tval) = tmpConBool(1);
			else if((yyvsp[-2].tval)->type == 2 && (yyvsp[-2].tval)->bval == (yyvsp[0].tval)->bval)
				(yyval.tval) = tmpConBool(1);
			else if((yyvsp[-2].tval)->type == 3 && strcmp((yyvsp[-2].tval)->cval, (yyvsp[0].tval)->cval) == 0)
				(yyval.tval) = tmpConBool(1);
			else
				(yyval.tval) = tmpConBool(0);
		}
#line 1844 "y.tab.c" /* yacc.c:1646  */
    break;

  case 38:
#line 210 "parse.y" /* yacc.c:1646  */
    {
			Trace("EXP > EXP");
			if((yyvsp[-2].tval)->type >=2 || (yyvsp[0].tval)->type >=2) yyerror("Type Error");
			if((yyvsp[-2].tval)->type != (yyvsp[0].tval)->type) yyerror("Type Diff");
			if((yyvsp[-2].tval)->type == 0 && (yyvsp[-2].tval)->ival > (yyvsp[0].tval)->ival)
				(yyval.tval) = tmpConBool(1);
			else if((yyvsp[-2].tval)->type == 1 && (yyvsp[-2].tval)->dval > (yyvsp[0].tval)->dval)
				(yyval.tval) = tmpConBool(1);
			else (yyval.tval) = tmpConBool(0);
		}
#line 1859 "y.tab.c" /* yacc.c:1646  */
    break;

  case 39:
#line 220 "parse.y" /* yacc.c:1646  */
    {
			Trace("EXP < EXP");
			if((yyvsp[-2].tval)->type >=2 || (yyvsp[0].tval)->type >=2) yyerror("Type Error");
			if((yyvsp[-2].tval)->type != (yyvsp[0].tval)->type) yyerror("Type Diff");
			if((yyvsp[-2].tval)->type == 0 && (yyvsp[-2].tval)->ival < (yyvsp[0].tval)->ival)
				(yyval.tval) = tmpConBool(1);
			else if((yyvsp[-2].tval)->type == 1 && (yyvsp[-2].tval)->dval < (yyvsp[0].tval)->dval)
				(yyval.tval) = tmpConBool(1);
			else (yyval.tval) = tmpConBool(0);
		}
#line 1874 "y.tab.c" /* yacc.c:1646  */
    break;

  case 40:
#line 230 "parse.y" /* yacc.c:1646  */
    {
			Trace("Not EXP");
			if((yyvsp[0].tval)->type !=2) yyerror("Type Error");
			if((yyvsp[0].tval)->bval == 0)
				(yyval.tval) = tmpConBool(1);
			else (yyval.tval) = tmpConBool(0);
		}
#line 1886 "y.tab.c" /* yacc.c:1646  */
    break;

  case 41:
#line 237 "parse.y" /* yacc.c:1646  */
    {
			Trace("EXP <= EXP");
			if((yyvsp[-2].tval)->type >= 2 || (yyvsp[0].tval)->type >= 2) yyerror("Type Error");
			if((yyvsp[-2].tval)->type != (yyvsp[0].tval)->type) yyerror("Type Diff");
			if((yyvsp[-2].tval)->type == 0 && (yyvsp[-2].tval)->ival <= (yyvsp[0].tval)->ival)
				(yyval.tval) = tmpConBool(1);
			else if((yyvsp[-2].tval)->type == 1 && (yyvsp[-2].tval)->dval <= (yyvsp[0].tval)->dval)
				(yyval.tval) = tmpConBool(1);
			else (yyval.tval) = tmpConBool(0);
		}
#line 1901 "y.tab.c" /* yacc.c:1646  */
    break;

  case 42:
#line 247 "parse.y" /* yacc.c:1646  */
    {
			Trace("EXP > EXP");
			if((yyvsp[-2].tval)->type >=2 || (yyvsp[0].tval)->type >=2) yyerror("Type Error");
			if((yyvsp[-2].tval)->type != (yyvsp[0].tval)->type) yyerror("Type Diff");
			if((yyvsp[-2].tval)->type == 0 && (yyvsp[-2].tval)->ival >= (yyvsp[0].tval)->ival)
				(yyval.tval) = tmpConBool(1);
			else if((yyvsp[-2].tval)->type == 1 && (yyvsp[-2].tval)->dval >= (yyvsp[0].tval)->dval)
				(yyval.tval) = tmpConBool(1);
			else (yyval.tval) = tmpConBool(0);
		}
#line 1916 "y.tab.c" /* yacc.c:1646  */
    break;

  case 43:
#line 257 "parse.y" /* yacc.c:1646  */
    {
			Trace("AND EXP");
			if((yyvsp[-2].tval)->type != 2 || (yyvsp[0].tval)->type != 2) yyerror("Type Error");
			if((yyvsp[-2].tval)->bval == 1 && (yyvsp[0].tval)->bval == 1)
				(yyval.tval) = tmpConBool(1);
			else (yyval.tval) = tmpConBool(0);
		}
#line 1928 "y.tab.c" /* yacc.c:1646  */
    break;

  case 44:
#line 264 "parse.y" /* yacc.c:1646  */
    {
			Trace("OR EXP");
			if((yyvsp[-2].tval)->type != 2 || (yyvsp[0].tval)->type != 2) yyerror("Type Error");
			if((yyvsp[-2].tval)->bval == 1 || (yyvsp[0].tval)->bval == 1)
				(yyval.tval) = tmpConBool(1);
			else (yyval.tval) = tmpConBool(0);
		}
#line 1940 "y.tab.c" /* yacc.c:1646  */
    break;

  case 45:
#line 271 "parse.y" /* yacc.c:1646  */
    {
			Trace("!= EXP");
			if((yyvsp[-2].tval)->type != 2 || (yyvsp[0].tval)->type != 2) yyerror("Type Error");
			if((yyvsp[-2].tval)->bval == 1 && (yyvsp[0].tval)->bval == 1)
				(yyval.tval) = tmpConBool(1);
			else (yyval.tval) = tmpConBool(0);
		}
#line 1952 "y.tab.c" /* yacc.c:1646  */
    break;

  case 46:
#line 279 "parse.y" /* yacc.c:1646  */
    {
			Trace("1 comma");
			(yyval.tval) = tmpVar("tmp",-1);
			copyVar((yyval.tval),(yyvsp[0].tval));
			(yyval.tval)->next = NULL;
		}
#line 1963 "y.tab.c" /* yacc.c:1646  */
    break;

  case 47:
#line 285 "parse.y" /* yacc.c:1646  */
    {
			Trace("2 comma");
			(yyval.tval) = tmpVar("tmp",-1);
			copyVar((yyval.tval),(yyvsp[-2].tval));
			SymbolTable* t = tmpVar("tmp",-1);
			copyVar(t,(yyvsp[0].tval));
			t->next = NULL;
			(yyval.tval)->next = t;
		}
#line 1977 "y.tab.c" /* yacc.c:1646  */
    break;

  case 48:
#line 294 "parse.y" /* yacc.c:1646  */
    {
			Trace("more comma");
			SymbolTable* t = tmpVar("tmp",-1);
			copyVar(t,(yyvsp[0].tval));
			t->next = NULL;
			ConnectSymbol((yyvsp[-2].tval),t);
			(yyval.tval) = (yyvsp[-2].tval);
		}
#line 1990 "y.tab.c" /* yacc.c:1646  */
    break;

  case 49:
#line 303 "parse.y" /* yacc.c:1646  */
    {
			Trace("proc_invo null");
			if(lookup((yyvsp[-1].tval)->id)==-1) yyerror("ID No define");
			else (yyvsp[-1].tval) = ReturnID((yyvsp[-1].tval)->id);
			if((yyvsp[-1].tval)->delcNum != 0) yyerror("Delc variable numuber not correct");
		}
#line 2001 "y.tab.c" /* yacc.c:1646  */
    break;

  case 50:
#line 309 "parse.y" /* yacc.c:1646  */
    {
			Trace("proc_invo var");
			if(lookup((yyvsp[-4].tval)->id)==-1) yyerror("ID No define");
			else (yyvsp[-4].tval) = ReturnID((yyvsp[-4].tval)->id);
			if((yyvsp[-4].tval)->delcNum != SymbolTableLength((yyvsp[-2].tval))) yyerror("Delc variable numuber not correct");
			if(CompareType((yyvsp[-4].tval)->fval->lead,(yyvsp[-2].tval))==-1) yyerror("Delc variable type not correct");
		}
#line 2013 "y.tab.c" /* yacc.c:1646  */
    break;

  case 51:
#line 317 "parse.y" /* yacc.c:1646  */
    {
			Trace("fun_invo var");
			if(lookup((yyvsp[-3].tval)->id)==-1) yyerror("ID No define");
			else (yyval.tval) = ReturnID((yyvsp[-3].tval)->id);
			if((yyval.tval)->delcNum != SymbolTableLength((yyvsp[-1].tval))) yyerror("Delc variable numuber not correct");
			if(CompareType((yyval.tval)->fval->lead,(yyvsp[-1].tval))==-1) yyerror("Delc variable type not correct");
		}
#line 2025 "y.tab.c" /* yacc.c:1646  */
    break;

  case 53:
#line 326 "parse.y" /* yacc.c:1646  */
    {Trace("PROCEDURE");
			if(strcmp((yyvsp[-6].tval)->id,(yyvsp[-1].tval)->id) != 0) yyerror("PROCEDURE ID error");
			insertLocalToFunc((yyvsp[-5].fval));
			if(CompareFuncReturnType((yyvsp[-5].fval)) == 0) yyerror("Return type error");
			if(lookup((yyvsp[-6].tval)->id) == -1) insertFun((yyvsp[-5].fval),(yyvsp[-6].tval)->id);
			else yyerror("Func ID repeat");
		}
#line 2037 "y.tab.c" /* yacc.c:1646  */
    break;

  case 54:
#line 333 "parse.y" /* yacc.c:1646  */
    {Trace("PROCEDURE");
			if(strcmp((yyvsp[-7].tval)->id,(yyvsp[-1].tval)->id) != 0) yyerror("PROCEDURE ID error");
			insertLocalToFunc((yyvsp[-6].fval));
			if(CompareFuncReturnType((yyvsp[-6].fval)) == 0) yyerror("Return type error");
			if(lookup((yyvsp[-7].tval)->id) == -1) insertFun((yyvsp[-6].fval),(yyvsp[-7].tval)->id);
			else yyerror("Func ID repeat");
		}
#line 2049 "y.tab.c" /* yacc.c:1646  */
    break;

  case 55:
#line 341 "parse.y" /* yacc.c:1646  */
    {	Trace("Function no return & no var"); 
			(yyval.fval) = createFun();
			(yyval.fval)->returnType = 6;}
#line 2057 "y.tab.c" /* yacc.c:1646  */
    break;

  case 56:
#line 344 "parse.y" /* yacc.c:1646  */
    {
			Trace("Function no var"); 
			(yyval.fval) = createFun();
			(yyval.fval)->returnType = (yyvsp[0].ival);
		}
#line 2067 "y.tab.c" /* yacc.c:1646  */
    break;

  case 57:
#line 349 "parse.y" /* yacc.c:1646  */
    {
			Trace("Function add var"); (yyval.fval) = createFun(); 
			if(lookup((yyvsp[0].tval)->id) == -1) insertFunVar((yyvsp[0].tval));
			else yyerror("ID repeat");
		}
#line 2077 "y.tab.c" /* yacc.c:1646  */
    break;

  case 58:
#line 354 "parse.y" /* yacc.c:1646  */
    {
			Trace("more var");
			if(lookup((yyvsp[0].tval)->id) == -1) insertFunVar((yyvsp[0].tval));
			else yyerror("ID repeat");
			(yyval.fval) = (yyvsp[-2].fval);
		}
#line 2088 "y.tab.c" /* yacc.c:1646  */
    break;

  case 59:
#line 360 "parse.y" /* yacc.c:1646  */
    {
			Trace("End fun Var");
			(yyvsp[-3].fval)->returnType = (yyvsp[0].ival);
			(yyval.fval) = (yyvsp[-3].fval);
		}
#line 2098 "y.tab.c" /* yacc.c:1646  */
    break;

  case 60:
#line 365 "parse.y" /* yacc.c:1646  */
    {
			Trace("End fun Var & void");
			(yyvsp[-1].fval)->returnType = 6;
			(yyval.fval) = (yyvsp[-1].fval);
		}
#line 2108 "y.tab.c" /* yacc.c:1646  */
    break;

  case 61:
#line 371 "parse.y" /* yacc.c:1646  */
    {
			Trace("loop");
			if((yyvsp[-5].tval)->type != 2) yyerror("loop's type error");
		}
#line 2117 "y.tab.c" /* yacc.c:1646  */
    break;

  case 62:
#line 376 "parse.y" /* yacc.c:1646  */
    {
			Trace("condition");
			if((yyvsp[-5].tval)->type != 2) yyerror("condition's type error");
		}
#line 2126 "y.tab.c" /* yacc.c:1646  */
    break;

  case 63:
#line 380 "parse.y" /* yacc.c:1646  */
    {
			Trace("condition");
			if((yyvsp[-7].tval)->type != 2) yyerror("condition's type error");
		}
#line 2135 "y.tab.c" /* yacc.c:1646  */
    break;

  case 64:
#line 385 "parse.y" /* yacc.c:1646  */
    {
			if((yyvsp[-4].ival) <= (yyvsp[-6].ival)) yyerror("Array Range Error");
			RedefineArray((yyvsp[-1].ival),(yyvsp[-6].ival),(yyvsp[-4].ival),0);
		}
#line 2144 "y.tab.c" /* yacc.c:1646  */
    break;

  case 66:
#line 391 "parse.y" /* yacc.c:1646  */
    {
			if((yyvsp[-4].ival) <= (yyvsp[-6].ival)) yyerror("Array Range Error");
			RedefineArray((yyvsp[-1].ival),(yyvsp[-6].ival),(yyvsp[-4].ival),0);
		}
#line 2153 "y.tab.c" /* yacc.c:1646  */
    break;

  case 67:
#line 395 "parse.y" /* yacc.c:1646  */
    {
			Trace("insertConst glo");
			if(lookup((yyvsp[-3].tval)->id) == -1) insertConst((yyvsp[-1].tval),(yyvsp[-3].tval)->id,0);
			else yyerror("ID repeat");
		}
#line 2163 "y.tab.c" /* yacc.c:1646  */
    break;

  case 69:
#line 402 "parse.y" /* yacc.c:1646  */
    {
			if((yyvsp[-4].ival) <= (yyvsp[-6].ival)) yyerror("Array Range Error");
			RedefineArray((yyvsp[-1].ival),(yyvsp[-6].ival),(yyvsp[-4].ival),1);
		}
#line 2172 "y.tab.c" /* yacc.c:1646  */
    break;

  case 70:
#line 406 "parse.y" /* yacc.c:1646  */
    {
			Trace("insertConst loc");
			if(lookup((yyvsp[-3].tval)->id) == -1) insertConst((yyvsp[-1].tval),(yyvsp[-3].tval)->id,1);
			else yyerror("ID repeat");

		}
#line 2183 "y.tab.c" /* yacc.c:1646  */
    break;

  case 72:
#line 414 "parse.y" /* yacc.c:1646  */
    {
			if((yyvsp[-4].ival) <= (yyvsp[-6].ival)) yyerror("Array Range Error");
			RedefineArray((yyvsp[-1].ival),(yyvsp[-6].ival),(yyvsp[-4].ival),0);
		}
#line 2192 "y.tab.c" /* yacc.c:1646  */
    break;

  case 73:
#line 418 "parse.y" /* yacc.c:1646  */
    {
			Trace("insertVar glo");
			RedefineType((yyvsp[-1].ival),0);
		}
#line 2201 "y.tab.c" /* yacc.c:1646  */
    break;

  case 75:
#line 424 "parse.y" /* yacc.c:1646  */
    {
			if((yyvsp[-4].ival) <= (yyvsp[-6].ival)) yyerror("Array Range Error");
			RedefineArray((yyvsp[-1].ival),(yyvsp[-6].ival),(yyvsp[-4].ival),1);
		}
#line 2210 "y.tab.c" /* yacc.c:1646  */
    break;

  case 76:
#line 428 "parse.y" /* yacc.c:1646  */
    {
			Trace("insertVar loc");
			RedefineType((yyvsp[-1].ival),1);

		}
#line 2220 "y.tab.c" /* yacc.c:1646  */
    break;

  case 77:
#line 434 "parse.y" /* yacc.c:1646  */
    {
			Trace("var com");
			if(lookup((yyvsp[0].tval)->id) == -1) insertVar((yyvsp[0].tval),0);
			else yyerror("ID repeat");
		}
#line 2230 "y.tab.c" /* yacc.c:1646  */
    break;

  case 78:
#line 439 "parse.y" /* yacc.c:1646  */
    {
			Trace("var com");
			if(lookup((yyvsp[0].tval)->id) == -1) insertVar((yyvsp[0].tval),0);
			else yyerror("ID repeat");		
		}
#line 2240 "y.tab.c" /* yacc.c:1646  */
    break;

  case 79:
#line 444 "parse.y" /* yacc.c:1646  */
    {
			Trace("var com");
			if(lookup((yyvsp[-2].tval)->id) == -1) insertVar((yyvsp[-2].tval),0);
			else yyerror("ID repeat");
			if(lookup((yyvsp[0].tval)->id) == -1) insertVar((yyvsp[0].tval),0);
			else yyerror("ID repeat");
		}
#line 2252 "y.tab.c" /* yacc.c:1646  */
    break;

  case 80:
#line 452 "parse.y" /* yacc.c:1646  */
    {	
			Trace("Announce Var");
			(yyval.tval) = tmpVar((yyvsp[-2].tval)->id,(yyvsp[0].ival));
		}
#line 2261 "y.tab.c" /* yacc.c:1646  */
    break;

  case 81:
#line 458 "parse.y" /* yacc.c:1646  */
    { 
			Trace("Make ID"); 
			(yyval.tval) = tmpVar((yyvsp[0].cval),-1); 
		}
#line 2270 "y.tab.c" /* yacc.c:1646  */
    break;

  case 82:
#line 463 "parse.y" /* yacc.c:1646  */
    {Trace("int"); 	 (yyval.ival) = 0;}
#line 2276 "y.tab.c" /* yacc.c:1646  */
    break;

  case 83:
#line 464 "parse.y" /* yacc.c:1646  */
    {Trace("real");  (yyval.ival) = 1;}
#line 2282 "y.tab.c" /* yacc.c:1646  */
    break;

  case 84:
#line 465 "parse.y" /* yacc.c:1646  */
    {Trace("bool");	 (yyval.ival) = 2;}
#line 2288 "y.tab.c" /* yacc.c:1646  */
    break;

  case 85:
#line 466 "parse.y" /* yacc.c:1646  */
    {Trace("string");(yyval.ival) = 3;}
#line 2294 "y.tab.c" /* yacc.c:1646  */
    break;

  case 86:
#line 467 "parse.y" /* yacc.c:1646  */
    {Trace("array"); (yyval.ival) = 4;}
#line 2300 "y.tab.c" /* yacc.c:1646  */
    break;

  case 87:
#line 470 "parse.y" /* yacc.c:1646  */
    { (yyval.tval) = tmpConInt((yyvsp[0].ival));}
#line 2306 "y.tab.c" /* yacc.c:1646  */
    break;

  case 88:
#line 471 "parse.y" /* yacc.c:1646  */
    { (yyval.tval) = tmpConReal((yyvsp[0].dval));}
#line 2312 "y.tab.c" /* yacc.c:1646  */
    break;

  case 89:
#line 472 "parse.y" /* yacc.c:1646  */
    { (yyval.tval) = tmpConBool((yyvsp[0].bval));}
#line 2318 "y.tab.c" /* yacc.c:1646  */
    break;

  case 90:
#line 473 "parse.y" /* yacc.c:1646  */
    { (yyval.tval) = tmpConStr((yyvsp[0].cval));}
#line 2324 "y.tab.c" /* yacc.c:1646  */
    break;


#line 2328 "y.tab.c" /* yacc.c:1646  */
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
#line 475 "parse.y" /* yacc.c:1906  */


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
