#include <stdio.h>

typedef struct {
    int dato;
} Nodo;

int main() {
    Nodo n1;
    Nodo *p;
    p = &n1;

    n1.dato = 10;
    p->dato = 20;

    printf("%d\n", n1.dato);
    printf("%d\n", p->dato);

    return 0;
}
