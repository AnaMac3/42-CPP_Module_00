# **CPP Module 00**

42 Common Core CPP Module 00.  
- Object-Oriented Programming in C++
- Classes and objects
- Encapsulation and data hiding

## Table of Contents
- [Namespaces](#namespaces)
- [Classes in Object-Oriented Programming](#classes-in-object-oriented-programming)
- [More info](#more-info)

----------------------------------------

### Namespaces
A **namespace** is a declarative region that provides scope to identifiers (variables, functions, classes, etc.). Its main purpose is to organize code and avoid naming conflicts.
- The Standard Library is contained in the **std** namespace.
- To access elements from it, you must:
  - Include the appropiate header (<iostrem>, <string>, etc.)
  - Qualify names with std::

            #include <iostream>
            
            int main() {
                std::cout << "Hello, World!" << std::endl;
                return 0;
            }

### Classes in Object-Oriented Programming
- A class is a blueprint that defines the structure (attributes) and behavior (methods) of objects.
- An object is an instance of a class - it has its own values for attributes but shares the same methods and structure defined by the class.
  
#### Elements of a class:  
- **Constructor:** a special method automatically called when an object is created.
  - Default constructor (no parameters)
  - Parametrized constructor
  - Constructor with default values
  - **Initialization list**: initializes members before the constructor body - neccesary for const members or references.
 
          class MyClass
          {
                int x;
                public:
                      MyClass(int val) : x(val) {} //initialization list
          }
    
- **Destructor:** a special method automatically called when an object goes out of scope. Used to release resources (close files, free dynamic memory, etc.).
- **Public and Private Members**
  - public: accesible from outside the class
  - private: accesible only within the class
  - **Encapsulation:** grouping data and functiions together while restricting direct access to internal details.
    - Benefit of private attributes with getters/setters:
      - Input validation
      - Flexibility (implementation changes won't break external code)
- **Member Attributes (fields):** variables that store the internal state of the object
- **Member Functons (methods):** functions that operate on the object's attributes
- **Static members:** beling to the class itself, not to a specific object.
  - Cannot access non-static members
  - Useful for counters, helpers, or shared state
- **Accessing members within a class:**
  - 'this->atribute': refers to the current object's member
  - 'Class::atribute': refers to a static member of the class

#### Advanges of Classes: 
- Encapsulation: keep related data and methods together
- Reusability: define once, instantiate multiple times
- Abstraction: hide implementation details behind an interface
- Modularity: improves organizaton and maintainability

### More info:

String class &rarr; [HERE](https://cplusplus.com/reference/string/string/#google_vignette)  
IO Manipultors &rarr; [HERE](https://cplusplus.com/reference/iomanip/)  
Guideline&rarr; [HERE](https://42-cursus.gitbook.io/guide/4-rank-04/cpp-00-04-doing/cpp00)  
