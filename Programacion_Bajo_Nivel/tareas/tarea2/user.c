#include <stdio.h>
#include "user.h"

void mostrarMensajeLlegada(Vehiculo *vehiculo, int tiempo_actual) {
    char tiempo_formateado[6];
    convertirTiempo(tiempo_actual, tiempo_formateado);

    char *tipo_vehiculo;
    if (vehiculo->tipo == 'A') {
        tipo_vehiculo = "Auto";
    } 
    else if (vehiculo->tipo == 'C') {
        tipo_vehiculo = "Camión";
    } 
    else {
        tipo_vehiculo = "Bus";
    }
    printf("%s %s ha llegado a la fila de la ribera a las %s\n", tipo_vehiculo, vehiculo->id, tiempo_formateado);
}

void mostrarMensajeCarga(Vehiculo *vehiculo, int tiempo_actual) {
    char tiempo_formateado[6];
    convertirTiempo(tiempo_actual, tiempo_formateado);

    char *tipo_vehiculo;
    if (vehiculo->tipo == 'A') {
        tipo_vehiculo = "Auto";
    } 
    else if (vehiculo->tipo == 'C') {
        tipo_vehiculo = "Camión";
    } 
    else {
        tipo_vehiculo = "Bus";
    }
    printf("%s %s ha sido cargado al ferry a las %s\n", tipo_vehiculo, vehiculo->id, tiempo_formateado);
}

void mostrarMensajeZarpe(char ribera_origen, int tiempo_actual) {
    char tiempo_formateado[6];
    convertirTiempo(tiempo_actual, tiempo_formateado);
    printf("\n\n--Navegacion--\n\nEl ferry ha zarpado desde la ribera %c a las %s\n", ribera_origen, tiempo_formateado);
}

void mostrarMensajeLlegadaFerry(char ribera_destino, int tiempo_actual) {
    char tiempo_formateado[6];
    convertirTiempo(tiempo_actual, tiempo_formateado);
    printf("\n\n--Llegada--\n\nEl ferry ha llegado a la ribera %c a las %s\n", ribera_destino, tiempo_formateado);
}

void mostrarMensajeDescarga(Vehiculo *vehiculo, int tiempo_actual) {
    char tiempo_formateado[6];
    convertirTiempo(tiempo_actual, tiempo_formateado);

    char *tipo_vehiculo;
    if (vehiculo->tipo == 'A') {
        tipo_vehiculo = "Auto";
    } 
    else if (vehiculo->tipo == 'C') {
        tipo_vehiculo = "Camión";
    } 
    else {
        tipo_vehiculo = "Bus";
    }
    printf("%s %s ha sido descargado en la ribera destino a las %s\n", tipo_vehiculo, vehiculo->id,tiempo_formateado);
}

void mostrarCantidadVehiculosRibera(char ribera, int cantidad) {
    printf("\nCantidad de vehículos en la ribera %c: %d\n\n", ribera, cantidad);
}