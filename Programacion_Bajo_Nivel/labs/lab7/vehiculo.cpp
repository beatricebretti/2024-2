#include "vehiculo.h"
using namespace std; 

Vehiculo::Vehiculo(string _patente, int _agno, string _marca, string _modelo, double _precioNuevo) {
    patente = _patente;
    agno = _agno;
    marca = _marca;
    modelo = _modelo;
    precioNuevo = _precioNuevo;
    numeroInfracciones = 0;
}

double Vehiculo::valorActual(int agnoActual) {
    int agnosTranscurridos = agnoActual - agno;
    double depreciacion = 0.2 + (agnosTranscurridos - 1) * 0.05;
    if (depreciacion > 1.0) {
        depreciacion = 1.0;
    }
    return precioNuevo * (1 - depreciacion);
}

void Vehiculo::agregaInfraccion() {
    numeroInfracciones++;
}

int Vehiculo::getInfracciones() const {
    return numeroInfracciones;
}

string Vehiculo::getPatente() const {
    return patente;
}

int Vehiculo::getAgno() const {
    return agno;
}

string Vehiculo::getMarca() const {
    return marca;
}

string Vehiculo::getModelo() const {
    return modelo;
}