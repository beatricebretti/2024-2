#include <string.h>
#include <stdio.h>

// caracteres de la tabla adjunta
char *tableMorse[36] = {
    ".-", "-...", "-.-.", "-..", ".", "..-.", "--.", "....", "..", ".---", "-.-", ".-..", "--", "-.",
    "---", ".--.", "--.-", ".-.", "...", "-", "..-", "...-", ".--", "-..-", "-.--", "--..", 
    "-----", ".----", "..---", "...--", "....-", ".....", "-....", "--...", "---..", "----."
};
// correspondencia con los de la tabla
char letras[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789";

// funciones
const char* morse(char letra); 

int main(int argc, char *argv[]) {
    if (argc < 2) {  
        printf("Error de parámetro\n");
        return 1;
    }

    const char *texto = argv[1];
    for (int i = 1; i < argc; i++) {
        char *texto = argv[i];
        for (int j = 0; j < strlen(texto); j++) {
            if (morse(texto[j])) { // verificara si esta en la tabla entregada
                printf("%s ", morse(texto[j]));  
            }
        }
        if(i != argc - 1){
            printf("/ ");
        }
    }
    printf("\n");
    return 0;
}

const char* morse(char letra) {
    // transformar a mayúscula para que calce
    if (letra >= 'a' && letra <= 'z') {
        letra = letra - 'a' + 'A'; //distancia entre may y min
    }
    
    for (int i = 0; i < 36; i++) {
        if (letras[i] == letra) {
            return tableMorse[i];
        }
    }
    return NULL;
}