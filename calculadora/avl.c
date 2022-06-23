#include "avl.h"
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <dlfcn.h>
#include <math.h>
#include "definicions.h"

typedef struct {
    void *punteiro;
} libreria;

typedef struct {
    int inicializada;

    union {
        double variable;

        double (*funcion)();
    } valor;
} simbolos;

struct celdaAVL {
    char *nome;
    int codigo;
    union {
        libreria lib;
        simbolos simb;
    } info;
    int fe;
    int altura;
    struct celdaAVL *izq, *der;
};


unsigned es_vacio(avl AVL) {
    return AVL == NULL;
}


/* * * * * * * * * * * * * * * * * * *
 *                                   *
 *          Funcións privadas        *
 *                                   *
 * * * * * * * * * * * * * *  * *  * */

int _max(int a, int b) {
    return a > b ? a : b;
}
//Cálculo da altura de un nodo
int _novaAltura(struct celdaAVL *nodo) {
    if (nodo == NULL)
        return 0;
    return (1 + _max(_novaAltura(nodo->izq), _novaAltura(nodo->der)));
}
//Cálculo do factor de equilibrio dun nodo
int _obterEquilibrio(struct celdaAVL *nodo) {
    if (nodo == NULL)
        return 0;
    //Cálculo do factor de equilibrio, diferenza de alturas entre subárbores do nodo
    return _novaAltura(nodo->der) - _novaAltura(nodo->izq);
}
//Rotación dereita para a árbore
void _rotarDereita(avl *AVL) {
    //Rotación esquerda esquerda
    struct celdaAVL *esquerda = (*AVL)->izq;
    struct celdaAVL *esquerda_dereita = esquerda->der;
    //O nodo raíz pasa a ser o elemento que colga a esquerda do nodo actual. O nodo actual pasa a ser nodo dereito.
    (*AVL)->izq = esquerda_dereita;
    esquerda->der = *AVL;
    (*AVL) = esquerda;
    (*AVL)->fe = _obterEquilibrio(*AVL);
    (*AVL)->der->fe = _obterEquilibrio((*AVL)->der);
}
//Rotación esquerda para a árbore
void _rotarEsquerda(avl *AVL) {
    //Rotación dereita dereita
    struct celdaAVL *dereita = (*AVL)->der;
    struct celdaAVL *dereita_izquierda = dereita->izq;

    //O nodo raíz pasa a ser o nodo que colga a dereita do nodo actual. O nodo actual pasa a ser o nodo esquerdo
    (*AVL)->der = dereita_izquierda;
    dereita->izq = *AVL;
    (*AVL) = dereita;
    (*AVL)->fe = _obterEquilibrio(*AVL);
    (*AVL)->izq->fe = _obterEquilibrio((*AVL)->izq);
}
//Cálculo do equilibrio da árbore
void _equilibrio(avl *AVL, char *lexema) {
    int equilibrio = _obterEquilibrio(*AVL);

    //Se o equilibrio do nodo actual e igual a -2 significa que hai unha descompesación pola esquerda
    if (equilibrio == -2 && strcmp(lexema, (*AVL)->izq->nome) < 0) {
        _rotarDereita(&(*AVL));
    } else if (equilibrio == 2 && strcmp(lexema, (*AVL)->der->nome) > 0) {  //Se o equilibrio do nodo actual e igual a 2 significa que hai unha descompesación pola dereita
        _rotarEsquerda(&(*AVL));
    } else if (equilibrio == 2 && strcmp(lexema, (*AVL)->der->nome) < 0) {  //fe->nodo == 2 e nodo->esquerda fe == -1
        _rotarDereita(&(*AVL)->der);
        _rotarEsquerda(&(*AVL));
    } else if (equilibrio == -2 && strcmp(lexema, (*AVL)->izq->nome) > 0) { //fe->nodo == -2 e nodo->dereita fe == 1
        _rotarEsquerda(&(*AVL)->izq);
        _rotarDereita(&(*AVL));
    }

}
//Recuperación do nodo máis pequeno
struct celdaAVL _minSubArbol(avl *AVL) {

