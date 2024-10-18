#ifndef SURTIDOR_H
#define SURTIDOR_H

#include "tanque.h"
#include <string>

class Tanque;

class Surtidor{
private:

    unsigned long id;
    std::string modelo;
    std::string tipoCombustible;

    bool habilitado;

    static unsigned long idCounter;

public:
    // Constructor
    Tanque* tanque; // Puntero al tanque asociado

    Surtidor(std::string tipoCombustible, std::string modelo, Tanque* t);


    // Método para vender combustible
    void venderCombustible(double precio, int estacionId);

    // Métodos para habilitar/deshabilitar el surtidor
    void habilitarSurtidor();
    void deshabilitarSurtidor();

    // Mostrar el estado del surtidor
    void mostrarEstadoSurtidor();

    bool getHabilitado();

};

#endif
