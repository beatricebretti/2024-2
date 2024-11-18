#ifndef TORRE_H
#define TORRE_H

#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>
#include <thread>
#include <chrono>
#include "personaje.h"

class Torre : public Personaje {
public:
    Torre() : Personaje('T', "Torre", 500, 30, 3, "HV", 0, 0) {}

    void actuar(vector<Personaje*>& enemigos, vector<Personaje*>& aliados) override {
        // Implementación de la torre
    }

    void desplazarse(int nuevaPos) override {
        // Las torres no se desplazan
    }
};

#endif