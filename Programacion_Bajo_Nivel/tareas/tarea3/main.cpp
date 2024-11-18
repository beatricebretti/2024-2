#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>
#include <thread>
#include <chrono>
#include "campodebatalla.h"

int main() {
    srand(time(nullptr));
    CampoDeBatalla campo(10);
    campo.mostrarCampo();
    campo.iniciarBatalla();
    return 0;
}