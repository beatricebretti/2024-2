#ifndef SEDAN_H
#define SEDAN_H 

#include "vehiculo.h"

class Sedan : public Vehiculo {
    private:
        bool tieneSunRoof;
        bool tieneManosLibres;
        double capacidadMaleta;
public:
    Sedan(string marca, string modelo, int agno, int capacidadPasajeros, string color, double precio, 
          bool tieneSunRoof, bool tieneManosLibres, double capacidadMaleta);
    void mostrarInfo() const;
};

#endif