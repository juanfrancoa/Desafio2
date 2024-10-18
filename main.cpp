#include "tanque.h"
#include "surtidor.h"
#include "isla.h"
#include "estacionservicio.h"
#include "preciogasolina.h"

#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>


void ventasEstacionServicio();
void ventasSurtidoresEstacion(int idEstacionBuscada);
void ventasTotalesPorEstacionYCombustible();
void mostrarMenu();
void crearEstacionServicio();


Tanque* tanqueRegular = nullptr;
PrecioGasolina precioGasolina;
std::vector<Surtidor*> surtidores; // Para almacenar los surtidores
Isla* isla1 = nullptr;

// Funciones para manejar las opciones del menú


void crearTanque(Tanque*& tanque) {
    tanque = new Tanque();
    std::cout << "Tanque creado.\n";
}

void crearIsla(Tanque* tanque, Isla*& isla) {
    if (!tanque) {
        std::cout << "Primero debes crear el tanque.\n";
        return;
    }

    isla = new Isla("Isla 1");
    tanque->agregarIsla(isla); // Agregar la isla al tanque
    std::cout << "Isla creada y asignada al tanque.\n";
}

void crearSurtidores(Tanque* tanque, Isla* isla) {
    if (!tanque || !isla) {
        std::cout << "Primero debes crear el tanque y la isla.\n";
        return;
    }

    // Crear surtidores dinámicamente
    for (int i = 0; i < 8; ++i) {
        if(tanque->mostrarSurtidores() >= 12){
            break;
        }
        Surtidor* surtidor = new Surtidor("Premium", "Modelo B", tanque);
        isla->agregarSurtidor(surtidor); // Agregar surtidor a la isla
    }
    std::cout << "Surtidores creados y asignados a la isla. Total surtidores en el tanque: " << tanque->mostrarSurtidores() << "\n";
}
void crearEstacionServicio(Tanque* tanque) {
    if (!tanque) {
        std::cout << "Primero debes crear el tanque.\n";
        return;
    }

    EstacionServicio estacionServicio("Estación 1", "Juan Pérez", 'N', 34.123456, -118.654321, tanque);
    std::cout << "Estacion de servicio creada.\n";
    std::cout << "Total surtidores en el tanque: " << tanque->mostrarSurtidores() << "\n";

    // Realizar una venta de combustible
    Surtidor* venta = tanque->obtenerSurtidorAleatorio();
    if (venta) {
        char region = estacionServicio.getRegion();
        double precio = precioGasolina.valorGasolina(region);
        venta->venderCombustible(precio, estacionServicio.getId());
        std::cout << "Venta realizada con exito.\n";
    } else {
        std::cout << "No se pudo realizar la venta, no hay surtidores habilitados.\n";
    }

    std::cout << "Surtidores habilitados: " << tanque->surtidoresHabilitados() << "\n";
}

void deshabilitarTodosSurtidores(Isla* isla) {
    if (!isla) {
        std::cout << "Primero debes crear la isla.\n";
        return;
    }

    // Obtener los surtidores de la isla
    for (Surtidor* surtidor : isla->obtenerSurtidores()) {
        surtidor->deshabilitarSurtidor();
    }
    std::cout << "Todos los surtidores han sido deshabilitados en la isla.\n";

}

void eliminarEstacion(EstacionServicio*& estacion) {
    if (estacion) {
        delete estacion; // Liberar memoria de la estación
        estacion = nullptr; // Poner a nullptr para evitar acceso a memoria liberada
        std::cout << "Estación de servicio eliminada.\n";
    }
    else {
        std::cout << "No hay estacion de servicio para eliminar o surtidores activos.\n";
    }
}

void liberarMemoria(Tanque* tanque, Isla* isla) {
    delete isla; // Asegúrate de liberar la isla correctamente
    delete tanque; // Asegúrate de liberar el tanque correctamente
    std::cout << "Memoria liberada.\n";
}


