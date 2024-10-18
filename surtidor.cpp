#include "surtidor.h"
#include "tanque.h"
#include "preciogasolina.h"
#include <fstream>  // Para trabajar con archivos
#include <ctime>    // Para obtener la fecha y hora actual
#include <cstdlib>  // Para funciones rand()
#include <iomanip>  // Para manejar formato de fecha y hora
#include "estacionservicio.h"

// Inicialización del contador estático
unsigned long Surtidor::idCounter = 0;
class Tanque;
class PrecioGasolina;
class EstacionServicio;

// Constructor
Surtidor::Surtidor(std::string tipoCombustible, std::string modelo, Tanque* t)
    : tipoCombustible(tipoCombustible), modelo(modelo), tanque(t), habilitado(true) {
    id = ++idCounter;
}


// Método para vender combustible
void Surtidor::venderCombustible(double precio, int estacionId) {

    if (habilitado) {
        // Llama al método del tanque asociado para realizar la venta

        // Generar una cantidad aleatoria entre 3 y 20 litros

        int cantidad = 3 + (std::rand() % 18);

        int gasolinaVendida =  tanque->venta(tipoCombustible, cantidad );

        std::ofstream archivoVentas("C:/Users/esteb/Desktop/ventas.txt", std::ios::app);  // Abrir en modo "append"
        if (archivoVentas.is_open() && gasolinaVendida != 0) {
            int numeroDocumento = 100000 + (std::rand() % 900000);  // Número entre 100000 y 999999
            // **Seleccionar tipo de pago aleatorio**
            std::string tiposDePago[] = {"Efectivo", "TDebito", "TCrédito"};
            std::string tipoPago = tiposDePago[std::rand() % 3];  // Selecciona un tipo de pago aleatorio

            // **Obtener la fecha y hora actual**
            std::time_t t = std::time(nullptr);  // Tiempo actual
            std::tm* localTime = std::localtime(&t);  // Convertir a hora local
            archivoVentas << "Estacion ID: " << estacionId << "\n";
            archivoVentas << "Surtidor ID: " << id << "\n";
            archivoVentas << "Tipo de Combustible: " << tipoCombustible << "\n";
            archivoVentas << "Litros Vendidos: " << gasolinaVendida << " litros\n";
            archivoVentas << "Número de Documento: " << numeroDocumento << "\n";
            archivoVentas << "Tipo de Pago: " << tipoPago << "\n";
            archivoVentas << "Valor :" << precio * gasolinaVendida << " $ \n";
            archivoVentas << "Fecha y Hora: "
                          << std::put_time(localTime, "%Y-%m-%d %H:%M:%S") << "\n";  // Formato: AAAA-MM-DD HH:MM:SS
            archivoVentas << "------------------------------\n";
            archivoVentas.close();  // Cerrar el archivo
            std::cout << "Se vendio " << gasolinaVendida <<" " << tipoCombustible<<std::endl;

        } else {
            std::cerr << "Error: No se pudo abrir el archivo de ventas.\n";
        }

    } else {
        std::cout << "El surtidor esta deshabilitado." << std::endl;
    }
}

// Método para mostrar el estado del surtidor
void Surtidor::mostrarEstadoSurtidor() {
    std::cout << "Surtidor ID: " << id << std::endl;
    std::cout << "Modelo: " << modelo << std::endl;
    std::cout << "Estado: " << habilitado << std::endl;
    std::cout << "Tipo de combustible: " << tipoCombustible << std::endl;
}

void Surtidor::habilitarSurtidor() {
    habilitado = true;  // Cambia el estado a habilitado
    std::cout << "Surtidor habilitado.\n";
}

// Método para deshabilitar el surtidor
void Surtidor::deshabilitarSurtidor() {
    habilitado = false;  // Cambia el estado a deshabilitado
    std::cout << "Surtidor deshabilitado.\n";
}

bool Surtidor::getHabilitado()
{
    return habilitado;
}
