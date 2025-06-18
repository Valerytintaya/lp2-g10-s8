#include <iostream>
#include <string>
#include <iomanip>
using namespace std;

const int MAX = 100;  // Tamaño máximo del arreglo

//
// EXPERIENCIA 01: TEMPLATE DE FUNCIÓN
//
template <typename T>
void ordenarArreglo(T arr[], int n) {
    for (int i = 0; i < n - 1; i++)
        for (int j = 0; j < n - i - 1; j++)
            if (arr[j] > arr[j + 1])
                swap(arr[j], arr[j + 1]);

    cout << "\nDistancias ordenadas:\n";
    for (int i = 0; i < n; i++)
        cout << fixed << setprecision(2) << arr[i] << " km ";
    cout << "\n";
}

//
// EXPERIENCIA 02 Y 03: TEMPLATE DE CLASE Y MÉTODO
//
template <typename T>
class SistemaRutas {
private:
    T ids[MAX];
    string destinos[MAX];
    double distancias[MAX];
    int cantidad;

public:
    SistemaRutas() {
        cantidad = 0;
    }

    void agregarRuta(T id, string destino, double distancia) {
        if (cantidad < MAX) {
            ids[cantidad] = id;
            destinos[cantidad] = destino;
            distancias[cantidad] = distancia;
            cantidad++;
        } else {
            cout << "Limite maximo.\n";
        }
    }

    void mostrarRutas() {
        cout << "\nReporte de Rutas:\n";
        for (int i = 0; i < cantidad; i++) {
            cout << "ID: " << ids[i]
                 << ", Destino: " << destinos[i]
                 << ", Distancia: " << fixed << setprecision(2) << distancias[i] << " km\n";
        }
    }

    template <typename V>
    void asignarVehiculo(T idRuta, V vehiculoID) {
        cout << "Vehiculo " << vehiculoID << " asignado a la ruta " << idRuta << ".\n";
    }

    void ordenarDistancias() {
        ordenarArreglo(distancias, cantidad);  // usa template de función
    }
};

//
// MAIN: Integración completa
//
int main() {
    SistemaRutas<string> sistema;

    sistema.agregarRuta("R001", "Ruta1", 150.5);
    sistema.agregarRuta("R002", "Ruta2", 320.0);
    sistema.agregarRuta("R003", "Ruta3", 850.75);
    sistema.agregarRuta("R004", "Ruta4", 230.0);

    sistema.mostrarRutas();

    sistema.asignarVehiculo("R001", "AB-123");
    sistema.asignarVehiculo("R002", 456); // uso de template de método

    sistema.ordenarDistancias(); // uso del template de función

    return 0;
}