int main() {
    srand(time(0)); // Inicializar semilla para rand()

    Tanque* tanqueRegular = nullptr;
    Isla* isla1 = nullptr;
    EstacionServicio* estacionServicio = nullptr;
    int opcion;
    do {
        std::cout << "Menu:\n";
        std::cout << "1. Crear Tanque\n";
        std::cout << "2. Crear Isla\n";
        std::cout << "3. Crear Surtidores\n";
        std::cout << "4. Crear Estacion de Servicio\n";
        std::cout << "5. Ventas de Estacion de Servicio\n";
        std::cout << "6. ventas por Estacion de Servicio y tipo\n";
        std::cout << "7. Desabilitar surtidores\n";
        std::cout << "8. Eliminar Estacion\n";
        std::cout << "0. Salir\n";
        std::cout << "Selecciona una opcion: ";
        std::cin >> opcion;


        if (std::cin.fail()) {
            std::cin.clear(); // Restablecer el estado de error
            std::cin.ignore(1000, '\n'); // Ignorar la entrada incorrecta
            std::cout << "Entrada no valida. Por favor ingrese un numero." << std::endl;
            continue; // Volver al inicio del bucle
        }


        switch (opcion) {
        case 1:
            crearTanque(tanqueRegular);
            break;
        case 2:
            crearIsla(tanqueRegular, isla1);
            break;
        case 3:
            crearSurtidores(tanqueRegular, isla1);
            break;
        case 4:
            crearEstacionServicio(tanqueRegular);
            break;
        case 5:
            ventasEstacionServicio();
            break;
        case 6:
            ventasTotalesPorEstacionYCombustible();
            break;
        case 7:
            deshabilitarTodosSurtidores(isla1);
            break;
        case 8:
            eliminarEstacion(estacionServicio);
            break;
        case 0:
            liberarMemoria(tanqueRegular, isla1);
            break;
        default:
            std::cout << "Opción no valida. Intentalo de nuevo.\n";
        }

        std::cout << std::endl; // Agregar una línea en blanco para mayor claridad
    } while (opcion != 0);



    /*
    Tanque* tanqueRegular = new Tanque();
    PrecioGasolina precioGasolina;

    // Crear surtidores dinámicamente
    Surtidor* surtidor1 = new Surtidor("Regular", "Modelo A", tanqueRegular);
    Surtidor* surtidor2 = new Surtidor("Premium", "Modelo B", tanqueRegular);
    Surtidor* surtidor3 = new Surtidor("Premium", "Modelo B", tanqueRegular);
    Surtidor* surtidor4 = new Surtidor("Premium", "Modelo B", tanqueRegular);
    Surtidor* surtidor5 = new Surtidor("Premium", "Modelo B", tanqueRegular);
    Surtidor* surtidor6 = new Surtidor("Premium", "Modelo B", tanqueRegular);
    Surtidor* surtidor7 = new Surtidor("Premium", "Modelo B", tanqueRegular);
    Surtidor* surtidor8 = new Surtidor("Premium", "Modelo B", tanqueRegular);

    // Crear isla y agregar surtidores
    Isla* isla1 = new Isla("Isla 1");
    isla1->agregarSurtidor(surtidor1);
    isla1->agregarSurtidor(surtidor2);
    isla1->agregarSurtidor(surtidor3);
    isla1->agregarSurtidor(surtidor4);
    isla1->agregarSurtidor(surtidor5);
    isla1->agregarSurtidor(surtidor6);
    isla1->agregarSurtidor(surtidor7);
    isla1->agregarSurtidor(surtidor8);

    // Agregar la isla al tanque
    tanqueRegular->agregarIsla(isla1);



    surtidor1->deshabilitarSurtidor();
    surtidor2->deshabilitarSurtidor();
    surtidor3->deshabilitarSurtidor();
    surtidor4->deshabilitarSurtidor();
    surtidor5->deshabilitarSurtidor();
    surtidor6->deshabilitarSurtidor();
    surtidor7->deshabilitarSurtidor();
    surtidor8->deshabilitarSurtidor();



    // Crear estación de servicio
    EstacionServicio estacionServicio("Estación 1", "Juan Pérez", 'N', 34.123456, -118.654321, tanqueRegular);
    //estacionServicio.getTanque()->mostrarIslas();
    std::cout << "tanqueRegular tiene " << estacionServicio.getTanque()->mostrarSurtidores() << " surtidores \n";

    // Realizar una venta de combustible
    char region = estacionServicio.getRegion();
    double precio = precioGasolina.valorGasolina(region);
    Surtidor* venta = tanqueRegular->obtenerSurtidorAleatorio();
    venta->venderCombustible(precio, estacionServicio.getId());

    std::cout << tanqueRegular->surtidoresHabilitados();

    ventasEstacionServicio();
    ventasTotalesPorEstacionYCombustible();
    ventasSurtidoresEstacion(0);
    // Liberar la memoria dinámica
    delete surtidor1;
    delete surtidor2;
    delete surtidor3;
    delete surtidor4;
    delete surtidor5;
    delete surtidor6;
    delete surtidor7;
    delete surtidor8;
    delete isla1;  // Elimina la isla
    delete tanqueRegular;  // Elimina el tanque
    */
    return 0;
}


