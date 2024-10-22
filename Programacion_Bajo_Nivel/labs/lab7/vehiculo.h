#include <string>
using namespace std;

class Vehiculo {
private:
    string patente;
    int agno;
    string marca;
    string modelo;
    double precioNuevo;
    int numeroInfracciones;

public:
    //constructor
    Vehiculo(string _patente, int _agno, string _marca, string _modelo, double _precioNuevo);

    double valorActual(int agnoActual);
    void agregaInfraccion();
    int getInfracciones() const;
    string getPatente() const;
    int getAgno() const;
    string getMarca() const;
    string getModelo() const;
};