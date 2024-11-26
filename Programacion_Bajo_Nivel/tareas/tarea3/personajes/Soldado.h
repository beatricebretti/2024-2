#ifndef SOLDADO_H
#define SOLDADO_H
#include "../Personaje.h"

class Soldado : public Personaje {
public:
    Soldado() : Personaje("S", 50, 10, 1, {'H', 'V'}, 1, 0) {}
};

#endif