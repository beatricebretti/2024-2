#include <stdio.h>
#include <stdlib.h>

float encontrar_minimo(float* notas, int n);
float encontrar_maximo(float* notas, int n);
float calcular_promedio(float* notas, int n);

int main() {
    int n;
    printf("Cuantas notas quiere ingresar?: ");
    scanf("%d", &n);

    if (n < 5 || n > 12) {
        printf("Número de notas inválido\n");
        return 1;  
    }

    float* notas = (float*) malloc(n * sizeof(float));

    for (int i = 0; i < n; i++) {
        printf("Ingrese nota %d: ", i + 1);
        scanf("%f", &notas[i]);
    }

    float min = encontrar_minimo(notas, n);
    float max = encontrar_maximo(notas, n);
    float promedio = calcular_promedio(notas, n);

    printf("Mínima = %.1f\n", min);
    printf("Promedio = %.1f\n", promedio);
    printf("Máximo = %.1f\n", max);

    FILE *archivo = fopen("notas.txt", "w");
    if (archivo == NULL) {
        printf("Error al abrir el archivo\n");
        free(notas);  
        return 1;
    }

    fprintf(archivo, "Notas ingresadas:\n");
    for (int i = 0; i < n; i++) {
        fprintf(archivo, "Nota %d: %.1f\n", i + 1, notas[i]);
    }
    fclose(archivo);
    free(notas);

    return 0;
}

float encontrar_minimo(float* notas, int n) {
    float min = notas[0];
    for (int i = 1; i < n; i++) {
        if (notas[i] < min) {
            min = notas[i];
        }
    }
    return min;
}

float encontrar_maximo(float* notas, int n) {
    float max = notas[0];
    for (int i = 1; i < n; i++) {
        if (notas[i] > max) {
            max = notas[i];
        }
    }
    return max;
}

float calcular_promedio(float* notas, int n) {
    float suma = 0;
    for (int i = 0; i < n; i++) {
        suma += notas[i];
    }
    return suma / n;
}
