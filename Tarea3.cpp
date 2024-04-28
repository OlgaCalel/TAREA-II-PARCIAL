#include <iostream>
#include <fstream>
#include <string>

const int MAX_ESTUDIANTES = 100; // Puedes ajustar este valor según tus necesidades

struct Estudiante {
    int id;
    std::string nombres;
    std::string apellidos;
    double notas[4];
    double promedio;
    std::string resultado;
};

void calcularPromedio(Estudiante* estudiante) {
    double sumaNotas = 0.0;
    for (int i = 0; i < 4; ++i) {
        sumaNotas += estudiante->notas[i];
    }
    estudiante->promedio = sumaNotas / 4.0;

    if (estudiante->promedio > 60.0) {
        estudiante->resultado = "Aprobado";
    } else {
        estudiante->resultado = "Reprobado";
    }
}

void guardarEnArchivo(Estudiante* estudiante, std::ofstream& archivo) {
    archivo.write(reinterpret_cast<char*>(estudiante), sizeof(Estudiante));
}

void leerDesdeArchivo(std::ifstream& archivo) {
    Estudiante estudiante;
    while (archivo.read(reinterpret_cast<char*>(&estudiante), sizeof(Estudiante))) {
        std::cout << "Estudiante #" << estudiante.id << ": "
                  << estudiante.nombres << " " << estudiante.apellidos
                  << " - Promedio: " << estudiante.promedio
                  << " - Resultado: " << estudiante.resultado << "\n";
    }
}

int main() {
    int n;
    std::cout << "Ingrese la cantidad de estudiantes: ";
    std::cin >> n;

    Estudiante estudiantes[MAX_ESTUDIANTES];

    for (int i = 0; i < n; ++i) {
        std::cout << "Estudiante #" << i + 1 << ":\n";
        estudiantes[i].id = i + 1;

        std::cout << "Nombres: ";
        std::cin >> estudiantes[i].nombres;

        std::cout << "Apellidos: ";
        std::cin >> estudiantes[i].apellidos;

        std::cout << "Notas (nota1 nota2 nota3 nota4): ";
        for (int j = 0; j < 4; ++j) {
            std::cin >> estudiantes[i].notas[j];
        }

        calcularPromedio(&estudiantes[i]);
    }

    // Guardar en archivo
    std::ofstream archivo("notas.dat", std::ios::binary);
    for (int i = 0; i < n; ++i) {
        guardarEnArchivo(&estudiantes[i], archivo);
    }
    archivo.close();

    // Leer desde archivo
    std::ifstream archivoLectura("notas.dat", std::ios::binary);
    std::cout << "\nResultados almacenados en notas.dat:\n";
    leerDesdeArchivo(archivoLectura);
    archivoLectura.close();

    return 0;
}

