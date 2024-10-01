#include <stdio.h>

int main() {
    const int CAPACIDADWH = 15000; 
    const int EQKHW = 1000; // 1Kwh = 1000wh
    int saldoInicial;
    int recarga;
    int consumo;
    int carga = 0;
    float porcentajeCarga; 
    unsigned short opcionMenu = 0;

    printf("Ingrese el nivel inicial (Kwh): ");
    scanf("%u", &saldoInicial);
    if((saldoInicial * EQKHW) > CAPACIDADWH) { // en caso de que supere los 15Kwh
        saldoInicial = CAPACIDADWH / EQKHW;
        printf("Saldo inicial seteado a 15 Kwh, máximo de la batería.\n");
    }

    carga += (saldoInicial * EQKHW);

    do {
        printf("Menú principal\n");
        printf("\t1) Mostrar saldo\n");
        printf("\t2) Recargar baterías\n");
        printf("\t3) Consumir electricidad\n");
        printf("\t4) Salir\n");
        printf("Ingrese opción: ");
        scanf("%hu", &opcionMenu);

        switch (opcionMenu) {
            case 1: // Mostrar saldo
                porcentajeCarga = ((carga * 100) / CAPACIDADWH);
                printf("Hay %i wh, %.0f%% de carga.\n\n", carga, porcentajeCarga);
                break;
            case 2: // Recargar baterías
                printf("Ingrese Kwh recargar: ");
                scanf("%u", &recarga);
                recarga = recarga * EQKHW;
                if((recarga + carga) > CAPACIDADWH) {
                    recarga = CAPACIDADWH - carga;
                }
                carga += recarga;
                printf("%i wh cargados\n\n", recarga);
                break;
            case 3: // Consumir electricidad
                printf("Ingrese el consumo en Kwh: ");
                scanf("%u", &consumo);
                consumo = consumo * EQKHW;
                if(consumo > carga) {
                    consumo = carga;
                }
                carga -= consumo;
                printf("Consumo realizado de %i wh\n\n", consumo);
                break;
            default:
                break;
        }
    } while (opcionMenu != 4);

    printf("\nEl contenedor quedó con %i wh.\n\n", carga);
    return 0;
}