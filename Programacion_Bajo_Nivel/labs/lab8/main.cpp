#include <iostream>
#include "sedan.h"
#include "suv.h"
#include "deportivo.h"
#include "furgon.h"

int main() {
    Sedan sedanes[] = {
        Sedan("Toyota", "Corolla", 2021, 5, "Blanco", 10000, true, true, 450),
        Sedan("Honda", "Civic", 2022, 5, "Gris", 20000, false, true, 430)
    };

    SUV suvs[] = {
        SUV("Jeep", "Cherokee", 2022, 5, "Negro", 30000, 20, 30, true),
        SUV("Ford", "Explorer", 2023, 7, "Rojo", 40000, 22, 25, false),
        SUV("Toyota", "4Runner", 2021, 5, "Blanco", 50000, 18, 28, true)
    };

    Deportivo deportivos[] = {
        Deportivo("Ferrari", "488", 2023, 2, "Rojo", 200000, 7, 3.0, 15),
        Deportivo("Lamborghini", "Huracan", 2022, 2, "Amarillo", 300000, 6, 2.9, 16)
    };

    Furgon furgones[] = {
        Furgon("Mercedes", "Sprinter", 2021, 3, "Blanco", 50000, 3000, 10, 12),
        Furgon("Ford", "Transit", 2022, 3, "Azul", 40000, 2800, 12, 10),
        Furgon("Renault", "Master", 2020, 3, "Gris", 40000, 2500, 9, 11)
    };

    std::cout << "Sedan:\n";
    for (int i=0; i < 2; i++) {
        sedanes[i].mostrarInfo();
    }

    std::cout << "\nSUV:\n";
    for (int i=0; i < 3; i++) {
        suvs[i].mostrarInfo();
    }

    std::cout << "\nDeportivo:\n";
    for (int i=0; i < 2; i++) {
        deportivos[i].mostrarInfo();
    }

    std::cout << "\nFurgon:\n";
    for (int i=0; i < 3; i++) {
        furgones[i].mostrarInfo();
    }

    return 0;
}