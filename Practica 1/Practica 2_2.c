#include <stdio.h>

#define TAM 100

int main() {
    int arreglo[TAM], n;
    int suma = 0, min, max, idx_min = 0, idx_max = 0;

    printf("¿Cuántos elementos deseas ingresar? (1-%d): ", TAM);
    scanf("%d", &n);

    if (n <= 0 || n > TAM) {
        printf("Número inválido.\n");
        return 1;
    }

    printf("Ingresa %d números:\n", n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &arreglo[i]);
        suma += arreglo[i];

        if (i == 0 || arreglo[i] < min) {
            min = arreglo[i];
            idx_min = i;
        }
        if (i == 0 || arreglo[i] > max) {
            max = arreglo[i];
            idx_max = i;
        }
    }

    double promedio = (double)suma / n;

    printf("\nSuma: %d\n", suma);
    printf("Promedio: %.2f\n", promedio);
    printf("Minimo: %d (indice %d)\n", min, idx_min);
    printf("Máximo: %d (indice %d)\n", max, idx_max);

    return 0;
}



