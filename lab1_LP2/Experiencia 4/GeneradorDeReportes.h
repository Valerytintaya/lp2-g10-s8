#ifndef GENERADOR_DE_REPORTES_H
#define GENERADOR_DE_REPORTES_H

#include "GestorDeInventario.h"
#include "Pedido.h"
#include <vector>

class GeneradorDeReportes {
private:
    GestorDeInventario* inventario;
    vector<Pedido> historialPedidos;

public:
    GeneradorDeReportes(GestorDeInventario* inv);

    void agregarPedidoAlHistorial(Pedido pedido);
    void reporteVentas();
    void reporteInventarioBajo(int umbral);
    void reporteGeneral();
};

#endif
