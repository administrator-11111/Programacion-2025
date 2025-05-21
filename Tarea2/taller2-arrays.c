/*Detalles:
-Primeros 10 min gratis
-Siguientes 15 min $3
-Primera hora $10
-Cada hora subsecuente $5
-A partir de la primera hora se cobran horas completas
-Si es Domingo se hace descuento de 10% sobre el monto total
*Leer minutos y horas e impromor ciantp se costora
*/
#include <stdio.h>
#define LIMITE_ESTACIONAMIENTO 5
float CalcularCosto(int, int, int);

int main() {
    int horas, minutos, descuento, finalizar = 1, i = 0, ingresados = 0, tiempo_vehiculo[LIMITE_ESTACIONAMIENTO];
    float costo_vehiculo[LIMITE_ESTACIONAMIENTO];
    for(int i = 0; i < LIMITE_ESTACIONAMIENTO; i++) {
        costo_vehiculo[i] = 0;
        tiempo_vehiculo[i] = 0;
    }

    printf("=====================================\n");
    printf("== ADMINISTRADOR DE ESTACIONAMIENTO\n");
    printf("=====================================\n");
    printf("-------------------------------------\n");
    printf("¨Es d¡a domingo? (Escriba '1' para responder SI y cualquiero otro numero para responder NO): ");
    scanf("%d", &descuento);
    if (descuento == 1) {
        printf("Respondiste SI, por lo tanto habr  un descuento del %%10 al total del costo del estacionamiento de los veh¡culos que ingreses.\n");
    } else { 
        printf("Se registr¢ tu respuesta 'no'.\n");
    }
    printf("-------------------------------------\n");
    while (finalizar != 0) {
        while(i < LIMITE_ESTACIONAMIENTO) {
            printf("== INFORMACIàN DEL VEHÖCULO '%d'.\n", i+1);
            printf("Ingrese la cantidad de horas que estuvo estacionado el veh¡culo %d: ", i+1);
            scanf("%d", &horas);
            if (horas >= 0) {
                tiempo_vehiculo[i] += 60*horas;
                printf("Ingrese la cantidad de minutos que estuvo estacionado el veh¡culo %d: ", i+1);
                scanf("%d", &minutos);
                if (minutos >= 0) {
                    tiempo_vehiculo[i] += minutos;
                    costo_vehiculo[i] = CalcularCosto(horas, minutos, descuento);
                    printf("Veh¡culo %d registrado correctamente.\n", i+1);
                    i++;
                    ingresados++;
                    if (i < LIMITE_ESTACIONAMIENTO) {
                        printf("¨Desea ingresar otro veh¡culo? (Escriba '1' para responder SI y cualquiero otro n£mero para responder NO.): ");
                        scanf("%d", &finalizar);
                        if (finalizar == 1) {
                            printf("Respondiste 's¡'.\n");
                        } else {
                            finalizar = 0;
                            i = LIMITE_ESTACIONAMIENTO;
                            printf("Respondiste 'no'.\n");
                        }
                    }
                    printf("-------------------------------------\n");
                } else {
                    printf("La cantidad de minutos ingresados es inv lida (Debe ser mayor o igual que 0).\n");
                }
            } else {
                printf("La cantidad de horas ingresadas es inv lida (Debe ser mayor o igual que 0).\n");
            }
        }
        finalizar = 0;
    }

    printf("|| [0]Veh¡culo\t[%8d]Horas/min\t[%8d]Costo($)\n", 1, 1);
    printf("-------------------------------------\n");
    for(int i = 0; i < ingresados; i++) {
        printf("|| Veh¡culo %d: %8d horas, %2d min\t%8.2f$\n", i+1, tiempo_vehiculo[i]/60, tiempo_vehiculo[i]%60, costo_vehiculo[i]);
    }
    return 0;
}

float CalcularCosto(int horas, int minutos, int descuento) {
    float costo = 0.0;
    if (horas > 0) {
        minutos += horas*60;
        horas = 0;
    }
    if (minutos > 0) {
        if (minutos < 60) {
            if (minutos <= 10) {
                costo = 0.0;
            } else {
                if (minutos <= (10+15)) {
                    costo += 3.0;
                }
            }
        } else {
            costo += 10.0;
            if ((minutos/60) > 0) {
                costo +=5.0*((minutos-60)/60);
            }
        }
        if (descuento == 1) {
            costo *= 0.10;
        }
    }
    if (minutos >= 60) {
        horas += minutos/60;
        minutos -= (minutos/60)*60;
    }
    return costo;
}