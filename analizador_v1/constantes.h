#ifndef INTERPRETEBISON_CONSTANTES_H


struct constante{
    char *nome;
    double valor;
};

struct constante constantes[] = {
        {"pi", 3.14159265358979323846},
        {"e", 2.71828182845904523536},
        {0,0}
};

#endif //INTERPRETEBISON_CONSTANTES_H
