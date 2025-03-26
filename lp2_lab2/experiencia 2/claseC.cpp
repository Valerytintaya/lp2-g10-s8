#include <iostream>
#include <string>
using namespace std;

class Libro {
private:
    string titulo;
    string autor;
    string genero;

public:
    int anio;
    int numeroPaginas;

    // Constructor
    Libro(string _titulo, string _autor, string _genero, int _anio, int _numeroPaginas)
        : titulo(_titulo), autor(_autor), genero(_genero), anio(_anio), numeroPaginas(_numeroPaginas) {}

    // Getters
    string getTitulo() const { return titulo; }
    string getAutor() const { return autor; }
    string getGenero() const { return genero; }

    // Setters
    void setTitulo(string _titulo) { titulo = _titulo; }
    void setAutor(string _autor) { autor = _autor; }
    void setGenero(string _genero) { genero = _genero; }

    // Método auxiliar para mostrar la información del libro
    void mostrarInfoLibro() {
        cout << "Libro: " << titulo << endl;
        cout << "Autor: " << autor << endl;
        cout << "Genero: " << genero << endl;
        cout << "Año de publicacion: " << anio << endl;
        cout << "Numero de paginas: " << numeroPaginas << endl;
        cout << "----------------------" << endl;
    }
};

int main() {
    // Instanciando varios libros
    Libro libro1("Cien anios de soledad", "Gabriel Garcia Marquez", "Realismo magico", 1967, 471);
    Libro libro2("1984", "George Orwell", "Ciencia ficcion", 1949, 328);
    Libro libro3("El principito", "Antoine de Saint-Exupery", "Fabula", 1943, 96);

    // Mostrando información de los libros
    libro1.mostrarInfoLibro();
    libro2.mostrarInfoLibro();
    libro3.mostrarInfoLibro();

    // Modificando algunos datos usando los setters
    libro1.setTitulo("Cien anios de soledad (Edicion especial)");
    libro1.setGenero("Ficcion historica");

    // Verificando cambios
    cout << "Actualizacion del libro 1:" << endl;
    libro1.mostrarInfoLibro();

    return 0;
}
