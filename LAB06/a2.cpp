#include <iostream>
#include <cmath> 

using namespace std;

class Circulo {
private:
    double radio;
    double diametro;

public:
    Circulo(double r) {
        radio = r;
        diametro = 2 * r;
    }

    void mostrarDatos() {
        cout << "Radio: " << radio << " unidades" << endl;
        cout << "Diámetro: " << diametro << " unidades" << endl;
    }

    friend double calcularArea(const Circulo& c);
};

double calcularArea(const Circulo& c) {
    return M_PI * c.radio * c.radio;
}

int main() {
    Circulo c1(3.0);
    Circulo c2(5.5);

    cout << "CÍRCULO 1" << endl;
    c1.mostrarDatos();
    cout << "Área: " << calcularArea(c1) << " unidades cuadradas" << endl;

    cout << "\nCÍRCULO 2" << endl;
    c2.mostrarDatos();
    cout << "Área: " << calcularArea(c2) << " unidades cuadradas" << endl;
    return 0;
}
