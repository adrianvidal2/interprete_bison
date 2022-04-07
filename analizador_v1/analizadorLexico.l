%{
#include "definicions.h"
#include "taboaSimbolos.h"
#include "erros.h"
#include "xestionErros.h"
#include "y.tab.h"
void apertura_arquivo(char *filename);
void peche_arquivo();
void cambiarGlobal();
%}


%option noyywrap
%option yylineno
%option nounput
%option noinput



NOVALINHA           \n
ESPAZOS             [[:blank:]]
UNICODE_CHAR        .
SEPARADOR           (\r|\t|{ESPAZOS})+
UNICODE_LETRA       [a-zA-Z]
UNICODE_DIXITO      [0-9]

LETRA               {UNICODE_LETRA}|_

INT_LIT             {UNICODE_DIXITO}+

EXPONHENTE          [eE][+-]?{UNICODE_DIXITO}+
FLOAT_LIT           {INT_LIT}+[.]{INT_LIT}?{EXPONHENTE}?|{INT_LIT}{EXPONHENTE}|[.]{INT_LIT}{EXPONHENTE}?
NUMERO              {FLOAT_LIT}|{INT_LIT}

IDENTIFICADOR       {LETRA}({LETRA}|{UNICODE_DIXITO})*



OP_ASIGNACION       =
OP_SUMA_IGUAL       \+=
OP_MAS_MAS          \+\+
OP_MENOS_MENOS      \-\-
OP_RESTA_IGUAL      \-=
OP_MULT_IGUAL       \*=
OP_DIV_IGUAL        \/=
OP_MAIOR_IGUAL      \>=
OP_MENOR_IGUAL      \<=
OP_DISTINTO       \!=
OP_IGUAL_IGUAL      ==
OP_INDV             [+*/%^,;.!<>()-]

ARQUIVO_ENTRADA     ([/]?|{LETRA}|{UNICODE_DIXITO}|\.)+

%x                  CARGAR

%%
"axuda()"           return (AXUDA);
"taboa"             return (TABOA);
"workspace"         return (WORKSPACE);
"eliminar()"        return (ELIMINAR);
"sair()"            {yylex_destroy();yyterminate();}
"load "            {
                        BEGIN(CARGAR);
                        return (ABRIR);
                  }




<CARGAR>{ARQUIVO_ENTRADA}              {
                                           yylval.cadea = (char*)malloc(sizeof(char)*(yyleng+1));
                                           strcpy(yylval.cadea,yytext);
                                           yylval.cadea[yyleng] = '\0';
                                           BEGIN(INITIAL);
                                           return (ARQUIVO);
                                       }

{SEPARADOR}

{NOVALINHA}         return ((int)*yytext);

{IDENTIFICADOR}         {
                           yylval.cadea = (char *)malloc(sizeof(char)*(yyleng+1));
                           strcpy(yylval.cadea,yytext);
                           yylval.cadea[yyleng] = '\0';
                            return IDENTIFICADOR;
                        }


{NUMERO}                 {
                            yylval.valor = atof(yytext);
                            return NUMERO;
                        }

{OP_ASIGNACION}          return (OP_ASIGNACION_COD);

{OP_SUMA_IGUAL}          return (OP_SUMA_IGUAL_COD);

{OP_RESTA_IGUAL}         return (OP_RESTA_IGUAL_COD);

{OP_MAS_MAS}             return (OP_MAS_MAS_COD);

{OP_MENOS_MENOS}         return (OP_MENOS_MENOS_COD);

{OP_MULT_IGUAL}          return (OP_MULT_IGUAL_COD);

{OP_DIV_IGUAL}           return (OP_DIV_IGUAL_COD);

{OP_MAIOR_IGUAL}         return (OP_MAIOR_IGUAL_COD);

{OP_MENOR_IGUAL}         return (OP_MENOR_IGUAL_COD);

{OP_DISTINTO}            return (OP_DISTINTO_COD);

{OP_IGUAL_IGUAL}         return (OP_IGUAL_IGUAL_COD);

{OP_INDV}                return ((int)*yytext);

.                       {
                            tipoErro(ERRO_LENDO_ARQUIVO,"",yylineno);
                        }

<<EOF>>                  {
                            cambiarGlobal(); peche_arquivo(); yyrestart(stdin); return (FIN_FICHEIRO);
                         }

%%



void apertura_arquivo(char *filename){
    if((yyin = fopen(filename,"r")) == NULL){
        tipoErro(ERRO_ARQUIVO,filename,0);
        yyin = stdin;
        cambiarGlobal();
    }
}

void peche_arquivo(){
    fclose(yyin);
}