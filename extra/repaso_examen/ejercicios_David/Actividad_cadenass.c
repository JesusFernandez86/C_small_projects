#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Función para leer una línea de texto de manera dinámica
char* leeLineaDinamica() {
    char *linea = NULL;
    size_t tam = 0;
    getline(&linea, &tam, stdin);
    linea[strcspn(linea, "\n")] = '\0'; // Eliminar el salto de línea
    return linea;
}

// Función para transformar las primeras letras de cada palabra a mayúsculas y las demás a minúsculas
void cambiaMayusculas(char *cadena) {
    int i = 0;
    while (cadena[i] != '\0') {
        if (i == 0 || cadena[i - 1] == ' ') {
            if (cadena[i] >= 'a' && cadena[i] <= 'z') {
                cadena[i] -= 32; // Convertir a mayúscula
            }
        } else {
            if (cadena[i] >= 'A' && cadena[i] <= 'Z') {
                cadena[i] += 32; // Convertir a minúscula
            }
        }
        i++;
    }
}

// Función para encriptar un mensaje utilizando dos diccionarios
void encriptaMensaje(char *mensaje) {
    char caracteres[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789";
    char reemplazos[] = "WXAHQFPIRVKBJDGMELNOYUTCZS7835462910";
    
    for (int i = 0; mensaje[i] != '\0'; i++) {
        if (mensaje[i] >= 'A' && mensaje[i] <= 'Z') {
            mensaje[i] = reemplazos[mensaje[i] - 'A'];
        } else if (mensaje[i] >= '0' && mensaje[i] <= '9') {
            mensaje[i] = reemplazos[mensaje[i] - '0' + 26];
        }
    }
}

// Función para encontrar y extraer los datos complejos dentro de corchetes
char* encuentraDatos(const char *mensaje) {
    char *inicio = strchr(mensaje, '[');
    char *fin = strchr(inicio, ']');
    if (inicio != NULL && fin != NULL) {
        char *datos = (char*)malloc(fin - inicio);
        strncpy(datos, inicio + 1, fin - inicio - 1);
        datos[fin - inicio - 1] = '\0';
        return datos;
    }
    return NULL;
}

// Función para separar los datos complejos en campos
void separaDatos(const char *datos, char **campos) {
    char *token = strtok((char*)datos, "-");
    int i = 0;
    while (token != NULL) {
        campos[i++] = token;
        token = strtok(NULL, "-");
    }
}

// Función para decodificar los campos de datos
void decodificaDatos(char **campos) {
    printf("Clave: %s\n", campos[0]);
    printf("Identificador: %s\n", campos[1]);
    printf("Especialidad: %s\n", campos[2]);
    printf("Estado: %s\n", campos[3]);
}

int main() {
    // Paso 1: Leer el mensaje
    printf("Ingrese el mensaje: ");
    char *mensaje = leeLineaDinamica();

    // Paso 2: Transformar las letras del mensaje
    cambiaMayusculas(mensaje);
    printf("Mensaje transformado: %s\n", mensaje);

    // Paso 3: Encriptar el mensaje
    encriptaMensaje(mensaje);
    printf("Mensaje encriptado: %s\n", mensaje);

    // Paso 4: Extraer los datos complejos
    char *datos = encuentraDatos(mensaje);
    printf("Datos complejos: %s\n", datos);

    // Paso 5: Separar los datos complejos en campos
    char *campos[4];
    separaDatos(datos, campos);

    // Paso 6: Decodificar los campos de datos
    decodificaDatos(campos);

    // Liberar memoria
    free(mensaje);
    free(datos);

    return 0;
}