#ifndef INTERPRETEBISON_RECURSOS_H

void imprimirBenvida();

double imprimirAxuda();

void * apertura_lib(char *nomeLibreria);
double executar_externa(char *conxunto,void *lib,char *nomeFuncion, double valor);
double executarExternaMult(char *conxunto, void *lib, char *nomeFuncion, double valor1, double valor2);
#endif //INTERPRETEBISON_RECURSOS_H
