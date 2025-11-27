#include <stdio.h>
#define MAX 5

typedef struct {
    int datos[MAX];
    int frente;
    int final;
} Cola;

void inicializar(Cola *c) {
    c->frente = 0;
    c->final = -1;
    printf("Cola inicializada vacia\n");
}

int estaLlena(Cola *c) {
    return c->final == MAX - 1;
}

int estaVacia(Cola *c) {
    return c->frente > c->final;
}

void enqueue(Cola *c, int valor) {
    if (estaLlena(c)) {
        printf("Error: la cola esta llena\n");
    } else {
        c->datos[++c->final] = valor;
        printf("Se inserto %d en la cola\n", valor);
    }
}

int dequeue(Cola *c) {
    if (estaVacia(c)) {
        printf("Error: la cola esta vacia\n");
        return -1;
    } else {
        int valor = c->datos[c->frente++];
        printf("Se extrajo %d de la cola\n", valor);
        return valor;
    }
}

void mostrar(Cola *c) {
    if (estaVacia(c)) {
        printf("[Cola vacia]\n");
    } else {
        printf("Estado actual de la cola: ");
        for (int i = c->frente; i <= c->final; i++)
            printf("%d ", c->datos[i]);
        printf("\n");
    }
}

int main() {
    Cola c;
    inicializar(&c);

    int n, valor;

    printf("\n¿Cuantos elementos quieres encolar? (maximo 5): ");
    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        printf("Ingresa el elemento %d: ", i + 1);
        scanf("%d", &valor);
        enqueue(&c, valor);
        mostrar(&c);
    }

    printf("\n¿Cuantos elementos quieres desencolar?: ");
    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        dequeue(&c);
        mostrar(&c);
    }

    return 0;
}

