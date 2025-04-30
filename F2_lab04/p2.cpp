#include <iostream>
#include <string>
using namespace std;

class Fecha {
private:
    int dia, mes, anio;
public:
    Fecha(int d, int m, int a) : dia(d), mes(m), anio(a) {
        cout << "Fecha creada: ";
        cout << endl;
    }

    void mostrar() const {
        cout << "FECHA -  "<<dia << "/" << mes << "/" << anio;
    }
};

class Direccion {
private:
    string ciudad;
    string calle;

public:
    // Constructor de Direccion
    Direccion(string _ciudad, string _calle) {
        ciudad = _ciudad;
        calle = _calle;
    }

    // Métodos de acceso
    string getCiudad() { return ciudad; }
    string getCalle() { return calle; }

    // Método para mostrar información de la dirección
    void mostrarDireccion() {
        cout << "DIRECCION - Ciudad: " << ciudad << " | Calle: " << calle << endl;
    }
};

class Cliente {
    private:
    string nombre, dni;
    Fecha fechaRegistro;
    Direccion dirección;
    
    public:
    Cliente(string n, string dn, int d, int m, int a, string _ciudad, string _calle)
    : nombre (n), dni(dn), fechaRegistro(d,m,a), dirección(_ciudad, _calle){}

    void mostrar(){
        cout<<"CLIENTE -  nombre: "<<nombre <<" | dni: "<<dni<<endl;
        dirección.mostrarDireccion();
        fechaRegistro.mostrar();
    }
};

int main (){
    Cliente cliente1("Ana Perez", "12345678", 25, 4, 2025, "Arequipa", "Av. Ejemplo 123");
    // Mostrar la información del cliente
    cliente1.mostrar();
    return 0;
}