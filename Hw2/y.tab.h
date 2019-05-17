/* A Bison parser, made by GNU Bison 3.0.4.  */

/* Bison interface for Yacc-like parsers in C

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
#line 9 "parse.y" /* yacc.c:1909  */

	int ival;
	double dval;
	int bval;
	char* cval;
	struct SymbolTable* tval;

#line 166 "y.tab.h" /* yacc.c:1909  */
};

typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_Y_TAB_H_INCLUDED  */
