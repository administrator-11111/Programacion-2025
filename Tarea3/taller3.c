#include <stdio.h>
#define MAX_DIGITOS 8   // Máximo de dígitos de rut en chile

void SolicitarDatos(int*, char*); 
int CalculoDigitoVerificador(int, int);
void SepararRut(int, int []); 
char ConvertirDigitoVerificador(int);
void VerificadorRut(void);

int main() {
    VerificadorRut();
    return 0;
}

void VerificadorRut() {
    int rut;
    char verificador;
    SolicitarDatos(&rut, &verificador);
    if (CalculoDigitoVerificador(rut, verificador) == 1) {
        
        printf("[+] El RUT %d-%c es correcto.\n", rut, verificador);
    } else {
        printf("[X] El RUT %d-%c NO es correcto.\n", rut, verificador);
    }
}

int CalculoDigitoVerificador(int rut, int digito_ingresado) {
    int rut_valido = 0, rut_digitos[MAX_DIGITOS];
    int productos[8], suma_productos = 0, codigo;
    char digito_verificador;
    
    SepararRut(rut, rut_digitos);

    for (int i = 0, primos = 0; i < MAX_DIGITOS; i++) {
        if (primos < 2 || primos >= 7) {
            primos = 2;
        } else {
            primos++;
        }
        productos[i] = rut_digitos[i] * primos;
        suma_productos += productos[i];
    }

    codigo = suma_productos % 11;
    codigo = 11 - codigo;
    digito_verificador = ConvertirDigitoVerificador(codigo);
    if (digito_verificador == digito_ingresado) {
        rut_valido = 1;
    }
    return  rut_valido;
}

void SolicitarDatos(int * rut, char * verificador) {
    printf("Ingrese su rut (sin digito verificador, ejemplo: 22333444):\n>> ");
    scanf("%d", *&rut);
    printf("Ingrese el dígito verificador de su rut:\n>> ");
    scanf(" %c", *&verificador);
}

void SepararRut(int rut, int salida[]) {
    for (int i = 0; i < MAX_DIGITOS; i++) {
        salida[i] = rut % 10;
        rut /= 10;
    }
}

char ConvertirDigitoVerificador(int verificador) {
    char codigo;
    if (verificador == 11) {
        codigo = '0' + verificador;
    } else {
        if (verificador == 10) {
            codigo = 'k';
        } else {
            codigo = '0' + verificador;
        }
    }
    return codigo;
}







