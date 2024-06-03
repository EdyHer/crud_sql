#pragma once
#include <string>

class Cliente {
public:
    int idCliente;
    std::string nombres;
    std::string apellidos;
    std::string NIT;
    bool genero;
    std::string telefono;
    std::string correo_electronico;
    std::string fechaingreso;

    Cliente(int id, std::string nom, std::string ape, std::string nit, bool gen, std::string tel, std::string correo, std::string fecha)
        : idCliente(id), nombres(nom), apellidos(ape), NIT(nit), genero(gen), telefono(tel), correo_electronico(correo), fechaingreso(fecha) {}
};



