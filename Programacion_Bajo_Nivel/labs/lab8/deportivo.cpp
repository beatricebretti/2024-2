#include "deportivo.h"
#include <iostream>

Deportivo::Deportivo(string marca, string modelo, int agno, int capacidadPasajeros, string color, double precio, 
                     int cantidadCambios, double aceleracion0_100, double diametroDiscosFreno)
    : Vehiculo(marca, modelo, agno, capacidadPasajeros, color, precio), 
      cantidadCambios(cantidadCambios), aceleracion0_100(aceleracion0_100), diametroDiscosFreno(diametroDiscosFreno) {}

void Deportivo::mostrarInfo() const {
    Vehiculo::mostrarInfo();
    cout << "\tCambios: " << cantidadCambios << ", Aceleración 0-100: " << aceleracion0_100 
         << " segundos, Diámetro de discos de freno: " << diametroDiscosFreno << " pulgadas" << endl;
}