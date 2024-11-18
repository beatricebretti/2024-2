#ifndef ARQUERO_H
#define ARQUERO_H

#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>
#include <thread>
#include <chrono>
#include "personaje.h"

class Arquero : public Personaje {
public:
    Arquero() : Personaje('A', "Arquero", 50, 5, 3, "HV", 1, 0) {}

    void actuar(vector<Personaje*>& enemigos, vector<Personaje*>& aliados) override {
        // Implementación del arquero
    }

    void desplazarse(int nuevaPos) override {
        // Implementación del desplazamiento del arquero
    }
};

#endif