void ventasEstacionServicio() {
    std::ifstream archivoVentas("C:/Users/esteb/Desktop/ventas.txt");
    std::string linea;

    // Arreglos paralelos para almacenar ID de estaciones y ventas totales
    std::vector<int> idsEstacion;
    std::vector<double> ventasEstacion;

    int idEstacion = 0;
    double valorVenta = 0.0;
    bool newTransaction = false;

    if (archivoVentas.is_open()) {
        while (std::getline(archivoVentas, linea)) {
            std::stringstream ss(linea);
            std::string clave;
            while (ss >> clave) {
                if (clave == "Estacion") {
                    ss.ignore(4); // Ignora " ID:"
                    int idSurtidor;
                    ss >> idSurtidor;
                    idEstacion = idSurtidor; // Lógica simplificada
                    newTransaction = true;
                }
                if (clave == "Valor") {
                    ss.ignore(2); // Ignora el espacio y el ":"
                    ss >> valorVenta;

                    if (newTransaction) {
                        // Verificar si la estación ya está en el vector
                        bool estacionEncontrada = false;
                        for (size_t i = 0; i < idsEstacion.size(); ++i) {
                            if (idsEstacion[i] == idEstacion) {
                                // Si la estación ya existe, suma la venta
                                ventasEstacion[i] += valorVenta;
                                estacionEncontrada = true;
                                break;
                            }
                        }
                        // Si no se encontró, agregar nueva estación y su venta
                        if (!estacionEncontrada) {
                            idsEstacion.push_back(idEstacion);
                            ventasEstacion.push_back(valorVenta);
                        }

                        newTransaction = false;
                    }
                }
            }
        }
        archivoVentas.close();
    } else {
        std::cerr << "Error: No se pudo abrir el archivo de ventas." << std::endl;
    }

    // Mostrar las ventas por estación de servicio
    for (size_t i = 0; i < idsEstacion.size(); ++i) {
        std::cout << "Estacion ID: " << idsEstacion[i] << ", Valor Total Vendido: " << ventasEstacion[i] << " $" << std::endl;
    }
}

void ventasSurtidoresEstacion(int idEstacionBuscada) {
    std::ifstream archivoVentas("C:/Users/esteb/Desktop/ventas.txt");
    std::string linea;

    // Vectores para almacenar los valores
    std::vector<int> surtidores;
    std::vector<std::string> tiposCombustible;
    std::vector<double> litrosVendidos;
    std::vector<double> valoresVenta;

    int idEstacion = 0;
    int idSurtidor = 0;
    std::string tipoCombustible;
    double litros = 0.0;
    double valor = 0.0;

    if (archivoVentas.is_open()) {
        while (std::getline(archivoVentas, linea)) {
            std::stringstream ss(linea);
            std::string clave;

            // Procesar cada línea del archivo
            if (linea.find("Estacion ID:") != std::string::npos) {
                ss.ignore(12); // Ignorar "Estacion ID: "
                ss >> idEstacion;
            }
            else if (linea.find("Surtidor ID:") != std::string::npos) {
                ss.ignore(12); // Ignorar "Surtidor ID: "
                ss >> idSurtidor;
            }
            else if (linea.find("Tipo de Combustible:") != std::string::npos) {
                ss.ignore(20); // Ignorar "Tipo de Combustible: "
                ss >> tipoCombustible;
            }
            else if (linea.find("Litros Vendidos:") != std::string::npos) {
                ss.ignore(17); // Ignorar "Litros Vendidos: "
                ss >> litros;
            }
            else if (linea.find("Valor :") != std::string::npos) {
                ss.ignore(7); // Ignorar "Valor : "
                ss >> valor;

                // Solo almacenar los datos si la estación coincide con la buscada
                if (idEstacion == idEstacionBuscada) {
                    surtidores.push_back(idSurtidor);
                    tiposCombustible.push_back(tipoCombustible);
                    litrosVendidos.push_back(litros);
                    valoresVenta.push_back(valor);
                }
            }
        }
        archivoVentas.close();
    } else {
        std::cerr << "Error: No se pudo abrir el archivo de ventas." << std::endl;
        return;
    }

    // Mostrar los datos agrupados por surtidor
    double totalEstacion = 0.0;
    for (size_t i = 0; i < surtidores.size(); ++i) {
        std::cout << "Surtidor ID: " << surtidores[i] << std::endl;
        std::cout << "Tipo de Combustible: " << tiposCombustible[i] << std::endl;
        std::cout << "Litros Vendidos: " << litrosVendidos[i] << " litros" << std::endl;
        std::cout << "Valor: " << valoresVenta[i] << " $" << std::endl;
        std::cout << "------------------------------" << std::endl;

        // Sumar al total de la estación
        totalEstacion += valoresVenta[i];
    }

    std::cout << "Total de ventas para la Estacion ID " << idEstacionBuscada << ": " << totalEstacion << " $" << std::endl;
}

