#ifndef TABOASIMBOLOS_TABOASIMBOLOS_H_


/*FUNCIÓN MODIFICACIÓN*/
void inicializarTaboa();
void destruirTaboa();
void eliminarWorkspace();

/*FUNCIÓNS DE IMPRESIÓN*/
void imprimirTaboa();
void imprimirWorkspace();

/*FUNCIÓNS DE INSERCIÓN*/
int insertarVariable(char *lexema, double valor);
int crearVariable(char *lexema);

/*FUNCIÓNS DE BÚSQUEDA E RECUPERACIÓN*/
int buscarNumero(char *lexema, int codigo);
int is_inicializada(char *lexema);
double recuperarValor(char *lexema);

/*FUNCIÓNS DE EXECUCIÓN DE FUNCIÓNS EXTERNAS*/
double executarFuncion(char *lexema, double valor);
double executarFuncionMultiple(char *lexema, double valor, double valor2);

#endif /* TABOASIMBOLOS_TABOASIMBOLOS_H_ */
