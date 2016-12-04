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
#line 2 "parse.y" /* yacc.c:339  */

  #define YYDEBUG 1
  #include "ast.h"
  #include <functional>
  #include <iostream>
  #include <fstream>
  #include <math.h>
  #include <vector>
  #include <memory>
  #include <cstring>
  #include "except.h"
  #include "parse.tab.h"
	int yylex (void);
	extern int yylineno;
	extern char *yytext;
	void yyerror (char const *);
    // exception list
    std::vector<const char*> except_list;
    std::ofstream ast_out;
    int num_calclist = 0;

#line 88 "parse.tab.c" /* yacc.c:339  */

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
   by #include "parse.tab.h".  */
#ifndef YY_YY_PARSE_TAB_H_INCLUDED
# define YY_YY_PARSE_TAB_H_INCLUDED
/* Debug traces.  */
#ifndef YYDEBUG
# define YYDEBUG 1
#endif
#if YYDEBUG
extern int yydebug;
#endif

/* Token type.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
  enum yytokentype
  {
    AMPEREQUAL = 258,
    AMPERSAND = 259,
    AND = 260,
    AS = 261,
    ASSERT = 262,
    AT = 263,
    BACKQUOTE = 264,
    BAR = 265,
    BREAK = 266,
    CIRCUMFLEX = 267,
    CIRCUMFLEXEQUAL = 268,
    CLASS = 269,
    COLON = 270,
    COMMA = 271,
    CONTINUE = 272,
    DEDENT = 273,
    DEF = 274,
    DEL = 275,
    DOT = 276,
    DOUBLESLASH = 277,
    DOUBLESLASHEQUAL = 278,
    DOUBLESTAR = 279,
    DOUBLESTAREQUAL = 280,
    ELIF = 281,
    ELSE = 282,
    ENDMARKER = 283,
    EQEQUAL = 284,
    EQUAL = 285,
    EXCEPT = 286,
    EXEC = 287,
    FINALLY = 288,
    FOR = 289,
    FROM = 290,
    GLOBAL = 291,
    GREATER = 292,
    GREATEREQUAL = 293,
    GRLT = 294,
    IF = 295,
    IMPORT = 296,
    IN = 297,
    INDENT = 298,
    IS = 299,
    LAMBDA = 300,
    LBRACE = 301,
    LEFTSHIFT = 302,
    LEFTSHIFTEQUAL = 303,
    LESS = 304,
    LESSEQUAL = 305,
    LPAR = 306,
    LSQB = 307,
    MINEQUAL = 308,
    MINUS = 309,
    NAME = 310,
    NEWLINE = 311,
    NOT = 312,
    NOTEQUAL = 313,
    NUMBER = 314,
    OR = 315,
    PASS = 316,
    PERCENT = 317,
    PERCENTEQUAL = 318,
    PLUS = 319,
    PLUSEQUAL = 320,
    PRINT = 321,
    RAISE = 322,
    RBRACE = 323,
    RETURN = 324,
    RIGHTSHIFT = 325,
    RIGHTSHIFTEQUAL = 326,
    RPAR = 327,
    RSQB = 328,
    SEMI = 329,
    SLASH = 330,
    SLASHEQUAL = 331,
    STAR = 332,
    STAREQUAL = 333,
    STRING = 334,
    TILDE = 335,
    TRY = 336,
    VBAREQUAL = 337,
    WHILE = 338,
    WITH = 339,
    YIELD = 340
  };
#endif

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED

union YYSTYPE
{
#line 24 "parse.y" /* yacc.c:355  */

  //std::string* str;
  Ast* ast;
  //behavior
  Ast* (*b) (Ast*, Ast*);
  //unary behavior
  Ast* (*ub) (Ast*);
  //assign behavior
  Ast* (*ab) (AstName*, Ast*);

#line 225 "parse.tab.c" /* yacc.c:355  */
};

typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_PARSE_TAB_H_INCLUDED  */

/* Copy the second part of user declarations.  */

#line 242 "parse.tab.c" /* yacc.c:358  */

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
#define YYFINAL  138
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   928

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  86
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  139
/* YYNRULES -- Number of rules.  */
#define YYNRULES  320
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  486

