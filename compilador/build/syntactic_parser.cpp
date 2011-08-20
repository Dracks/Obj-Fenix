/* A Bison parser, made by GNU Bison 2.3.  */

/* Skeleton implementation for Bison's Yacc-like parsers in C

   Copyright (C) 1984, 1989, 1990, 2000, 2001, 2002, 2003, 2004, 2005, 2006
   Free Software Foundation, Inc.

   This program is free software; you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation; either version 2, or (at your option)
   any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program; if not, write to the Free Software
   Foundation, Inc., 51 Franklin Street, Fifth Floor,
   Boston, MA 02110-1301, USA.  */

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
#define YYBISON_VERSION "2.3"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Using locations.  */
#define YYLSP_NEEDED 0



/* Tokens.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
   /* Put the tokens into the symbol table, so that GDB and other debuggers
      know about them.  */
   enum yytokentype {
     MOD_TOKEN = 258,
     UMENYS = 259,
     ID_SUBTYPE = 260,
     ID_FUNCTION = 261,
     CLASS_TOKEN = 262,
     DEF_TOKEN = 263,
     PROGRAM_TOKEN = 264,
     END_TOKEN = 265,
     IMPORT_TOKEN = 266,
     INTERFACE_TOKEN = 267,
     PACKAGE_TOKEN = 268,
     NATIVE_TOKEN = 269,
     THIS_TOKEN = 270,
     INHERIT_TOKEN = 271,
     BEGIN_TOKEN = 272,
     ELIF_TOKEN = 273,
     IF_TOKEN = 274,
     ELSE_TOKEN = 275,
     RETURN_TOKEN = 276,
     PROTECTED_TOKEN = 277,
     PUBLIC_TOKEN = 278,
     PRIVATE_TOKEN = 279,
     WHILE_TOKEN = 280,
     DO_TOKEN = 281,
     LOOP_TOKEN = 282,
     FOR_TOKEN = 283,
     IN_TOKEN = 284,
     LEXICAL_ERROR = 285,
     AND_TOKEN = 286,
     LE_OP = 287,
     GE_OP = 288,
     DIF_OP = 289,
     POT_OP = 290,
     ASSIG = 291,
     DOS_PUNTOS = 292,
     IDENTIFIER = 293,
     NUMERIC_LITERAL = 294,
     CHARACTER_LITERAL = 295,
     STRING_LITERAL = 296,
     CONSTANT_VALUE = 297
   };
#endif
/* Tokens.  */
#define MOD_TOKEN 258
#define UMENYS 259
#define ID_SUBTYPE 260
#define ID_FUNCTION 261
#define CLASS_TOKEN 262
#define DEF_TOKEN 263
#define PROGRAM_TOKEN 264
#define END_TOKEN 265
#define IMPORT_TOKEN 266
#define INTERFACE_TOKEN 267
#define PACKAGE_TOKEN 268
#define NATIVE_TOKEN 269
#define THIS_TOKEN 270
#define INHERIT_TOKEN 271
#define BEGIN_TOKEN 272
#define ELIF_TOKEN 273
#define IF_TOKEN 274
#define ELSE_TOKEN 275
#define RETURN_TOKEN 276
#define PROTECTED_TOKEN 277
#define PUBLIC_TOKEN 278
#define PRIVATE_TOKEN 279
#define WHILE_TOKEN 280
#define DO_TOKEN 281
#define LOOP_TOKEN 282
#define FOR_TOKEN 283
#define IN_TOKEN 284
#define LEXICAL_ERROR 285
#define AND_TOKEN 286
#define LE_OP 287
#define GE_OP 288
#define DIF_OP 289
#define POT_OP 290
#define ASSIG 291
#define DOS_PUNTOS 292
#define IDENTIFIER 293
#define NUMERIC_LITERAL 294
#define CHARACTER_LITERAL 295
#define STRING_LITERAL 296
#define CONSTANT_VALUE 297




/* Copy the first part of user declarations.  */
#line 1 "/Users/dracks/Documents/Programacio/Obj-Fenix/Obj-Fenix/compilador/src/syntactic_parser.y"

	
#include <stdio.h>
#include <stdlib.h>
#include "syntactic_parser.h"
#include "../src/main.h"
#include "../src/tools.h"
#include "../src/debug.h"
//#include "../src/classes/clist.h"
#include "../src/classes/syntacticElement.h"
#include "../src/treeCode/Base.h"
#include "../src/treeCode/Loop.h"
#include "../src/treeCode/Condition.h"//*/
#include "../src/treeCode/Expresion.h"
	
#define YYLMAX 100
#define YES 1
#define NO 0
#define FALSE 0
#define TRUE 1
	
	extern FILE *yyout;
	extern int yylineno;
	extern int num_line;
	extern int num_column;
	extern int espai_actual;
	extern char* parsing_file;
	extern int yylex();
	extern void yyerror(char*);
	extern clist list_files_compile;
	extern clist list_objects_builded;
	extern SyntacticElement* main_object;
	int regs[26];
	char * str ;
	int tmp_num_line;
	
	char ambitoActual=0;
	SyntacticElement* actualClass;
	SyntacticElement* tmpSyntactic;
	clist listReturnStatments;


/* Enabling traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif

/* Enabling verbose error messages.  */
#ifdef YYERROR_VERBOSE
# undef YYERROR_VERBOSE
# define YYERROR_VERBOSE 1
#else
# define YYERROR_VERBOSE 1
#endif

/* Enabling the token table.  */
#ifndef YYTOKEN_TABLE
# define YYTOKEN_TABLE 0
#endif

#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef union YYSTYPE
#line 44 "/Users/dracks/Documents/Programacio/Obj-Fenix/Obj-Fenix/compilador/src/syntactic_parser.y"
{

	struct SyntacticElement* data;
	struct clist* list;
	struct AbstractExpresion* expresion;
	struct Base*  sentence;
	bool boolean;
}
/* Line 193 of yacc.c.  */
#line 231 "/Users/dracks/Documents/Programacio/Obj-Fenix/Obj-Fenix/compilador/build/syntactic_parser.cpp"
	YYSTYPE;
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
# define YYSTYPE_IS_TRIVIAL 1
#endif



/* Copy the second part of user declarations.  */


/* Line 216 of yacc.c.  */
#line 244 "/Users/dracks/Documents/Programacio/Obj-Fenix/Obj-Fenix/compilador/build/syntactic_parser.cpp"

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
# if defined YYENABLE_NLS && YYENABLE_NLS
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
YYID (int i)
#else
static int
YYID (i)
    int i;
#endif
{
  return i;
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
  yytype_int16 yyss;
  YYSTYPE yyvs;
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
# define YYSTACK_RELOCATE(Stack)					\
    do									\
      {									\
	YYSIZE_T yynewbytes;						\
	YYCOPY (&yyptr->Stack, Stack, yysize);				\
	Stack = &yyptr->Stack;						\
	yynewbytes = yystacksize * sizeof (*Stack) + YYSTACK_GAP_MAXIMUM; \
	yyptr += yynewbytes / sizeof (*yyptr);				\
      }									\
    while (YYID (0))

#endif

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  5
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   156

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  55
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  56
/* YYNRULES -- Number of rules.  */
#define YYNRULES  91
/* YYNRULES -- Number of states.  */
#define YYNSTATES  160

/* YYTRANSLATE(YYLEX) -- Bison symbol number corresponding to YYLEX.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   297

#define YYTRANSLATE(YYX)						\
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[YYLEX] -- Bison symbol number corresponding to YYLEX.  */
static const yytype_uint8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     4,     2,
      52,    53,     7,     5,    51,     6,    54,     8,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,    49,    50,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     3,     2,     2,     2,     2,     2,
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
       2,     2,     2,     2,     2,     2,     1,     2,     9,    10,
      11,    12,    13,    14,    15,    16,    17,    18,    19,    20,
      21,    22,    23,    24,    25,    26,    27,    28,    29,    30,
      31,    32,    33,    34,    35,    36,    37,    38,    39,    40,
      41,    42,    43,    44,    45,    46,    47,    48
};

