#ifndef FURGON_H
#define FURGON_H 

#include "vehiculo.h"

class Furgon : public Vehiculo {
    private:
        double cargaMaxima;
        double volumenCarga;
        double rendimientoKML;
    public:
        Furgon(string marca, string modelo, int agno, int capacidadPasajeros, string color, double precio, 
               double cargaMaxima, double volumenCarga, double rendimientoKML);
        void mostrarInfo() const;
};

#endif