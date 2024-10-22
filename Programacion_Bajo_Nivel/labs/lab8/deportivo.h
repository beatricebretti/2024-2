#ifndef DEPORTIVO_H
#define DEPORTIVO_H 

#include "vehiculo.h"

class Deportivo : public Vehiculo {
    private:
        int cantidadCambios;
        double aceleracion0_100;
        double diametroDiscosFreno;
    public:
        Deportivo(string marca, string modelo, int agno, int capacidadPasajeros, string color, double precio, 
                  int cantidadCambios, double aceleracion0_100, double diametroDiscosFreno);
        void mostrarInfo() const;
};

#endif
