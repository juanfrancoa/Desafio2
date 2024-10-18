#include "tanque.h"
#include "surtidor.h"
#include "isla.h"



// Constructor por defecto
Tanque::Tanque() {

    // Generar valores aleatorios entre 100 y 200 litros para cada tipo de combustible
    capacidad_regular = 100 + (std::rand() % 101);  // Genera un valor entre 100 y 200
    capacidad_premium = 100 + (std::rand() % 101);  // Genera un valor entre 100 y 200
    capacidad_ecoextra = 100 + (std::rand() % 101); // Genera un valor entre 100 y 200

    nivel_actual_regular = capacidad_regular;
    nivel_actual_premium = capacidad_premium;
    nivel_actual_ecoextra = capacidad_ecoextra;

    // Inicializar semilla aleatoria
    std::srand(std::time(0));
}

// Método para mostrar los niveles de combustible
void Tanque::mostrarDatosTanque() {

    std::cout << "Niveles actuales de combustible en el tanque central: \n";
    std::cout << "Regular: " << nivel_actual_regular << " litros \n";
    std::cout << "Premium: " << nivel_actual_premium << " litros \n";
    std::cout << "EcoExtra: " << nivel_actual_ecoextra << " litros \n";
}

int Tanque::venta(std::string tipo, int cantidad){


    if (tipo == "Regular") {
        if (nivel_actual_regular >= cantidad) {
            nivel_actual_regular -= cantidad;
        } else {
            // Vender solo lo disponible
            cantidad = nivel_actual_regular;
            nivel_actual_regular = 0;  // Todo el combustible disponible ha sido vendido
        }
    } else if (tipo == "Premium") {
        if (nivel_actual_premium >= cantidad) {
            nivel_actual_premium -= cantidad;
        } else {
            // Vender solo lo disponible
            cantidad = nivel_actual_premium;
            nivel_actual_premium = 0;  // Todo el combustible disponible ha sido vendido
        }
    } else if (tipo == "EcoExtra") {
        if (nivel_actual_ecoextra >= cantidad) {
            nivel_actual_ecoextra -= cantidad;
        } else {
            // Vender solo lo disponible
            cantidad = nivel_actual_ecoextra;
            nivel_actual_ecoextra = 0;  // Todo el combustible disponible ha sido vendido
        }
    } else {
        return 0;
    }

    return cantidad;


}

void Tanque::agregarIsla(Isla* isla) {
    islas.push_back(isla); // Agrega la isla al vector
}

void Tanque::mostrarIslas() const {
    std::cout << "Islas asociadas al tanque:\n";
    for (const auto& isla : islas) {
        isla->mostrarSurtidores(); // Muestra los surtidores de cada isla
    }
}

int Tanque::mostrarSurtidores() {
    int i = 0;
    for (const auto& isla : islas) {
        i += isla->contarSurtidores(); // Muestra los surtidores de cada isla
    }
    return i;
}

bool Tanque::surtidoresHabilitados(){
    bool surtidoresHabilitados = false;
    for (const auto& isla : islas) {
        if(isla->surtidoresHabilitados()){ // Muestra los surtidores de cada isla
            surtidoresHabilitados = true;
        }
    }
    return surtidoresHabilitados;
}

Surtidor* Tanque::obtenerSurtidorAleatorio() const {
    if (islas.empty()) return nullptr;

    // Selecciona una isla aleatoria
    int islaIndex = std::rand() % islas.size();
    Isla* isla = islas[islaIndex];

    // Obtén los surtidores de la isla seleccionada
    const std::vector<Surtidor*>& surtidores = isla->obtenerSurtidores();
    if (surtidores.empty()) return nullptr;

    // Selecciona un surtidor aleatorio de la isla
    int surtidorIndex = std::rand() % surtidores.size();
    return surtidores[surtidorIndex];
}





