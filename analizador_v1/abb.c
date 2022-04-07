#include "abb.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "definicions.h"

/*			STRUCTURES			*/

/*Elements of the tree
 *
 * char *lexema: Keywords or ID names
 * int codigo: Keywords or ID codes
 * */
typedef struct {
    char *lexema;
    int codigo;
    int inicializada;

    union {
        double variable;

        double (*funcion)();
    } valor;
} elemento;

struct celda {
    elemento info;
    struct celda *izq, *der;
};

/*Tree Initialization*/
void crear(abb *A) {
    *A = NULL;
}

/*Tree destruction*/
void destruir(abb *A) {
    if (*A != NULL) {
        destruir(&(*A)->izq);    //destruction of the children of the left branch
        destruir(&(*A)->der);    //destruction of the children of the right branch
        if (&(*A)->info.lexema != NULL) {//lexeme memory release
            free((*A)->info.lexema);
            (*A)->info.lexema = NULL;
        }
        free(*A);                //tree memoria release
        *A = NULL;
    }
}

void eliminar_workspace(abb *A){
    if(!es_vacio(*A)){
        eliminar_workspace(&(*A)->izq);
        eliminar_workspace(&(*A)->der);
        if((*A)->info.codigo == VARIABLE_COD){
            if((*A)->info.lexema != NULL){
                free((*A)->info.lexema);
                (*A)->info.lexema = NULL;
            }
            free(*A);
            *A = NULL;
        }

    }
}

/*INFORMATION OPERATIONS*/

//Determine if the tree is empty
unsigned es_vacio(abb A) {
    return A == NULL;
}

//Return of the left subtree
abb izq(abb A) {
    return A->izq;
}

//Return of the right subtree
abb der(abb A) {
    return A->der;
}

/*MODIFICATION OPERATIONS*/
void insertarFuncion(abb *A, char *nome, void *func) {
    if (es_vacio(*A)) {
        *A = (abb) malloc(sizeof(struct celda));
        (*A)->info.lexema = (char *) malloc(strlen(nome) + 1 * sizeof(char));
        strcpy((*A)->info.lexema, nome);
        (*A)->info.lexema[strlen(nome)] = '\0';
        (*A)->info.codigo = FUNCION_COD;
        (*A)->info.valor.funcion = func;
        (*A)->info.inicializada = 1;
        (*A)->izq = NULL;
        (*A)->der = NULL;
        return;
    }

    int comparacion = strcmp(nome, (*A)->info.lexema);

    if (comparacion > 0) {
        insertarFuncion(&(*A)->der, nome, func);
    } else {
        insertarFuncion(&(*A)->izq, nome, func);
    }

}

void insertarConstante(abb *A, char *nome, double valor) {
    if (es_vacio(*A)) {
        *A = (abb) malloc(sizeof(struct celda));
        (*A)->info.lexema = (char *) malloc(strlen(nome) + 1 * sizeof(char));
        strcpy((*A)->info.lexema, nome);
        (*A)->info.lexema[strlen(nome)] = '\0';
        (*A)->info.codigo = CONSTANTE_COD;
        (*A)->info.valor.variable = valor;
        (*A)->info.inicializada = 1;
        (*A)->izq = NULL;
        (*A)->der = NULL;
        return;
    }

    int comparacion = strcmp(nome, (*A)->info.lexema);

    if (comparacion == 0) {

    } else if (comparacion > 0) {
        insertarConstante(&(*A)->der, nome, valor);
    } else {
        insertarConstante(&(*A)->izq, nome, valor);
    }

}

int insertar_variable(abb *A, char *nome, double valor) {
    if (es_vacio(*A)) {
        *A = (abb) malloc(sizeof(struct celda));
        (*A)->info.lexema = (char *) malloc(strlen(nome) + 1 * sizeof(char));
        strcpy((*A)->info.lexema, nome);
        (*A)->info.lexema[strlen(nome)] = '\0';
        (*A)->info.codigo = VARIABLE_COD;
        (*A)->info.valor.variable = valor;
        (*A)->info.inicializada = 1;
        (*A)->izq = NULL;
        (*A)->der = NULL;
        return VARIABLE_COD;
    }

    int comparacion = strcmp(nome, (*A)->info.lexema);

    if (comparacion == 0 && (*A)->info.codigo == VARIABLE_COD) {
        (*A)->info.valor.variable = valor;
        (*A)->info.inicializada = 1;
        return VARIABLE_COD;
    } else if (comparacion == 0) {
        return FUNCION_COD;
    } else if (comparacion < 0) {
        return insertar_variable(&(*A)->izq, nome, valor);
    } else {
        return insertar_variable(&(*A)->der, nome, valor);
    }
}

