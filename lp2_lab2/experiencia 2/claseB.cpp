#include <iostream>
#include <string>
using namespace std;

class CuentaBancaria {
private:
    float saldo;
    int numeroCuenta;
    int clave;

public:
    string titular;
    string tipoCuenta;
    string tipoMoneda;

    // Constructor con el orden de inicialización (se asign en l orden qeu se crea la variable)
    CuentaBancaria(string _titular, string _tipoCuenta, string _tipoMoneda, float _saldo, int _numeroCuenta, int _clave)
       : saldo(_saldo), numeroCuenta(_numeroCuenta), clave(_clave), titular(_titular), tipoCuenta(_tipoCuenta), tipoMoneda(_tipoMoneda) {}
    

    float getSaldo(){return saldo;};
    int depositar (float monto){
        if (monto<1){
            cout<<"monto invalido..."<<endl;
            return -1;
        }
        else{
            saldo+=monto;
            cout<<"monto depositado..."<<endl;
            return 1;
        }
        
    }

    int retirar (float monto){
        if (monto<1 || monto>saldo){
            cout<<"monto invalido..."<<endl;
            return -1;
        }
        else{
            saldo-=monto;
            cout<<"monto retirado..."<<endl;
            return 1;
        }
    }

    void imprimir(){
        cout << "nombre: "<< titular << " | tipo de cuenta: "<<tipoCuenta << " | tipo de moneda: "<<tipoMoneda<<endl;
        cout << "Saldo: "<< saldo << " | numero de cuenta: "<< numeroCuenta<< " | clave: "<< clave<<endl;

    }
};

int main() {
    CuentaBancaria c("juan", "ahorros", "soles", 100, 12345, 111);
    int validar=-1;

    c.imprimir();

    cout << "============DEPOSITAR==========="<<endl;

    while (validar==-1){
        float depositar;
        cout<< "monto a depositar: ";
        cin>>depositar;
        validar=c.depositar(depositar);
    }

    cout << "============RETIRAR==========="<<endl;
    validar=-1;
    while (validar==-1){
        float retirar;
        cout<< "monto a retirar: ";
        cin>>retirar;
        validar=c.retirar(retirar);
    }
    c.imprimir();
    return 0;

    c.imprimir();
}
