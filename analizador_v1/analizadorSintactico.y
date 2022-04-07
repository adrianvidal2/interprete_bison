%{
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
%}

/*Tipo de pila*/
%union{
double valor;   /*Para devolver números*/
char *cadea;    /*Para devolver cadeas*/
}


%start input

%token <valor> NUMERO           /*Número simple en punto flotante (definición do token NUM e o seu tipo)*/
%token <cadea> IDENTIFICADOR    /*Identificador (definición do token ID e o seu tipo)*/
%token OP_ASIGNACION_COD
%token OP_MAS_MAS_COD
%token OP_MENOS_MENOS_COD
%token OP_SUMA_IGUAL_COD
%token OP_RESTA_IGUAL_COD
%token OP_MULT_IGUAL_COD
%token OP_DIV_IGUAL_COD
%token OP_MAIOR_IGUAL_COD
%token OP_MENOR_IGUAL_COD
%token OP_DISTINTO_COD
%token OP_IGUAL_IGUAL_COD
%token <cadea> ARQUIVO


%type <valor> exp


%type <valor> declaracion
%type <valor> metodo
%type <valor> comparacion
%type <valor> calculo

%token AXUDA
%token TABOA
%token SAIR
%token WORKSPACE
%token ELIMINAR
%token ABRIR
%token FIN_FICHEIRO

%right OP_ASIGNACION_COD
%left '-' '+' OP_MAS_MAS_COD OP_MENOS_MENOS_COD OP_SUMA_IGUAL_COD OP_RESTA_IGUAL_COD
%left '*' '/' OP_MULT_IGUAL_COD OP_DIV_IGUAL_COD
%left '>' '<' OP_MAIOR_IGUAL_COD OP_MENOR_IGUAL_COD OP_DISTINTO_COD OP_IGUAL_IGUAL_COD
%left NEGACION /*Negación--menos unario*/
%right '^'  /*Potencia*/



/*GRAMÁTICA*/

%%
input: {printf(">> ");}
      | input line
;


line: '\n' {
            if(!global)
                printf(">> ");
        }
        | exp '\n' {
            if(!global){
                if(!isnan($1)){
                        printf("%.10g\n>> ",$1);
                    }else
                        printf(">> ");
            } else {
                if(!isnan($1))
                        printf("%.10g\n",$1);
            }
        }
        | exp ';' {printf("%.10g\n", $1);}
        | FIN_FICHEIRO {printf(">> ");}
;

exp: NUMERO    {$$ = $1;}
    | TABOA  {imprimirTaboa(); $$ = NAN;}
    | WORKSPACE  {imprimirWorkspace(); $$ = NAN;}
    | ELIMINAR  {eliminarWorkspace(); $$ = NAN;}
    | IDENTIFICADOR {
        if(buscarNumero($1, VARIABLE_COD) || buscarNumero($1, CONSTANTE_COD)){
            if (is_inicializada($1) == 1) $$ = recuperarValor($1);
            else $$ = NAN;

        } else {
            if(buscarNumero($1, FUNCION_COD)){
                  $$ = NAN;
                  yyerror("[ERROR] Trátase dunha función");
            } else {
                crearVariable($1);
                $$ = NAN;
               yyerror("[WARNING] A variable é creada sen inicializar");
            }
        }


        free($1);
    }
    | '(' exp ')' {$$ = $2;}
    | comparacion
    | declaracion
    | metodo
    | calculo
    | ABRIR ARQUIVO {
                            apertura_arquivo($2); free($2); cambiarGlobal(); $$ = NAN;
                    }
;

