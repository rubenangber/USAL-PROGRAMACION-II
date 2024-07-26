#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int* obtenerColumna(int** matriz, int filas, int columnas, int fila) {
    int* columna = (int*) malloc(filas * sizeof(int));

    for (int i = 0; i < filas; i++) {
        columna[i] = matriz[i][fila];
    }

    return columna;
}

int main() {
    int filas, columnas, fila;
    srand(time(NULL));

    printf("Introduce el número de filas >> ");
    scanf("%d", &filas);
    printf("Introduce el número de columnas >> ");
    scanf("%d", &columnas);

    int** matriz = (int**) malloc(filas * sizeof(int*));
    for (int i = 0; i < filas; i++) {
        matriz[i] = (int*) malloc(columnas * sizeof(int));
        for (int j = 0; j < columnas; j++) {
            matriz[i][j] = rand() % 11; // Llenado con valores aleatorios entre 0 y 10
        }
    }

    printf("Matriz:\n");
    for (int i = 0; i < filas; i++) {
        for (int j = 0; j < columnas; j++) {
            printf("%d ", matriz[i][j]);
        }
        printf("\n");
    }

    printf("Introduce la columna deseada >> ");
    scanf("%d", &fila);

    int* columna = obtenerColumna(matriz, filas, columnas, (fila - 1));

    printf("Columna %d >>\n", fila);
    for (int i = 0; i < filas; i++) {
        printf("%d ", columna[i]);
    }
    printf("\n");

    free(columna);
    for (int i = 0; i < filas; i++) {
        free(matriz[i]);
    }
    free(matriz);

    return 0;
}
