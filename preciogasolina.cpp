#include "preciogasolina.h"
#include <iostream>

PrecioGasolina::PrecioGasolina() {

    norte = 12.4;
    sur = 10.2;
    centro = 9.2;
}

void PrecioGasolina::cambioPrecio(char region, double valor){
    if(region == 'N'){
        norte = valor;
    }
    else if(region == 'S'){
        sur = valor;
    }
    else if(region == 'C'){
        centro = valor;
    }
    else{
        std::cout << "No se pudo cambiar el valor de la gasolina. \n";
    }
}

double PrecioGasolina::valorGasolina(char region){
    double valor = 0;
    if(region == 'N'){
        valor = norte;
    }
    else if(region == 'S'){
        valor = sur;
    }
    else{
        valor = centro;
    }
    return valor;
}
