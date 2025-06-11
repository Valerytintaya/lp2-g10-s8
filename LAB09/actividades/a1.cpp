#include <iostream>
using namespace std;
class Animal{
    public:
    virtual void hacerSonido(){
        cout<<"haciendo sonido generico"<<endl;
    }
};
class Perro: public Animal{
    public:
    void hacerSonido() override{
        cout<<"el perro esta ladrando"<<endl;
    }
};

int main(){
    Animal* a1= new Perro();
    a1->hacerSonido();
    return 0;
}
