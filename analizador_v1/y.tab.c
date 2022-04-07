/* A Bison parser, made by GNU Bison 3.7.6.  */

/* Bison implementation for Yacc-like parsers in C

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

/* C LALR(1) parser skeleton written by Richard Stallman, by
   simplifying the original so-called "semantic" parser.  */

/* DO NOT RELY ON FEATURES THAT ARE NOT DOCUMENTED in the manual,
   especially those whose name start with YY_ or yy_.  They are
   private implementation details that can be changed or removed.  */

/* All symbols defined below should begin with yy or YY, to avoid
   infringing on user name space.  This should be done even for local
   variables, as they might otherwise be expanded by user macros.
   There are some unavoidable exceptions within include files to
   define necessary library symbols; they are noted "INFRINGES ON
   USER NAME SPACE" below.  */

/* Identify Bison output, and Bison version.  */
#define YYBISON 30706

/* Bison version string.  */
#define YYBISON_VERSION "3.7.6"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1




/* First part of user prologue.  */
#line 1 "analizadorSintactico.y"

#include <stdio.h>
#include <math.h>
#include <string.h>
#include "definicions.h"
#include "taboaSimbolos.h"
#include "xestionErros.h"
#include "lex.yy.h"
extern int yylex();
void yyerror(char* s);
void cambiarGlobal();
int global = 0;

#line 85 "y.tab.c"

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

/* Use api.header.include to #include this header
   instead of duplicating it here.  */
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
    ARQUIVO = 271,                 /* ARQUIVO  */
    AXUDA = 272,                   /* AXUDA  */
    TABOA = 273,                   /* TABOA  */
    SAIR = 274,                    /* SAIR  */
    WORKSPACE = 275,               /* WORKSPACE  */
    ELIMINAR = 276,                /* ELIMINAR  */
    ABRIR = 277,                   /* ABRIR  */
    FIN_FICHEIRO = 278,            /* FIN_FICHEIRO  */
    NEGACION = 279                 /* NEGACION  */
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
#define ARQUIVO 271
#define AXUDA 272
#define TABOA 273
#define SAIR 274
#define WORKSPACE 275
#define ELIMINAR 276
#define ABRIR 277
#define FIN_FICHEIRO 278
#define NEGACION 279

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
union YYSTYPE
{
#line 16 "analizadorSintactico.y"

double valor;   /*Para devolver números*/
char *cadea;    /*Para devolver cadeas*/

#line 191 "y.tab.c"

};
typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_Y_TAB_H_INCLUDED  */
/* Symbol kind.  */
enum yysymbol_kind_t
{
  YYSYMBOL_YYEMPTY = -2,
  YYSYMBOL_YYEOF = 0,                      /* "end of file"  */
  YYSYMBOL_YYerror = 1,                    /* error  */
  YYSYMBOL_YYUNDEF = 2,                    /* "invalid token"  */
  YYSYMBOL_NUMERO = 3,                     /* NUMERO  */
  YYSYMBOL_IDENTIFICADOR = 4,              /* IDENTIFICADOR  */
  YYSYMBOL_OP_ASIGNACION_COD = 5,          /* OP_ASIGNACION_COD  */
  YYSYMBOL_OP_MAS_MAS_COD = 6,             /* OP_MAS_MAS_COD  */
  YYSYMBOL_OP_MENOS_MENOS_COD = 7,         /* OP_MENOS_MENOS_COD  */
  YYSYMBOL_OP_SUMA_IGUAL_COD = 8,          /* OP_SUMA_IGUAL_COD  */
  YYSYMBOL_OP_RESTA_IGUAL_COD = 9,         /* OP_RESTA_IGUAL_COD  */
  YYSYMBOL_OP_MULT_IGUAL_COD = 10,         /* OP_MULT_IGUAL_COD  */
  YYSYMBOL_OP_DIV_IGUAL_COD = 11,          /* OP_DIV_IGUAL_COD  */
  YYSYMBOL_OP_MAIOR_IGUAL_COD = 12,        /* OP_MAIOR_IGUAL_COD  */
  YYSYMBOL_OP_MENOR_IGUAL_COD = 13,        /* OP_MENOR_IGUAL_COD  */
  YYSYMBOL_OP_DISTINTO_COD = 14,           /* OP_DISTINTO_COD  */
  YYSYMBOL_OP_IGUAL_IGUAL_COD = 15,        /* OP_IGUAL_IGUAL_COD  */
  YYSYMBOL_ARQUIVO = 16,                   /* ARQUIVO  */
  YYSYMBOL_AXUDA = 17,                     /* AXUDA  */
  YYSYMBOL_TABOA = 18,                     /* TABOA  */
  YYSYMBOL_SAIR = 19,                      /* SAIR  */
  YYSYMBOL_WORKSPACE = 20,                 /* WORKSPACE  */
  YYSYMBOL_ELIMINAR = 21,                  /* ELIMINAR  */
  YYSYMBOL_ABRIR = 22,                     /* ABRIR  */
  YYSYMBOL_FIN_FICHEIRO = 23,              /* FIN_FICHEIRO  */
  YYSYMBOL_24_ = 24,                       /* '-'  */
  YYSYMBOL_25_ = 25,                       /* '+'  */
  YYSYMBOL_26_ = 26,                       /* '*'  */
  YYSYMBOL_27_ = 27,                       /* '/'  */
  YYSYMBOL_28_ = 28,                       /* '>'  */
  YYSYMBOL_29_ = 29,                       /* '<'  */
  YYSYMBOL_NEGACION = 30,                  /* NEGACION  */
  YYSYMBOL_31_ = 31,                       /* '^'  */
  YYSYMBOL_32_n_ = 32,                     /* '\n'  */
  YYSYMBOL_33_ = 33,                       /* ';'  */
  YYSYMBOL_34_ = 34,                       /* '('  */
  YYSYMBOL_35_ = 35,                       /* ')'  */
  YYSYMBOL_36_ = 36,                       /* ','  */
  YYSYMBOL_YYACCEPT = 37,                  /* $accept  */
  YYSYMBOL_input = 38,                     /* input  */
  YYSYMBOL_line = 39,                      /* line  */
  YYSYMBOL_exp = 40,                       /* exp  */
  YYSYMBOL_declaracion = 41,               /* declaracion  */
  YYSYMBOL_comparacion = 42,               /* comparacion  */
  YYSYMBOL_calculo = 43,                   /* calculo  */
  YYSYMBOL_metodo = 44                     /* metodo  */
};
typedef enum yysymbol_kind_t yysymbol_kind_t;




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

