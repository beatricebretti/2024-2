#ifndef TORRE_H
#define TORRE_H
#include "../Personaje.h"

class Torre : public Personaje {
public:
    Torre() : Personaje("T", 50, 30, 3, {'H', 'V'}, 0, 0) {}
};

#endif