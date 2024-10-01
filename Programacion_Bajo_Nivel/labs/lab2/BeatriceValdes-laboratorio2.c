#include <stdio.h>
#include <math.h>
#include <stdbool.h>

bool esPrimo (int numero);

int main () {
    int n;
    int numeros = 0;

    printf("Ingrese el número: "); scanf("%d", &n);
    int arregloN[n];

    printf("%d primeros números primos:\n", n);
    
    for (int i = 2; numeros < n; i++) {
        if(esPrimo(i)) {
            arregloN[numeros] = i;
            numeros++;
        }
    }     
    
    // Imprimir los números
    for (int i = 0; i < numeros; i++) {
        printf("%d ", arregloN[i]);
    }
    printf("\n");
    return 0;
}

bool esPrimo (int numero) {
    bool primo = true;
    int i = 2;
    while (i <= sqrt(numero)) {
        if (numero % i == 0) {
            primo = false;
            break;
        }
        i++;
    }
    return primo;    
}