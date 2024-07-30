#include <stdio.h>
#include <stdlib.h>
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

void insertarNodo(Nodo** cabeza, int valor) {
    Nodo* nuevoNodo = crearNodo(valor);
    if (*cabeza == NULL) {
        *cabeza = nuevoNodo;
    } else {
        Nodo* temp = *cabeza;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = nuevoNodo;
    }
}

int contarNodos(Nodo* cabeza) {
    int contador = 0;
    Nodo* temp = cabeza;
    while (temp != NULL) {
        contador++;
        temp = temp->next;
    }
    return contador;
}

void imprimirLista(Nodo* cabeza) {
    Nodo* temp = cabeza;
    while (temp != NULL) {
        printf("%d -> ", temp->valor);
        temp = temp->next;
    }
    printf("NULL\n");
}

void insertarOrdenadoDescendente(Nodo** cabeza, int valor) {
    if (*cabeza == NULL || (*cabeza)->valor < valor) {
        Nodo* nuevoNodo = crearNodo(valor);
        nuevoNodo->next = *cabeza;
        *cabeza = nuevoNodo;
    } else if ((*cabeza)->valor != valor) {
        Nodo* temp = *cabeza;
        while (temp->next != NULL && temp->next->valor > valor) {
            temp = temp->next;
        }
        if (temp->next == NULL || temp->next->valor != valor) {
            Nodo* nuevoNodo = crearNodo(valor);
            nuevoNodo->next = temp->next;
            temp->next = nuevoNodo;
        }
    }
}

Nodo* generarListaOrdenadaDescendente(Nodo* cabeza) {
    Nodo* nuevaCabeza = NULL;
    Nodo* temp = cabeza;
    while (temp != NULL) {
        insertarOrdenadoDescendente(&nuevaCabeza, temp->valor);
        temp = temp->next;
    }
    return nuevaCabeza;
}

int main() {
    Nodo* cabeza = NULL;
    int cantidadNumeros = 20;

    srand(time(NULL));

    for (int i = 0; i < cantidadNumeros; i++) {
        int numeroAleatorio = rand() % 101; 
        insertarNodo(&cabeza, numeroAleatorio);
    }

    int nodosIniciales = contarNodos(cabeza);
    printf("Número de nodos inicial >> %d\n", nodosIniciales);

    printf("Lista enlazada inicial >> \n");
    imprimirLista(cabeza);

    Nodo* cabezaOrdenada = generarListaOrdenadaDescendente(cabeza);

    int nodosFinales = contarNodos(cabezaOrdenada);
    printf("Número de nodos en la segunda lista >> %d\n", nodosFinales);

    printf("Segunda lista enlazada ordenada descendente sin repetidos >> \n");
    imprimirLista(cabezaOrdenada);

    while (cabeza != NULL) {
        Nodo* temp = cabeza;
        cabeza = cabeza->next;
        free(temp);
    }

    while (cabezaOrdenada != NULL) {
        Nodo* temp = cabezaOrdenada;
        cabezaOrdenada = cabezaOrdenada->next;
        free(temp);
    }

    return 0;
}
