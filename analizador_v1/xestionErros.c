#include "xestionErros.h"
#include <stdio.h>

void tipoErro(int codigo, char *lexema, int linha) {
    switch (codigo) {
        case 1:
            printf("[ERRO] Variable %s non declarada\n", lexema);
            break;
        case 2:
            printf("[ERRO] %s é unha función\n", lexema);
            break;
        case 3:
            printf("[ERRO] Non se permite a mofificación de constantes\n");
            break;
        case 4:
            printf("[ERRO] Non se puido ler correctamente do ficheiro na liña: %d\n", linha);
            break;
        case 5:
            printf("[ERRO] Non se puido abrir o arquivo %s\n", lexema);
            break;
    }
}