/* YYTRANSLATE[YYX] -- Symbol number corresponding to YYX as returned
   by yylex, with out-of-bounds checking.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   340

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
      85
};

#if YYDEBUG
  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,    63,    63,    64,    76,    79,    80,   109,   110,   113,
     114,   117,   118,   121,   122,   125,   126,   129,   135,   136,
     139,   140,   143,   144,   147,   148,   151,   152,   155,   156,
     159,   160,   163,   166,   167,   170,   173,   174,   175,   176,
     177,   178,   179,   180,   181,   184,   185,   198,   199,   202,
     203,   206,   213,   220,   227,   234,   241,   242,   243,   244,
     245,   246,   254,   263,   267,   270,   271,   274,   275,   278,
     281,   284,   285,   286,   287,   288,   291,   294,   297,   301,
     304,   307,   308,   311,   312,   315,   316,   319,   320,   323,
     326,   327,   330,   331,   334,   335,   338,   339,   340,   343,
     344,   347,   348,   351,   354,   355,   358,   359,   362,   367,
     374,   375,   378,   379,   382,   383,   384,   385,   386,   387,
     388,   389,   392,   393,   396,   397,   400,   401,   404,   405,
     408,   409,   412,   413,   416,   417,   420,   421,   424,   427,
     428,   431,   432,   435,   436,   439,   440,   443,   444,   448,
     449,   455,   460,   466,   467,   470,   471,   474,   475,   484,
     485,   488,   489,   492,   493,   496,   497,   500,   501,   504,
     505,   508,   509,   510,   511,   512,   513,   514,   515,   516,
     517,   518,   522,   523,   526,   527,   530,   531,   534,   535,
     538,   539,   542,   544,   550,   563,   581,   583,   588,   605,
     613,   629,   639,   640,   644,   653,   662,   672,   673,   676,
     677,   680,   681,   682,   683,   684,   685,   686,   690,   691,
     694,   695,   698,   699,   702,   703,   706,   707,   710,   711,
     714,   715,   718,   719,   722,   723,   724,   727,   730,   731,
     732,   735,   736,   739,   740,   743,   744,   747,   751,   754,
     755,   758,   759,   762,   763,   766,   767,   770,   771,   774,
     775,   776,   777,   778,   779,   782,   783,   786,   787,   790,
     791,   794,   795,   798,   799,   802,   803,   807,   808,   811,
     812,   815,   816,   819,   823,   824,   827,   828,   829,   832,
     833,   834,   837,   838,   839,   842,   843,   844,   847,   848,
     849,   852,   853,   854,   858,   859,   860,   863,   864,   865,
     868,   869,   870,   873,   876,   879,   880,   881,   884,   885,
     886
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || 0
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "AMPEREQUAL", "AMPERSAND", "AND", "AS",
  "ASSERT", "AT", "BACKQUOTE", "BAR", "BREAK", "CIRCUMFLEX",
  "CIRCUMFLEXEQUAL", "CLASS", "COLON", "COMMA", "CONTINUE", "DEDENT",
  "DEF", "DEL", "DOT", "DOUBLESLASH", "DOUBLESLASHEQUAL", "DOUBLESTAR",
  "DOUBLESTAREQUAL", "ELIF", "ELSE", "ENDMARKER", "EQEQUAL", "EQUAL",
  "EXCEPT", "EXEC", "FINALLY", "FOR", "FROM", "GLOBAL", "GREATER",
  "GREATEREQUAL", "GRLT", "IF", "IMPORT", "IN", "INDENT", "IS", "LAMBDA",
  "LBRACE", "LEFTSHIFT", "LEFTSHIFTEQUAL", "LESS", "LESSEQUAL", "LPAR",
  "LSQB", "MINEQUAL", "MINUS", "NAME", "NEWLINE", "NOT", "NOTEQUAL",
  "NUMBER", "OR", "PASS", "PERCENT", "PERCENTEQUAL", "PLUS", "PLUSEQUAL",
  "PRINT", "RAISE", "RBRACE", "RETURN", "RIGHTSHIFT", "RIGHTSHIFTEQUAL",
  "RPAR", "RSQB", "SEMI", "SLASH", "SLASHEQUAL", "STAR", "STAREQUAL",
  "STRING", "TILDE", "TRY", "VBAREQUAL", "WHILE", "WITH", "YIELD",
  "$accept", "start", "file_input", "pick_NEWLINE_stmt",
  "star_NEWLINE_stmt", "decorator", "opt_arglist", "decorators",
  "decorated", "funcdef", "parameters", "varargslist", "opt_EQUAL_test",
  "star_fpdef_COMMA", "opt_DOUBLESTAR_NAME", "pick_STAR_DOUBLESTAR",
  "fpdef", "fplist", "stmt", "simple_stmt", "small_stmt", "expr_stmt",
  "pick_yield_expr_testlist", "star_EQUAL", "augassign", "print_stmt",
  "opt_test", "opt_test_2", "del_stmt", "pass_stmt", "flow_stmt",
  "break_stmt", "continue_stmt", "return_stmt", "yield_stmt", "raise_stmt",
  "opt_COMMA_test", "opt_test_3", "import_stmt", "import_name",
  "import_from", "star_DOT", "plus_DOT", "pick_STAR_import",
  "import_as_name", "dotted_as_name", "import_as_names", "dotted_as_names",
  "dotted_name", "global_stmt", "exec_stmt", "assert_stmt",
  "compound_stmt", "if_stmt", "star_ELIF", "while_stmt", "for_stmt",
  "try_stmt", "plus_except", "opt_ELSE", "opt_FINALLY", "with_stmt",
  "star_COMMA_with_item", "with_item", "except_clause", "pick_AS_COMMA",
  "opt_AS_COMMA", "suite", "plus_stmt", "testlist_safe", "old_test",
  "old_lambdef", "test", "opt_IF_ELSE", "or_test", "and_test", "not_test",
  "comparison", "comp_op", "expr", "xor_expr", "and_expr", "shift_expr",
  "pick_LEFTSHIFT_RIGHTSHIFT", "arith_expr", "pick_PLUS_MINUS", "term",
  "pick_multop", "factor", "pick_unop", "power", "star_trailer", "atom",
  "pick_yield_expr_testlist_comp", "opt_yield_test", "opt_listmaker",
  "opt_dictorsetmaker", "plus_STRING", "listmaker", "testlist_comp",
  "lambdef", "trailer", "subscriptlist", "subscript", "opt_test_only",
  "opt_sliceop", "sliceop", "exprlist", "testlist", "dictorsetmaker",
  "pick_comp_for", "pick_for_test", "classdef", "opt_testlist", "arglist",
  "argument", "opt_comp_for", "list_iter", "list_for", "list_if",
  "comp_iter", "comp_for", "comp_if", "testlist1", "encoding_decl",
  "yield_expr", "star_fpdef_notest", "star_COMMA_expr", "star_COMMA_fpdef",
  "star_COMMA_test", "star_test_COLON_test", "star_COMMA_subscript",
  "star_COMMA_import_as_name", "plus_COMMA_test", "plus_COMMA_old_test",
  "dictarg", "listarg", "arglist_postlist", "small_stmt_STAR_OR_SEMI", YY_NULLPTR
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
     335,   336,   337,   338,   339,   340
};
# endif

#define YYPACT_NINF -360

#define yypact_value_is_default(Yystate) \
  (!!((Yystate) == (-360)))

#define YYTABLE_NINF -303

#define yytable_value_is_error(Yytable_value) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
     398,   831,     5,   831,  -360,    43,  -360,    62,   344,   344,
     344,    41,    63,   831,     5,    22,   831,   200,   831,  -360,
      48,  -360,    93,  -360,  -360,  -360,   724,   831,   831,    53,
    -360,    54,   831,   831,   831,   140,  -360,   477,   114,   145,
     137,  -360,  -360,  -360,  -360,    88,  -360,  -360,  -360,  -360,
    -360,  -360,  -360,  -360,  -360,  -360,  -360,  -360,  -360,   148,
    -360,  -360,  -360,  -360,  -360,  -360,  -360,  -360,   150,     6,
     162,  -360,   239,   159,   158,   167,    14,     4,    18,  -360,
     344,  -360,    68,  -360,  -360,    51,  -360,  -360,  -360,  -360,
     160,  -360,    36,  -360,    47,    24,   123,   120,  -360,    55,
     133,    29,     5,   136,  -360,   166,  -360,   168,    38,   831,
     103,  -360,   171,    11,   152,    94,   119,  -360,    87,  -360,
     121,  -360,  -360,    91,   117,  -360,  -360,   831,  -360,   150,
     175,  -360,  -360,   635,   179,   181,   193,  -360,  -360,  -360,
    -360,  -360,  -360,  -360,   686,   149,   146,   831,  -360,    93,
      93,  -360,    93,  -360,  -360,  -360,  -360,  -360,   147,  -360,
    -360,   164,  -360,   344,   344,   344,   344,  -360,  -360,   344,
    -360,  -360,   344,  -360,  -360,  -360,  -360,   344,  -360,   156,
     309,   763,   189,    68,  -360,  -360,  -360,  -360,   200,  -360,
    -360,  -360,  -360,  -360,  -360,  -360,  -360,  -360,   200,   831,
     163,   309,  -360,  -360,   831,   635,   831,     0,   202,   344,
    -360,   831,   831,  -360,  -360,    64,    -6,   635,     5,   165,
    -360,   203,   153,   831,   169,   172,  -360,   831,   205,   831,
     344,  -360,  -360,  -360,  -360,  -360,  -360,  -360,   344,  -360,
    -360,  -360,   214,  -360,   831,  -360,   190,  -360,   130,   635,
     831,   217,   344,    88,  -360,  -360,   150,    26,   162,  -360,
    -360,  -360,   159,   158,   167,    14,     4,    18,  -360,  -360,
     831,   831,   170,   125,  -360,   221,  -360,   223,   219,   226,
     180,   228,   241,   344,  -360,   230,  -360,  -360,  -360,  -360,
    -360,   191,  -360,  -360,  -360,   195,  -360,   201,   635,   120,
     245,   247,    -6,   210,   268,  -360,  -360,   259,  -360,   256,
    -360,  -360,   103,  -360,  -360,  -360,  -360,   270,  -360,    28,
    -360,    97,   242,   248,   831,  -360,  -360,   245,   556,   831,
     272,   264,   277,   266,   181,   635,   159,  -360,  -360,   831,
    -360,  -360,  -360,   831,  -360,  -360,   309,   801,   273,  -360,
     605,  -360,   831,  -360,  -360,   243,   280,  -360,  -360,  -360,
     831,  -360,   635,  -360,   229,   249,   210,  -360,   831,   271,
     203,   276,  -360,  -360,   152,   831,  -360,  -360,  -360,    93,
     848,   286,  -360,   556,   285,   118,   635,   291,   274,   635,
     293,  -360,  -360,  -360,  -360,  -360,   294,  -360,  -360,  -360,
     228,  -360,   297,  -360,   635,  -360,   287,  -360,  -360,   259,
     298,   301,  -360,   262,   205,   304,     7,    27,   101,   305,
    -360,   260,   831,  -360,  -360,  -360,  -360,  -360,   831,  -360,
    -360,   635,   307,  -360,   295,   635,   801,  -360,   831,  -360,
    -360,  -360,   310,  -360,   635,   635,  -360,  -360,   831,   848,
    -360,  -360,  -360,   848,   312,   848,  -360,  -360,  -360,   848,
    -360,  -360,  -360,   635,  -360,  -360,  -360,  -360,   635,   256,
    -360,   308,   109,  -360,   848,   101,   315,  -360,  -360,  -360,
    -360,  -360,  -360,  -360,   848,  -360
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_uint16 yydefact[] =
{
       8,     0,     0,     0,    76,     0,    77,     0,     0,     0,
       0,    93,     0,     0,     0,    25,   225,   221,   223,   205,
     215,     5,     0,   216,    70,   204,    66,    82,    79,   227,
     206,     0,     0,     0,   285,     0,     2,     8,     0,    14,
       0,   121,   119,     6,    33,   320,    36,    37,    38,    39,
      40,    71,    72,    73,    75,    74,    41,    87,    88,    42,
      43,    44,    34,   114,   115,   116,   117,   118,   297,   162,
     163,   165,   168,   169,   182,   184,   186,   188,   192,   196,
       0,   203,   210,   217,   160,    50,   120,     3,    80,   215,
     113,   106,     0,   281,     0,     0,     0,   291,    69,   111,
       0,    93,     0,     0,   109,     0,   104,    89,   102,     0,
       0,    30,     0,     0,    23,   297,     0,   224,   297,   220,
       0,   219,   218,   297,     0,   222,   167,     0,    63,   297,
      86,    78,   226,     0,     0,   140,   142,   284,     1,     7,
       4,    13,    16,    15,   319,     0,     0,   296,   248,     0,
       0,   159,     0,   173,   172,   174,   176,   178,   180,   171,
     175,     0,   177,     0,     0,     0,     0,   190,   191,     0,
     195,   194,     0,   201,   200,   199,   198,     0,   202,     0,
      12,   242,   208,   210,    56,    58,    62,    61,     0,    59,
      52,    55,    51,    60,    54,    53,    57,    46,     0,     0,
       0,    12,    10,   214,     0,     0,   258,    25,     0,   290,
     247,     0,     0,    92,    94,     0,     0,     0,     0,     0,
     233,   288,     0,     0,     0,     0,    20,     0,   294,     0,
       0,   250,   253,   254,   213,   230,   231,   211,     0,   228,
     229,   212,    68,    65,     0,    81,     0,   149,     0,     0,
       0,     0,     0,   320,    35,   108,   297,     0,   164,   166,
     181,   179,   170,   183,   185,   187,   189,   193,   197,   236,
       0,     0,     0,   268,    11,   261,   264,   263,     0,   239,
       0,   303,     0,     0,   209,    50,    48,    47,    45,   112,
     107,     0,   282,   256,   257,     0,    19,     0,     0,   291,
      84,     0,     0,     0,   100,    96,    91,   306,    98,   125,
     105,   101,   287,    32,    31,   232,    29,    27,    22,    25,
      21,   300,     0,     0,     0,    64,    67,    84,     0,   144,
       0,   135,     0,   127,   140,     0,   141,   318,   295,     0,
     313,   314,   234,     0,   265,   267,   260,     0,     0,   235,
     242,   237,   242,   207,    49,     0,     0,    18,    17,   289,
       0,   110,     0,    90,     0,     0,   305,   103,     0,   123,
     288,     0,    28,    24,    23,   299,   249,   251,   252,     0,
       0,   309,    85,   152,     0,   148,     0,     0,   137,     0,
       0,   139,   138,   161,   266,   259,   317,   316,   262,   238,
     303,   241,   244,     9,     0,    83,   129,    97,    99,   306,
       0,     0,   286,     0,   294,     0,   278,    25,   272,   154,
     156,   155,   308,   307,   151,   150,   145,   146,     0,   143,
     131,     0,     0,   130,   133,     0,     0,   301,   246,   240,
     243,   255,     0,   304,     0,     0,    26,   292,     0,     0,
     277,   275,   276,     0,     0,     0,   271,   269,   270,     0,
     153,   147,   134,     0,   132,   126,   315,   245,     0,   125,
     122,   300,   280,   158,     0,   274,   312,   136,   128,   124,
     298,   279,   157,   273,   311,   310
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -360,  -360,  -360,  -360,   299,  -360,   131,   296,  -360,   303,
    -360,  -203,   -40,    25,  -360,  -360,  -104,  -360,  -292,     1,
     197,  -360,   139,    65,  -360,  -360,  -360,  -360,  -360,  -360,
    -360,  -360,  -360,  -360,  -360,  -360,    12,  -360,  -360,  -360,
    -360,   246,   251,    46,    -9,   138,    59,  -360,     9,  -360,
    -360,  -360,  -360,  -360,  -111,  -360,  -360,  -360,   -69,  -360,
    -360,  -360,    35,   122,  -360,  -360,  -360,  -197,   -13,  -360,
    -359,  -360,    -1,  -360,  -144,   225,   -15,  -360,  -360,    20,
     207,   211,   212,  -360,   208,  -360,   209,  -360,   -71,  -360,
    -360,   196,  -360,  -360,  -360,  -360,  -360,   351,  -360,  -360,
    -360,  -360,  -360,    32,    31,  -360,  -360,    -7,   -10,  -360,
    -360,  -360,   345,  -360,    45,  -324,  -360,   -88,   269,  -360,
     -79,  -105,  -360,  -360,  -360,    -3,    30,    95,   -17,   -96,
     -70,     2,    -5,    33,   -66,  -313,  -360,   -25,   173
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,    35,    36,    37,    38,    39,   272,    40,    41,    42,
     208,   112,   228,   113,   372,   226,   114,   222,    43,   247,
      45,    46,   285,   197,   198,    47,   128,   325,    48,    49,
      50,    51,    52,    53,    54,    55,   361,   245,    56,    57,
      58,   102,   103,   306,   307,   106,   308,   107,   108,    59,
      60,    61,    62,    63,   369,    64,    65,    66,   331,   388,
     433,    67,   251,   135,   332,   428,   429,   248,   384,   418,
     476,   420,    68,   151,    69,    70,    71,    72,   163,    73,
      74,    75,    76,   169,    77,   172,    78,   177,    79,    80,
      81,   182,    82,   119,   120,   124,   116,    83,   125,   121,
      84,   183,   280,   281,   282,   439,   440,    98,    85,   117,
     376,   231,    86,   295,   274,   275,   344,   456,   457,   458,
     450,   451,   452,    94,    87,    88,   313,   210,   320,   148,
     378,   351,   367,   326,   460,   276,   277,   398,   145
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
      90,    44,    93,   100,   297,   257,   221,   126,   293,   178,
     232,    92,   105,   235,   122,   115,   118,   123,   131,   233,
     309,   419,   236,   396,   137,   129,   130,   240,    97,    99,
      97,   134,   136,   243,   397,   224,   383,   109,    44,   205,
     173,   230,   453,  -293,   219,   303,   149,   449,  -283,   304,
     101,   110,   333,   339,   184,   111,   203,   200,   170,   200,
      91,   167,   101,   204,   185,   164,   150,   150,   171,   133,
     -95,   305,   296,   110,   186,   206,   187,   111,   110,   110,
     174,   188,   111,   111,   168,   200,   150,   201,   225,   179,
     472,   383,   202,   175,   473,   176,   475,   211,    95,   189,
    -293,   358,     3,   147,   190,   302,   268,   147,   220,   229,
     147,   215,   396,   375,   191,   482,   192,    96,   104,   180,
     181,   230,   193,   397,   426,   238,   242,   194,   230,   195,
     164,   230,    29,   196,   427,   238,   209,   259,   392,    16,
     138,   455,   140,   230,    17,    18,   256,    19,    89,   449,
      22,     5,    23,     2,   110,   343,     7,    25,   111,   230,
     338,   329,   144,   330,   146,   406,   147,   152,   345,   164,
     165,   166,    29,    30,   207,   212,   199,   216,   286,   273,
     279,   217,   227,   262,   218,   287,   223,   234,   286,   430,
     241,   244,   434,   237,   249,   287,   294,   250,   289,   252,
     273,   255,   301,   292,   260,   254,   261,   441,   370,     3,
     300,   269,   353,   283,   454,   374,   377,   298,   290,   312,
     311,   319,   315,   322,   316,   314,   318,   317,   321,   299,
     324,   323,   335,   328,   462,   416,   421,   346,   465,   347,
     348,  -241,   342,   327,   350,    15,    16,   469,   470,   136,
      97,    17,    18,   349,    19,    89,   352,    22,    97,    23,
     188,   360,   362,   355,    25,   304,   477,   356,   153,   340,
     341,   478,   336,   357,   365,   366,   154,   155,   156,    29,
      30,   157,   368,   158,   379,    34,   371,   386,   159,   160,
     380,   387,   389,   390,   399,   404,   161,   162,   411,   403,
     413,   407,   422,   425,   408,   421,   431,   432,   435,   421,
     436,   421,   438,   444,   442,   421,   445,   446,     3,   448,
     150,   459,   463,   381,   375,   468,   329,   474,   385,    44,
     421,   484,   291,   270,   414,   141,   139,   288,   393,   382,
     421,   253,   394,   142,   373,   273,   273,   213,   363,   279,
     354,   401,   214,     3,    15,    16,   310,   409,   479,   405,
      17,    18,   364,    19,    89,   464,    22,   410,    23,   391,
     424,   263,   334,    25,   415,   258,   264,   266,   265,   284,
     132,   267,   400,   402,    44,   143,   271,   483,    29,    30,
      16,   395,   239,   481,   359,    17,    18,   447,    19,    89,
     412,   480,   437,    23,   443,     1,     2,     3,    25,     4,
     485,   466,     5,     0,   423,     6,     0,     7,     8,     0,
       0,   381,     0,    29,    30,     0,   337,   461,     0,     0,
       9,     0,    10,    11,    12,   273,     0,   467,    13,    14,
       0,     0,     0,    15,    16,     0,     0,   471,     0,    17,
      18,     0,    19,    20,    21,    22,     0,    23,     0,    24,
       0,     0,    25,     0,    26,    27,     0,    28,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    29,    30,    31,
       0,    32,    33,    34,     1,     2,     3,     0,     4,     0,
       0,     5,     0,     0,     6,     0,     7,     8,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     9,
       0,    10,    11,    12,     0,     0,     0,    13,    14,     0,
       0,     0,    15,    16,     0,     0,     0,     0,    17,    18,
       0,    19,    89,    21,    22,     0,    23,     0,    24,     0,
       0,    25,     0,    26,    27,     0,    28,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    29,    30,    31,     0,
      32,    33,    34,     1,     2,     3,     0,     4,     0,     0,
       5,     0,     0,     6,     0,     7,     8,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     9,     0,
      10,    11,    12,     0,     0,     0,    13,    14,     0,     0,
       0,    15,    16,     0,     0,     0,     0,    17,    18,     0,
      19,    89,     0,    22,     3,    23,     0,    24,     0,     0,
      25,     0,    26,    27,     0,    28,   278,     0,     0,     0,
       0,     0,     0,     0,     0,    29,    30,    31,     0,    32,
      33,    34,     1,     0,     3,     0,     4,     0,     0,     0,
      15,    16,     6,     0,     0,     8,    17,    18,     0,    19,
      89,     0,    22,     0,    23,     0,     0,     9,     0,    25,
      11,    12,     0,     0,     0,     0,    14,     0,  -302,     0,
      15,    16,     0,     0,    29,    30,    17,    18,     0,    19,
      89,   246,    22,     1,    23,     3,    24,     4,     0,    25,
       0,    26,    27,     6,    28,     0,     8,     0,     0,     0,
       0,     0,     0,     0,    29,    30,     0,     0,     9,     0,
      34,    11,    12,     0,     0,     0,     0,    14,     0,     0,
       0,    15,    16,     3,     0,     0,     0,    17,    18,     0,
      19,    89,     0,    22,     0,    23,     0,    24,     0,     0,
      25,     0,    26,    27,     0,    28,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    29,    30,     0,     0,    15,
      16,    34,     3,     0,     0,    17,    18,     0,    19,    89,
       0,    22,     0,    23,   278,     0,     0,     0,    25,     0,
       0,     0,     0,     0,   127,     0,     0,     0,     0,     0,
       0,     0,     0,    29,    30,     0,     0,     0,    15,    16,
       3,     0,     0,     0,    17,    18,     0,    19,    89,     0,
      22,     0,    23,     0,     0,   270,     0,    25,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       3,     0,    29,    30,     0,     0,    15,    16,     0,     0,
       0,     0,    17,    18,     0,    19,    89,     3,    22,     0,
      23,     0,     0,     0,     0,    25,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    15,    16,     0,     0,
      29,    30,    17,    18,     0,    19,    89,     0,    22,     0,
      23,     0,     0,   417,    16,    25,     0,     0,     0,    17,
      18,     0,    19,    89,     0,    22,     0,    23,     0,     0,
      29,    30,    25,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    29,    30
};

static const yytype_int16 yycheck[] =
{
       1,     0,     3,    10,   207,   149,   110,    22,   205,    80,
     115,     2,    13,   118,    17,    16,    17,    18,    28,   115,
     217,   380,   118,   347,    34,    26,    27,   123,     8,     9,
      10,    32,    33,   129,   347,    24,   328,    15,    37,    15,
      22,    34,    15,    15,     6,    51,    40,    40,     0,    55,
      21,    51,   249,    27,     3,    55,     9,    21,    54,    21,
      55,    47,    21,    16,    13,    10,    60,    60,    64,    15,
      41,    77,    72,    51,    23,    51,    25,    55,    51,    51,
      62,    30,    55,    55,    70,    21,    60,    51,    77,    21,
     449,   383,    56,    75,   453,    77,   455,    42,    55,    48,
      72,   298,     9,    16,    53,    41,   177,    16,   109,    15,
      16,   102,   436,    16,    63,   474,    65,    55,    55,    51,
      52,    34,    71,   436,     6,    34,   127,    76,    34,    78,
      10,    34,    79,    82,    16,    34,    16,   152,   335,    46,
       0,    40,    28,    34,    51,    52,   147,    54,    55,    40,
      57,    14,    59,     8,    51,    30,    19,    64,    55,    34,
     256,    31,    74,    33,    16,   362,    16,     5,   273,    10,
      12,     4,    79,    80,    51,    42,    16,    41,   188,   180,
     181,    15,    30,   163,    16,   188,    15,    68,   198,   386,
      73,    16,   389,    72,    15,   198,   206,    16,   199,     6,
     201,    55,   212,   204,    57,    56,    42,   404,   312,     9,
     211,    55,   283,    24,   417,   319,   321,    15,    55,    16,
      55,    16,   223,   230,    55,    72,   227,    55,   229,   209,
      16,   238,    15,    43,   431,   379,   380,    16,   435,    16,
      21,    15,    72,   244,    16,    45,    46,   444,   445,   250,
     230,    51,    52,    73,    54,    55,    15,    57,   238,    59,
      30,    16,    15,    72,    64,    55,   463,    72,    29,   270,
     271,   468,   252,    72,     6,    16,    37,    38,    39,    79,
      80,    42,    26,    44,    42,    85,    16,    15,    49,    50,
      42,    27,    15,    27,    21,    15,    57,    58,    27,    56,
      24,    72,    16,    18,    55,   449,    15,    33,    15,   453,
      16,   455,    15,    15,    27,   459,    15,    55,     9,    15,
      60,    16,    15,   324,    16,    15,    31,    15,   329,   328,
     474,    16,   201,    24,   374,    39,    37,   198,   339,   327,
     484,   144,   343,    40,   319,   346,   347,   101,   302,   350,
     285,   352,   101,     9,    45,    46,   218,   366,   469,   360,
      51,    52,   303,    54,    55,   434,    57,   368,    59,   334,
     383,   164,   250,    64,   375,   150,   165,   169,   166,   183,
      29,   172,   350,   352,   383,    40,    77,   475,    79,    80,
      46,   346,   123,   472,   299,    51,    52,   414,    54,    55,
     370,   471,   400,    59,   409,     7,     8,     9,    64,    11,
     476,   436,    14,    -1,   381,    17,    -1,    19,    20,    -1,
      -1,   422,    -1,    79,    80,    -1,   253,   428,    -1,    -1,
      32,    -1,    34,    35,    36,   436,    -1,   438,    40,    41,
      -1,    -1,    -1,    45,    46,    -1,    -1,   448,    -1,    51,
      52,    -1,    54,    55,    56,    57,    -1,    59,    -1,    61,
      -1,    -1,    64,    -1,    66,    67,    -1,    69,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    79,    80,    81,
      -1,    83,    84,    85,     7,     8,     9,    -1,    11,    -1,
      -1,    14,    -1,    -1,    17,    -1,    19,    20,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    32,
      -1,    34,    35,    36,    -1,    -1,    -1,    40,    41,    -1,
      -1,    -1,    45,    46,    -1,    -1,    -1,    -1,    51,    52,
      -1,    54,    55,    56,    57,    -1,    59,    -1,    61,    -1,
      -1,    64,    -1,    66,    67,    -1,    69,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    79,    80,    81,    -1,
      83,    84,    85,     7,     8,     9,    -1,    11,    -1,    -1,
      14,    -1,    -1,    17,    -1,    19,    20,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    32,    -1,
      34,    35,    36,    -1,    -1,    -1,    40,    41,    -1,    -1,
      -1,    45,    46,    -1,    -1,    -1,    -1,    51,    52,    -1,
      54,    55,    -1,    57,     9,    59,    -1,    61,    -1,    -1,
      64,    -1,    66,    67,    -1,    69,    21,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    79,    80,    81,    -1,    83,
      84,    85,     7,    -1,     9,    -1,    11,    -1,    -1,    -1,
      45,    46,    17,    -1,    -1,    20,    51,    52,    -1,    54,
      55,    -1,    57,    -1,    59,    -1,    -1,    32,    -1,    64,
      35,    36,    -1,    -1,    -1,    -1,    41,    -1,    73,    -1,
      45,    46,    -1,    -1,    79,    80,    51,    52,    -1,    54,
      55,    56,    57,     7,    59,     9,    61,    11,    -1,    64,
      -1,    66,    67,    17,    69,    -1,    20,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    79,    80,    -1,    -1,    32,    -1,
      85,    35,    36,    -1,    -1,    -1,    -1,    41,    -1,    -1,
      -1,    45,    46,     9,    -1,    -1,    -1,    51,    52,    -1,
      54,    55,    -1,    57,    -1,    59,    -1,    61,    -1,    -1,
      64,    -1,    66,    67,    -1,    69,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    79,    80,    -1,    -1,    45,
      46,    85,     9,    -1,    -1,    51,    52,    -1,    54,    55,
      -1,    57,    -1,    59,    21,    -1,    -1,    -1,    64,    -1,
      -1,    -1,    -1,    -1,    70,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    79,    80,    -1,    -1,    -1,    45,    46,
       9,    -1,    -1,    -1,    51,    52,    -1,    54,    55,    -1,
      57,    -1,    59,    -1,    -1,    24,    -1,    64,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
       9,    -1,    79,    80,    -1,    -1,    45,    46,    -1,    -1,
      -1,    -1,    51,    52,    -1,    54,    55,     9,    57,    -1,
      59,    -1,    -1,    -1,    -1,    64,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    45,    46,    -1,    -1,
      79,    80,    51,    52,    -1,    54,    55,    -1,    57,    -1,
      59,    -1,    -1,    45,    46,    64,    -1,    -1,    -1,    51,
      52,    -1,    54,    55,    -1,    57,    -1,    59,    -1,    -1,
      79,    80,    64,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    79,    80
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,     7,     8,     9,    11,    14,    17,    19,    20,    32,
      34,    35,    36,    40,    41,    45,    46,    51,    52,    54,
      55,    56,    57,    59,    61,    64,    66,    67,    69,    79,
      80,    81,    83,    84,    85,    87,    88,    89,    90,    91,
      93,    94,    95,   104,   105,   106,   107,   111,   114,   115,
     116,   117,   118,   119,   120,   121,   124,   125,   126,   135,
     136,   137,   138,   139,   141,   142,   143,   147,   158,   160,
     161,   162,   163,   165,   166,   167,   168,   170,   172,   174,
     175,   176,   178,   183,   186,   194,   198,   210,   211,    55,
     158,    55,   134,   158,   209,    55,    55,   165,   193,   165,
     193,    21,   127,   128,    55,   158,   131,   133,   134,    15,
      51,    55,    97,    99,   102,   158,   182,   195,   158,   179,
     180,   185,   211,   158,   181,   184,   162,    70,   112,   158,
     158,   194,   183,    15,   158,   149,   158,   194,     0,    90,
      28,    93,    95,   198,    74,   224,    16,    16,   215,    40,
      60,   159,     5,    29,    37,    38,    39,    42,    44,    49,
      50,    57,    58,   164,    10,    12,     4,    47,    70,   169,
      54,    64,   171,    22,    62,    75,    77,   173,   174,    21,
      51,    52,   177,   187,     3,    13,    23,    25,    30,    48,
      53,    63,    65,    71,    76,    78,    82,   109,   110,    16,
      21,    51,    56,     9,    16,    15,    51,    51,    96,    16,
     213,    42,    42,   127,   128,   134,    41,    15,    16,     6,
     158,   102,   103,    15,    24,    77,   101,    30,    98,    15,
      34,   197,   207,   215,    68,   207,   215,    72,    34,   204,
     215,    73,   158,   215,    16,   123,    56,   105,   153,    15,
      16,   148,     6,   106,    56,    55,   158,   160,   161,   162,
      57,    42,   165,   166,   167,   168,   170,   172,   174,    55,
      24,    77,    92,   158,   200,   201,   221,   222,    21,   158,
     188,   189,   190,    24,   177,   108,   194,   211,   108,   158,
      55,    92,   158,   153,   194,   199,    72,    97,    15,   165,
     158,   194,    41,    51,    55,    77,   129,   130,   132,   153,
     131,    55,    16,   212,    72,   158,    55,    55,   158,    16,
     214,   158,   193,   193,    16,   113,   219,   158,    43,    31,
      33,   144,   150,   153,   149,    15,   165,   224,   215,    27,
     158,   158,    72,    30,   202,   207,    16,    16,    21,    73,
      16,   217,    15,   174,   109,    72,    72,    72,   153,   213,
      16,   122,    15,   129,   132,     6,    16,   218,    26,   140,
     102,    16,   100,    99,   102,    16,   196,   207,   216,    42,
      42,   158,   122,   104,   154,   158,    15,    27,   145,    15,
      27,   148,   153,   158,   158,   200,   201,   221,   223,    21,
     189,   158,   190,    56,    15,   158,   153,    72,    55,   130,
     158,    27,   212,    24,    98,   158,   160,    45,   155,   156,
     157,   160,    16,   219,   154,    18,     6,    16,   151,   152,
     153,    15,    33,   146,   153,    15,    16,   217,    15,   191,
     192,   153,    27,   218,    15,    15,    55,   214,    15,    40,
     206,   207,   208,    15,    97,    40,   203,   204,   205,    16,
     220,   158,   153,    15,   144,   153,   223,   158,    15,   153,
     153,   158,   156,   156,    15,   156,   156,   153,   153,   140,
     216,   206,   156,   203,    16,   220
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    86,    87,    87,    88,    89,    89,    90,    90,    91,
      91,    92,    92,    93,    93,    94,    94,    95,    96,    96,
      97,    97,    98,    98,    99,    99,   100,   100,   101,   101,
     102,   102,   103,   104,   104,   105,   106,   106,   106,   106,
     106,   106,   106,   106,   106,   107,   107,   108,   108,   109,
     109,   110,   110,   110,   110,   110,   110,   110,   110,   110,
     110,   110,   110,   111,   111,   112,   112,   113,   113,   114,
     115,   116,   116,   116,   116,   116,   117,   118,   119,   119,
     120,   121,   121,   122,   122,   123,   123,   124,   124,   125,
     126,   126,   127,   127,   128,   128,   129,   129,   129,   130,
     130,   131,   131,   132,   133,   133,   134,   134,   135,   135,
     136,   136,   137,   137,   138,   138,   138,   138,   138,   138,
     138,   138,   139,   139,   140,   140,   141,   141,   142,   142,
     143,   143,   144,   144,   145,   145,   146,   146,   147,   148,
     148,   149,   149,   150,   150,   151,   151,   152,   152,   153,
     153,   154,   154,   155,   155,   156,   156,   157,   157,   158,
     158,   159,   159,   160,   160,   161,   161,   162,   162,   163,
     163,   164,   164,   164,   164,   164,   164,   164,   164,   164,
     164,   164,   165,   165,   166,   166,   167,   167,   168,   168,
     169,   169,   170,   170,   171,   171,   172,   172,   173,   173,
     173,   173,   174,   174,   175,   175,   175,   176,   176,   177,
     177,   178,   178,   178,   178,   178,   178,   178,   179,   179,
     180,   180,   181,   181,   182,   182,   183,   183,   184,   184,
     185,   185,   186,   186,   187,   187,   187,   188,   189,   189,
     189,   190,   190,   191,   191,   192,   192,   193,   194,   195,
     195,   196,   196,   197,   197,   198,   198,   199,   199,   200,
     200,   200,   200,   200,   200,   201,   201,   202,   202,   203,
     203,   204,   204,   205,   205,   206,   206,   207,   207,   208,
     208,   209,   209,   210,   211,   211,   212,   212,   212,   213,
     213,   213,   214,   214,   214,   215,   215,   215,   216,   216,
     216,   217,   217,   217,   218,   218,   218,   219,   219,   219,
     220,   220,   220,   221,   222,   223,   223,   223,   224,   224,
     224
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     1,     1,     2,     1,     1,     2,     0,     6,
       3,     1,     0,     2,     1,     2,     2,     5,     3,     2,
       2,     3,     2,     0,     4,     0,     3,     0,     3,     2,
       1,     3,     2,     1,     1,     3,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     3,     2,     1,     1,     3,
       0,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     2,     4,     2,     0,     1,     0,     2,
       1,     1,     1,     1,     1,     1,     1,     1,     2,     1,
       1,     3,     1,     2,     0,     3,     0,     1,     1,     2,
       5,     4,     2,     0,     2,     1,     1,     3,     1,     3,
       1,     3,     1,     2,     1,     3,     1,     3,     3,     2,
       5,     2,     4,     2,     1,     1,     1,     1,     1,     1,
       1,     1,     8,     5,     5,     0,     7,     4,     9,     6,
       6,     6,     4,     3,     3,     0,     3,     0,     5,     3,
       0,     3,     1,     3,     1,     1,     1,     2,     0,     1,
       4,     2,     1,     2,     1,     1,     1,     4,     3,     2,
       1,     4,     0,     1,     3,     1,     3,     2,     1,     1,
       3,     1,     1,     1,     1,     1,     1,     1,     1,     2,
       1,     2,     1,     3,     1,     3,     1,     3,     1,     3,
       1,     1,     1,     3,     1,     1,     1,     3,     1,     1,
       1,     1,     2,     1,     1,     1,     1,     4,     2,     2,
       0,     3,     3,     3,     3,     1,     1,     1,     1,     1,
       1,     0,     1,     0,     1,     0,     2,     1,     2,     2,
       2,     2,     4,     3,     3,     3,     2,     2,     3,     1,
       4,     1,     0,     1,     0,     2,     1,     2,     2,     4,
       2,     1,     1,     1,     1,     7,     4,     1,     0,     3,
       2,     1,     3,     1,     1,     2,     3,     1,     0,     1,
       1,     5,     4,     3,     2,     1,     1,     5,     4,     3,
       2,     1,     3,     1,     2,     1,     3,     1,     0,     3,
       1,     0,     4,     1,     0,     3,     1,     0,     5,     1,
       0,     3,     1,     0,     3,     1,     0,     3,     3,     2,
       3,     3,     2,     2,     2,     3,     1,     1,     3,     1,
       0
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
        case 6:
#line 81 "parse.y" /* yacc.c:1646  */
    {
        if ((yyvsp[0].ast))
        {
            try
            {
                ast_out << "digraph ast" << num_calclist++ << " {" << std::endl;
                AstVal* v = (yyvsp[0].ast)->eval();
                // $1 may be a func definition
                if (v && !v->isFunc())
                    delete v; 
                ast_out << "}" << std::endl;;
                delete (yyvsp[0].ast);
            }
            catch (std::exception& e)
            {
                except_list.push_back(e.what());
            }
        }
        // if there are exceptions, print the first and dump all
        if (!except_list.empty())
        {
            std::cout << except_list.front() << std::endl;
            except_list.clear();
        }
    }
