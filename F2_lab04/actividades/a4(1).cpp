#include <iostream>
#include <string>
using namespace std;

class ComponenteA {
private:
    string nombreA;

public:
    ComponenteA() : nombreA("Componente A") {
        cout << "Se construyo " << nombreA << "." << endl;
    }

    ~ComponenteA() {
        cout << "Se destruyo " << nombreA << "." << endl;
    }
};

class ComponenteB {
private:
    string nombreB;

public:
    ComponenteB() : nombreB("Componente B") {
        cout << "Se construyo " << nombreB << "." << endl;
    }

    ~ComponenteB() {
        cout << "Se destruyo " << nombreB << "." << endl;
    }
};

class Sistema {
private:
    ComponenteA componenteA; // Miembro objeto
    ComponenteB componenteB; // Miembro objeto
    string nombreSistema;    // Atributo adicional

public:
    Sistema() : nombreSistema("Sistema Principal") {
        cout << "Se construyo " << nombreSistema << "." << endl;
    }

    ~Sistema() {
        cout << "Se destruyo " << nombreSistema << "." << endl;
    }
};

int main() {
    cout << "Creando objeto Sistema...\n";
    Sistema sistema;
    cout << "Objeto Sistema creado.\n";

    return 0;
}
