#include <iostream>
using namespace std;
class Cliente {
protected:
    string nombre;
    string correo;
    string direccion;

public:
    Cliente(string nom, string mail, string dir)
        : nombre(nom), correo(mail), direccion(dir) {}

    void mostrarNombre() {
        cout << "Nombre: " << nombre << endl;
    }

    void mostrarCorreo() {
        cout << "Correo: " << correo << endl;
    }

    void mostrarDireccion() {
        cout << "Dirección: " << direccion << endl;
    }
};

class ClientePublico : public Cliente {
public:
    ClientePublico(string nom, string mail, string dir)
        : Cliente(nom, mail, dir) {}

    void mostrarTodoPublico() {
        cout << "\n[Cliente con Herencia Pública]" << endl;
        mostrarNombre();      // acceso público
        mostrarCorreo();      // acceso público
        mostrarDireccion();   // acceso público
    }
};

// ---------- HERENCIA PROTEGIDA ----------
class ClienteProtegido : protected Cliente {
public:
    ClienteProtegido(string nom, string mail, string dir)
        : Cliente(nom, mail, dir) {}

    void mostrarTodoProtegido() {
        cout << "\n[Cliente con Herencia Protegida]" << endl;
        mostrarNombre();      
        mostrarDireccion();
    }
};

// ---------- HERENCIA PRIVADA ------------
class ClientePrivado : private Cliente {
public:
    ClientePrivado(string nom, string mail, string dir)
        : Cliente(nom, mail, dir) {}

    void mostrarTodoPrivado() {
        cout << "\n[Cliente con Herencia Privada]" << endl;
        mostrarNombre();     
        mostrarCorreo();
        mostrarDireccion();
    }
};

int main() {
    // HERENCIA PÚBLICA
    ClientePublico cliente1("Juan Pérez", "juan@email.com", "Av. Lima 123");
    cliente1.mostrarTodoPublico();
    cliente1.mostrarNombre(); // permitido porque sigue siendo público

    // HERENCIA PROTEGIDA
    ClienteProtegido cliente2("Ana Torres", "ana@email.com", "Av. Cusco 456");
    cliente2.mostrarTodoProtegido();
    // cliente2.mostrarNombre(); // Error: método protegido fuera de clase derivada

    // HERENCIA PRIVADA
    ClientePrivado cliente3("Luis Rojas", "luis@email.com", "Av. Arequipa 789");
    cliente3.mostrarTodoPrivado();
    // cliente3.mostrarCorreo(); // Error: método privado fuera de clase derivada

    return 0;
}