#line 1840 "parse.tab.c" /* yacc.c:1646  */
    break;

  case 8:
#line 110 "parse.y" /* yacc.c:1646  */
    { (yyval.ast) = 0; }
#line 1846 "parse.tab.c" /* yacc.c:1646  */
    break;

  case 12:
#line 118 "parse.y" /* yacc.c:1646  */
    { (yyval.ast) = 0; }
#line 1852 "parse.tab.c" /* yacc.c:1646  */
    break;

  case 17:
#line 130 "parse.y" /* yacc.c:1646  */
    {
        (yyval.ast) = new AstFuncdef((AstName*)(yyvsp[-3].ast), (AstSuite*)(yyvsp[0].ast));
    }
#line 1860 "parse.tab.c" /* yacc.c:1646  */
    break;

  case 22:
#line 143 "parse.y" /* yacc.c:1646  */
    { }
#line 1866 "parse.tab.c" /* yacc.c:1646  */
    break;

  case 23:
#line 144 "parse.y" /* yacc.c:1646  */
    { (yyval.ast) = 0; }
#line 1872 "parse.tab.c" /* yacc.c:1646  */
    break;

  case 25:
#line 148 "parse.y" /* yacc.c:1646  */
    { (yyval.ast) = 0; }
#line 1878 "parse.tab.c" /* yacc.c:1646  */
    break;

  case 27:
