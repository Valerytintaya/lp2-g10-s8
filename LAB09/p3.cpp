#include <iostream>
using namespace std;

// Clase base abstracta
class Empleado {
public:
    virtual double calcularSalario() = 0;
    virtual void mostrarInformacion() = 0;
    virtual ~Empleado() {}
};

// Empleado asalariado
class Asalariado : public Empleado {
private:
    double salarioMensual;
public:
    Asalariado(double salario) : salarioMensual(salario) {}

    double calcularSalario() override {
        return salarioMensual;
    }

    void mostrarInformacion() override {
        cout << "Empleado Asalariado - Salario mensual: S/ " << calcularSalario() << endl;
    }
};

// Empleado por hora
class PorHora : public Empleado {
private:
    double tarifaHora;
    int horasTrabajadas;
public:
    PorHora(double tarifa, int horas) : tarifaHora(tarifa), horasTrabajadas(horas) {}

    double calcularSalario() override {
        return tarifaHora * horasTrabajadas;
    }

    void mostrarInformacion() override {
        cout << "Empleado por Hora - Tarifa: S/ " << tarifaHora
             << ", Horas trabajadas: " << horasTrabajadas
             << ", Salario: S/ " << calcularSalario() << endl;
    }
};

// Empleado comisionista
class Comisionista : public Empleado {
private:
    double salarioBase;
    double ventas;
    double porcentajeComision;
public:
    Comisionista(double base, double ventasRealizadas, double porcentaje)
        : salarioBase(base), ventas(ventasRealizadas), porcentajeComision(porcentaje) {}

    double calcularSalario() override {
        return salarioBase + (ventas * porcentajeComision / 100.0);
    }

    void mostrarInformacion() override {
        cout << "Empleado Comisionista - Base: S/ " << salarioBase
             << ", Ventas: S/ " << ventas
             << ", Comisión: " << porcentajeComision << "%"
             << ", Salario total: S/ " << calcularSalario() << endl;
    }
};

int main() {
    Empleado* empleados[3];
    empleados[0]= new Asalariado (3000);
    empleados[1]= new Comisionista (1200, 5000, 10);
    empleados[2]= new PorHora(25, 160);

    for (int i = 0; i < 3; i++) {
        empleados[i]->mostrarInformacion();
        cout << endl;
    }

    return 0;
}
