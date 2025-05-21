#include <iostream>
using namespace std;

// Clase base con método virtual
class Animal {
public:
    virtual void hacerSonido() {
        cout << "Este animal hace un sonido genérico." << endl;
    }

    virtual ~Animal() {}
};

// Clase derivada: Perro
class Perro : public Animal {
public:
    void hacerSonido() override {
        cout << "El perro dice: ¡Guau guau!" << endl;
    }
};

// Clase derivada: Gato
class Gato : public Animal {
public:
    void hacerSonido() override {
        cout << "El gato dice: ¡Miau!" << endl;
    }
};

// Clase derivada: Vaca
class Vaca : public Animal {
public:
    void hacerSonido() override {
        cout << "La vaca dice: ¡Muuu!" << endl;
    }
};

// Función principal
int main() {
    // Usando polimorfismo
    Animal* animal1 = new Perro();
    Animal* animal2 = new Gato();
    Animal* animal3 = new Vaca();

    // Llamadas polimórficas
    cout << "Sonidos de los animales:" << endl;
    animal1->hacerSonido();  // Perro
    animal2->hacerSonido();  // Gato
    animal3->hacerSonido();  // Vaca

    // Liberar memoria
    delete animal1;
    delete animal2;
    delete animal3;

    return 0;
}