#line 152 "parse.y" /* yacc.c:1646  */
    { (yyval.ast) = 0; }
#line 1884 "parse.tab.c" /* yacc.c:1646  */
    break;

  case 36:
#line 173 "parse.y" /* yacc.c:1646  */
    { (yyval.ast) = (yyvsp[0].ast); }
#line 1890 "parse.tab.c" /* yacc.c:1646  */
    break;

  case 37:
#line 174 "parse.y" /* yacc.c:1646  */
    { (yyval.ast) = (yyvsp[0].ast); }
#line 1896 "parse.tab.c" /* yacc.c:1646  */
    break;

  case 38:
#line 175 "parse.y" /* yacc.c:1646  */
    { (yyval.ast) = 0; }
#line 1902 "parse.tab.c" /* yacc.c:1646  */
    break;

  case 39:
#line 176 "parse.y" /* yacc.c:1646  */
    { (yyval.ast) = 0; }
#line 1908 "parse.tab.c" /* yacc.c:1646  */
    break;

  case 40:
#line 177 "parse.y" /* yacc.c:1646  */
    { (yyval.ast) = (yyvsp[0].ast); }
#line 1914 "parse.tab.c" /* yacc.c:1646  */
    break;

  case 41:
#line 178 "parse.y" /* yacc.c:1646  */
    { (yyval.ast) = 0; }
