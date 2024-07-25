#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int* sumaFilasMatriz(int** matriz, int filas, int columnas) {
    int* vectorSumas = (int*) malloc(filas * sizeof(int));
    if (vectorSumas == NULL) {
        printf("Error al asignar memoria para el vector de sumas.\n");
        exit(1);
    }

    for (int i = 0; i < filas; i++) {
        int suma = 0;
        for (int j = 0; j < columnas; j++) {
            suma += matriz[i][j];
        }
        vectorSumas[i] = suma;
    }

    return vectorSumas;
}

int main() {
    int filas, columnas;

    printf("Introduce numero de filas >> ");
    scanf("%d", &filas);
    printf("Introduce numero de columnas >> ");
    scanf("%d", &columnas);

    srand(time(NULL));

    int** matriz = (int**) malloc(filas * sizeof(int*));
    for (int i = 0; i < filas; i++) {
        matriz[i] = (int*) malloc(columnas * sizeof(int));
        for (int j = 0; j < columnas; j++) {
            matriz[i][j] = rand() % 11;
        }
    }

    printf("Matriz >>\n");
    for (int i = 0; i < filas; i++) {
        for (int j = 0; j < columnas; j++) {
            printf("%d ", matriz[i][j]);
        }
        printf("\n");
    }

    int* vectorSumas = sumaFilasMatriz(matriz, filas, columnas);

    printf("Vector de sumas de las filas >>\n");
    for (int i = 0; i < filas; i++) {
        printf("%d ", vectorSumas[i]);
    }
    printf("\n");

    free(vectorSumas);

    for (int i = 0; i < filas; i++) {
        free(matriz[i]);
    }
    free(matriz);

    return 0;
}
