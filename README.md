# Final proyect for OOP Introduction Course

Streaming service modeled via Object Oriented Programming.

## Compilation

Using g++ compiler (version 13). Commands to compile:

* Windows

`g++ gameLogic/*.cpp classes/*.cpp -o main main.cpp`

* Linux

`g++-13 gameLogic/*.cpp classes/*.cpp -o main main.cpp`

## UML Diagram compilation

Using [Mermeid CLI](https://github.com/mermaid-js/mermaid-cli) the UML class diagram can be compiled with:

`mmdc -i class_diagram.md -o class_diagram.png -t dark -b transparent`