void ventasTotalesPorEstacionYCombustible() {
    std::ifstream archivoVentas("C:/Users/esteb/Desktop/ventas.txt");
    std::string linea;

    // Vectores para almacenar los datos de las ventas
    std::vector<int> estaciones;
    std::vector<std::string> tiposCombustible;
    std::vector<double> valoresVenta;

    int idEstacion = 0;
    std::string tipoCombustible;
    double valor = 0.0;

    if (archivoVentas.is_open()) {
        while (std::getline(archivoVentas, linea)) {
            std::stringstream ss(linea);

            // Procesar cada línea del archivo
            if (linea.find("Estacion ID:") != std::string::npos) {
                ss.ignore(12); // Ignorar "Estacion ID: "
                ss >> idEstacion;
            }
            else if (linea.find("Tipo de Combustible:") != std::string::npos) {
                ss.ignore(20); // Ignorar "Tipo de Combustible: "
                ss >> tipoCombustible;
            }
            else if (linea.find("Valor :") != std::string::npos) {
                ss.ignore(7); // Ignorar "Valor : "
                ss >> valor;

                // Almacenar los datos de cada venta
                estaciones.push_back(idEstacion);
                tiposCombustible.push_back(tipoCombustible);
                valoresVenta.push_back(valor);
            }
        }
        archivoVentas.close();
    } else {
        std::cerr << "Error: No se pudo abrir el archivo de ventas." << std::endl;
        return;
    }

    // Vector para registrar estaciones ya procesadas
    std::vector<int> estacionesProcesadas;
    // Procesar cada estación
    for (size_t i = 0; i < estaciones.size(); ++i) {
        int estacionActual = estaciones[i];

        // Verificar si la estación ya fue procesada manualmente
        bool yaProcesada = false;
        for (size_t k = 0; k < estacionesProcesadas.size(); ++k) {
            if (estacionesProcesadas[k] == estacionActual) {
                yaProcesada = true;
                break;
            }
        }
        if (yaProcesada) {
            continue;
        }

        // Marcar la estación como procesada
        estacionesProcesadas.push_back(estacionActual);

        // Mostrar los totales discriminados por tipo de combustible
        std::cout << "Estacion ID: " << estacionActual << std::endl;
        double totalRegular = 0.0, totalPremium = 0.0, totalEcoExtra = 0.0;

        for (size_t j = 0; j < estaciones.size(); ++j) {
            if (estaciones[j] == estacionActual) {
                if (tiposCombustible[j] == "Regular") {
                    totalRegular += valoresVenta[j];
                } else if (tiposCombustible[j] == "Premium") {
                    totalPremium += valoresVenta[j];
                } else if (tiposCombustible[j] == "EcoExtra") {
                    totalEcoExtra += valoresVenta[j];
                }
            }
        }

        // Mostrar los totales de cada tipo de combustible para la estación actual
        std::cout << "Total Regular: " << totalRegular << " $" << std::endl;
        std::cout << "Total Premium: " << totalPremium << " $" << std::endl;
        std::cout << "Total EcoExtra: " << totalEcoExtra << " $" << std::endl;
        std::cout << "------------------------------" << std::endl;
    }
}
