#include <stdio.h>
#include <stdlib.h>
#include <dlfcn.h>
#include <string.h>
#include "taboaSimbolos.h"
#include "definicions.h"
#include <math.h>
#include "avl.h"

void *libreria = NULL;
/* * * * * * * * * * * * * * * * * * *
 *                                   *
 *        Funcións de axuda          *
 *                                   *
 * * * * * * * * * * * * * *  * *  * */

void imprimirBenvida() {
    printf("%92s%s\n\n", "========================", "=========================================");
    printf("%67s%50s%20s\n\n", "||", "BENVIDO A CALCULADORA MATEMÁTICA", "||");
    printf("%67s%32s%s%12s\n\n", "||", "Realice diversos tipos ", "de operacións matemáticas", "||");
    printf("%67s%32s%s%13s\n\n", "||", "Para visualizar a axuda", " escriba o comando axuda", "||");
    printf("%92s%s\n\n", "========================", "=========================================");
}

double imprimirAxuda() {

    printf("%100s\n\n", "**********************");
    printf("%79s%17s%5s\n\n", "*", "PRESENTACIÓN", "*");
    printf("%100s\n\n", "**********************");

    printf("%45s%s\n", "A calculadora permite ",
           "realizar operacións matemáticas básicas. Permite así, a declaración de variables, así como a realización de operacións aritméticas.");
    printf("%36s%s\n\n", "de variables.", " Ademais permite a importación de librerías propias compiladas.");

    printf("%100s\n\n", "**********************");
    printf("%79s%17s%4s\n\n", "*", "PALABRAS CLAVE", "*");
    printf("%100s\n\n", "**********************");

    printf("%81s%18s%s\n", "\"axuda\"", "->", " Imprime esta axuda.");
    printf("%81s%18s%s\n", "\"taboa\"", "->",
           " Imprime a taboa de símbolos global (constantes, variables e funcións).");
    printf("%81s%18s%s\n", "\"workspace\"", "->", " Imprime as variables e valores utilizados ata o momento.");
    printf("%81s%18s%s\n", "\"eliminar\"", "->", " Eliminación do espazo de traballo actual.");
    printf("%81s%18s%s\n", "\"import(lib)\"", "->", " Importa a librería lib para poder facer uso das súas funcións.");
    printf("%81s%18s%s\n", "\"load(file)\"", "->", " Executa as operacións contidas no arquivo.");
    printf("%81s%18s%s\n", "\"sair\"", "->", " Remate do programa.");
    printf("\n\n\n\n");

    printf("%100s\n\n", "**********************");
    printf("%79s%15s%6s\n\n", "*", "CONSTANTES", "*");
    printf("%100s\n\n", "**********************");

    printf("%79s%20s%s\n", "pi", "->", " 3.14159265358979323846");
    printf("%79s%20s%s\n", "e", "->", " 2.71828182845904523536");
    printf("\n\n\n");


    printf("%100s\n\n", "**********************");
    printf("%79s%16s%6s\n\n", "*", "OPERACIÓNS", "*");
    printf("%100s\n\n", "**********************");

    printf("%79s%20s%s\n", "+", "->", " Suma");
    printf("%79s%20s%s\n", "-", "->", " Resta");
    printf("%79s%20s%s\n", "*", "->", " Multiplicación");
    printf("%79s%20s%s\n", "/", "->", " División");
    printf("%79s%20s%s\n", "%", "->", " Módulo");
    printf("%79s%20s%s\n", "^", "->", " Potencia");
    printf("%79s%20s%s\n", "<", "->", " Menor que");
    printf("%79s%20s%s\n", ">", "->", " Maior que");
    printf("%79s%20s%s\n", "<=", "->", " Menor ou igual que");
    printf("%79s%20s%s\n", ">=", "->", " Maior ou igual que");
    printf("%79s%20s%s\n", "==", "->", " Igual que");
    printf("%79s%20s%s\n\n", "!=", "->", " Diferente que");
    printf("%78s%s\n\n", "[NOTA] ", "As seguintes operacións só son aplicables a variables.");
    printf("%79s%20s%s\n", "++", "->", " Incremento dunha unidade");
    printf("%79s%20s%s\n", "--", "->", " Decremento dunha unidade");
    printf("%79s%20s%s\n", "+=", "->", " Suma e asignación");
    printf("%79s%20s%s\n", "-=", "->", " Resta e asignación");
    printf("%79s%20s%s\n", "*=", "->", " Multiplicación e asignación");
    printf("%79s%20s%s\n", "/=", "->", " División e asignación");
    printf("\n\n");


    printf("%100s\n\n", "**********************");
    printf("%79s%16s%6s\n\n", "*", " LIBRERÍAS", "*");
    printf("%100s\n\n", "**********************");

    printf("%45s%s\n", "Para poder utilizar ",
           "funcións como as definidas na librería matemática, debe indicarse que se quere facer uso desta. A libraría cargaráse dinámicamente e");
    printf("%36s%s\n\n", "para poder ", "facer uso das funcións, deberá indicarse como no seguinte exemplo:");
    printf("%79s%15s\n\n", ">>", " import(math.h)");
    printf("%79s%10s\n\n", ">>", " math/sin(2)");
    printf("%34s%s\n", "De igual ",
           "maneira, o usuario pode importar as súas propias librerías, indicando no import a ruta do arquivo .so que contén a función. O uso das súas funcións");
    printf("%36s%s\n\n", "realízase ",
           "da mesma forma que como no exemplo anterior \"nomelibreria/nomefuncion\". Pódense usar múltiples librerías en cada execución.");

    printf("%100s\n\n", "**********************");
    printf("%79s%14s%8s\n\n", "*", "LÉXICO", "*");
    printf("%100s\n\n", "**********************");


    printf("%38s%s\n", "As variables ",
           "declaradas sen ningunha asignación serán creadas sen inicialización, indicándoselle o usuario. O nome das variables debe comezar por unha letra");
    printf("%39s%s\n", "As librerías ",
           "deberán rematar con unha extesión .h ou .so. A utilización de scripts externos, non permitirá a chamada recursiva a outros scripts. Non se imprimirán ");
    printf("%42s%s\n\n", "aqueles comandos ",
           "que rematen co símbolo ;.");
    return 1;
}


