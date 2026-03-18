# Sistema Académico en C++

Proyecto académico desarrollado en C++ que simula un sistema básico de gestión académica desde consola.

El programa permite registrar y consultar información de **alumnos, profesores y materias**, utilizando programación orientada a objetos y estructuras de datos de la biblioteca estándar.

## Funcionalidades

- Registro de profesores
- Registro de materias
- Registro de alumnos
- Asociación de materias cursadas por alumno
- Asociación de profesor asignado a una materia
- Consulta de registros por ID mediante un menú interactivo

## Estructura del programa

El sistema está compuesto por tres clases principales:

- **Alumno**
  - Información personal del alumno
  - Lista de materias que está cursando

- **Profesor**
  - Información básica del profesor
  - Datos profesionales

- **Materia**
  - Información de la materia
  - Profesor asignado

Los registros se almacenan en memoria utilizando `std::vector`.

El sistema incluye una función genérica de búsqueda mediante **templates** que permite localizar registros por ID y mostrar su información.

## Tecnologías utilizadas

- **C++**
- Programación Orientada a Objetos (POO)
- Biblioteca estándar de C++ (`vector`, `string`)
- Uso de templates para funciones genéricas

## Compilación

Para compilar el programa utilizando `g++`:

```bash
g++ main.cpp -o sistema
```

## Ejecución
```bash
./sistema
```
El programa solicitará capturar datos de profesores, materias y alumnos, y posteriormente permitirá consultar la información mediante un menú.

## Autor
Ivan Robles