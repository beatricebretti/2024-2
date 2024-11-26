#ifndef CABALLERO_H
#define CABALLERO_H
#include "../Personaje.h"

class Caballero : public Personaje {
public:
    Caballero() : Personaje("C", 100, 30, 1, {'H', 'V'}, 3, 0) {}
};

#endif