    avl aux;
    struct celdaAVL min;
    //Recuperación do nodo máis pequeno que se atope na subárbore dereita, retornando dito elemento e liberando o nodo
    if (es_vacio((*AVL)->izq)) {
        min.nome = (*AVL)->nome;
        min.codigo = (*AVL)->codigo;
        min.info.simb.valor.variable = (*AVL)->info.simb.valor.variable;
        min.info.simb.inicializada = (*AVL)->info.simb.inicializada;
        aux = *AVL;
        *AVL = (*AVL)->der;
        free(aux);
        return min;
    } else {
        return _minSubArbol(&(*AVL)->izq);
    }
}
//Eliminación do nodo da árbore
void _suprimir(avl *AVL) {
    avl auxiliar;
    //Se se trata dun nodo follo, realízase a eliminación normal
    if (es_vacio((*AVL)->izq) && es_vacio((*AVL)->der)) {
        if ((*AVL)->nome != NULL) {
            free((*AVL)->nome);
            (*AVL)->nome = NULL;
            free(*AVL);
            *AVL = NULL;
        }
    } else if (es_vacio((*AVL)->der)) { //Se conta con un fillo esquerdo e non dereito , o nodo pasará a ser o fillo esquerdo, eliminando o actual
        auxiliar = (*AVL);
        (*AVL) = (*AVL)->izq;
        if (auxiliar->nome != NULL) {
            free(auxiliar->nome);
            auxiliar->nome = NULL;
        }
        free(auxiliar);
    } else if (es_vacio((*AVL)->izq)) { //Se conta con un fillo dereito e non esquerdo , o nodo pasará a ser o fillo dereito, eliminando o actual
        auxiliar = (*AVL);
        (*AVL) = (*AVL)->der;
        if (auxiliar->nome != NULL) {
            free(auxiliar->nome);
            auxiliar->nome = NULL;
        }
        free(auxiliar);
    } else {                                //Se conta cos dous fillos, o nodo actual pasará o ser o máis pequeno da subárbore esquerda, eliminando o actual e recalculando o equilibrio
        if ((*AVL)->nome != NULL) {
            free((*AVL)->nome);
            (*AVL)->nome = NULL;
        }
        struct celdaAVL celda = _minSubArbol(&(*AVL)->der);
        (*AVL)->nome = celda.nome;
        (*AVL)->codigo = celda.codigo;
        (*AVL)->info.simb.valor.variable = celda.info.simb.valor.variable;
        (*AVL)->info.simb.inicializada = celda.info.simb.inicializada;

        if (celda.codigo == VARIABLE_COD) {
            _suprimir(&(*AVL));
        }

        _equilibrio(&(*AVL), celda.nome);
    }
}
//Eliminación dunha variable dunha subárbore
void _eliminar_var_subarbol(avl *AVL) {
    if (!es_vacio((*AVL))) {

        //Compróbase se o fillo esquerdo ou dereito é unha variable
        if (!es_vacio((*AVL)->izq) && (*AVL)->izq->codigo == VARIABLE_COD) {
            _suprimir(&(*AVL)->izq);
        }

        if (!es_vacio((*AVL)->der) && (*AVL)->der->codigo == VARIABLE_COD) {
            _suprimir(&(*AVL)->der);
        }

        //Recalculase o equilibrio
        (*AVL)->fe = _obterEquilibrio((*AVL));
        if (!es_vacio((*AVL))) {
            if ((*AVL)->fe == 2 && !es_vacio((*AVL)->der) && (*AVL)->der->fe >= 0) {
                _rotarEsquerda(&(*AVL));
            } else if ((*AVL)->fe == 2 && !es_vacio((*AVL)->der) && (*AVL)->der->fe < 0) {
                _rotarDereita(&(*AVL));
                _rotarEsquerda(&(*AVL));
            } else if ((*AVL)->fe == -2 && !es_vacio((*AVL)->izq) && (*AVL)->izq->fe <= 0) {
                _rotarDereita(&(*AVL));
            } else if ((*AVL)->fe == -2 && !es_vacio((*AVL)->izq) && (*AVL)->izq->fe > 0) {
                _rotarEsquerda(&(*AVL));
                _rotarDereita(&(*AVL));
            }
        }
        return;
    }
}

/* * * * * * * * * * * * * * * * * * *
 *                                   *
 *        Funcións de creación       *
 *           e destrución            *
 *                                   *
 * * * * * * * * * * * * * *  * *  * */
//Creación da árbore
void crear(avl *AVL) {
    *AVL = NULL;
}

//Destrución da árbore de librerías
void destruirLibrerias(avl *AVL) {
    if (*AVL != NULL) {
        destruirLibrerias(&(*AVL)->izq);    //Destrución dos fillos da rama esquerda
        destruirLibrerias(&(*AVL)->der);    //Destrución dos fillos da rama dereita
        if ((*AVL)->nome != NULL) {
            free((*AVL)->nome);
            (*AVL)->nome = NULL;
            if (dlclose((*AVL)->info.lib.punteiro)) {   //Péchase a librería aberta dinamicamente
                printf("[ERROR] peche da librería %s: %s\n", (*AVL)->nome, dlerror());
            }
        }

        free(*AVL);
        *AVL = NULL;
    }
}

