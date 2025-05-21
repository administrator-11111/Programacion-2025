#include <stdio.h>
#define MAX_AUTOS 10

int main() {

    int finalizar = 0, i;
    char vehiculos[MAX_AUTOS][10];
    while (finalizar == 0) {
        for(i = 0; i < MAX_AUTOS; i++) {
            printf("Ingrese la patente de su vehículo(Ejemplo: ABC123): ");
            scanf("%c", &vehiculos[i]);
            if (vehiculos[i][6] != "") {
                printf("La patente ingresada debe contener hasta 6 carácteres.");
            }
        }
    }
    return 0;
}