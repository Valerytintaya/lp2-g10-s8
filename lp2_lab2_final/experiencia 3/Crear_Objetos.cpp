#include <iostream>
#include <vector>
#include "claseA.cpp"
#include "claseC.cpp"
using namespace std;

void agregarPersona(vector<Persona>& lista, Persona nuevaPersona) {
    lista.push_back(nuevaPersona);
}

void agregarLibro(vector<Libro>& lista, Libro nuevoLibro) {
    lista.push_back(nuevoLibro);
}

void mostrarPersonas(const vector<Persona>& lista) {
    for (const auto& persona : lista) {
        persona.mostrarInformacion();
    }
}

void mostrarLibros(const vector<Libro>& lista) {
    for (const auto& libro : lista) {
        libro.mostrarInfoLibro();
    }
}

void eliminarPersona(vector<Persona>& lista, const string& nombre) {
    for (auto it = lista.begin(); it != lista.end(); ++it) {
        if (it->getNombre() == nombre) {
            lista.erase(it);
            break;
        }
    }
}

void actualizarEdadPersona(vector<Persona>& lista, const string& nombre, int nuevaEdad) {
    for (auto& persona : lista) {
        if (persona.getNombre() == nombre) {
            persona.setEdad(nuevaEdad);
            break;
        }
    }
}

// A) Método para comparar dos libros por título y autor
bool esIgualA(const Libro& libro1, const Libro& libro2) {
    return (libro1.getTitulo() == libro2.getTitulo() && libro1.getAutor() == libro2.getAutor());
}

int main() {
    vector<Persona> personas;
    vector<Libro> libros;

    agregarPersona(personas, Persona("Carlos Diaz", "Av. Lima 123", "10/05/1992", 32, 87654321));
    agregarPersona(personas, Persona("Andrés Pérez", "Calle 456", "22/03/1995", 29, 12345678));
    
    agregarLibro(libros, Libro("El Quijote", "Miguel de Cervantes", "Novela", 1605, 500));
    agregarLibro(libros, Libro("1984", "George Orwell", "Distopía", 1949, 328));
    agregarLibro(libros, Libro("1984", "George Orwell", "Distopía", 1949, 328));
    
    cout << "Lista de Personas antes de eliminar y actualizar:" << endl;
    mostrarPersonas(personas);
    
    eliminarPersona(personas, "Carlos Diaz");
    
    actualizarEdadPersona(personas, "Andrés Pérez", 30);
    
    cout << "Lista de Personas después de eliminar y actualizar:" << endl;
    mostrarPersonas(personas);
    
    // B) Comparar dos libros en el arreglo
    if (esIgualA(libros[1], libros[2])) {
        cout << "Los libros son iguales." << endl;
    } else {
        cout << "Los libros son diferentes." << endl;
    }
    
    return 0;
}

