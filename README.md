# Final proyect for OOP Introduction Course

Streaming service modeled via Object Oriented Programming.

## Compilation

Using g++ compiler (version 13). Commands to compile:

* Windows

`g++ classes/*.cpp -o main main.cpp`

* Linux

`g++-13 classes/*.cpp -o main main.cpp`

## UML Diagram compilation

Using [Mermeid CLI](https://github.com/mermaid-js/mermaid-cli) the UML class diagram can be compiled with:

`mmdc -i class_diagram.md -o uml_diagram.png -t dark -b transparent`
