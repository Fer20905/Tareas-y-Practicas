#include <stdio.h>
#include <stdlib.h>

int main() {
    int n, i, agregar;
    float *calificaciones = NULL;
    float suma = 0, promedio = 0;

    // Primero pido la cantidad inicial de estudiantes
    printf("¿Cuántos estudiantes deseas registrar? ");
    scanf("%d", &n);

    // Despues reservo memoria para n calificaciones
    calificaciones = (float *)malloc(n * sizeof(float));
    if (calificaciones == NULL) {
        printf("Error: no se pudo asignar memoria.\n");
        return 1;
    }

    // Se capturan las calificaciones iniciales
    for (i = 0; i < n; i++) {
        printf("Calificación del estudiante %d: ", i + 1);
        scanf("%f", &calificaciones[i]);
        suma += calificaciones[i];
    }

    promedio = suma / n;
    printf("Promedio inicial: %.2f\n", promedio);

    // Pregunto si se quieren agregar más estudiantes
    printf("\n¿Deseas agregar más estudiantes? (cantidad, 0 para no): ");
    scanf("%d", &agregar);

    if (agregar > 0) {
        int nuevo_tamano = n + agregar;
        calificaciones = (float *)realloc(calificaciones, nuevo_tamano * sizeof(float));

        if (calificaciones == NULL) {
            printf("Error: no se pudo ampliar la memoria.\n");
            return 1;
        }

        // Con ello se capturan las nuevas calificaciones
        for (i = n; i < nuevo_tamano; i++) {
            printf("Calificación del estudiante %d: ", i + 1);
            scanf("%f", &calificaciones[i]);
            suma += calificaciones[i];
        }

        n = nuevo_tamano;
        promedio = suma / n;
    }

    // Muestro todas las calificaciones
    printf("\n=== Calificaciones registradas ===\n");
    for (i = 0; i < n; i++) {
        printf("Estudiante %d: %.2f\n", i + 1, calificaciones[i]);
    }

    printf("Promedio general: %.2f\n", promedio);

    // Y por ultimo se libera la memoria
    free(calificaciones);
    printf("\nMemoria liberada correctamente.\n");

    return 0;
}
