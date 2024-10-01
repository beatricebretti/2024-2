#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void convertir_romano(int numero, char *resultado);

int main(int argc, char *argv[]) {
    //revisamos si se ingreso el numero en la linea de comando
    if (argc == 2) {
        int numero = atoi(argv[1]);
        if (numero < 0 || numero > 99999) {
            printf("Debe ser un entero entre 0-99999\n");
            return 1;
        }
        if (numero == 0) {
            printf("0 no tiene representacion en romano\n");
        } 
        else {
            char resultado[100] = "";
            convertir_romano(numero, resultado);
            printf("%d en romano es: %s\n", numero, resultado);
        }
    }
    //si no se ingresa como linea de comando 
    else {
        char continuar;
        do {
            char input[100];
            printf("Ingresar un numero entero: "); scanf("%s", input);

            int numero = atoi(input);
            if (numero < 0 || numero > 99999) {
                printf("Debe ser un entero entre 0-99999\n");
                return 1;
            }
            if (numero == 0) {
                printf("0 no tiene representacion en romanos\n");
                return 1;
            } 
            else {
                char resultado[100] = "";
                convertir_romano(numero, resultado);
                printf("%d en romano es: %s\n", numero, resultado);
            }

            printf("Convertir otro numero?(y/n): "); scanf(" %c", &continuar);
        } while (continuar == 'y');
    }

    return 0;
}

void convertir_romano(int numero, char *resultado) {
    int entero[] = {100000, 90000, 50000, 40000, 10000, 9000, 5000, 4000, 1000, 900, 500, 400, 100, 90, 50, 40, 10, 9, 5, 4, 1};
    char *romano[] = {"_C", "_X_C", "_L", "_X_L", "_X", "M_X", "_V", "M_V", "M", "CM", "D", "CD", "C", "XC", "L", "XL", "X", "IX", "V", "IV", "I"};
    
    int i = 0;
    while (numero > 0) {
        while (numero >= entero[i]) {
            strcat(resultado, romano[i]);
            numero -= entero[i];
        }
        i++;
    }
}

