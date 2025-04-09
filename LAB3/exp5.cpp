#include <iostream>
#include <string>
using namespace std;

const int MAX = 10;  // Tamaño máximo de la colección

// Clase que representa los objetos a agregar
class Objeto {
private:
    int id;
    string nombre;

public:
    // Constructor
    Objeto(int i = 0, string n = " ") : id(i), nombre(n) {}

    // Métodos para establecer y obtener los atributos
    void setId(int i) { id = i; }
    int getId() { return id; }

    void setNombre(string n) { nombre = n; }
    string getNombre() { return nombre; }

    // Método para mostrar los detalles del objeto
    void mostrar() {
        cout << "ID: " << id << ", Nombre: " << nombre << endl;
    }

    ~Objeto (){
        cout<<"objeto eliminado.."<<endl;
    }
};

// Clase base que representa la colección
class Coleccion {
private:
    Objeto* objetos[MAX];  // Colección de objetos
    int numObjetos;

public:
    // Constructor
    Coleccion() : numObjetos(0) {}

    // Método para agregar un objeto a la colección
    void agregarObjeto(Objeto* obj) {
        if (numObjetos < MAX) {
            objetos[numObjetos++] = obj;
        } else {
            cout << "La colección está llena, no se puede agregar más objetos." << endl;
        }
    }

    // Método para eliminar un objeto de la colección
    void eliminarObjeto(int id) {
        for (int i = 0; i < numObjetos; i++) {
            if (objetos[i]->getId() == id) {
                // Desplazar los elementos
                for (int j = i; j < numObjetos - 1; j++) {
                    objetos[j] = objetos[j + 1];
                }
                numObjetos--;
                cout << "Objeto con ID " << id << " eliminado." << endl;
                return;
               
            }
        }
       
        cout << "Objeto con ID " << id << " no encontrado." << endl;
      
    }

    void mostrarColeccion() {
        if (numObjetos == 0) {
            cout << "La coleccion está vacía." << endl;
            return;
        }
        cout << "Objetos en la colección:" << endl;
        for (int i = 0; i < numObjetos; i++) {
            objetos[i]->mostrar();
        }
    }

    // Método para obtener un objeto de la colección
    Objeto* obtenerObjeto(int id) {
        for (int i = 0; i < numObjetos; i++) {
            if (objetos[i]->getId() == id) {
                return objetos[i];
            }
        }
        cout << "Objeto con ID " << id << " no encontrado." << endl;
        return nullptr;
    }

    ~Coleccion (){
        cout<<"coleccion eliminada..."<<endl;
    }
};

// Función principal
int main() {
    // Crear objetos de la clase Objeto
    Objeto obj1 (1, "Objeto 1");
    Objeto obj2 (2, "Objeto 2");
    Objeto obj3 (3, "Objeto 3");

    // Crear una instancia de la clase Coleccion
    Coleccion coleccion;

    // Agregar los objetos a la colección
    coleccion.agregarObjeto(&obj1);
    coleccion.agregarObjeto(&obj2);
    coleccion.agregarObjeto(&obj3);

    // Mostrar los objetos en la colección
    coleccion.mostrarColeccion();

    Objeto* objModificado = coleccion.obtenerObjeto(2);
    if (objModificado) {
        objModificado->setNombre("Objeto Modificado");
    }
    // Eliminar un objeto de la colección
    coleccion.eliminarObjeto(1);

    // Mostrar la colección después de eliminar un objeto
    coleccion.mostrarColeccion();

    return 0;
}
