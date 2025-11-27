#include <stdio.h>

int main(void) {
    // En este programa declaro un arreglo con 5 enteros
    int a[5] = {2, 4, 6, 8, 10};

    // Aquí declaro un apuntador p, que empieza apuntando a la primera posición del arreglo (a[0])
    int *p = a;

    // En esta línea muestro el valor que está en la posición 1 del arreglo, o sea a[1] = 4
    printf("(1) a[1] = %d\n", a[1]);

    // Aquí utilizo aritmética de apuntadores: *(a+3) significa moverme 3 posiciones en el arreglo.
    // Eso corresponde a a[3], que vale 8.
    printf("(2) *(a+3) = %d\n", *(a+3));

    // En esta línea uso *p++ que primero imprime el valor al que apunta p (a[0] = 2)
    // y después hace que p avance a la siguiente posición (ahora p apunta a a[1]).
    printf("(3) *p++ = %d\n", *p++);

    // Ahora uso *++p, que primero incrementa p (ahora apunta a a[2]) y luego imprime ese valor (a[2] = 6).
    printf("(4) *++p = %d\n", *++p);

    // Aquí p ya está en a[2]. Cuando pongo p[1], eso significa "a partir de donde está p, muévete 1".
    // Entonces imprime el valor de a[3], que es 8.
    printf("(5) p[1] = %d\n", p[1]);

    // En esta parte pongo *(p+2). Como p está en a[2], p+2 significa a[4], que vale 10.
    printf("(6) *(p+2) = %d\n", *(p+2));

    // Finalmente, calculo la diferencia entre la posición actual de p (que está en a[2]) y el inicio del arreglo (a).
    // Eso me da 2, porque hay dos posiciones de diferencia.
    printf("(7) p - a = %ld\n", p - a);

    return 0;
}