//Eliminación do avl de constantes, variables e funcións
void destruirAVL(avl *AVL) {
    if (*AVL != NULL) {
        destruirAVL(&(*AVL)->izq);
        destruirAVL(&(*AVL)->der);
        if ((*AVL)->nome != NULL) {
            free((*AVL)->nome);
            (*AVL)->nome = NULL;
        }
        free(*AVL);
        *AVL = NULL;
    }
}

//Eliminación das variables utilizadas ata o momento
double eliminar_workspace(avl *AVL) {
    if (es_vacio(*AVL)) {
        return 0;
    }

    //Eliminanse as variables ata que non queden nodos por recorrer, realizando o reequilibrio en cada iteración
    if (!es_vacio(*AVL)) {
        _eliminar_var_subarbol(&(*AVL));
        (*AVL)->fe = _obterEquilibrio(*AVL);

        if ((*AVL)->fe == 2 && !es_vacio((*AVL)->der) && (*AVL)->der->fe >= 0) {
            _rotarEsquerda(&(*AVL));
        } else if ((*AVL)->fe == 2 && !es_vacio((*AVL)->der) && (*AVL)->der->fe < 0) {
            _rotarDereita(&(*AVL));
            _rotarEsquerda(&(*AVL));
        } else if ((*AVL)->fe == -2 && !es_vacio((*AVL)->izq) && (*AVL)->izq->fe <= 0) {
            _rotarDereita(&(*AVL));
        } else if ((*AVL)->fe == -2 && !es_vacio((*AVL)->izq) && (*AVL)->izq->fe > 0) {
            _rotarEsquerda(&(*AVL));
            _rotarDereita(&(*AVL));
        }
        eliminar_workspace(&(*AVL)->izq);
        eliminar_workspace(&(*AVL)->der);
        (*AVL)->fe = _obterEquilibrio(*AVL);

    }
    return 1;
}

/* * * * * * * * * * * * * * * * * * *  *
 *                                      *
 *        Funcións de inserción         *
 *                                      *
 * * * * * * * * * * * * * *  * *  * *  */
//Inserción de funcións
void insertar_funcion(avl *AVL, char *nome, int codigo, void *func) {
    if (es_vacio(*AVL)) {
        *AVL = (avl) malloc(sizeof(struct celdaAVL));
        (*AVL)->nome = (char *) malloc(sizeof(char) * strlen(nome) + 1);
        strncpy((*AVL)->nome, nome, strlen(nome) + 1);
        (*AVL)->nome[strlen(nome)] = '\0';
        (*AVL)->codigo = codigo;
        (*AVL)->info.simb.valor.funcion = func;
        (*AVL)->info.simb.inicializada = 1;
        (*AVL)->izq = NULL;
        (*AVL)->der = NULL;
        (*AVL)->fe = 0;
        return;
    }

    int comparacion = strcmp(nome, (*AVL)->nome);

    if (comparacion > 0) {
        insertar_funcion(&(*AVL)->der, nome, codigo, func);
    } else if (comparacion < 0) {
        insertar_funcion(&(*AVL)->izq, nome, codigo, func);
    }

    (*AVL)->fe = _obterEquilibrio(*AVL);

    _equilibrio(AVL, nome);
}

//Inserción de variables e constantes
void insertarComponhente(avl *AVL, char *nome, int codigo, double valor) {
    if (es_vacio(*AVL)) {
        *AVL = (avl) malloc(sizeof(struct celdaAVL));
        (*AVL)->nome = (char *) malloc(sizeof(char) * strlen(nome) + 1);
        strncpy((*AVL)->nome, nome, strlen(nome) + 1);
        (*AVL)->nome[strlen(nome)] = '\0';
        (*AVL)->codigo = codigo;
        (*AVL)->info.simb.valor.variable = valor;
        if (!isnan(valor)) (*AVL)->info.simb.inicializada = 1;
        else (*AVL)->info.simb.inicializada = 0;
        (*AVL)->izq = NULL;
        (*AVL)->der = NULL;
        (*AVL)->fe = 0;
        return;
    }

    int comparacion = strcmp(nome, (*AVL)->nome);

    if (!comparacion && (*AVL)->codigo == VARIABLE_COD) {
        (*AVL)->info.simb.valor.variable = valor;
        if (!isnan(valor)) (*AVL)->info.simb.inicializada = 1;
        else (*AVL)->info.simb.inicializada = 0;
    } else if (comparacion < 0) {
        insertarComponhente(&(*AVL)->izq, nome, codigo, valor);
    } else if (comparacion > 0) {
        insertarComponhente(&(*AVL)->der, nome, codigo, valor);
    }

    (*AVL)->fe = _obterEquilibrio(*AVL);
    _equilibrio(AVL, nome);
}

