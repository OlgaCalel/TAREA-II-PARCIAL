#include <iostream>
#include <string>

const int MAX_ESTUDIANTES = 100; // Puedes ajustar este valor según tus necesidades

struct Estudiante {
    int id;
    std::string nombres;
    std::string apellidos;
    double notas[4];
};

void calcularPromedio(Estudiante* estudiante) {
    double promedio = 0.0;
    for (int i = 0; i < 4; ++i) {
        promedio += estudiante->notas[i];
    }
    promedio /= 4.0;
    estudiante->notas[4] = promedio;
}

void mostrarResultado(Estudiante* estudiante) {
    std::cout << "Estudiante #" << estudiante->id << ": "
              << estudiante->nombres << " " << estudiante->apellidos
              << " - Promedio: " << estudiante->notas[4];

    if (estudiante->notas[4] > 60.0) {
        std::cout << " (Aprobado)\n";
    } else {
        std::cout << " (Reprobado)\n";
    }
}

int main() {
    int n;
    std::cout << "Ingrese la cantidad de estudiantes: ";
    std::cin >> n;

    Estudiante* estudiantes[MAX_ESTUDIANTES];

    for (int i = 0; i < n; ++i) {
        estudiantes[i] = new Estudiante;
        std::cout << "Estudiante #" << i + 1 << ":\n";
        estudiantes[i]->id = i + 1;

        std::cout << "Nombres: ";
        std::cin >> estudiantes[i]->nombres;

        std::cout << "Apellidos: ";
        std::cin >> estudiantes[i]->apellidos;

        std::cout << "Notas (nota1 nota2 nota3 nota4): ";
        for (int j = 0; j < 4; ++j) {
            std::cin >> estudiantes[i]->notas[j];
        }

        calcularPromedio(estudiantes[i]);
    }

    std::cout << "\nResultados:\n";
    for (int i = 0; i < n; ++i) {
        mostrarResultado(estudiantes[i]);
        delete estudiantes[i];
    }

    return 0;
}

