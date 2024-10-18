#ifndef PRECIOGASOLINA_H
#define PRECIOGASOLINA_H

class PrecioGasolina
{

private:
    double norte;
    double sur;
    double centro;
public:
    PrecioGasolina();
    void cambioPrecio(char region, double valor);
    double valorGasolina(char region);
};

#endif // PRECIOGASOLINA_H
