#ifndef ARQUERO_H
#define ARQUERO_H
#include "../Personaje.h"

class Arquero : public Personaje {
public:
    Arquero() : Personaje("A", 50, 5, 3, {'H', 'V', 'D'}, 1, 0) {}
};

#endif