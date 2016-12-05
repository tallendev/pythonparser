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
    void go(Ast* a)
    {
        if (a)
        {
            try
            {
                ast_out << "digraph ast" << num_calclist++ << " {" << std::endl;
                AstVal* v = a->eval();
                // $1 may be a func definition
                if (v && !v->isFunc())
                    delete v; 
                ast_out << "}" << std::endl;;
                delete a;
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

#line 114 "parse.tab.c" /* yacc.c:339  */

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
#line 51 "parse.y" /* yacc.c:355  */

  Ast* ast;
  //behavior
  Ast* (*b) (Ast*, Ast*);
  //unary behavior
  Ast* (*ub) (Ast*);
  //assign behavior
  Ast* (*ab) (AstName*, Ast*);

#line 250 "parse.tab.c" /* yacc.c:355  */
};

typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_PARSE_TAB_H_INCLUDED  */

/* Copy the second part of user declarations.  */

#line 267 "parse.tab.c" /* yacc.c:358  */

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
#define YYFINAL  140
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   869

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  86
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  141
/* YYNRULES -- Number of rules.  */
#define YYNRULES  324
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  490

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
       0,    89,    89,    90,    91,   100,   101,   104,   107,   108,
     112,   113,   116,   117,   120,   121,   124,   125,   128,   129,
     132,   138,   139,   142,   143,   146,   147,   150,   151,   154,
     155,   158,   159,   162,   163,   166,   170,   174,   175,   178,
     181,   182,   183,   184,   185,   186,   187,   188,   189,   192,
     193,   206,   207,   210,   211,   214,   221,   228,   235,   242,
     249,   250,   251,   252,   253,   254,   262,   271,   275,   278,
     279,   282,   283,   286,   289,   292,   293,   294,   295,   296,
     299,   302,   305,   309,   312,   315,   316,   319,   320,   323,
     324,   327,   328,   331,   334,   335,   338,   339,   342,   343,
     346,   347,   348,   351,   352,   355,   356,   359,   362,   363,
     366,   367,   370,   375,   382,   383,   386,   387,   390,   391,
     392,   393,   394,   395,   396,   397,   400,   401,   404,   405,
     408,   409,   412,   413,   416,   417,   420,   421,   424,   425,
     428,   429,   432,   435,   436,   439,   440,   443,   444,   447,
     448,   451,   452,   456,   457,   463,   468,   474,   475,   478,
     479,   482,   483,   492,   493,   496,   497,   500,   501,   504,
     505,   508,   509,   512,   513,   516,   517,   518,   519,   520,
     521,   522,   523,   524,   525,   526,   530,   531,   534,   535,
     538,   539,   542,   543,   546,   547,   550,   552,   558,   571,
     589,   591,   596,   613,   621,   637,   647,   648,   652,   661,
     670,   680,   681,   684,   685,   688,   689,   690,   691,   692,
     693,   694,   698,   699,   702,   703,   706,   707,   710,   711,
     714,   715,   718,   719,   722,   723,   726,   727,   730,   732,
     733,   736,   739,   740,   741,   744,   745,   748,   749,   752,
     753,   756,   760,   763,   764,   767,   768,   771,   772,   775,
     776,   779,   780,   783,   784,   785,   786,   787,   788,   791,
     792,   795,   796,   799,   800,   803,   804,   807,   808,   811,
     812,   816,   817,   820,   821,   824,   825,   828,   832,   833,
     836,   837,   838,   841,   842,   843,   846,   847,   848,   851,
     852,   853,   856,   857,   858,   861,   862,   863,   867,   868,
     869,   872,   873,   874,   877,   878,   879,   882,   885,   888,
     889,   890,   893,   894,   895
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
  "$accept", "start", "single_input", "file_input", "pick_NEWLINE_stmt",
  "star_NEWLINE_stmt", "decorator", "opt_arglist", "decorators",
  "decorated", "funcdef", "parameters", "varargslist", "opt_EQUAL_test",
  "star_fpdef_COMMA", "opt_DOUBLESTAR_NAME", "pick_STAR_DOUBLESTAR",
  "fpdef", "fplist", "stmt_stmt", "stmt", "simple_stmt", "small_stmt",
  "expr_stmt", "pick_yield_expr_testlist", "star_EQUAL", "augassign",
  "print_stmt", "opt_test", "opt_test_2", "del_stmt", "pass_stmt",
  "flow_stmt", "break_stmt", "continue_stmt", "return_stmt", "yield_stmt",
  "raise_stmt", "opt_COMMA_test", "opt_test_3", "import_stmt",
  "import_name", "import_from", "star_DOT", "plus_DOT", "pick_STAR_import",
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

#define YYPACT_NINF -363

#define yypact_value_is_default(Yystate) \
  (!!((Yystate) == (-363)))

#define YYTABLE_NINF -307

#define yytable_value_is_error(Yytable_value) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
     402,   758,     2,   758,  -363,    39,  -363,    76,   789,   789,
     789,    33,   118,   758,     2,    14,   758,    29,   758,  -363,
     174,   178,   348,  -363,  -363,  -363,    89,   758,   758,   101,
    -363,   164,   758,   758,   758,   181,  -363,  -363,   481,   154,
     179,   156,  -363,  -363,   186,  -363,  -363,   115,  -363,  -363,
    -363,  -363,  -363,  -363,  -363,  -363,  -363,  -363,  -363,  -363,
    -363,   175,  -363,  -363,  -363,  -363,  -363,  -363,  -363,  -363,
     176,     3,   189,  -363,   221,   187,   184,   195,    -3,    -9,
      15,  -363,   789,  -363,   100,  -363,  -363,    48,  -363,  -363,
    -363,  -363,   185,  -363,    82,  -363,    43,    19,   149,   144,
    -363,    30,   161,    66,     2,   169,  -363,   190,  -363,   197,
     151,   758,   110,  -363,   200,    22,   188,   121,   152,  -363,
      26,  -363,   150,  -363,  -363,    32,   148,  -363,  -363,   758,
    -363,   176,   208,  -363,  -363,   639,   210,   211,   223,  -363,
    -363,  -363,  -363,  -363,  -363,  -363,  -363,  -363,   690,   182,
     191,   758,  -363,   348,   348,  -363,   348,  -363,  -363,  -363,
    -363,  -363,   180,  -363,  -363,   199,  -363,   789,   789,   789,
     789,  -363,  -363,   789,  -363,  -363,   789,  -363,  -363,  -363,
    -363,   789,  -363,   196,   231,   609,   207,   100,  -363,  -363,
    -363,  -363,    29,  -363,  -363,  -363,  -363,  -363,  -363,  -363,
    -363,  -363,    29,   758,   201,   231,  -363,  -363,   758,   639,
     758,     7,   227,   789,  -363,   758,   758,  -363,  -363,   104,
      72,   639,     2,   202,  -363,   229,   171,   758,   206,   209,
    -363,   758,   238,   758,   789,  -363,  -363,  -363,  -363,  -363,
    -363,  -363,   789,  -363,  -363,  -363,   246,  -363,   758,  -363,
     225,  -363,    87,   639,   758,   254,   789,   115,  -363,  -363,
     176,     8,   189,  -363,  -363,  -363,   187,   184,   195,    -3,
      -9,    15,  -363,  -363,   758,   758,   203,   133,  -363,   264,
    -363,   265,   263,   272,   216,   275,   277,   789,  -363,   266,
    -363,  -363,  -363,  -363,  -363,   222,  -363,  -363,  -363,   226,
    -363,   228,   639,   144,   281,   278,    72,   244,   295,  -363,
    -363,   286,  -363,   279,  -363,  -363,   110,  -363,  -363,  -363,
    -363,   288,  -363,    34,  -363,   113,   270,   273,   758,  -363,
    -363,   281,   560,   758,   291,   287,   301,   290,   211,   639,
     187,  -363,  -363,   758,  -363,  -363,  -363,   758,  -363,  -363,
     231,   728,   297,  -363,   313,  -363,   758,  -363,  -363,   267,
     304,  -363,  -363,  -363,   758,  -363,   639,  -363,   248,   269,
     244,  -363,   758,   294,   229,   302,  -363,  -363,   188,   758,
    -363,  -363,  -363,   348,   775,   309,  -363,   560,   311,   116,
     639,   315,   298,   639,   320,  -363,  -363,  -363,  -363,  -363,
     321,  -363,  -363,  -363,   275,  -363,   324,  -363,   639,  -363,
     314,  -363,  -363,   286,   325,   328,  -363,   289,   238,   330,
      16,    49,   122,   331,  -363,   276,   758,  -363,  -363,  -363,
    -363,  -363,   758,  -363,  -363,   639,   333,  -363,   323,   639,
     728,  -363,   758,  -363,  -363,  -363,   336,  -363,   639,   639,
    -363,  -363,   758,   775,  -363,  -363,  -363,   775,   337,   775,
    -363,  -363,  -363,   775,  -363,  -363,  -363,   639,  -363,  -363,
    -363,  -363,   639,   279,  -363,   340,   124,  -363,   775,   122,
     344,  -363,  -363,  -363,  -363,  -363,  -363,  -363,   775,  -363
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_uint16 yydefact[] =
{
      11,     0,     0,     0,    80,     0,    81,     0,     0,     0,
       0,    97,     0,     0,     0,    28,   229,   225,   227,   209,
     219,     8,     0,   220,    74,   208,    70,    86,    83,   231,
     210,     0,     0,     0,   289,     0,     4,     2,    11,     0,
      17,     0,   125,   123,     9,    36,    37,   324,    40,    41,
      42,    43,    44,    75,    76,    77,    79,    78,    45,    91,
      92,    46,    47,    48,    38,   118,   119,   120,   121,   122,
     301,   166,   167,   169,   172,   173,   186,   188,   190,   192,
     196,   200,     0,   207,   214,   221,   164,    54,   124,     3,
      84,   219,   117,   110,     0,   285,     0,     0,     0,   295,
      73,   115,     0,    97,     0,     0,   113,     0,   108,    93,
     106,     0,     0,    33,     0,     0,    26,   301,     0,   228,
     301,   224,     0,   223,   222,   301,     0,   226,   171,     0,
      67,   301,    90,    82,   230,     0,     0,   144,   146,   288,
       1,     8,    10,     9,     7,    16,    19,    18,   323,     0,
       0,   300,   252,     0,     0,   163,     0,   177,   176,   178,
     180,   182,   184,   175,   179,     0,   181,     0,     0,     0,
       0,   194,   195,     0,   199,   198,     0,   205,   204,   203,
     202,     0,   206,     0,    15,   246,   212,   214,    60,    62,
      66,    65,     0,    63,    56,    59,    55,    64,    58,    57,
      61,    50,     0,     0,     0,    15,    13,   218,     0,     0,
     262,    28,     0,   294,   251,     0,     0,    96,    98,     0,
       0,     0,     0,     0,   237,   292,     0,     0,     0,     0,
      23,     0,   298,     0,     0,   254,   257,   258,   217,   234,
     235,   215,     0,   232,   233,   216,    72,    69,     0,    85,
       0,   153,     0,     0,     0,     0,     0,   324,    39,   112,
     301,     0,   168,   170,   185,   183,   174,   187,   189,   191,
     193,   197,   201,   240,     0,     0,     0,   272,    14,   265,
     268,   267,     0,   243,     0,   307,     0,     0,   213,    54,
      52,    51,    49,   116,   111,     0,   286,   260,   261,     0,
      22,     0,     0,   295,    88,     0,     0,     0,   104,   100,
      95,   310,   102,   129,   109,   105,   291,    35,    34,   236,
      32,    30,    25,    28,    24,   304,     0,     0,     0,    68,
      71,    88,     0,   148,     0,   139,     0,   131,   144,     0,
     145,   322,   299,     0,   317,   318,   238,     0,   269,   271,
     264,     0,     0,   239,   246,   241,   246,   211,    53,     0,
       0,    21,    20,   293,     0,   114,     0,    94,     0,     0,
     309,   107,     0,   127,   292,     0,    31,    27,    26,   303,
     253,   255,   256,     0,     0,   313,    89,   156,     0,   152,
       0,     0,   141,     0,     0,   143,   142,   165,   270,   263,
     321,   320,   266,   242,   307,   245,   248,    12,     0,    87,
     133,   101,   103,   310,     0,     0,   290,     0,   298,     0,
     282,    28,   276,   158,   160,   159,   312,   311,   155,   154,
     149,   150,     0,   147,   135,     0,     0,   134,   137,     0,
       0,   305,   250,   244,   247,   259,     0,   308,     0,     0,
      29,   296,     0,     0,   281,   279,   280,     0,     0,     0,
     275,   273,   274,     0,   157,   151,   138,     0,   136,   130,
     319,   249,     0,   129,   126,   304,   284,   162,     0,   278,
     316,   140,   132,   128,   302,   283,   161,   277,   315,   314
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -363,  -363,  -363,  -363,  -363,   335,  -363,   157,   326,  -363,
     334,  -363,  -204,   -17,    46,  -363,  -363,  -107,  -363,   338,
    -305,     1,   232,  -363,   172,    90,  -363,  -363,  -363,  -363,
    -363,  -363,  -363,  -363,  -363,  -363,  -363,  -363,    50,  -363,
    -363,  -363,  -363,   280,   282,    78,    12,   165,    83,  -363,
      11,  -363,  -363,  -363,  -363,  -363,   -82,  -363,  -363,  -363,
     -49,  -363,  -363,  -363,    57,   142,  -363,  -363,  -363,  -200,
      17,  -363,  -362,  -363,    -1,  -363,  -150,   243,   -14,  -363,
    -363,    10,   230,   237,   245,  -363,   235,  -363,   241,  -363,
     -76,  -363,  -363,   214,  -363,  -363,  -363,  -363,  -363,   385,
    -363,  -363,  -363,  -363,  -363,    64,    67,  -363,  -363,    -6,
      -4,  -363,  -363,  -363,   379,  -363,    74,  -328,  -363,   -53,
     305,  -363,   -47,  -106,  -363,  -363,  -363,    -7,    58,   130,
      27,   -84,   -40,    36,    31,    61,   -31,  -323,  -363,    20,
     193
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,    35,    36,    37,    38,    39,    40,   276,    41,    42,
      43,   212,   114,   232,   115,   376,   230,   116,   226,    44,
      45,   251,    47,    48,   289,   201,   202,    49,   130,   329,
      50,    51,    52,    53,    54,    55,    56,    57,   365,   249,
      58,    59,    60,   104,   105,   310,   311,   108,   312,   109,
     110,    61,    62,    63,    64,    65,   373,    66,    67,    68,
     335,   392,   437,    69,   255,   137,   336,   432,   433,   252,
     388,   422,   480,   424,    70,   155,    71,    72,    73,    74,
     167,    75,    76,    77,    78,   173,    79,   176,    80,   181,
      81,    82,    83,   186,    84,   121,   122,   126,   118,    85,
     127,   123,    86,   187,   284,   285,   286,   443,   444,   100,
      87,   119,   380,   235,    88,   299,   278,   279,   348,   460,
     461,   462,   454,   455,   456,    96,    89,    90,   317,   214,
     324,   152,   382,   355,   371,   330,   464,   280,   281,   402,
     149
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
      92,    46,    95,   261,   102,   225,   182,   301,   128,   297,
     124,   236,   107,    94,   239,   117,   120,   125,    99,   101,
      99,   313,   423,   400,   133,   131,   132,   387,   401,   111,
     139,   136,   138,   237,   209,   343,   240,   177,     3,    46,
     168,   244,   151,   153,   171,   174,   228,   247,   151,  -297,
     234,   188,   207,   337,   103,   175,   453,    93,   112,   208,
     234,   189,   113,   154,   457,   112,   242,   172,   154,   113,
     210,   190,   215,   191,    15,    16,   154,   178,   192,   300,
      17,    18,   387,    19,    91,   112,    22,   103,    23,   113,
     179,   476,   180,    25,    97,   477,   193,   479,     3,   229,
     112,   194,   362,   204,   113,   272,  -297,   -99,    29,    30,
     224,   195,   400,   196,    34,   219,   486,   401,   333,   197,
     334,   183,   430,   307,   198,   204,   199,   308,   246,   379,
     200,    98,   431,   205,    15,    16,   233,   151,   206,   396,
      17,    18,   263,    19,    91,   306,    22,   234,    23,   309,
     260,   184,   185,    25,   168,   234,   242,   223,   234,   129,
     213,   112,   459,   347,   453,   113,   410,   234,    29,    30,
       5,   349,   204,   106,  -287,     7,   342,   266,    -5,   135,
      29,   140,   144,   277,   283,   291,    -6,     2,   290,   148,
     434,   150,   151,   438,   156,   291,   169,   168,   290,   170,
     211,   203,   293,   216,   277,   221,   298,   296,   445,   374,
     220,   357,   305,   222,   304,   227,   378,   458,   231,   381,
     238,   245,   241,   303,   248,   253,   319,   254,   326,   256,
     322,   287,   325,   420,   425,   466,   327,   264,   258,   469,
       3,   265,   302,   318,    99,   316,   259,   331,   473,   474,
     157,   273,    99,   138,   323,   274,   294,   315,   158,   159,
     160,   320,   328,   161,   321,   162,   340,   481,   332,   339,
     163,   164,   482,   344,   345,   346,    15,    16,   165,   166,
     350,   351,    17,    18,   352,    19,    91,  -245,    22,   353,
      23,   354,   356,   366,   359,    25,   192,   364,   360,   308,
     361,   369,   370,   425,   375,   372,   390,   425,   275,   425,
      29,    30,   383,   425,   391,   384,   393,   394,   403,   408,
     411,   415,     3,   407,   412,   426,   417,   385,   425,   429,
     435,   436,   389,    46,   282,   439,   154,   440,   425,   442,
     448,   446,   397,   449,   450,   452,   398,   463,   467,   277,
     277,   472,   478,   283,   333,   405,   379,     3,    15,    16,
     488,   418,   295,   409,    17,    18,   145,    19,    91,   377,
      22,   414,    23,   142,   292,   146,   143,    25,   419,   358,
     257,   386,   413,   217,   367,   218,  -306,   314,    46,   468,
     368,   483,    29,    30,    16,   395,   338,   262,   267,    17,
      18,   288,    19,    91,   428,    22,   268,    23,   270,     1,
       2,     3,    25,     4,   134,   269,     5,   271,   404,     6,
     147,     7,     8,   406,   399,   385,   487,    29,    30,   485,
     243,   465,   416,   363,     9,   484,    10,    11,    12,   277,
     441,   471,    13,    14,   447,   451,   427,    15,    16,   489,
     341,   475,     0,    17,    18,     0,    19,    20,    21,    22,
     470,    23,     0,    24,     0,     0,    25,     0,    26,    27,
       0,    28,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    29,    30,    31,     0,    32,    33,    34,     1,     2,
       3,     0,     4,     0,     0,     5,     0,     0,     6,     0,
       7,     8,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     9,     0,    10,    11,    12,     0,     0,
       0,    13,    14,     0,     0,     0,    15,    16,     0,     0,
       0,     0,    17,    18,     0,    19,    91,   141,    22,     0,
      23,     0,    24,     0,     0,    25,     0,    26,    27,     0,
      28,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      29,    30,    31,     0,    32,    33,    34,     1,     2,     3,
       0,     4,     0,     0,     5,     0,     0,     6,     0,     7,
       8,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     9,     0,    10,    11,    12,     0,     0,     0,
      13,    14,     0,     0,     0,    15,    16,     0,     0,     0,
       0,    17,    18,     0,    19,    91,     0,    22,     3,    23,
       0,    24,     0,     0,    25,     0,    26,    27,     0,    28,
     282,     0,     0,     0,     0,     0,     0,     0,     0,    29,
      30,    31,     0,    32,    33,    34,     1,     0,     3,     0,
       4,     0,     0,     0,    15,    16,     6,     0,     0,     8,
      17,    18,     0,    19,    91,     0,    22,     0,    23,     0,
       0,     9,     0,    25,    11,    12,     0,     0,     0,     0,
      14,     0,     0,     0,    15,    16,     0,     0,    29,    30,
      17,    18,     0,    19,    91,   250,    22,     1,    23,     3,
      24,     4,     0,    25,     0,    26,    27,     6,    28,     0,
       8,     0,     0,     0,     0,     0,     0,     0,    29,    30,
       0,     0,     9,     0,    34,    11,    12,     0,     0,     0,
       0,    14,     0,     0,     0,    15,    16,     3,     0,     0,
       0,    17,    18,     0,    19,    91,     0,    22,     0,    23,
       0,    24,   274,     0,    25,     0,    26,    27,     0,    28,
       0,     0,     0,     0,     0,     0,     0,     3,     0,    29,
      30,     0,     0,    15,    16,    34,     0,     0,     0,    17,
      18,     0,    19,    91,     3,    22,     0,    23,     0,     0,
       0,     0,    25,     0,     0,     0,     0,     0,     3,     0,
       0,     0,     0,    15,    16,     0,     0,    29,    30,    17,
      18,     0,    19,    91,     0,    22,     0,    23,     0,     0,
     421,    16,    25,     0,     0,     0,    17,    18,     0,    19,
      91,     0,    22,     0,    23,    16,     0,    29,    30,    25,
      17,    18,     0,    19,    91,     0,     0,     0,    23,     0,
       0,     0,     0,    25,    29,    30,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    29,    30
};

static const yytype_int16 yycheck[] =
{
       1,     0,     3,   153,    10,   112,    82,   211,    22,   209,
      17,   117,    13,     2,   120,    16,    17,    18,     8,     9,
      10,   221,   384,   351,    28,    26,    27,   332,   351,    15,
      34,    32,    33,   117,    15,    27,   120,    22,     9,    38,
      10,   125,    16,    40,    47,    54,    24,   131,    16,    15,
      34,     3,     9,   253,    21,    64,    40,    55,    51,    16,
      34,    13,    55,    60,    15,    51,    34,    70,    60,    55,
      51,    23,    42,    25,    45,    46,    60,    62,    30,    72,
      51,    52,   387,    54,    55,    51,    57,    21,    59,    55,
      75,   453,    77,    64,    55,   457,    48,   459,     9,    77,
      51,    53,   302,    21,    55,   181,    72,    41,    79,    80,
     111,    63,   440,    65,    85,   104,   478,   440,    31,    71,
      33,    21,     6,    51,    76,    21,    78,    55,   129,    16,
      82,    55,    16,    51,    45,    46,    15,    16,    56,   339,
      51,    52,   156,    54,    55,    41,    57,    34,    59,    77,
     151,    51,    52,    64,    10,    34,    34,     6,    34,    70,
      16,    51,    40,    30,    40,    55,   366,    34,    79,    80,
      14,   277,    21,    55,     0,    19,   260,   167,     0,    15,
      79,     0,    28,   184,   185,   192,     0,     8,   192,    74,
     390,    16,    16,   393,     5,   202,    12,    10,   202,     4,
      51,    16,   203,    42,   205,    15,   210,   208,   408,   316,
      41,   287,   216,    16,   215,    15,   323,   421,    30,   325,
      68,    73,    72,   213,    16,    15,   227,    16,   234,     6,
     231,    24,   233,   383,   384,   435,   242,    57,    56,   439,
       9,    42,    15,    72,   234,    16,    55,   248,   448,   449,
      29,    55,   242,   254,    16,    24,    55,    55,    37,    38,
      39,    55,    16,    42,    55,    44,   256,   467,    43,    15,
      49,    50,   472,   274,   275,    72,    45,    46,    57,    58,
      16,    16,    51,    52,    21,    54,    55,    15,    57,    73,
      59,    16,    15,    15,    72,    64,    30,    16,    72,    55,
      72,     6,    16,   453,    16,    26,    15,   457,    77,   459,
      79,    80,    42,   463,    27,    42,    15,    27,    21,    15,
      72,    27,     9,    56,    55,    16,    24,   328,   478,    18,
      15,    33,   333,   332,    21,    15,    60,    16,   488,    15,
      15,    27,   343,    15,    55,    15,   347,    16,    15,   350,
     351,    15,    15,   354,    31,   356,    16,     9,    45,    46,
      16,   378,   205,   364,    51,    52,    40,    54,    55,   323,
      57,   372,    59,    38,   202,    41,    38,    64,   379,   289,
     148,   331,   370,   103,   306,   103,    73,   222,   387,   438,
     307,   473,    79,    80,    46,   338,   254,   154,   168,    51,
      52,   187,    54,    55,   387,    57,   169,    59,   173,     7,
       8,     9,    64,    11,    29,   170,    14,   176,   354,    17,
      41,    19,    20,   356,   350,   426,   479,    79,    80,   476,
     125,   432,   374,   303,    32,   475,    34,    35,    36,   440,
     404,   442,    40,    41,   413,   418,   385,    45,    46,   480,
     257,   452,    -1,    51,    52,    -1,    54,    55,    56,    57,
     440,    59,    -1,    61,    -1,    -1,    64,    -1,    66,    67,
      -1,    69,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    79,    80,    81,    -1,    83,    84,    85,     7,     8,
       9,    -1,    11,    -1,    -1,    14,    -1,    -1,    17,    -1,
      19,    20,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    32,    -1,    34,    35,    36,    -1,    -1,
      -1,    40,    41,    -1,    -1,    -1,    45,    46,    -1,    -1,
      -1,    -1,    51,    52,    -1,    54,    55,    56,    57,    -1,
      59,    -1,    61,    -1,    -1,    64,    -1,    66,    67,    -1,
      69,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      79,    80,    81,    -1,    83,    84,    85,     7,     8,     9,
      -1,    11,    -1,    -1,    14,    -1,    -1,    17,    -1,    19,
      20,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    32,    -1,    34,    35,    36,    -1,    -1,    -1,
      40,    41,    -1,    -1,    -1,    45,    46,    -1,    -1,    -1,
      -1,    51,    52,    -1,    54,    55,    -1,    57,     9,    59,
      -1,    61,    -1,    -1,    64,    -1,    66,    67,    -1,    69,
      21,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    79,
      80,    81,    -1,    83,    84,    85,     7,    -1,     9,    -1,
      11,    -1,    -1,    -1,    45,    46,    17,    -1,    -1,    20,
      51,    52,    -1,    54,    55,    -1,    57,    -1,    59,    -1,
      -1,    32,    -1,    64,    35,    36,    -1,    -1,    -1,    -1,
      41,    -1,    -1,    -1,    45,    46,    -1,    -1,    79,    80,
      51,    52,    -1,    54,    55,    56,    57,     7,    59,     9,
      61,    11,    -1,    64,    -1,    66,    67,    17,    69,    -1,
      20,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    79,    80,
      -1,    -1,    32,    -1,    85,    35,    36,    -1,    -1,    -1,
      -1,    41,    -1,    -1,    -1,    45,    46,     9,    -1,    -1,
      -1,    51,    52,    -1,    54,    55,    -1,    57,    -1,    59,
      -1,    61,    24,    -1,    64,    -1,    66,    67,    -1,    69,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,     9,    -1,    79,
      80,    -1,    -1,    45,    46,    85,    -1,    -1,    -1,    51,
      52,    -1,    54,    55,     9,    57,    -1,    59,    -1,    -1,
      -1,    -1,    64,    -1,    -1,    -1,    -1,    -1,     9,    -1,
      -1,    -1,    -1,    45,    46,    -1,    -1,    79,    80,    51,
      52,    -1,    54,    55,    -1,    57,    -1,    59,    -1,    -1,
      45,    46,    64,    -1,    -1,    -1,    51,    52,    -1,    54,
      55,    -1,    57,    -1,    59,    46,    -1,    79,    80,    64,
      51,    52,    -1,    54,    55,    -1,    -1,    -1,    59,    -1,
      -1,    -1,    -1,    64,    79,    80,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    79,    80
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,     7,     8,     9,    11,    14,    17,    19,    20,    32,
      34,    35,    36,    40,    41,    45,    46,    51,    52,    54,
      55,    56,    57,    59,    61,    64,    66,    67,    69,    79,
      80,    81,    83,    84,    85,    87,    88,    89,    90,    91,
      92,    94,    95,    96,   105,   106,   107,   108,   109,   113,
     116,   117,   118,   119,   120,   121,   122,   123,   126,   127,
     128,   137,   138,   139,   140,   141,   143,   144,   145,   149,
     160,   162,   163,   164,   165,   167,   168,   169,   170,   172,
     174,   176,   177,   178,   180,   185,   188,   196,   200,   212,
     213,    55,   160,    55,   136,   160,   211,    55,    55,   167,
     195,   167,   195,    21,   129,   130,    55,   160,   133,   135,
     136,    15,    51,    55,    98,   100,   103,   160,   184,   197,
     160,   181,   182,   187,   213,   160,   183,   186,   164,    70,
     114,   160,   160,   196,   185,    15,   160,   151,   160,   196,
       0,    56,    91,   105,    28,    94,    96,   200,    74,   226,
      16,    16,   217,    40,    60,   161,     5,    29,    37,    38,
      39,    42,    44,    49,    50,    57,    58,   166,    10,    12,
       4,    47,    70,   171,    54,    64,   173,    22,    62,    75,
      77,   175,   176,    21,    51,    52,   179,   189,     3,    13,
      23,    25,    30,    48,    53,    63,    65,    71,    76,    78,
      82,   111,   112,    16,    21,    51,    56,     9,    16,    15,
      51,    51,    97,    16,   215,    42,    42,   129,   130,   136,
      41,    15,    16,     6,   160,   103,   104,    15,    24,    77,
     102,    30,    99,    15,    34,   199,   209,   217,    68,   209,
     217,    72,    34,   206,   217,    73,   160,   217,    16,   125,
      56,   107,   155,    15,    16,   150,     6,   108,    56,    55,
     160,   162,   163,   164,    57,    42,   167,   168,   169,   170,
     172,   174,   176,    55,    24,    77,    93,   160,   202,   203,
     223,   224,    21,   160,   190,   191,   192,    24,   179,   110,
     196,   213,   110,   160,    55,    93,   160,   155,   196,   201,
      72,    98,    15,   167,   160,   196,    41,    51,    55,    77,
     131,   132,   134,   155,   133,    55,    16,   214,    72,   160,
      55,    55,   160,    16,   216,   160,   195,   195,    16,   115,
     221,   160,    43,    31,    33,   146,   152,   155,   151,    15,
     167,   226,   217,    27,   160,   160,    72,    30,   204,   209,
      16,    16,    21,    73,    16,   219,    15,   176,   111,    72,
      72,    72,   155,   215,    16,   124,    15,   131,   134,     6,
      16,   220,    26,   142,   103,    16,   101,   100,   103,    16,
     198,   209,   218,    42,    42,   160,   124,   106,   156,   160,
      15,    27,   147,    15,    27,   150,   155,   160,   160,   202,
     203,   223,   225,    21,   191,   160,   192,    56,    15,   160,
     155,    72,    55,   132,   160,    27,   214,    24,    99,   160,
     162,    45,   157,   158,   159,   162,    16,   221,   156,    18,
       6,    16,   153,   154,   155,    15,    33,   148,   155,    15,
      16,   219,    15,   193,   194,   155,    27,   220,    15,    15,
      55,   216,    15,    40,   208,   209,   210,    15,    98,    40,
     205,   206,   207,    16,   222,   160,   155,    15,   146,   155,
     225,   160,    15,   155,   155,   160,   158,   158,    15,   158,
     158,   155,   155,   142,   218,   208,   158,   205,    16,   222
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    86,    87,    87,    87,    88,    88,    89,    90,    90,
      91,    91,    92,    92,    93,    93,    94,    94,    95,    95,
      96,    97,    97,    98,    98,    99,    99,   100,   100,   101,
     101,   102,   102,   103,   103,   104,   105,   106,   106,   107,
     108,   108,   108,   108,   108,   108,   108,   108,   108,   109,
     109,   110,   110,   111,   111,   112,   112,   112,   112,   112,
     112,   112,   112,   112,   112,   112,   112,   113,   113,   114,
     114,   115,   115,   116,   117,   118,   118,   118,   118,   118,
     119,   120,   121,   121,   122,   123,   123,   124,   124,   125,
     125,   126,   126,   127,   128,   128,   129,   129,   130,   130,
     131,   131,   131,   132,   132,   133,   133,   134,   135,   135,
     136,   136,   137,   137,   138,   138,   139,   139,   140,   140,
     140,   140,   140,   140,   140,   140,   141,   141,   142,   142,
     143,   143,   144,   144,   145,   145,   146,   146,   147,   147,
     148,   148,   149,   150,   150,   151,   151,   152,   152,   153,
     153,   154,   154,   155,   155,   156,   156,   157,   157,   158,
     158,   159,   159,   160,   160,   161,   161,   162,   162,   163,
     163,   164,   164,   165,   165,   166,   166,   166,   166,   166,
     166,   166,   166,   166,   166,   166,   167,   167,   168,   168,
     169,   169,   170,   170,   171,   171,   172,   172,   173,   173,
     174,   174,   175,   175,   175,   175,   176,   176,   177,   177,
     177,   178,   178,   179,   179,   180,   180,   180,   180,   180,
     180,   180,   181,   181,   182,   182,   183,   183,   184,   184,
     185,   185,   186,   186,   187,   187,   188,   188,   189,   189,
     189,   190,   191,   191,   191,   192,   192,   193,   193,   194,
     194,   195,   196,   197,   197,   198,   198,   199,   199,   200,
     200,   201,   201,   202,   202,   202,   202,   202,   202,   203,
     203,   204,   204,   205,   205,   206,   206,   207,   207,   208,
     208,   209,   209,   210,   210,   211,   211,   212,   213,   213,
     214,   214,   214,   215,   215,   215,   216,   216,   216,   217,
     217,   217,   218,   218,   218,   219,   219,   219,   220,   220,
     220,   221,   221,   221,   222,   222,   222,   223,   224,   225,
     225,   225,   226,   226,   226
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     1,     1,     1,     1,     1,     2,     1,     1,
       2,     0,     6,     3,     1,     0,     2,     1,     2,     2,
       5,     3,     2,     2,     3,     2,     0,     4,     0,     3,
       0,     3,     2,     1,     3,     2,     1,     1,     1,     3,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     3,
       2,     1,     1,     3,     0,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     2,     4,     2,
       0,     1,     0,     2,     1,     1,     1,     1,     1,     1,
       1,     1,     2,     1,     1,     3,     1,     2,     0,     3,
       0,     1,     1,     2,     5,     4,     2,     0,     2,     1,
       1,     3,     1,     3,     1,     3,     1,     2,     1,     3,
       1,     3,     3,     2,     5,     2,     4,     2,     1,     1,
       1,     1,     1,     1,     1,     1,     8,     5,     5,     0,
       7,     4,     9,     6,     6,     6,     4,     3,     3,     0,
       3,     0,     5,     3,     0,     3,     1,     3,     1,     1,
       1,     2,     0,     1,     4,     2,     1,     2,     1,     1,
       1,     4,     3,     2,     1,     4,     0,     1,     3,     1,
       3,     2,     1,     1,     3,     1,     1,     1,     1,     1,
       1,     1,     1,     2,     1,     2,     1,     3,     1,     3,
       1,     3,     1,     3,     1,     1,     1,     3,     1,     1,
       1,     3,     1,     1,     1,     1,     2,     1,     1,     1,
       1,     4,     2,     2,     0,     3,     3,     3,     3,     1,
       1,     1,     1,     1,     1,     0,     1,     0,     1,     0,
       2,     1,     2,     2,     2,     2,     4,     3,     3,     3,
       2,     2,     3,     1,     4,     1,     0,     1,     0,     2,
       1,     2,     2,     4,     2,     1,     1,     1,     1,     7,
       4,     1,     0,     3,     2,     1,     3,     1,     1,     2,
       3,     1,     0,     1,     1,     5,     4,     3,     2,     1,
       1,     5,     4,     3,     2,     1,     3,     1,     2,     1,
       3,     1,     0,     3,     1,     0,     4,     1,     0,     3,
       1,     0,     5,     1,     0,     3,     1,     0,     3,     1,
       0,     3,     3,     2,     3,     3,     2,     2,     2,     3,
       1,     1,     3,     1,     0
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
        case 11:
#line 113 "parse.y" /* yacc.c:1646  */
    { (yyval.ast) = 0; }
#line 1831 "parse.tab.c" /* yacc.c:1646  */
    break;

  case 15:
#line 121 "parse.y" /* yacc.c:1646  */
    { (yyval.ast) = 0; }
#line 1837 "parse.tab.c" /* yacc.c:1646  */
    break;

  case 20:
#line 133 "parse.y" /* yacc.c:1646  */
    {
        (yyval.ast) = new AstFuncdef((AstName*)(yyvsp[-3].ast), (AstSuite*)(yyvsp[0].ast));
    }
#line 1845 "parse.tab.c" /* yacc.c:1646  */
    break;

  case 26:
#line 147 "parse.y" /* yacc.c:1646  */
    { (yyval.ast) = 0; }
#line 1851 "parse.tab.c" /* yacc.c:1646  */
    break;

  case 28:
#line 151 "parse.y" /* yacc.c:1646  */
    { (yyval.ast) = 0; }
#line 1857 "parse.tab.c" /* yacc.c:1646  */
    break;

  case 30:
#line 155 "parse.y" /* yacc.c:1646  */
    { (yyval.ast) = 0; }
#line 1863 "parse.tab.c" /* yacc.c:1646  */
    break;

  case 36:
#line 171 "parse.y" /* yacc.c:1646  */
    { go((yyvsp[0].ast)); }
#line 1869 "parse.tab.c" /* yacc.c:1646  */
    break;

  case 40:
#line 181 "parse.y" /* yacc.c:1646  */
    { (yyval.ast) = (yyvsp[0].ast); }
#line 1875 "parse.tab.c" /* yacc.c:1646  */
    break;

  case 41:
#line 182 "parse.y" /* yacc.c:1646  */
    { (yyval.ast) = (yyvsp[0].ast); }
#line 1881 "parse.tab.c" /* yacc.c:1646  */
    break;

  case 42:
#line 183 "parse.y" /* yacc.c:1646  */
    { (yyval.ast) = 0; }
#line 1887 "parse.tab.c" /* yacc.c:1646  */
    break;

  case 43:
#line 184 "parse.y" /* yacc.c:1646  */
    { (yyval.ast) = 0; }
#line 1893 "parse.tab.c" /* yacc.c:1646  */
    break;

  case 44:
#line 185 "parse.y" /* yacc.c:1646  */
    { (yyval.ast) = (yyvsp[0].ast); }
#line 1899 "parse.tab.c" /* yacc.c:1646  */
    break;

  case 45:
#line 186 "parse.y" /* yacc.c:1646  */
    { (yyval.ast) = 0; }
#line 1905 "parse.tab.c" /* yacc.c:1646  */
    break;

  case 46:
#line 187 "parse.y" /* yacc.c:1646  */
    { (yyval.ast) = (yyvsp[0].ast); }
#line 1911 "parse.tab.c" /* yacc.c:1646  */
    break;

  case 47:
#line 188 "parse.y" /* yacc.c:1646  */
    { (yyval.ast) = 0; }
#line 1917 "parse.tab.c" /* yacc.c:1646  */
    break;

  case 48:
#line 189 "parse.y" /* yacc.c:1646  */
    { (yyval.ast) = 0; }
#line 1923 "parse.tab.c" /* yacc.c:1646  */
    break;

  case 49:
#line 192 "parse.y" /* yacc.c:1646  */
    { (yyval.ast) = (yyvsp[-1].ab)((AstName*)(yyvsp[-2].ast), (yyvsp[0].ast)); }
#line 1929 "parse.tab.c" /* yacc.c:1646  */
    break;

  case 50:
#line 194 "parse.y" /* yacc.c:1646  */
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
#line 1944 "parse.tab.c" /* yacc.c:1646  */
    break;

  case 51:
#line 206 "parse.y" /* yacc.c:1646  */
    { }
#line 1950 "parse.tab.c" /* yacc.c:1646  */
    break;

  case 52:
#line 207 "parse.y" /* yacc.c:1646  */
    { }
#line 1956 "parse.tab.c" /* yacc.c:1646  */
    break;

  case 53:
#line 210 "parse.y" /* yacc.c:1646  */
    { (yyval.ast) = (yyvsp[-1].ast); }
#line 1962 "parse.tab.c" /* yacc.c:1646  */
    break;

  case 54:
#line 211 "parse.y" /* yacc.c:1646  */
    { (yyval.ast) = 0; }
#line 1968 "parse.tab.c" /* yacc.c:1646  */
    break;

  case 55:
#line 215 "parse.y" /* yacc.c:1646  */
    { (yyval.ab) = [](AstName* x, Ast* y) 
        {
            Ast* temp = x && y ? new AstPlusEqual(x, y) : 0;
            return temp;
        }; 
    }
#line 1979 "parse.tab.c" /* yacc.c:1646  */
    break;

  case 56:
#line 222 "parse.y" /* yacc.c:1646  */
    { (yyval.ab) = [](AstName* x, Ast* y) 
        {
            Ast* temp = x && y ? new AstMinusEqual(x, y) : 0;
            return temp;
        }; 
    }
#line 1990 "parse.tab.c" /* yacc.c:1646  */
    break;

  case 57:
#line 229 "parse.y" /* yacc.c:1646  */
    { (yyval.ab) = [](AstName* x, Ast* y) 
        {
            Ast* temp = x && y ? new AstStarEqual(x, y) : 0;
            return temp;
        }; 
    }
#line 2001 "parse.tab.c" /* yacc.c:1646  */
    break;

  case 58:
#line 236 "parse.y" /* yacc.c:1646  */
    { (yyval.ab) = [](AstName* x, Ast* y) 
        {
            Ast* temp = x && y ? new AstDivEqual(x, y) : 0;
            return temp;
        }; 
    }
#line 2012 "parse.tab.c" /* yacc.c:1646  */
    break;

  case 59:
#line 243 "parse.y" /* yacc.c:1646  */
    { (yyval.ab) = [](AstName* x, Ast* y) 
        {
            Ast* temp = x && y ? new AstModEqual(x, y) : 0;
            return temp;
        }; 
    }
#line 2023 "parse.tab.c" /* yacc.c:1646  */
    break;

  case 60:
#line 249 "parse.y" /* yacc.c:1646  */
    { (yyval.ab) = [](AstName* x, Ast* y) { return (Ast*)NULL; }; }
#line 2029 "parse.tab.c" /* yacc.c:1646  */
    break;

  case 61:
#line 250 "parse.y" /* yacc.c:1646  */
    { (yyval.ab) = [](AstName* x, Ast* y) { return (Ast*)NULL; }; }
#line 2035 "parse.tab.c" /* yacc.c:1646  */
    break;

  case 62:
#line 251 "parse.y" /* yacc.c:1646  */
    { (yyval.ab) = [](AstName* x, Ast* y) { return (Ast*)NULL; }; }
#line 2041 "parse.tab.c" /* yacc.c:1646  */
    break;

  case 63:
#line 252 "parse.y" /* yacc.c:1646  */
    { (yyval.ab) = [](AstName* x, Ast* y) { return (Ast*)NULL; }; }
#line 2047 "parse.tab.c" /* yacc.c:1646  */
    break;

  case 64:
#line 253 "parse.y" /* yacc.c:1646  */
    { (yyval.ab) = [](AstName* x, Ast* y) { return (Ast*)NULL; }; }
#line 2053 "parse.tab.c" /* yacc.c:1646  */
    break;

  case 65:
#line 255 "parse.y" /* yacc.c:1646  */
    { (yyval.ab) = [](AstName* x, Ast* y) 
        {
            Ast* temp = x && y ? new AstExpEqual(x, y) : 0;
            return temp;
        }; 
    }
#line 2064 "parse.tab.c" /* yacc.c:1646  */
    break;

  case 66:
#line 263 "parse.y" /* yacc.c:1646  */
    { (yyval.ab) = [](AstName* x, Ast* y) 
        {
            Ast* temp = x && y ? new AstIntDivEqual(x, y) : 0;
            return temp;
        }; 
    }
#line 2075 "parse.tab.c" /* yacc.c:1646  */
    break;

  case 67:
#line 272 "parse.y" /* yacc.c:1646  */
    {
        (yyval.ast) = new AstPrint((yyvsp[0].ast));
    }
#line 2083 "parse.tab.c" /* yacc.c:1646  */
    break;

  case 69:
#line 278 "parse.y" /* yacc.c:1646  */
    { (yyval.ast) = (yyvsp[-1].ast); }
#line 2089 "parse.tab.c" /* yacc.c:1646  */
    break;

  case 70:
#line 279 "parse.y" /* yacc.c:1646  */
    { (yyval.ast) = 0; }
#line 2095 "parse.tab.c" /* yacc.c:1646  */
    break;

  case 72:
#line 283 "parse.y" /* yacc.c:1646  */
    { (yyval.ast) = 0; }
#line 2101 "parse.tab.c" /* yacc.c:1646  */
    break;

  case 77:
#line 294 "parse.y" /* yacc.c:1646  */
    { (yyval.ast) = (yyvsp[0].ast); }
#line 2107 "parse.tab.c" /* yacc.c:1646  */
    break;

  case 82:
#line 306 "parse.y" /* yacc.c:1646  */
    {
       (yyval.ast) = new AstReturn((yyvsp[0].ast));
    }
#line 2115 "parse.tab.c" /* yacc.c:1646  */
    break;

  case 88:
#line 320 "parse.y" /* yacc.c:1646  */
    { (yyval.ast) = 0; }
#line 2121 "parse.tab.c" /* yacc.c:1646  */
    break;

  case 90:
#line 324 "parse.y" /* yacc.c:1646  */
    { (yyval.ast) = 0; }
#line 2127 "parse.tab.c" /* yacc.c:1646  */
    break;

  case 97:
#line 339 "parse.y" /* yacc.c:1646  */
    { (yyval.ast) = 0; }
#line 2133 "parse.tab.c" /* yacc.c:1646  */
    break;

  case 112:
#line 371 "parse.y" /* yacc.c:1646  */
    {
        ((AstName*)(yyvsp[-2].ast))->makeGlobal();
        (yyval.ast) = (yyvsp[-2].ast);
    }
#line 2142 "parse.tab.c" /* yacc.c:1646  */
    break;

  case 113:
#line 376 "parse.y" /* yacc.c:1646  */
    {
        ((AstName*)(yyvsp[0].ast))->makeGlobal();
        (yyval.ast) = (yyvsp[0].ast);
    }
#line 2151 "parse.tab.c" /* yacc.c:1646  */
    break;

  case 118:
#line 390 "parse.y" /* yacc.c:1646  */
    { (yyval.ast) = 0; }
#line 2157 "parse.tab.c" /* yacc.c:1646  */
    break;

  case 119:
#line 391 "parse.y" /* yacc.c:1646  */
    { (yyval.ast) = 0; }
#line 2163 "parse.tab.c" /* yacc.c:1646  */
    break;

  case 120:
#line 392 "parse.y" /* yacc.c:1646  */
    { (yyval.ast) = 0; }
#line 2169 "parse.tab.c" /* yacc.c:1646  */
    break;

  case 121:
#line 393 "parse.y" /* yacc.c:1646  */
    { (yyval.ast) = 0; }
#line 2175 "parse.tab.c" /* yacc.c:1646  */
    break;

  case 122:
#line 394 "parse.y" /* yacc.c:1646  */
    { (yyval.ast) = 0; }
#line 2181 "parse.tab.c" /* yacc.c:1646  */
    break;

  case 123:
#line 395 "parse.y" /* yacc.c:1646  */
    { (yyval.ast) = (yyvsp[0].ast); }
#line 2187 "parse.tab.c" /* yacc.c:1646  */
    break;

  case 124:
#line 396 "parse.y" /* yacc.c:1646  */
    { (yyval.ast) = 0; }
#line 2193 "parse.tab.c" /* yacc.c:1646  */
    break;

  case 125:
#line 397 "parse.y" /* yacc.c:1646  */
    { (yyval.ast) = 0; }
#line 2199 "parse.tab.c" /* yacc.c:1646  */
    break;

  case 129:
#line 405 "parse.y" /* yacc.c:1646  */
    { (yyval.ast) = 0; }
#line 2205 "parse.tab.c" /* yacc.c:1646  */
    break;

  case 139:
#line 425 "parse.y" /* yacc.c:1646  */
    { (yyval.ast) = 0; }
#line 2211 "parse.tab.c" /* yacc.c:1646  */
    break;

  case 141:
#line 429 "parse.y" /* yacc.c:1646  */
    { (yyval.ast) = 0; }
#line 2217 "parse.tab.c" /* yacc.c:1646  */
    break;

  case 144:
#line 436 "parse.y" /* yacc.c:1646  */
    { (yyval.ast) = 0; }
#line 2223 "parse.tab.c" /* yacc.c:1646  */
    break;

  case 152:
#line 452 "parse.y" /* yacc.c:1646  */
    { (yyval.ast) = 0; }
#line 2229 "parse.tab.c" /* yacc.c:1646  */
    break;

  case 154:
#line 458 "parse.y" /* yacc.c:1646  */
    {
        (yyval.ast) = (yyvsp[-1].ast);
    }
#line 2237 "parse.tab.c" /* yacc.c:1646  */
    break;

  case 155:
#line 464 "parse.y" /* yacc.c:1646  */
    {

        (yyval.ast) = new AstSuite((yyvsp[-1].ast), (AstSuite*)(yyvsp[0].ast));
    }
#line 2246 "parse.tab.c" /* yacc.c:1646  */
    break;

  case 156:
#line 469 "parse.y" /* yacc.c:1646  */
    {
        (yyval.ast) = new AstSuite((yyvsp[0].ast));
    }
#line 2254 "parse.tab.c" /* yacc.c:1646  */
    break;

  case 164:
#line 493 "parse.y" /* yacc.c:1646  */
    { (yyval.ast) = 0; }
#line 2260 "parse.tab.c" /* yacc.c:1646  */
    break;

  case 166:
#line 497 "parse.y" /* yacc.c:1646  */
    { (yyval.ast) = 0; }
#line 2266 "parse.tab.c" /* yacc.c:1646  */
    break;

  case 172:
#line 509 "parse.y" /* yacc.c:1646  */
    { (yyval.ast) = (yyvsp[0].ast); }
#line 2272 "parse.tab.c" /* yacc.c:1646  */
    break;

  case 173:
#line 512 "parse.y" /* yacc.c:1646  */
    { (yyval.ast) = (yyvsp[0].ast); }
#line 2278 "parse.tab.c" /* yacc.c:1646  */
    break;

  case 174:
#line 513 "parse.y" /* yacc.c:1646  */
    { (yyval.ast) = 0; }
#line 2284 "parse.tab.c" /* yacc.c:1646  */
    break;

  case 186:
#line 530 "parse.y" /* yacc.c:1646  */
    {  (yyval.ast) = (yyvsp[0].ast); }
#line 2290 "parse.tab.c" /* yacc.c:1646  */
    break;

  case 188:
#line 534 "parse.y" /* yacc.c:1646  */
    { (yyval.ast) = (yyvsp[0].ast); }
#line 2296 "parse.tab.c" /* yacc.c:1646  */
    break;

  case 190:
#line 538 "parse.y" /* yacc.c:1646  */
    { (yyval.ast) = (yyvsp[0].ast); }
#line 2302 "parse.tab.c" /* yacc.c:1646  */
    break;

  case 192:
#line 542 "parse.y" /* yacc.c:1646  */
    { (yyval.ast) = (yyvsp[0].ast); }
#line 2308 "parse.tab.c" /* yacc.c:1646  */
    break;

  case 193:
#line 543 "parse.y" /* yacc.c:1646  */
    { (yyval.ast) = 0; }
#line 2314 "parse.tab.c" /* yacc.c:1646  */
    break;

  case 196:
#line 551 "parse.y" /* yacc.c:1646  */
    { (yyval.ast) = (yyvsp[0].ast); }
#line 2320 "parse.tab.c" /* yacc.c:1646  */
    break;

  case 197:
#line 554 "parse.y" /* yacc.c:1646  */
    { (yyval.ast) = (yyvsp[-1].b)((yyvsp[-2].ast), (yyvsp[0].ast)); }
#line 2326 "parse.tab.c" /* yacc.c:1646  */
    break;

  case 198:
#line 559 "parse.y" /* yacc.c:1646  */
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
#line 2342 "parse.tab.c" /* yacc.c:1646  */
    break;

  case 199:
#line 572 "parse.y" /* yacc.c:1646  */
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
#line 2362 "parse.tab.c" /* yacc.c:1646  */
    break;

  case 200:
#line 590 "parse.y" /* yacc.c:1646  */
    { (yyval.ast) = (yyvsp[0].ast); }
#line 2368 "parse.tab.c" /* yacc.c:1646  */
    break;

  case 201:
#line 592 "parse.y" /* yacc.c:1646  */
    { (yyval.ast) = (yyvsp[-1].b)((yyvsp[-2].ast), (yyvsp[0].ast)); }
#line 2374 "parse.tab.c" /* yacc.c:1646  */
    break;

  case 202:
#line 597 "parse.y" /* yacc.c:1646  */
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
#line 2394 "parse.tab.c" /* yacc.c:1646  */
    break;

  case 203:
#line 614 "parse.y" /* yacc.c:1646  */
    { (yyval.b) = [](Ast* x, Ast* y) 
        { 
            Ast* temp = new AstDiv(x, y); 
            return temp;
        }; 
    }
#line 2405 "parse.tab.c" /* yacc.c:1646  */
    break;

  case 204:
#line 622 "parse.y" /* yacc.c:1646  */
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
#line 2425 "parse.tab.c" /* yacc.c:1646  */
    break;

  case 205:
#line 638 "parse.y" /* yacc.c:1646  */
    { 
        (yyval.b) = [](Ast* x, Ast* y) 
        { 
            Ast* temp = new AstIntDiv(x, y); 
            return temp;
        }; 
    }
#line 2437 "parse.tab.c" /* yacc.c:1646  */
    break;

  case 206:
#line 647 "parse.y" /* yacc.c:1646  */
    { (yyval.ast) = (yyvsp[-1].ub)((yyvsp[0].ast)); }
#line 2443 "parse.tab.c" /* yacc.c:1646  */
    break;

  case 207:
#line 648 "parse.y" /* yacc.c:1646  */
    { (yyval.ast) = (yyvsp[0].ast); }
#line 2449 "parse.tab.c" /* yacc.c:1646  */
    break;

  case 208:
#line 653 "parse.y" /* yacc.c:1646  */
    {
         (yyval.ub) = [](Ast* x) 
         { 
            Ast* temp = x ? new AstUPlus(x) : 0;
            return temp;
         };
     }
#line 2461 "parse.tab.c" /* yacc.c:1646  */
    break;

  case 209:
#line 662 "parse.y" /* yacc.c:1646  */
    {
         (yyval.ub) = [](Ast* x) 
         { 
             Ast* temp = x ? new AstUMin(x) : 0;
             return temp;
         }; 
    }
#line 2473 "parse.tab.c" /* yacc.c:1646  */
    break;

  case 210:
#line 671 "parse.y" /* yacc.c:1646  */
    { 
        (yyval.ub) = [](Ast* x) 
        { 
            Ast* temp = x ? new AstUNot(x) : 0;
            return temp;
        };
    }
#line 2485 "parse.tab.c" /* yacc.c:1646  */
    break;

  case 211:
#line 680 "parse.y" /* yacc.c:1646  */
    { (yyval.ast) = (yyvsp[-3].ast) && (yyvsp[0].ast) ? new AstExp((yyvsp[-3].ast), (yyvsp[0].ast)) : 0; }
#line 2491 "parse.tab.c" /* yacc.c:1646  */
    break;

  case 212:
#line 681 "parse.y" /* yacc.c:1646  */
    { (yyval.ast) = (yyvsp[-1].ast); }
#line 2497 "parse.tab.c" /* yacc.c:1646  */
    break;

  case 213:
#line 684 "parse.y" /* yacc.c:1646  */
    { (yyval.ast) = 0; }
#line 2503 "parse.tab.c" /* yacc.c:1646  */
    break;

  case 214:
#line 685 "parse.y" /* yacc.c:1646  */
    { (yyval.ast) = 0; }
#line 2509 "parse.tab.c" /* yacc.c:1646  */
    break;

  case 215:
#line 688 "parse.y" /* yacc.c:1646  */
    { (yyval.ast) = (yyvsp[-1].ast); }
#line 2515 "parse.tab.c" /* yacc.c:1646  */
    break;

  case 216:
#line 689 "parse.y" /* yacc.c:1646  */
    { (yyval.ast) = 0; }
#line 2521 "parse.tab.c" /* yacc.c:1646  */
    break;

  case 217:
#line 690 "parse.y" /* yacc.c:1646  */
    { (yyval.ast) = 0; }
#line 2527 "parse.tab.c" /* yacc.c:1646  */
    break;

  case 218:
#line 691 "parse.y" /* yacc.c:1646  */
    { (yyval.ast) = 0; }
#line 2533 "parse.tab.c" /* yacc.c:1646  */
    break;

  case 219:
#line 692 "parse.y" /* yacc.c:1646  */
    { (yyval.ast) = (yyvsp[0].ast); }
#line 2539 "parse.tab.c" /* yacc.c:1646  */
    break;

  case 220:
#line 693 "parse.y" /* yacc.c:1646  */
    { (yyval.ast) = (yyvsp[0].ast); }
#line 2545 "parse.tab.c" /* yacc.c:1646  */
    break;

  case 221:
#line 694 "parse.y" /* yacc.c:1646  */
    { (yyval.ast) = 0; }
#line 2551 "parse.tab.c" /* yacc.c:1646  */
    break;

  case 222:
#line 698 "parse.y" /* yacc.c:1646  */
    { (yyval.ast) = (yyvsp[0].ast); }
#line 2557 "parse.tab.c" /* yacc.c:1646  */
    break;

  case 223:
#line 699 "parse.y" /* yacc.c:1646  */
    { (yyval.ast) = (yyvsp[0].ast); }
#line 2563 "parse.tab.c" /* yacc.c:1646  */
    break;

  case 224:
#line 702 "parse.y" /* yacc.c:1646  */
    { (yyval.ast) = (yyvsp[0].ast); }
#line 2569 "parse.tab.c" /* yacc.c:1646  */
    break;

  case 225:
#line 703 "parse.y" /* yacc.c:1646  */
    { (yyval.ast) = 0; }
#line 2575 "parse.tab.c" /* yacc.c:1646  */
    break;

  case 227:
#line 707 "parse.y" /* yacc.c:1646  */
    { (yyval.ast) = 0; }
#line 2581 "parse.tab.c" /* yacc.c:1646  */
    break;

  case 229:
#line 711 "parse.y" /* yacc.c:1646  */
    { (yyval.ast) = 0; }
#line 2587 "parse.tab.c" /* yacc.c:1646  */
    break;

  case 230:
#line 714 "parse.y" /* yacc.c:1646  */
    { (yyval.ast) = (yyvsp[0].ast); }
#line 2593 "parse.tab.c" /* yacc.c:1646  */
    break;

  case 238:
#line 731 "parse.y" /* yacc.c:1646  */
    { (yyval.ast) = (yyvsp[-1].ast); }
#line 2599 "parse.tab.c" /* yacc.c:1646  */
    break;

  case 246:
#line 745 "parse.y" /* yacc.c:1646  */
    { (yyval.ast) = 0; }
#line 2605 "parse.tab.c" /* yacc.c:1646  */
    break;

  case 248:
#line 749 "parse.y" /* yacc.c:1646  */
    { (yyval.ast) = 0; }
#line 2611 "parse.tab.c" /* yacc.c:1646  */
    break;

  case 252:
#line 760 "parse.y" /* yacc.c:1646  */
    { (yyval.ast) = (yyvsp[-1].ast); }
#line 2617 "parse.tab.c" /* yacc.c:1646  */
    break;

  case 262:
#line 780 "parse.y" /* yacc.c:1646  */
    { (yyval.ast) = 0; }
#line 2623 "parse.tab.c" /* yacc.c:1646  */
    break;

  case 272:
#line 796 "parse.y" /* yacc.c:1646  */
    { (yyval.ast) = 0; }
#line 2629 "parse.tab.c" /* yacc.c:1646  */
    break;

  case 288:
#line 832 "parse.y" /* yacc.c:1646  */
    { (yyval.ast) = (yyvsp[0].ast); }
#line 2635 "parse.tab.c" /* yacc.c:1646  */
    break;

  case 292:
#line 838 "parse.y" /* yacc.c:1646  */
    { (yyval.ast) = 0; }
#line 2641 "parse.tab.c" /* yacc.c:1646  */
    break;

  case 295:
#line 843 "parse.y" /* yacc.c:1646  */
    { (yyval.ast) = 0; }
#line 2647 "parse.tab.c" /* yacc.c:1646  */
    break;

  case 298:
#line 848 "parse.y" /* yacc.c:1646  */
    { (yyval.ast) = 0; }
#line 2653 "parse.tab.c" /* yacc.c:1646  */
    break;

  case 301:
#line 853 "parse.y" /* yacc.c:1646  */
    { (yyval.ast) = 0; }
#line 2659 "parse.tab.c" /* yacc.c:1646  */
    break;

  case 304:
#line 858 "parse.y" /* yacc.c:1646  */
    { (yyval.ast) = 0; }
#line 2665 "parse.tab.c" /* yacc.c:1646  */
    break;

  case 307:
#line 863 "parse.y" /* yacc.c:1646  */
    { (yyval.ast) = 0; }
#line 2671 "parse.tab.c" /* yacc.c:1646  */
    break;

  case 310:
#line 869 "parse.y" /* yacc.c:1646  */
    { (yyval.ast) = 0; }
#line 2677 "parse.tab.c" /* yacc.c:1646  */
    break;

  case 324:
#line 895 "parse.y" /* yacc.c:1646  */
    { (yyval.ast) = 0; }
#line 2683 "parse.tab.c" /* yacc.c:1646  */
    break;


#line 2687 "parse.tab.c" /* yacc.c:1646  */
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
#line 898 "parse.y" /* yacc.c:1906  */


#include <stdio.h>
void yyerror (char const *s) {
	fprintf (stderr, "%d: %s with [%s]\n", yylineno, s, yytext);
}

