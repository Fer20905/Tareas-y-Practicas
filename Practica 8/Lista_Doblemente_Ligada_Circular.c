#include <stdio.h>
#include <stdlib.h>

struct Nodo {
    int dato;
    struct Nodo *anterior;
    struct Nodo *siguiente;
};

void insertarCircular(struct Nodo **inicio, int valor){
    struct Nodo *nuevo = (struct Nodo*)malloc(sizeof(struct Nodo));
    nuevo->dato = valor;

    if(*inicio == NULL){
        nuevo->siguiente = nuevo;
        nuevo->anterior = nuevo;
        *inicio = nuevo;
        return;
    }

    struct Nodo *ultimo = (*inicio)->anterior;

    nuevo->siguiente = *inicio;
    nuevo->anterior = ultimo;
    ultimo->siguiente = nuevo;
    (*inicio)->anterior = nuevo;
}

void recorrerCircular(struct Nodo *inicio){
    if(inicio == NULL) return;

    struct Nodo *temp = inicio;
    printf("\nLista circular: ");
    do{
        printf("%d ", temp->dato);
        temp = temp->siguiente;
    }while(temp != inicio);
    printf("\n");
}

void eliminarCircular(struct Nodo **inicio, int valor){
    if(*inicio == NULL) return;

    struct Nodo *temp = *inicio;
    do{
        if(temp->dato == valor){
            
            if(temp->siguiente == temp){
                free(temp);
                *inicio = NULL;
                return;
            }

            temp->anterior->siguiente = temp->siguiente;
            temp->siguiente->anterior = temp->anterior;

            if(temp == *inicio)
                *inicio = temp->siguiente;

            free(temp);
            return;
        }
        temp = temp->siguiente;
    }while(temp != *inicio);

    printf("Valor no encontrado.\n");
}

int main(){
    struct Nodo *inicio = NULL;
    int n, valor, borrar;

    printf("Cuantos valores insertar? ");
    scanf("%d", &n);

    for(int i=0; i<n; i++){
        printf("Valor: ");
        scanf("%d", &valor);
        insertarCircular(&inicio, valor);
    }

    recorrerCircular(inicio);

    printf("\nValor a eliminar: ");
    scanf("%d", &borrar);
    eliminarCircular(&inicio, borrar);

    recorrerCircular(inicio);

    return 0;
}

