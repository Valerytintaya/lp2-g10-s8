#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Empresa;
class Usuario {
    private:
        string userId;
        string contrasenia;
        string estadoSesion;
    
    public:
        Usuario(string id = "", string pass = "") : userId(id), contrasenia(pass), estadoSesion("cerrada") {}

        void iniciarSesion() {
            if (estadoSesion == "cerrada") {
                estadoSesion = "Activa";
            } else {
                cout << "Ya estás en sesión." << endl;
            }
        }
        
        void registrarUsuario(const string& id, const string& pass) {
            userId = id;
            contrasenia = pass;
        }
    
        bool verificarUsuario(const string& id) {
            return userId == id;
        }
    
        string getUserId() const { return userId; }
        string getEstadoSesion() const { return estadoSesion; }
};


class UsuarioAdministrador : public Usuario {
    private:
        string nombre;
        string dni;
        
    public:
        UsuarioAdministrador(string n, string d, string id, string pass)
        : Usuario(id, pass), nombre(n), dni(d) {}
    

        void setDatos(const string& nom, const string& d) {
            nombre = nom;
            dni = d;
        }
        
        void actuEmpleado() {
            cout << "Actualizando empleado..." << endl;
        }
        
        void actuEmpresa() {
            cout << "Actualizando empresa..." << endl;
        }
        
        void generarReporteDEtodos() {
            cout << "Generando reporte de todos los empleados..." << endl;
        }
        void generarReporteDnI() {
            cout << "Generando por dni..." << endl;
        }
        void generarSueldoMesDni() {
            cout << "Generando sueldo por mes..." << endl;
        }
};
class AFP {
    private:
        float porcentajeAporte; // 10% de sueldo bruto
        float porcentajeSeguro; // 1.74% de sueldo bruto
        float porcentajeComision; // Variable según AFP
        
    public:
        // Constructor
        AFP(float porcentajeAporte, float porcentajeSeguro, float porcentajeComision)
            : porcentajeAporte(porcentajeAporte), porcentajeSeguro(porcentajeSeguro), porcentajeComision(porcentajeComision) {}
        
            // Método para calcular el descuento total de la AFP sobre el sueldo
        float calcularDescuento(float sueldoBruto) {
            float aporte = sueldoBruto * (porcentajeAporte / 100);
            float seguro = sueldoBruto * (porcentajeSeguro / 100);
            float comision = sueldoBruto * (porcentajeComision / 100);
        
            return aporte + seguro + comision;
        }
        
        // Métodos para obtener los porcentajes de los componentes
        float getPorcentajeAporte() {
            return porcentajeAporte;
        }
        
        float getPorcentajeSeguro() {
            return porcentajeSeguro;
        }
        
        float getPorcentajeComision() {
            return porcentajeComision;
        }
};

class AFPIntegra : public AFP {
    public:
        // Constructor, usa los valores específicos para AFP Integra
        AFPIntegra() : AFP(10.0, 1.74, 1.55) {}
};
    
        
class AFPPrima : public AFP {
    public:
        // Constructor, usa los valores específicos para AFP Prima
        AFPPrima() : AFP(10.0, 1.74, 1.60) {}
};
        
        
class AFPProfuturo : public AFP {
    public:
        // Constructor, usa los valores específicos para AFP Profuturo
        AFPProfuturo() : AFP(10.0, 1.74, 1.69) {}
    
};

class UsuarioEmpleado : public Usuario {
    private:
        string nombre;
        string dni;
        string celular;
        double sueldoBruto;
        int numHijos;
        AFP* afp;
        Empresa* empresa;
        static const int asignacionFamiliar = 113;
    
    public:
           
        UsuarioEmpleado(string nombre, string dni, string celular, float sueldoBruto, int nroHijos, AFP* afp, Empresa* m, string id, string pass)
        : Usuario(id, pass), nombre(nombre), dni(dni), celular(celular), sueldoBruto(sueldoBruto), numHijos(nroHijos), afp(afp), empresa(m) {}
    
