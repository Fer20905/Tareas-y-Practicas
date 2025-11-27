#include <stdio.h>
#include <stdlib.h>

typedef struct Nodo {
    int dato;
    struct Nodo *sig;
} Nodo;

void insertar(Nodo **lista, int valor) {
    Nodo *nuevo = (Nodo*)malloc(sizeof(Nodo));
    nuevo->dato = valor;

    if (*lista == NULL) {
        *lista = nuevo;
        nuevo->sig = nuevo;
        return;
    }

    Nodo *temp = *lista;
    while (temp->sig != *lista)
        temp = temp->sig;

    temp->sig = nuevo;
    nuevo->sig = *lista;
}

void imprimir(Nodo *lista) {
    if (lista == NULL) {
        printf("Lista vacia\n");
        return;
    }

    Nodo *temp = lista;
    do {
        printf("%d -> ", temp->dato);
        temp = temp->sig;
    } while (temp != lista);

    printf("(regresa al inicio)\n");
}

void liberar(Nodo *lista) {
    if (lista == NULL)
        return;

    Nodo *temp = lista->sig;
    Nodo *siguiente;

    while (temp != lista) {
        siguiente = temp->sig;
        free(temp);
        temp = siguiente;
    }

    free(lista);
}

int main() {
    Nodo *lista = NULL;
    int opcion, valor;

    do {
        printf("\n--- LISTA CIRCULAR ---\n");
        printf("1. Insertar\n");
        printf("2. Imprimir lista\n");
        printf("3. Salir\n");
        printf("Opcion: ");
        scanf("%d", &opcion);

        switch (opcion) {
            case 1:
                printf("Valor: ");
                scanf("%d", &valor);
                insertar(&lista, valor);
                break;
            case 2:
                imprimir(lista);
                break;
            case 3:
                liberar(lista);
                printf("Memoria liberada.\n");
                break;
            default:
                printf("Opcion invalida.\n");
        }

    } while (opcion != 3);

    return 0;
}