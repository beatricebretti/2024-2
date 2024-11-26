#include "Personaje.h"
#include <iostream>
#include <ctime>

using namespace std;

bool Personaje::puedeAtacarEnDireccion(char direccion) const {
    for (char dir : direccionesAtaque) {
        if (dir == direccion) return true;
    }
    return false;
}

void Personaje::actuar(Personaje* enemigo, char direccion) {
    if (!enemigo || !enemigo->estaVivo() || !puedeAtacarEnDireccion(direccion)) return;

    int danio = rand() % (fuerzaMax / 2) + (fuerzaMax / 2);
    enemigo->recibirDanio(danio);
    cout << codigo << " atacó a " << enemigo->getCodigo() << " y causó " << danio << " de daño en dirección " << direccion << ".\n";
}

void Personaje::desplazarse(vector<Personaje*>& bando, int& posicion) {
    int nuevaPosicion = posicion + desplazamientoMax;
    if (nuevaPosicion >= static_cast<int>(bando.size()))  
        nuevaPosicion = static_cast<int>(bando.size()) - 1;

    bool puedeMoverse = true;
    for (int i = posicion + 1; i <= nuevaPosicion; i++) {
        if (bando[i] != nullptr) {
            puedeMoverse = false;
            break;
        }
    }

    if (puedeMoverse) {
        bando[nuevaPosicion] = this;
        bando[posicion] = nullptr;
        posicion = nuevaPosicion;
        cout << codigo << " se ha movido a la posición " << nuevaPosicion << ".\n";
    }
}

void Personaje::recibirDanio(int danio) {
    salud -= danio;
    if (salud < 0) salud = 0;
}