#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Estudiante {
private:
    string nombre;
    string apellido;
    vector<float> notas;

public:
    // Constructor
    Estudiante(string nombre, string apellido, vector<float> notas)
        : nombre(nombre), apellido(apellido), notas(notas) {}

    // Métodos para obtener los datos
    string getNombre() { return nombre; }
    string getApellido() { return apellido; }
    float getPromedio() {
        float suma = 0;
        for (float nota : notas) {
            suma += nota;
        }
        return suma / notas.size();
    }
    // Método para imprimir los datos del estudiante
    void imprimir() {
        cout << "Nombre: " << nombre << " " << apellido << " | Promedio: " << getPromedio() << endl;
    }
};
int main() {
    vector<Estudiante> estudiantes;

    estudiantes.push_back(Estudiante("Ana", "Perez", {15.0, 18.5, 17.0}));
    estudiantes.push_back(Estudiante("Luis", "Gomez", {12.5, 14.0, 10.0}));
    estudiantes.push_back(Estudiante("Carlos", "Martinez", {19.0, 20.0, 18.0}));
    estudiantes.push_back(Estudiante("Maria", "Lopez", {13.5, 14.5, 15.0}));

    cout << "Lista de estudiantes:" << endl;
    for ( Estudiante& est : estudiantes) {
        est.imprimir();
    }
    return 0;
}

