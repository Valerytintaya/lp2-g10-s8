#include <iostream>
#include <string>
using namespace std;

class CuentaBancaria {
private:
    string numero, titular;
    double saldo;

public:

    CuentaBancaria(string n, string t, double s): numero(n), titular(t), saldo(s) {}

    CuentaBancaria& Depositar(double deposito) {
        if (deposito <= 0) {
            cout << "El monto del deposito no es valido" << endl;
            return *this; 
        }
        saldo += deposito;
        cout << "Depósito hecho." << endl;
        return *this; 
    }

    
    CuentaBancaria& Retirar(double retiro) {
        if (retiro > saldo) {
            cout << "Saldo insuficiente para retiro." << endl;
            return *this; // Devolvemos la referencia 
        }
        saldo -= retiro;
        cout << "Retiro hecho." << endl;
        return *this; //encadenar
    }

    void mostrarSaldo() const {
        cout << "Titular: " << titular << " | Saldo: " << saldo << endl;
    }
};

int main() {
    CuentaBancaria cuenta1("12345", "Rosa Perez", 100.00);

    // Encadenamos métodos
    cuenta1.Depositar(50).Retirar(120).mostrarSaldo();  
    cuenta1.Depositar(-30).Retirar(50).mostrarSaldo();  
}
