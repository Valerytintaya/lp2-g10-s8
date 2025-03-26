#include "Carro.cpp"

int main() {
    Carro miCarro(16);

    miCarro.mover();
    miCarro.inflarRuedas();
    miCarro.cambiarRueda(2, 18); // Intento de cambiar rueda en movimiento

    miCarro.detener();
    miCarro.cambiarRueda(2, 18); // Cambio exitoso

    return 0;
}
