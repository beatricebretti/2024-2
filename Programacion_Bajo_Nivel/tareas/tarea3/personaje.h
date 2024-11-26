#ifndef PERSONAJE_H
#define PERSONAJE_H

#include <string>
#include <vector>
#include <cstdlib>

using namespace std;

class Personaje {
protected:
    string codigo;
    int salud;
    int fuerzaMax;
    int alcanceMax;
    vector<char> direccionesAtaque; 
    int desplazamientoMax;
    int curacion;

public:
    Personaje(string codigo, int salud, int fuerzaMax, int alcanceMax, vector<char> direccionesAtaque, int desplazamientoMax, int curacion)
        : codigo(codigo), salud(salud), fuerzaMax(fuerzaMax), alcanceMax(alcanceMax), direccionesAtaque(direccionesAtaque), desplazamientoMax(desplazamientoMax), curacion(curacion) {}
    
    virtual ~Personaje() = default;

    virtual void actuar(Personaje* enemigo, char direccion);
    virtual void desplazarse(vector<Personaje*>& bando, int& posicion);
    bool puedeAtacarEnDireccion(char direccion) const;
    int getSalud() const { return salud; }
    std::string getCodigo() const { return codigo; }
    void recibirDanio(int danio);
    bool estaVivo() const { return salud > 0; }
};

#endif