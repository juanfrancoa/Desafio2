#ifndef ISLA_H
#define ISLA_H

#include <iostream>
#include <string>
#include <vector>
#include "surtidor.h" // Asegúrate de incluir el archivo surtidor

class Surtidor;

class Isla {
private:
    std::string nombre; // Nombre de la isla
    std::vector<Surtidor*> surtidores; // Almacena los surtidores de la isla

public:
    // Constructor
    Isla(const std::string& nombre);

    // Métodos
    void agregarSurtidor(Surtidor* surtidor);
    void mostrarSurtidores() const;
    int contarSurtidores();
    bool surtidoresHabilitados();
    const std::vector<Surtidor*>& obtenerSurtidores() const;

};

#endif
