#include <stdio.h>
#include <stdlib.h>
#include <time.h> // para poder llenar la lisra de forma aleatoria c:
#include "func.h"

// funciones oara llenado de listas
void llenarManual(int *lista, int largo);
void llenarAleatorio(int *lista, int largo);
void llenarFgets(int *lista, int largo);

int main() {
    int largo;
    printf("Ingresa tamaño de la lista: ");
    scanf("%d", &largo);
    int lista[largo];  
    getchar();//limpiar buffer
    int opcion;
    printf("Llenado de la lista:\n");
    printf("1. Manualmente\n");
    printf("2. Aleatorio\n");
    printf("3. Usando gets\n");
    scanf("%d", &opcion);
    getchar();

    switch(opcion) {
        case 1:
            llenarManual(lista, largo);
            break;
        case 2:
            llenarAleatorio(lista, largo);
            break;
        case 3:
            llenarFgets(lista, largo);
            break;
        default:
            return 1;
    }

    int suma_directa = sumaLista(lista, largo);
    int mayor_directo = mayorLista(lista, largo);
    printf("La suma directa es %d\n", suma_directa);
    printf("El mayor directo es %d\n", mayor_directo);

    int (*pfsuma)(int*, int) = sumaLista;
    int (*pfmayor)(int*, int) = mayorLista;
    int suma_puntero = pfsuma(lista, largo);
    int mayor_puntero = pfmayor(lista, largo);
    printf("La suma con punteros a funcion es %d\n", suma_puntero);
    printf("El mayor con punteros a funcion es %d\n", mayor_puntero);

    return 0;
}

void llenarManual(int *lista, int largo) {
    for(int i = 0; i < largo; i++) {
        printf("lista[%d]: ", i);
        scanf("%d", &lista[i]);
    }
}

void llenarAleatorio(int *lista, int largo) {
    srand(time(NULL));  
    for(int i = 0; i < largo; i++) {
        lista[i] = rand() % 100;
    }

    printf("[");
    for(int i = 0; i < largo; i++) {
        printf("%d", lista[i]);
        if (i < largo - 1) {
            printf(", ");
        }
    }
    printf("]\n");
}

void llenarFgets(int *lista, int largo) {
    char buffer[10];
    for(int i = 0; i < largo; i++) {
        printf("lista[%d]: ", i);
        fgets(buffer, sizeof(buffer), stdin);
        lista[i] = atoi(buffer); 
    }
}