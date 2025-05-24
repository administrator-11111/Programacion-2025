
#include <stdio.h>
#define LIMITE_ESTACIONAMIENTO 5
#define DIAS_MES    30
#define MES_ACTUAL    "5"
#define ANO_ACTUAL    "2025"
#define DESCUENTO     (0.90)

float CalcularCosto(int, int);
int CalcularFechaFinal(int, int, int, int);
int PreguntarEsDomingo();
int PreguntarDiaMes();
int ContinuarRegistrando();

int main() {
    int descuento, finalizar = 1, i = 0, ingresados;
    int dia[LIMITE_ESTACIONAMIENTO], hora[LIMITE_ESTACIONAMIENTO], minutos[LIMITE_ESTACIONAMIENTO], tiempo_vehiculo[LIMITE_ESTACIONAMIENTO];
    float costo_vehiculo[LIMITE_ESTACIONAMIENTO], ganancia_diaria[DIAS_MES];;
    for (int x = 0; x < DIAS_MES; x++) {
        ganancia_diaria[x] = 0.0f;
        ingresados = 0;
    }
    printf("=====================================\n");
    printf("== ADMINISTRADOR DE ESTACIONAMIENTO\n");
    printf("=====================================\n\n");

    while (finalizar != 0) {
        while(i < LIMITE_ESTACIONAMIENTO) {
            printf("== REGISTRO DE VEHÖCULO '%d'.\n", i+1);
            dia[i] = PreguntarDiaMes();
            if (dia[i] < 1 || dia[i] > 30) {
                printf("El d¡a ingresado no es v lido, vuelva a intentarlo.\n");
                continue;
            }
            descuento = PreguntarEsDomingo();   
            printf("Escriba la hora de ingreso (0-23) del veh¡culo: ");
            scanf("%d", &hora[i]);
            if (hora[i] >= 0 && hora[i] <= 23) {
                printf("Hora ingresada, ahora escriba los minutos (0-59): ");
                scanf("%d", &minutos[i]);
                if (minutos[i] >= 0 && minutos[i] <= 59) {
                    printf("Hora de ingreso registrada correctamente: %02d:%02d\n\n", hora[i], minutos[i]);
                    
                    printf("Ingrese la cantidad de minutos que estuvo estacionado el veh¡culo: ", i);
                    scanf("%d", &tiempo_vehiculo[i]);
                    if (tiempo_vehiculo[i] > 0) {
                        costo_vehiculo[i] = CalcularCosto(tiempo_vehiculo[i], descuento);
                        ganancia_diaria[(dia[i] - 1)] += costo_vehiculo[i];
                        printf("Veh¡culo %d registrado correctamente.\n", i+1);
                        ingresados++;
                        i++;
                        if (i < LIMITE_ESTACIONAMIENTO) {
                            finalizar = ContinuarRegistrando();
                            if (finalizar == 0) {
                                i = LIMITE_ESTACIONAMIENTO;
                            }
                        }
                    } else{
                        printf("El tiempo ingresado no es v lido.");
                    }
                } else {
                    printf("Minuto inv lido.");
                }
            } else {
                printf("Hora inv lida.\n");
            }
        }
        finalizar = 0;
    }
    
    printf("===== RESUMEN DE INGRESOS DIARIO =====\n");
    printf("== (Solo se muestran d¡as que que hubo ingresos)\n");
    for(int i = 0; i < DIAS_MES; i++) {
        if (ganancia_diaria[i] >= 1.0) {
            printf("%2d/"MES_ACTUAL"/"ANO_ACTUAL": $%.2f\n", i + 1, ganancia_diaria[i]);
        }
    }
    printf("\n::::: RESUMEN MENSUAL :::::\n");
    for (int d = 0; d < DIAS_MES; d++) {
        printf(":: DÖA %02d\n", d + 1);
        int autos_registrados = 0;
        for (int j = 0; j < ingresados; j++) {
            if (dia[j] == (d + 1)) {
                int salida = CalcularFechaFinal(dia[j], hora[j], minutos[j], tiempo_vehiculo[j]);
                printf("::: Ingreso: %02d/"MES_ACTUAL"/"ANO_ACTUAL" a las %02d hrs, %02d min.\n", dia[j], hora[j], minutos[j]);
                printf("::: Tiempo: %d hrs, %d min\n", (tiempo_vehiculo[j] / 60), (tiempo_vehiculo[j] % 60)); 
                printf("::: Salida: %02d/"MES_ACTUAL"/"ANO_ACTUAL" a las %02d hrs, %02d min.\n", (salida / 10000), ((salida / 100) % 100), (salida % 100));
                printf("::: Costo: $%.2f\n", costo_vehiculo[j]);   
                autos_registrados++;
            }
        }
        if (autos_registrados == 0) {
            printf("::: No se registraron veh¡culos este d¡a.\n");
        }
    }
    return 0;
}

int PreguntarEsDomingo() {
    int descuento;
    printf("¨Es d¡a domingo? (Escriba '1' para responder SI y cualquiero otro numero para responder NO): ");
    scanf("%d", &descuento);

    if (descuento == 1) {
        printf("Respondiste SI, por lo tanto habr  un descuento del %%10 al total del costo del estacionamiento para este veh¡culo.\n");
    }
    return descuento;
}
int PreguntarDiaMes() {
    int dia;
    printf("Indique el d¡a del mes (1-%d): ", DIAS_MES);
    scanf("%d", &dia);
    return dia;
}
int ContinuarRegistrando() {
    int finalizar;
    printf("¨Desea ingresar otro veh¡culo? (Escriba '1' para responder SI y cualquiero otro n£mero para responder NO.): ");
    scanf("%d", &finalizar);
    if (finalizar != 1) {
        finalizar = 0;
    }
    return finalizar;
}

int CalcularFechaFinal(int dia, int hora, int minutos, int tiempo) {
    int total_tiempo, dia_final, hora_final, minuto_final, tiempo_restante, resultado;
    //total_tiempo = ((dia - 1) * 1440) + (hora * 60) + minutos + tiempo;
    total_tiempo = (dia * 1440) + (hora * 60) + minutos + tiempo;
    dia_final = total_tiempo / (24 * 60);
    tiempo_restante = total_tiempo % (24 * 60);
    hora_final = tiempo_restante / 60;
    minuto_final = tiempo_restante % 60;
    if (dia_final > 30) {
        dia_final = 30;
    }
    resultado = (dia_final * 10000) + (hora_final * 100) + minuto_final;
    return resultado;
}

float CalcularCosto(int minutos, int descuento) {
    float costo = 0.0;
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
            costo *= DESCUENTO;
        }
    }
    return costo;
}