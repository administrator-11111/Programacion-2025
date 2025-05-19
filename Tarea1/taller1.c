/* Aclaraciones: 
- Para obtener la desviación estandar se debe sacar la 
  raíz cuadrada de la varianza y al no poder utilizar math.h utilicé el
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
    float minima = 0.0, media = 0.0, maxima = numero, proximacion;
    proximacion = 0.00001; // exactitud del resultado
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
    float nota, promedio, nota_max, nota_min, varianza, desviacion;
    int cantidad_notas, i;
    varianza = 0.0;
    desviacion = 0.0;
    promedio = 0.0;
    nota_max = 1.0;
    nota_min = 7.0;
    cantidad_notas = 0;
    i = 0;
    while (i == 0) {
        printf("Ingrese una nota (Entre 1.0 y 7.0, Escriba '0' para finalizar.): ");
        scanf("%f", &nota);
        if (nota >= 1.0 && nota <= 7.0) {
            printf("Nota ingresada: %f\n", nota);
            cantidad_notas++;
            promedio = promedio + nota;
            varianza = varianza + (nota*nota); //Se suman la nota al cuadrado
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
    varianza = (varianza/cantidad_notas) - (promedio*promedio);
    desviacion = CalcularRaiz(varianza);
    printf("Cantidad de notas ingresadas: %d\n", cantidad_notas);
    printf("Promedio de las notas: %.2f\n", promedio);
    printf("Calificación máxima: %.2f\n", nota_max);
    printf("Calificación mínima: %.2f\n", nota_min);
    printf("Desviación estandar: %f", desviacion);
    return 0;
}