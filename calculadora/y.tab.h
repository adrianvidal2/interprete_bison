/* A Bison parser, made by GNU Bison 3.7.6.  */

/* Bison interface for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2015, 2018-2021 Free Software Foundation,
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
   along with this program.  If not, see <https://www.gnu.org/licenses/>.  */

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

/* DO NOT RELY ON FEATURES THAT ARE NOT DOCUMENTED in the manual,
   especially those whose name start with YY_ or yy_.  They are
   private implementation details that can be changed or removed.  */

#ifndef YY_YY_Y_TAB_H_INCLUDED
# define YY_YY_Y_TAB_H_INCLUDED
/* Debug traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif
#if YYDEBUG
extern int yydebug;
#endif

/* Token kinds.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
  enum yytokentype
  {
    YYEMPTY = -2,
    YYEOF = 0,                     /* "end of file"  */
    YYerror = 256,                 /* error  */
    YYUNDEF = 257,                 /* "invalid token"  */
    NUMERO = 258,                  /* NUMERO  */
    IDENTIFICADOR = 259,           /* IDENTIFICADOR  */
    OP_ASIGNACION_COD = 260,       /* OP_ASIGNACION_COD  */
    OP_MAS_MAS_COD = 261,          /* OP_MAS_MAS_COD  */
    OP_MENOS_MENOS_COD = 262,      /* OP_MENOS_MENOS_COD  */
    OP_SUMA_IGUAL_COD = 263,       /* OP_SUMA_IGUAL_COD  */
    OP_RESTA_IGUAL_COD = 264,      /* OP_RESTA_IGUAL_COD  */
    OP_MULT_IGUAL_COD = 265,       /* OP_MULT_IGUAL_COD  */
    OP_DIV_IGUAL_COD = 266,        /* OP_DIV_IGUAL_COD  */
    OP_MAIOR_IGUAL_COD = 267,      /* OP_MAIOR_IGUAL_COD  */
    OP_MENOR_IGUAL_COD = 268,      /* OP_MENOR_IGUAL_COD  */
    OP_DISTINTO_COD = 269,         /* OP_DISTINTO_COD  */
    OP_IGUAL_IGUAL_COD = 270,      /* OP_IGUAL_IGUAL_COD  */
    TABOA = 271,                   /* TABOA  */
    AXUDA = 272,                   /* AXUDA  */
    WORKSPACE = 273,               /* WORKSPACE  */
    ELIMINAR = 274,                /* ELIMINAR  */
    IMPORT = 275,                  /* IMPORT  */
    LOAD = 276,                    /* LOAD  */
    SAIR = 277,                    /* SAIR  */
    ARQUIVO = 278,                 /* ARQUIVO  */
    LIBRERIA = 279,                /* LIBRERIA  */
    FIN_FICHEIRO = 280,            /* FIN_FICHEIRO  */
    NEGACION = 281                 /* NEGACION  */
  };
  typedef enum yytokentype yytoken_kind_t;
#endif
/* Token kinds.  */
#define YYEMPTY -2
#define YYEOF 0
#define YYerror 256
#define YYUNDEF 257
#define NUMERO 258
#define IDENTIFICADOR 259
#define OP_ASIGNACION_COD 260
#define OP_MAS_MAS_COD 261
#define OP_MENOS_MENOS_COD 262
#define OP_SUMA_IGUAL_COD 263
#define OP_RESTA_IGUAL_COD 264
#define OP_MULT_IGUAL_COD 265
#define OP_DIV_IGUAL_COD 266
#define OP_MAIOR_IGUAL_COD 267
#define OP_MENOR_IGUAL_COD 268
#define OP_DISTINTO_COD 269
#define OP_IGUAL_IGUAL_COD 270
#define TABOA 271
#define AXUDA 272
#define WORKSPACE 273
#define ELIMINAR 274
#define IMPORT 275
#define LOAD 276
#define SAIR 277
#define ARQUIVO 278
#define LIBRERIA 279
#define FIN_FICHEIRO 280
#define NEGACION 281

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
union YYSTYPE
{
#line 17 "analizadorSintactico.y"

double valor;   /*Para devolver números*/
char *cadea;    /*Para devolver cadeas*/

#line 124 "y.tab.h"

};
typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_Y_TAB_H_INCLUDED  */
