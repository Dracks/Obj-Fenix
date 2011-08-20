/* A Bison parser, made by GNU Bison 2.3.  */

/* Skeleton interface for Bison's Yacc-like parsers in C

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




#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef union YYSTYPE
#line 42 "/Users/Dracks/Documents/Programacio/Obj-Fenix/Obj-Fenix/compilador_2/src/syntactic_parser.y"
{

	struct SyntacticElement* data;
	struct clist* list;
	struct AbstractExpresion* expresion;
	struct Base*  sentence;
	bool boolean;
}
/* Line 1529 of yacc.c.  */
#line 142 "/Users/Dracks/Documents/Programacio/Obj-Fenix/Obj-Fenix/compilador_2/build/syntactic_parser.hpp"
	YYSTYPE;
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
# define YYSTYPE_IS_TRIVIAL 1
#endif

extern YYSTYPE yylval;

