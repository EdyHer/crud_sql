#pragma once
#include <string>

class Compra {
public:
    int idCompra;
    int no_orden_compra;
    int idproveedor;
    std::string fecha_orden;
    std::string fechaingreso;

    Compra(int id, int orden, int proveedor, std::string fechaOrden, std::string fechaIngreso)
        : idCompra(id), no_orden_compra(orden), idproveedor(proveedor), fecha_orden(fechaOrden), fechaingreso(fechaIngreso) {}
};


