#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h> // Para los bool 
#include <time.h>

typedef struct Nodo {
    int valor;
    struct Nodo* next;
} Nodo;

Nodo* crearNodo(int valor) {
    Nodo* nuevoNodo = (Nodo*)malloc(sizeof(Nodo));
    if (nuevoNodo == NULL) {
        printf("Error al asignar memoria para el nodo\n");
        exit(1);
    }
    nuevoNodo->valor = valor;
    nuevoNodo->next = NULL;
    return nuevoNodo;
}

void insertarElemento(Nodo** cabeza, int valor) {
    Nodo* nuevoNodo = crearNodo(valor);
    nuevoNodo->next = *cabeza;
    *cabeza = nuevoNodo;
}

bool estaEnConjunto(Nodo* cabeza, int valor) {
    Nodo* temp = cabeza;
    while (temp != NULL) {
        if (temp->valor == valor) {
            return true;
        }
        temp = temp->next;
    }
    return false;
}

void imprimirConjunto(Nodo* cabeza) {
    Nodo* temp = cabeza;
    printf("[ ");
    while (temp != NULL) {
        printf("%d ", temp->valor);
        temp = temp->next;
    }
    printf("]\n");
}

void liberarConjunto(Nodo* cabeza) {
    while (cabeza != NULL) {
        Nodo* temp = cabeza;
        cabeza = cabeza->next;
        free(temp);
    }
}

void unionConjuntos(Nodo* c1, Nodo* c2, Nodo** c3) {
    Nodo* temp = c1;
    while (temp != NULL) {
        if (!estaEnConjunto(*c3, temp->valor)) {
            insertarElemento(c3, temp->valor);
        }
        temp = temp->next;
    }

    temp = c2;
    while (temp != NULL) {
        if (!estaEnConjunto(*c3, temp->valor)) {
            insertarElemento(c3, temp->valor);
        }
        temp = temp->next;
    }
}

void diferenciaConjuntos(Nodo* c1, Nodo* c2, Nodo** c3) {
    Nodo* temp = c1;
    while (temp != NULL) {
        if (!estaEnConjunto(c2, temp->valor)) {
            insertarElemento(c3, temp->valor);
        }
        temp = temp->next;
    }
}

bool incluidoEnConjunto(Nodo* c1, Nodo* c2) {
    Nodo* temp = c1;
    while (temp != NULL) {
        if (!estaEnConjunto(c2, temp->valor)) {
            return false;
        }
        temp = temp->next;
    }
    return true;
}

void interseccionConjuntos(Nodo* c1, Nodo* c2, Nodo** c3) {
    Nodo* temp = c1;
    while (temp != NULL) {
        if (estaEnConjunto(c2, temp->valor)) {
            insertarElemento(c3, temp->valor);
        }
        temp = temp->next;
    }
}

int main() {
    Nodo* c1 = NULL;
    Nodo* c2 = NULL;
    Nodo* c3 = NULL;

    srand(time(NULL));

    for(int i = 0; i < 3; i++) {
        insertarElemento(&c1, rand() % 11);
        insertarElemento(&c2, rand() % 11);
    }

    printf("Conjunto c1 >> ");
    imprimirConjunto(c1);

    printf("Conjunto c2 >> ");
    imprimirConjunto(c2);

    unionConjuntos(c1, c2, &c3);
    printf("Unión de c1 y c2 >> ");
    imprimirConjunto(c3);
    liberarConjunto(c3);
    c3 = NULL;

    diferenciaConjuntos(c1, c2, &c3);
    printf("Diferencia de c1 y c2 >> ");
    imprimirConjunto(c3);
    liberarConjunto(c3);
    c3 = NULL;

    bool incluido = incluidoEnConjunto(c1, c2);
    printf("c1 incluido en c2 >>  %s\n", incluido ? "Sí" : "No");

    interseccionConjuntos(c1, c2, &c3);
    printf("Intersección de c1 y c2 >> ");
    imprimirConjunto(c3);
    liberarConjunto(c3);

    liberarConjunto(c1);
    liberarConjunto(c2);

    return 0;
}