#if YYDEBUG
/* YYPRHS[YYN] -- Index of the first RHS symbol of rule number YYN in
   YYRHS.  */
static const yytype_uint8 yyprhs[] =
{
       0,     0,     3,     4,    10,    14,    15,    18,    19,    23,
      24,    28,    31,    33,    35,    36,    45,    47,    48,    51,
      52,    58,    59,    61,    63,    65,    68,    70,    72,    74,
      75,    76,    83,    86,    89,    93,    94,    95,   102,   107,
     108,   112,   113,   114,   119,   120,   124,   125,   131,   133,
     137,   138,   139,   144,   147,   148,   150,   152,   154,   156,
     160,   163,   164,   168,   170,   171,   178,   184,   188,   189,
     191,   193,   195,   197,   203,   208,   213,   215,   217,   221,
     222,   226,   227,   233,   237,   238,   244,   245,   246,   248,
     249,   253
};

/* YYRHS -- A `-1'-separated list of the rules' RHS.  */
static const yytype_int8 yyrhs[] =
{
      56,     0,    -1,    -1,    58,    59,    60,    57,    62,    -1,
      15,    44,    49,    -1,    -1,    59,    61,    -1,    -1,    19,
      44,    50,    -1,    -1,    17,    48,    50,    -1,    62,    63,
      -1,    63,    -1,    64,    -1,    -1,    13,    66,    44,    67,
      65,    49,    68,    16,    -1,    20,    -1,    -1,    22,    44,
      -1,    -1,    69,    49,    70,    16,    68,    -1,    -1,    29,
      -1,    30,    -1,    28,    -1,    71,    70,    -1,    71,    -1,
      72,    -1,    77,    -1,    -1,    -1,    75,    49,    73,    44,
      74,    50,    -1,     1,    50,    -1,    44,    76,    -1,    51,
      44,    76,    -1,    -1,    -1,    14,    44,    78,    79,    83,
      85,    -1,    52,    81,    80,    53,    -1,    -1,    51,    81,
      80,    -1,    -1,    -1,    44,    49,    82,    44,    -1,    -1,
      27,    84,    44,    -1,    -1,    49,    86,    23,    89,    16,
      -1,    50,    -1,    87,    50,    86,    -1,    -1,    -1,    75,
      49,    88,    44,    -1,    89,    90,    -1,    -1,    95,    -1,
      98,    -1,    91,    -1,    93,    -1,   103,    92,    50,    -1,
      42,   103,    -1,    -1,    27,    94,    50,    -1,   103,    -1,
      -1,    25,    97,    49,    89,    96,    16,    -1,    24,    97,
      49,    89,    96,    -1,    26,    49,    89,    -1,    -1,   103,
      -1,    99,    -1,   100,    -1,   101,    -1,    31,    97,    49,
      89,    16,    -1,    32,    49,    89,    16,    -1,    33,    49,
      89,    16,    -1,    44,    -1,    48,    -1,    52,   103,    53,
      -1,    -1,   102,   104,   105,    -1,    -1,    54,    44,   106,
     107,   105,    -1,    44,   108,   109,    -1,    -1,    52,   108,
     103,   110,    53,    -1,    -1,    -1,   103,    -1,    -1,    51,
     103,   110,    -1,    -1
};

/* YYRLINE[YYN] -- source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,    82,    82,    80,    86,    97,   100,   101,   103,   104,
     106,   108,   109,   111,   114,   114,   171,   172,   174,   175,
     178,   182,   184,   185,   186,   188,   189,   197,   198,   200,
     200,   200,   217,   219,   221,   222,   224,   224,   271,   275,
     277,   281,   283,   283,   299,   299,   300,   302,   310,   312,
     322,   324,   324,   347,   348,   350,   351,   352,   353,   356,
     367,   372,   374,   381,   382,   385,   400,   413,   426,   432,
     436,   437,   438,   449,   464,   479,   493,   494,   502,   504,
     504,   589,   589,   611,   624,   629,   636,   638,   645,   652,
     654,   658
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || YYTOKEN_TABLE
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "'|'", "'&'", "'+'", "'-'", "'*'", "'/'",
  "MOD_TOKEN", "UMENYS", "ID_SUBTYPE", "ID_FUNCTION", "CLASS_TOKEN",
  "DEF_TOKEN", "PROGRAM_TOKEN", "END_TOKEN", "IMPORT_TOKEN",
  "INTERFACE_TOKEN", "PACKAGE_TOKEN", "NATIVE_TOKEN", "THIS_TOKEN",
  "INHERIT_TOKEN", "BEGIN_TOKEN", "ELIF_TOKEN", "IF_TOKEN", "ELSE_TOKEN",
  "RETURN_TOKEN", "PROTECTED_TOKEN", "PUBLIC_TOKEN", "PRIVATE_TOKEN",
  "WHILE_TOKEN", "DO_TOKEN", "LOOP_TOKEN", "FOR_TOKEN", "IN_TOKEN",
  "LEXICAL_ERROR", "AND_TOKEN", "LE_OP", "GE_OP", "DIF_OP", "POT_OP",
  "ASSIG", "DOS_PUNTOS", "IDENTIFIER", "NUMERIC_LITERAL",
  "CHARACTER_LITERAL", "STRING_LITERAL", "CONSTANT_VALUE", "':'", "';'",
  "','", "'('", "')'", "'.'", "$accept", "program", "@1",
  "option_defining_program", "list_modules_import",
  "option_package_definition", "module_import", "list_class_definition",
  "class_interface_definition", "class_definition", "@2", "option_native",
  "option_inherit", "list_acces_level_block", "level_definition_token",
  "list_definitions", "definition", "propiety_definition", "@3", "@4",
  "list_propiety", "list_propiety_concat", "method_definition", "@5",
  "option_definition_parameters", "list_definition_parameters",
  "definition_parameter", "@6", "option_return", "@7",
  "implementation_option", "var_declaration_list", "var_declaration", "@8",
  "list_sentences", "sentence", "call_sentence", "option_assign_sentence",
  "return_sentence", "option_expression", "condition_sentence",
  "option_elsif_sentences_list", "conditional_sentence",
  "loop_options_sentence", "while_sentence", "do_sentence",
  "loop_sentence", "value", "expression", "@9",
  "option_extension_expression", "@10", "option_call_parameters_parent",
  "push_espai_claseActual", "option_call_parameters",
  "list_call_parameters", 0
};
#endif

# ifdef YYPRINT
/* YYTOKNUM[YYLEX-NUM] -- Internal token number corresponding to
   token YYLEX-NUM.  */
static const yytype_uint16 yytoknum[] =
{
       0,   256,   257,   124,    38,    43,    45,    42,    47,   258,
     259,   260,   261,   262,   263,   264,   265,   266,   267,   268,
     269,   270,   271,   272,   273,   274,   275,   276,   277,   278,
     279,   280,   281,   282,   283,   284,   285,   286,   287,   288,
     289,   290,   291,   292,   293,   294,   295,   296,   297,    58,
      59,    44,    40,    41,    46
};
# endif

/* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    55,    57,    56,    58,    58,    59,    59,    60,    60,
      61,    62,    62,    63,    65,    64,    66,    66,    67,    67,
      68,    68,    69,    69,    69,    70,    70,    71,    71,    73,
      74,    72,    72,    75,    76,    76,    78,    77,    79,    79,
      80,    80,    82,    81,    84,    83,    83,    85,    85,    86,
      86,    88,    87,    89,    89,    90,    90,    90,    90,    91,
      92,    92,    93,    94,    94,    95,    96,    96,    96,    97,
      98,    98,    98,    99,   100,   101,   102,   102,   102,   104,
     103,   106,   105,   105,   105,   107,   107,   108,   109,   109,
     110,   110
};

/* YYR2[YYN] -- Number of symbols composing right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     0,     5,     3,     0,     2,     0,     3,     0,
       3,     2,     1,     1,     0,     8,     1,     0,     2,     0,
       5,     0,     1,     1,     1,     2,     1,     1,     1,     0,
       0,     6,     2,     2,     3,     0,     0,     6,     4,     0,
       3,     0,     0,     4,     0,     3,     0,     5,     1,     3,
       0,     0,     4,     2,     0,     1,     1,     1,     1,     3,
       2,     0,     3,     1,     0,     6,     5,     3,     0,     1,
       1,     1,     1,     5,     4,     4,     1,     1,     3,     0,
       3,     0,     5,     3,     0,     5,     0,     0,     1,     0,
       3,     0
};

/* YYDEFACT[STATE-NAME] -- Default rule to reduce with in state
   STATE-NUM when YYTABLE doesn't specify something else to do.  Zero
   means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       5,     0,     0,     7,     0,     1,     9,     4,     0,     0,
       2,     6,     0,     0,     0,    10,     8,    17,     3,    12,
      13,    16,     0,    11,    19,     0,    14,    18,     0,    21,
      24,    22,    23,     0,     0,    15,     0,     0,     0,    35,
       0,     0,    27,     0,    28,    32,    36,     0,    33,    21,
      25,    29,    39,    35,    20,     0,     0,    46,    34,    30,
       0,    41,    44,     0,     0,    42,     0,     0,     0,    50,
      48,    37,    31,     0,    41,    38,    45,     0,     0,     0,
      43,    40,    51,    54,    50,     0,     0,    49,    52,    47,
       0,    64,     0,     0,     0,    76,    77,     0,    53,    57,
      58,    55,    56,    70,    71,    72,    79,    61,     0,    69,
       0,    63,     0,    54,    54,     0,    84,     0,     0,    54,
      62,    54,     0,     0,    78,    87,     0,    80,    60,    59,
      68,     0,    74,    75,    89,    81,     0,     0,     0,    73,
      88,    83,    86,     0,    54,    65,    87,    84,    54,    67,
       0,    82,    68,    91,    66,     0,     0,    91,    85,    90
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     2,    14,     3,     6,    10,    11,    18,    19,    20,
      28,    22,    26,    33,    34,    40,    41,    42,    55,    64,
      43,    48,    44,    52,    57,    67,    61,    73,    63,    68,
      71,    78,    79,    85,    86,    98,    99,   118,   100,   110,
     101,   138,   108,   102,   103,   104,   105,   106,   107,   116,
     127,   142,   147,   134,   141,   156
};

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
#define YYPACT_NINF -91
static const yytype_int8 yypact[] =
{
      13,   -23,    29,   -91,   -19,   -91,     7,   -91,   -16,    -9,
     -91,   -91,    -7,    -5,    38,   -91,   -91,    32,    38,   -91,
     -91,   -91,    12,   -91,    37,    18,   -91,   -91,    14,   -18,
     -91,   -91,   -91,    58,    27,   -91,     5,    31,    33,    28,
      66,     4,   -91,    40,   -91,   -91,   -91,    44,   -91,   -18,
     -91,   -91,    41,    28,   -91,    46,    48,    67,   -91,   -91,
      47,    49,   -91,   -34,    45,   -91,    48,    50,    55,    60,
     -91,   -91,   -91,    75,    49,   -91,   -91,    62,    97,    71,
     -91,   -91,   -91,   -91,    60,    78,     6,   -91,   -91,   -91,
     -35,   -35,   -35,    74,    76,   -91,   -91,   -35,   -91,   -91,
     -91,   -91,   -91,   -91,   -91,   -91,   -91,    86,    83,   -91,
      77,   -91,    87,   -91,   -91,    88,   -40,   -35,    81,   -91,
     -91,   -91,     9,    39,   -91,   -91,    80,   -91,   -91,   -91,
      82,    53,   -91,   -91,   -35,   -91,   -35,    89,   119,   -91,
     -91,   -91,    90,    91,   -91,   -91,   -91,   -40,   -91,    85,
     -35,   -91,    82,    92,   -91,   -35,    93,    92,   -91,   -91
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int8 yypgoto[] =
{
     -91,   -91,   -91,   -91,   -91,   -91,   -91,   -91,   121,   -91,
     -91,   -91,   -91,    95,   -91,   104,   -91,   -91,   -91,   -91,
     -61,    94,   -91,   -91,   -91,    79,    84,   -91,   -91,   -91,
     -91,    64,   -91,   -91,   -46,   -91,   -91,   -91,   -91,   -91,
     -91,    -3,   -89,   -91,   -91,   -91,   -91,   -91,   -90,   -91,
       8,   -91,   -91,    10,   -91,    -6
};

/* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule which
   number is the opposite.  If zero, do what YYDEFACT says.
   If YYTABLE_NINF, syntax error.  */
#define YYTABLE_NINF -27
static const yytype_int16 yytable[] =
{
     109,   111,   109,   112,   125,    37,    37,   115,    77,    95,
      30,    31,    32,    96,   126,    69,    70,    97,    38,    38,
     -26,     4,    89,    77,     8,   132,     9,   128,     1,     5,
       7,    90,    12,    91,    90,    13,    91,    92,    93,    94,
      92,    93,    94,    15,   140,    16,   109,   143,    39,    39,
      95,    17,    21,    95,    96,   133,    24,    96,    97,    25,
     153,    97,    27,    29,    90,   157,    91,   122,   123,   139,
      92,    93,    94,   130,    35,   131,    36,    46,    90,    47,
      91,    45,    49,    95,    92,    93,    94,    96,    53,    51,
      59,    97,    60,    56,    62,    72,    65,    95,   149,    76,
      66,    96,   152,    75,    39,    97,   136,    90,   137,    91,
      90,    82,    91,    92,    93,    94,    92,    93,    94,    80,
      83,    84,    88,   113,   135,   114,    95,   120,   117,    95,
      96,   129,   119,    96,    97,   145,   121,    97,   144,    23,
     148,   124,   146,   155,    54,    50,   158,    58,    87,   154,
      74,   159,     0,    81,     0,   151,   150
};

static const yytype_int16 yycheck[] =
{
      90,    91,    92,    92,    44,     1,     1,    97,    69,    44,
      28,    29,    30,    48,    54,    49,    50,    52,    14,    14,
      16,    44,    16,    84,    17,    16,    19,   117,    15,     0,
      49,    25,    48,    27,    25,    44,    27,    31,    32,    33,
      31,    32,    33,    50,   134,    50,   136,   136,    44,    44,
      44,    13,    20,    44,    48,    16,    44,    48,    52,    22,
     150,    52,    44,    49,    25,   155,    27,   113,   114,    16,
      31,    32,    33,   119,    16,   121,    49,    44,    25,    51,
      27,    50,    16,    44,    31,    32,    33,    48,    44,    49,
      44,    52,    44,    52,    27,    50,    49,    44,   144,    44,
      51,    48,   148,    53,    44,    52,    24,    25,    26,    27,
      25,    49,    27,    31,    32,    33,    31,    32,    33,    44,
      23,    50,    44,    49,    44,    49,    44,    50,    42,    44,
      48,    50,    49,    48,    52,    16,    49,    52,    49,    18,
      49,    53,    52,    51,    49,    41,    53,    53,    84,   152,
      66,   157,    -1,    74,    -1,   147,   146
};

/* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
   symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,    15,    56,    58,    44,     0,    59,    49,    17,    19,
      60,    61,    48,    44,    57,    50,    50,    13,    62,    63,
      64,    20,    66,    63,    44,    22,    67,    44,    65,    49,
      28,    29,    30,    68,    69,    16,    49,     1,    14,    44,
      70,    71,    72,    75,    77,    50,    44,    51,    76,    16,
      70,    49,    78,    44,    68,    73,    52,    79,    76,    44,
      44,    81,    27,    83,    74,    49,    51,    80,    84,    49,
      50,    85,    50,    82,    81,    53,    44,    75,    86,    87,
      44,    80,    49,    23,    50,    88,    89,    86,    44,    16,
      25,    27,    31,    32,    33,    44,    48,    52,    90,    91,
      93,    95,    98,    99,   100,   101,   102,   103,    97,   103,
      94,   103,    97,    49,    49,   103,   104,    42,    92,    49,
      50,    49,    89,    89,    53,    44,    54,   105,   103,    50,
      89,    89,    16,    16,   108,    44,    24,    26,    96,    16,
     103,   109,   106,    97,    49,    16,    52,   107,    49,    89,
     108,   105,    89,   103,    96,    51,   110,   103,    53,   110
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
# if defined YYLTYPE_IS_TRIVIAL && YYLTYPE_IS_TRIVIAL
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
yy_stack_print (yytype_int16 *bottom, yytype_int16 *top)
#else
static void
yy_stack_print (bottom, top)
    yytype_int16 *bottom;
    yytype_int16 *top;
#endif
{
  YYFPRINTF (stderr, "Stack now");
  for (; bottom <= top; ++bottom)
    YYFPRINTF (stderr, " %d", *bottom);
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
      fprintf (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr, yyrhs[yyprhs[yyrule] + yyi],
		       &(yyvsp[(yyi + 1) - (yynrhs)])
		       		       );
      fprintf (stderr, "\n");
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



/* The look-ahead symbol.  */
int yychar;

/* The semantic value of the look-ahead symbol.  */
YYSTYPE yylval;

/* Number of syntax errors so far.  */
int yynerrs;



/*----------.
| yyparse.  |
`----------*/

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
  int yyn;
  int yyresult;
  /* Number of tokens to shift before error messages enabled.  */
  int yyerrstatus;
  /* Look-ahead token as an internal (translated) token number.  */
  int yytoken = 0;
#if YYERROR_VERBOSE
  /* Buffer for error messages, and its allocated size.  */
  char yymsgbuf[128];
  char *yymsg = yymsgbuf;
  YYSIZE_T yymsg_alloc = sizeof yymsgbuf;
#endif

  /* Three stacks and their tools:
     `yyss': related to states,
     `yyvs': related to semantic values,
     `yyls': related to locations.

     Refer to the stacks thru separate pointers, to allow yyoverflow
     to reallocate them elsewhere.  */

  /* The state stack.  */
  yytype_int16 yyssa[YYINITDEPTH];
  yytype_int16 *yyss = yyssa;
  yytype_int16 *yyssp;

  /* The semantic value stack.  */
  YYSTYPE yyvsa[YYINITDEPTH];
  YYSTYPE *yyvs = yyvsa;
  YYSTYPE *yyvsp;



#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N))

  YYSIZE_T yystacksize = YYINITDEPTH;

  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;


  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yystate = 0;
  yyerrstatus = 0;
  yynerrs = 0;
  yychar = YYEMPTY;		/* Cause a token to be read.  */

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
	YYSTACK_RELOCATE (yyss);
	YYSTACK_RELOCATE (yyvs);

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

  goto yybackup;

/*-----------.
| yybackup.  |
`-----------*/
yybackup:

  /* Do appropriate processing given the current state.  Read a
     look-ahead token if we need one and don't already have one.  */

  /* First try to decide what to do without reference to look-ahead token.  */
  yyn = yypact[yystate];
  if (yyn == YYPACT_NINF)
    goto yydefault;

  /* Not known => get a look-ahead token if don't already have one.  */

  /* YYCHAR is either YYEMPTY or YYEOF or a valid look-ahead symbol.  */
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

  if (yyn == YYFINAL)
    YYACCEPT;

  /* Count tokens shifted since error; after three, turn off error
     status.  */
  if (yyerrstatus)
    yyerrstatus--;

  /* Shift the look-ahead token.  */
  YY_SYMBOL_PRINT ("Shifting", yytoken, &yylval, &yylloc);

  /* Discard the shifted token unless it is eof.  */
  if (yychar != YYEOF)
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
        case 2:
#line 82 "/Users/dracks/Documents/Programacio/Obj-Fenix/Obj-Fenix/compilador/src/syntactic_parser.y"
    {syntactic_debug("program <-- option_package_definition");}
    break;

  case 3:
#line 83 "/Users/dracks/Documents/Programacio/Obj-Fenix/Obj-Fenix/compilador/src/syntactic_parser.y"
    {syntactic_debug("program <-- Option_defining_program list_modules_import option_package_Definition list_class_definition");;}
    break;

  case 4:
#line 86 "/Users/dracks/Documents/Programacio/Obj-Fenix/Obj-Fenix/compilador/src/syntactic_parser.y"
    { syntactic_debug("option_defining_program <-- Program Identifier :"); 
	if (main_object!=NULL){
		str=(char*)malloc(1024*sizeof(char));
		sprintf(str,"Two classes for program defined, ignorign(%s)",tmpSyntactic->getName().c_str());
		showError(str);
		free(str);
//		showError("Two classes for program defined")
	} else {
		main_object=(yyvsp[(2) - (3)].data);
	}
;}
    break;

  case 5:
#line 97 "/Users/dracks/Documents/Programacio/Obj-Fenix/Obj-Fenix/compilador/src/syntactic_parser.y"
    {syntactic_debug("option_defining_program <-- nothing");;}
    break;

  case 6:
#line 100 "/Users/dracks/Documents/Programacio/Obj-Fenix/Obj-Fenix/compilador/src/syntactic_parser.y"
    {syntactic_debug("list_modules_import <-- list_modules_import module_import");;}
    break;

  case 7:
#line 101 "/Users/dracks/Documents/Programacio/Obj-Fenix/Obj-Fenix/compilador/src/syntactic_parser.y"
    {syntactic_debug("list_modules_import <-- nothing");}
    break;

  case 8:
#line 103 "/Users/dracks/Documents/Programacio/Obj-Fenix/Obj-Fenix/compilador/src/syntactic_parser.y"
    {syntactic_debug("option_package_definition <-- PACKAGE_TOKEN IDENTIFIER ;");}
    break;

  case 9:
#line 104 "/Users/dracks/Documents/Programacio/Obj-Fenix/Obj-Fenix/compilador/src/syntactic_parser.y"
    {syntactic_debug("option_package_definition <-- nothing");}
    break;

  case 10:
#line 106 "/Users/dracks/Documents/Programacio/Obj-Fenix/Obj-Fenix/compilador/src/syntactic_parser.y"
    {syntactic_debug("module_import <-- import STRING"); list_files_compile.add(strCopy((yyvsp[(2) - (3)].data)->getName().c_str()));}
    break;

  case 11:
#line 108 "/Users/dracks/Documents/Programacio/Obj-Fenix/Obj-Fenix/compilador/src/syntactic_parser.y"
    {syntactic_debug("list_class_definition <-- list_class_definition class_interface_definition");}
    break;

  case 12:
#line 109 "/Users/dracks/Documents/Programacio/Obj-Fenix/Obj-Fenix/compilador/src/syntactic_parser.y"
    {syntactic_debug("list_class_definition <-- class_interface_definition");}
    break;

  case 13:
#line 111 "/Users/dracks/Documents/Programacio/Obj-Fenix/Obj-Fenix/compilador/src/syntactic_parser.y"
    {syntactic_debug("class_interface_definition <-- class_definition");}
    break;

  case 14:
