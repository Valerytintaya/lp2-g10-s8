#include <iostream>
#include <string>
using namespace std;

class Coche {
private:
    string modelo;
    int anio;
    float velocidad;
    float max_velocidad;

public:
    // Constructor
    Coche(string _modelo, int _anio, float _max_velocidad) {
        modelo = _modelo;
        anio = _anio;
        max_velocidad = _max_velocidad;
        velocidad = 0; // Inicialmente, el coche está detenido
    }

    // Método para acelerar el coche
    void acelerar(float incremento) {
        if (velocidad + incremento > max_velocidad) {
            velocidad = max_velocidad;
            cout << "El coche ha alcanzado su velocidad máxima de " << max_velocidad << " km/h" << endl;
        } else {
            velocidad += incremento;
            cout << "El coche acelera a " << velocidad << " km/h" << endl;
        }
    }

    // Método para frenar el coche
    void frenar(float decremento) {
        if (velocidad - decremento < 0) {
            velocidad = 0;
            cout << "El coche se ha detenido." << endl;
        } else {
            velocidad -= decremento;
            cout << "El coche frena a " << velocidad << " km/h" << endl;
        }
    }

    // Método para mostrar información del coche
    void mostrarInfo() {
        cout << "Modelo: " << modelo << " | Año: " << anio << " | Velocidad actual: " << velocidad << " km/h" << endl;
    }
};

int main() {
    // Crear dos objetos Coche
    Coche coche1("Toyota Corolla", 2020, 180);
    Coche coche2("Ford Mustang", 2022, 250);

    // Prueba de aceleración y frenado
    coche1.mostrarInfo();
    coche1.acelerar(50);
    coche1.acelerar(150);
    coche1.frenar(80);
    coche1.mostrarInfo();

    cout << "-------------------------" << endl;

    coche2.mostrarInfo();
    coche2.acelerar(100);
    coche2.acelerar(180);
    coche2.frenar(200);
    coche2.mostrarInfo();

    return 0;
}
