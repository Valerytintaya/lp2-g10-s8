#include <iostream>
#include <string>
using namespace std;

class Dispositivo {
private:
    int codigo;
    string marca, modelo, anio;
    string color;
    int año;
   

public:
    // Constructor por defecto
    Dispositivo() {
        codigo = 0;
        marca = "apple";
        modelo = "iphone 10";
        anio = "2010";
        color="gold";

    }

    // Constructor parametrizado
    Dispositivo(string m, string mo, string an) : marca(m), modelo(mo), anio(an) {}

    // Constructor de copia
    Dispositivo(const Dispositivo& copia) {
        marca = copia.marca;
        modelo = copia.modelo;
        anio = copia.anio;
    }

    // Constructor de copia2

    // Destructor
    ~Dispositivo() {
        cout << modelo << " destruido" << endl;
    }

    // Método para mostrar información del dispositivo
    void mostrar() {
        cout << "Marca: " << marca << ", Modelo: " << modelo << ", Anio: " << anio << endl;
    }
};

int main() {
    // Crear un arreglo de objetos Dispositivo
    Dispositivo dispositivos[3] = {
        Dispositivo(),
        Dispositivo("Samsung", "A10", "2018"),
        Dispositivo("Xiomi", "HonorX", "2020")
    };

    // Mostrar los dispositivos
    for (int i = 0; i < 3; i++) {
        dispositivos[i].mostrar();
    }

    return 0;
}
