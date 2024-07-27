#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MIN_DIM 10
#define MAX_DIM 100

int** generarMalla(int filas, int columnas) {
    if (filas < MIN_DIM || filas > MAX_DIM || columnas < MIN_DIM || columnas > MAX_DIM) {
        printf("Dimensiones fuera de rango, deben estar entre %d y %d\n", MIN_DIM, MAX_DIM);
        return NULL;
    }

    int** malla = (int**) malloc(filas * sizeof(int*));
    for (int i = 0; i < filas; i++) {
        malla[i] = (int*) malloc(columnas * sizeof(int));
    }

    srand(time(NULL));
    for (int i = 0; i < filas; i++) {
        for (int j = 0; j < columnas; j++) {
            malla[i][j] = rand() % 11;
        }
    }

    return malla;
}

void imprimirMalla(int** malla, int filas, int columnas) {
    for (int i = 0; i < filas; i++) {
        for (int j = 0; j < columnas; j++) {
            printf("%d ", malla[i][j]);
        }
        printf("\n");
    }
}

int** detectarRuido(int** malla, int filas, int columnas) {
    int** ruidoMalla = (int**) malloc(filas * sizeof(int*));
    for (int i = 0; i < filas; i++) {
        ruidoMalla[i] = (int*) malloc(columnas * sizeof(int));
    }

    for (int i = 0; i < filas; i++) {
        for (int j = 0; j < columnas; j++) {
            if (i == 0 || j == 0 || i == filas - 1 || j == columnas - 1) {
                ruidoMalla[i][j] = 0;
            } else {
                int suma = 0;
                for (int k = -1; k <= 1; k++) {
                    for (int l = -1; l <= 1; l++) {
                        if (k != 0 || l != 0) {
                            suma += malla[i + k][j + l];
                        }
                    }
                }
                int media = suma / 8;
                ruidoMalla[i][j] = (abs(malla[i][j] - media) >= 2) ? 1 : 0; // Operacion ternaria, si se cumple la condicion se asigna 1, si no 0
            }
        }
    }

    return ruidoMalla;
}

int** suavizarMalla(int** malla, int filas, int columnas) {
    int** mallaSuavizada = (int**) malloc((filas - 2) * sizeof(int*));
    for (int i = 0; i < filas - 2; i++) {
        mallaSuavizada[i] = (int*) malloc((columnas - 2) * sizeof(int));
    }

    for (int i = 1; i < filas - 1; i++) {
        for (int j = 1; j < columnas - 1; j++) {
            int suma = 0;
            for (int k = -1; k <= 1; k++) {
                for (int l = -1; l <= 1; l++) {
                    if (k != 0 || l != 0) {
                        suma += malla[i + k][j + l];
                    }
                }
            }
            mallaSuavizada[i - 1][j - 1] = suma / 8;
        }
    }

    return mallaSuavizada;
}

int main() {
    int filas, columnas;

    printf("Introduce el número de filas de la malla (entre %d y %d) >> ", MIN_DIM, MAX_DIM);
    scanf("%d", &filas);
    printf("Introduce el número de columnas de la malla (entre %d y %d) >> ", MIN_DIM, MAX_DIM);
    scanf("%d", &columnas);

    int** malla = generarMalla(filas, columnas);
    if (malla == NULL) {
        return 1;
    }

    printf("\nMalla original >> \n");
    imprimirMalla(malla, filas, columnas);

    int** ruidoMalla = detectarRuido(malla, filas, columnas);
    printf("\nMalla de ruido >> \n");
    imprimirMalla(ruidoMalla, filas, columnas);

    int** mallaSuavizada = suavizarMalla(malla, filas, columnas);
    printf("\nMalla suavizada >> \n");
    imprimirMalla(mallaSuavizada, filas - 2, columnas - 2);

    for (int i = 0; i < filas; i++) {
        free(malla[i]);
        free(ruidoMalla[i]);
    }
    for (int i = 0; i < filas - 2; i++) {
        free(mallaSuavizada[i]);
    }
    free(malla);
    free(ruidoMalla);
    free(mallaSuavizada);

    return 0;
}
