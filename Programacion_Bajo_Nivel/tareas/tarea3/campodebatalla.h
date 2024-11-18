#include "personaje.h"
#include "soldado.h"
#include "arquero.h"
#include "caballero.h"
#include "heroe.h"
#include "medico.h"
#include "zombie.h"

#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>
#include <thread>
#include <chrono>

class CampoDeBatalla {
private:
    vector<Personaje*> oeste;
    vector<Personaje*> este;
    int largo;

public:
    CampoDeBatalla(int L) : largo(L) {
        generarPersonajes();
    }

    void generarPersonajes() {
        oeste.push_back(new Soldado());
        oeste.push_back(new Arquero());
        oeste.push_back(new Caballero());
        oeste.push_back(new Heroe());
        oeste.push_back(new Medico());
        
        este.push_back(new Zombie());
        este.push_back(new Zombie());
        este.push_back(new Zombie());
    }

    void mostrarCampo() {
        cout << "Campo de Batalla:" << endl;
        for (int i = 0; i < largo; ++i) {
            if (i < oeste.size()) {
                cout << oeste[i]->getCodigo() << " ";
            } else {
                cout << ". ";
            }
        }
        cout << endl;
        for (int i = 0; i < largo; ++i) {
            if (i < este.size()) {
                cout << este[i]->getCodigo() << " ";
            } else {
                cout << ". ";
            }
        }
        cout << endl;
    }

    void iniciarBatalla() {
        while (!oeste.empty() && !este.empty()) {
            cout << "\nTurno de los personajes:" << endl;
            for (auto& p : oeste) {
                p->actuar(este, oeste);
            }
            for (auto& p : este) {
                p->actuar(oeste, este);
            }
            mostrarCampo();
            std::this_thread::sleep_for(std::chrono::milliseconds(1000));
            oeste.erase(remove_if(oeste.begin(), oeste.end(), [](Personaje* p) { return p->getSaludActual() <= 0; }), oeste.end());
            este.erase(remove_if(este.begin(), este.end(), [](Personaje* p) { return p->getSaludActual() <= 0; }), este.end());
        }
        if (oeste.empty()) {
            cout << "Los zombies han ganado la batalla!" << endl;
        } else {
            cout << "Los personajes del oeste han ganado la batalla!" << endl;
        }
    }

    ~CampoDeBatalla() {
        for (auto& p : oeste) delete p;
        for (auto& p : este) delete p;
    }
};