//Inserción de librerías
void insertarLibreria(avl *AVL, char *nomeLib, void *puntLib) {
    if (es_vacio(*AVL)) {
        *AVL = (avl) malloc(sizeof(struct celdaAVL));
        (*AVL)->nome = (char *) malloc(sizeof(char) * strlen(nomeLib) + 1);
        strncpy((*AVL)->nome, nomeLib, strlen(nomeLib) + 1);
        (*AVL)->nome[strlen(nomeLib)] = '\0';
        (*AVL)->codigo = LIB_COD;
        (*AVL)->info.lib.punteiro = puntLib;
        (*AVL)->izq = NULL;
        (*AVL)->der = NULL;
        (*AVL)->fe = 0;
        return;
    }

    int comparacion = strcmp(nomeLib, (*AVL)->nome);
    if (comparacion > 0) {
        insertarLibreria(&(*AVL)->der, nomeLib, puntLib);
    } else if (comparacion < 0) {
        insertarLibreria(&(*AVL)->izq, nomeLib, puntLib);
    }

    (*AVL)->fe = _obterEquilibrio(*AVL);

    _equilibrio(AVL, nomeLib);
}

/* * * * * * * * * * * * * * * * * * *
 *                                   *
 *          Funcións búsqueda        *
 *                                   *
 * * * * * * * * * * * * * *  * *  * */
//Busca dunha librería aberta
int buscar_libreria(avl *AVL, char *nome) {

    if (!es_vacio((*AVL))) {
        int comparacion = strcmp(nome, (*AVL)->nome);
        if (comparacion == 0) {
            return 1;
        } else if (comparacion > 0) {
            return buscar_libreria(&(*AVL)->der, nome);
        } else if (comparacion < 0) {
            return buscar_libreria(&(*AVL)->izq, nome);
        }
    }

    return 0;

}

//Busca dunha constante ou variable
int buscar_numero(avl AVL, char *lexema, int codigo) {
    if (es_vacio(AVL)) {
        return 0;
    }

    int comparacion = strcmp(lexema, AVL->nome);
    if (comparacion == 0 && AVL->codigo == codigo) {
        return AVL->codigo;
    } else if (comparacion < 0) {
        return buscar_numero(AVL->izq, lexema, codigo);
    } else {
        return buscar_numero(AVL->der, lexema, codigo);
    }
}

//Busca das funcións insertadas dende un inicio
int buscar_executables(avl AVL, char *lexema) {
    if (es_vacio(AVL)) {
        return 0;
    }
    int comparacion = strcmp(lexema, AVL->nome);
    if (comparacion == 0 &&
        (AVL->codigo == TABOA_COD || AVL->codigo == WORKSPACE_COD ||
         AVL->codigo == ELIMINAR_WORKSPACE_COD ||
         AVL->codigo == FUNCION_COD || AVL->codigo == SAIR_COD ||
         AVL->codigo == IMPORT_COD ||
         AVL->codigo == LOAD_COD || AVL->codigo == AXUDA_COD)) {
        return AVL->codigo;
    } else if (comparacion < 0) {
        return buscar_executables(AVL->izq, lexema);
    } else {
        return buscar_executables(AVL->der, lexema);
    }
}

//Busca da variable inicializada
int isInicializada(avl AVL, char *lexema) {
    if (es_vacio(AVL)) {
        return -1;
    }

    int comparacion = strcmp(lexema, AVL->nome);

    if (comparacion == 0 && AVL->info.simb.inicializada == 1) {
        return AVL->info.simb.inicializada;
    } else if (comparacion < 0) {
        return isInicializada(AVL->izq, lexema);
    } else if (comparacion > 0) {
        return isInicializada(AVL->der, lexema);
    } else {
        return -1;
    }
}

/* * * * * * * * * * * * * * * * * * *
 *                                   *
 *       Funcións recuperación       *
 *                                   *
 * * * * * * * * * * * * * *  * *  * */
