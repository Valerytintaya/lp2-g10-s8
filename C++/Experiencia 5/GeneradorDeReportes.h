#ifndef GENERADORDEREPORTES_H
#define GENERADORDEREPORTES_H

#include "GestorDeInventario.h"

class GeneradorDeReportes {
private:
    GestorDeInventario* gestor;
    std::vector<Pedido> historialPedidos;

public:
    GeneradorDeReportes(GestorDeInventario* gestor);
    void agregarPedidoAlHistorial(const Pedido& pedido);
    void reporteGeneral() const;
};

#endif
