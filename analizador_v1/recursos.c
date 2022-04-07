#include <stdio.h>

void imprimirBenvida(){
    printf("%92s%s\n\n","========================", "=========================================");
    printf("%67s%50s%20s\n\n", "||","BENVIDO A CALCULADORA MATEMÁTICA", "||");
    printf("%67s%32s%s%12s\n\n","||", "Realice diversos tipos ", "de operacións matemáticas", "||");
    printf("%67s%32s%s%11s\n\n",  "||","Para visualizar a axuda", " escriba o comando axuda()","||");
    printf("%92s%s\n\n","========================", "=========================================");
}

void imprimirAxuda(){

    printf("**********************\n\n");
    printf("%-5s%5s%5s\n\n","*", "PRESENTACIÓN", "*");
    printf("**********************\n\n\n");

    printf("A calculadora permite realizar operacións matemáticas básicas. Permite así, a declaración\n");
    printf("de variables.\n\n\n");
}