#include <iostream>
#include <cmath>  
using namespace std;

// Clase base
class FiguraGeometrica {
public:
    virtual double calcularArea()=0;
    virtual double calcularPerimetro()=0;
    virtual ~FiguraGeometrica() {}  // Destructor virtual
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
};

int main(){
    FiguraGeometrica* figuras[3];
    figuras[0]= new Circulo(10);
    figuras[1]= new Rectangulo(2,4);
    figuras[2]= new Triangulo(10,5,8);
    
    for (int i=0; i<3; i++){
        cout<<"area: "<< figuras[i]->calcularArea()<<endl;
    }
    cout<<"--------------------------------"<<endl;
    for (int i=0; i<3; i++){
        cout<<"perimetro: "<< figuras[i]->calcularPerimetro()<<endl;
    }
    
     for (int i=0; i<3; i++){
       delete figuras[i];
    }
    
    return 0; 
}
    
