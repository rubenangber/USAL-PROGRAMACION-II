#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct Nodo {
    int valor;
    struct Nodo* siguiente;
} Nodo;

Nodo* crearNodo(int valor) {
    Nodo* nuevoNodo = (Nodo*)malloc(sizeof(Nodo));
    if (nuevoNodo == NULL) {
        printf("Error al asignar memoria para el nodo.\n");
        exit(1);
    }
    nuevoNodo->valor = valor;
    nuevoNodo->siguiente = NULL;
    return nuevoNodo;
}

void insertarNodo(Nodo** cabeza, int valor) {
    Nodo* nuevoNodo = crearNodo(valor);
    if (*cabeza == NULL) {
        *cabeza = nuevoNodo;
    } else {
        Nodo* temp = *cabeza;
        while (temp->siguiente != NULL) {
            temp = temp->siguiente;
        }
        temp->siguiente = nuevoNodo;
    }
}

int contarNodos(Nodo* cabeza) {
    int contador = 0;
    Nodo* temp = cabeza;
    while (temp != NULL) {
        contador++;
        temp = temp->siguiente;
    }
    return contador;
}

void imprimirLista(Nodo* cabeza) {
    Nodo* temp = cabeza;
    while (temp != NULL) {
        printf("%d -> ", temp->valor);
        temp = temp->siguiente;
    }
    printf("NULL\n");
}

void eliminarNodos(Nodo** cabeza, int valor) {
    Nodo* temp = *cabeza;
    Nodo* prev = NULL;
    while (temp != NULL) {
        if (temp->valor == valor) {
            if (prev == NULL) {
                *cabeza = temp->siguiente;
            } else {
                prev->siguiente = temp->siguiente;
            }
            Nodo* nodoAEliminar = temp;
            temp = temp->siguiente;
            free(nodoAEliminar);
        } else {
            prev = temp;
            temp = temp->siguiente;
        }
    }
}

int main() {
    Nodo* cabeza = NULL;
    int cantidadNumeros = 20;
    int valor, nodosIniciales, nodosFinales;

    srand(time(NULL));

    for (int i = 0; i < cantidadNumeros; i++) {
        int numeroAleatorio = rand() % 11;
        insertarNodo(&cabeza, numeroAleatorio);
    }

    printf("Lista enlazada inicial:\n");
    imprimirLista(cabeza);

    while (1) {
        nodosIniciales = contarNodos(cabeza);
        printf("Número de nodos al inicio: %d\n", nodosIniciales);

        printf("Introduce un número para eliminar (número negativo para salir): ");
        scanf("%d", &valor);

        if (valor < 0) {
            break;
        }

        eliminarNodos(&cabeza, valor);

        nodosFinales = contarNodos(cabeza);
        printf("Número de nodos al final: %d\n", nodosFinales);
        printf("Lista enlazada después de eliminación:\n");
        imprimirLista(cabeza);
    }

    while (cabeza != NULL) {
        Nodo* temp = cabeza;
        cabeza = cabeza->siguiente;
        free(temp);
    }

    return 0;
}
