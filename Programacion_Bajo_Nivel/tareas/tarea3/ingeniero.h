#ifndef INGENIERO_H
#define INGENIERO_H

#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>
#include <thread>
#include <chrono>
#include "personaje.h"

class Ingeniero : public Personaje {
public:
    Ingeniero() : Personaje('I', "Ingeniero", 30, 50, 4, "HVD", 3, 20) {}

    void actuar(vector<Personaje*>& enemigos, vector<Personaje*>& aliados) override {
        if (!enemigos.empty()) {
            int danio = fuerzaMax; 
            int enemigoIndex = rand() % enemigos.size(); 
            enemigos[enemigoIndex]->recibirDanio(danio);
            cout << "El ingeniero ataca a " << enemigos[enemigoIndex]->getCodigo() << " y le causa " << danio << " de daño." << endl;
        }
    }

    void desplazarse(int nuevaPos) override {
        // Implementación del desplazamiento del ingeniero
    }
};

#endif