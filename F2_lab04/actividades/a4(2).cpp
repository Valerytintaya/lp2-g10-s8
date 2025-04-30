#include <iostream>
#include <string>
using namespace std;

class A {
private:
    string nombreA; 
public:
    A() : nombreA("Componente A") {
        cout << "Constructor de A llamado. Nombre: " << nombreA << endl;
    }

    ~A() {
        cout << "Destructor de A llamado. Nombre: " << nombreA << endl;
    }
};

class B {
private:
    A objetoA;      
    string nombreB; 

public:
    B() : nombreB("Sistema B") {
        cout << "Constructor de B llamado. Nombre: " << nombreB << endl;
    }

    ~B() {
        cout << "Destructor de B llamado. Nombre: " << nombreB << endl;
    }
};

int main() {
    cout << "Creando objeto B..." << endl;
    B objetoB;
    cout << "Objeto B creado." << endl;

    return 0;
}
