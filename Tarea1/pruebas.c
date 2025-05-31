#include <stdio.h>

int main() {
    float number;
    int i, total = 20;

    for (i = 0; i < total; i++) {
        printf("Numero: ");
        scanf("%f", &number);

        if ((int)number == number) {
            // Es un n£mero entero
            printf("Entero: %02d\n", (int)number);
        } else {
            // Es un n£mero con decimales
            printf("Flaot: %.3f\n", number);
        }
    }

    return 0;
}