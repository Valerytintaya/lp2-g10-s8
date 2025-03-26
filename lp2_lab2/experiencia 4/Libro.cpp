#include <iostream>
#include <string>
using namespace std;

// A) Crear una clase Libro
class Libro {
private:
    string titulo;
    string autor;
    bool prestado;
public:
    Libro(string t, string a) : titulo(t), autor(a), prestado(false) {}
    string getTitulo() const { return titulo; }
    string getAutor() const { return autor; }
    bool estaPrestado() const { return prestado; }

    // 2) Método para devolver el libro (elimina el atributo de préstamo)
    void prestar() { prestado = true; }
    void devolver() { prestado = false; }
};
