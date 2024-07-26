#include <stdio.h>
#include <stdlib.h>
#include <math.h>

double* leerPolinomio(int grado) {
    double* coeficientes = (double*) malloc((grado + 1) * sizeof(double));

    printf("Introduce los coeficientes del polinomio de grado %d en orden decreciente >> \n", grado);
    for (int i = 0; i <= grado; i++) {
        printf("Coeficiente de x^%d >> ", grado - i);
        scanf("%lf", &coeficientes[i]);
    }

    return coeficientes;
}

double evaluarPolinomio(double* coeficientes, int grado, double x) {
    double resultado = 0.0;

    for (int i = 0; i <= grado; i++) {
        resultado += coeficientes[i] * pow(x, grado - i);
    }

    return resultado;
}

int main() {
    int grado;
    double x;

    printf("Introduce el grado del polinomio >> ");
    scanf("%d", &grado);

    double* coeficientes = leerPolinomio(grado);

    printf("Introduce el valor de x para evaluar el polinomio >>  ");
    scanf("%lf", &x);

    double resultado = evaluarPolinomio(coeficientes, grado, x);

    printf("El valor del polinomio en x = %.2f es >>  %.2f\n", x, resultado);

    free(coeficientes);

    return 0;
}