        void setDatos(string& nom, string& d, string& cel) {
            nombre = nom;
            dni = d;
            celular = cel;
        }
    
        void setAFP(AFP* a) { afp = a; }
        void setSueldo(double sueldo) { sueldoBruto = sueldo; }
        void setNumHijos(int hijos) { numHijos = hijos; }
    
        double calcularDescuento() {
            if (afp) return afp->calcularDescuento(sueldoBruto);
            return 0;
        }
    
        double calcularSueldoNeto() {
            double descuento = calcularDescuento();
            double asignacion = numHijos > 0 ? asignacionFamiliar : 0;
            return sueldoBruto - descuento + asignacion;
        }
    
        void actualizarDatos(string nuevoNombre, string nuevoDni, string nuevaCelular) {
            nombre = nuevoNombre;
            dni = nuevoDni;
            celular = nuevaCelular;
            cout << "Datos de la empresa actualizados correctamente." << endl;
        }
    
       // Método para mostrar los datos del empleado
        void mostrarDatos();
        string getDni() const { return dni; }
        double getSueldo() const { return sueldoBruto; }
};

class Gerente : public UsuarioEmpleado {
    private:
        string area;
    public:
        // Constructor
        Gerente(string nombre, string dni, string celular, float sueldoBruto, int nroHijos, AFP* a,Empresa* m, string area = "")
            : UsuarioEmpleado(nombre, dni, celular, sueldoBruto, nroHijos, a,m, "Gerente", "pass123"), area(area) {}

        void mostrarDatos() {
            UsuarioEmpleado::mostrarDatos();
            cout << "Tipo de Empleado: Gerente" << endl;
        }

        // Sobrescribe calcular sueldo neto si es necesario
        double calcularSueldoNeto() {
            return UsuarioEmpleado::calcularSueldoNeto(); // Por defecto, se calcula igual que el Empleado
        }
};

class Operario : public UsuarioEmpleado {
    public:
        // Constructor
        Operario(string nombre, string dni, string celular, float sueldoBruto, int nroHijos, AFP* a,Empresa* m)
        : UsuarioEmpleado(nombre, dni, celular, sueldoBruto, nroHijos, a,m, "Operario", "clave321") {}

        void mostrarDatos() {
            UsuarioEmpleado::mostrarDatos();
            cout << "Tipo de Empleado: Operario" << endl;
        }

        // Sobrescribe calcular sueldo neto si es necesario
        double calcularSueldoNeto() {
            return UsuarioEmpleado::calcularSueldoNeto(); // Por defecto, se calcula igual que el Empleado
        }
};
const int maxi=10;
class Empresa {
    private:
        string nombre;
        string ruc;
        string direccion;
        UsuarioEmpleado* empleados[maxi];
        int n;    
    public:
        // Constructor
        Empresa(string nombre, string ruc, string direccion)
            : nombre(nombre), ruc(ruc), direccion(direccion), n(0) {}
    
        // Método para actualizar los datos de la empresa
        void actualizarDatos(string nuevoNombre, string nuevoRuc, string nuevaDireccion) {
            nombre = nuevoNombre;
            ruc = nuevoRuc;
            direccion = nuevaDireccion;
            cout << "Datos de la empresa actualizados correctamente." << endl;
        }
    
        // Método para mostrar los datos de la empresa
        void mostrarDatos() {
            cout << "Nombre de la Empresa: " << nombre << endl;
            cout << "RUC: " << ruc << endl;
            cout << "Direccion: " << direccion << endl;
        }

        void agregarEmpleado(UsuarioEmpleado* nuevo){
            empleados[n++]= nuevo;
            cout<<"empleado agregado a al empresa..."<<endl;
        }

        void buscarPordni(){
            cout<<"se encontro empleado..."<<endl;
        }

