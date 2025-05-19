/*
Solicitar notas -
Mostrar cada nota -
Calcular promedio -
Mostrar cantidad de notas válidas ingresadas -
Mostrar calificación mayor y menor -
Calcular desviación estandar -
[!] Manejar división por 0 para evitar errores -
Aclaraciones: 
- Para obtener la desviación estandar se debe sacar la 
  raíz cuadrada y al no poder utilizar math.h utilicé el
  método por bisección para obtenerla con una función.
- También necesitaba el valor absoluto en la función para
  calcular la raíz, así que realicé un función para obtenerlo.
*/
#include <stdio.h>

float ValorAbsoluto(float numero) { //Valor absoluto de un número
    if (numero < 0) {
        numero = numero *-1;
    }
    return numero;
}

float CalcularRaiz(float numero) { //Método por bisección
    float minima = 0.0, media = 0.0, maxima = numero, proximacion = 0.00001;
    media = (minima + maxima)/2;
    while(ValorAbsoluto(numero - media*media) > proximacion) {
        media = (minima+maxima)/2;
        if ((media * media) > numero) {
            maxima = media;
        } else {
            if ((media * media) < numero) {
                minima = media;
            }
        }
    }
    return media;
}

int main() {
    float nota, promedio, nota_max, nota_min;
    int cantidad_notas, i;
    promedio = 0.0;
    nota_max = 1.0;
    nota_min = 7.0;
    cantidad_notas = 0;
    i = 0;
    while (i == 0) {
        printf("Ingrese una nota (Entre 1.0 y 7.0. Escriba '0' para finalizar.): ");
        scanf("%f", &nota);
        if (nota >= 1.0 && nota <= 7.0) {
            printf("Nota ingresada: %.2f\n", nota);
            cantidad_notas++;
            promedio = promedio + nota;
            if (nota < nota_min) {
                nota_min = nota;    //Actualizar calificación menor;
            }
            if (nota > nota_max) {
                nota_max = nota;    //Actualizar calificación mayor;
            }
        } else {
            if (nota != 0) {
                printf("Error: Nota inválida, debe estar entre 0 y 7 (0 para finalizar).\n");

            } else {
                if (cantidad_notas < 2) {
                    printf("Cantidad de notas mínimas para finalizar: 2.\n");
                } else {
                    i++;
                }
            }
        }
    }
    promedio = promedio/cantidad_notas;
    printf("Cantidad de notas ingresadas: %d\n", cantidad_notas);
    printf("Promedio de las notas: %.2f\n", promedio);
    printf("Calificación máxima: %.2f\n", nota_max);
    printf("Calificación mínima: %.2f\n", nota_min);
    printf("Desviación estandar: %f", CalcularRaiz(promedio));
    return 0;
}
