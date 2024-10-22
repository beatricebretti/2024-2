#include <iostream>
#include "vehiculo.h"
using namespace std; 

int main() {
    //vehiculos inventadosa
    Vehiculo v1("AAA123", 2014, "Toyota", "Corolla", 10000);
    Vehiculo v2("BBB456", 2016, "Honda", "Civic", 12000);
    Vehiculo v3("CCC789", 2018, "Ford", "Focus", 15000);
    Vehiculo v4("DDD123", 2020, "Chevrolet", "Malibu", 13000);
    Vehiculo v5("EEE456", 2022, "Tesla", "Model 3", 35000);

    //infracciones
    v1.agregaInfraccion();
    v1.agregaInfraccion();
    v2.agregaInfraccion();
    v3.agregaInfraccion();
    v3.agregaInfraccion();
    v3.agregaInfraccion();
    v4.agregaInfraccion();
    v5.agregaInfraccion();
    v5.agregaInfraccion();
    v5.agregaInfraccion();

    int agnoActual = 2024;
    Vehiculo vehiculos[] = {v1, v2, v3, v4, v5}; //lista de vehiculos
    for (int i = 0; i < 5; i++) {
        cout << "Marca: " << vehiculos[i].getMarca() << "\n";
        cout << "Modelo: " << vehiculos[i].getModelo() << "\n";
        cout << "Año: " << vehiculos[i].getAgno() << "\n";
        cout << "Patente: " << vehiculos[i].getPatente() << "\n";
        cout << "Valor Actual: $" << vehiculos[i].valorActual(agnoActual) << "\n";
        cout << "Infracciones: " << vehiculos[i].getInfracciones() << "\n";
        cout << "-----------------------------\n";
    }
    return 0;
}