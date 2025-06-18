#include <iostream>
#include <string>
using namespace std;

const int MAX = 100;

template <typename T>
class Recipiente {
private:
    T elementos[MAX];
    int cantidad;

public:
    Recipiente() {
        cantidad = 0;
    }

    void agregar(T valor) {
        if (cantidad < MAX) {
            elementos[cantidad++] = valor;
        } else {
            cout << "El recipiente está lleno." << endl;
        }
    }

    void mostrar() const {
        cout << "Contenido del recipiente:\n";
        for (int i = 0; i < cantidad; i++) {
            cout << "- " << elementos[i] << endl;
        }
    }

    int size() const {
        return cantidad;
    }

    T obtener(int indice) const {
        if (indice >= 0 && indice < cantidad) {
            return elementos[indice];
        } else {
            cout << "Índice fuera de rango.\n";
            return T(); 
        }
    }
};


int main() {
    Recipiente<int> enteros;
    enteros.agregar(10);
    enteros.agregar(25);
    enteros.agregar(5);
    enteros.mostrar();

    Recipiente<string> textos;
    textos.agregar("Lima");
    textos.agregar("Arequipa");
    textos.agregar("Cusco");
    textos.mostrar();

    return 0;
}
