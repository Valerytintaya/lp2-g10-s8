#include <iostream>
#include <string>
using namespace std;

class Estudiante {
private:
    string nombre, direccion;
    int edad, grado, codigo_estudiante;

public:
    // Constructor
    Estudiante(string _nombre, string _direccion, int _edad, int _grado, int _codigo_estudiante)
        : nombre(_nombre), direccion(_direccion), edad(_edad), grado(_grado), codigo_estudiante(_codigo_estudiante) {}

    void tomarExamen(string curso) {
        cout << nombre << " (Codigo: " << codigo_estudiante << ") esta tomando el examen de " << curso << "." << endl;
    }

    void recibir_calificacion(float nota) {
        if (nota < 12) {
            cout << " Nota desaprobatoria: " << nota << endl;
        } else {
            cout << " Nota aprobatoria: " << nota << endl;
        }
    }

    void mostrar_info() {
        cout << " Nombre: " << nombre << " |  Direccion: " << direccion << " |  Edad: " << edad  << endl;
        cout << "Grado: " << grado << " | Codigo Estudiante: " << codigo_estudiante << endl;
    }

    string getNombre() { return nombre; }

    ~Estudiante(){cout << "des"<<endl;};
};

int main() {
    Estudiante estudiantes[4] = {
        Estudiante("Juan", "Av. Industrial", 12, 5, 12345),
        Estudiante("Alex", "Av. Fermin", 11, 4, 12334),
        Estudiante("Marta", "Av. Goethe", 15, 3, 12636),
        Estudiante("Fin", "Calle Norte", 14, 7, 23541)
    };

    // Mostrar información de los estudiantes
    for (int i = 0; i < 4; i++) {
        estudiantes[i].mostrar_info();
        cout << "-------------------------" << endl;
    }

    string curso;
    float nota;

    // Tomar examen
    for (int i = 0; i < 4; i++) {
        cout << "¿Que curso esta rindiendo " << estudiantes[i].getNombre() << "? ";
        cin >> curso;
        estudiantes[i].tomarExamen(curso);
        cout << "-------------------------" << endl;
    }

    // Recibir calificaciones
    for (int i = 0; i < 4; i++) {
        cout << "Ingresa la nota de " << estudiantes[i].getNombre() << ": ";
        cin >> nota;
        estudiantes[i].recibir_calificacion(nota);
        cout << "-------------------------" << endl;
    }

    return 0;
}
