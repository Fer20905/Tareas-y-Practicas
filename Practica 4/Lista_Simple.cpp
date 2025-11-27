#include <stdio.h>
#include <stdlib.h>

typedef struct Nodo {
    int dato;
    struct Nodo *sig;
} Nodo;

// Insertar al inicio
void insertarInicio(Nodo **lista, int valor) {
    Nodo *nuevo = (Nodo*)malloc(sizeof(Nodo));
    if (!nuevo) {
        printf("Error al asignar memoria\n");
        return;
    }
    nuevo->dato = valor;
    nuevo->sig = *lista;
    *lista = nuevo;
}

// Insertar al final
void insertarFinal(Nodo **lista, int valor) {
    Nodo *nuevo = (Nodo*)malloc(sizeof(Nodo));
    nuevo->dato = valor;
    nuevo->sig = NULL;

    if (*lista == NULL) {
        *lista = nuevo;
        return;
    }

    Nodo *temp = *lista;
    while (temp->sig != NULL)
        temp = temp->sig;

    temp->sig = nuevo;
}

// Imprimir lista
void imprimirLista(Nodo *lista) {
    while (lista != NULL) {
        printf("%d -> ", lista->dato);
        lista = lista->sig;
    }
    printf("NULL\n");
}

// Liberar memoria
void liberar(Nodo *lista) {
    Nodo *temp;
    while (lista != NULL) {
        temp = lista;
        lista = lista->sig;
        free(temp);
    }
}

int main() {
    Nodo *lista = NULL;
    int opcion, valor;

    do {
        printf("\n--- LISTA SIMPLEMENTE ENLAZADA ---\n");
        printf("1. Insertar al inicio\n");
        printf("2. Insertar al final\n");
        printf("3. Imprimir lista\n");
        printf("4. Salir\n");
        printf("Opcion: ");
        scanf("%d", &opcion);

        switch (opcion) {
            case 1:
                printf("Valor: ");
                scanf("%d", &valor);
                insertarInicio(&lista, valor);
                break;
            case 2:
                printf("Valor: ");
                scanf("%d", &valor);
                insertarFinal(&lista, valor);
                break;
            case 3:
                imprimirLista(lista);
                break;
            case 4:
                liberar(lista);
                printf("Memoria liberada.\n");
                break;
            default:
                printf("Opcion invalida.\n");
        }
    } while (opcion != 4);

    return 0;
}