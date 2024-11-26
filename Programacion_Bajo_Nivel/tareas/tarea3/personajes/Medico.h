#ifndef MEDICO_H
#define MEDICO_H
#include "../Personaje.h"

class Medico : public Personaje {
public:
    Medico() : Personaje("M", 30, 0, 0, {}, 3, 15) {}
};

#endif