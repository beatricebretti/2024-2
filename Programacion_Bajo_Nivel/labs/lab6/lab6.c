#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct cuenta {
    char email[50];
    char password[50];
    struct cuenta *sig;
} cuenta;

void liberar(cuenta *inicio);

int main() {
    cuenta *primero = NULL;
    cuenta *actual = NULL;
    cuenta *nuevo = NULL;
    char respuesta;
    int totalCuentas = 0;

    do {
        nuevo = (cuenta*)malloc(sizeof(cuenta));
        printf("Ingrese usuario: "); scanf("%s", nuevo->email);
        printf("Ingrese clave: "); scanf("%s", nuevo->password);

        nuevo->sig = NULL; // es el priomero
        if (primero == NULL) {
            primero = nuevo;  
        } 
        else {
            actual->sig = nuevo; 
        }
        actual = nuevo; 
        totalCuentas++;
        if (totalCuentas >= 2) {
            printf("Desea ingresar mas usuarios: (S/N) "); scanf(" %c", &respuesta);
        } else {
            respuesta = 'S';
        }
    } while (respuesta == 'S' || respuesta == 's'); //por si lo ponen minuscula 

    actual = primero;
    printf("\n--Usuarios en el sistema--\n");
    while (actual != NULL) {
        printf("%s\n", actual->email);
        actual = actual->sig;
    }
    printf("Hay %d usuarios en el sistema.\n", totalCuentas);
    liberar(primero);
    return 0;
}

void liberar(cuenta *inicio) {
    cuenta *temp;
    while (inicio != NULL) {
        temp = inicio;
        inicio = inicio->sig;
        free(temp);
    }
}