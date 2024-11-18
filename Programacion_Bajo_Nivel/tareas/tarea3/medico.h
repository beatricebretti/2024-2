#ifndef MEDICO_H
#define MEDICO_H

#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>
#include <thread>
#include <chrono>
#include "personaje.h"

class Medico : public Personaje {
public:
    Medico() : Personaje('M', "Medico", 30, 0, 0, "", 3, 15) {}

    void actuar(vector<Personaje*>& enemigos, vector<Personaje*>& aliados) override {
        for (auto& aliado : aliados) {
            if (aliado->getSaludActual() < aliado->saludBase) {
                aliado->curar(curacion);
                cout << "El médico cura a " << aliado->getCodigo() << " a " << curacion << " puntos de salud." << endl;
                return;
            }
        }
    }

    void desplazarse(int nuevaPos) override {
        // Implementación del desplazamiento del médico
    }
};

#endif