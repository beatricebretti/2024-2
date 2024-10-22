#ifndef VEHICULO_H
#define VEHICULO_H 

#include <string>
using namespace std;

class Vehiculo {
    private:
        string marca;
        string modelo;
        int agno;
        int capacidadPasajeros;
        string color;
        double precio;
    public:
        Vehiculo(string marca, string modelo, int agno, int capacidadPasajeros, string color, double precio);
        virtual void mostrarInfo() const;
        virtual ~Vehiculo() {}
};

#endif