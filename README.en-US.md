# Interpreter analyzer with Flex

[Español](README.md)

Implementatios of a **mathematical calculator** that would allow basic mathematical operations, as well as more complex operations. This interpreter is generated from the **Bison** and **Flex** tools. The symbol table used consists of a self-balancing binary search tree (BST) structure developed in the **C** language.

This practice has been carried out for the subject *Compilers and Interpreters*.

## IDE
Visual Studio Code

## Available files
- **main.c**: program execution code.
- **tablaSimbolos.h** y **tablaSimbolos.c**: header and implementation of what will be the symbol table that will contain the different variables created and functions used.
- **avl.h** y **avl.c**: header and implementation of the self-balancing binary search tree that will be the structure that represents the symbol table.
- **analizadorSintactico.y** : implementation by Bison of the different behaviors of the interpreter.
- **xestionErros.h** y **xestionErros.c": header and implementation of the different types of errors.
- **erros.h**: definition of the types of errors that can occur.
- **definicions.h**: definition of constants for the different types of tokens that can occur.
- **concurrentSum.go**: file with a basic implementation of a program written in the *GO* language and that you want to analyze.
- **libreria.c** y **libreria.so**: header and compilation of an exmaple library to help understand the use of these (it implements a function sin different from the sin function provided by *math.h*).
- **analizadorLexico.l**: implementation using Flex for the recognition of the different lexical components.
- **recursos.h** y **recursos.c**: header and implementation of the functions that will show the help and deal with the import of libraries.

## Compilation and execution
For the compilation of the files mentioned above a *Makefile* is provided. The files must all be found in the same place.

```
cd <carpeta-implementacion>
make
```

The name of the generated executable will be *calculadora*. Two types of execution are allowed:

- Normal execution.
- Run from a file (can be in any directory).

```
./calculadora

./calculadora [[-]]l <file>]
```

If the file is not in the same folder, the path of the directory in which it is located must be indicated.

You can run the following command to remove all object files.

```
make clean
```

You can run the following command to remove all object files and the executable

```
make cleanall
```
## Incorporated operations
- *axuda* -> Shows the help of the program.
- *taboa* -> Shows the global symbol table (variables, constants, and functions).
- *workspace* -> Printing of variables and their values used so far.
- *eliminar* -> Delete workspace.
- *import(lib)* -> Import library lib.
- *load(file)* -> Execution of the operations contained in the file.
- *sair* -> Exit.


## Use of libraries
The import of libraries has been implemented dynamically, allowing the use of multiples libraries at the same time. Considering that a function may have the same time in different libraries, I have chosen a choice of representation of the path of each name. For example, the use of the function without the mathematical library would be done:

```
math/sin(2)
```


A user's own libraries must be loaded through the *.so*. These do not have to be in the same directory and their execution will be done in the same way as explained above.

 ```
library located in /home/xx/xx/libreria.so
```

```
import(/home/xx/xx/libreria.so)
libreria/sin(2)
```


## Improvements to consider
- Improvement in the implemented symbol table.
- Improvement in the erros system.

## Author

[Adrián Vidal Lorenzo](https://github.com/adrianvidal2)