declaracion: IDENTIFICADOR OP_ASIGNACION_COD exp {
                if(buscarNumero($1, CONSTANTE_COD)){
                    yyerror("[ERROR] Non se pode redeclarar unha constante");
                } else {
                    if(insertarVariable($1,$3) == FUNCION_COD){
                       $$ = NAN;
                       yyerror("[ERROR] Non se pode redeclarar unha función");
                    } else {
                        $$ = $3;
                    }
                }
                free($1);
             }
             | IDENTIFICADOR OP_MAS_MAS_COD {
                 if (buscarNumero($1,CONSTANTE_COD)){
                     $$ = recuperarValor($1) + 1;
                 }else if (buscarNumero($1,VARIABLE_COD)){
                     if(is_inicializada($1) == 1){
                           $$ = recuperarValor($1) + 1;
                           insertarVariable($1,$$);
                     } else {
                        $$ = NAN;
                         yyerror("[ERROR] Non se pode incrementar unha variable non inicializada");
                     }

                 }else {
                     $$ = NAN;
                     yyerror("[ERROR] Non se atopa o identificador");
                 }

                 free($1);
             }
             | IDENTIFICADOR OP_MENOS_MENOS_COD {
                 if (buscarNumero($1,CONSTANTE_COD)){
                     $$ = recuperarValor($1) - 1;
                 }else if (buscarNumero($1,VARIABLE_COD)){
                     if (is_inicializada($1) == 1){
                         $$ = recuperarValor($1) - 1;
                         insertarVariable($1,$$);
                     } else {
                         $$ = NAN;
                         yyerror("[ERROR] Non se pode decrementar unha variable non inicializada");
                     }
                 }else {
                     $$ = NAN;
                     yyerror("[ERROR] Non se atopa o identificador");
                 }

                 free($1);
             }
             | IDENTIFICADOR OP_SUMA_IGUAL_COD exp {
                 if (buscarNumero($1,CONSTANTE_COD)){
                     yyerror("[ERROR] Non se pode asignar a unha constante");
                 }else if (buscarNumero($1,VARIABLE_COD)){
                     if(is_inicializada($1) == 1){
                         $$ = recuperarValor($1) + $3;
                         insertarVariable($1,$$);
                     } else {
                        $$ = NAN;
                         yyerror("[ERROR] Non se pode asignar a unha variable non inicializada");
                     }
                 }else {
                     $$ = NAN;
                     yyerror("[ERROR] Non se atopa o identificador");
                 }

                 free($1);
             }
             | IDENTIFICADOR OP_RESTA_IGUAL_COD exp {
                 if (buscarNumero($1,CONSTANTE_COD)){
                     yyerror("[ERROR] Non se pode asignar a unha constante");
                 }else if (buscarNumero($1,VARIABLE_COD)){
                     if (is_inicializada($1) == 1){
                         $$ = recuperarValor($1) - $3;
                         insertarVariable($1,$$);
                     } else {
                        $$ = NAN;
                         yyerror("[ERROR] Non se pode asignar a unha variable non inicializada");
                     }
                 }else {
                       $$ = NAN;
                     yyerror("[ERROR] Non se atopa o identificador");
                 }

                 free($1);
             }
             | IDENTIFICADOR OP_MULT_IGUAL_COD exp {
                 if (buscarNumero($1,CONSTANTE_COD)){
                     yyerror("[ERROR] Non se pode asignar a unha constante");
                 }else if (buscarNumero($1,VARIABLE_COD)){
                     if (is_inicializada($1) == 1){
                         $$ = recuperarValor($1) * $3;
                         insertarVariable($1,$$);
                     } else {
                        $$ = NAN;
                         yyerror("[ERROR] Non se pode asignar a unha variable non inicializada");
                     }
                 }else {
                    $$ = NAN;
                     yyerror("[ERROR] Non se atopa o identificador");
                 }

                 free($1);
             }
             | IDENTIFICADOR OP_DIV_IGUAL_COD exp {
                 if (buscarNumero($1,CONSTANTE_COD)){
                     yyerror("[ERROR] Non se pode asignar a unha constante");
                 }else if (buscarNumero($1,VARIABLE_COD)){
                     if (is_inicializada($1) == 1 && $3 != 0){
                         $$ = recuperarValor($1) / $3;
                         insertarVariable($1,$$);
                     } else {
                         if($3 == 0){ yyerror("[ERROR] Non se pode dividir entre 0"); $$ = NAN;}
                         else {
                             $$ = NAN;
                             yyerror("[ERROR] Non se pode asignar a unha variable non inicializada");
                         }
                     }
                 }else {
                     $$ = NAN;
                     yyerror("[ERROR] Non se atopa o identificador");
                 }

                 free($1);
             }
;

