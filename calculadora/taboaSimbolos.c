#include <stdio.h>
#include "avl.h"
#include "definicions.h"
#include "taboaSimbolos.h"
#include "lex.yy.h"
#include <math.h>
#include <dlfcn.h>
#include "recursos.h"
#include "constantes.h"

/*Representation of the symbol table*/
avl arboreSimbolos;
avl arboreLibrerias;


/*ESTRUCTURAS PARA FUNCIÓN PREDEFINIDAS*/
struct funcion {
    char *nome;
    int codigo;

    double (*funcion)();
};

double aperturaLibreria(char *nome);

/*FUNCIÓNS RESERVADAS PARA USOS ESPECIAIS*/
struct funcion reservadas[] = {
        {"sair", SAIR_COD, sair},
        {"taboa", TABOA_COD, imprimirTaboa},
        {"workspace", WORKSPACE_COD, imprimirWorkspace},
        {"eliminar", ELIMINAR_WORKSPACE_COD, eliminarWorkspace},
        {"import", IMPORT_COD, aperturaLibreria},
        {"load", LOAD_COD, apertura_arquivo},
        {"axuda", AXUDA_COD, imprimirAxuda},
        {0, 0, 0}
};

//Inicialización da táboa de símbolos
void inicializarTaboa() {
    crear(&arboreSimbolos);
    crear(&arboreLibrerias);
    for (int i = 0; constantes[i].nome != 0; i++) {
        insertarComponhente(&arboreSimbolos, constantes[i].nome, CONSTANTE_COD, constantes[i].valor);
    }

    for (int i = 0; reservadas[i].nome != 0; i++) {
        insertar_funcion(&arboreSimbolos, reservadas[i].nome, reservadas[i].codigo, reservadas[i].funcion);
    }
}

//Destrución das dúas árbores avl utilizadas
void destruirTaboa() {
    destruirLibrerias(&arboreLibrerias);
    destruirAVL(&arboreSimbolos);
}

//Eliminación do workspace
double eliminarWorkspace() {
    return eliminar_workspace(&arboreSimbolos);
}

//Impresión da táboa de símbolos
double imprimirTaboa() {
    printf("========================================== TABOA SÍMBOLOS ==========================================\n");
    printf("NOME %27s%19s%26s%22s\n", "CODIGO", "VALOR", "FUNCION", "INICIALIZADA");
    imprimir_tabla(&arboreSimbolos);
    printf("====================================================================================================\n\n");
    return 0;
}

//Impresión do workspace
double imprimirWorkspace() {
    printf("=================== WORKSPACE ===================\n");
    printf("NOME%28s%17s\n", "VALOR", "INICIALIZADA");
    imprimir_workspace(&arboreSimbolos);
    printf("=============================================\n\n");
    return 0;
}

//Inserción de funcións
void insertarFuncion(char *nomeFuncion, int code, void *func) {
    insertar_funcion(&arboreSimbolos, nomeFuncion, code, func);
}

//Inserción de variables
void insertarVariable(char *lexema, double valor) {
    insertarComponhente(&arboreSimbolos, lexema, VARIABLE_COD, valor);
}

//Busca de variables e constantes
int buscarNumero(char *lexema, int codigo) {
    return buscar_numero(arboreSimbolos, lexema, codigo);
}

//Busca de funcións predefinidas
int buscarKeyword(char *lexema) {
    return buscar_executables(arboreSimbolos, lexema);
}

//Busca de librerias
int buscarLibreria(char *lexema) {
    return buscar_libreria(&arboreLibrerias, lexema);
}

//Comprobación de inicialización de variables
int is_inicializada(char *nome) {
    return isInicializada(arboreSimbolos, nome);
}

//Recuperación do valor dunha variable
double recuperarValor(char *lexema) {
    return recuperar_valor(arboreSimbolos, lexema);
}

//Execución dunha función con un único parámetro
double executarFuncion(char *lexema, double valor) {
    return executar_funcion(arboreSimbolos, lexema, valor);
}

//Execución de función con múltiples parámetros
double executarFuncionMultiple(char *lexema, double valor, double valor2) {
    return executar_funcion_multiple(arboreSimbolos, lexema, valor, valor2);
}

//Execución dunha función predefinida
double executar(char *nomeFuncion) {
    return executar_funcion_simple(arboreSimbolos, nomeFuncion);
}

//Carga dun script
double funcionCarga(char *funcion, char *nomeArquivo) {
    return funcion_carga(arboreSimbolos, funcion, nomeArquivo);
}


char *obterNomeLibreria(char *libreria) {
    char *nome;

    if (strstr(libreria, "/") == NULL) {
        nome = strtok(libreria, ".");
    } else {
        for (int i = strlen(libreria) - 1; i >= 0; i--) {
            if (libreria[i] == '/') {
                nome = strtok(&libreria[i + 1], ".");
                break;
            }
        }
    }
    return nome;

}

double aperturaLibreria(char *nomeLibreria) {
    void *lib;
    char *nome;
    nome = strdup(nomeLibreria);
    strtok(nome, ".");

    if (!buscar_libreria(&arboreLibrerias, nome)) {
        if ((lib = apertura_lib(nomeLibreria)) != NULL) {
            insertarLibreria(&arboreLibrerias, obterNomeLibreria(nomeLibreria), lib);
        }
        free(nome);
        free(nomeLibreria);
        return 1;
    }
    free(nome);
    free(nomeLibreria);
    return 0;

}

double executarExterna(char *conxunto, char *libreria, char *nomeFuncion, double valor) {
    if (isnan(valor)) {
        printf("[ERROR] O parámetro introducido non é válido...\n");
        return NAN;
    }
    void *lib = recuperarLibreria(&arboreLibrerias, libreria);

    return executar_externa(conxunto, lib, nomeFuncion, valor);

}


double executarExternaMultiple(char *conxunto, char *libreria, char *nomeFuncion, double valor1, double valor2) {
    if (isnan(valor1) || isnan(valor2)) {
        printf("[ERROR] Parámetro/s inválido/s...\n");
        return NAN;
    }
    void *lib = recuperarLibreria(&arboreLibrerias, libreria);

    return executarExternaMult(conxunto, lib, nomeFuncion, valor1, valor2);
}
