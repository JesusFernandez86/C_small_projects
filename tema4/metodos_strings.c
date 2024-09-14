// strlen() te devuelve la longitud de un string
 
// strcpy() --- char *strcpy(char *dest, const char *src);

#include <stdio.h>
#include <string.h>

int main()
{
    char src[50] = "Hola Mundo!";
    char dest[50];
    strcpy(dest, src);
    printf("La cadena de destino es: %s\n", dest);
    return 0;
}

// scanf(): Esta función se utiliza para leer datos formateados desde la entrada estándar (generalmente el teclado).
#include <stdio.h>

int main()
{
    int number;
    printf("Enter a number: ");
    scanf("%d", &number); // Lee un entero desde la entrada estándar
    printf("You entered: %d\n", number);
    return 0;
}

// getchar(): Esta función se utiliza para leer un solo carácter desde la entrada estándar.
#include <stdio.h>

int main()
{
    printf("Enter a character: ");
    char ch = getchar(); // Lee un carácter desde la entrada estándar
    printf("You entered: %c\n", ch);
    return 0;
}

// getc(): Similar a getchar(), pero puede leer desde cualquier flujo de entrada, no solo la entrada estándar.
#include <stdio.h>

int main()
{
    printf("Enter a character: ");
    char ch = getc(stdin); // Lee un carácter desde la entrada estándar
    printf("You entered: %c\n", ch);
    return 0;
}

// putchar(): Esta función se utiliza para escribir un solo carácter en la salida estándar.
#include <stdio.h>

int main()
{
    char ch = 'A';
    putchar(ch); // Escribe el carácter 'A' en la salida estándar
    return 0;
}

// putc(): Similar a putchar(), pero puede escribir en cualquier flujo de salida, no solo la salida estándar
#include <stdio.h>

int main()
{
    char ch = 'A';
    putc(ch, stdout); // Escribe el carácter 'A' en la salida estándar
    return 0;
}

// fgets(): Esta función se utiliza para leer una línea de texto desde un flujo de entrada.
#include <stdio.h>

int main()
{
    char str[50];
    printf("Enter a string: ");
    fgets(str, 50, stdin); // Lee una línea de texto desde la entrada estándar
    printf("You entered: %s", str);
    return 0;
}

// strcpy(): Esta función se utiliza para copiar una cadena a otra.
#include <stdio.h>
#include <string.h>

int main()
{
    char src[50] = "Hola Mundo!";
    char dest[50];
    strcpy(dest, src); // Copia la cadena src a dest
    printf("La cadena de destino es: %s\n", dest);
    return 0;
}

// strcat(): Esta función se utiliza para concatenar (unir) dos cadenas.
#include <stdio.h>
#include <string.h>

int main()
{
    char dest[50] = "Hola ";
    char src[50] = "Mundo!";
    strcat(dest, src); // Une la cadena src al final de dest
    printf("La cadena de destino es: %s\n", dest);
    return 0;
}

// strchr(): Esta función se utiliza para buscar la primera ocurrencia de un carácter en una cadena.
#include <stdio.h>
#include <string.h>

int main()
{
    char str[50] = "Hola Mundo!";
    char *p = strchr(str, 'M'); // Busca la primera ocurrencia de 'M' en str
    if (p)
    {
        printf("El carácter 'M' se encontró en la posición: %ld\n", p - str);
    }
    else
    {
        printf("El carácter 'M' no se encontró en la cadena.\n");
    }
    return 0;
}

// strcmp(): Esta función se utiliza para comparar dos cadenas.
#include <stdio.h>
#include <string.h>

int main()
{
    char str1[50] = "Hola";
    char str2[50] = "Hola";
    int result = strcmp(str1, str2); // Compara str1 y str2
    if (result == 0)
    {
        printf("Las cadenas son iguales.\n");
    }
    else
    {
        printf("Las cadenas son diferentes.\n");
    }
    return 0;
}

// strcasecmp(): Similar a strcmp(), pero ignora las diferencias de mayúsculas y minúsculas.
#include <stdio.h>
#include <string.h>

int main()
{
    char str1[50] = "Hola";
    char str2[50] = "hola";
    int result = strcasecmp(str1, str2); // Compara str1 y str2 ignorando las diferencias de mayúsculas y minúsculas
    if (result == 0)
    {
        printf("Las cadenas son iguales.\n");
    }
    else
    {
        printf("Las cadenas son diferentes.\n");
    }
    return 0;
}

// strstr(): Esta función se utiliza para buscar la primera ocurrencia de una subcadena en una cadena.
#include <stdio.h>
#include <string.h>

int main()
{
    char str[50] = "Hola Mundo!";
    char *p = strstr(str, "Mundo"); // Busca la primera ocurrencia de "Mundo" en str
    if (p)
    {
        printf("La subcadena 'Mundo' se encontró en la posición: %ld\n", p - str);
    }
    else
    {
        printf("La subcadena 'Mundo' no se encontró en la cadena.\n");
    }
    return 0;
}

/*
memcpy() se utiliza para copiar n bytes de un bloque de memoria a otro,
independientemente del tipo de datos. Esto significa que memcpy() puede utilizarse para copiar cualquier tipo de datos
(por ejemplo, estructuras, arrays, etc.).

strcpy() se utiliza específicamente para copiar cadenas de caracteres. Copia caracteres de la cadena fuente
a la cadena destino hasta que encuentra un carácter nulo ('\0').
Entonces, también copia el carácter nulo al final de la cadena destino.
*/
#include <stdio.h>
#include <string.h>

int main()
{
    char src[50] = "Hola Mundo!";
    char dest[50];
    memcpy(dest, src, strlen(src) + 1); // Copia la cadena src a dest
    printf("La cadena de destino es: %s\n", dest);
    return 0;
}

// strtok(): Esta función se utiliza para dividir una cadena en tokens (subcadenas) basándose en un conjunto de delimitadores.
#include <stdio.h>
#include <string.h>

int main()
{
    char str[50] = "Hola-Mundo!";
    char *token = strtok(str, "-"); // Divide str en tokens basándose en el delimitador '-'
    while (token != NULL)
    {
        printf("Token: %s\n", token);
        token = strtok(NULL, "-");
    }
    return 0;
}

// strncpy(): Similar a strcpy(), pero copia solo los primeros n caracteres de la cadena fuente.
#include <stdio.h>
#include <string.h>

int main()
{
    char src[50] = "Hola Mundo!";
    char dest[50];
    strncpy(dest, src, 4); // Copia los primeros 4 caracteres de src a dest
    dest[4] = '\0';        // Asegura que dest es una cadena válida
    printf("La cadena de destino es: %s\n", dest);
    return 0;
}

// strcspn(): Esta función se utiliza para buscar el primer carácter en una cadena que coincide con cualquier carácter en otra cadena.
#include <stdio.h>
#include <string.h>

int main()
{
    char str1[50] = "1234567890";
    char str2[50] = "567";
    int pos = strcspn(str1, str2); // Busca el primer carácter en str1 que coincide con cualquier carácter en str2
    printf("El primer carácter coincidente se encontró en la posición: %d\n", pos);
    return 0;
}