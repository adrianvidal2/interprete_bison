#ifndef AVL_LIBRARY_H
typedef struct celdaAVL * avl;

void crear(avl *AVL);
void destruirLibrerias(avl *AVL);
void destruirAVL(avl *AVL);
double eliminar_workspace(avl *AVL);

void insertarLibreria(avl *AVL, char *nomeLib, void *puntLib);
void insertar_funcion(avl *AVL, char *nome, int codigo, void *func);
void insertarComponhente(avl *AVL, char *nome, int codigo, double valor);

int buscar_libreria(avl *AVL, char *nome);
int buscar_numero(avl AVL, char *lexema, int codigo);
int buscar_executables(avl AVL, char *lexema);
int isInicializada(avl AVL, char *lexema);

void * recuperarLibreria(avl *AVL, char *nome);
double recuperar_valor(avl AVL, char *lexema);

void imprimir_tabla(avl *AVL);
void imprimir_workspace(avl *AVL);

double executar_funcion(avl AVL, char *lexema, double valor);
double executar_funcion_multiple(avl AVL, char *lexema, double valor, double valor2);
double executar_funcion_simple(avl AVL, char *nomeFuncion);
double funcion_carga(avl AVL, char * funcion, char *nomeArquivo);
#endif //AVL_LIBRARY_H
