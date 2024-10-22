#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "user.h"

// variables globales ------------------------------------------------------------------------------------------------------------------------
const int MAX_METROS = 100;
const int FRECUENCIAS[16] = {10, 10, 20, 50, 60, 30, 30, 15, 30, 50, 60, 70, 30, 30, 10, 10};

Vehiculo *riberaN = NULL;
Vehiculo *riberaS = NULL;
Vehiculo *ferry = NULL;

int capacidadN = 10;
int capacidadS = 10;
int capacidadFerry = 10;
int cantidadN = 0;
int cantidadS = 0;
int cantidadFerry = 0;

int tiempo_actual = 7 * 60;
int suma_tiempos_cruce = 0;
int cantidad_vehiculos_cruzados = 0;

// declaracion funciones ------------------------------------------------------------------------------------------------------------------------
/* void agregarVehiculo(Vehiculo *ribera, Vehiculo vehiculo, int *cantidad, int capacidad)
 * agregar un vehículo a una ribera
 * Parametros: Vehiculo *ribera, Vehiculo vehiculo, int *cantidad, int capacidad
 */
void agregarVehiculo(Vehiculo *ribera, Vehiculo vehiculo, int *cantidad, int capacidad);

/* Vehiculo crearVehiculo(int hora_actual, char ribera)
 * para crear vehículos aleatorios con probabilidades
 * Parametros: int hora_actual, char ribera
 * Return: Vehiculo nuevo
 */
Vehiculo crearVehiculo(int hora_actual, char ribera);

/* void cruzarFerry(Vehiculo *ribera_origen, Vehiculo *ribera_destino, int *cantidad_origen, int *cantidad_destino, int capacidad_destino)
 * simular cruce del ferry
 * Parametros: Vehiculo *ribera_origen, Vehiculo *ribera_destino, int *cantidad_origen, int *cantidad_destino, int capacidad_destino
 */
void cruzarFerry(Vehiculo *ribera_origen, Vehiculo *ribera_destino, int *cantidad_origen, int *cantidad_destino, int capacidad_destino, char ribera_origen_id);

/* void inicializarMemoria()
 * inicializar la memoria de las riberas y el ferry
 */
void inicializarMemoria();

/* void liberarMemoria()
 * liberar memoria al final
 */
void liberarMemoria();

// definicion funciones ------------------------------------------------------------------------------------------------------------------------
int main() {
    srand(time(NULL));
    inicializarMemoria();

    int index_frecuencia = (tiempo_actual / 60) - 6; 

    while (tiempo_actual <= (21 * 60)) {
        int frecuencia = FRECUENCIAS[index_frecuencia];
        int limite_inferior = (int)(frecuencia * 0.85);
        int limite_superior = (int)(frecuencia * 1.15);

        // numero aleatorio de llegada vehiculos
        int cantidad_llegandoN = rand() % (limite_superior - limite_inferior + 1) + limite_inferior;
        int cantidad_llegandoS = rand() % (limite_superior - limite_inferior + 1) + limite_inferior;
        // norte
        for (int i = 0; i < cantidad_llegandoN && cantidadN < capacidadN; i++) {
            Vehiculo vN = crearVehiculo(tiempo_actual, 'N');
            agregarVehiculo(riberaN, vN, &cantidadN, capacidadN);
            mostrarMensajeLlegada(&vN, tiempo_actual);
        }
        // sur
        for (int i = 0; i < cantidad_llegandoS && cantidadS < capacidadS; i++) {
            Vehiculo vS = crearVehiculo(tiempo_actual, 'S');
            agregarVehiculo(riberaS, vS, &cantidadS, capacidadS);
            mostrarMensajeLlegada(&vS, tiempo_actual);
        }

        // cruce desde norte
        if (tiempo_actual % 60 == 0) {
            mostrarCantidadVehiculosRibera('N', cantidadN);
            cruzarFerry(riberaN, riberaS, &cantidadN, &cantidadS, capacidadS, 'N');
        }
        // cruce desde sur
        if ((tiempo_actual + 30) % 60 == 0) {
            mostrarCantidadVehiculosRibera('S', cantidadS);
            cruzarFerry(riberaS, riberaN, &cantidadS, &cantidadN, capacidadN, 'S');
        }
        tiempo_actual += 10;
        index_frecuencia = (tiempo_actual / 60) - 6;
    }

    // tiempo promedio
    if (cantidad_vehiculos_cruzados > 0) {
        int promedio_cruce = suma_tiempos_cruce / cantidad_vehiculos_cruzados;
        printf("\n---Tiempo promedio de cruce: %d minutos---\n", promedio_cruce);
    } 
    else {
        printf("ninguno\n");
    }
    liberarMemoria(); 
    return 0;
}

