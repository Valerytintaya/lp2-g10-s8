#include <iostream>
#include <string>
using namespace std;

class Habitacion {
private:
    int numero;
    string tipo;
    double precioPorNoche;

public:
    Habitacion() : numero(0), tipo(""), precioPorNoche(0.0) {}

    Habitacion(int num, string tipo, double precio)
        : numero(num), tipo(tipo), precioPorNoche(precio) {}

    double getPrecioPorNoche() const {
        return precioPorNoche;
    }

    void mostrar() const {
        cout << "Habitacion " << numero << ", Tipo: " << tipo
             << ", Precio:" << precioPorNoche << endl;
    }
};

class ReservaHotel {
private:
    Habitacion* habitaciones; // arreglo dinámico
    int cantidad;
    int n;

public:
    // Constructor parametrizado
    ReservaHotel(int cant) {
        cantidad = cant;
        habitaciones = new Habitacion[cantidad]; // memoria dinámica
        n=0;
    }

    // Método para asignar una habitación en una posición
    void asignarHabitacion(int numero, string tipo, double precio) {
        if (n < cantidad) {
            habitaciones[n++] = Habitacion(numero, tipo, precio);
        }
    }

    double calcularTotalPorNoche(){
        double total = 0;
        for (int i = 0; i < cantidad; ++i) {
            total += habitaciones[i].getPrecioPorNoche();
        }
        return total;
    }

    void mostrarHabitaciones() {
        for (int i = 0; i < cantidad; ++i) {
            habitaciones[i].mostrar();
        }
    }

    // Destructor
    ~ReservaHotel() {
        delete[] habitaciones;
        cout << "Memoria liberada correctamente.\n";
    }
};

int main() {
    ReservaHotel hotel(3);

    hotel.asignarHabitacion(101, "Simple", 100.0);
    hotel.asignarHabitacion(102, "Doble", 150.0);
    hotel.asignarHabitacion(103, "Suite", 250.0);

    hotel.mostrarHabitaciones();

    cout << "Total por noche de todas las habitaciones:" << hotel.calcularTotalPorNoche() << endl;

    return 0; 
}