#line 1920 "parse.tab.c" /* yacc.c:1646  */
    break;

  case 42:
#line 179 "parse.y" /* yacc.c:1646  */
    { (yyval.ast) = (yyvsp[0].ast); }
#line 1926 "parse.tab.c" /* yacc.c:1646  */
    break;

  case 43:
#line 180 "parse.y" /* yacc.c:1646  */
    { (yyval.ast) = 0; }
#line 1932 "parse.tab.c" /* yacc.c:1646  */
    break;

  case 44:
#line 181 "parse.y" /* yacc.c:1646  */
    { (yyval.ast) = 0; }
#line 1938 "parse.tab.c" /* yacc.c:1646  */
    break;

  case 45:
#line 184 "parse.y" /* yacc.c:1646  */
    { (yyval.ast) = (yyvsp[-1].ab)((AstName*)(yyvsp[-2].ast), (yyvsp[0].ast)); }
#line 1944 "parse.tab.c" /* yacc.c:1646  */
    break;

  case 46:
#line 186 "parse.y" /* yacc.c:1646  */
    {
        if ((yyvsp[-1].ast) && (yyvsp[0].ast))
        {
            (yyval.ast) = new AstEqual((AstName*)(yyvsp[-1].ast), (yyvsp[0].ast));
        }
        else
        {
            (yyval.ast) = (yyvsp[-1].ast);
        }
    }
