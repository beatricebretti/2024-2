#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>
#include <thread>
#include <chrono>

#include "Personaje.h"
#include "personajes/Arquero.h"
#include "personajes/Caballero.h"
#include "personajes/Heroe.h"
#include "personajes/Soldado.h"
#include "personajes/Torre.h"
#include "personajes/Zombie.h"
#include "personajes/Ingeniero.h"
#include "personajes/Medico.h"

using namespace std;

void mostrarCampoBatalla(const vector<Personaje*>& oeste, const vector<Personaje*>& este);
void pausar(int ms);
Personaje* crearPersonajeAleatorio();
int contarPersonajesVivos(const vector<Personaje*>& bando);

int main() {
    srand(static_cast<unsigned>(time(0)));

    int largoCampo = 20;
    vector<Personaje*> bandoOeste(largoCampo, nullptr);
    vector<Personaje*> bandoEste(largoCampo, nullptr);

    for (int i = 0; i < largoCampo / 2; ++i) {
        bandoOeste[i] = crearPersonajeAleatorio();
        bandoEste[i] = crearPersonajeAleatorio();
    }

    while (contarPersonajesVivos(bandoOeste) > 0 && contarPersonajesVivos(bandoEste) > 0) {
        for (int i = 0; i < static_cast<int>(bandoOeste.size()); ++i) {  
            if (bandoOeste[i] && bandoOeste[i]->estaVivo()) {
                char direccion = bandoOeste[i]->getCodigo() == "S" ? 'H' : 'D';
                bandoOeste[i]->actuar(bandoEste[rand() % bandoEste.size()], direccion);
                bandoOeste[i]->desplazarse(bandoOeste, i);
            }
        }

        for (int i = 0; i < static_cast<int>(bandoEste.size()); ++i) {  
            if (bandoEste[i] && bandoEste[i]->estaVivo()) {
                char direccion = bandoEste[i]->getCodigo() == "S" ? 'H' : 'D';
                bandoEste[i]->actuar(bandoOeste[rand() % bandoOeste.size()], direccion);
                bandoEste[i]->desplazarse(bandoEste, i);
            }
        }

        mostrarCampoBatalla(bandoOeste, bandoEste);
        pausar(1000); // Pausa de 1 segundo
    }

    if (contarPersonajesVivos(bandoOeste) > 0) {
        cout << "¡El bando Oeste ha ganado!\n";
    } else if (contarPersonajesVivos(bandoEste) > 0) {
        cout << "¡El bando Este ha ganado!\n";
    } else {
        cout << "¡Es un empate!\n";
    }

    for (Personaje* personaje : bandoOeste) delete personaje;
    for (Personaje* personaje : bandoEste) delete personaje;

    return 0;
}

Personaje* crearPersonajeAleatorio() {
    int tipo = rand() % 7;
    switch (tipo) {
        case 0: return new Soldado();
        case 1: return new Arquero();
        case 2: return new Caballero();
        case 3: return new Torre();
        case 4: return new Heroe();
        case 5: return new Zombie();
        case 6: return new Medico();
        case 7: return new Ingeniero();
    }
    return nullptr;
}

void mostrarCampoBatalla(const vector<Personaje*>& oeste, const vector<Personaje*>& este) {
    cout << "Oeste     Este\n";
    for (size_t i = 0; i < oeste.size(); ++i) {
        if (oeste[i] && oeste[i]->estaVivo()) cout << oeste[i]->getCodigo() << " " << oeste[i]->getSalud() << " ";
        else cout << "   ";
        cout << "     ";
        if (este[i] && este[i]->estaVivo()) cout << este[i]->getCodigo() << " " << este[i]->getSalud();
        cout << "\n";
    }
}

void pausar(int ms) {
    this_thread::sleep_for(chrono::milliseconds(ms));
}

int contarPersonajesVivos(const vector<Personaje*>& bando) {
    int contador = 0;
    for (const Personaje* personaje : bando) {
        if (personaje && personaje->estaVivo()) {
            contador++;
        }
    }
    return contador;
}