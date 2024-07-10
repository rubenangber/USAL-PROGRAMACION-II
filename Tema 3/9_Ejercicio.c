#include <stdlib.h>
#include <stdio.h>
#include <time.h>

#define TAM 10

int * generarResultado(int *v1, int tam1, int *v2, int tam2) {
    int *vresultado = (int *)malloc((tam1 + tam2) * sizeof(int));
    
    for(int i = 0; i < tam1; i++) {
        vresultado[i] = v1[i];
    }
    for (int i = 0; i < tam2; i++) {
        vresultado[tam1 + i] = v2[i];
    }

    return vresultado;
}

int main(int argc, char const *argv[]) {
    int v1[TAM], v2[TAM];
    int tam1, tam2;
    srand(time(NULL));

    printf("Introduce el tamaño del vector 1 >> ");
    scanf("%d", &tam1);

    for (int i = 0; i < tam1; i++) {
        v1[i] = rand() % 100;
    }

    printf("VECTOR 1 >>\n");
    for (int i = 0; i < tam1; i++) {
        printf("%d ", v1[i]);
    }
    printf("\n");
    
    printf("Introduce el tamaño del vector 2 >> ");
    scanf("%d", &tam2);

    for (int i = 0; i < tam2; i++) {
        v2[i] = rand() % 100;
    }

    printf("VECTOR 2 >>\n");
    for (int i = 0; i < tam2; i++) {
        printf("%d ", v2[i]);
    }
    printf("\n");

    int *vresultado = generarResultado(v1, tam1, v2, tam2);

    printf("VECTOR CONCATENADO >>\n");
    for (int i = 0; i < tam1 + tam2; i++) {
        printf("%d ", vresultado[i]);
    }
    printf("\n");

    return 0;
}
