#include "ensamblaje.h"
using namespace std;

int main() {
    Ensamblaje ensamblaje;

    ensamblaje.llenarComponentes();
    ensamblaje.operarEstacion1();
    ensamblaje.operarEstacion2();
    ensamblaje.operarEstacion3();
    ensamblaje.operarEstacion4();
    ensamblaje.mostrarResultados();
    ensamblaje.mostrarEstadoColas();

    return 0;
}