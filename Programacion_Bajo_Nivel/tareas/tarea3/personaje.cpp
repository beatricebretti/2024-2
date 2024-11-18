#include "personaje.h"
#include <iostream>
#include <cstdlib> 

void Personaje::actuar() {
    // Lógica de acción del personaje (ataque, curación, etc.)
}

void Personaje::desplazarse() {
    // Lógica de desplazamiento del personaje
}

void Personaje::recibirDanio(int danio) {
    salud -= danio;
    if (salud < 0) salud = 0;
}