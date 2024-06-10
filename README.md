# Final proyect for OOP Introduction Course

Movie and series ranking platform modeled via Object Oriented Programming.

## Compilation

Using g++ compiler (version 13 or greater), commands to compile:

* Windows

```
cd src
g++ classes/*.cpp -o main main.cpp
```

* Linux

```
cd src
g++-13 classes/*.cpp -o main main.cpp
```

## UML Diagram compilation

The [UML class diagram](class_diagram.md) provides a visual representation of the classes in the project, following UMl standards.

Using [Mermeid CLI](https://github.com/mermaid-js/mermaid-cli) the UML class diagram can be compiled with:

`mmdc -i class_diagram.md -o uml.png -t dark -b transparent`
