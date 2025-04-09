#include <iostream>
#include <vector>
#include <string>
const int MAX=15;

using namespace std;

class Libro{
    private:
    string Isbn, titulo, anio;
    int cantEjemplar;

    public:

    Libro(string is=" ", string t= " ", string a=" ", int can=0)
    : Isbn(is), titulo(t), anio(a), cantEjemplar(can) {}

    string getTitulo(){return titulo;}

};

class Autor{
    private:
    string nombre, nacion; 
    Libro* libros[MAX];
    int numLibros;
    int nautorers;

    public:
    Autor(string n=" ", string na=" ")
    : nombre(n), nacion(na),  numLibros(0), nautorers(0){}

    void agregarLibro(Libro* nuevo){
        if (numLibros<MAX){
            libros[numLibros++]=nuevo;
            cout<<"libro agregado ..."<<endl;
        }
        else{
            cout<<"cantidad excede..."<<endl;
        }
    }

    void imprimirSoloautores(){
        cout<< " - " <<nombre << " - "<< nacion<<endl;
    }

    bool tieneLibros() {
        return numLibros > 0;
    }
    

    Libro* getLibro(int indice) {
        if (indice >= 0 && indice < numLibros) {
            return libros[indice];
        }
        return nullptr;
    }
    
};

class Prestamo {
    private:
        Libro* libroPrestado;
        string fechaPrestamo;
        string fechaDevolucion;
    
    public:
        Prestamo() : libroPrestado(nullptr), fechaPrestamo(""), fechaDevolucion("") {}
        
        Prestamo(Libro* libro, string fechaP, string fechaD)
            : libroPrestado(libro), fechaPrestamo(fechaP), fechaDevolucion(fechaD) {}
    
        void mostrarPrestamo() {
            cout << "Libro: " << libroPrestado->getTitulo() << endl;
            cout << "Fecha de prestamo: " << fechaPrestamo << endl;
            cout << "Fecha de devolucion: " << fechaDevolucion << endl;
        }
    };
    

class Usuario {
    private: 
    string nombre, direc, telefono;
    Prestamo* prestamos[MAX];
    int pres;

    public: 
    Usuario(string n=" ", string di= " ", string t=" ")
    : nombre(n), direc(di), telefono(t), pres(0) {}

    void imprimir (){
        cout<< " - " <<nombre << " - "<< direc<<" - "<<telefono<<endl;
    }

    void agregar_prestamo(Prestamo* agregaR){
        if (pres<MAX){
            prestamos[pres++]= agregaR;
            cout<<"prestamo agregado..."<<endl;
        }else{
            cout<<"cantidad excede..."<<endl;
        }
    }

    void imprimirLibro(){
        for (int i=0; i<pres; i++){
            prestamos[i]->mostrarPrestamo();
        }
    }

};



void mostrarMenu() {
    cout << "\n===== MENU BIBLIOTECA =====\n";
    cout << "1. Registrar autor\n";
    cout << "2. Registrar libro\n";
    cout << "3. Registrar usuario\n";
    cout << "4. Prestar libro\n";
    cout << "5. Mostrar prestamos de un usuario\n";
    cout << "6. Salir\n";
    cout << "Seleccione una opcion: ";
}

// ==== Programa Principal ====

