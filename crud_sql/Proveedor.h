#pragma once
#include <string>

class Proveedor {
public:
    int idProveedor;
    std::string proveedor;
    std::string nit;
    std::string direccion;
    std::string telefono;

    Proveedor(int id, std::string prov, std::string n, std::string dir, std::string tel)
        : idProveedor(id), proveedor(prov), nit(n), direccion(dir), telefono(tel) {}
};


