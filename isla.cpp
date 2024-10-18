#include "isla.h"

// Constructor
Isla::Isla(const std::string& nombre) : nombre(nombre) {}

// Método para agregar un surtidor
void Isla::agregarSurtidor(Surtidor* surtidor) {
    surtidores.push_back(surtidor); // Agrega el surtidor al vector
}

// Método para mostrar los surtidores de la isla
void Isla::mostrarSurtidores() const {
    std::cout << "Surtidores en la isla " << nombre << ":\n";
    for (const auto& surtidor : surtidores) {
        surtidor->mostrarEstadoSurtidor(); // Muestra el estado de cada surtidor
    }
}

int Isla::contarSurtidores(){
    int i = 0;
    for (const auto& surtidor : surtidores) {
        i++;
    }
    return i;
}

bool Isla::surtidoresHabilitados(){
    bool surtidoresHabilitados = false;
    for (const auto& surtidor : surtidores) {
        if(surtidor->getHabilitado()){
            surtidoresHabilitados = true;
        }
    }
    return surtidoresHabilitados;
}

const std::vector<Surtidor*>& Isla::obtenerSurtidores() const {
    return surtidores;
}
