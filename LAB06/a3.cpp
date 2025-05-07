#include <iostream>
#include <vector>
using namespace std;

class Banco {
private:
    static float tasaInteres; 

public:
    static float getTasaInteres() {
        return tasaInteres;
    }
    static void setTasaInteres(float nuevaTasa) {
        tasaInteres = nuevaTasa;
    }
};

float Banco::tasaInteres = 0.05f; // 5% de tasa de interés

class CuentaBancaria {
    private:
        float saldo; 
    public:
        CuentaBancaria(float saldoInicial) : saldo(saldoInicial) {}

        float getSaldo() const {
            return saldo;
        }

        void depositar(float monto) {
            if (monto > 0) {
                saldo += monto;
                cout << "Deposito exitoso: " << monto << endl;
            } else {
                cout << "Monto de depósito invalido." << endl;
            }
        }
        void retirar(float monto) {
            if (monto > 0 && monto <= saldo) {
                saldo -= monto;
                cout << "Retiro exitoso: " << monto << endl;
            } else {
                cout << "Saldo insuficiente o monto invalido." << endl;
            }
        }
        // Método para calcular el interés ganado usando la tasa de interés estática del banco
        float calcularInteres() const {
            return saldo * Banco::getTasaInteres();
        }
};

int main() {
    CuentaBancaria cuenta1(1000.0f);
    cout << "Saldo inicial: " << cuenta1.getSaldo() << endl;
    cuenta1.depositar(500.0f);
    cuenta1.retirar(200.0f);
    cout << "Saldo despues de operaciones: " << cuenta1.getSaldo() << endl;
    cout << "Interes ganado: " << cuenta1.calcularInteres() << endl;
    Banco::setTasaInteres(0.07f); 
    cout << "Nuevo interes ganado con tasa de 7%: " << cuenta1.calcularInteres() << endl;
    return 0;
}
    