int crear_variable(abb *A, char *var) {
    if (es_vacio(*A)) {
        *A = (abb) malloc(sizeof(struct celda));
        (*A)->info.lexema = (char *) malloc(strlen(var) + 1 * sizeof(char));
        strcpy((*A)->info.lexema,var);
        (*A)->info.lexema[strlen(var)] = '\0';
        (*A)->info.codigo = VARIABLE_COD;
        (*A)->info.valor.variable = 0;
        (*A)->info.inicializada = 0;
        (*A)->izq = NULL;
        (*A)->der = NULL;
        return (*A)->info.codigo;
    }

    int comparacion = strcmp(var, (*A)->info.lexema);
    if (comparacion < 0) {
        return crear_variable(&(*A)->izq, var);
    } else {
        return crear_variable(&(*A)->der, var);
    }
}


/*
 * Function that performs the printing of the tree, it works as follows:
 * Check if the node is not empty, if there is a left child it will be called recursively until the end is reached and print the name and value of the lexeme.
 * In the same way, the process is carried out for the children of the right branches
 * */
void imprimir_tabla(abb *A) {
    if (!es_vacio(*A)) {
        if (&(*A)->izq != NULL) {
            imprimir_tabla(&(*A)->izq);
            printf("%-5s ", (*A)->info.lexema);
        }

        printf("%18d", (*A)->info.codigo);
        if ((*A)->info.codigo == FUNCION_COD) {
            printf("%19s%20s%17d\n", "-", (*A)->info.lexema, (*A)->info.inicializada);
        } else {
            printf("%22lf%16s%18d\n", (*A)->info.valor.variable, "-", (*A)->info.inicializada);
        }

        if (&(*A)->der != NULL) {
            imprimir_tabla(&(*A)->der);
        }
    }
}


void imprimir_workspace(abb *A){
    if(!es_vacio(*A)){
        if(&(*A)->izq != NULL){
            imprimir_workspace(&(*A)->izq);
        }

        if((*A)->info.codigo == VARIABLE_COD){
            if((*A)->info.inicializada) printf("%s%26lf%12d\n", (*A)->info.lexema, (*A)->info.valor.variable,(*A)->info.inicializada);
            else printf("%s%22s%16d\n", (*A)->info.lexema, "-",(*A)->info.inicializada);
        }

        if(&(*A)->der != NULL){
            imprimir_workspace(&(*A)->der);
        }
    }
}


int buscar_numero(abb A, char *lexema, int codigo) {
    if (es_vacio(A)) {
        return 0;
    }

    int comparacion = strcmp(lexema, A->info.lexema);
    if (comparacion == 0 && A->info.codigo == codigo) {
        return A->info.codigo;
    } else if (comparacion < 0) {
        return buscar_numero(A->izq, lexema, codigo);
    } else {
        return buscar_numero(A->der, lexema, codigo);
    }

}
int isInicializada(abb A, char *lexema) {
    if (es_vacio(A)) {
        return -1;
    }

    int comparacion = strcmp(lexema, A->info.lexema);

    if (comparacion == 0 && A->info.inicializada == 1) {
        return A->info.inicializada;
    } else if (comparacion < 0) {
        return isInicializada(A->izq, lexema);
    } else if (comparacion > 0) {
        return isInicializada(A->der, lexema);
    } else {
        return -1;
    }
}


double recuperar_valor(abb A, char *lexema) {
    int comparacion = strcmp(lexema, A->info.lexema);

    if (comparacion == 0) {
        return A->info.valor.variable;
    } else if (comparacion < 0) {
        return recuperar_valor(A->izq, lexema);
    } else {
        return recuperar_valor(A->der, lexema);
    }
}



double executar_funcion(abb A, char *lexema, double valor) {
    int comparacion = strcmp(lexema, A->info.lexema);

    if (comparacion == 0) {
        return A->info.valor.funcion(valor);
    } else if (comparacion < 0) {
        return executar_funcion(A->izq, lexema, valor);
    } else {
        return executar_funcion(A->der, lexema, valor);
    }
}

double executar_funcion_multiple(abb A, char *lexema, double valor, double valor2) {
    int comparacion = strcmp(lexema, A->info.lexema);
    if (comparacion == 0) {
        return A->info.valor.funcion(valor, valor2);
    } else if (comparacion < 0) {
        return executar_funcion_multiple(A->izq, lexema, valor, valor2);
    } else {
        return executar_funcion_multiple(A->der, lexema, valor, valor2);
    }
}