#line 114 "/Users/dracks/Documents/Programacio/Obj-Fenix/Obj-Fenix/compilador/src/syntactic_parser.y"
    {
	tmpSyntactic=(yyvsp[(3) - (4)].data); 
	//printf("algo xirria - %s - %d\n", tmpSyntactic->getName(), tmpSyntactic->getSyntactic());
	if (tmpSyntactic->getSyntactic()==0){
		//printf("Vamus per parts!\n");
		tmpSyntactic->setSyntactic(1);
		actualClass=tmpSyntactic;
		printf("Debug definition class: %s in namespace: %d pointer: %p ", tmpSyntactic->getName().c_str(), espai_actual, tmpSyntactic);
		actualClass->setUID(getNextClassID());
		espai_actual=actualClass->getUID()+2;
		actualClass->setSpaceName(espai_actual);
		printf("with UID: %d\n", actualClass->getUID());
		insertThisToken(tmpSyntactic);
		tmpSyntactic=searchElem("this");
		if (tmpSyntactic==NULL){
			exit(-1);
		}
		tmpSyntactic=insertToken(strCopy(actualClass->getName().c_str()), IDENTIFIER, actualClass->getSpaceName());
		//tmpSyntactic=new SyntacticElement(actualClass->getName(), IDENTIFIER, num_line, parsing_file);
		tmpSyntactic->setSyntactic(2);
		clist* aux=new clist();
		SyntacticElement* aux2=new SyntacticElement("", IDENTIFIER, num_line, parsing_file);
		aux2->setSemantic(searchElem("Object",0));
		//assert(aux2!=NULL);
		aux->add(aux2);
		//MethodDefinition* cast=new MethodDefinition(actualClass->getName(), aux, new clist(), actualClass, 3, num_line);
		tmpSyntactic->addMethodImplementation(aux, new clist(), new clist(), actualClass, 3, num_line);
		actualClass->addMethod(tmpSyntactic);
//		insertToken(<#char *lexema#>, <#int type#>, <#int espai#>)
		//tmpSyntactic->setSyntactic(5);
		//tmpSyntactic->setSemantic(actualClass);
		//printf("Vamus per parts2!\n");
	} else if (tmpSyntactic->getSyntactic()==1){
		//fprintf(stderr, "ERROR line %d")
		//printf("I de fet, xirria molt!\n");
		str=(char*)malloc(1024*sizeof(char));
		sprintf(str,"Redeclaration class %s",tmpSyntactic->getName().c_str());
		showError(str);
		free(str);
	} //*/
	/*Aqui iria la herencia, de momento a NULL que vendria a ser el objeto padre. */
	actualClass->setSemantic((yyvsp[(4) - (4)].data));
;}
    break;

  case 15:
#line 158 "/Users/dracks/Documents/Programacio/Obj-Fenix/Obj-Fenix/compilador/src/syntactic_parser.y"
    {
	char* str=(char*)malloc(sizeof(char)*1024);
	sprintf(str, "class_definition <-- class option_native identifier(%s): list_acces_level_block end", actualClass->getName().c_str());
	syntactic_debug(str);
	free(str);
	
	list_objects_builded.add(actualClass);
	actualClass->setNative((yyvsp[(2) - (8)].boolean));
	
	espai_actual=0;
	ambitoActual=0;
;}
    break;

  case 16:
#line 171 "/Users/dracks/Documents/Programacio/Obj-Fenix/Obj-Fenix/compilador/src/syntactic_parser.y"
    {syntactic_debug("option_native <-- native"); (yyval.boolean)=YES;;}
    break;

  case 17:
#line 172 "/Users/dracks/Documents/Programacio/Obj-Fenix/Obj-Fenix/compilador/src/syntactic_parser.y"
    {syntactic_debug("option_native <-- nothing"); (yyval.boolean)=NO;;}
    break;

  case 18:
#line 174 "/Users/dracks/Documents/Programacio/Obj-Fenix/Obj-Fenix/compilador/src/syntactic_parser.y"
    {(yyval.data)=(yyvsp[(2) - (2)].data);;}
    break;

  case 19:
#line 175 "/Users/dracks/Documents/Programacio/Obj-Fenix/Obj-Fenix/compilador/src/syntactic_parser.y"
    {(yyval.data)=searchElem("Object");;}
    break;

  case 20:
#line 180 "/Users/dracks/Documents/Programacio/Obj-Fenix/Obj-Fenix/compilador/src/syntactic_parser.y"
    {syntactic_debug("list_acces_level_block <-- level_definition_token : list_definitions end list_acces_level_block");}
    break;

  case 21:
#line 182 "/Users/dracks/Documents/Programacio/Obj-Fenix/Obj-Fenix/compilador/src/syntactic_parser.y"
    {syntactic_debug("list_acces_level_block <-- nothing");}
    break;

  case 22:
#line 184 "/Users/dracks/Documents/Programacio/Obj-Fenix/Obj-Fenix/compilador/src/syntactic_parser.y"
    {syntactic_debug("level_definition_token <-- public");ambitoActual=0;;}
    break;

  case 23:
#line 185 "/Users/dracks/Documents/Programacio/Obj-Fenix/Obj-Fenix/compilador/src/syntactic_parser.y"
    {syntactic_debug("level_definition_token <-- private");ambitoActual=2;;}
    break;

  case 24:
#line 186 "/Users/dracks/Documents/Programacio/Obj-Fenix/Obj-Fenix/compilador/src/syntactic_parser.y"
    {syntactic_debug("level_definition_token <-- protected");ambitoActual=1;}
    break;

  case 25:
#line 188 "/Users/dracks/Documents/Programacio/Obj-Fenix/Obj-Fenix/compilador/src/syntactic_parser.y"
    {syntactic_debug("list_definitions <-- definition list_definitions");}
    break;

  case 26:
#line 189 "/Users/dracks/Documents/Programacio/Obj-Fenix/Obj-Fenix/compilador/src/syntactic_parser.y"
    {syntactic_debug("list_definitions <-- definition");}
    break;

  case 27:
#line 197 "/Users/dracks/Documents/Programacio/Obj-Fenix/Obj-Fenix/compilador/src/syntactic_parser.y"
    {syntactic_debug("definition <-- propiety_definition");}
    break;

  case 28:
#line 198 "/Users/dracks/Documents/Programacio/Obj-Fenix/Obj-Fenix/compilador/src/syntactic_parser.y"
    {syntactic_debug("definition <-- method_definition");}
    break;

  case 29:
#line 200 "/Users/dracks/Documents/Programacio/Obj-Fenix/Obj-Fenix/compilador/src/syntactic_parser.y"
    {name_space_push(0);}
    break;

  case 30:
#line 200 "/Users/dracks/Documents/Programacio/Obj-Fenix/Obj-Fenix/compilador/src/syntactic_parser.y"
    {name_space_pop();;}
    break;

  case 31:
#line 200 "/Users/dracks/Documents/Programacio/Obj-Fenix/Obj-Fenix/compilador/src/syntactic_parser.y"
    {syntactic_debug("propiety_definition <-- list_propiety : IDENTIFIER ;");
	cnode* nodeAux= (yyvsp[(1) - (6)].list)->getFirst();
	while (nodeAux!=NULL){
		tmpSyntactic=(SyntacticElement*)nodeAux->getContents();
		if (tmpSyntactic->getSyntactic()==0){
			tmpSyntactic->setAmbito(ambitoActual);
			tmpSyntactic->setSemantic((yyvsp[(4) - (6)].data));
			tmpSyntactic->setSyntactic(3);
			actualClass->addPropiety(tmpSyntactic);
		} else {
			str=(char*)malloc(1024*sizeof(char));
			sprintf(str, "Redeclaration of variable %s", tmpSyntactic->getName().c_str());
		}
		nodeAux=nodeAux->getNext();
	}//*/
	delete (yyvsp[(1) - (6)].list);
;}
    break;

  case 32:
#line 217 "/Users/dracks/Documents/Programacio/Obj-Fenix/Obj-Fenix/compilador/src/syntactic_parser.y"
    {syntactic_debug("propiety_definition <-- error ;");}
    break;

  case 33:
#line 219 "/Users/dracks/Documents/Programacio/Obj-Fenix/Obj-Fenix/compilador/src/syntactic_parser.y"
    {syntactic_debug("list_propiety <-- IDENTIFIER list_propiety_concat "); (yyval.list)=(yyvsp[(2) - (2)].list);(yyval.list)->addFirst((yyvsp[(1) - (2)].data));;}
    break;

  case 34:
#line 221 "/Users/dracks/Documents/Programacio/Obj-Fenix/Obj-Fenix/compilador/src/syntactic_parser.y"
    {syntactic_debug("list_propiety_concat <-- , IDENTIFIER list_propiety_concat"); (yyval.list)=(yyvsp[(3) - (3)].list);(yyval.list)->addFirst((yyvsp[(2) - (3)].data));;}
    break;

  case 35:
