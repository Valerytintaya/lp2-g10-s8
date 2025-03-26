#include <iostream>
#include <string>
using namespace std;
class Animales
{
    private: 
        string nombre, tipo_especie, habitat, tipo_alimentacion;
        int edad;
        float peso;
    public:

        Animales(string _nombre="ND", string _tipo_especie="ND", string _habitad ="ND",string _tipo_alimentacion="ND",int _edad=0, float _peso=0.0){
            nombre=_nombre;
            tipo_especie= _tipo_especie;
            habitat= _habitad;
            tipo_alimentacion= _tipo_alimentacion;
            edad= _edad;
            peso= _peso;
        }
        

        string getNombre(){return nombre;};
        string getAlimentacion(){ return tipo_alimentacion;};

        //metodo virtual  (polimorfismo)

        virtual void hacer_sonido() {cout<<" ";}; // si no se añade una implementacion ; =0
        virtual void alimentar() { cout<<" ";};

        virtual ~Animales(){
        cout <<"animales destruido"<<endl;
        };
};

class Perro: public Animales{
    private:
        string raza;
    public:
        Perro(string _nombre, string _tipo_especie, string _habitad,string _tipo_alimentacion,int _edad, float _peso, string _raza) : Animales(_nombre, _tipo_especie, _habitad ,_tipo_alimentacion,_edad,_peso), raza(_raza){}
        
        void hacer_sonido ()override{
            cout<<"el perro: "<< getNombre() << "  | sonido:  LADRA "<<endl;
        }

        void alimentar()override{
            cout<<"el perro: "<< getNombre()<< " | se esta alimentado con : "<< getAlimentacion()<<endl;
        }
};

class Caballo: public Animales{
    private:
        string raza;
    public:
        Caballo(string _nombre, string _tipo_especie, string _habitad,string _tipo_alimentacion,int _edad, float _peso, string _raza) : Animales(_nombre, _tipo_especie, _habitad ,_tipo_alimentacion,_edad,_peso), raza(_raza){}
        
        void hacer_sonido()override{
            cout<<"el caballo: "<< getNombre() << " | sonido:  RELINCHA "<<endl;
        }

        void alimentar()override{
            cout<<"el caballo: "<< getNombre()<< " | se esta alimentado con : "<< getAlimentacion()<<endl;
        }
};

class Gato: public Animales{
    private:
        string raza;
    public:
        Gato(string _nombre, string _tipo_especie, string _habitad,string _tipo_alimentacion,int _edad, float _peso, string _raza) : Animales(_nombre, _tipo_especie, _habitad ,_tipo_alimentacion,_edad,_peso), raza(_raza){}
        
        void hacer_sonido()override{
            cout<<"el gato: "<< getNombre() << " | sonido:  MAULLA "<<endl;
        }

        void alimentar()override{
            cout<<"el gato: "<< getNombre()<< " | se esta alimentado con : "<< getAlimentacion()<<endl;
        }
};


int main(){

    Animales* animales[3];  // Arreglo de punteros a Animales

    animales[0] = new Perro("Max", "Canino", "Casa", "Croquetas", 5, 12.5, "Labrador");
    animales[1] = new Caballo("Relampago", "Equino", "Campo", "Pasto", 7, 350.0, "Pura Sangre");
    animales[2] = new Gato("Michi", "Felino", "Departamento", "Pescado", 3, 4.2, "Siames");
    
    for (int i = 0; i < 3; i++) {
        animales[i]->hacer_sonido();
        animales[i]->alimentar();
        cout << endl;
    }
    
        // Liberar memoria
    for (int i = 0; i < 3; i++) {
        delete animales[i];
    }
    
    return 0;
}