#include <stdio.h>
#include <ctype.h>
#include <stdbool.h>
/* 
Escribe un programa en C que solicite al usuario que ingrese una cadena de caracteres. 
El programa debe realizar las siguientes operaciones:
- Contar la cantidad de caracteres en la cadena ingresada (sin contar el carácter nulo '\0' al final).
- Calcular la cantidad de palabras en la cadena. Se considera que una palabra está delimitada por espacios en blanco.
- Reemplazar todas las vocales en la cadena por el carácter '*' (asterisco).
- Imprimir la cadena resultante después de realizar las operaciones anteriores.
El programa debe cumplir con las siguientes especificaciones:
- Debe utilizar funciones para realizar cada una de las operaciones mencionadas.
- No debe utilizar funciones predefinidas de bibliotecas como strlen(), strtok(), strcpy(), etc., 
para calcular la longitud de la cadena, contar palabras o realizar el reemplazo de vocales.

*/


//Soución sin usar bibliotecas:

int contarCaracteres(const char *cadena) {
    int contador = 0;
    while (*cadena != '\0') {
        contador++;
        cadena++;
    }
    return contador;
}

int contarPalabras(const char *cadena) {
    int contador = 0;
    bool dentroPalabra = false;

    while (*cadena != '\0') {
        if (*cadena == ' ' || *cadena == '\t' || *cadena == '\n') {
            dentroPalabra = false;
        } else if (dentroPalabra == 0) {
            dentroPalabra = true;
            contador++;
        }
        cadena++;
    }
    return contador;
}

void reemplazarVocales(char *cadena) {
    while (*cadena != '\0') {
        switch (*cadena) {
            case 'a':
            case 'e':
            case 'i':
            case 'o':
            case 'u':
            case 'A':
            case 'E':
            case 'I':
            case 'O':
            case 'U':
                *cadena = '*';
                break;
        }
        cadena++;
    }
}



//Solucion con funciones de cadenas


#include <stdio.h>
#include <string.h>

int contarCaracteres(const char *cadena) {
  
   int longitud = strlen(cadena);

    return longitud;
}

int contarPalabras(const char *cadena) {
    int contador = 0;
    char *token = strtok(cadena, " ");
    while (token != NULL) {
        contador++;
        token = strtok(NULL, " ");
    }
    return contador;
}


void reemplazarVocales(char *cadena) {
    for (int i = 0; cadena[i] != '\0'; i++) {
        switch (cadena[i]) {
            case 'a':
            case 'e':
            case 'i':
            case 'o':
            case 'u':
            case 'A':
            case 'E':
            case 'I':
            case 'O':
            case 'U':
                cadena[i] = '*';
                break;
        }
    }
}
