#ifndef ENSAMBLAJE_H
#define ENSAMBLAJE_H

#include <queue>
#include <string>
#include <vector>
#include <iostream>

using namespace std;

class Ensamblaje {
    private:
        queue<string> colaCPU;
        queue<string> colaPlacaMadre;
        queue<string> colaRAM;
        queue<string> colaDiscoDuro;
        queue<string> colaFuentePoder;
        queue<string> colaTarjetaGrafica;
        queue<string> colaRefrigeracion;
        queue<string> colaGabinete;
        queue<string> colaCaja;
        vector<string> bodega; 
    
    public:
        Ensamblaje();
        void llenarComponentes();
        void operarEstacion1();
        void operarEstacion2();
        void operarEstacion3();
        void operarEstacion4();
        void mostrarResultados();
        void mostrarEstadoColas();
};

#endif