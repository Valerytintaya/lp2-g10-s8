#include <iostream>
#include <string>
#include <vector>
#include <cmath>
using namespace std;

// Clase base
class FiguraGeometrica {
public:
    virtual double calcularArea()=0;
    virtual double calcularPerimetro()=0;
    virtual void mostrar()=0;
    virtual ~FiguraGeometrica() {}  
};

// Clase derivada: Círculo
class Circulo : public FiguraGeometrica {
private:
    double radio;
public:
    Circulo(double r) : radio(r) {}
    
    double calcularArea() override {
        return M_PI * radio * radio;
    }
    
    double calcularPerimetro() override {
        return M_PI * radio * 2;
    }

    void mostrar() override{
        cout << "Círculo - Radio: " << radio
                  << ", Área: " << calcularArea()
                  << ", Perímetro: " << calcularPerimetro() << "\n";
    }
};

// Clase derivada: Rectángulo
class Rectangulo : public FiguraGeometrica {
private:
    double ancho, alto;
public:
    Rectangulo(double a, double h) : ancho(a), alto(h) {}

    double calcularArea() override {
        return ancho*alto;
    }
    
    double calcularPerimetro() override {
        return 2*(ancho+alto);
    }
    void mostrar() override {
        cout << "Rectangulo - Ancho: " << ancho << ", Alto: " << alto
                  << ", Área: " << calcularArea()
                  << ", Perímetro: " << calcularPerimetro() << "\n";
    }
};

class Triangulo : public FiguraGeometrica {
private:
    double lado1, lado2, lado3;
public:
    Triangulo(double l1, double l2, double l3) : lado1(l1), lado2(l2), lado3(l3) {}

    double calcularArea() override {
        double s = (lado1 + lado2 + lado3) / 2;
        return sqrt(s * (s - lado1) * (s - lado2) * (s - lado3));
    }

    double calcularPerimetro() override {
        return lado1 + lado2 + lado3;
    }

    void mostrar()override {
        cout << "Triangulo - Lados: " << lado1 << ", " << lado2 << ", " << lado3
                  << ", Área: " << calcularArea()
                  << ", Perímetro: " << calcularPerimetro() << "\n";
    }
};

class GestionarFiguras{
    protected:
    vector <FiguraGeometrica*> figuras;
    public:

    void agregarFigura(FiguraGeometrica* nuevo){
        figuras.emplace_back(nuevo);
    }

    void mostrarInfo(){
        int n= figuras.size();
        for (int i=0; i<n;i++){
        figuras[i]->mostrar();
        }
    }
};

int main(){
    GestionarFiguras gestor;

    gestor.agregarFigura(new Circulo(5));
    gestor.agregarFigura(new Rectangulo(4, 6));
    gestor.agregarFigura(new Triangulo(3, 4, 5));

    gestor.mostrarInfo();
    
    cout<<"-----------------------------------------"<<endl;
    // Usamos punteros a la clase base
    FiguraGeometrica* f1 = new Circulo (3.0);
    FiguraGeometrica* f2 = new Rectangulo(4.0, 5.0);;
    FiguraGeometrica* f3 = new Triangulo(3.0, 4.0, 5.0);;

    f1->mostrar();
    f2->mostrar();
    f3->mostrar();

    return 0;
    return 0; 
}