#line 222 "/Users/dracks/Documents/Programacio/Obj-Fenix/Obj-Fenix/compilador/src/syntactic_parser.y"
    {syntactic_debug("list_propiety_concat <-- nothing "); (yyval.list)=new clist();}
    break;

  case 36:
#line 224 "/Users/dracks/Documents/Programacio/Obj-Fenix/Obj-Fenix/compilador/src/syntactic_parser.y"
    {sym_push_scope(); tmp_num_line=num_line;;}
    break;

  case 37:
#line 225 "/Users/dracks/Documents/Programacio/Obj-Fenix/Obj-Fenix/compilador/src/syntactic_parser.y"
    {
			syntactic_debug("method_definition <-- def IDENTIFIER option_definition_parameters option_return implementation_option");
			//printf("debug_espai_actual: %d\n", espai_actual);
			sym_pop_scope();
			MethodDefinition* impl;
			//printf("$>%s<\n", $<data>2->getName().c_str());
			if ((yyvsp[(2) - (6)].data)->getSyntactic()==1){ 
				//this is a constructor
				(yyvsp[(2) - (6)].data)=insertToken(strCopy((yyvsp[(2) - (6)].data)->getName().c_str()), IDENTIFIER);
			}
			if ((yyvsp[(6) - (6)].list)!=NULL)
				impl=(yyvsp[(2) - (6)].data)->addMethodImplementation((yyvsp[(4) - (6)].list),(clist*) (yyvsp[(6) - (6)].list)->getFirst()->getContents(),(clist*) (yyvsp[(6) - (6)].list)->getLast()->getContents(), (yyvsp[(5) - (6)].data), ambitoActual, tmp_num_line);
			else
				impl=(yyvsp[(2) - (6)].data)->addMethodImplementation((yyvsp[(4) - (6)].list),NULL,NULL, (yyvsp[(5) - (6)].data), ambitoActual, tmp_num_line);
			bool found=FALSE;
			//printf("·>%s<\n", impl->getName().c_str());
			
			if (stricmp((yyvsp[(2) - (6)].data)->getName(), actualClass->getName())==0){
				impl->setAsConstructor(true);
				impl->setReturn(actualClass);
			}
		//	printf("Provant aquest element:%s - %d de la clase %s - %d\n", $<data>2->getName(),$<data>2->getSyntactic(), actualClass->getName(), actualClass->getSyntactic());
			if (actualClass->getMethodList()!=NULL){
				cnode* aux=actualClass->getMethodList()->getFirst();
				while (aux!=NULL && !found){
					SyntacticElement* tst=(SyntacticElement*)aux->getContents();
					if (strcmp(tst->getName().c_str(), (yyvsp[(2) - (6)].data)->getName().c_str())==0)
						found=TRUE;
					aux=aux->getNext();
				}
			}
			//impl->setnReturnStatments(listReturnStatments.count());
			cnode* aux=listReturnStatments.getFirst();
			while (aux!=NULL){
				((Return*) aux->getContents())->setSemantic((yyvsp[(5) - (6)].data));
				aux=aux->getNext();
			}
			listReturnStatments.clear();
			
			if (!found){
				actualClass->addMethod((yyvsp[(2) - (6)].data));
				(yyvsp[(2) - (6)].data)->setSyntactic(2);
			}
			//printf("->%s<\n", impl->getName().c_str());
		;}
    break;

  case 38:
#line 271 "/Users/dracks/Documents/Programacio/Obj-Fenix/Obj-Fenix/compilador/src/syntactic_parser.y"
    {
		(yyval.list)=(yyvsp[(3) - (4)].list);
		(yyval.list)->addFirst((yyvsp[(2) - (4)].data));
	;}
    break;

  case 39:
#line 275 "/Users/dracks/Documents/Programacio/Obj-Fenix/Obj-Fenix/compilador/src/syntactic_parser.y"
    {(yyval.list)=new clist();;}
    break;

  case 40:
#line 277 "/Users/dracks/Documents/Programacio/Obj-Fenix/Obj-Fenix/compilador/src/syntactic_parser.y"
    {
		(yyval.list)=(yyvsp[(3) - (3)].list); 
		(yyval.list)->addFirst((yyvsp[(2) - (3)].data));
	;}
    break;

  case 41:
#line 281 "/Users/dracks/Documents/Programacio/Obj-Fenix/Obj-Fenix/compilador/src/syntactic_parser.y"
    {(yyval.list)=new clist();;}
    break;

  case 42:
#line 283 "/Users/dracks/Documents/Programacio/Obj-Fenix/Obj-Fenix/compilador/src/syntactic_parser.y"
    {name_space_push(0);}
    break;

  case 43:
#line 283 "/Users/dracks/Documents/Programacio/Obj-Fenix/Obj-Fenix/compilador/src/syntactic_parser.y"
    {
		SyntacticElement* tmpSyntactic=(yyvsp[(1) - (4)].data);
		//printf("Definition_parameter: espai_actual: %d %s %p\n", espai_actual, $<data>4->getName(), $<data>4);
		name_space_pop();
		if (tmpSyntactic->getSyntactic()==0){
			tmpSyntactic->setAmbito(ambitoActual);
			tmpSyntactic->setSemantic((yyvsp[(4) - (4)].data));
			tmpSyntactic->setSyntactic(5);
			//actualClass->addPropiety(tmpSyntactic);
		} else {
			str=(char*)malloc(1024*sizeof(char));
			sprintf(str, "Redeclaration of variable %s", tmpSyntactic->getName().c_str());
		}
		(yyval.data)=tmpSyntactic;
;}
    break;

  case 44:
#line 299 "/Users/dracks/Documents/Programacio/Obj-Fenix/Obj-Fenix/compilador/src/syntactic_parser.y"
    {name_space_push(0);}
    break;

  case 45:
#line 299 "/Users/dracks/Documents/Programacio/Obj-Fenix/Obj-Fenix/compilador/src/syntactic_parser.y"
    { name_space_pop();(yyval.data)=(yyvsp[(3) - (3)].data);;}
    break;

  case 46:
#line 300 "/Users/dracks/Documents/Programacio/Obj-Fenix/Obj-Fenix/compilador/src/syntactic_parser.y"
    {(yyval.data)=NULL;;}
    break;

  case 47:
#line 303 "/Users/dracks/Documents/Programacio/Obj-Fenix/Obj-Fenix/compilador/src/syntactic_parser.y"
    {
			//printf("Data: espai_actual: %d\n", espai_actual);
			syntactic_debug("implementation_option <-- : var_declaration_list BEGIN list_sentences END");
			(yyval.list)=new clist(); 
			(yyval.list)->add((yyvsp[(2) - (5)].list)); 
			(yyval.list)->add((yyvsp[(4) - (5)].list));
		;}
    break;

  case 48:
#line 310 "/Users/dracks/Documents/Programacio/Obj-Fenix/Obj-Fenix/compilador/src/syntactic_parser.y"
    {syntactic_debug("implementation_option <-- ;"); (yyval.list)=NULL;}
    break;

  case 49:
#line 312 "/Users/dracks/Documents/Programacio/Obj-Fenix/Obj-Fenix/compilador/src/syntactic_parser.y"
    {
	cnode* aux=(yyvsp[(1) - (3)].list)->getFirst();
	while (aux!=NULL){
		(yyvsp[(3) - (3)].list)->add(aux->getContents());
		//((SyntacticElement*) aux->getContents())->setSyntactic(5);
		aux=aux->getNext();
	}
	(yyval.list)=(yyvsp[(3) - (3)].list);
	delete (yyvsp[(1) - (3)].list);
;}
    break;

  case 50:
#line 322 "/Users/dracks/Documents/Programacio/Obj-Fenix/Obj-Fenix/compilador/src/syntactic_parser.y"
    {(yyval.list)=new clist();;}
    break;

  case 51:
#line 324 "/Users/dracks/Documents/Programacio/Obj-Fenix/Obj-Fenix/compilador/src/syntactic_parser.y"
    {name_space_push(0);}
    break;

  case 52:
#line 324 "/Users/dracks/Documents/Programacio/Obj-Fenix/Obj-Fenix/compilador/src/syntactic_parser.y"
    {
	cnode* nodeAux= (yyvsp[(1) - (4)].list)->getFirst();
	name_space_pop();
	while (nodeAux!=NULL){
		tmpSyntactic=(SyntacticElement*)nodeAux->getContents();
		if (tmpSyntactic->getSyntactic()==0){
			//tmpSyntactic->setAmbito(ambitoActual);
			tmpSyntactic->setSemantic((yyvsp[(4) - (4)].data));
			tmpSyntactic->setSyntactic(5);
			//actualClass->addPropiety(tmpSyntactic);
		} else {
			str=(char*)malloc(1024*sizeof(char));
			sprintf(str, "Redeclaration of variable %s", tmpSyntactic->getName().c_str());
		}
		nodeAux=nodeAux->getNext();
	}//*/
	(yyval.list)=(yyvsp[(1) - (4)].list);
	//delete $<list>1;
;}
    break;

  case 53:
#line 347 "/Users/dracks/Documents/Programacio/Obj-Fenix/Obj-Fenix/compilador/src/syntactic_parser.y"
    {(yyval.list)=(yyvsp[(1) - (2)].list); (yyval.list)->add((yyvsp[(2) - (2)].sentence));;}
    break;

  case 54:
#line 348 "/Users/dracks/Documents/Programacio/Obj-Fenix/Obj-Fenix/compilador/src/syntactic_parser.y"
    {(yyval.list)=new clist();;}
    break;

  case 59:
#line 356 "/Users/dracks/Documents/Programacio/Obj-Fenix/Obj-Fenix/compilador/src/syntactic_parser.y"
    {
		//$<expresion>1->setParent(actualClass);
		if ((yyvsp[(2) - (3)].expresion)!=NULL){
			(yyval.sentence)=new Assignation((yyvsp[(1) - (3)].expresion), (yyvsp[(2) - (3)].expresion), num_line);
		//	$<expresion>2->setParent(actualClass);
		} else {
			(yyval.sentence)=(yyvsp[(1) - (3)].expresion);
		}
	;}
    break;

  case 60:
#line 367 "/Users/dracks/Documents/Programacio/Obj-Fenix/Obj-Fenix/compilador/src/syntactic_parser.y"
    {
	syntactic_debug("assign_sentence <-- expression := expression ;");
	//$<sentence>$=new Assignation($<expresion>1,$<expresion>3, num_line);
	(yyval.expresion)=(yyvsp[(2) - (2)].expresion);
;}
    break;

  case 61:
#line 372 "/Users/dracks/Documents/Programacio/Obj-Fenix/Obj-Fenix/compilador/src/syntactic_parser.y"
    {(yyval.expresion)=NULL;}
    break;

  case 62:
#line 374 "/Users/dracks/Documents/Programacio/Obj-Fenix/Obj-Fenix/compilador/src/syntactic_parser.y"
    {
			//AbstractExpresion* debug=$<expresion>1;
			(yyval.sentence)=new Return((yyvsp[(2) - (3)].expresion), num_line);
			listReturnStatments.add((yyval.sentence));
		;}
    break;

  case 63:
#line 381 "/Users/dracks/Documents/Programacio/Obj-Fenix/Obj-Fenix/compilador/src/syntactic_parser.y"
    {(yyval.expresion)=(yyvsp[(1) - (1)].expresion);;}
    break;

  case 64:
#line 382 "/Users/dracks/Documents/Programacio/Obj-Fenix/Obj-Fenix/compilador/src/syntactic_parser.y"
    {(yyval.expresion)=NULL;;}
    break;

  case 65:
#line 389 "/Users/dracks/Documents/Programacio/Obj-Fenix/Obj-Fenix/compilador/src/syntactic_parser.y"
    {
	Condition* tmp=new Condition((yyvsp[(2) - (6)].expresion),(yyvsp[(5) - (6)].sentence), num_line);
	cnode* aux=(yyvsp[(4) - (6)].list)->getFirst();
	while (aux!=NULL){
		tmp->addSentence((Base*) aux->getContents());
		aux=aux->getNext();
	}
	delete (yyvsp[(4) - (6)].list);
	(yyval.sentence)=tmp;
;}
    break;

  case 66:
#line 403 "/Users/dracks/Documents/Programacio/Obj-Fenix/Obj-Fenix/compilador/src/syntactic_parser.y"
    {
	Condition* tmp=new Condition((yyvsp[(2) - (5)].expresion),(yyvsp[(5) - (5)].sentence), num_line);
	cnode* aux=(yyvsp[(4) - (5)].list)->getFirst();
	while (aux!=NULL){
		tmp->addSentence((Base*) aux->getContents());
		aux=aux->getNext();
	}
	(yyval.sentence)=tmp;
	delete (yyvsp[(4) - (5)].list);
;}
    break;

  case 67:
#line 415 "/Users/dracks/Documents/Programacio/Obj-Fenix/Obj-Fenix/compilador/src/syntactic_parser.y"
    {
	Else* tmp=new Else(num_line);
	cnode* aux=(yyvsp[(3) - (3)].list)->getFirst();
	while (aux!=NULL){
		tmp->addSentence((Base*) aux->getContents());
		aux=aux->getNext();
	}
	(yyval.sentence)=tmp;
	delete (yyvsp[(3) - (3)].list);
	
;}
    break;

  case 68:
#line 426 "/Users/dracks/Documents/Programacio/Obj-Fenix/Obj-Fenix/compilador/src/syntactic_parser.y"
    {(yyval.sentence)=NULL;}
    break;

  case 73:
#line 452 "/Users/dracks/Documents/Programacio/Obj-Fenix/Obj-Fenix/compilador/src/syntactic_parser.y"
    {
	//printf("While token\n");
	While* tmp=new While((yyvsp[(2) - (5)].expresion), num_line);
	cnode* aux=(yyvsp[(4) - (5)].list)->getFirst();
	while (aux!=NULL){
		tmp->addSentence((Base*) aux->getContents());
		aux=aux->getNext();
	}
	(yyval.sentence)=tmp;
;}
    break;

  case 74:
#line 467 "/Users/dracks/Documents/Programacio/Obj-Fenix/Obj-Fenix/compilador/src/syntactic_parser.y"
    {
	/*DoWhile* tmp=new DoWhile(conditional_sentence, num_line);
	cnode* aux=$<list>4->getFirst();
	while (aux!=NULL){
		tmp->addSentence((Base*) aux->getContents());
		aux=aux->getNext();
	}
	$<sentece>$=tmp;*/
;}
    break;

  case 75:
#line 482 "/Users/dracks/Documents/Programacio/Obj-Fenix/Obj-Fenix/compilador/src/syntactic_parser.y"
    {
	Loop* tmp=new Loop(num_line);
	cnode* aux=(yyvsp[(4) - (4)].list)->getFirst();
	while (aux!=NULL){
		tmp->addSentence((Base*) aux->getContents());
		aux=aux->getNext();
	}
	(yyval.sentence)=tmp;
;}
    break;

  case 76:
#line 493 "/Users/dracks/Documents/Programacio/Obj-Fenix/Obj-Fenix/compilador/src/syntactic_parser.y"
    {(yyval.data)=(yyvsp[(1) - (1)].data);;}
    break;

  case 77:
#line 494 "/Users/dracks/Documents/Programacio/Obj-Fenix/Obj-Fenix/compilador/src/syntactic_parser.y"
    {
	(yyval.data)=(yyvsp[(1) - (1)].data); 
				(yyval.data)->setSyntactic(6);
	str=(char*) malloc(sizeof(char)*1024);
	sprintf(str,"Constant Value %s %d", (yyvsp[(1) - (1)].data)->getName().c_str(), (yyvsp[(1) - (1)].data)->getParser());
	syntactic_debug(str);
	free(str);
;}
    break;

  case 78:
#line 502 "/Users/dracks/Documents/Programacio/Obj-Fenix/Obj-Fenix/compilador/src/syntactic_parser.y"
    {(yyval.data)=new SyntacticElement((void*)(yyvsp[(2) - (3)].expresion), num_line, parsing_file);;}
    break;

  case 79:
