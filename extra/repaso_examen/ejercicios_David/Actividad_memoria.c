#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#define MAX_VENTANA 80
char* leerMensaje() {
    char buffer[100]; 
    printf("Ingrese el mensaje a animar: "); 
    fgets(buffer, sizeof(buffer), stdin); 
    buffer[strcspn(buffer, "\n")] = '\0'; //elimino salto linea

    // Calcular la longitud del mensaje
    int longitud = strlen(buffer);

    // Asignar memoria dinámica para almacenar el mensaje y copiarlo
    char *mensaje = (char*)malloc(longitud + 1); // Se reserva memoria para el mensaje
    if (mensaje == NULL) { // nullcheck
        printf("Error: No se pudo reservar memoria."); 
        exit(1);
    }
    strcpy(mensaje, buffer); // Copiar el contenido del buffer

    return mensaje; //puntero al mensaje almacenado dinámicamente
}

void configurarAnimacion(int *velocidad) {
    printf("Ingrese la velocidad de desplazamiento (en segundos): "); 
    scanf("%d", velocidad); //
}

void animarTexto(const char *mensaje, int velocidad) {
    int longitud = strlen(mensaje);
    int inicio = 0;

    while (inicio < longitud + MAX_VENTANA) { 
        printf("\r"); // Volver al principio de la línea
        for (int i = 0; i < MAX_VENTANA; i++) {
            if (inicio + i < longitud) { 
                putchar(mensaje[inicio + i]); // Imprimir el carácter del mensaje en la posición actual
            } else {
                putchar(' '); // Si no hay más caracteres en el mensaje, imprimir un espacio en blanco
            }
        }
        fflush(stdout); // Forzar la salida del búfer stdout
        inicio++; // Avanzar al siguiente segmento del mensaje
        usleep(velocidad * 1000000); // Pausa la ejecución
    }
}

int main() {
    char *mensaje; 
    int velocidad; 

    mensaje = leerMensaje(); 
    configurarAnimacion(&velocidad); 

    system("clear || cls");

    animarTexto(mensaje, velocidad);

    free(mensaje);

    return 0;
}