//Apertura da librería dinamicamente
void *apertura_lib(char *nomeLibreria) {

    //Compróbase se o usuario quere utilizar a librería matemática
    if (!strcmp(nomeLibreria, "math.h")) {
        if (!(libreria = dlopen("libm.so.6", RTLD_LAZY))) {
            free(nomeLibreria);
            return NULL;
        }
    } else {
        //Comprobación se a librería se atopa no path indicado ou no directorio dende o cal se executa o programa
        if (!(libreria = dlopen(nomeLibreria, RTLD_LAZY))) {
            char *directorio = (char *) malloc(sizeof(char) * strlen(nomeLibreria) + 3);
            strncpy(directorio, "./", 3);
            strncat(directorio + 1, nomeLibreria, strlen(nomeLibreria) + 1);
            directorio[strlen(nomeLibreria) + 2] = '\0';

            if (!(libreria = dlopen(directorio, RTLD_LAZY))) {
                printf("Non se pode abrir a libreria: %s\n", nomeLibreria);
                free(directorio);
                return NULL;
            } else {
                free(directorio);
            }
        }
    }
    printf("Aberta a librería: %s\n", nomeLibreria);
    return libreria;
}

/* * * * * * * * * * * * * * * * * * *
 *                                   *
 *       Funcións de execución       *
 *                                   *
 * * * * * * * * * * * * * *  * *  * */

double executar_externa(char *conxunto, void *lib, char *nomeFuncion, double valor) {
    //Buscamos a función na librería correspondente
    double (*funcion)(double);
    funcion = (double (*)(double)) dlsym(lib, nomeFuncion);
    if (funcion != NULL) {
        //Insertamos a función na táboa de símbolos para evitar así este procedemento con cada execución
        insertarFuncion(conxunto, FUNCION_COD, funcion);
        return (*funcion)(valor);
    }
    return NAN;
}

double executarExternaMult(char *conxunto, void *lib, char *nomeFuncion, double valor1, double valor2) {
    double (*funcion)(double, double);
    funcion = (double (*)(double, double)) dlsym(libreria, nomeFuncion);
    if (funcion != NULL) {
        insertarFuncion(conxunto, FUNCION_COD, funcion);
        return (*funcion)(valor1, valor2);
    }
    return NAN;
}
