#include <iostream>
using namespace std;

#include "Rueda.cpp"

// 1) Crear una clase Carro
class Carro {
private:
    Rueda ruedas[4]; // 1A) Cuatro objetos de la clase Rueda como atributos
    bool enMovimiento; 

public:
    Carro(int tamanoRueda) : ruedas{Rueda(tamanoRueda), Rueda(tamanoRueda), Rueda(tamanoRueda), Rueda(tamanoRueda)}, enMovimiento(false) {}

    void mover() {
        enMovimiento = true;
        cout << "El carro está en movimiento." << endl;
    }

    void detener() {
        enMovimiento = false;
        cout << "El carro se ha detenido." << endl;
    }

    void cambiarRueda(int indice, int nuevoTamano) {
        // 2B) ¿Qué pasa si cambias una rueda a mitad de la marcha?
        if (enMovimiento) {
            cout << "¡No puedes cambiar una rueda mientras el carro está en marcha!" << endl;
            return;
        }

        if (indice >= 0 && indice < 4) {
            ruedas[indice].setTamano(nuevoTamano);
            cout << "Rueda " << indice + 1 << " cambiada." << endl;
        } else {
            cout << "Índice de rueda inválido." << endl;
        }
    }

    void inflarRuedas() {
        // 2A) Un método de Carro invoca métodos de Rueda
        for (int i = 0; i < 4; i++) {
            ruedas[i].inflar();
        }
    }
};
