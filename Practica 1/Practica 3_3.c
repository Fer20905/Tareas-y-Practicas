#include <stdio.h>

#define TAM 100

int main() {
    int arreglo[TAM], n;

    printf("¿Cuántos elementos deseas ingresar? (1-%d): ", TAM);
    scanf("%d", &n);

    if (n <= 0 || n > TAM) {
        printf("Número inválido.\n");
        return 1;
    }

    printf("Ingresa %d números:\n", n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &arreglo[i]);
    }

    for (int i = 0; i < n / 2; i++) {
        int temp = arreglo[i];
        arreglo[i] = arreglo[n - 1 - i];
        arreglo[n - 1 - i] = temp;
    }

    printf("Arreglo invertido:\n");
    for (int i = 0; i < n; i++) {
      if (i == n - 1)
        printf("%d ", arreglo[i]);
      else
        printf("%d, ", arreglo[i]);
    }
    printf("\n");

    return 0;
}


