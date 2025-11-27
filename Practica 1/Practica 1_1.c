#include <stdio.h>

#define TAM 100

int main() {
    int arreglo[TAM];
    int n;

    printf("¿Cuántos elementos deseas ingresar? (1-%d): ", TAM);
    scanf("%d", &n);

    if (n <= 0 || n > TAM) {
        printf("Número inválido. Debe estar entre 1 y %d.\n", TAM);
        return 1;
    }

    printf("Ingresa %d números:\n", n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &arreglo[i]);
    }

    printf("Elementos ingresados:\n");
    for (int i = 0; i < n; i++) {
        if (i == n - 1)
            printf("%d", arreglo[i]);
        else
            printf("%d, ", arreglo[i]);
    }
    printf("\n");

    return 0;
}


