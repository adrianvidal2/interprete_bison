#include "taboaSimbolos.h"
#include "y.tab.h"
#include "recursos.h"

int main() {
    imprimirBenvida();
    inicializarTaboa();
    yyparse();
    destruirTaboa();
}