#line 1959 "parse.tab.c" /* yacc.c:1646  */
    break;

  case 47:
#line 198 "parse.y" /* yacc.c:1646  */
    { }
#line 1965 "parse.tab.c" /* yacc.c:1646  */
    break;

  case 48:
#line 199 "parse.y" /* yacc.c:1646  */
    { }
#line 1971 "parse.tab.c" /* yacc.c:1646  */
    break;

  case 49:
#line 202 "parse.y" /* yacc.c:1646  */
    { (yyval.ast) = (yyvsp[-1].ast); }
#line 1977 "parse.tab.c" /* yacc.c:1646  */
    break;

  case 50:
#line 203 "parse.y" /* yacc.c:1646  */
    { (yyval.ast) = 0; }
#line 1983 "parse.tab.c" /* yacc.c:1646  */
    break;

  case 51:
#line 207 "parse.y" /* yacc.c:1646  */
    { (yyval.ab) = [](AstName* x, Ast* y) 
        {
            Ast* temp = x && y ? new AstPlusEqual(x, y) : 0;
            return temp;
        }; 
    }
#line 1994 "parse.tab.c" /* yacc.c:1646  */
    break;

  case 52:
#line 214 "parse.y" /* yacc.c:1646  */
    { (yyval.ab) = [](AstName* x, Ast* y) 
        {
            Ast* temp = x && y ? new AstMinusEqual(x, y) : 0;
            return temp;
        }; 
    }
#line 2005 "parse.tab.c" /* yacc.c:1646  */
    break;

  case 53:
#line 221 "parse.y" /* yacc.c:1646  */
    { (yyval.ab) = [](AstName* x, Ast* y) 
        {
            Ast* temp = x && y ? new AstStarEqual(x, y) : 0;
            return temp;
        }; 
    }
#line 2016 "parse.tab.c" /* yacc.c:1646  */
    break;

  case 54:
#line 228 "parse.y" /* yacc.c:1646  */
    { (yyval.ab) = [](AstName* x, Ast* y) 
        {
            Ast* temp = x && y ? new AstDivEqual(x, y) : 0;
            return temp;
        }; 
    }
#line 2027 "parse.tab.c" /* yacc.c:1646  */
    break;

  case 55:
#line 235 "parse.y" /* yacc.c:1646  */
    { (yyval.ab) = [](AstName* x, Ast* y) 
        {
            Ast* temp = x && y ? new AstModEqual(x, y) : 0;
            return temp;
        }; 
    }
#line 2038 "parse.tab.c" /* yacc.c:1646  */
    break;

  case 56:
#line 241 "parse.y" /* yacc.c:1646  */
    { (yyval.ab) = [](AstName* x, Ast* y) { return (Ast*)NULL; }; }
#line 2044 "parse.tab.c" /* yacc.c:1646  */
    break;

  case 57:
#line 242 "parse.y" /* yacc.c:1646  */
    { (yyval.ab) = [](AstName* x, Ast* y) { return (Ast*)NULL; }; }
#line 2050 "parse.tab.c" /* yacc.c:1646  */
    break;

  case 58:
#line 243 "parse.y" /* yacc.c:1646  */
    { (yyval.ab) = [](AstName* x, Ast* y) { return (Ast*)NULL; }; }
#line 2056 "parse.tab.c" /* yacc.c:1646  */
    break;

  case 59:
#line 244 "parse.y" /* yacc.c:1646  */
    { (yyval.ab) = [](AstName* x, Ast* y) { return (Ast*)NULL; }; }
#line 2062 "parse.tab.c" /* yacc.c:1646  */
    break;

  case 60:
#line 245 "parse.y" /* yacc.c:1646  */
    { (yyval.ab) = [](AstName* x, Ast* y) { return (Ast*)NULL; }; }
#line 2068 "parse.tab.c" /* yacc.c:1646  */
    break;

  case 61:
#line 247 "parse.y" /* yacc.c:1646  */
    { (yyval.ab) = [](AstName* x, Ast* y) 
        {
            Ast* temp = x && y ? new AstExpEqual(x, y) : 0;
            return temp;
        }; 
    }
#line 2079 "parse.tab.c" /* yacc.c:1646  */
    break;

  case 62:
#line 255 "parse.y" /* yacc.c:1646  */
    { (yyval.ab) = [](AstName* x, Ast* y) 
        {
            Ast* temp = x && y ? new AstIntDivEqual(x, y) : 0;
            return temp;
        }; 
    }
#line 2090 "parse.tab.c" /* yacc.c:1646  */
    break;

  case 63:
#line 264 "parse.y" /* yacc.c:1646  */
    {
        (yyval.ast) = new AstPrint((yyvsp[0].ast));
    }
#line 2098 "parse.tab.c" /* yacc.c:1646  */
    break;

  case 65:
#line 270 "parse.y" /* yacc.c:1646  */
    { (yyval.ast) = (yyvsp[-1].ast); }
#line 2104 "parse.tab.c" /* yacc.c:1646  */
    break;

  case 66:
#line 271 "parse.y" /* yacc.c:1646  */
    { (yyval.ast) = 0; }
#line 2110 "parse.tab.c" /* yacc.c:1646  */
    break;

  case 68:
#line 275 "parse.y" /* yacc.c:1646  */
    { (yyval.ast) = 0; }
#line 2116 "parse.tab.c" /* yacc.c:1646  */
    break;

  case 73:
#line 286 "parse.y" /* yacc.c:1646  */
    { (yyval.ast) = (yyvsp[0].ast); }
#line 2122 "parse.tab.c" /* yacc.c:1646  */
    break;

  case 78:
#line 298 "parse.y" /* yacc.c:1646  */
    {
       (yyval.ast) = new AstReturn((yyvsp[0].ast));
    }
