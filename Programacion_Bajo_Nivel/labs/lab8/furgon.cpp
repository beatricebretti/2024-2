#include "furgon.h"
#include <iostream>

Furgon::Furgon(string marca, string modelo, int agno, int capacidadPasajeros, string color, double precio, 
               double cargaMaxima, double volumenCarga, double rendimientoKML)
    : Vehiculo(marca, modelo, agno, capacidadPasajeros, color, precio), 
      cargaMaxima(cargaMaxima), volumenCarga(volumenCarga), rendimientoKML(rendimientoKML) {}

void Furgon::mostrarInfo() const {
    Vehiculo::mostrarInfo();
    cout << "\tCarga Máxima: " << cargaMaxima << " kg, Volumen de Carga: " << volumenCarga 
         << " m^3, Rendimiento: " << rendimientoKML << " km/l" << endl;
}