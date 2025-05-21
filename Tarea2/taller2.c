/*Detalles:
-Primeros 10 min gratis
-Siguientes 15 min $3
-Primera hora $10
-Cada hora subsecuente $5
-A partir de la primera hora se cobran horas completas
-Si es Domingo se hace descuento de 10% sobre el monto total
*Leer minutos y horas e impromor ciantp se pagara
*/
#include <stdio.h>

int main() {
    int tiempo, dia, i = 0, paga = 0;
    
    printf("Ingrese el número correspondiente al día de la semana.\n1.Lunes\n2.Martes\n3.Miércoles\n4.Jueves\n5.Viernes\n6.Sábado\n7.Domingo\n");
    while(i == 0) {
        printf("Día: ");
        scanf("%d", &dia);
        if (dia > 0 && dia < 8) {
            printf("Ahora ingrese el tiempo que estuvo estacionado(en minutos): ");
            scanf("%d", &tiempo);
            if (tiempo > 0) {
                if (tiempo < 60) { //Si es una hora
                    if (tiempo <= 10) { //si son 10 minutos
                        paga = 0;   //Gratis
                    } else {
                        if (tiempo <= (10 + 15)) { // 10 minutos + siguientes 15 minutos
                            paga += 3;  //Se aumenta $3
                        }
                    }
                } else {
                    paga += 10; //Primera hora
                    if((tiempo/60) > 1) {   //Si el tiempo es +1 horas
                        paga += 5*((tiempo-60)/60);
                    }
                }
                if (dia == 7) {
                    paga = paga*0.10;
                }
                printf("----------------------------------------------------");
                printf("Horas/min\tTotal a pagar\n%d hrs, %d min\t$%d\n", tiempo/60, tiempo%60, paga);
                i++;
            } else {
                printf("No se ingresó un tiempo válido.");
            }
        } else {
            
            printf("Por favor, ingrese un día válido.\n");
        }
    }
    return 0;
}
