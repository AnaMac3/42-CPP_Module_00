# **CPP Module 00**

### Introducción

Para aprender a ... primeras nociones de c++ y de la programación orientada a objetos.

### Conceptos nuevos
- namespaces: qué son, cómo se usan... Un namespace es una forma de organizar el código y evitar conflictos entre nombres. std es el namespace de la biblioteca estándar de C++. Sintaxis para llamar a una función de la biblioteca estándar de C++:
      std::<función>
      ej.: std::cout
  Pero aparte del namespace, también hay que incluir las librerias en las que están estas funciones.


- clases: qué son, para qué se usan, elementos (función constructora, initialization lists, member functions, member atributes - atributos de instancia, atributos estáticos... -)
    - Constructor: método especial de una clase que se llama automáticamente cuando se crea un nuevo objeto de esa clase. Se puede tener un constructor vacio y uno que haga algo, al que se le llame con argumentos... Se pueden especificar valores por defecto.
          - Initialization list: pone el atributo de clase en base al valor entre paréntesis (siempre es obligatorio inicializar los atributos privados??)
    - Destructor
    - Elementos privados y públicos -> es público aquello a lo que se puede acceder desde fuera de la clase y privado aquello a lo que solo se accede desde dentro de la clase. Encapsulación... Ventaja de tener atributos privados y getters y setters para acceder a ellos -> con setters, puedes validar los datos antes de guardarlos. Otra ventaja: flexibilidad -> si en el futuro quieres cambiar el tipo de dato que es un atributo, si es público, tienes que cambiar todas las partes del código; con getters/setters, solo modificas la implementación interna.

Principio de encapsulación...
  
    - Atributos miembro
    - Métodos miembro: operadores o funciones declarados como miembros en una clase.


Para ex02: diferencias entre dos archivos: vimdiff file1 file2

Más infor:
String class -> https://cplusplus.com/reference/string/string/#google_vignette
IO Manipultors -> https://cplusplus.com/reference/iomanip/
Guideline ->	https://42-cursus.gitbook.io/guide/4-rank-04/cpp-00-04-doing/cpp00
