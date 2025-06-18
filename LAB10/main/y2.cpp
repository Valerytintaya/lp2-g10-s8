#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Ruta {
private:
    int id;
    string destino;
public:
    Ruta(int id, string destino) : id(id), destino(destino) {}

    template <typename T>
    void asignarVehiculo(T vehiculoID) {
        cout << "Ruta " << id << " hacia " << destino 
             << " asignada al vehículo: " << vehiculoID << endl;
    }
};

class Entrega {
private:
    string codigoPaquete;
public:
    Entrega(string codigo) : codigoPaquete(codigo) {}

    template <typename H>
    void programarHorario(H horaEntrega) {
        cout << "Entrega del paquete " << codigoPaquete 
             << " programada para: " << horaEntrega << endl;
    }
};

int main() {
    Ruta r1(101, "Lima");
    Ruta r2(102, "Arequipa");

    r1.asignarVehiculo("AB-123");
    r2.asignarVehiculo(456);  // int

    Entrega e1("PKG001");
    Entrega e2("PKG002");

    e1.programarHorario("10:30 AM");
    e2.programarHorario(14.5); 

    return 0;
}

