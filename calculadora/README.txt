COMPILACIÓN:
	- Envíase un MAKEFILE que facilitará a compilación do programa.
	- Este MAKEFILE deberá estar situado no mesmo directorio que o resto de arquivos
	- Nunha terminal situada no directorio, executar o comando make

EXECUCIÓN:
	- O programa permite dous tipos de execución:
	
						./calculadora
						./calculadora [[-]l <ficheiro>]
						
	- Permite a execución normal ou comezar a execución dende un ficheiro.
	- O ficheiro non ten porque estar no mesmo directorio que o resto de arquivos, tendo que indicar así a ruta deste.

CONSIDERACIÓNS:
	- Realizouse a implementación de importacións de librerías dunha maneira dinámica, podendo así usar múltiples librerías a vez.
	- Considerando que unha función pode ter o mesmo nome en diferentes librerías, optouse por unha elección da representación da ruta de cada nome. Por exemplo, para chamar a función sin da librería
	matemática, faríase da seguinte forma:
	
								math/sin(2)
								
	- As librerías propias do usuario, deben cargarse a través do .so. Non teñen porque estar no mesmo directorio e a súa execución realizariase da mesma maneira que a explicada no punto anterior.
	Exemplo:
	
								librería situada en /home/xx/xx/libreria.so
								import(/home/xx/xx/libreria.so)
								libreria/sin(2)
	
	- Proporciónase o código dunha librería e o código obxeto desta para poder realizar a proba. Es librería conta con unha función redefinida (sin()).
	
TÁBOA DE SÍMBOLOS:
	- Para esta práctica, implementouse unha árbore AVL pois tivose en conta, que pode ter unha cantidade o suficientemente grande de símbolos, o que faría ineficiente o uso dunha árbore binaria
	de búsqueda.
	

VERSIÓNS:
	- Ubuntu: 21.10
	- Kernel: 5.13.0-37-generic
	- GCC: 11.2.0 (Ubuntu 11.2.0-7ubuntu2)
								