        string getNombre(){return nombre;}
};

class Boleta {
    UsuarioEmpleado* empleado;
    float sueldoNeto;
    float descuentos;
    int inasistencias;
public:
    Boleta(UsuarioEmpleado* e, int faltas) : empleado(e), inasistencias(faltas) {}

    void generarBoleta() {
        cout<< "se genera boleta..."<<endl;
        descuentos = empleado->calcularDescuento();
        sueldoNeto = empleado->calcularSueldoNeto() - (inasistencias * 20);
    }

    void mostrar() {
        cout << "===== BOLETA =====\n";
        empleado->mostrarDatos();
        cout << "Inasistencias: " << inasistencias << endl;
        cout << "Descuentos: S/" << descuentos << endl;
        cout << "Sueldo Neto: S/" << sueldoNeto << endl;
    }
};

void UsuarioEmpleado::  mostrarDatos  (){
    cout << "Nombre: " << nombre << endl;
    cout << "DNI: " << dni << endl;
    cout << "Celular: " << celular << endl;
    cout << "Sueldo Bruto: " << sueldoBruto << endl;
    cout << "Numero de Hijos: " << numHijos << endl;
    cout << "empresa: " << empresa->getNombre() << endl;
}


int main() {
    // Crear la empresa
    Empresa miEmpresa("MiEmpresa S.A.C.", "20123456789", "Av. Viva 742");
    miEmpresa.mostrarDatos();
    miEmpresa.actualizarDatos("NuevaEmpresa S.A.C.", "20987654321", "Calle Nueva 123");
    miEmpresa.mostrarDatos();

    // Crear administrador
    UsuarioAdministrador admin("Carlos Perez", "12345678", "admin01", "admin123");
    admin.iniciarSesion();
    cout << "Estado de la sesion del administrador: " << admin.getEstadoSesion() << endl;
    admin.actuEmpleado();
    admin.actuEmpresa();
    admin.generarReporteDEtodos();

    // Crear AFPs
    AFPIntegra afpIntegra;
    AFPPrima afpPrima;
    AFPProfuturo afpProfuturo;

    // Crear un gerente y operario y asignarles los datos
    Gerente gerente("Luis Soto", "87654321", "987654321", 5000, 2, &afpIntegra, &miEmpresa);
    gerente.iniciarSesion();  // Inicia sesión
    cout << "\nDatos del Gerente:" << endl;
    gerente.mostrarDatos();  // Muestra los datos del gerente

    // Modificar los datos del gerente
    gerente.actualizarDatos("Ana Lopez", "000123", "000000");
    gerente.mostrarDatos();  // Muestra los datos modificados del gerente

    // Mostrar el sueldo neto del gerente
    cout << "Sueldo Neto Gerente: " << gerente.calcularSueldoNeto() << endl;

    // Crear un operario y asignarles los datos
    Operario operario("Ana Torres", "11223344", "999888777", 2500, 0, &afpPrima, &miEmpresa);
    operario.iniciarSesion();  // Inicia sesión
    cout << "\nDatos del Operario:" << endl;
    operario.mostrarDatos();  // Muestra los datos del operario

    // Modificar los datos del operario
    operario.actualizarDatos("Carlos Torres", "12345678", "123456789");
    operario.mostrarDatos();  // Muestra los datos modificados del operario

    // Mostrar el sueldo neto del operario
    cout << "Sueldo Neto Operario: " << operario.calcularSueldoNeto() << endl;

    // Crear boletas de pago para Gerente y Operario
    Boleta boletaGerente(&gerente, 1); // Gerente con 1 inasistencia
    boletaGerente.generarBoleta();
    boletaGerente.mostrar();

    Boleta boletaOperario(&operario, 3); // Operario con 3 inasistencias
    boletaOperario.generarBoleta();
    boletaOperario.mostrar();
    return 0;
}


    


        
    