/* Work around bug in HP-UX 11.23, which defines these macros
   incorrectly for preprocessor constants.  This workaround can likely
   be removed in 2023, as HPE has promised support for HP-UX 11.23
   (aka HP-UX 11i v2) only through the end of 2022; see Table 2 of
   <https://h20195.www2.hpe.com/V2/getpdf.aspx/4AA4-7673ENW.pdf>.  */
#ifdef __hpux
# undef UINT_LEAST8_MAX
# undef UINT_LEAST16_MAX
# define UINT_LEAST8_MAX 255
# define UINT_LEAST16_MAX 65535
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
typedef yytype_int8 yy_state_t;

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
# define YY_USE(E) ((void) (E))
#else
# define YY_USE(E) /* empty */
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

#if !defined yyoverflow

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
#endif /* !defined yyoverflow */

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
#define YYFINAL  2
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   172

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  37
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  8
/* YYNRULES -- Number of rules.  */
#define YYNRULES  38
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  63

/* YYMAXUTOK -- Last valid token kind.  */
#define YYMAXUTOK   279


/* YYTRANSLATE(TOKEN-NUM) -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex, with out-of-bounds checking.  */
#define YYTRANSLATE(YYX)                                \
  (0 <= (YYX) && (YYX) <= YYMAXUTOK                     \
   ? YY_CAST (yysymbol_kind_t, yytranslate[YYX])        \
   : YYSYMBOL_YYUNDEF)

/* YYTRANSLATE[TOKEN-NUM] -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex.  */
static const yytype_int8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
      32,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
      34,    35,    26,    25,    36,    24,     2,    27,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,    33,
      29,     2,    28,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,    31,     2,     2,     2,     2,     2,
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
      15,    16,    17,    18,    19,    20,    21,    22,    23,    30
};

#if YYDEBUG
  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_int16 yyrline[] =
{
       0,    68,    68,    69,    73,    77,    88,    89,    92,    93,
      94,    95,    96,   115,   116,   117,   118,   119,   120,   125,
     138,   157,   175,   193,   211,   229,   252,   262,   271,   280,
     289,   299,   310,   318,   326,   334,   346,   357,   371
};
#endif

/** Accessing symbol of state STATE.  */
#define YY_ACCESSING_SYMBOL(State) YY_CAST (yysymbol_kind_t, yystos[State])

#if YYDEBUG || 0
/* The user-facing name of the symbol whose (internal) number is
   YYSYMBOL.  No bounds checking.  */
static const char *yysymbol_name (yysymbol_kind_t yysymbol) YY_ATTRIBUTE_UNUSED;

/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "\"end of file\"", "error", "\"invalid token\"", "NUMERO",
  "IDENTIFICADOR", "OP_ASIGNACION_COD", "OP_MAS_MAS_COD",
  "OP_MENOS_MENOS_COD", "OP_SUMA_IGUAL_COD", "OP_RESTA_IGUAL_COD",
  "OP_MULT_IGUAL_COD", "OP_DIV_IGUAL_COD", "OP_MAIOR_IGUAL_COD",
  "OP_MENOR_IGUAL_COD", "OP_DISTINTO_COD", "OP_IGUAL_IGUAL_COD", "ARQUIVO",
  "AXUDA", "TABOA", "SAIR", "WORKSPACE", "ELIMINAR", "ABRIR",
  "FIN_FICHEIRO", "'-'", "'+'", "'*'", "'/'", "'>'", "'<'", "NEGACION",
  "'^'", "'\\n'", "';'", "'('", "')'", "','", "$accept", "input", "line",
  "exp", "declaracion", "comparacion", "calculo", "metodo", YY_NULLPTR
};

static const char *
yysymbol_name (yysymbol_kind_t yysymbol)
{
  return yytname[yysymbol];
}
#endif

