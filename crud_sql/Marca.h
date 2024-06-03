#pragma once
#include <string>

class Marca {
public:
    int idMarca;
    std::string marca;

    Marca(int id, std::string mar)
        : idMarca(id), marca(mar) {}
};


