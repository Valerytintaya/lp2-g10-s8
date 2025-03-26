#include <iostream>
#include <string>
using namespace std;

class Factura {
private:
    string codigo;
    string cliente;
    float montoTotal;

public:
    string fecha;
    string metodoPago;

    // Constructor
    Factura(string _codigo, string _cliente, float _montoTotal, string _fecha, string _metodoPago)
        : codigo(_codigo), cliente(_cliente), montoTotal(_montoTotal), fecha(_fecha), metodoPago(_metodoPago) {}

    // Getters
    string getCodigo() const { return codigo; }
    string getCliente() const { return cliente; }
    float getMontoTotal() const { return montoTotal; }

    // Setters
    void setCodigo(string _codigo) { codigo = _codigo; }
    void setCliente(string _cliente) { cliente = _cliente; }
    void setMontoTotal(float _montoTotal) { montoTotal = _montoTotal; }

    // Método para mostrar la factura se peude usar "const" permite no modificar los atributosd entro de sat calse accid,
    void mostrarFactura()  {
        cout << "Factura Codigo: " << codigo << endl;
        cout << "Cliente: " << cliente << endl;
        cout << "Monto Total: $" << montoTotal << endl;
        cout << "Fecha: " << fecha << endl;
        cout << "Metodo de Pago: " << metodoPago << endl;
        cout << "-----------------------------" << endl;
    }
};

int main() {
    // Instanciando varias facturas
    Factura factura1("F001", "Juan Perez", 150.75, "20/03/2025", "Tarjeta de credito");
    Factura factura2("F002", "Ana Gomez", 89.99, "21/03/2025", "Efectivo");

    // Mostrando información de las facturas
    factura1.mostrarFactura();
    factura2.mostrarFactura();

    // Modificando datos con los setters
    factura1.setMontoTotal(160.50);
    factura1.metodoPago = "Transferencia bancaria";

    // Verificando cambios
    cout << "Actualizacion de Factura 1:" << endl;
    factura1.mostrarFactura();

    return 0;
}
