#include <stdio.h>

int mayorLista(int *lista, int largo) {
    int mayor = lista[0];
    for(int i = 1; i < largo; i++) {
        if(lista[i] > mayor) {
            mayor = lista[i];
        }
    }
    return mayor;
}

int sumaLista(int *lista, int largo) {
    int suma = 0;
    for(int i = 0; i < largo; i++) {
        suma += lista[i];
    }
    return suma;
}
