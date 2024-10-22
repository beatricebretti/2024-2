#include "sedan.h"
#include <iostream>

Sedan::Sedan(string marca, string modelo, int agno, int capacidadPasajeros, string color, double precio, 
             bool tieneSunRoof, bool tieneManosLibres, double capacidadMaleta)
    : Vehiculo(marca, modelo, agno, capacidadPasajeros, color, precio), 
      tieneSunRoof(tieneSunRoof), tieneManosLibres(tieneManosLibres), capacidadMaleta(capacidadMaleta) {}

void Sedan::mostrarInfo() const {
    Vehiculo::mostrarInfo();

    cout << "\tSunRoof: ";
    if (tieneSunRoof){
      cout << "Si";
    }
    else{
      cout << "No";
    }
    cout<< ", Manos Libres: ";
    if(tieneManosLibres) {
      cout << "Si";
    } 
    else{
      cout << "No";
    }
    cout << ", Capacidad Maleta: " << capacidadMaleta << " litros" << endl;
}