#line 504 "/Users/dracks/Documents/Programacio/Obj-Fenix/Obj-Fenix/compilador/src/syntactic_parser.y"
    {
	//printf("Test\n");
	//if ($<data>1==NULL)
	//printf("Verifico %s %d, %d\n", $<data>1->getName(), $<data>1->getUID(), $<data>1->getSyntactic());
	// Tractar el canvi d'espais de noms per cada variable
	SyntacticElement* aux;
	if ((yyvsp[(1) - (1)].data)->getSyntactic()==1)
		aux=(yyvsp[(1) - (1)].data);
	else 
		aux=(yyvsp[(1) - (1)].data)->getSemantic();
	if (aux!=NULL){ //we know what class is defined the identifier
	//	printf("Test in it\n");
		if (aux->getSyntactic()==0){
			name_space_push(1);
		} else{
			name_space_push(aux->getSpaceName()); //we change to the spacename of this class
		}
	//	printf("It can be?\n");
	} else {
	//	printf("Un altre cami\n");
		name_space_push(1); //if we don't know what class is this variable, we only change to the undefined namespace, waiting the semantic parser, that it should solve this.
	}
;}
    break;

  case 80:
#line 527 "/Users/dracks/Documents/Programacio/Obj-Fenix/Obj-Fenix/compilador/src/syntactic_parser.y"
    {
	//printf("%s\n", $<data>1->getSemantic()->getName().c_str());
	Subpropiety* aux=new Subpropiety((yyvsp[(1) - (3)].data),num_line);
	aux->setParent(actualClass);
	aux->setExtension((Subpropiety*) (yyvsp[(3) - (3)].expresion));
	name_space_pop();
	/*if (stricmp($<data>1->getName(), "this")!=0 && $<data>1->getParser()==IDENTIFIER && $<data>1->getSyntactic()<4 && $<data>1->getSyntactic()>1){
		//printf("Good %d\n", espai_actual);
		Subpropiety* aux2=new Subpropiety(searchElem("this"),num_line);
		//printf("Shit!\n");
		aux2->setExtension(aux);
		$<expresion>$=aux2;
	} else{
		$<expresion>$=aux;
				//printf("Bad\n");
	}*/
	(yyval.expresion)=aux;
	syntactic_debug("expression <-- IDENTIFIER option_extension_expression");
;}
    break;

  case 81:
#line 589 "/Users/dracks/Documents/Programacio/Obj-Fenix/Obj-Fenix/compilador/src/syntactic_parser.y"
    {
	SyntacticElement* aux=(yyvsp[(1) - (2)].data)->getSemantic();
	if (aux!=NULL){ //we know what class is defined the identifier
		if (aux->getSyntactic()==0)
			name_space_push(1);
			else
				name_space_push(aux->getSpaceName()); //we change to the spacename of this class
			} else {
				name_space_push(1); //if we don't know what class is this variable, we only change to the undefined namespace, waiting the semantic parser, that it should solve this.
			}
	;}
    break;

  case 82:
#line 599 "/Users/dracks/Documents/Programacio/Obj-Fenix/Obj-Fenix/compilador/src/syntactic_parser.y"
    {
		name_space_pop();
		Subpropiety* aux=new Subpropiety((yyvsp[(2) - (5)].data),num_line);
		cnode* tmp=(yyvsp[(4) - (5)].list)->getFirst();
		while (tmp!=NULL){
			aux->addParamCall((AbstractExpresion*) tmp->getContents());
			tmp=tmp->getNext();
		}
		aux->setExtension((Subpropiety*) (yyvsp[(5) - (5)].expresion));
		(yyval.expresion)=aux;
		syntactic_debug("option_extension_expression <-- . IDENTIFIER option_call_parameters_parent option_expression_expression");
	;}
    break;

  case 83:
#line 611 "/Users/dracks/Documents/Programacio/Obj-Fenix/Obj-Fenix/compilador/src/syntactic_parser.y"
    {
		name_space_pop();
		//printf("%d.%d no se que cony passa '%s'\n", num_line, num_column, $<data>1->getName());
		syntactic_debug("option_extension_expression <-- IDENTIFIER option_call_parameters");
		Subpropiety* aux=new Subpropiety((yyvsp[(1) - (3)].data),num_line);
		//aux->setExtension(NULL);
		cnode* tmp=(yyvsp[(3) - (3)].list)->getFirst();
		while (tmp!=NULL){
			aux->addParamCall((AbstractExpresion*) tmp->getContents());
			tmp=tmp->getNext();
		}
		(yyval.expresion)=aux;
	;}
    break;

  case 84:
#line 624 "/Users/dracks/Documents/Programacio/Obj-Fenix/Obj-Fenix/compilador/src/syntactic_parser.y"
    {(yyval.expresion)=NULL;
		syntactic_debug("option_extension_expression <-- nothing");
;}
    break;

  case 85:
#line 630 "/Users/dracks/Documents/Programacio/Obj-Fenix/Obj-Fenix/compilador/src/syntactic_parser.y"
    {
				name_space_pop();
				//sym_pop_scope();
				(yyval.list)=(yyvsp[(4) - (5)].list);
				(yyval.list)->addFirst((yyvsp[(3) - (5)].expresion));
			;}
    break;

  case 86:
#line 636 "/Users/dracks/Documents/Programacio/Obj-Fenix/Obj-Fenix/compilador/src/syntactic_parser.y"
    {(yyval.list)=new clist();;}
    break;

  case 87:
#line 638 "/Users/dracks/Documents/Programacio/Obj-Fenix/Obj-Fenix/compilador/src/syntactic_parser.y"
    {
			name_space_push(actualClass->getSpaceName());
			//printf("%d debug namespace (%s)-> %d\n", num_line, actualClass->getName(), actualClass->getUID());
			//sym_push_scope(actualClass->getUID());
			//sym_push_scope();
;}
    break;

  case 88:
#line 645 "/Users/dracks/Documents/Programacio/Obj-Fenix/Obj-Fenix/compilador/src/syntactic_parser.y"
    {
	//name_space_pop();
	syntactic_debug("option_call_parameters <-- 2/2");
	//sym_pop_scope();
	(yyval.list)=new clist();
	(yyval.list)->addFirst((yyvsp[(1) - (1)].expresion));
;}
    break;

  case 89:
#line 652 "/Users/dracks/Documents/Programacio/Obj-Fenix/Obj-Fenix/compilador/src/syntactic_parser.y"
    {(yyval.list)=new clist();}
    break;

  case 90:
#line 654 "/Users/dracks/Documents/Programacio/Obj-Fenix/Obj-Fenix/compilador/src/syntactic_parser.y"
    {
	(yyval.list)=(yyvsp[(3) - (3)].list);
	(yyval.list)->addFirst((yyvsp[(2) - (3)].expresion));
;}
    break;

  case 91:
#line 658 "/Users/dracks/Documents/Programacio/Obj-Fenix/Obj-Fenix/compilador/src/syntactic_parser.y"
    {(yyval.list)=new clist();;}
    break;


/* Line 1267 of yacc.c.  */
#line 2360 "/Users/dracks/Documents/Programacio/Obj-Fenix/Obj-Fenix/compilador/build/syntactic_parser.cpp"
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
      /* If just tried and failed to reuse look-ahead token after an
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

  /* Else will try to reuse look-ahead token after shifting the error
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

  if (yyn == YYFINAL)
    YYACCEPT;

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

#ifndef yyoverflow
/*-------------------------------------------------.
| yyexhaustedlab -- memory exhaustion comes here.  |
`-------------------------------------------------*/
yyexhaustedlab:
  yyerror (YY_("memory exhausted"));
  yyresult = 2;
  /* Fall through.  */
#endif

yyreturn:
  if (yychar != YYEOF && yychar != YYEMPTY)
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


#line 673 "/Users/dracks/Documents/Programacio/Obj-Fenix/Obj-Fenix/compilador/src/syntactic_parser.y"





