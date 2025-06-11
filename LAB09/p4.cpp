#include <iostream>
using namespace std;

// Clase base abstracta
class Personaje {
public:
    virtual void atacar() = 0;
    virtual void defender() = 0;
    virtual void usarHabilidadEspecial() = 0;
    virtual ~Personaje() {}
};

// Clase Guerrero
class Guerrero : public Personaje {
public:
    void atacar() override {
        cout << "El Guerrero ataca con su espada." << endl;
    }

    void defender() override {
        cout << "El Guerrero bloquea con su escudo." << endl;
    }

    void usarHabilidadEspecial() override {
        cout << "El Guerrero usa 'Furia del acero' ." << endl;
    }
};

// Clase Mago
class Mago : public Personaje {
public:
    void atacar() override {
        cout << "El Mago lanza un hechizo." << endl;
    }

    void defender() override {
        cout << "El Mago crea una barrera." << endl;
    }

    void usarHabilidadEspecial() override {
        cout << "El Mago usa 'Tormenta ' ." << endl;
    }
};

// Clase Arquero
class Arquero : public Personaje {
public:
    void atacar() override {
        cout << "El Arquero dispara una flecha." << endl;
    }

    void defender() override {
        cout << "El Arquero esquiva el ataque." << endl;
    }

    void usarHabilidadEspecial() override {
        cout << "El Arquero ataca ." << endl;
    }
};

int main() {
    Personaje* personajes[3];
    personajes[0] = new Guerrero();
    personajes[1] = new Mago();
    personajes[2] = new Arquero();

    for (int i = 0; i < 3; i++) {
        personajes[i]->atacar();
        personajes[i]->defender();
        personajes[i]->usarHabilidadEspecial();
        cout << endl;
    }

    for (int i = 0; i < 3; i++) {
        delete personajes[i];
    }

    return 0;
}
