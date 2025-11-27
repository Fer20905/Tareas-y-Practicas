#include <stdio.h>
#define MAX 5

typedef struct {
    int datos[MAX];
    int tope;
} Pila;

void inicializar(Pila *p) {
    p->tope = -1;
    printf("Pila inicializada vacia\n");
}

int estaLlena(Pila *p) {
    return p->tope == MAX - 1;
}

int estaVacia(Pila *p) {
    return p->tope == -1;
}

void push(Pila *p, int valor) {
    if (estaLlena(p)) {
        printf("Error: la pila esta llena\n");
    } else {
        p->datos[++p->tope] = valor;
        printf("Se inserto %d en la pila\n", valor);
    }
}

int pop(Pila *p) {
    if (estaVacia(p)) {
        printf("Error: la pila esta vacia\n");
        return -1;
    } else {
        int valor = p->datos[p->tope--];
        printf("Se extrajo %d de la pila\n", valor);
        return valor;
    }
}

void mostrar(Pila *p) {
    if (estaVacia(p)) {
        printf("[Pila vacia]\n");
    } else {
        printf("Estado actual de la pila: ");
        for (int i = 0; i <= p->tope; i++)
            printf("%d ", p->datos[i]);
        printf("\n");
    }
}

int main() {
    Pila p;
    inicializar(&p);

    int n, valor;

