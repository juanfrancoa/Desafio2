#ifndef ESTACIONSERVICIO_H
#define ESTACIONSERVICIO_H

#include <string>
#include "tanque.h"

class Tanque;

class EstacionServicio
{
private:
    unsigned int id;
    std::string nombre;
    std::string gerente;
    char region;
    double latitud;
    double longitud;

    static unsigned long int idCounter;

public:
    Tanque *tanque;
    EstacionServicio(const std::string& nombre, const std::string& gerente, char region, double latitud, double longitud, Tanque * t);

    // Métodos
    void mostrarDatos() const;
    bool esRegionValida(char region) const;

    // Getters
    unsigned int getId() const;
    std::string getNombre() const;
    std::string getGerente() const;
    char getRegion() const;
    double getLatitud() const;
    double getLongitud() const;
    Tanque* getTanque() const;  // Agregado


};

#endif // ESTACIONSERVICIO_H
