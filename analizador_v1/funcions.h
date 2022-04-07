#ifndef INTERPRETEBISON_FUNCIONS_H
#define INTERPRETEBISON_FUNCIONS_H
#include "math.h"


struct funcions {
    char *nomeFuncion;
    double (*funcion)();
};

struct funcions aritmeticas[] = {
        {"sin",   sin},
        {"cos",   cos},
        {"tan",   tan},
        {"sqrt",  sqrt},
        {"asin",  asin},
        {"acos",  acos},
        {"atan",  atan},
        {"exp",   exp},
        {"log",   log},
        {"log10", log10},
        {"pow",   pow},
        {"ceil",  ceil},
        {"floor", floor},
        {"fabs",  fabs},
        {"fmax", fmax},
        {0,       0}
};


#endif //INTERPRETEBISON_FUNCIONS_H
