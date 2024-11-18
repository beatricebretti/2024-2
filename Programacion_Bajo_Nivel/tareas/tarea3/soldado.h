#ifndef SOLDADO_H
#define SOLDADO_H

#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>
#include <thread>
#include <chrono>
#include "personaje.h"

class Soldado : public Personaje {
public:
    Soldado() : Personaje('S', "Soldado", 50, 10, 1, "HV", 1, 0) {}

    void actuar(vector<Personaje*>& enemigos, vector<Personaje*>& aliados) override {
        // Implementación del soldado
    }

    void desplazarse(int nuevaPos) override {
        // Implementación del desplazamiento del soldado
    }
};

#endif