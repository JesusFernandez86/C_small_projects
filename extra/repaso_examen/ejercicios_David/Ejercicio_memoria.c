#include <stdio.h>
#include <stdlib.h>

/* Escribe un programa en C que solicite al usuario que ingrese un número entero n. 
Luego, el programa debe solicitar al usuario n números enteros y almacenarlos dinámicamente en un array. 
Después de almacenar los números, el programa debe calcular y mostrar la suma de todos los números ingresados.*/

int main() {
    int n;
    printf("Ingrese el numero de elementos: ");
    scanf("%d", &n);

    // Reservar memoria dinámica para el array
    int *numeros = (int*)malloc(n * sizeof(int));
    if (numeros == NULL) {
        printf("Error: No se pudo reservar memoria.");
        return 1;
    }

    // Leer los numeros ingresados por el usuario
    printf("Ingrese %d numeros enteros:\n", n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &numeros[i]);
    }

    // Calcular la suma de los numeros
    int suma = 0;
    for (int i = 0; i < n; i++) {
        suma += numeros[i];
    }

    // Mostrar la suma
    printf("La suma de los numeros ingresados es: %d\n", suma);

    free(numeros);

    return 0;
}
