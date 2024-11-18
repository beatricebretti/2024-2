#ifndef CABALLERO_H
#define CABALLERO_H

#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>
#include <thread>
#include <chrono>
#include "personaje.h"

class Caballero : public Personaje {
public:
    Caballero() : Personaje('C', "Caballero", 100, 30, 1, "HV", 3, 0) {}

    void actuar(vector<Personaje*>& enemigos, vector<Personaje*>& aliados) override {
        // Implementación del caballero
    }

    void desplazarse(int nuevaPos) override {
        // Implementación del desplazamiento del caballero
    }
};

#endif