# **CPP Module 00**

### Introducción

Para aprender a ... primeras nociones de c++ y de la programación orientada a objetos.

### Conceptos nuevos
- namespaces: qué son, cómo se usan... Un namespace es una forma de organizar el código y evitar conflictos entre nombres. std es el namespace de la biblioteca estándar de C++. Sintaxis para llamar a una función de la biblioteca estándar de C++:
      std::<función>
      ej.: std::cout
  Pero aparte del namespace, también hay que incluir las librerias en las que están estas funciones.

--------------------

### Clases en la Programación Orientada a Objetos (POO)
- Clases: una clase es una plantilla que define la estructura y el comportamiento de un objeto. Describe qué datos (atributos) y acciones/funciones (métodos) tendrán los objetos que se creen a partir de ella.
- Un objeto es una instancia concreta de una clase, que puede tener sus propios valores de atributos, pero que comparte la estructura y los métodos de la clase.
  
#### Elementos de una clase: 
- **Constructor:** método especial de una clase que se llama automáticamente al crear un objeto. Puede ser:
  - Constructor vacío (default)
  - Constructor con parámetros (para inicializar atributos al crear el objeto)
  - Con valores por defecto para los parámetros
  - **Initialization list**: permite inicializar atributos directamente antes del cuerpo del constructor. Especialmente útil par atributos const o referencias.
            MyClass(int val) : x(val) {}
  - ¿Siempre hay que inicializar los atributos privados? No es obligatorio si el tipo tiene un constructor por defecto (como int o std::string), pero es buena práctica para evitar valores indeterminados.
- **Destructor:** método especial que se llama automáticamente cuando un objeto deja de existir. Se usa para liberar recursos, cerrar archivos, liberar memoria dinámica, etc.
- **Elementos privados y públicos:**
  - public: accesible desde fuera de la clase
  - private: accesible solo desde dentro de la clase
  - **Encapsulación:** agrupa datos y funciones, protege los datos internos. 
    - **Ventaja de atributos privados con getters/setters:** permite validar datos antes de asignarlos; aporta flexibilidad (si cambias el tipo de dato interno, no es necesario modificar todo el código, solo los getters/setters).
- **Atributos miembro:** variables que representan el estado interno del objeto
- **Métodos miembro:** operadores o funciones definidos dentro de la clase, que pueden interactuar con los atributos objeto.
- **Funciones miembro 'static':** una función es 'static' cuando no depende de un objeto concreto, sino que pertenece a la clase en sí. No puede acceder a atributos no estáticos (que pertenecen a objetos), solo a otros atributos/métodos 'static'. Útil para contadores globales, helpers que aplican a la clase completa, o información compartida entre todos los objetos.
- **Acceso a atributos/métodos dentro de la clase:**
  - 'this->atributo': referencia al atributo del objeto actual.
  - 'Clase::atributo': referencia a un atributo o método estático de la clase.

#### Ventajas de usar clases: 
- Encapsulación: datos y funciones relacionadas se agrupan en el mismo bloque
- Reutilización
- Abstracción
- Organización y claridad: modularidad

-----------------------
Para ex02: diferencias entre dos archivos: vimdiff file1 file2

Más infor:
String class -> https://cplusplus.com/reference/string/string/#google_vignette
IO Manipultors -> https://cplusplus.com/reference/iomanip/
Guideline ->	https://42-cursus.gitbook.io/guide/4-rank-04/cpp-00-04-doing/cpp00
