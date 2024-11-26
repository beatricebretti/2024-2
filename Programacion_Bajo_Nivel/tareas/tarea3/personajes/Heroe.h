#ifndef HEROE_H
#define HEROE_H
#include "../Personaje.h"

class Heroe : public Personaje {
public:
    Heroe() : Personaje("H", 500, 30, 3, {'H', 'V', 'D'}, 4, 5) {}
};

#endif