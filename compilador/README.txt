
Esto es una maldita prueba de concepto, en base lo que ya tenemos medio definido y mi actual practica de compiladores, Hay mucho codigo por limpiar, y deberiamos pensar en refactorizar con calma y tranquilidad muchas cosas, para terminar con algo más leible. 

Listado de archivos:

Makefile:> Todos lo sabemos
test :> Carpeta contenedora de los juegos de pruebas.
 |- First:> El primer ejemplo de programa, hecho en obj-Fenix, si preguntan que fue antes el programa o el lenguaje, podremos decir que el programa :)
src :> Todo el meollo, 
 |- classes :> Carpeta creada inicialmente, no la utilize, se puede borrar el contenido, aunque creo que mejor conservar-la e intentar refactorizar ciertos archivos en distintos, y si podemos un poco de POO, mejor que mejor, porque hice una lista enlazada en C, de forma parecida a la POO, y deberiamos intentar usar POO.
 |- debug.cpp :> Teoricamente, todas las llamadas para depurar este compilador, deberian passar por las funciones de este archivo. Se activan y desactivan asignando o desasignando un archivo  para la salida.
 |- main.cpp :> Restos de la practica de compiladores, medio restructurado, y sacadas muchas funciones.
 |- main.h :> Lo se Lo se, no es normal que el main tenga un .h, pero... hay muchas funciones en el main que se requieren en los otros.
 |- symtab.c/h :> libreria de simbolos, muy potente, en el .h hay todas las estructuras de datos que se requieren en mi practica (Tambien se necesita refactorizar)
 |- lexical_analyzer.l :> Anda, si el nombre lo dice, estas son las reglas flex (expresiones regulares) para detectar todos los elementos primarios del bisson, este y bisson se comunican solitos.
 |- SemanticAnalisis.cpp :> El inicio del analisis semantico, este repassa todas las clases que previamente se han cargado a memoria, y para cada funcion la analiza y verifica.
 |- syntactic_parser_pract.y :> mas de 500 lineas de reglas del miniAda convinado con el analisis semantico del mismo, es como un suicidio pero sin el como.
 |- syntactic_parser.y :> este es el nuestro, Hasta donde yo he aprendido de bisson, de moment las reglas solo se pueden aplicar de forma descendente, o sea que tenemos el problema de que si usamos X antes de declaralo, no lo reconocera. 
 |- treeCode :> Las clases que representan el codigo que se esta compilando, es donde se hace el analisis semantico, y se deja el graph que representa el codigo limpio. 
 |- tools.cpp :> funciones y mas funciones utilizadas en otras partes del codigo.

 
 TODO:
	Refactorizar main.c y main.h para que solo contenga el void main void, y alguna cosilla pequeña mas. 
	 - Depurar la generacion del arbol, para solucionar algun pequeño problema, como no encontrar classes si se usan en los parametros de una funcion antes de nada.
	 - Posibilidad de crear variables privadas en un metodo, ya que actualmente, no hay opcion
	 - Reglas de Herencia en el analisis Sintactico, al igual que descapar alguna opción del arbol sintactico capado para facilitar el trabajo de depuracion;
	 - Terminar la generacion del arbol, para bucles i condiciones (al igual que montar el analisis para los bucles)
	 - Empezar a generar ByteCode, o algun tipo de salida pseudo-ejecutable. <Esto comporta crear clases para contener-lo>