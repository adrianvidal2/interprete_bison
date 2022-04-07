#include <stdio.h>
#include <stdlib.h>
#include "abb.h"
#include "definicions.h"
#include "taboaSimbolos.h"
#include "funcions.h"
#include "constantes.h"

/*Representation of the symbol table*/
abb arbore;

//Creating table and inserting keywords in the table
void inicializarTaboa() {
    crear(&arbore);

    for (int i = 0; aritmeticas[i].nomeFuncion != 0; i++) {
        insertarFuncion(&arbore, aritmeticas[i].nomeFuncion, aritmeticas[i].funcion);
    }

    for (int i = 0; constantes[i].nome != 0; i++) {
        insertarConstante(&arbore, constantes[i].nome, constantes[i].valor);
    }
}

//Destruction of the table
void destruirTaboa() {
    destruir(&arbore);
}

void eliminarWorkspace() {
    eliminar_workspace(&arbore);
}

//Print table
void imprimirTaboa() {
    printf("=================================== TABOA SÍMBOLOS ==================================\n");
    printf("NOME %20s%20s%20s%20s\n", "CODIGO", "VALOR", "FUNCION", "INICIALIZADA");
    imprimir_tabla(&arbore);
    printf("=====================================================================================\n\n");

}

void imprimirWorkspace() {
    printf("================= WORKSPACE =================\n");
    printf("NOME %20s%20s\n", "VALOR", "INICIALIZADA");
    imprimir_workspace(&arbore);
    printf("=============================================\n\n");
}

int insertarVariable(char *lexema, double valor) {
    return insertar_variable(&arbore, lexema, valor);
}

int crearVariable(char *lexema) {
    if (!buscar_numero(arbore, lexema, VARIABLE_COD) && !buscar_numero(arbore, lexema, CONSTANTE_COD) &&
        !buscar_numero(arbore, lexema, FUNCION_COD)) {
        return crear_variable(&arbore, lexema);
    } else {
        return 0;
    }
}

int buscarNumero(char *lexema, int codigo) {
    return buscar_numero(arbore, lexema, codigo);
}

int is_inicializada(char *nome) {
    return isInicializada(arbore, nome);
}



double recuperarValor(char *lexema) {
    return recuperar_valor(arbore, lexema);
}

double executarFuncion(char *lexema, double valor) {
    return executar_funcion(arbore, lexema, valor);
}

double executarFuncionMultiple(char *lexema, double valor, double valor2) {
    return executar_funcion_multiple(arbore, lexema, valor, valor2);
}

