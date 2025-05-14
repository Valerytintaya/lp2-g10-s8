#include <iostream>
#include <string>
#include <algorithm> // reverse
using namespace std;

// Clase base
class Cliente {
protected:
    string nombre;
    string correo;
    string direccion;
    string numeroTarjeta;
    string cvv;
    string contrasena;
    // Método protegido para encriptar datos (simulación)
    string encriptar(string dato) {
        reverse(dato.begin(), dato.end());
        return dato;
    }

public:
    Cliente(string nom, string mail, string dir, string tarjeta, string cvv, string pass)
        : nombre(nom), correo(mail), direccion(dir),
          numeroTarjeta(tarjeta), cvv(cvv), contrasena(pass) {}

    void mostrarInformacion() {
        cout << "Nombre: " << nombre << endl;
        cout << "Correo: " << correo << endl;
        cout << "Dirección: " << direccion << endl;
    }
};

// Clase derivada
class ClienteSeguro : public Cliente {
private:
    string tarjetaEncriptada;
    string cvvEncriptado;
    string contrasenaEncriptada;

public:
    ClienteSeguro(string nom, string mail, string dir, string tarjeta, string cvv, string pass)
        : Cliente(nom, mail, dir, tarjeta, cvv, pass) {
        // Usamos el método protegido de la clase base
        tarjetaEncriptada = encriptar(numeroTarjeta);
        cvvEncriptado = encriptar(cvv);
        contrasenaEncriptada = encriptar(contrasena);
    }

    bool autenticar(string intento) {
        return encriptar(intento) == contrasenaEncriptada;
    }

    void mostrarDatosEncriptados() {
        cout << "Tarjeta Encriptada: " << tarjetaEncriptada << endl;
        cout << "CVV Encriptado: " << cvvEncriptado << endl;
    }
};

int main() {
    ClienteSeguro cliente1("Luis García", "luis@email.com", "Calle 456",
                           "9876543210987654", "321", "claveSegura");

    cliente1.mostrarInformacion();
    cliente1.mostrarDatosEncriptados();

    string intento;
    cout << "\nIngrese su contraseña para autenticar: ";
    cin >> intento;

    if (cliente1.autenticar(intento)) {
        cout << "Autenticación exitosa. Procesando compra..." << endl;
    } else {
        cout << "Autenticación fallida. Intente nuevamente." << endl;
    }

    return 0;
}
