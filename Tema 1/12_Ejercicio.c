#include <stdio.h>
#include <string.h>

struct Fraccion {
    int numerador;
    int denominador;
};

int main(int argc, char const *argv[]) {
    struct Fraccion f1, f2, resultado;
    int opc;

    printf("Introduce numerador del primer numero >> ");
    scanf("%d", &f1.numerador);
    printf("Introduce denominador del primer numero >> ");
    scanf("%d", &f1.denominador);

    printf("Introduce numerador del segundo numero >> ");
    scanf("%d", &f2.numerador);
    printf("Introduce denominador del segundo numero >> ");
    scanf("%d", &f2.denominador);

    do {
        printf("1) Suma (+)\n");
        printf("2) Resta (-)\n");
        printf("3) Division (/)\n");
        printf("4) Multiplicacion (*)\n");
        printf("Selecciona una opcion >> ");
        scanf("%d", &opc);
    } while (opc != 1 && opc != 2 && opc != 3 && opc != 4);

    switch (opc) {
        case 1:
            resultado.numerador = f1.numerador * f2.denominador + f2.numerador * f1.denominador;
            resultado.denominador = f1.denominador * f2.denominador;
            printf("El resultado de la suma es >> %d/%d\n", resultado.numerador, resultado.denominador);
        break;

        case 2:
            resultado.numerador = f1.numerador * f2.denominador - f2.numerador * f1.denominador;
            resultado.denominador = f1.denominador * f2.denominador;
            printf("El resultado de la resta es >> %d/%d\n", resultado.numerador, resultado.denominador);
        break;
            
        case 3:
            resultado.numerador = f1.numerador * f2.denominador;
            resultado.denominador = f1.denominador * f2.numerador;
            printf("El resultado de la divison es >> %d/%d\n", resultado.numerador, resultado.denominador);
        break;
        
        case 4:
            resultado.numerador = f1.numerador * f2.numerador;
            resultado.denominador = f1.denominador * f2.denominador;
            printf("El resultado de la multiplicacion es >> %d/%d\n", resultado.numerador, resultado.denominador);
        break;
    }

    return 0;
}
