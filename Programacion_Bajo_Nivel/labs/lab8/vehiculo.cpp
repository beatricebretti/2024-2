#include "vehiculo.h"
#include <iostream>

Vehiculo::Vehiculo(string marca, string modelo, int agno, int capacidadPasajeros, string color, double precio)
    : marca(marca), modelo(modelo), agno(agno), capacidadPasajeros(capacidadPasajeros), color(color), precio(precio) {}

void Vehiculo::mostrarInfo() const {
    cout << "\t- Marca: " << marca << ", Modelo: " << modelo << ", Año: " << agno 
         << ", Capacidad de Pasajeros: " << capacidadPasajeros << ", Color: " << color 
         << ", Precio: " << precio << endl;
}