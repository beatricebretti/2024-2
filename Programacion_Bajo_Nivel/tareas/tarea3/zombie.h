#ifndef ZOMBIE_H
#define ZOMBIE_H

#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>
#include <thread>
#include <chrono>
#include "personaje.h"

class Zombie : public Personaje {
public:
    Zombie() : Personaje('Z', "Zombie", 50, 10, 1, "HVD", 1, 0) {}

    void actuar(vector<Personaje*>& enemigos, vector<Personaje*>& aliados) override {
        // Implementación del zombie
    }

    void desplazarse(int nuevaPos) override {
        // Implementación del desplazamiento del zombie
    }
};

#endif