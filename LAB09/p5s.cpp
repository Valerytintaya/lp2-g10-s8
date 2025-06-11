#include <iostream>
using namespace std;

// Clase base abstracta
class Producto {
protected:
    string nombre;
    double precioUnitario;
    int cantidad;

public:
    Producto(const string& _nombre = "", double _precioUnitario = 0.0, int _cantidad = 0)
        : nombre(_nombre), precioUnitario(_precioUnitario), cantidad(_cantidad) {}

    virtual ~Producto() {}

    virtual double calcularValorInventario() const = 0;
    virtual void aplicarDescuento(double descuento) = 0;

    virtual void mostrar() const {
        cout << "Nombre: " << nombre
             << ", Precio Unitario: " << precioUnitario
             << ", Cantidad: " << cantidad;
    }
};

// Electrónicos
class ProductoElectronico : public Producto {
public:
    ProductoElectronico(const string& _nombre, double _precioUnitario, int _cantidad)
        : Producto(_nombre, _precioUnitario, _cantidad) {}

    double calcularValorInventario() const override {
        return precioUnitario * cantidad;
    }

    void aplicarDescuento(double descuento) override {
        precioUnitario -= precioUnitario * descuento;
    }
};

// Ropa
class ProductoRopa : public Producto {
public:
    ProductoRopa(const string& _nombre, double _precioUnitario, int _cantidad)
        : Producto(_nombre, _precioUnitario, _cantidad) {}

    double calcularValorInventario() const override {
        return precioUnitario * cantidad;
    }

    void aplicarDescuento(double descuento) override {
        precioUnitario -= precioUnitario * descuento;
    }
};

// Alimentos
class ProductoAlimento : public Producto {
public:
    ProductoAlimento(const string& _nombre, double _precioUnitario, int _cantidad)
        : Producto(_nombre, _precioUnitario, _cantidad) {}

    double calcularValorInventario() const override {
        return precioUnitario * cantidad;
    }

    void aplicarDescuento(double descuento) override {
        precioUnitario -= precioUnitario * descuento;
    }
};

int main() {
    Producto* inventario[4];
    int totalProductos = 0;

    inventario[totalProductos++] = new ProductoElectronico("Laptop", 1200.0, 5);
    inventario[totalProductos++] = new ProductoRopa("Camisa", 50.0, 20);
    inventario[totalProductos++] = new ProductoAlimento("Manzana", 1.5, 100);

    // Calcular valor total
    double valorTotal = 0;
    for (int i = 0; i < totalProductos; i++) {
        valorTotal += inventario[i]->calcularValorInventario();
    }

    cout << "\nValor total del inventario (sd): $" << valorTotal << endl;

    cout<<"---------------------------------------------------"<<endl;

    for (int i = 0; i < totalProductos; i++) {
       inventario[i]->aplicarDescuento(0.20);
    }

    // Mostrar productos actualizados
    double Total = 0;
    cout << "\nInventario con descuento aplicado:\n";
    for (int i = 0; i < totalProductos; i++) {
        inventario[i]->mostrar();
        cout << ", Valor actual: $" << inventario[i]->calcularValorInventario() << endl;
        Total += inventario[i]->calcularValorInventario();
    }

    cout << "\nValor total del inventario: $" << Total << endl;

    // Liberar memoria
    for (int i = 0; i < totalProductos; i++) {
        delete inventario[i];
    }

    return 0;
}