//Devolución do punteiro para poder facer uso da librería aberta
void *recuperarLibreria(avl *AVL, char *nome) {
    if (!es_vacio((*AVL))) {
        int comparacion = strcmp(nome, (*AVL)->nome);
        if (comparacion == 0) {
            return (*AVL)->info.lib.punteiro;
        } else if (comparacion > 0) {
            return recuperarLibreria(&(*AVL)->der, nome);
        } else if (comparacion < 0) {
            return recuperarLibreria(&(*AVL)->izq, nome);
        }
    }

    return NULL;
}

//Recuperación do valor dunha variable
double recuperar_valor(avl AVL, char *lexema) {
    int comparacion = strcmp(lexema, AVL->nome);

    if (comparacion == 0) {
        return AVL->info.simb.valor.variable;
    } else if (comparacion < 0) {
        return recuperar_valor(AVL->izq, lexema);
    } else {
        return recuperar_valor(AVL->der, lexema);
    }
}

/* * * * * * * * * * * * * * * * * * *
 *                                   *
 *        Funcións impresión         *
 *                                   *
 * * * * * * * * * * * * * *  * *  * */

void imprimir_tabla(avl *AVL) {
    if (!es_vacio(*AVL)) {
        if (&(*AVL)->izq != NULL) {
            imprimir_tabla(&(*AVL)->izq);
            printf("%-10s ", (*AVL)->nome);
        }

        printf("%19d", (*AVL)->codigo);
        if ((*AVL)->codigo != VARIABLE_COD && (*AVL)->codigo != CONSTANTE_COD) {
            printf("%19s%27s%17d\n", "-", (*AVL)->nome, (*AVL)->info.simb.inicializada);
        } else {
            printf("%22lf%22s%19d\n", (*AVL)->info.simb.valor.variable, "-", (*AVL)->info.simb.inicializada);
        }

        if (&(*AVL)->der != NULL) {
            imprimir_tabla(&(*AVL)->der);
        }
    }
}

void imprimir_workspace(avl *AVL) {
    if (!es_vacio(*AVL)) {
        if (&(*AVL)->izq != NULL) {
            imprimir_workspace(&(*AVL)->izq);
        }

        if ((*AVL)->codigo == VARIABLE_COD) {
            printf("%-10s%22lf%12d\n", (*AVL)->nome, (*AVL)->info.simb.valor.variable, (*AVL)->info.simb.inicializada);
        }

        if (&(*AVL)->der != NULL) {
            imprimir_workspace(&(*AVL)->der);
        }
    }
}

/* * * * * * * * * * * * * * * * * * *
 *                                   *
 *        Funcións execución         *
 *                                   *
 * * * * * * * * * * * * * *  * *  * */
//Execución dunha función con un único parámetro
double executar_funcion(avl AVL, char *lexema, double valor) {
    int comparacion = strcmp(lexema, AVL->nome);

    if (comparacion == 0) {
        return AVL->info.simb.valor.funcion(valor);
    } else if (comparacion < 0 && !es_vacio(AVL->izq)) {
        return executar_funcion(AVL->izq, lexema, valor);
    } else if (comparacion > 0 && !es_vacio(AVL->der)) {
        return executar_funcion(AVL->der, lexema, valor);
    } else {
        return NAN;
    }

}

//Execución dunha función con dous parámetros
double executar_funcion_multiple(avl AVL, char *lexema, double valor, double valor2) {
    int comparacion = strcmp(lexema, AVL->nome);
    if (comparacion == 0) {
        return AVL->info.simb.valor.funcion(valor, valor2);
    } else if (comparacion < 0) {
        return executar_funcion_multiple(AVL->izq, lexema, valor, valor2);
    } else {
        return executar_funcion_multiple(AVL->der, lexema, valor, valor2);
    }
}

//Execución dunha función sen parámetros
double executar_funcion_simple(avl AVL, char *nomeFuncion) {
    int comparacion = strcmp(nomeFuncion, AVL->nome);
    if (comparacion == 0) {
        free(nomeFuncion);
        return AVL->info.simb.valor.funcion();
    } else if (comparacion < 0) {
        return executar_funcion_simple(AVL->izq, nomeFuncion);
    } else {
        return executar_funcion_simple(AVL->der, nomeFuncion);
    }
    return NAN;
}

//Carga dun arquivo
double funcion_carga(avl AVL, char *funcion, char *nomeArquivo) {
    int comparacion = strcmp(funcion, AVL->nome);
    if (comparacion == 0) {
        free(funcion);
        return AVL->info.simb.valor.funcion(nomeArquivo);
    } else if (comparacion < 0) {
        return funcion_carga(AVL->izq, funcion, nomeArquivo);
    } else {
        return funcion_carga(AVL->der, funcion, nomeArquivo);
    }
}