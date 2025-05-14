#include <iostream>
#include <string>
#include <algorithm> // (simulación de encriptado)
using namespace std;

// Clase base
class Cliente {
protected:
    string nombre;
    string correo;
    string direccion;
    string numeroTarjeta; // Información financiera (simulada)
    string cvv;
    string contrasena;

public:
    Cliente(string nom, string mail, string dir, string tarjeta, string cvv, string pass)
        : nombre(nom), correo(mail), direccion(dir),
          numeroTarjeta(tarjeta), cvv(cvv), contrasena(pass) {}

    void mostrarInformacion() {
        cout << "Nombre: " << nombre << endl;
        cout << "Correo: " << correo << endl;
        cout << "Direccion: " << direccion << endl;
    }
};

// Clase derivada
class ClienteSeguro : public Cliente {
private:
    string tarjetaEncriptada;
    string cvvEncriptado;
    string hashContrasena;
    string encriptarDato(string dato) {
        reverse(dato.begin(), dato.end());
        return dato;
    }

public:
    ClienteSeguro(string nom, string mail, string dir, string tarjeta, string cvv, string pass)
        : Cliente(nom, mail, dir, tarjeta, cvv, pass) {
        // Encriptamos la información sensible al crear el objeto
        tarjetaEncriptada = encriptarDato(numeroTarjeta);
        cvvEncriptado = encriptarDato(cvv);
        hashContrasena = encriptarDato(contrasena);
    }

    // Método para verificar autenticidad del cliente (contrasena)
    bool autenticar(string inputPass) {
        return encriptarDato(inputPass) == hashContrasena;
    }

    void mostrarDatosEncriptados() {
        cout << "Tarjeta Encriptada: " << tarjetaEncriptada << endl;
        cout << "CVV Encriptado: " << cvvEncriptado << endl;
    }
};

int main() {
    ClienteSeguro cliente1("Ana Lopez", "ana@email.com", "Av. Lima 123",
                           "1234567890123456", "123", "segura123");

    cliente1.mostrarInformacion();
    cliente1.mostrarDatosEncriptados();

    string intento;
    cout << "\nIngrese su contraseña para autenticar: ";
    cin >> intento;

    if (cliente1.autenticar(intento)) {
        cout << "Autenticacion exitosa. Procesando pago..." << endl;
    } else {
        cout << "Autenticacion fallida. Acceso denegado." << endl;
    }

    return 0;
}
