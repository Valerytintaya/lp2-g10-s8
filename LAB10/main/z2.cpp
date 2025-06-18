#include <iostream>
#include <string>
#include <iomanip>
using namespace std;

const int MAX = 100;  

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
            cout << "Límite máximo .\n";
        }
    }

    void mostrarRutas() {
        cout << "\nReporte de Rutas:\n";
        for (int i = 0; i < cantidad; i++) {
            cout << "ID: " << ids[i]
                 << ", Destino: " << destinos[i]
                 << ", Distancia: " << distancias[i] << " km\n";
        }
    }

    template <typename Tipo>
    void ordenarYMostrar(Tipo arr[], int n) {
        for (int i = 0; i < n - 1; i++)
            for (int j = 0; j < n - i - 1; j++)
                if (arr[j] > arr[j + 1])
                    swap(arr[j], arr[j + 1]);

        cout << "\n Distancias ordenadas:\n";
        for (int i = 0; i < n; i++)
            cout << arr[i] << " km ";
        cout << "\n";
    }

    void ordenarDistancias() {
        ordenarYMostrar(distancias, cantidad); 
    }

    template <typename V>
    void asignarVehiculo(T idRuta, V vehiculoID) {
        cout << "Vehículo " << vehiculoID << " asignado a la ruta " << idRuta << ".\n";
    }
};

int main() {
    SistemaRutas<string> sistema;

    sistema.agregarRuta("R001", "Lima", 150.5);
    sistema.agregarRuta("R002", "Cusco", 320.0);
    sistema.agregarRuta("R003", "Tacna", 850.75);
    sistema.agregarRuta("R004", "Piura", 230.0);

    sistema.mostrarRutas();

    sistema.asignarVehiculo("R001", "AB-123");
    sistema.asignarVehiculo("R002", 456); 

    sistema.ordenarDistancias(); 

    return 0;
}
