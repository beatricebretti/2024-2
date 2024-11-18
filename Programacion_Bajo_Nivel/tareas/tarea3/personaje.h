#ifndef PERSONAJE_H
#define PERSONAJE_H

#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>
#include <thread>
#include <chrono>
#include <string>

using namespace std;

class Personaje {
protected:
    char codigo;
    string nombre;
    int saludBase;
    int saludActual;
    int fuerzaMax;
    int alcanceMax;
    string direccionAtaque;
    int desplazamientoMax;
    int curacion;

public:
    Personaje(char cod, string nom, int salud, int fuerza, int alcance, string direccion, int desplazamiento, int curar)
        : codigo(cod), nombre(nom), saludBase(salud), saludActual(salud), fuerzaMax(fuerza), alcanceMax(alcance),
          direccionAtaque(direccion), desplazamientoMax(desplazamiento), curacion(curar) {}

    virtual void actuar(vector<Personaje*>& enemigos, vector<Personaje*>& aliados) = 0;
    virtual void desplazarse(int nuevaPos) = 0;
    
    char getCodigo() const { return codigo; }
    int getSaludActual() const { return saludActual; }
    void recibirDanio(int danio) { saludActual -= danio; }
    void curar(int cantidad) { 
        saludActual += cantidad; 
        if (saludActual > saludBase) saludActual = saludBase; 
    }
    int getFuerzaMax() const { return fuerzaMax; }
    int getAlcanceMax() const { return alcanceMax; }
    int getDesplazamientoMax() const { return desplazamientoMax; }
};

#endif