#include <iostream>
#include <string>
using namespace std;
// Clase Brazo (objeto compuesto)
class Brazo {
private:
    string nombre;
public:
    // Constructor para inicializar el brazo
    Brazo(string n = "") : nombre(n) {}
    // Método para mostrar el nombre del brazo
    void mostrar() {
        cout << "Este es el " << nombre << endl;
    }
};

// Clase Humano (contenedora)
class Humano {
private:
    Brazo* brazo;  // El brazo es un objeto compuesto del humano
public:
    // Constructor: Inicializa el brazo
    Humano(string brazoNombre = "") {
        brazo = new Brazo(brazoNombre);  // Creamos el brazo
    }
    // Destructor: Elimina el brazo cuando el humano se destruye
    ~Humano() {
        delete brazo;  
        cout << "El humano ha sido destruido, junto con su brazo." << endl;
    }

    // Método para acceder al brazo
    Brazo& obtenerBrazo() {
        return *brazo;  // Retorna una referencia al brazo
    }
};

int main() {
    // Crear un objeto de la clase Humano, el cual automáticamente crea un brazo
    Humano h1("Brazo izquierdo");

    // Acceder al brazo y mostrar información sobre él
    h1.obtenerBrazo().mostrar();
    return 0;
}
