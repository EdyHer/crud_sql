#pragma once
#include <string>

class Producto {
public:
    int idProducto;
    std::string producto;
    int idMarca;
    std::string descripcion;
    std::string imagen;
    double precio_costo;
    double precio_venta;
    int existencia;
    std::string fecha_ingreso;

    Producto(int id, std::string prod, int marca, std::string desc, std::string img, double costo, double venta, int exist, std::string fecha)
        : idProducto(id), producto(prod), idMarca(marca), descripcion(desc), imagen(img), precio_costo(costo), precio_venta(venta), existencia(exist), fecha_ingreso(fecha) {}
};


