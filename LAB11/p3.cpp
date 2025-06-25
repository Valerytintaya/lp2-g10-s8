
#include <iostream>
#include <fstream>
#include <string>
#include "cereal/archives/binary.hpp"
#include "cereal/types/string.hpp"

using namespace std;

// Clase Persona
class Persona {
private:
    string nombre;
    int edad;
    string direccion;
    friend class cereal::access;

    template <class Archive>
    void serialize(Archive& ar) {
        ar(nombre, edad, direccion);
    }

public:
    Persona() {} // Constructor por defecto 

    Persona(string n, int e, string d) : nombre(n), edad(e), direccion(d) {}

    void setNombre(string n) { nombre = n; }
    void setEdad(int e) { edad = e; }
    void setDireccion(string d) { direccion = d; }

    string getNombre() const { return nombre; }
    int getEdad() const { return edad; }
    string getDireccion() const { return direccion; }

    void mostrar() const {
        cout << "Nombre: " << nombre << endl;
        cout << "Edad: " << edad << endl;
        cout << "Dirección: " << direccion << endl;
    }
};

int main() {
    Persona personaOriginal("Juan Pérez", 30, "Av. Principal 123");

    {
        ofstream os("persona.dat", ios::binary);
        cereal::BinaryOutputArchive archive(os);
        archive(personaOriginal);
        cout << "Objeto serializado exitosamente.\n";
    }

    Persona personaRecuperada;
    {
        ifstream is("persona.dat", ios::binary);
        cereal::BinaryInputArchive archive(is);
        archive(personaRecuperada);
        cout << "\nObjeto deserializado exitosamente:\n";
        personaRecuperada.mostrar();
    }

    return 0;
}

//g++ -Iinclude p3.cpp -o programa
//./programa
