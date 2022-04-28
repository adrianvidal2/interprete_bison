#include "taboaSimbolos.h"
#include "y.tab.h"
#include "lex.yy.h"
#include "recursos.h"
#include "unistd.h"

int main(int argc, char *argv[]) {
    imprimirBenvida();
    inicializarTaboa();
    if (argc == 3) {
        int opcion;
        if ((opcion = getopt(argc, argv, "l")) != -1) {
            switch (opcion) {
                case '?':
                    printf("Argumentos: ./calculadora [[-]l <ficheiro>]\n");
                    return EXIT_FAILURE;
                case 'l':
                    apertura_arquivo(argv[2]);
                    break;
            }
        }
    } else if (argc > 3) {
        printf("Número de agurmentos incorrecto\n");
        printf("Argumentos: ./calculadora [[-]l <ficheiro>]\n");
        return EXIT_FAILURE;
    }

    yyparse();
    destruirTaboa();
    return EXIT_SUCCESS;
}
