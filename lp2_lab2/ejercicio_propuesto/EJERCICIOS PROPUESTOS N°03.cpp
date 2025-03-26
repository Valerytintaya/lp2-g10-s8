#include <iostream>
using namespace std;

class Avion {
public:
    string modelo;
    double combustible; // litros
    double consumo; // litros por hora
    int capacidadTripulacion;

    Avion(string m, double c, double co, int cap) 
        : modelo(m), combustible(c), consumo(co), capacidadTripulacion(cap) {}

    bool puedeVolar(double duracion) {
        return combustible >= (consumo * duracion);
    }

    bool puedeLlevarTripulacion(int tripulantes) {
        return tripulantes <= capacidadTripulacion;
    }


};

class Mision {
public:
    string destino;
    double duracion; // horas
    int tripulacion; // cantidad de tripulantes

    Mision(string d, double du, int t) : destino(d), duracion(du), tripulacion(t) {}

    void simular(Avion &avion) {
        cout << "\nMision a " << destino << " por " << duracion << " horas con " << tripulacion << " tripulantes.\n";
        
        if (!avion.puedeLlevarTripulacion(tripulacion)) {
            cout << "Fallo en la mision: Excede la capacidad de tripulacion .\n";
            return;
        }

        if (avion.puedeVolar(duracion)) {
            cout << "Mision completada \n";
            avion.combustible -= (avion.consumo * duracion);
        } else {
            cout << "Fallo en la mision: Combustible insuficiente.\n";
        }
    }
};

int main() {
    Avion avion("LATAM A380", 5000, 400, 5); 
    Mision mision("Perú", 10, 3); 
    int opcion;

    do {
        cout << "\n--- Menú ---\n";
        cout << "1. Definir misión\n";
        cout << "2. Simular misión\n";
        cout << "3. Salir\n";
        cout << "Opción: ";
        cin >> opcion;

        if (opcion == 1) {
            string destino;
            double duracion;
            int tripulacion;

            cout << "Destino: "; cin >> destino;
            cout << "Duracion (horas): "; cin >> duracion;
            cout << "Cantidad de tripulantes: "; cin >> tripulacion;

            if (duracion > 0 && tripulacion > 0) {
                mision = Mision(destino, duracion, tripulacion);
            } else {
                cout << "Error: deben ser valores positivos.\n";
            }
        } 
        else if (opcion == 2) {
            mision.simular(avion);
        } 

    } while (opcion != 3);
    return 0;
}

