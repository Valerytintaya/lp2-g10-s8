#include <iostream>
using namespace std;

// 1) Crear una clase Rueda
class Rueda {
private:
    int tamano; // 2A) Atributo para el tamaño de la rueda

public:
    Rueda(int t) : tamano(t) {}

    int getTamano() const { return tamano; }
    void setTamano(int t) { tamano = t; }

    void inflar() { cout << "Rueda inflada." << endl; }
};
