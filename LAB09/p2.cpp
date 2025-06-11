#include <iostream>
using namespace std;

// Clase base abstracta
class Animal {
public:
    virtual void comer() = 0;
    virtual void dormir() = 0;
    virtual void moverse() = 0;
    virtual ~Animal() {}
};

// Mamífero
class Mamifero : public Animal {
public:
    void comer() override {
        cout << "El mamifero mastica su comida." << endl;
    }
    void dormir() override {
        cout << "El mamifero duerme en tierra firme." << endl;
    }
    void moverse() override {
        cout << "El mamifero camina sobre sus patas." << endl;
    }
};

// Ave
class Ave : public Animal {
public:
    void comer() override {
        cout << "El ave picotea su alimento." << endl;
    }
    void dormir() override {
        cout << "El ave duerme en su nido." << endl;
    }
    void moverse() override {
        cout << "El ave vuela por el aire." << endl;
    }
};

// Reptil
class Reptil : public Animal {
public:
    void comer() override {
        cout << "El reptil traga su comida sin masticar." << endl;
    }
    void dormir() override {
        cout << "El reptil duerme bajo una roca." << endl;
    }
    void moverse() override {
        cout << "El reptil se arrastra lentamente." << endl;
    }
};

int main() {
    Animal* animales[3];
    animales[0]= new Mamifero;
    animales[1]= new Ave;
    animales[2]= new Reptil;

    for (int i = 0; i < 3; ++i) {
        animales[i]->comer();
        animales[i]->dormir();
        animales[i]->moverse();
        cout<<"----------------------------------"<<endl;
    }

    return 0;
}
