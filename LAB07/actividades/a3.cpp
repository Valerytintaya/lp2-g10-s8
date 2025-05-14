#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

class Cliente {
protected:
    string nombre;
    string correo;
    string direccion;
    string numeroTarjeta;
    string cvv;
    string contrasena;

    string encriptar(string dato) {
        reverse(dato.begin(), dato.end());
        return dato;
    }

public:
    // Constructor de la clase base
    Cliente(string nom, string mail, string dir, string tarjeta, string cvv, string pass)
        : nombre(nom), correo(mail), direccion(dir),
          numeroTarjeta(tarjeta), cvv(cvv), contrasena(pass) {
        cout << "Constructor de Cliente llamado." << endl;
    }

    void mostrarInformacion() {
        cout << "\n--- Informacion del Cliente ---" << endl;
        cout << "Nombre: " << nombre << endl;
        cout << "Correo: " << correo << endl;
        cout << "Direccion: " << direccion << endl;
    }

    // Destructor de la clase base
    virtual ~Cliente() {
        cout << "Destructor de Cliente ejecutado." << endl;
    }
};

// Clase derivada
class ClienteSeguro : public Cliente {
private:
    string tarjetaEncriptada;
    string cvvEncriptado;
    string contrasenaEncriptada;

public:
    ClienteSeguro(string nom, string mail, string dir,
                  string tarjeta, string cvv, string pass)
        : Cliente(nom, mail, dir, tarjeta, cvv, pass) // Llamada al constructor base
    {
        tarjetaEncriptada = encriptar(numeroTarjeta);
        cvvEncriptado = encriptar(cvv);
        contrasenaEncriptada = encriptar(contrasena);
        cout << " Constructor de ClienteSeguro llamado." << endl;
    }
    bool autenticar(string intento) {
        return encriptar(intento) == contrasenaEncriptada;
    }

    void mostrarDatosEncriptados() {
        cout << "\n--- Datos Encriptados ---" << endl;
        cout << "Tarjeta Encriptada: " << tarjetaEncriptada << endl;
        cout << "CVV Encriptado: " << cvvEncriptado << endl;
    }

    // Destructor de la clase derivada
    ~ClienteSeguro() {
        cout << "Destructor de ClienteSeguro ejecutado." << endl;
    }
};

// --- Función principal ---
int main() {
    {
        ClienteSeguro cliente1("Lucia Ramos", "lucia@email.com", "Av. El Sol 789","1111222233334444", "987", "miClaveSegura");
        cliente1.mostrarInformacion();
        cliente1.mostrarDatosEncriptados();
        string intento;
        cout << "\nIngrese su contraseña para autenticar: ";
        cin >> intento;

        if (cliente1.autenticar(intento)) {
            cout << "Autenticacion exitosa. Procesando compra..." << endl;
        } else {
            cout << "Autenticacion fallida. Intente nuevamente." << endl;
        }
    } // Aquí se destruye automáticamente el objeto cliente1 y se invocan los destructores
    return 0;
}
