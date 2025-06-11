#include <iostream>
using namespace std;

// Clase base
class Animal {
public:
    virtual void hacerSonido() const {
        cout << "Sonido genérico de animal" << endl;
    }
    virtual ~Animal() {}
};

// Clases derivadas
class Perro : public Animal {
public:
    void hacerSonido() const override {
        cout << "Guau guau" << endl;
    }
};

class Gato : public Animal {
public:
    void hacerSonido() const override {
        cout << "Miau miau" << endl;
    }
};

class Vaca : public Animal {
public:
    void hacerSonido() const override {
        cout << "Muu muu" << endl;
    }
};

int main() {
    Animal* animales[3];
    animales[0] = new Perro();
    animales[1] = new Gato();
    animales[2] = new Vaca();

    for (int i = 0; i < 3; i++) {
        animales[i]->hacerSonido();  // Ejecuta la versión correcta según el tipo real
    }

    // Liberar memoria
    for (int i = 0; i < 3; i++) {
        delete animales[i];
    }

    return 0;
}
