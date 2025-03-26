#include <iostream>
#include <vector>
#include <string>
using namespace std;

// Definir la clase Libro antes de usarla en Biblioteca
class Libro {
private:
    string titulo;
    string autor;
    bool prestado;
public:
    Libro() : titulo(""), autor(""), prestado(false) {} // Constructor por defecto
    Libro(string t, string a) : titulo(t), autor(a), prestado(false) {}

    string getTitulo() const { return titulo; }
    string getAutor() const { return autor; }
    bool estaPrestado() const { return prestado; }

    void prestar() { prestado = true; }
    void devolver() { prestado = false; }
};

// Definir la clase Biblioteca
class Biblioteca {
private:
    vector<Libro> libros;
public:
    void agregarLibro(const Libro& libro) { libros.push_back(libro); }

    void prestarLibro(string titulo) {
        for (auto& libro : libros) {
            if (libro.getTitulo() == titulo) {
                if (!libro.estaPrestado()) {
                    libro.prestar();
                    cout << "Libro prestado: " << titulo << endl;
                } else {
                    cout << "El libro ya está prestado." << endl;
                }
                return;
            }
        }
        cout << "Libro no encontrado." << endl;
    }
};
