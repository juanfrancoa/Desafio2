#include "estacionservicio.h"
#include "iostream"
#include "tanque.h"

// Inicialización del contador estático
unsigned long EstacionServicio::idCounter = 0;
class tanque;

// Constructor
EstacionServicio::EstacionServicio(const std::string& nombre, const std::string& gerente, char region, double latitud, double longitud, Tanque *t)
    : nombre(nombre), gerente(gerente), region(region), latitud(latitud), longitud(longitud), tanque(t) {
    id = ++idCounter;
}

// Mostrar datos de la estación
void EstacionServicio::mostrarDatos() const {
    std::cout << "ID: " << id << std::endl;
    std::cout << "Nombre: " << nombre << std::endl;
    std::cout << "Gerente: " << gerente << std::endl;
    std::cout << "Región: " << region << std::endl;
    std::cout << "Latitud: " << latitud << std::endl;
    std::cout << "Longitud: " << longitud << std::endl;
}

// Validar región
bool EstacionServicio::esRegionValida(char region) const {
    return region == 'N' || region == 'C' || region == 'S';
}

// Obtener ID
unsigned int EstacionServicio::getId() const {
    return id;
}

// Obtener nombre
std::string EstacionServicio::getNombre() const {
    return nombre;
}

// Obtener gerente
std::string EstacionServicio::getGerente() const {
    return gerente;
}

// Obtener región
char EstacionServicio::getRegion() const {
    return region;
}

// Obtener latitud
double EstacionServicio::getLatitud() const {
    return latitud;
}

// Obtener longitud
double EstacionServicio::getLongitud() const {
    return longitud;
}

Tanque* EstacionServicio::getTanque() const {
    return tanque; // Retorna el puntero al tanque
}




