#include <stdio.h>
#include <string.h>

#define MAX_PELIS 50

struct pelicula {
    char nombre[50];
    char genero[30];
    int anio;
    int numDirectores;
    char directores[5][50]; 
};

void imprimirPelicula(struct pelicula p) {
    printf("\n--- Película ---\n");
    printf("Nombre: %s\n", p.nombre);
    printf("Género: %s\n", p.genero);
    printf("Año: %d\n", p.anio);
    printf("Directores (%d):\n", p.numDirectores);
    for (int i = 0; i < p.numDirectores; i++) {
        printf(" - %s\n", p.directores[i]);
    }
}

int main() {
    struct pelicula videoteca[MAX_PELIS];
    int n;

    printf("¿Cuántas películas quieres registrar?: ");
    scanf("%d", &n);

    if (n <= 0) {
        printf("Error: La videoteca no puede tener %d películas.\n", n);
        return 1;
    }

    for (int i = 0; i < n; i++) {
        printf("\n--- Captura de película %d ---\n", i+1);

        printf("Nombre: ");
        scanf(" %[^\n]", videoteca[i].nombre);

        printf("Género: ");
        scanf(" %[^\n]", videoteca[i].genero);

        printf("Año: ");
        scanf("%d", &videoteca[i].anio);

        printf("Número de directores: ");
        scanf("%d", &videoteca[i].numDirectores);

        // Validación de directores
        if (videoteca[i].numDirectores <= 0) {
            printf("Error: número de directores inválido.\n");
            return 1;
        }

        for (int j = 0; j < videoteca[i].numDirectores; j++) {
            printf("Nombre del director %d: ", j+1);
            scanf(" %[^\n]", videoteca[i].directores[j]);
        }
    }

    printf("\n=== Películas en orden inverso ===\n");
    for (int i = n-1; i >= 0; i--) {
        imprimirPelicula(videoteca[i]);
    }

    char buscar[50];
    int opcion;
    printf("\n=== Búsqueda ===\n");
    printf("Buscar por: 1) Nombre  2) Año  3) Director\nOpción: ");
    scanf("%d", &opcion);

    if (opcion == 1) {
        printf("Introduce el nombre: ");
        scanf(" %[^\n]", buscar);
        for (int i = 0; i < n; i++) {
            if (strcmp(videoteca[i].nombre, buscar) == 0) {
                imprimirPelicula(videoteca[i]);
            }
        }
    } else if (opcion == 2) {
        int anioBuscado;
        printf("Introduce el año: ");
        scanf("%d", &anioBuscado);
        for (int i = 0; i < n; i++) {
            if (videoteca[i].anio == anioBuscado) {
                imprimirPelicula(videoteca[i]);
            }
        }
    } else if (opcion == 3) {
        printf("Introduce el nombre del director: ");
        scanf(" %[^\n]", buscar);
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < videoteca[i].numDirectores; j++) {
                if (strcmp(videoteca[i].directores[j], buscar) == 0) {
                    imprimirPelicula(videoteca[i]);
                }
            }
        }
    }

    // 6) Contador por género
    printf("\n=== Contador por género ===\n");
    for (int i = 0; i < n; i++) {
        int contador = 0;
        for (int j = 0; j < n; j++) {
            if (strcmp(videoteca[i].genero, videoteca[j].genero) == 0) {
                contador++;
            }
        }
        printf("%s: %d películas\n", videoteca[i].genero, contador);
    }

    return 0;
}