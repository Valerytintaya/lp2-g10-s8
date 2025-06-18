#include <iostream>
#include <string>
using namespace std;
template <typename T> //
class Ruta {
private:
    T inicio;
    T destino;
    double distancia;

public:
    Ruta(T ini, T des, double dist) : inicio(ini), destino(des), distancia(dist) {}

    void mostrarRuta() const {
        cout << "Ruta desde " << inicio << " hasta " 
             << destino << " con una distancia de " << distancia << " km." << endl;
    }

    double obtenerDistancia() const {
        return distancia;
    }
};
// Clase principal del sistema de gestión de rutas de entrega
template <typename T>
class SistemaGestionRutas {
private:
    Ruta<T>* rutas[100];
    int contadorRutas;

public:
    SistemaGestionRutas() : contadorRutas(0) {}

    ~SistemaGestionRutas() {
        for (int i = 0; i < contadorRutas; ++i) {
            delete rutas[i];
        }
    }
    void agregarRuta(T inicio, T destino, double distancia) {
        if (contadorRutas < 100) {
            rutas[contadorRutas++] = new Ruta<T>(inicio, destino, distancia);
        } else {
            cout << "No se pueden agregar más rutas." << endl;
        }
    }

    void mostrarRutas() const {
        for (int i = 0; i < contadorRutas; ++i) {
            rutas[i]->mostrarRuta();
        }
    }

    double calcularDistanciaTotal() const {
        double total = 0;
        for (int i = 0; i < contadorRutas; ++i) {
            total += rutas[i]->obtenerDistancia();
        }
        return total;
    }
};



// Función principal para probar el sistema
int main() {
    // Prueba con strings
    SistemaGestionRutas<string> sistemaString;
    sistemaString.agregarRuta("A", "B", 10.5);
    sistemaString.agregarRuta("B", "C", 20.3);
    sistemaString.agregarRuta("C", "D", 15.0);

    cout << "Rutas en el sistema (string):" << endl;
    sistemaString.mostrarRutas();
    cout << "Distancia total de todas las rutas: " << sistemaString.calcularDistanciaTotal() << " km" << endl;

    // Prueba con chars
    SistemaGestionRutas<char> sistemaChar;
    sistemaChar.agregarRuta('A', 'B', 5.5);
    sistemaChar.agregarRuta('B', 'C', 10.2);

    cout << "\nRutas en el sistema (char):" << endl;
    sistemaChar.mostrarRutas();
    cout << "Distancia total de todas las rutas: " << sistemaChar.calcularDistanciaTotal() << " km" << endl;


    return 0;
}