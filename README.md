# Intérprete con Bison y Flex
[English](README.en-US.md)

Implementación de un **calculadora matemática** que permitira operaciones básicas matemáticas, así como, operaciones más complejas. Este intérprete es generado a partir de las herramientas **Bison** y **Flex**. La tabla de símbolos utilizada consta de una estructura de árbol equilibrado de búsqueda (AVL) desarrollado en lenguaje **C**.

Esta práctica ha sido realizada para la asignatura de *Compiladores e Intérpretes*.

## IDE utilizado
Visual Studio Code
## Ficheros disponibles
- **main.c**: código de ejecución del programa.
- **tablaSimbolos.h** y **tablaSimbolos.c**: cabecera e implementación de lo que será la tabla de símbolos que contendrá las diferentes variables creadas y funciones utilizadas.
- **avl.h** y **avl.c**: cabecera e implementación del árbol equilibrado de búsqueda que será la estructura que representa la tabla de símbolos.
- **analizadorSintactico.y**: implementación mediante Bison de los diferentes comportamientos del intérprete.
- **xestionErros.h** y **xestionErros.c": cabecera e implementación de los diferentes tipos de errores.
- **erros.h**: definición de los tipos de errores que se pueden presentar.
- **definicions.h**: definición de constantes para los diferentes tipos de componentes léxicos que se pueden presentar.
- **libreria.c** y **libreria.so**: cabecera y compilación de una librería auxiliar para ayudar a entender el uso de estas (implementa una función sin diferente a la proporcionada por *math.h*).
- **analizadorLexico.l**: implementación mediante Flex para el reconocimiento de los diferentes componentes léxicos.
- **recursos.h** y **recursos.c**: cabecera e implementación de las funciones que mostrarán la ayuda y tratarán la importación de librerías.


## Compilation and execution
Para la compilación de los ficheros mencionados anteriormente se proporciona un *Makefile*. Los ficheros se deben encontrar todos en el mismo lugar.

```
cd <carpeta-implementacion>
make
```

El nombre del ejecutable generado será *calculadora*. Two types of execution are allowed:

- Ejecución normal.
- Ejecución a partir de un archivo (puede estar en cualquier directorio):

```
./calculadora

./calculadora [[-]]l <archivo>]
```

Si el archivo no se encuentra en la misma carpeta se debe indicar la ruta del directorio en el cual se encuentra.
Se puede ejecutar el siguiente comando para la eliminación de todos los archivos objeto.


```
make clean
```

Se puede ejecutar el siguiente comando para la eliminación de todos los archivos objeto y el ejecutable.
```
make cleanall
```

## Funciones incorporadas
- *axuda* -> Muestra la ayuda del programa.
- *taboa* -> Muestra la tabla de símbolos global (variables, constantes y funciones).
- *workspace* -> Impresión de las variables y sus valores utilizados hasta el momento.
- *eliminar* -> Eliminación del workspace.
- *import(lib)* -> Importación de librerias.
- *load(file)* -> Ejecución de las operaciones que contiene el archivo.
- *sair* -> Salida del programa.

## Uso de librerías
Se ha implementado la importación de librerías de forma dinámica, permitiendo así el uso de múltiples de estas al mismo tiempo. Teniendo en cuenta que una función puede tener el mismo nombre en diferentes librerías, se ha optado por una elección de representación de la ruta de cada nombre. Por ejemplo, el uso de la función sin de la librería matemática se realizaría:


```
math/sin(2)
```


Las librerías propias de un usuario, deben cargarse a través del *.so*. Estas no tienen porque encontrarse en el mismo directorio y su ejecución se realizará de la misma forma que la explicada anteriormente.

 ```
librería situada en /home/xx/xx/libreria.so
```
```
import(/home/xx/xx/libreria.so)
libreria/sin(2)
```


## Mejoras a considerar
- Mejora en la tabla de símbolos implementada.
- Mejora en el sistema de errores.

## Autor
[Adrián Vidal Lorenzo](https://github.com/adrianvidal2)
