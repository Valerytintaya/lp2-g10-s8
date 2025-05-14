#include <iostream>
#include <string>
using namespace std;

class Persona {
    private: 
    string nombre;
    int edad;
    float salario;
    
    protected:
    string email; // accesible clases derivadas

    public:
    Persona(string n, int e, float s, string em)
        : nombre(n), edad(e), salario(s), email(em) {}
        
    string getNombre(){return nombre;}

    void mostrarBase() {
        cout << "Nombre: " << nombre << endl;
        cout << "Edad: " << edad << " años" << endl;
        cout << "Salario: $" << salario << endl;
    }
};

class Empleado : public Persona {
private:
    string puesto;

public:
    Empleado(string n, int e, float s, string em, string p)
        : Persona(n, e, s, em), puesto(p) {}

    void mostrar() {
        mostrarBase(); 
        cout << "Correo electronico: " << email << endl; 
        cout << "Puesto: " << puesto<< endl;
    }
};

class Cliente : public Persona {
private:
    string empresa;

public:
    Cliente(string n, int e, float s, string em, string emp)
        : Persona(n, e, s, em), empresa(emp) {}

    void mostrar() {
        mostrarBase(); // Llamamos al método mostrar de la clase base
        cout << "Correo electronico: " << email << endl; 
        cout << "Empresa: " << empresa<< endl; // si llamo email aqui como atributo si se puede << email << endl;
    }
};

int main() {
    Empleado emp("Juan Pérez", 30, 50000, "juan.perez@empresa.com", "Desarrollador");
    Cliente c1("María López", 45, 0, "maria.lopez@cliente.com", "Compañía ABC");

    // Mostrar la información del empleado
    cout << "Información del empleado:" << endl;
    emp.mostrar();
    cout << endl;

    // Mostrar la información del cliente
    cout << "Información del cliente:" << endl;
    c1.mostrar();
    
    return 0;
}