#line 2130 "parse.tab.c" /* yacc.c:1646  */
    break;

  case 84:
#line 312 "parse.y" /* yacc.c:1646  */
    { (yyval.ast) = 0; }
#line 2136 "parse.tab.c" /* yacc.c:1646  */
    break;

  case 86:
#line 316 "parse.y" /* yacc.c:1646  */
    { (yyval.ast) = 0; }
#line 2142 "parse.tab.c" /* yacc.c:1646  */
    break;

  case 93:
#line 331 "parse.y" /* yacc.c:1646  */
    { (yyval.ast) = 0; }
#line 2148 "parse.tab.c" /* yacc.c:1646  */
    break;

  case 108:
#line 363 "parse.y" /* yacc.c:1646  */
    {
        ((AstName*)(yyvsp[-2].ast))->makeGlobal();
        (yyval.ast) = (yyvsp[-2].ast);
    }
#line 2157 "parse.tab.c" /* yacc.c:1646  */
    break;

  case 109:
#line 368 "parse.y" /* yacc.c:1646  */
    {
        ((AstName*)(yyvsp[0].ast))->makeGlobal();
        (yyval.ast) = (yyvsp[0].ast);
    }
#line 2166 "parse.tab.c" /* yacc.c:1646  */
    break;

  case 114:
#line 382 "parse.y" /* yacc.c:1646  */
    { (yyval.ast) = 0; }
#line 2172 "parse.tab.c" /* yacc.c:1646  */
    break;

  case 115:
#line 383 "parse.y" /* yacc.c:1646  */
    { (yyval.ast) = 0; }
#line 2178 "parse.tab.c" /* yacc.c:1646  */
    break;

  case 116:
#line 384 "parse.y" /* yacc.c:1646  */
    { (yyval.ast) = 0; }
#line 2184 "parse.tab.c" /* yacc.c:1646  */
    break;

  case 117:
#line 385 "parse.y" /* yacc.c:1646  */
    { (yyval.ast) = 0; }
#line 2190 "parse.tab.c" /* yacc.c:1646  */
    break;

  case 118:
#line 386 "parse.y" /* yacc.c:1646  */
    { (yyval.ast) = 0; }
#line 2196 "parse.tab.c" /* yacc.c:1646  */
    break;

  case 119:
#line 387 "parse.y" /* yacc.c:1646  */
    { (yyval.ast) = (yyvsp[0].ast); }
#line 2202 "parse.tab.c" /* yacc.c:1646  */
    break;

  case 120:
#line 388 "parse.y" /* yacc.c:1646  */
    { (yyval.ast) = 0; }
#line 2208 "parse.tab.c" /* yacc.c:1646  */
    break;

  case 121:
#line 389 "parse.y" /* yacc.c:1646  */
    { (yyval.ast) = 0; }
#line 2214 "parse.tab.c" /* yacc.c:1646  */
    break;

  case 125:
#line 397 "parse.y" /* yacc.c:1646  */
    { (yyval.ast) = 0; }
#line 2220 "parse.tab.c" /* yacc.c:1646  */
    break;

  case 135:
#line 417 "parse.y" /* yacc.c:1646  */
    { (yyval.ast) = 0; }
#line 2226 "parse.tab.c" /* yacc.c:1646  */
    break;

  case 137:
#line 421 "parse.y" /* yacc.c:1646  */
    { (yyval.ast) = 0; }
#line 2232 "parse.tab.c" /* yacc.c:1646  */
    break;

  case 140:
#line 428 "parse.y" /* yacc.c:1646  */
    { (yyval.ast) = 0; }
#line 2238 "parse.tab.c" /* yacc.c:1646  */
    break;

  case 148:
#line 444 "parse.y" /* yacc.c:1646  */
    { (yyval.ast) = 0; }
#line 2244 "parse.tab.c" /* yacc.c:1646  */
    break;

  case 150:
#line 450 "parse.y" /* yacc.c:1646  */
    {
        (yyval.ast) = (yyvsp[-1].ast);
    }
#line 2252 "parse.tab.c" /* yacc.c:1646  */
    break;

  case 151:
#line 456 "parse.y" /* yacc.c:1646  */
    {

        (yyval.ast) = new AstSuite((yyvsp[-1].ast), (AstSuite*)(yyvsp[0].ast));
    }
#line 2261 "parse.tab.c" /* yacc.c:1646  */
    break;

  case 152:
#line 461 "parse.y" /* yacc.c:1646  */
    {
        (yyval.ast) = new AstSuite((yyvsp[0].ast));
    }
#line 2269 "parse.tab.c" /* yacc.c:1646  */
    break;

  case 160:
#line 485 "parse.y" /* yacc.c:1646  */
    { (yyval.ast) = 0; }
#line 2275 "parse.tab.c" /* yacc.c:1646  */
    break;

  case 162:
#line 489 "parse.y" /* yacc.c:1646  */
    { (yyval.ast) = 0; }
#line 2281 "parse.tab.c" /* yacc.c:1646  */
    break;

  case 168:
#line 501 "parse.y" /* yacc.c:1646  */
    { (yyval.ast) = (yyvsp[0].ast); }
#line 2287 "parse.tab.c" /* yacc.c:1646  */
    break;

  case 169:
#line 504 "parse.y" /* yacc.c:1646  */
    { (yyval.ast) = (yyvsp[0].ast); }
#line 2293 "parse.tab.c" /* yacc.c:1646  */
    break;

  case 170:
#line 505 "parse.y" /* yacc.c:1646  */
    { (yyval.ast) = 0; }
#line 2299 "parse.tab.c" /* yacc.c:1646  */
    break;

  case 182:
#line 522 "parse.y" /* yacc.c:1646  */
    {  (yyval.ast) = (yyvsp[0].ast); }
#line 2305 "parse.tab.c" /* yacc.c:1646  */
    break;

  case 184:
#line 526 "parse.y" /* yacc.c:1646  */
    { (yyval.ast) = (yyvsp[0].ast); }
#line 2311 "parse.tab.c" /* yacc.c:1646  */
    break;

  case 186:
#line 530 "parse.y" /* yacc.c:1646  */
    { (yyval.ast) = (yyvsp[0].ast); }
#line 2317 "parse.tab.c" /* yacc.c:1646  */
    break;

  case 188:
#line 534 "parse.y" /* yacc.c:1646  */
    { (yyval.ast) = (yyvsp[0].ast); }
#line 2323 "parse.tab.c" /* yacc.c:1646  */
    break;

  case 189:
#line 535 "parse.y" /* yacc.c:1646  */
    { (yyval.ast) = 0; }
#line 2329 "parse.tab.c" /* yacc.c:1646  */
    break;

  case 192:
#line 543 "parse.y" /* yacc.c:1646  */
    { (yyval.ast) = (yyvsp[0].ast); }
#line 2335 "parse.tab.c" /* yacc.c:1646  */
    break;

  case 193:
#line 546 "parse.y" /* yacc.c:1646  */
    { (yyval.ast) = (yyvsp[-1].b)((yyvsp[-2].ast), (yyvsp[0].ast)); }
#line 2341 "parse.tab.c" /* yacc.c:1646  */
    break;

  case 194:
#line 551 "parse.y" /* yacc.c:1646  */
    { 
        (yyval.b) = [](Ast* x, Ast* y) 
        { 
            Ast* temp; 
            if (x && y)
                temp = new AstPlus(x, y);
            else
                temp = 0;
            return temp; 
        }; 
    }
#line 2357 "parse.tab.c" /* yacc.c:1646  */
    break;

  case 195:
#line 564 "parse.y" /* yacc.c:1646  */
    { 
        (yyval.b) = [](Ast* x, Ast* y) 
        {   
            Ast* temp;
            if (x && y)
            {
                temp = new AstMinus(x, y);
            }
            else
            {
                temp = 0;
            }
            return temp;
        }; 
    }
#line 2377 "parse.tab.c" /* yacc.c:1646  */
    break;

  case 196:
#line 582 "parse.y" /* yacc.c:1646  */
    { (yyval.ast) = (yyvsp[0].ast); }
#line 2383 "parse.tab.c" /* yacc.c:1646  */
    break;

  case 197:
#line 584 "parse.y" /* yacc.c:1646  */
    { (yyval.ast) = (yyvsp[-1].b)((yyvsp[-2].ast), (yyvsp[0].ast)); }
#line 2389 "parse.tab.c" /* yacc.c:1646  */
    break;

  case 198:
#line 589 "parse.y" /* yacc.c:1646  */
    { 
        (yyval.b) = [](Ast* x, Ast* y) 
        { 
            Ast* temp;
            if (x && y)
            {
                temp  = new AstMult(x, y); 
            }
            else
            {
                temp = 0;
            }
            return temp;
        }; 
    }
#line 2409 "parse.tab.c" /* yacc.c:1646  */
    break;

  case 199:
#line 606 "parse.y" /* yacc.c:1646  */
    { (yyval.b) = [](Ast* x, Ast* y) 
        { 
            Ast* temp = new AstDiv(x, y); 
            return temp;
        }; 
    }
