#ifndef ABB_H
#define ABB_H


typedef struct celda * abb;

/*FUNCIÓNS MODIFICACIÓN*/
void crear(abb *A);
void destruir(abb *A);
void eliminar_workspace(abb *A);


/*OPERACIÓNS DE INFORMACIÓN*/
unsigned es_vacio(abb A);
abb izq(abb A);
abb der(abb A);

/*FUNCIÓNS DE INSERCIÓN*/
void insertarFuncion(abb *A, char *nome, void *func);
void insertarConstante(abb *A, char *nome, double valor);
int insertar_variable(abb *A, char *nome, double valor);
int crear_variable(abb *A, char *var);

/*FUNCIÓNS DE IMPRESIÓN*/
void imprimir_tabla(abb *A);
void imprimir_workspace(abb *A);

/*FUNCIÓNS DE BÚSQUEDA E RECUPERACIÓN*/
int buscar_numero(abb A, char *lexema, int codigo);
int isInicializada(abb A, char *lexema);
double recuperar_valor(abb A, char *lexema);


/*FUNCIÓNS DE EXECUCIÓN DE FUNCIÓNS EXTERNAS*/
double executar_funcion(abb A,char *lexema ,double valor);
double executar_funcion_multiple(abb A, char *lexema, double valor, double valor2);


#endif	// ABB_H

