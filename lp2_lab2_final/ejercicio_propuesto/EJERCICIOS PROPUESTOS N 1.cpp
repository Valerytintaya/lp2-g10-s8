#include <iostream>
#include <cstdlib>
#include <ctime>
#include <string>
using namespace std;

class Auto {
private:
    string nombre;
    string color;
    float velocidad;
    float distanciaR;

public:
    Auto(string n = "PC1", string c = "ds", float v = 0.0, float dis=0.0) 
        : nombre(n), color(c), velocidad(v), distanciaR(dis) {}

    float getDistancia() { return distanciaR; }
    string getNombre() { return nombre; }

    float acelerar() {
        int avance = rand() % 10 + 1; // Avanza entre 1 y 10 unidades por turno
        distanciaR += avance;
        return avance; // Solo devuelve la distancia recorrida, no imprime nada
    }
};

class Carrera {
private:
    Auto *autos;
    int cantidad;
    float distanciaTotal;
    string dificultad;
    Auto computadora;

public:
    Carrera(Auto *a, int n, float dist = 50, string difi = "2") 
        : autos(a), cantidad(n), distanciaTotal(dist), dificultad(difi), computadora("Computadora", "Negro", 10.0) {}

    void iniciar_carrera() {
        cout << "\t=== LA CARRERA INICIA === con " << cantidad + 1 << " vehículos" << endl;
        cout << "Distancia total: " << distanciaTotal << " metros" << endl;

        while (!finalizarCarrera()) {
            cout << "Presiona Enter para avanzar...";
            cin.ignore();
            cout << endl;

            for (int i = 0; i < cantidad; i++) {
                float avance = autos[i].acelerar();
                cout << "El auto " << autos[i].getNombre() << " recorre " << avance 
                     << " metros. Total recorrido: " << autos[i].getDistancia() << "m" << endl;
            }

            int avance_pc = compt_pc();
            cout << "La computadora recorre " << avance_pc 
                 << " metros. Total recorrido: " << computadora.getDistancia() << "m" << endl;

            cout << "-----------------------------" << endl;
        }
        determinar_ganador();
    }

    
    int compt_pc() {
        int avance = rand() % 10 + 1; // Avance base
    
        if (dificultad == "1") { // Fácil
            if (rand() % 4 == 0) { // 25% de probabilidad de retroceder
                int retroceso = rand() % 5 + 1; // Retrocede entre 1 y 5 metros
                computadora = Auto(computadora.getNombre(), "Negro", 10.0, computadora.getDistancia() - retroceso);
                return -retroceso; // Devuelve la distancia negativa
            }
        } else if (dificultad == "2") { // Medio
            avance = rand() % 8 + 2;
        } else { // Difícil
            avance = rand() % 6 + 5;
        }
    
        computadora = Auto(computadora.getNombre(), "Negro", 10.0, computadora.getDistancia() + avance);
        return avance; // Devuelve la distancia recorrida
    }
    
    

    bool finalizarCarrera() {
        if (computadora.getDistancia() >= distanciaTotal) return true;
        for (int i = 0; i < cantidad; i++) {
            if (autos[i].getDistancia() >= distanciaTotal) return true;
        }
        return false;
    }

    void determinar_ganador() {
        float max_distancia = computadora.getDistancia();
        string ganador = computadora.getNombre();
        bool empate = false;

        for (int i = 0; i < cantidad; i++) {
            if (autos[i].getDistancia() > max_distancia) {
                max_distancia = autos[i].getDistancia();
                ganador = autos[i].getNombre();
                empate = false;
            } else if (autos[i].getDistancia() == max_distancia) {
                empate = true;
            }
        }

        if (empate) {
            cout << "¡Es un empate!" << endl;
        } else {
            cout << "¡El ganador es " << ganador << "!" << endl;
        }
    }
};

int main() {
    srand(time(0));
    int n;
    cout << "Cantidad de jugadores: ";
    cin >> n;
    Auto *autos = new Auto[n];

    for (int i = 0; i < n; i++) {
        string nombre, color;
        float velocidad;
        cout << "\t=== AUTO " << i + 1 << " ===" << endl;
        cout << "Nombre del auto: ";
        cin >> nombre;
        cout << "Color: ";
        cin >> color;
        cout << "Velocidad (km/h): ";
        cin >> velocidad;
        autos[i] = Auto(nombre, color, velocidad);
    }

    float distancia;
    cout << "Metros de la carrera: ";
    cin >> distancia;
    string dificultad;
    cout << "Dificultad (1=Facil, 2=Medio, 3=Dificil): ";
    cin >> dificultad;

    Carrera carrera(autos, n, distancia, dificultad);
    carrera.iniciar_carrera();

    delete[] autos;
    return 0;
}