#line 2420 "parse.tab.c" /* yacc.c:1646  */
    break;

  case 200:
#line 614 "parse.y" /* yacc.c:1646  */
    { 
        (yyval.b) = [](Ast* x, Ast* y) 
        {
            Ast* temp;
            if (x && y)
            {
                temp = new AstMod(x, y); 
            }
            else
            {
                temp = 0;
            }
            return temp;
        }; 
    }
#line 2440 "parse.tab.c" /* yacc.c:1646  */
    break;

  case 201:
#line 630 "parse.y" /* yacc.c:1646  */
    { 
        (yyval.b) = [](Ast* x, Ast* y) 
        { 
            Ast* temp = new AstIntDiv(x, y); 
            return temp;
        }; 
    }
#line 2452 "parse.tab.c" /* yacc.c:1646  */
    break;

  case 202:
#line 639 "parse.y" /* yacc.c:1646  */
    { (yyval.ast) = (yyvsp[-1].ub)((yyvsp[0].ast)); }
#line 2458 "parse.tab.c" /* yacc.c:1646  */
    break;

  case 203:
#line 640 "parse.y" /* yacc.c:1646  */
    { (yyval.ast) = (yyvsp[0].ast); }
#line 2464 "parse.tab.c" /* yacc.c:1646  */
    break;

  case 204:
#line 645 "parse.y" /* yacc.c:1646  */
    {
         (yyval.ub) = [](Ast* x) 
         { 
            Ast* temp = x ? new AstUPlus(x) : 0;
            return temp;
         };
     }
#line 2476 "parse.tab.c" /* yacc.c:1646  */
    break;

  case 205:
#line 654 "parse.y" /* yacc.c:1646  */
    {
         (yyval.ub) = [](Ast* x) 
         { 
             Ast* temp = x ? new AstUMin(x) : 0;
             return temp;
         }; 
    }
#line 2488 "parse.tab.c" /* yacc.c:1646  */
    break;

  case 206:
#line 663 "parse.y" /* yacc.c:1646  */
    { 
        (yyval.ub) = [](Ast* x) 
        { 
            Ast* temp = x ? new AstUNot(x) : 0;
            return temp;
        };
    }
#line 2500 "parse.tab.c" /* yacc.c:1646  */
    break;

  case 207:
#line 672 "parse.y" /* yacc.c:1646  */
    { (yyval.ast) = (yyvsp[-3].ast) && (yyvsp[0].ast) ? new AstExp((yyvsp[-3].ast), (yyvsp[0].ast)) : 0; }
#line 2506 "parse.tab.c" /* yacc.c:1646  */
    break;

  case 208:
#line 673 "parse.y" /* yacc.c:1646  */
    { (yyval.ast) = (yyvsp[-1].ast); }
#line 2512 "parse.tab.c" /* yacc.c:1646  */
    break;

  case 209:
#line 676 "parse.y" /* yacc.c:1646  */
    { (yyval.ast) = 0; }
#line 2518 "parse.tab.c" /* yacc.c:1646  */
    break;

  case 210:
#line 677 "parse.y" /* yacc.c:1646  */
    { (yyval.ast) = 0; }
#line 2524 "parse.tab.c" /* yacc.c:1646  */
    break;

  case 211:
#line 680 "parse.y" /* yacc.c:1646  */
    { (yyval.ast) = (yyvsp[-1].ast); }
#line 2530 "parse.tab.c" /* yacc.c:1646  */
    break;

  case 212:
#line 681 "parse.y" /* yacc.c:1646  */
    { (yyval.ast) = 0; }
#line 2536 "parse.tab.c" /* yacc.c:1646  */
    break;

  case 213:
#line 682 "parse.y" /* yacc.c:1646  */
    { (yyval.ast) = 0; }
#line 2542 "parse.tab.c" /* yacc.c:1646  */
    break;

  case 214:
#line 683 "parse.y" /* yacc.c:1646  */
    { (yyval.ast) = 0; }
#line 2548 "parse.tab.c" /* yacc.c:1646  */
    break;

  case 215:
#line 684 "parse.y" /* yacc.c:1646  */
    { (yyval.ast) = (yyvsp[0].ast); }
#line 2554 "parse.tab.c" /* yacc.c:1646  */
    break;

  case 216:
#line 685 "parse.y" /* yacc.c:1646  */
    { (yyval.ast) = (yyvsp[0].ast); }
#line 2560 "parse.tab.c" /* yacc.c:1646  */
    break;

  case 217:
#line 686 "parse.y" /* yacc.c:1646  */
    { (yyval.ast) = 0; }
#line 2566 "parse.tab.c" /* yacc.c:1646  */
    break;

  case 218:
#line 690 "parse.y" /* yacc.c:1646  */
    { (yyval.ast) = (yyvsp[0].ast); }
#line 2572 "parse.tab.c" /* yacc.c:1646  */
    break;

  case 219:
#line 691 "parse.y" /* yacc.c:1646  */
    { (yyval.ast) = (yyvsp[0].ast); }
#line 2578 "parse.tab.c" /* yacc.c:1646  */
    break;

  case 220:
#line 694 "parse.y" /* yacc.c:1646  */
    { (yyval.ast) = (yyvsp[0].ast); }
#line 2584 "parse.tab.c" /* yacc.c:1646  */
    break;

  case 221:
#line 695 "parse.y" /* yacc.c:1646  */
    { (yyval.ast) = 0; }
#line 2590 "parse.tab.c" /* yacc.c:1646  */
    break;

  case 223:
#line 699 "parse.y" /* yacc.c:1646  */
    { (yyval.ast) = 0; }
#line 2596 "parse.tab.c" /* yacc.c:1646  */
    break;

  case 225:
#line 703 "parse.y" /* yacc.c:1646  */
    { (yyval.ast) = 0; }
#line 2602 "parse.tab.c" /* yacc.c:1646  */
    break;

  case 226:
#line 706 "parse.y" /* yacc.c:1646  */
    { (yyval.ast) = (yyvsp[0].ast); }
#line 2608 "parse.tab.c" /* yacc.c:1646  */
    break;

  case 242:
#line 736 "parse.y" /* yacc.c:1646  */
    { (yyval.ast) = 0; }
#line 2614 "parse.tab.c" /* yacc.c:1646  */
    break;

  case 244:
#line 740 "parse.y" /* yacc.c:1646  */
    { (yyval.ast) = 0; }
#line 2620 "parse.tab.c" /* yacc.c:1646  */
    break;

  case 248:
#line 751 "parse.y" /* yacc.c:1646  */
    { (yyval.ast) = (yyvsp[-1].ast); }
#line 2626 "parse.tab.c" /* yacc.c:1646  */
    break;

  case 258:
#line 771 "parse.y" /* yacc.c:1646  */
    { (yyval.ast) = 0; }
#line 2632 "parse.tab.c" /* yacc.c:1646  */
    break;

  case 268:
#line 787 "parse.y" /* yacc.c:1646  */
    { (yyval.ast) = 0; }
#line 2638 "parse.tab.c" /* yacc.c:1646  */
    break;

  case 284:
#line 823 "parse.y" /* yacc.c:1646  */
    { (yyval.ast) = (yyvsp[0].ast); }
#line 2644 "parse.tab.c" /* yacc.c:1646  */
    break;

  case 288:
#line 829 "parse.y" /* yacc.c:1646  */
    { (yyval.ast) = 0; }
#line 2650 "parse.tab.c" /* yacc.c:1646  */
    break;

  case 291:
#line 834 "parse.y" /* yacc.c:1646  */
    { (yyval.ast) = 0; }
#line 2656 "parse.tab.c" /* yacc.c:1646  */
    break;

  case 294:
#line 839 "parse.y" /* yacc.c:1646  */
    { (yyval.ast) = 0; }
#line 2662 "parse.tab.c" /* yacc.c:1646  */
    break;

  case 297:
#line 844 "parse.y" /* yacc.c:1646  */
    { (yyval.ast) = 0; }
#line 2668 "parse.tab.c" /* yacc.c:1646  */
    break;

  case 300:
#line 849 "parse.y" /* yacc.c:1646  */
    { (yyval.ast) = 0; }
#line 2674 "parse.tab.c" /* yacc.c:1646  */
    break;

  case 303:
#line 854 "parse.y" /* yacc.c:1646  */
    { (yyval.ast) = 0; }
#line 2680 "parse.tab.c" /* yacc.c:1646  */
    break;

  case 306:
#line 860 "parse.y" /* yacc.c:1646  */
    { (yyval.ast) = 0; }
#line 2686 "parse.tab.c" /* yacc.c:1646  */
    break;

  case 320:
#line 886 "parse.y" /* yacc.c:1646  */
    { (yyval.ast) = 0; }
#line 2692 "parse.tab.c" /* yacc.c:1646  */
    break;


#line 2696 "parse.tab.c" /* yacc.c:1646  */
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
#line 889 "parse.y" /* yacc.c:1906  */


#include <stdio.h>
void yyerror (char const *s) {
	fprintf (stderr, "%d: %s with [%s]\n", yylineno, s, yytext);
}

