#pragma once
#include <string>

class Venta {
public:
    int idVenta;
    int nofactura;
    char serie;
    std::string fechafactura;
    int idCliente;
    int idEmpleado;
    std::string fechaingreso;

    Venta(int id, int factura, char ser, std::string fechaFac, int cliente, int empleado, std::string fechaIng)
        : idVenta(id), nofactura(factura), serie(ser), fechafactura(fechaFac), idCliente(cliente), idEmpleado(empleado), fechaingreso(fechaIng) {}
};


