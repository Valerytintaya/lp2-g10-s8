#include <iostream>
using namespace std;

class Vehiculo {
public:
    virtual void acelerar() {
        cout << "Acelerando el vehículo" << endl;
    }

    virtual ~Vehiculo() {}
};
class Coche : public Vehiculo {
public:
    void acelerar() override {
        cout << "Acelerando el coche" << endl;
    }

    void encenderLuces() {
        cout << "Luces del coche encendidas" << endl;
    }
};

class Motocicleta : public Vehiculo {
public:
    void acelerar() override {
        cout << "Acelerando la motocicleta" << endl;
    }
};

// Función principal
int main() {
    cout << "---- Vehículo tipo Coche ----" << endl;
    Coche miCoche;
    miCoche.acelerar();         // Redefinición del método
    miCoche.encenderLuces();    // Método refinado solo en Coche

    cout << "\n---- Vehículo tipo Motocicleta ----" << endl;
    Motocicleta miMoto;
    miMoto.acelerar();          // Redefinición del método

    // Verificación de herencia y comportamiento específico
    // miMoto.encenderLuces(); // Esta línea daría error si se descomenta, porque Motocicleta no tiene ese método
    return 0;
}
