#Opcións de compilación (Warnings all)
CC=gcc -Wall

#Carpeta das cabeceiras
HEADER_FILES_DIR=.

#Opcións de compilación, indica onde están os arquivos .h
INCLUDES=-I $(HEADER_FILES_DIR)

#nome do executable
OUTPUT=calculadora

#fontes
SOURCES= main.c avl.c taboaSimbolos.c xestionErros.c y.tab.c lex.yy.c recursos.c
#arquivos .h
LIB_HEADERS=$(HEADER_FILES_DIR)/avl.h constantes.h definicions.h erros.h funcions.h taboaSimbolos.h xestionErros.h y.tab.h lex.yy.h recursos.h

#arquivos .o, un análogo a cada .c
OBJS= $(SOURCES:.c=.o)

#regla do executable
$(OUTPUT): $(OBJS)
	$(CC) -o $(OUTPUT) $(OBJS) $(LIBS) -lm -ldl

#regla que xera os .o cando é necesario.
#$@ será o nome dos arquivos xerados coa regla
#$< nome dos arquivos .c
%.o: %.c $(LIB_HEADEADERS)
	$(CC) -c -o $@ $< $(INCLUDES) -lm -ldl

#eliminación do executable (prerrequisito: clean)
cleanall: clean
	rm -f $(OUTPUT)

#eliminación dos arquivos .o e backups
clean:
	rm -f *.o *~
