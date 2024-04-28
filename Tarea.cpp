#include <iostream>
using namespace std;

const int MAX_ESTUDIANTES = 100;

struct Estudiante {
    int id;
    string nombres;
    string apellidos;
    double notas[4];
    double promedio;
};

void calcularPromedio(Estudiante& estudiante) {
    double sumaNotas = 0;
    for (int i = 0; i < 4; i++) {
        sumaNotas += estudiante.notas[i];
    }
    estudiante.promedio = sumaNotas / 4;
}

void mostrarResultado(const Estudiante& estudiante) {
    cout << "ID: " << estudiante.id << endl;
    cout << "Nombre completo: " << estudiante.nombres << " " << estudiante.apellidos << endl;
    cout << "Promedio: " << estudiante.promedio << endl;
    if (estudiante.promedio > 60) {
        cout << "Resultado: Aprobado" << endl;
    } else {
        cout << "Resultado: Reprobado" << endl;
    }
}

int main() {
    Estudiante estudiantes[MAX_ESTUDIANTES];
    int numEstudiantes;

    cout << "Ingrese el número de estudiantes: ";
    cin >> numEstudiantes;

    for (int i = 0; i < numEstudiantes; i++) {
        cout << "Estudiante #" << i + 1 << endl;
        cout << "ID: ";
        cin >> estudiantes[i].id;
        cout << "Nombres: ";
        cin >> estudiantes[i].nombres;
        cout << "Apellidos: ";
        cin >> estudiantes[i].apellidos;
        for (int j = 0; j < 4; j++) {
            cout << "Nota " << j + 1 << ": ";
            cin >> estudiantes[i].notas[j];
        }
        calcularPromedio(estudiantes[i]);
    }

    cout << "\nResultados:\n";
    for (int i = 0; i < numEstudiantes; i++) {
        mostrarResultado(estudiantes[i]);
    }

    return 0;
}

