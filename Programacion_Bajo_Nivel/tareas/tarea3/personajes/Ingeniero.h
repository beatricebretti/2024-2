#ifndef INGENIERO_H
#define INGENIERO_H
#include "../Personaje.h"

class Ingeniero : public Personaje {
public:
    Ingeniero() : Personaje("I", 30, 50, 4, {'H', 'V', 'D'}, 3, 20) {}
};

#endif