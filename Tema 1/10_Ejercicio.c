#include <stdlib.h>
#include <stdio.h>
#include <math.h>

struct punto {
    float x;
    float y;
};

int main(int argc, char const *argv[]) {
    struct punto p1, p2, p3;

    printf("Ingrese la coordenada x del primer punto >> ");
    scanf("%f", &p1.x);
    printf("Ingrese la coordenada y del primer punto >> ");
    scanf("%f", &p1.y);

    printf("Ingrese la coordenada x del segundo punto >> ");
    scanf("%f", &p2.x);
    printf("Ingrese la coordenada y del segundo punto >> ");
    scanf("%f", &p2.y);

    float distancia = sqrt(pow(p1.x - p2.x, 2) + pow(p1.y - p2.y, 2));
    printf("La distancia entre (%.2f , %.2f) y (%.2f , %.2f) es >> %f\n", p1.x, p1.y, p2.x, p2.y, distancia);

    p3.x = (p1.x + p2.x) / 2;
    p3.y = (p1.y + p2.y) / 2;

    printf("El punto medio entre (%.2f , %.2f) y (%.2f , %.2f) es (%.2f , %.2f)\n", p1.x, p1.y, p2.x, p2.y, p3.x, p3.y);

    return 0;
}
