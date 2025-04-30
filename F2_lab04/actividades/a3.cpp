#include <iostream>
#include <string>
using namespace std;

class Fecha {
private:
    int dia, mes, anio;
public:
    Fecha(int d, int m, int a) : dia(d), mes(m), anio(a) {}

    void mostrar() const {
        cout << dia << "/" << mes << "/" << anio << endl;
    }
};

class Contrato {
public:
    string codigo, descrip;
    Fecha fechainicio;

    // Constructor for Contrato
    Contrato(string c, string des, int d, int m, int a) 
    : codigo(c), descrip(des), fechainicio(d, m, a) {}

    void mostrarContrato() {
        cout << "CONTRATO:" << endl;
        cout << "codigo: " << codigo << " | descripcion: " << descrip << endl;
        fechainicio.mostrar();
    }
};

class Empleado {
private:
    string nombre, dni;
    Contrato contratos;

public:

    Empleado(string n, string dn, string c, string des, int d, int m, int a)
        : nombre(n), dni(dn), contratos(c, des, d, m, a) {
        cout << "Empleado creado..." << endl;
    }

    void mostrarInfo() {
        cout << "EMPLEADO: " << nombre << " DNI: " << dni << endl;
        contratos.mostrarContrato();
    }
};

int main() {
    Empleado p("Ana", "12345678", "001", "Contrato por 3 meses", 10, 01, 2001);
    p.mostrarInfo();
    return 0;
}
