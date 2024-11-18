#include "ensamblaje.h"
using namespace std;

Ensamblaje::Ensamblaje() {
}

// llenar componentes en las colas 
void Ensamblaje::llenarComponentes() {
    for (int i = 1; i <= 50; i++) {
        colaCPU.push("CPU" + to_string(i));
        colaPlacaMadre.push("PM" + to_string(i));
        colaDiscoDuro.push("HD" + to_string(i));
        colaFuentePoder.push("PS" + to_string(i));
        colaTarjetaGrafica.push("GPU" + to_string(i));
        colaRefrigeracion.push("R" + to_string(i));
        colaGabinete.push("G" + to_string(i));
        colaCaja.push("E" + to_string(i));
    }
    for (int i = 1; i <= 100; i++) {
        colaRAM.push("RAM" + to_string(i));
    }
}

void Ensamblaje::operarEstacion1() {
    while (!colaCPU.empty() && !colaPlacaMadre.empty() && colaRAM.size() >= 2 && !colaDiscoDuro.empty()) {
        //llenar placa madre, cpu y 1 ram
        string ensamble =  colaCPU.front() + colaPlacaMadre.front() + colaRAM.front();
        colaRAM.pop();
        // agregar la otra ram
        ensamble += colaRAM.front();
        colaRAM.pop();
        // agregar disco duro
        ensamble += colaDiscoDuro.front();
        colaCPU.pop();
        colaPlacaMadre.pop();
        colaDiscoDuro.pop();

        bodega.push_back(ensamble);
    }
}

void Ensamblaje::operarEstacion2() {
    for (int i = 0; i < bodega.size(); i++) {
        if (!colaGabinete.empty() && !colaFuentePoder.empty()) {
            bodega[i] += colaGabinete.front() + colaFuentePoder.front();
            colaGabinete.pop();
            colaFuentePoder.pop();
        }
    }
}

void Ensamblaje::operarEstacion3() {
    for (int i = 0; i < bodega.size(); ++i) {
        if (!colaRefrigeracion.empty() && !colaTarjetaGrafica.empty()) {
            bodega[i] += colaRefrigeracion.front() + colaTarjetaGrafica.front();
            colaRefrigeracion.pop();
            colaTarjetaGrafica.pop();
        }
    }
}

void Ensamblaje::operarEstacion4() {
    for (int i = 0; i < bodega.size(); ++i) {
        if (!colaCaja.empty()) {
            bodega[i] += colaCaja.front();
            colaCaja.pop();
        }
    }
}

void Ensamblaje::mostrarResultados() {
    cout << "\nComputadores ensamblados en bodega:\n";
    for (int i = 0; i < bodega.size(); ++i) {
        cout << bodega[i] << endl;
    }
}

void Ensamblaje::mostrarEstadoColas() {
    cout << "\nEstado de las colas al final:\n";
    cout << "CPU: " << colaCPU.size() << "\n";
    cout << "Placa Madre: " << colaPlacaMadre.size() << "\n";
    cout << "RAM: " << colaRAM.size() << "\n";
    cout << "Disco Duro: " << colaDiscoDuro.size() << "\n";
    cout << "Fuente de Poder: " << colaFuentePoder.size() << "\n";
    cout << "Tarjeta Gráfica: " << colaTarjetaGrafica.size() << "\n";
    cout << "Refrigeración: " << colaRefrigeracion.size() << "\n";
    cout << "Gabinete: " << colaGabinete.size() << "\n";
    cout << "Cajas: " << colaCaja.size() << "\n";
}