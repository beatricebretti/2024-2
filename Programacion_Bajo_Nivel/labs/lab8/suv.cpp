#include "suv.h"
#include <iostream>

SUV::SUV(string marca, string modelo, int agno, int capacidadPasajeros, string color, double precio, 
         int tamañoNeumatico, double despejeSuelo, bool tieneHuinche)
    : Vehiculo(marca, modelo, agno, capacidadPasajeros, color, precio), 
      tamañoNeumatico(tamañoNeumatico), despejeSuelo(despejeSuelo), tieneHuinche(tieneHuinche) {}

void SUV::mostrarInfo() const {
     Vehiculo::mostrarInfo();
     
     cout << "\tTamaño Neumático: " << tamañoNeumatico << " pulgadas, Despeje del suelo: " 
         << despejeSuelo << " cm, Huinche: ";
     if (tieneHuinche){
          cout << "Si";
     }
     else{
          cout << "No";
     } 
     cout << endl;
}