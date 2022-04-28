%{
#include <stdio.h>
#include <math.h>
#include <dlfcn.h>
#include <string.h>
#include "definicions.h"
#include "taboaSimbolos.h"
#include "xestionErros.h"
#include "recursos.h"
#include "lex.yy.h"
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

%type <valor> exp


%type <valor> declaracion
%type <valor> comparacion
%type <valor> calculo
%type <valor> externas

%token <cadea> TABOA
%token <cadea> AXUDA
%token <cadea> WORKSPACE
%token <cadea> ELIMINAR
%token <cadea> IMPORT
%token <cadea> LOAD
%token <cadea> SAIR
%token <cadea> ARQUIVO
%token <cadea> LIBRERIA
%token FIN_FICHEIRO

%right OP_ASIGNACION_COD
%left '-' '+' OP_SUMA_IGUAL_COD OP_RESTA_IGUAL_COD
%left '*' '/' '%' OP_MULT_IGUAL_COD OP_DIV_IGUAL_COD
%left '>' '<' OP_MAIOR_IGUAL_COD OP_MENOR_IGUAL_COD OP_DISTINTO_COD OP_IGUAL_IGUAL_COD
%right NEGACION /*Negación--menos unario*/
%right '^'  /*Potencia*/



/*GRAMÁTICA*/

%%
input:  %empty {printf(">> ");}
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
        | exp ';'
        | FIN_FICHEIRO {printf(">> ");}
        | error {yyclearin;}
;

exp: NUMERO    {$$ = $1;}
    | AXUDA    {executar($1); $$ = NAN;}
    | TABOA     {executar($1); $$ = NAN;}
    | WORKSPACE {executar($1); $$ = NAN;}
    | ELIMINAR  {executar($1); $$ = NAN;}
    | SAIR      {$$ = NAN;
                     if(!global){
                         return executar($1);
                    }else {
                        yyerror("[ERROR] No pode sair dende un ficheiro");
                        free($1);
                    }
                }
    | IDENTIFICADOR {
       if(buscarNumero($1, VARIABLE_COD) || buscarNumero($1, CONSTANTE_COD)){
                   if (is_inicializada($1) == 1) $$ = recuperarValor($1);
                   else $$ = NAN;

               } else {
                   if(buscarNumero($1, FUNCION_COD)){
                         $$ = NAN;
                         yyerror("[ERROR] Trátase dunha función");
                   } else {
                       insertarVariable($1, NAN);
                       $$ = NAN;
                      yyerror("[WARNING] A variable é creada sen inicializar");
                   }
               }


        free($1);
    }
    | '(' exp ')' {$$ = $2;}
    | comparacion
    | declaracion
    | calculo
    | externas
    | IMPORT LIBRERIA   {
                            if(!funcionCarga($1,$2)){
                                yyerror("[ERROR] A librería xa está importada...");
                            }
                            $$ = NAN;
                        }
    | LOAD ARQUIVO      {
                            if(!global){
                                funcionCarga($1,$2);
                            } else {
                                yyerror("[ERROR] Xa se está tratando un script...");
                                free($1);
                            }
                            free($2);$$ = NAN;
                        }
;

declaracion: IDENTIFICADOR OP_ASIGNACION_COD exp {
                                                    if ( buscarNumero($1, CONSTANTE_COD)) {
                                                         yyerror("[ERROR] Non se pode redefinir unha constante...");
                                                         $$ = NAN;
                                                    } else {
                                                         insertarVariable($1, $3);
                                                         $$ = $3;
                                                    }
                                                    free($1);
                                                 }
              | IDENTIFICADOR OP_MAS_MAS_COD {
                                                    if(buscarNumero($1,CONSTANTE_COD)){
                                                        $$ = recuperarValor($1) + 1;
                                                    } else if (buscarNumero($1, VARIABLE_COD)){
                                                      if(is_inicializada($1)){
                                                            if(isnan(recuperarValor($1))){
                                                                yyerror("[WARNING] A variable non se atopa inicializada...");
                                                                $$ = NAN;
                                                            } else {
                                                                $$ = recuperarValor($1) + 1;
                                                                insertarVariable($1, $$);
                                                            }
                                                      }
                                                    } else {
                                                        $$ = NAN;
                                                        yyerror("[ERROR] Non se pode incrementar unha variable non inicializada...");
                                                    }
                                                    free($1);
                                             }
              | IDENTIFICADOR OP_MENOS_MENOS_COD {
                                                    if(buscarNumero($1,CONSTANTE_COD)){
                                                        $$ = recuperarValor($1) - 1;
                                                    } else if (buscarNumero($1, VARIABLE_COD)){
                                                       if(is_inicializada($1)){
                                                            if(isnan(recuperarValor($1))){
                                                                yyerror("[WARNING] A variable non se atopa inicializada...");
                                                                $$ = NAN;
                                                            } else {
                                                                $$ = recuperarValor($1) - 1;
                                                                insertarVariable($1, $$);
                                                            }
                                                        }
                                                    } else {
                                                        $$ = NAN;
                                                        yyerror("[ERROR] Non se pode decrementar unha variable non inicializada...");
                                                    }
                                                    free($1);
                                             }
              | IDENTIFICADOR OP_SUMA_IGUAL_COD exp {
                                                       if(buscarNumero($1,CONSTANTE_COD)){
                                                           yyerror("[ERROR] Non se pode redefinir unha constante...");
                                                           $$ = NAN;
                                                       } else if (buscarNumero($1, VARIABLE_COD)) {
                                                            if (is_inicializada($1)) {
                                                                if (isnan(recuperarValor($1))) {
                                                                    yyerror("[WARNING] A variable non se atopa inicializada...");
                                                                    $$ = NAN;
                                                                } else {
                                                                    $$ = recuperarValor($1) + $3;
                                                                    insertarVariable($1, $$);
                                                                }

                                                            }
                                                       } else {
                                                            $$ = NAN;
                                                            yyerror("[ERROR] Non se pode incrementar unha variable non inicializada...");
                                                       }
                                                       free($1);
                                                    }
              | IDENTIFICADOR OP_RESTA_IGUAL_COD exp {
                                                       if(buscarNumero($1,CONSTANTE_COD)){
                                                           yyerror("[ERROR] Non se pode redefinir unha constante...");
                                                           $$ = NAN;
                                                       } else if (buscarNumero($1, VARIABLE_COD)) {
                                                            if (is_inicializada($1)) {
                                                                if(isnan(recuperarValor($1))) {
                                                                    yyerror("[WARNING] A variable non se atopa inicializada...");
                                                                    $$ = NAN;
                                                                } else {
                                                                    $$ = recuperarValor($1) - $3;
                                                                    insertarVariable($1, $$);
                                                                }
                                                            }
                                                       } else {
                                                            $$ = NAN;
                                                            yyerror("[ERROR] Non se pode decrementar unha variable non inicializada...");
                                                       }
                                                       free($1);
                                                    }
              | IDENTIFICADOR OP_MULT_IGUAL_COD exp {
                                                       if(buscarNumero($1,CONSTANTE_COD)){
                                                           yyerror("[ERROR] Non se pode redefinir unha constante...");
                                                           $$ = NAN;
                                                       } else if (buscarNumero($1, VARIABLE_COD)) {
                                                            if (is_inicializada($1)) {
                                                                if(isnan(recuperarValor($1))) {
                                                                    yyerror("[WARNING] A variable non se atopa inicializada...");
                                                                    $$ = NAN;
                                                                } else {
                                                                    $$ = recuperarValor($1) * $3;
                                                                    insertarVariable($1, $$);
                                                                }
                                                            }
                                                       } else {
                                                            $$ = NAN;
                                                            yyerror("[ERROR] Non se pode multiplicar unha variable non inicializada...");
                                                       }
                                                       free($1);
                                                    }
              | IDENTIFICADOR OP_DIV_IGUAL_COD exp {
                                                       if(buscarNumero($1,CONSTANTE_COD)){
                                                           yyerror("[ERROR] Non se pode redefinir unha constante...");
                                                           $$ = NAN;
                                                       } else if (buscarNumero($1, VARIABLE_COD)) {
                                                            if (is_inicializada($1) && $3 != 0) {
                                                                if(isnan(recuperarValor($1))) {
                                                                    yyerror("[WARNING] A variable non se atopa inicializada...");
                                                                    $$ = NAN;
                                                                } else {
                                                                    $$ = recuperarValor($1) / $3;
                                                                    insertarVariable($1, $$);
                                                                }
                                                            } else {
                                                                 yyerror("[ERROR] División por 0...");
                                                                $$ = NAN;
                                                            }
                                                       } else {
                                                            $$ = NAN;
                                                            yyerror("[ERROR] Non se pode dividir unha variable non inicializada...");
                                                       }
                                                       free($1);
                                                    }
;

comparacion: exp '>' exp {
                            if (!isnan($1) && !isnan($3)) {
                             if ($1 > $3) {
                                  printf("Verdadeiro\n");
                                 } else {
                                  printf("Falso\n");
                                 }
                            } else {
                             yyerror("[ERROR] Variable/s non inicializada/s...");
                            }
                              $$ = NAN;
                         }
              | exp '<' exp {
                                if (!isnan($1) && !isnan($3)) {
                                 if ($1 < $3) {
                                      printf("Verdadeiro\n");
                                     } else {
                                      printf("Falso\n");
                                     }
                                } else {
                                 yyerror("[ERROR] Variable/s non inicializada/s...");
                                }
                                  $$ = NAN;
                            }
              | exp OP_IGUAL_IGUAL_COD exp {
                                                if (!isnan($1) && !isnan($3)) {
                                                    if (fabs($1 - $3) < 0.01) {
                                                        printf("Verdadeiro\n");
                                                     } else {
                                                        printf("Falso\n");
                                                     }
                                                } else {
                                                    yyerror("[ERROR] Variable/s non inicializada/s...");
                                                }
                                                $$ = NAN;
                                            }
              | exp OP_DISTINTO_COD exp {
                                            if (!isnan($1) && !isnan($3)) {
                                                    if ($1 != $3) {
                                                        printf("Verdadeiro\n");
                                                    } else {
                                                        printf("Falso\n");
                                                    }
                                                } else {
                                                    yyerror("[ERROR] Variable/s non inicializada/s...");
                                                }
                                                $$ = NAN;
                                          }
              | exp OP_MENOR_IGUAL_COD exp {
                                                if (!isnan($1) && !isnan($3)) {
                                                    if ($1 <= $3) {
                                                        printf("Verdadeiro\n");
                                                    } else {
                                                        printf("Falso\n");
                                                    }
                                                } else {
                                                    yyerror("[ERROR] Variable/s non inicializada/s...");
                                                }
                                                $$ = NAN;
                                            }
              | exp OP_MAIOR_IGUAL_COD exp {
                                                if (!isnan($1) && !isnan($3)) {
                                                    if ($1 >= $3) {
                                                        printf("Verdadeiro\n");
                                                    } else {
                                                        printf("Falso\n");
                                                    }
                                                } else {
                                                    yyerror("[ERROR] Variable/s non inicializada/s...");
                                                }
                                                $$ = NAN;
                                            }
;


calculo: exp '+' exp {
                        if (!isnan($1) && !isnan($3)) {
                            $$ = $1 + $3;
                        } else {
                            yyerror("[ERROR] Variable/s non inicializada/s...");
                            $$ = NAN;
                        }
                     }
       | exp '-' exp {
                            if (!isnan($1) && !isnan($3)) {
                                $$ = $1 - $3;
                            } else {
                                yyerror("[ERROR] Variable/s non inicializada/s...");
                                $$ = NAN;
                            }
                         }
       | exp '*' exp {
                            if (!isnan($1) && !isnan($3)) {
                                $$ = $1 * $3;
                            } else {
                                yyerror("[ERROR] Variable/s non inicializada/s...");
                                $$ = NAN;
                            }
                     }
       | exp '/' exp {
                            if ((!isnan($1) && !isnan($3)) || ($3 != 0)) {
                                $$ = $1 / $3;
                            } else {
                                if ($3 != 0) yyerror("[ERROR] Variable/s non inicializada/s...");
                                else yyerror("[ERROR] División por 0...");
                                $$ = NAN;
                            }
                       }
       | exp '%' exp {
                            if ((!isnan($1) && !isnan($3)) || ($3 != 0)) {
                                $$ = fmod($1,$3);
                            } else {
                                if ($3 != 0) yyerror("[ERROR] Variable/s non inicializada/s...");
                                else yyerror("[ERROR] División por 0...");
                                $$ = NAN;
                            }
                       }
       | exp '^' exp {
                            if (!isnan($1) && !isnan($3)) {
                                $$ = pow($1, $3);
                            } else {
                                yyerror("[ERROR] Variable/s non inicializada/s...");
                                $$ = NAN;
                            }
                       }
       | '-' exp %prec NEGACION {
                                    if (!isnan($2)) {
                                        $$ = -$2;
                                    } else {
                                        yyerror("[ERROR] Variable/s non inicializada/s...");
                                        $$ = NAN;
                                    }
                                }

;

externas: LIBRERIA '/' IDENTIFICADOR '(' exp ')'{
                                                    char *busqueda = (char *)malloc(sizeof(char)*(strlen($1)+strlen($3)+2));
                                                    strncpy(busqueda,$1, strlen($1));
                                                    strncpy(busqueda+strlen($1),"/", 2);
                                                    strncpy(busqueda+strlen($1)+1,$3, strlen($3));
                                                    busqueda[strlen($1)+strlen($3)+1] = '\0';

                                                    if(buscarNumero(busqueda,FUNCION_COD)){
                                                        if(!isnan($5)){
                                                            $$ = executarFuncion(busqueda,$5);
                                                        } else {
                                                           yyerror("[ERROR] O parámetro utilizado non é válido...");
                                                           $$ = NAN;
                                                        }
                                                    } else {
                                                        /*Comprobamos se a función existe e executamola e insertámola. En caso contraria significaría que a función non existe*/
                                                        if(buscarLibreria($1)){
                                                            $$ = executarExterna(busqueda,$1, $3, $5);
                                                        } else {
                                                            $$ = NAN;
                                                            yyerror("[ERROR] A función non está incluída...");
                                                        }
                                                    }
                                                    free($1);free($3); free(busqueda);
                                                }
          | LIBRERIA '/' IDENTIFICADOR '(' exp ',' exp ')'{
                                                             char *busqueda = (char *)malloc(sizeof(char)*(strlen($1)+strlen($3)+2));
                                                             strncpy(busqueda,$1, strlen($1));
                                                             strncpy(busqueda+strlen($1),"/", 2);
                                                             strncpy(busqueda+strlen($1)+1,$3, strlen($3));
                                                             busqueda[strlen($1)+strlen($3)+1] = '\0';

                                                             if(buscarNumero(busqueda, FUNCION_COD)){
                                                                 if (!isnan($5) && !isnan($7)){
                                                                      $$ = executarFuncionMultiple(busqueda,$5,$7);
                                                                 } else {
                                                                      yyerror("[ERROR] Parámetro/s inválido/s...");
                                                                      $$ = NAN;
                                                                 }
                                                             } else {
                                                                 /*Comprobamos se a función existe e executamola e insertámola. En caso contrario significaría que a función non existe*/
                                                                 if(buscarLibreria($1)){
                                                                    $$ = executarExternaMultiple(busqueda,$1, $3, $5, $7);
                                                                 } else {
                                                                    $$ = NAN;
                                                                    yyerror("[ERROR] A librería non está incluída...");
                                                                 }
                                                             }
                                                             free($1);free($3); free(busqueda);
                                                          }
;
%%

void cambiarGlobal(){
    global = global == 0 ? 1 : 0;
}


void yyerror(char *s){
    printf("%s\n", s);
}