void agregarVehiculo(Vehiculo *ribera, Vehiculo vehiculo, int *cantidad, int capacidad) {
    if (*cantidad >= capacidad) {
        printf("Error\n");
        return;
    }
    ribera[*cantidad] = vehiculo;
    (*cantidad)++;
}

Vehiculo crearVehiculo(int hora_actual, char ribera) {
    Vehiculo nuevo;
    int probabilidad = rand() % 100;

    if (probabilidad < 70){
        nuevo.tipo = 'A'; 
    } 
    else if (probabilidad < 90) {
        nuevo.tipo = 'C';
    }  
    else {
        nuevo.tipo = 'B';
    }  

    snprintf(nuevo.id, 6, "%c%05d", ribera, rand() % 10000);
    nuevo.hora_llegada = hora_actual;
    return nuevo;
}

void cruzarFerry(Vehiculo *ribera_origen, Vehiculo *ribera_destino, int *cantidad_origen, int *cantidad_destino, int capacidad_destino, char ribera_origen_id) {
    int espacio_disponible = MAX_METROS;
    int vehiculos_cargados = 0;

    for (int i = 0; i < *cantidad_origen; i++) {
        int longitud_vehiculo;
        if (ribera_origen[i].tipo == 'A') {
            longitud_vehiculo = 4;
        } 
        else if (ribera_origen[i].tipo == 'C') {
            longitud_vehiculo = 20;
        } 
        else {
            longitud_vehiculo = 30;
        }

        if (longitud_vehiculo <= espacio_disponible && cantidadFerry < capacidadFerry) {
            espacio_disponible -= longitud_vehiculo;
            ferry[cantidadFerry++] = ribera_origen[i];
            vehiculos_cargados++;
            mostrarMensajeCarga(&ribera_origen[i], tiempo_actual);

            for (int j = i; j < *cantidad_origen - 1; j++) {
                ribera_origen[j] = ribera_origen[j + 1];
            }
            (*cantidad_origen)--;
            i--;
        }
    }

    mostrarMensajeZarpe(ribera_origen_id, tiempo_actual);
    tiempo_actual += 20;
    mostrarMensajeLlegadaFerry(ribera_origen_id == 'N' ? 'S' : 'N', tiempo_actual);

    for (int i = 0; i < vehiculos_cargados; i++) {
        if (*cantidad_destino < capacidad_destino) {
            ribera_destino[*cantidad_destino] = ferry[i];
            (*cantidad_destino)++;

            int tiempo_cruce = tiempo_actual - ferry[i].hora_llegada;
            suma_tiempos_cruce += tiempo_cruce;
            cantidad_vehiculos_cruzados++;

            mostrarMensajeDescarga(&ferry[i], tiempo_actual);
        }
    }
    cantidadFerry = 0;
}

void inicializarMemoria() {
    riberaN = (Vehiculo *)malloc(capacidadN * sizeof(Vehiculo));
    riberaS = (Vehiculo *)malloc(capacidadS * sizeof(Vehiculo));
    ferry = (Vehiculo *)malloc(capacidadFerry * sizeof(Vehiculo));
}

void liberarMemoria() {
    free(ferry);
    free(riberaN);
    free(riberaS);
}

void convertirTiempo(int minutos, char *resultado) {
    int horas = minutos / 60;
    int minutos_resto = minutos % 60;
    snprintf(resultado, 6, "%02d:%02d", horas, minutos_resto);
}