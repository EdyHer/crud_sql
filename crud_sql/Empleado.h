#pragma once
#include <string>

class Empleado {
public:
    int idEmpleado;
    std::string nombres;
    std::string apellidos;
    std::string direccion;
    std::string telefono;
    std::string DPI;
    bool genero;
    std::string fecha_nacimiento;
    int idPuesto;
    std::string fecha_inicio_labores;
    std::string fechaingreso;

    Empleado(int id, std::string nom, std::string ape, std::string dir, std::string tel, std::string dpi, bool gen, std::string fechaNac, int puesto, std::string fechaInicio, std::string fechaIngreso)
        : idEmpleado(id), nombres(nom), apellidos(ape), direccion(dir), telefono(tel), DPI(dpi), genero(gen), fecha_nacimiento(fechaNac), idPuesto(puesto), fecha_inicio_labores(fechaInicio), fechaingreso(fechaIngreso) {}
};


