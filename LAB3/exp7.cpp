#include <iostream>
#include <string>
using namespace std;

// Clase base "Ave"
class Ave {
private:
    string nombre;
    int edad;

public:
    // Constructor de la clase base
    Ave(string n = "Ave desconocida", int e = 0) : nombre(n), edad(e) {}

    virtual ~Ave() {
        cout << "Destruyendo Ave: " << nombre << endl;
    }

    // Métodos de la clase base
    void volar() {
        cout << nombre << " esta volando." << endl;
    }


    string getNombre() const { return nombre; }
    int getEdad() const { return edad; }
};


class Gallina : public Ave {
private:
    bool poneHuevos;

public:
    Gallina(string n, int e, bool p = true) : Ave(n, e), poneHuevos(p) {}

    ~Gallina() {
        cout << "Destruyendo Gallina: " << getNombre() << endl;
    }

    // Método propio de la clase derivada
    void ponerHuevos() {
        if (poneHuevos) {
            cout << getNombre() << " esta poniendo huevos." << endl;
        } else {
            cout << getNombre() << " no pone huevos." << endl;
        }
    }

    void cambiarEstadoHuevos(bool estado) {
        poneHuevos = estado;
    }
};


int main() {

    Gallina g1("Gallina guinea", 3);

    // Acceder a los métodos heredados de la clase base "Ave"
    g1.volar();
    cout << "La " << g1.getNombre() << " tiene " << g1.getEdad() << " años." << endl;

    // Acceder a los métodos propios de la clase derivada "Gallina"
    g1.ponerHuevos();

    // Modificar el atributo propio de la clase derivada
    g1.cambiarEstadoHuevos(false);
    g1.ponerHuevos();

    return 0;
}
