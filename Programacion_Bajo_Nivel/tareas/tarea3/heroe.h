#ifndef HEROE_H
#define HEROE_H

#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>
#include <thread>
#include <chrono>
#include "personaje.h"

class Heroe : public Personaje {
public:
    Heroe() : Personaje('H', "Heroe", 500, 30, 3, "HVD", 4, 5) {}

    void actuar(vector<Personaje*>& enemigos, vector<Personaje*>& aliados) override {
        // Implementación del héroe
    }

    void desplazarse(int nuevaPos) override {
        // Implementación del desplazamiento del héroe
    }
};

#endif