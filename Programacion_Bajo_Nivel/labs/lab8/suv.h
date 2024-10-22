#ifndef SUV_H
#define SUV_H 

#include "vehiculo.h"

class SUV : public Vehiculo {
    private:
        int tamañoNeumatico;
        double despejeSuelo;
        bool tieneHuinche;
    public:
        SUV(string marca, string modelo, int agno, int capacidadPasajeros, string color, double precio, 
        int tamañoNeumatico, double despejeSuelo, bool tieneHuinche);
        void mostrarInfo() const;
};

#endif