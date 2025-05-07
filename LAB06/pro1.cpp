#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

class Grupo;

class Alumno {
private:
    string nombre;
    int edad;
    float promedio;
public:
    Alumno(string n, int e, float p) : nombre(n), edad(e), promedio(p) {}

    string aCaracteres() {
        string strEdad = to_string(edad);
        string strPromedio = to_string(promedio);
        return "CLASE ALUMNO | nombre: " + nombre + " | edad: " + strEdad + " | promedio: " + strPromedio;
    }

    bool operator<(const Alumno& otro) const {
        return (promedio < otro.promedio);  
    }

    friend class Grupo;  
};

class Grupo {
private:
    vector<Alumno> alumnos;
    int cantidad;
    int n;

public:
    Grupo(int c) : cantidad(c), n(0) {
        alumnos.reserve(cantidad); 
    }

    string aCaracteres() {
        string strCantidad = to_string(cantidad);
        return "CLASE GRUPO | cantidad de alumnos: " + strCantidad;
    }

    void agregarAlumnos(string no, int ed, float pro) {
        if (n >= cantidad) {
            cout << "Cantidad de alumnos excedida..." << endl;
        } else {
            alumnos.push_back(Alumno(no, ed, pro));
            n++;
            cout << "Alumno agregado..." << endl;
        }
    }

    void ordenarAlumnos() {
        sort(alumnos.begin(), alumnos.end());
    }

    void calcularPromedio() {
        float suma = 0;
        for (int i = 0; i < n; i++) {
            suma += alumnos[i].promedio;
        }
        if (n > 0) {
            cout << "Promedio final/general: " << suma / n << endl;
        }
    }

    Alumno mejor() {
        if (n == 0) {
            cout << "No hay alumnos en el grupo." << endl;
            return Alumno("", 0, 0); 
        }

        Alumno mejorA = alumnos[0];
        for (int i = 1; i < n; i++) {
            if (alumnos[i].promedio > mejorA.promedio) {
                mejorA = alumnos[i];
            }
        }
        return mejorA;
    }

    void mostrarAlumnos() {
        for (int i = 0; i < n; i++) {
            cout << alumnos[i].aCaracteres() << endl;
        }
    }
};

int main() {
    Grupo grupo(5);  

    grupo.agregarAlumnos("Luis", 20, 15.5);
    grupo.agregarAlumnos("Ana", 19, 18.0);
    grupo.agregarAlumnos("Carlos", 18, 14.0);
    grupo.agregarAlumnos("Anonimo", 19, 0.8);
    grupo.agregarAlumnos("xiomara", 225, 10);

    grupo.mostrarAlumnos();


    grupo.ordenarAlumnos();
    cout << "\nAlumnos ordenados por promedio:" << endl;
    grupo.mostrarAlumnos();

    grupo.calcularPromedio();

    Alumno mejorAlumno = grupo.mejor();
    cout << "\nMejor alumno: " << mejorAlumno.aCaracteres() << endl;

    return 0;
}
