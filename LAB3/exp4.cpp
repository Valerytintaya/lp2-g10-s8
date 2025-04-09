#include <iostream>
#include <string>
using namespace std;

const int MAX = 10;  // Tamaño máximo del arreglo de trabajadores

// Clase Trabajador
class Trabajador {
private:
    string nombre, apellido, edad;
    Trabajador* companeros[MAX];  // Relación reflexiva: trabajadores que son compañeros
    int numCompaneros;

public:
    // Constructor
    Trabajador(string n = " ", string a = " ", string e = " ")
        : nombre(n), apellido(a), edad(e), numCompaneros(0) {}

    // Métodos para establecer y obtener nombre
    void setNombre(string nuevo) { nombre = nuevo; }
    string getNombre() { return nombre; }

    // Método para agregar compañeros (asociación reflexiva)
    void agregarCompanero(Trabajador* compañero) {
        if (numCompaneros < MAX) {
            companeros[numCompaneros++] = compañero;
        }
    }

    // Método para imprimir compañeros
    void imprimirCompaneros() {
        if (numCompaneros == 0) {
            cout << nombre << " no tiene compañeros asignados." << endl;
        } else {
            cout << nombre << " tiene los siguientes compañeros: ";
            for (int i = 0; i < numCompaneros; i++) {
                cout << companeros[i]->getNombre() << " ";
            }
            cout << endl;
        }
    }
};

// Clase Gerente que hereda de Trabajador
class Gerente : public Trabajador {
private:
    string area;
    Trabajador* trabajadores[MAX];  // Arreglo de trabajadores a su cargo
    int numTrabajadores;

public:
    // Constructor
    Gerente(string n = " ", string a = " ", string e = " ")
        : Trabajador(n, a, e), area(""), numTrabajadores(0) {}

    // Establecer y obtener área
    void setArea(string a) { area = a; }
    string getArea() { return area; }

    // Método para agregar trabajador al gerente
    void agregarTrabajador(Trabajador* t) {
        if (numTrabajadores < MAX) {
            trabajadores[numTrabajadores++] = t;
        }
    }

    // Método para mostrar información de los trabajadores a cargo
    void imprimirTrabajadores() {
        cout << "Trabajadores a cargo del gerente " << getNombre() << ": ";
        for (int i = 0; i < numTrabajadores; i++) {
            cout << trabajadores[i]->getNombre() << " ";
        }
        cout << endl;
    }

    // Establecer relaciones de compañeros entre los trabajadores a cargo
    void establecerRelaciones() {
        for (int i = 0; i < numTrabajadores; i++) {
            for (int j = 0; j < numTrabajadores; j++) {
                if (i != j) {
                    trabajadores[i]->agregarCompanero(trabajadores[j]);
                }
            }
        }
    }
};

// Función principal
int main() {
    // Crear instancias de los trabajadores y gerentes
    Gerente g1("Carlos", "Producción", "40");
    Gerente g2("Beto", "Administración", "45");

    Trabajador t1("Nano", "Lopez", "24");
    Trabajador t2("Felip", "Nuñez", "34");
    Trabajador t3("Ana", "Arcos", "43");

    // Asignar trabajadores a los gerentes
    g1.agregarTrabajador(&t1);
    g1.agregarTrabajador(&t2);

    g2.agregarTrabajador(&t3);

    // Establecer relaciones entre los trabajadores del mismo gerente
    g1.establecerRelaciones();
    g2.establecerRelaciones();

    // Mostrar los compañeros de cada trabajador
    t1.imprimirCompaneros();
    t2.imprimirCompaneros();
    t3.imprimirCompaneros();

    // Mostrar los trabajadores a cargo de cada gerente
    g1.imprimirTrabajadores();
    g2.imprimirTrabajadores();

    return 0;
}
