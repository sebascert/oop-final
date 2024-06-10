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

## UML Diagrams compilation

The [UML class diagram](class_diagram.md) provides a visual representation of the classes in the project, following UMl standards.

The [UML sequence diagram](sequence_diagram.md) provides a visual representation of the sequence of events in the project execution.

Using [Mermeid CLI](https://github.com/mermaid-js/mermaid-cli) the UML diagrams can be compiled with:

#### Class Diagram
`mmdc -i class_diagram.md -o class_uml.png -t dark -b transparent`

#### Sequence Diagram
`mmdc -i sequence_diagram.md -o sequence_uml.png -t dark -b transparent`
