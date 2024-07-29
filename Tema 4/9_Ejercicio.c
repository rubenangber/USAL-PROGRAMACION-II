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
        printf("Error al asignar memoria para el nodo.\n");
        exit(1);
    }
    nuevoNodo->valor = valor;
    nuevoNodo->next = NULL;
    return nuevoNodo;
}

void insertarOrdenado(Nodo** cabeza, int valor) {
    Nodo* nuevoNodo = crearNodo(valor);
    if (*cabeza == NULL || (*cabeza)->valor >= valor) {
        nuevoNodo->next = *cabeza;
        *cabeza = nuevoNodo;
    } else {
        Nodo* temp = *cabeza;
        while (temp->next != NULL && temp->next->valor < valor) {
            temp = temp->next;
        }
        nuevoNodo->next = temp->next;
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

void eliminarMayores(Nodo** cabeza, int valor) {
    while (*cabeza != NULL && (*cabeza)->valor > valor) {
        Nodo* temp = *cabeza;
        *cabeza = (*cabeza)->next;
        free(temp);
    }
    if (*cabeza == NULL) {
        return;
    }
    Nodo* temp = *cabeza;
    while (temp->next != NULL) {
        if (temp->next->valor > valor) {
            Nodo* nodoAEliminar = temp->next;
            temp->next = temp->next->next;
            free(nodoAEliminar);
        } else {
            temp = temp->next;
        }
    }
}

int main() {
    Nodo* cabeza = NULL;
    int cantidadNumeros = 20;
    int numero, nodosIniciales, nodosFinales;

    srand(time(NULL));

    for (int i = 0; i < cantidadNumeros; i++) {
        int numeroAleatorio = rand() % 101;
        insertarOrdenado(&cabeza, numeroAleatorio);
    }

    nodosIniciales = contarNodos(cabeza);
    printf("Número de nodos inicial >> %d\n", nodosIniciales);

    printf("Lista enlazada inicial >> \n");
    imprimirLista(cabeza);

    printf("Introduce un número para eliminar nodos con valores mayores que este >> ");
    scanf("%d", &numero);

    eliminarMayores(&cabeza, numero);

    nodosFinales = contarNodos(cabeza);
    printf("Número de nodos final >> %d\n", nodosFinales);

    printf("Lista enlazada final >> \n");
    imprimirLista(cabeza);

    while (cabeza != NULL) {
        Nodo* temp = cabeza;
        cabeza = cabeza->next;
        free(temp);
    }

    return 0;
}