comparacion: exp '>' exp {
                  if(!isnan($1) && !isnan($3)){
                      if( $1 > $3 ) printf("Verdadeiro\n");
                      else printf("Falso\n");
                  } else {
                    yyerror("[ERROR] Estase utilizando unha variable sen inicializar");
                  }

                  $$ = NAN;
               }
               | exp '<' exp {
                   if(!isnan($1) && !isnan($3)){
                       if( $1 < $3 ) printf("Verdadeiro\n");
                       else printf("Falso\n");
                   } else {
                     yyerror("[ERROR] Estase utilizando unha variable sen inicializar");
                   }
                  $$ = NAN;
               }
               | exp OP_IGUAL_IGUAL_COD exp {
                  if(!isnan($1) && !isnan($3)){
                      if(fabs($1 - $3) < 0.01) printf("Verdadeiro\n");
                      else printf("Falso\n");
                  } else {
                    yyerror("[ERROR] Estase utilizando unha variable sen inicializar");
                  }
                   $$ = NAN;
               }
               | exp  OP_DISTINTO_COD exp {
                   if(!isnan($1) && !isnan($3)){
                       if($1 != $3) printf("Verdadeiro\n");
                       else printf("Falso\n");
                   } else {
                     yyerror("[ERROR] Estase utilizando unha variable sen inicializar");
                   }
                  $$ = NAN;
               }
               | exp OP_MENOR_IGUAL_COD exp {
                   if(!isnan($1) && !isnan($3)){
                       if($1 <= $3) printf("Verdadeiro\n");
                       else printf("Falso\n");
                   } else {
                     yyerror("[ERROR] Estase utilizando unha variable sen inicializar");
                   }

                  $$ = NAN;
               }
               | exp  OP_MAIOR_IGUAL_COD exp {
                   if(!isnan($1) && !isnan($3)){
                       if($1 >= $3) printf("Verdadeiro\n");
                       else printf("Falso\n");
                   } else {
                     yyerror("[ERROR] Estase utilizando unha variable sen inicializar");
                   }
                  $$ = NAN;
               }
;

calculo: exp '+' exp {
             if(isnan($1) || isnan($3)){
                 yyerror("[ERROR] Estase utilizando unha variable sen inicializar");
                 $$ = NAN;
             } else {
                 $$ = $1 + $3;
             }
         }
         | exp '-' exp {
            if(isnan($1) || isnan($3)){
                yyerror("[ERROR] Estase utilizando unha variable sen inicializar");
                $$ = NAN;
            } else {
                $$ = $1 - $3;
            }
         }
         | exp '*' exp {
             if(isnan($1) || isnan($3)){
                 yyerror("[ERROR] Estase utilizando unha variable sen inicializar");
                 $$ = NAN;
             } else {
                 $$ = $1 * $3;
             }
         }
         | exp '/' exp {
             if(isnan($1) || isnan($3)){
                 yyerror("[ERROR] Estase utilizando unha variable sen inicializar");
                 $$ = NAN;
             } else {
                 if($3 == 0){ yyerror("[ERROR] Non se pode dividir entre 0"); $$ = NAN;}
                 else {
                     $$ = $1 / $3;
                 }
             }

         }
         | '-' exp %prec NEGACION {
             if(isnan($2)){
                 yyerror("[ERROR] Estase utilizando unha variable sen inicializar");
                 $$ = NAN;
             } else {
                 $$ = -$2;
             }
         }
;


metodo: IDENTIFICADOR '(' exp ')' {
            if(buscarNumero($1,FUNCION_COD)){
                if(!isnan($3)){
                    $$ = executarFuncion($1,$3);
                } else {
                    $$ = NAN;
                    yyerror("[ERROR] Estase utilizando unha variable sen inicializar");
                }
            }else{
                $$ = NAN;
                yyerror("[ERROR] Non se atopa a función");
              }
              free($1);
        }
        | IDENTIFICADOR '(' exp ',' exp ')' {
            if(buscarNumero($1,FUNCION_COD)){
                if(!isnan($3) && !isnan($5)){
                    $$ = executarFuncionMultiple($1,$3,$5);
                } else {
                    $$ = NAN;
                    yyerror("[ERROR] Estase utilizando unha variable sen inicializar");
                }
            }else{
                $$ = NAN;
                yyerror("[ERROR] Non se atopa a función");
              }
              free($1);
        }
;
%%


void yyerror(char *s){
    printf("%s\n", s);
}

void cambiarGlobal(){
    global = global == 0 ? 1 : 0;
}