#ifndef TANQUE_H
#define TANQUE_H

#include <iostream>    // Necesario para std::cout
#include <string>      // Necesario para std::string
#include <vector>    // Para usar std::vector
#include <ctime>
#include <vector>
#include "isla.h" // Asegúrate de incluir el archivo isla
#include "surtidor.h"

class Isla;  // Declaración adelantada para evitar dependencias circulares
class Surtidor;

class Tanque {

private:

    double capacidad_regular;
    double capacidad_premium;
    double capacidad_ecoextra;
    double nivel_actual_regular;
    double nivel_actual_premium;
    double nivel_actual_ecoextra;
    std::vector<Isla*> islas; // Almacena las islas asociadas al tanque


public:
    // Constructor por defecto
    Tanque();


    // Métodos
    void mostrarDatosTanque();
    int venta(std::string tipo, int cantidad);

    int mostrarSurtidores();
    bool surtidoresHabilitados();

    // Métodos para agregar islas y mostrar islas
    void agregarIsla(Isla* isla);
    void mostrarIslas() const;


    Surtidor* obtenerSurtidorAleatorio() const;

};

#endif
