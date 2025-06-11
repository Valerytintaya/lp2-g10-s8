#include <iostream>
#include <cmath>  // Para M_PI

using namespace std;

// Clase base
class Figura {
public:
    virtual double calcularArea() const { 
        return 0.0; 
    }
    virtual ~Figura() {}  // Destructor virtual por buenas prácticas
};

// Clase derivada: Círculo
class Circulo : public Figura {
private:
    double radio;
public:
    Circulo(double r) : radio(r) {}
    
    double calcularArea() const override {
        return M_PI * radio * radio;
    }
};

// Clase derivada: Rectángulo
class Rectangulo : public Figura {
private:
    double ancho, alto;
public:
    Rectangulo(double a, double h) : ancho(a), alto(h) {}

    double calcularArea() const override {
        return ancho * alto;
    }
};

// Clase derivada: Triángulo
class Triangulo : public Figura {
private:
    double base, altura;
public:
    Triangulo(double b, double h) : base(b), altura(h) {}

    double calcularArea() const override {
        return (base * altura) / 2.0;
    }
};

int main(){
    Figura* figuras[3];
    figuras[0]= new Circulo(10);
    figuras[1]= new Rectangulo(2,4);
    figuras[2]= new Triangulo(10,5);
    
    for (int i=0; i<3; i++){
        cout<<"area: "<< figuras[i]->calcularArea()<<endl;
    }
    
     for (int i=0; i<3; i++){
       delete figuras[i];
    }
     
}
