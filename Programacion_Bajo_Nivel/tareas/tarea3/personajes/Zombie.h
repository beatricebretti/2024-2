#ifndef ZOMBIE_H
#define ZOMBIE_H
#include "../Personaje.h"

class Zombie : public Personaje {
public:
    Zombie() : Personaje("Z", 50, 10, 1, {'H', 'V', 'D'}, 1, 0) {}
};

#endif