int main() {
    Autor autores[MAX];
    Usuario usuarios[MAX];
    int n=0;
    int n1=0;
    int opcion;

    do {
        mostrarMenu();
        cin >> opcion;
        switch (opcion){
        case 1: {
            string nombre, nacionalidad;
            int numero;
            cout <<"numero de autores a registrar: ";
            cin>>numero;
            for (int i=0; i <numero; i++){
                cout << "Nombre del autor: ";
                cin>>nombre;
                cout << "Nacionalidad: ";
                cin>> nacionalidad;
                autores[n++]= Autor(nombre, nacionalidad);
                cout << "Autor registrado.\n";
                cout<<endl;
            }
            break;
        }
        case 2: {
            if (n==0) {
                cout << "No hay autores registrados. Registre un autor primero.\n";
                break;
            }
            string isbn, titulo,anio;
            int cantidad, idAutor;

            int numero;
            cout <<"numero de libros a registrar: ";
            cin>>numero;

            for (int i=0; i <numero; i++){
                cout << "ISBN: ";
                cin>> isbn;
                cout << "Titulo: ";
                cin>>titulo;
                cout << "Anio de publicacion: ";
                cin >> anio;
                cout << "Cantidad de ejemplares: ";
                cin >> cantidad;
                
                cout<<"----------AUTORES--------"<<endl;
                for (int i=0; i<n; i++){
                    cout<< i+1<< "| ";
                    autores[i].imprimirSoloautores();
                }
                cout << "Seleccione autor (indice):\n";
                cin >> idAutor;
                Libro* nuevoLibro = new Libro(isbn, titulo, anio, cantidad);
                autores[idAutor-1].agregarLibro(nuevoLibro);
            }
            cout << "Libro registrado.\n";
            break;
        
        }
        case 3: {
            string nombre, direccion, telefono;
            int numero;
            if (n1>MAX-1){break;}
            cout <<"numero de USUARIOS a registrar: ";
            cin>>numero;

            for (int i=0; i <numero; i++){
                cout << "Nombre del usuario: ";
                cin>>nombre;
                cout << "Direccion: ";
                cin>>direccion;
                cout << "Telefono: ";
                cin>>telefono;
                usuarios[n1++]= Usuario(nombre, direccion, telefono);
                cout << "Usuario registrado.\n";
            }
            break;
        }

        case 4: {
            if (n1 == 0 || n == 0) {
                cout << "Debe registrar usuarios y libros primero.\n";
                break;
            }
        
            int idUsuario, idAutor, idLibro;
            string fechaDev, fechaPRES;
        
            // Mostrar usuarios
            cout << "---------- USUARIOS ----------\n";
            for (int i = 0; i < n1; i++) {
                cout << i + 1 << " | ";
                usuarios[i].imprimir();
            }
            cout << "Seleccione usuario (índice): ";
            cin >> idUsuario;
        
            // Mostrar autores
            cout << "---------- AUTORES ----------\n";
            for (int i = 0; i < n; i++) {
                if (autores[i].tieneLibros()) {
                    cout << i + 1 << " | ";
                    autores[i].imprimirSoloautores();
                }
            }
            cout << "Seleccione autor del libro: ";
            cin >> idAutor;
        
            // Mostrar libros del autor seleccionado
            cout << "Libros del autor:\n";
            for (int i = 0; i < MAX; i++) {
                Libro* libro = autores[idAutor - 1].getLibro(i);
                if (libro != nullptr) {
                    cout << i + 1 << " | " << libro->getTitulo() << endl;
                }
            }
        
            cout << "Seleccione libro: ";
            cin >> idLibro;
        
            cout << "Fecha de PRESTAMO: ";
            cin >> fechaPRES;
        
            cout << "Fecha de DEVOLUCION: ";
            cin >> fechaDev;
        
            // Crear y agregar préstamo
            Libro* libroSeleccionado = autores[idAutor - 1].getLibro(idLibro - 1);
            Prestamo* nuevoPrestamo = new Prestamo(libroSeleccionado, fechaPRES, fechaDev);
            usuarios[idUsuario - 1].agregar_prestamo(nuevoPrestamo);
    
            break;
        }

        case 5: {
            if (n1 == 0 || n == 0) {
                cout << "no hay prestamos.\n";
                break;
            }
        
            int idUsuario;
        
            // Mostrar usuarios
            cout << "---------- USUARIOS ----------\n";
            for (int i = 0; i < n1; i++) {
                cout << i + 1 << " | ";
                usuarios[i].imprimir();
            }
            cout << "Seleccione usuario (Indice): ";
            cin >> idUsuario;

            usuarios[idUsuario-1].imprimirLibro();
            break;
        }
        case 6: {
            break;
        }
    }

    } while (opcion != 6);

    return 0;
}

