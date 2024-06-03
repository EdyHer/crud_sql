#pragma once
#include <string>

class Puesto {
public:
    int idPuesto;
    std::string puesto;

    Puesto(int id, std::string pue)
        : idPuesto(id), puesto(pue) {}
};


