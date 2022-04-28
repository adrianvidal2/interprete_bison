#ifndef TABOASIMBOLOS_TABOASIMBOLOS_H_


/*FUNCIÓN MODIFICACIÓN*/
void inicializarTaboa();
void destruirTaboa();
double eliminarWorkspace();

/*FUNCIÓNS DE IMPRESIÓN*/
double imprimirTaboa();
double imprimirWorkspace();

/*FUNCIÓNS DE INSERCIÓN*/
void insertarFuncion(char *nome, int code, void *func);
void insertarVariable(char *lexema, double valor);

/*FUNCIÓNS DE BÚSQUEDA E RECUPERACIÓN*/
int buscarNumero(char *lexema, int codigo);
int buscarKeyword(char *lexema);
int buscarLibreria(char *lexema);
int is_inicializada(char *lexema);

double recuperarValor(char *lexema);

/*FUNCIÓNS DE EXECUCIÓN DE FUNCIÓNS EXTERNAS*/
double executarFuncion(char *lexema, double valor);
double executarFuncionMultiple(char *lexema, double valor, double valor2);
double executar(char *nomeFuncion);
double funcionCarga(char *funcion,char *nomeArquivo);

double executarExterna(char *conxunto,char *libreria,char *nomeFuncion, double valor);
double executarExternaMultiple(char *conxunto, char *libreria, char *nomeFuncion, double valor1, double valor2);
#endif /* TABOASIMBOLOS_TABOASIMBOLOS_H_ */
