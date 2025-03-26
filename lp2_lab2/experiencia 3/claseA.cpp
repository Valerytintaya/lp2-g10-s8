#include <iostream>
#include <string>
using namespace std;

class Persona
{ 
    private:
        string nombre, direccion, fecha_naci;
        int edad, dni;
    
    public: 
        // Constructor
        Persona (string _nombre = "ND", string _direccion  = "ND", string _fecha  = "ND", int _edad = 0, int _dni = 0)
        : nombre(_nombre), direccion(_direccion), fecha_naci(_fecha), edad(_edad), dni(_dni) {}

        // Getters 
        string getNombre() { return nombre; }
        string getDireccion() { return direccion; }
        string getFecha() { return fecha_naci; }
        int getEdad() { return edad; }
        int getDni() { return dni; }

        // Setters
        void setNombre(string nuevoNombre) {
            if (nuevoNombre.empty()) {
                cout << "Nombre inválido.\n";
            } else {
                nombre = nuevoNombre;
                cout << "Nombre cambiado.\n";
            }
        }

        void setDireccion(string nuevaDireccion) {
            if (nuevaDireccion.empty()) {
                cout << "Dirección inválida.\n";
            } else {
                direccion = nuevaDireccion;
                cout << "Dirección cambiada.\n";
            }
        }

        void setFecha(string nuevaFecha) {
            if (nuevaFecha.empty()) {
                cout << "Fecha inválida.\n";
            } else {
                fecha_naci = nuevaFecha;
                cout << "Fecha cambiada.\n";
            }
        }

        void setEdad(int nuevaEdad) {
            if (nuevaEdad < 0) {
                cout << "Edad inválida.\n";
            } else {
                edad = nuevaEdad;
                cout << "Edad cambiada.\n";
            }
        }

        void setDni(int nuevoDni) {
            dni = nuevoDni;
            cout << "DNI cambiado.\n";
        }

        // Método para mostrar información de la persona
        void mostrarInformacion() {
            cout << "Nombre: " << nombre << endl;
            cout << "Dirección: " << direccion << endl;
            cout << "Fecha de Nacimiento: " << fecha_naci << endl;
            cout << "Edad: " << edad << endl;
            cout << "DNI: " << dni << endl;
            cout << "-------------------------------\n";
        }
};

int main() {
    // Crear objetos de Persona
    Persona persona1("Juan Perez", "Av. Arequipa 123", "15/06/1990", 34, 12345678);
    Persona persona2;

    // Mostrar datos iniciales
    cout << "Datos de Persona 1:\n";
    persona1.mostrarInformacion();

    cout << "Datos de Persona 2 (valores por defecto):\n";
    persona2.mostrarInformacion();

    // Modificar datos usando setters
    persona2.setNombre("Maria Lopez");
    persona2.setDireccion("Calle Lima 456");
    persona2.setFecha("22/10/1995");
    persona2.setEdad(29);
    persona2.setDni(87654321);

    // Mostrar datos actualizados
    cout << "Datos actualizados de Persona 2:\n";
    persona2.mostrarInformacion();

    return 0;
}
