#include <iostream>
#include <string>
#include <vector>

class Alumno {
private:
    int idAlumno;
    std::string nombre;
    std::string apellido;
    int edad;
    char sexo;
    int semestre;
    std::vector<int> materiasCursando;

public:
    void capturarDatos() {
        std::cout << "ID del alumno: ";
        std::cin >> idAlumno;
        std::cin.ignore();

        std::cout << "Nombre: ";
        std::getline(std::cin, nombre);

        std::cout << "Apellido: ";
        std::getline(std::cin, apellido);

        std::cout << "Edad: ";
        std::cin >> edad;

        std::cout << "Sexo: ";
        std::cin >> sexo;

        std::cout << "Semestre: ";
        std::cin >> semestre;

        int cantidad;
        std::cout << "¿Cuántas materias cursa este alumno? ";
        std::cin >> cantidad;

        for (int i = 0; i < cantidad; ++i) {
            int idMat;
            std::cout << "ID de la materia " << (i + 1) << ": ";
            std::cin >> idMat;
            materiasCursando.push_back(idMat);
        }
    }

    int getId() const {
        return idAlumno;
    }

    void mostrarDatos() const {
        std::cout << "ID de Alumno: " << idAlumno << std::endl;
        std::cout << "Nombre: " << nombre << " " << apellido << std::endl;
        std::cout << "Edad: " << edad << std::endl;
        std::cout << "Sexo: " << sexo << std::endl;
        std::cout << "Semestre: " << semestre << std::endl;
        std::cout << "Materias cursando (IDs): ";

        for (int id : materiasCursando) {
            std::cout << id << " ";
        }

        std::cout << std::endl;
    }
};

template <typename T>
void buscarYMostrar(std::vector<T>& lista, int id) {
    for (T& obj : lista) {
        if (obj.getId() == id) {
            obj.mostrarDatos();
            return;
        }
    }

    std::cout << "No hay registro con ese ID" << std::endl;
}

class Profesor {
private:
    int idProfesor;
    std::string nombre;
    std::string apellido;
    char sexo;
    int edad;
    std::string titulo;
    int numeroCedula;

public:
    void capturarDatos() {
        std::cout << "ID del profesor: ";
        std::cin >> idProfesor;
        std::cin.ignore();

        std::cout << "Nombre: ";
        std::getline(std::cin, nombre);

        std::cout << "Apellido: ";
        std::getline(std::cin, apellido);

        std::cout << "Sexo: ";
        std::cin >> sexo;

        std::cout << "Edad: ";
        std::cin >> edad;
        std::cin.ignore();

        std::cout << "Título: ";
        std::getline(std::cin, titulo);

        std::cout << "Número de cédula profesional: ";
        std::cin >> numeroCedula;
    }

    int getId() const {
        return idProfesor;
    }

    void mostrarDatos() const {
        std::cout << "ID Profesor: " << idProfesor << std::endl;
        std::cout << "Nombre: " << nombre << " " << apellido << std::endl;
        std::cout << "Sexo: " << sexo << std::endl;
        std::cout << "Edad: " << edad << std::endl;
        std::cout << "Título: " << titulo << std::endl;
        std::cout << "Cédula: " << numeroCedula << std::endl;
    }
};

class Materia {
private:
    int idMateria;
    std::string nombreMateria;
    int numeroCreditos;
    int idProfesorAsignado;

public:
    void capturarDatos() {
        std::cout << "ID de la materia: ";
        std::cin >> idMateria;
        std::cin.ignore();

        std::cout << "Nombre de la materia: ";
        std::getline(std::cin, nombreMateria);

        std::cout << "Número de créditos: ";
        std::cin >> numeroCreditos;

        std::cout << "ID del profesor: ";
        std::cin >> idProfesorAsignado;
    }

    int getId() const {
        return idMateria;
    }

    void mostrarDatos() const {
        std::cout << "ID Materia: " << idMateria << std::endl;
        std::cout << "Nombre: " << nombreMateria << std::endl;
        std::cout << "Créditos: " << numeroCreditos << std::endl;
        std::cout << "ID Profesor: " << idProfesorAsignado << std::endl;
    }
};

int main() {
    std::vector<Profesor> profesores;
    std::vector<Materia> materias;
    std::vector<Alumno> alumnos;

    for (int i = 0; i < 2; ++i) {
        std::cout << "Profesor: " << (i + 1) << std::endl;
        Profesor p;
        p.capturarDatos();
        profesores.push_back(p);
    }

    for (int i = 0; i < 3; ++i) {
        std::cout << "Materia: " << (i + 1) << std::endl;
        Materia m;
        m.capturarDatos();
        materias.push_back(m);
    }

    for (int i = 0; i < 2; ++i) {
        std::cout << "Alumno: " << (i + 1) << std::endl;
        Alumno a;
        a.capturarDatos();
        alumnos.push_back(a);
    }

    int opcion;

    do {
        std::cout << "Desea visualizar:" << std::endl << std::endl;
        std::cout << "1. Profesor" << std::endl;
        std::cout << "2. Materia" << std::endl;
        std::cout << "3. Alumno" << std::endl;
        std::cout << "4. Salir" << std::endl;
        std::cout << "Selecciona una opcion: ";
        std::cin >> opcion;

        int id;

        switch (opcion) {
            case 1:
                std::cout << "Ingrese ID del profesor: ";
                std::cin >> id;
                buscarYMostrar(profesores, id);
                break;

            case 2:
                std::cout << "Ingrese ID de la materia: ";
                std::cin >> id;
                buscarYMostrar(materias, id);
                break;

            case 3:
                std::cout << "Ingrese ID del alumno: ";
                std::cin >> id;
                buscarYMostrar(alumnos, id);
                break;

            case 4:
                std::cout << "Finalizando programa..." << std::endl;
                break;

            default:
                std::cout << "Opción inválida." << std::endl;
        }
    } while (opcion != 4);

    return 0;
}