#ifdef YYPRINT
/* YYTOKNUM[NUM] -- (External) token number corresponding to the
   (internal) symbol number NUM (which must be that of a token).  */
static const yytype_int16 yytoknum[] =
{
       0,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   277,   278,    45,    43,    42,    47,    62,    60,
     279,    94,    10,    59,    40,    41,    44
};
#endif

#define YYPACT_NINF (-16)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-1)

#define yytable_value_is_error(Yyn) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
     -16,    31,   -16,   -16,    68,   -16,   -16,   -16,   -15,   -16,
      38,   -16,    38,   -16,   117,   -16,   -16,   -16,   -16,    38,
     -16,   -16,    38,    38,    38,    38,    38,   -16,   -16,    81,
      38,    38,    38,    38,    38,    38,    38,    38,    38,    38,
     -16,   -16,   139,   143,   143,    75,    75,    56,   -16,   -16,
     -16,   -16,   -16,   143,   143,    75,    75,   -16,   -16,   -16,
      38,    99,   -16
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_int8 yydefact[] =
{
       2,     0,     1,     8,    12,     9,    10,    11,     0,     7,
       0,     4,     0,     3,     0,    15,    14,    17,    16,     0,
      20,    21,     0,     0,     0,     0,     0,    18,    36,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       5,     6,    19,    22,    23,    24,    25,     0,    13,    31,
      30,    29,    28,    33,    32,    34,    35,    26,    27,    37,
       0,     0,    38
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int8 yypgoto[] =
{
     -16,   -16,   -16,   -10,   -16,   -16,   -16,   -16
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int8 yydefgoto[] =
{
       0,     1,    13,    14,    15,    16,    17,    18
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int8 yytable[] =
{
      28,    27,    29,     0,     0,     0,     0,     0,     0,    42,
       0,     0,    43,    44,    45,    46,    47,     0,     0,     0,
      49,    50,    51,    52,    53,    54,    55,    56,    57,    58,
       0,     2,     0,     0,     3,     4,     0,     0,     0,     0,
       0,     3,     4,     0,     0,     0,     0,     0,     0,     5,
      61,     6,     7,     8,     9,    10,     5,     0,     6,     7,
       8,     0,    10,    11,     0,    12,     0,     0,    30,    31,
      32,    33,    12,    19,    20,    21,    22,    23,    24,    25,
      34,    35,    36,    37,    38,    39,     0,    30,    31,    32,
      33,    59,    60,    30,    31,    32,    33,     0,     0,     0,
       0,     0,    26,    38,    39,    34,    35,    36,    37,    38,
      39,    30,    31,    32,    33,     0,    48,     0,     0,     0,
       0,     0,     0,    34,    35,    36,    37,    38,    39,    30,
      31,    32,    33,     0,    62,     0,     0,     0,     0,     0,
       0,    34,    35,    36,    37,    38,    39,     0,     0,    40,
      41,    30,    31,    32,    33,    30,    31,    32,    33,     0,
       0,     0,     0,    34,    35,    36,    37,    38,    39,    36,
      37,    38,    39
};

static const yytype_int8 yycheck[] =
{
      10,    16,    12,    -1,    -1,    -1,    -1,    -1,    -1,    19,
      -1,    -1,    22,    23,    24,    25,    26,    -1,    -1,    -1,
      30,    31,    32,    33,    34,    35,    36,    37,    38,    39,
      -1,     0,    -1,    -1,     3,     4,    -1,    -1,    -1,    -1,
      -1,     3,     4,    -1,    -1,    -1,    -1,    -1,    -1,    18,
      60,    20,    21,    22,    23,    24,    18,    -1,    20,    21,
      22,    -1,    24,    32,    -1,    34,    -1,    -1,    12,    13,
      14,    15,    34,     5,     6,     7,     8,     9,    10,    11,
      24,    25,    26,    27,    28,    29,    -1,    12,    13,    14,
      15,    35,    36,    12,    13,    14,    15,    -1,    -1,    -1,
      -1,    -1,    34,    28,    29,    24,    25,    26,    27,    28,
      29,    12,    13,    14,    15,    -1,    35,    -1,    -1,    -1,
      -1,    -1,    -1,    24,    25,    26,    27,    28,    29,    12,
      13,    14,    15,    -1,    35,    -1,    -1,    -1,    -1,    -1,
      -1,    24,    25,    26,    27,    28,    29,    -1,    -1,    32,
      33,    12,    13,    14,    15,    12,    13,    14,    15,    -1,
      -1,    -1,    -1,    24,    25,    26,    27,    28,    29,    26,
      27,    28,    29
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_int8 yystos[] =
{
       0,    38,     0,     3,     4,    18,    20,    21,    22,    23,
      24,    32,    34,    39,    40,    41,    42,    43,    44,     5,
       6,     7,     8,     9,    10,    11,    34,    16,    40,    40,
      12,    13,    14,    15,    24,    25,    26,    27,    28,    29,
      32,    33,    40,    40,    40,    40,    40,    40,    35,    40,
      40,    40,    40,    40,    40,    40,    40,    40,    40,    35,
      36,    40,    35
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_int8 yyr1[] =
{
       0,    37,    38,    38,    39,    39,    39,    39,    40,    40,
      40,    40,    40,    40,    40,    40,    40,    40,    40,    41,
      41,    41,    41,    41,    41,    41,    42,    42,    42,    42,
      42,    42,    43,    43,    43,    43,    43,    44,    44
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     0,     2,     1,     2,     2,     1,     1,     1,
       1,     1,     1,     3,     1,     1,     1,     1,     2,     3,
       2,     2,     3,     3,     3,     3,     3,     3,     3,     3,
       3,     3,     3,     3,     3,     3,     2,     4,     6
};


enum { YYENOMEM = -2 };

#define yyerrok         (yyerrstatus = 0)
#define yyclearin       (yychar = YYEMPTY)

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

/* Backward compatibility with an undocumented macro.
   Use YYerror or YYUNDEF. */
#define YYERRCODE YYUNDEF


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
# ifndef YY_LOCATION_PRINT
#  define YY_LOCATION_PRINT(File, Loc) ((void) 0)
# endif


# define YY_SYMBOL_PRINT(Title, Kind, Value, Location)                    \
do {                                                                      \
  if (yydebug)                                                            \
    {                                                                     \
      YYFPRINTF (stderr, "%s ", Title);                                   \
      yy_symbol_print (stderr,                                            \
                  Kind, Value); \
      YYFPRINTF (stderr, "\n");                                           \
    }                                                                     \
} while (0)


/*-----------------------------------.
| Print this symbol's value on YYO.  |
`-----------------------------------*/

static void
yy_symbol_value_print (FILE *yyo,
                       yysymbol_kind_t yykind, YYSTYPE const * const yyvaluep)
{
  FILE *yyoutput = yyo;
  YY_USE (yyoutput);
  if (!yyvaluep)
    return;
# ifdef YYPRINT
  if (yykind < YYNTOKENS)
    YYPRINT (yyo, yytoknum[yykind], *yyvaluep);
# endif
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YY_USE (yykind);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}


/*---------------------------.
| Print this symbol on YYO.  |
`---------------------------*/

static void
yy_symbol_print (FILE *yyo,
                 yysymbol_kind_t yykind, YYSTYPE const * const yyvaluep)
{
  YYFPRINTF (yyo, "%s %s (",
             yykind < YYNTOKENS ? "token" : "nterm", yysymbol_name (yykind));

  yy_symbol_value_print (yyo, yykind, yyvaluep);
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
yy_reduce_print (yy_state_t *yyssp, YYSTYPE *yyvsp,
                 int yyrule)
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
                       YY_ACCESSING_SYMBOL (+yyssp[yyi + 1 - yynrhs]),
                       &yyvsp[(yyi + 1) - (yynrhs)]);
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
# define YYDPRINTF(Args) ((void) 0)
# define YY_SYMBOL_PRINT(Title, Kind, Value, Location)
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






/*-----------------------------------------------.
| Release the memory associated to this symbol.  |
`-----------------------------------------------*/

static void
yydestruct (const char *yymsg,
            yysymbol_kind_t yykind, YYSTYPE *yyvaluep)
{
  YY_USE (yyvaluep);
  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yykind, yyvaluep, yylocationp);

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YY_USE (yykind);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}


/* Lookahead token kind.  */
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
    yy_state_fast_t yystate = 0;
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus = 0;

    /* Refer to the stacks through separate pointers, to allow yyoverflow
       to reallocate them elsewhere.  */

    /* Their size.  */
    YYPTRDIFF_T yystacksize = YYINITDEPTH;

    /* The state stack: array, bottom, top.  */
    yy_state_t yyssa[YYINITDEPTH];
    yy_state_t *yyss = yyssa;
    yy_state_t *yyssp = yyss;

    /* The semantic value stack: array, bottom, top.  */
    YYSTYPE yyvsa[YYINITDEPTH];
    YYSTYPE *yyvs = yyvsa;
    YYSTYPE *yyvsp = yyvs;

  int yyn;
  /* The return value of yyparse.  */
  int yyresult;
  /* Lookahead symbol kind.  */
  yysymbol_kind_t yytoken = YYSYMBOL_YYEMPTY;
  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;



#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N))

  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  YYDPRINTF ((stderr, "Starting parse\n"));

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
  YY_STACK_PRINT (yyss, yyssp);

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
#  undef YYSTACK_RELOCATE
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

  /* YYCHAR is either empty, or end-of-input, or a valid lookahead.  */
  if (yychar == YYEMPTY)
    {
      YYDPRINTF ((stderr, "Reading a token\n"));
      yychar = yylex ();
    }

  if (yychar <= YYEOF)
    {
      yychar = YYEOF;
      yytoken = YYSYMBOL_YYEOF;
      YYDPRINTF ((stderr, "Now at end of input.\n"));
    }
  else if (yychar == YYerror)
    {
      /* The scanner already issued an error message, process directly
         to error recovery.  But do not keep the error token as
         lookahead, it is too special and may lead us to an endless
         loop in error recovery. */
      yychar = YYUNDEF;
      yytoken = YYSYMBOL_YYerror;
      goto yyerrlab1;
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
  case 2: /* input: %empty  */
#line 68 "analizadorSintactico.y"
       {printf(">> ");}
#line 1278 "y.tab.c"
    break;

  case 4: /* line: '\n'  */
#line 73 "analizadorSintactico.y"
           {
            if(!global)
                printf(">> ");
        }
#line 1287 "y.tab.c"
    break;

  case 5: /* line: exp '\n'  */
#line 77 "analizadorSintactico.y"
                   {
            if(!global){
                if(!isnan((yyvsp[-1].valor))){
                        printf("%.10g\n>> ",(yyvsp[-1].valor));
                    }else
                        printf(">> ");
            } else {
                if(!isnan((yyvsp[-1].valor)))
                        printf("%.10g\n",(yyvsp[-1].valor));
            }
        }
#line 1303 "y.tab.c"
    break;

  case 6: /* line: exp ';'  */
#line 88 "analizadorSintactico.y"
                  {printf("%.10g\n", (yyvsp[-1].valor));}
#line 1309 "y.tab.c"
    break;

  case 7: /* line: FIN_FICHEIRO  */
#line 89 "analizadorSintactico.y"
                       {printf(">> ");}
#line 1315 "y.tab.c"
    break;

  case 8: /* exp: NUMERO  */
#line 92 "analizadorSintactico.y"
               {(yyval.valor) = (yyvsp[0].valor);}
#line 1321 "y.tab.c"
    break;

  case 9: /* exp: TABOA  */
#line 93 "analizadorSintactico.y"
             {imprimirTaboa(); (yyval.valor) = NAN;}
#line 1327 "y.tab.c"
    break;

  case 10: /* exp: WORKSPACE  */
#line 94 "analizadorSintactico.y"
                 {imprimirWorkspace(); (yyval.valor) = NAN;}
#line 1333 "y.tab.c"
    break;

  case 11: /* exp: ELIMINAR  */
#line 95 "analizadorSintactico.y"
                {eliminarWorkspace(); (yyval.valor) = NAN;}
#line 1339 "y.tab.c"
    break;

  case 12: /* exp: IDENTIFICADOR  */
#line 96 "analizadorSintactico.y"
                    {
        if(buscarNumero((yyvsp[0].cadea), VARIABLE_COD) || buscarNumero((yyvsp[0].cadea), CONSTANTE_COD)){
            if (is_inicializada((yyvsp[0].cadea)) == 1) (yyval.valor) = recuperarValor((yyvsp[0].cadea));
            else (yyval.valor) = NAN;

        } else {
            if(buscarNumero((yyvsp[0].cadea), FUNCION_COD)){
                  (yyval.valor) = NAN;
                  yyerror("[ERROR] Trátase dunha función");
            } else {
                crearVariable((yyvsp[0].cadea));
                (yyval.valor) = NAN;
               yyerror("[WARNING] A variable é creada sen inicializar");
            }
        }


        free((yyvsp[0].cadea));
    }
#line 1363 "y.tab.c"
    break;

  case 13: /* exp: '(' exp ')'  */
#line 115 "analizadorSintactico.y"
                  {(yyval.valor) = (yyvsp[-1].valor);}
#line 1369 "y.tab.c"
    break;

  case 18: /* exp: ABRIR ARQUIVO  */
#line 120 "analizadorSintactico.y"
                    {
                            apertura_arquivo((yyvsp[0].cadea)); free((yyvsp[0].cadea)); cambiarGlobal(); (yyval.valor) = NAN;
                    }
#line 1377 "y.tab.c"
    break;

  case 19: /* declaracion: IDENTIFICADOR OP_ASIGNACION_COD exp  */
#line 125 "analizadorSintactico.y"
                                                 {
                if(buscarNumero((yyvsp[-2].cadea), CONSTANTE_COD)){
                    yyerror("[ERROR] Non se pode redeclarar unha constante");
                } else {
                    if(insertarVariable((yyvsp[-2].cadea),(yyvsp[0].valor)) == FUNCION_COD){
                       (yyval.valor) = NAN;
                       yyerror("[ERROR] Non se pode redeclarar unha función");
                    } else {
                        (yyval.valor) = (yyvsp[0].valor);
                    }
                }
                free((yyvsp[-2].cadea));
             }
#line 1395 "y.tab.c"
    break;

  case 20: /* declaracion: IDENTIFICADOR OP_MAS_MAS_COD  */
#line 138 "analizadorSintactico.y"
                                            {
                 if (buscarNumero((yyvsp[-1].cadea),CONSTANTE_COD)){
                     (yyval.valor) = recuperarValor((yyvsp[-1].cadea)) + 1;
                 }else if (buscarNumero((yyvsp[-1].cadea),VARIABLE_COD)){
                     if(is_inicializada((yyvsp[-1].cadea)) == 1){
                           (yyval.valor) = recuperarValor((yyvsp[-1].cadea)) + 1;
                           insertarVariable((yyvsp[-1].cadea),(yyval.valor));
                     } else {
                        (yyval.valor) = NAN;
                         yyerror("[ERROR] Non se pode incrementar unha variable non inicializada");
                     }

                 }else {
                     (yyval.valor) = NAN;
                     yyerror("[ERROR] Non se atopa o identificador");
                 }

                 free((yyvsp[-1].cadea));
             }
#line 1419 "y.tab.c"
    break;

  case 21: /* declaracion: IDENTIFICADOR OP_MENOS_MENOS_COD  */
#line 157 "analizadorSintactico.y"
                                                {
                 if (buscarNumero((yyvsp[-1].cadea),CONSTANTE_COD)){
                     (yyval.valor) = recuperarValor((yyvsp[-1].cadea)) - 1;
                 }else if (buscarNumero((yyvsp[-1].cadea),VARIABLE_COD)){
                     if (is_inicializada((yyvsp[-1].cadea)) == 1){
                         (yyval.valor) = recuperarValor((yyvsp[-1].cadea)) - 1;
                         insertarVariable((yyvsp[-1].cadea),(yyval.valor));
                     } else {
                         (yyval.valor) = NAN;
                         yyerror("[ERROR] Non se pode decrementar unha variable non inicializada");
                     }
                 }else {
                     (yyval.valor) = NAN;
                     yyerror("[ERROR] Non se atopa o identificador");
                 }

                 free((yyvsp[-1].cadea));
             }
#line 1442 "y.tab.c"
    break;

  case 22: /* declaracion: IDENTIFICADOR OP_SUMA_IGUAL_COD exp  */
#line 175 "analizadorSintactico.y"
                                                   {
                 if (buscarNumero((yyvsp[-2].cadea),CONSTANTE_COD)){
                     yyerror("[ERROR] Non se pode asignar a unha constante");
                 }else if (buscarNumero((yyvsp[-2].cadea),VARIABLE_COD)){
                     if(is_inicializada((yyvsp[-2].cadea)) == 1){
                         (yyval.valor) = recuperarValor((yyvsp[-2].cadea)) + (yyvsp[0].valor);
                         insertarVariable((yyvsp[-2].cadea),(yyval.valor));
                     } else {
                        (yyval.valor) = NAN;
                         yyerror("[ERROR] Non se pode asignar a unha variable non inicializada");
                     }
                 }else {
                     (yyval.valor) = NAN;
                     yyerror("[ERROR] Non se atopa o identificador");
                 }

                 free((yyvsp[-2].cadea));
             }
#line 1465 "y.tab.c"
    break;

  case 23: /* declaracion: IDENTIFICADOR OP_RESTA_IGUAL_COD exp  */
#line 193 "analizadorSintactico.y"
                                                    {
                 if (buscarNumero((yyvsp[-2].cadea),CONSTANTE_COD)){
                     yyerror("[ERROR] Non se pode asignar a unha constante");
                 }else if (buscarNumero((yyvsp[-2].cadea),VARIABLE_COD)){
                     if (is_inicializada((yyvsp[-2].cadea)) == 1){
                         (yyval.valor) = recuperarValor((yyvsp[-2].cadea)) - (yyvsp[0].valor);
                         insertarVariable((yyvsp[-2].cadea),(yyval.valor));
                     } else {
                        (yyval.valor) = NAN;
                         yyerror("[ERROR] Non se pode asignar a unha variable non inicializada");
                     }
                 }else {
                       (yyval.valor) = NAN;
                     yyerror("[ERROR] Non se atopa o identificador");
                 }

                 free((yyvsp[-2].cadea));
             }
#line 1488 "y.tab.c"
    break;

  case 24: /* declaracion: IDENTIFICADOR OP_MULT_IGUAL_COD exp  */
#line 211 "analizadorSintactico.y"
                                                   {
                 if (buscarNumero((yyvsp[-2].cadea),CONSTANTE_COD)){
                     yyerror("[ERROR] Non se pode asignar a unha constante");
                 }else if (buscarNumero((yyvsp[-2].cadea),VARIABLE_COD)){
                     if (is_inicializada((yyvsp[-2].cadea)) == 1){
                         (yyval.valor) = recuperarValor((yyvsp[-2].cadea)) * (yyvsp[0].valor);
                         insertarVariable((yyvsp[-2].cadea),(yyval.valor));
                     } else {
                        (yyval.valor) = NAN;
                         yyerror("[ERROR] Non se pode asignar a unha variable non inicializada");
                     }
                 }else {
                    (yyval.valor) = NAN;
                     yyerror("[ERROR] Non se atopa o identificador");
                 }

                 free((yyvsp[-2].cadea));
             }
#line 1511 "y.tab.c"
    break;

  case 25: /* declaracion: IDENTIFICADOR OP_DIV_IGUAL_COD exp  */
#line 229 "analizadorSintactico.y"
                                                  {
                 if (buscarNumero((yyvsp[-2].cadea),CONSTANTE_COD)){
                     yyerror("[ERROR] Non se pode asignar a unha constante");
                 }else if (buscarNumero((yyvsp[-2].cadea),VARIABLE_COD)){
                     if (is_inicializada((yyvsp[-2].cadea)) == 1 && (yyvsp[0].valor) != 0){
                         (yyval.valor) = recuperarValor((yyvsp[-2].cadea)) / (yyvsp[0].valor);
                         insertarVariable((yyvsp[-2].cadea),(yyval.valor));
                     } else {
                         if((yyvsp[0].valor) == 0){ yyerror("[ERROR] Non se pode dividir entre 0"); (yyval.valor) = NAN;}
                         else {
                             (yyval.valor) = NAN;
                             yyerror("[ERROR] Non se pode asignar a unha variable non inicializada");
                         }
                     }
                 }else {
                     (yyval.valor) = NAN;
                     yyerror("[ERROR] Non se atopa o identificador");
                 }

                 free((yyvsp[-2].cadea));
             }
#line 1537 "y.tab.c"
    break;

  case 26: /* comparacion: exp '>' exp  */
#line 252 "analizadorSintactico.y"
                         {
                  if(!isnan((yyvsp[-2].valor)) && !isnan((yyvsp[0].valor))){
                      if( (yyvsp[-2].valor) > (yyvsp[0].valor) ) printf("Verdadeiro\n");
                      else printf("Falso\n");
                  } else {
                    yyerror("[ERROR] Estase utilizando unha variable sen inicializar");
                  }

                  (yyval.valor) = NAN;
               }
#line 1552 "y.tab.c"
    break;

  case 27: /* comparacion: exp '<' exp  */
#line 262 "analizadorSintactico.y"
                             {
                   if(!isnan((yyvsp[-2].valor)) && !isnan((yyvsp[0].valor))){
                       if( (yyvsp[-2].valor) < (yyvsp[0].valor) ) printf("Verdadeiro\n");
                       else printf("Falso\n");
                   } else {
                     yyerror("[ERROR] Estase utilizando unha variable sen inicializar");
                   }
                  (yyval.valor) = NAN;
               }
#line 1566 "y.tab.c"
    break;

  case 28: /* comparacion: exp OP_IGUAL_IGUAL_COD exp  */
#line 271 "analizadorSintactico.y"
                                            {
                  if(!isnan((yyvsp[-2].valor)) && !isnan((yyvsp[0].valor))){
                      if(fabs((yyvsp[-2].valor) - (yyvsp[0].valor)) < 0.01) printf("Verdadeiro\n");
                      else printf("Falso\n");
                  } else {
                    yyerror("[ERROR] Estase utilizando unha variable sen inicializar");
                  }
                   (yyval.valor) = NAN;
               }
#line 1580 "y.tab.c"
    break;

  case 29: /* comparacion: exp OP_DISTINTO_COD exp  */
#line 280 "analizadorSintactico.y"
                                          {
                   if(!isnan((yyvsp[-2].valor)) && !isnan((yyvsp[0].valor))){
                       if((yyvsp[-2].valor) != (yyvsp[0].valor)) printf("Verdadeiro\n");
                       else printf("Falso\n");
                   } else {
                     yyerror("[ERROR] Estase utilizando unha variable sen inicializar");
                   }
                  (yyval.valor) = NAN;
               }
#line 1594 "y.tab.c"
    break;

  case 30: /* comparacion: exp OP_MENOR_IGUAL_COD exp  */
#line 289 "analizadorSintactico.y"
                                            {
                   if(!isnan((yyvsp[-2].valor)) && !isnan((yyvsp[0].valor))){
                       if((yyvsp[-2].valor) <= (yyvsp[0].valor)) printf("Verdadeiro\n");
                       else printf("Falso\n");
                   } else {
                     yyerror("[ERROR] Estase utilizando unha variable sen inicializar");
                   }

                  (yyval.valor) = NAN;
               }
#line 1609 "y.tab.c"
    break;

  case 31: /* comparacion: exp OP_MAIOR_IGUAL_COD exp  */
#line 299 "analizadorSintactico.y"
                                             {
                   if(!isnan((yyvsp[-2].valor)) && !isnan((yyvsp[0].valor))){
                       if((yyvsp[-2].valor) >= (yyvsp[0].valor)) printf("Verdadeiro\n");
                       else printf("Falso\n");
                   } else {
                     yyerror("[ERROR] Estase utilizando unha variable sen inicializar");
                   }
                  (yyval.valor) = NAN;
               }
#line 1623 "y.tab.c"
    break;

  case 32: /* calculo: exp '+' exp  */
#line 310 "analizadorSintactico.y"
                     {
             if(isnan((yyvsp[-2].valor)) || isnan((yyvsp[0].valor))){
                 yyerror("[ERROR] Estase utilizando unha variable sen inicializar");
                 (yyval.valor) = NAN;
             } else {
                 (yyval.valor) = (yyvsp[-2].valor) + (yyvsp[0].valor);
             }
         }
#line 1636 "y.tab.c"
    break;

  case 33: /* calculo: exp '-' exp  */
#line 318 "analizadorSintactico.y"
                       {
            if(isnan((yyvsp[-2].valor)) || isnan((yyvsp[0].valor))){
                yyerror("[ERROR] Estase utilizando unha variable sen inicializar");
                (yyval.valor) = NAN;
            } else {
                (yyval.valor) = (yyvsp[-2].valor) - (yyvsp[0].valor);
            }
         }
#line 1649 "y.tab.c"
    break;

  case 34: /* calculo: exp '*' exp  */
#line 326 "analizadorSintactico.y"
                       {
             if(isnan((yyvsp[-2].valor)) || isnan((yyvsp[0].valor))){
                 yyerror("[ERROR] Estase utilizando unha variable sen inicializar");
                 (yyval.valor) = NAN;
             } else {
                 (yyval.valor) = (yyvsp[-2].valor) * (yyvsp[0].valor);
             }
         }
#line 1662 "y.tab.c"
    break;

  case 35: /* calculo: exp '/' exp  */
#line 334 "analizadorSintactico.y"
                       {
             if(isnan((yyvsp[-2].valor)) || isnan((yyvsp[0].valor))){
                 yyerror("[ERROR] Estase utilizando unha variable sen inicializar");
                 (yyval.valor) = NAN;
             } else {
                 if((yyvsp[0].valor) == 0){ yyerror("[ERROR] Non se pode dividir entre 0"); (yyval.valor) = NAN;}
                 else {
                     (yyval.valor) = (yyvsp[-2].valor) / (yyvsp[0].valor);
                 }
             }

         }
#line 1679 "y.tab.c"
    break;

  case 36: /* calculo: '-' exp  */
#line 346 "analizadorSintactico.y"
                                  {
             if(isnan((yyvsp[0].valor))){
                 yyerror("[ERROR] Estase utilizando unha variable sen inicializar");
                 (yyval.valor) = NAN;
             } else {
                 (yyval.valor) = -(yyvsp[0].valor);
             }
         }
#line 1692 "y.tab.c"
    break;

  case 37: /* metodo: IDENTIFICADOR '(' exp ')'  */
#line 357 "analizadorSintactico.y"
                                  {
            if(buscarNumero((yyvsp[-3].cadea),FUNCION_COD)){
                if(!isnan((yyvsp[-1].valor))){
                    (yyval.valor) = executarFuncion((yyvsp[-3].cadea),(yyvsp[-1].valor));
                } else {
                    (yyval.valor) = NAN;
                    yyerror("[ERROR] Estase utilizando unha variable sen inicializar");
                }
            }else{
                (yyval.valor) = NAN;
                yyerror("[ERROR] Non se atopa a función");
              }
              free((yyvsp[-3].cadea));
        }
#line 1711 "y.tab.c"
    break;

  case 38: /* metodo: IDENTIFICADOR '(' exp ',' exp ')'  */
#line 371 "analizadorSintactico.y"
                                            {
            if(buscarNumero((yyvsp[-5].cadea),FUNCION_COD)){
                if(!isnan((yyvsp[-3].valor)) && !isnan((yyvsp[-1].valor))){
                    (yyval.valor) = executarFuncionMultiple((yyvsp[-5].cadea),(yyvsp[-3].valor),(yyvsp[-1].valor));
                } else {
                    (yyval.valor) = NAN;
                    yyerror("[ERROR] Estase utilizando unha variable sen inicializar");
                }
            }else{
                (yyval.valor) = NAN;
                yyerror("[ERROR] Non se atopa a función");
              }
              free((yyvsp[-5].cadea));
        }
#line 1730 "y.tab.c"
    break;


#line 1734 "y.tab.c"

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
  YY_SYMBOL_PRINT ("-> $$ =", YY_CAST (yysymbol_kind_t, yyr1[yyn]), &yyval, &yyloc);

  YYPOPSTACK (yylen);
  yylen = 0;

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
  yytoken = yychar == YYEMPTY ? YYSYMBOL_YYEMPTY : YYTRANSLATE (yychar);
  /* If not already recovering from an error, report this error.  */
  if (!yyerrstatus)
    {
      ++yynerrs;
      yyerror (YY_("syntax error"));
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

  /* Pop stack until we find a state that shifts the error token.  */
  for (;;)
    {
      yyn = yypact[yystate];
      if (!yypact_value_is_default (yyn))
        {
          yyn += YYSYMBOL_YYerror;
          if (0 <= yyn && yyn <= YYLAST && yycheck[yyn] == YYSYMBOL_YYerror)
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
                  YY_ACCESSING_SYMBOL (yystate), yyvsp);
      YYPOPSTACK (1);
      yystate = *yyssp;
      YY_STACK_PRINT (yyss, yyssp);
    }

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END


  /* Shift the error token.  */
  YY_SYMBOL_PRINT ("Shifting", YY_ACCESSING_SYMBOL (yyn), yyvsp, yylsp);

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


#if !defined yyoverflow
/*-------------------------------------------------.
| yyexhaustedlab -- memory exhaustion comes here.  |
`-------------------------------------------------*/
yyexhaustedlab:
  yyerror (YY_("memory exhausted"));
  yyresult = 2;
  goto yyreturn;
#endif


/*-------------------------------------------------------.
| yyreturn -- parsing is finished, clean up and return.  |
`-------------------------------------------------------*/
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
                  YY_ACCESSING_SYMBOL (+*yyssp), yyvsp);
      YYPOPSTACK (1);
    }
#ifndef yyoverflow
  if (yyss != yyssa)
    YYSTACK_FREE (yyss);
#endif

  return yyresult;
}

#line 386 "analizadorSintactico.y"



void yyerror(char *s){
    printf("%s\n", s);
}

void cambiarGlobal(){
    global = global == 0 ? 1 : 0;
}
