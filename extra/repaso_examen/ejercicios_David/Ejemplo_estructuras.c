#include <stdio.h>
#include <math.h>


/*
Necesitamos representar diferentes tipos de formas geométricas, 
cada una con diferentes propiedades. 

Además de calcular el área, queremos calcular otros atributos específicos para cada tipo 
de forma (el perímetro para un cuadrado y el diámetro para un círculo).
*/

// Definición de estructuras
struct Circulo {
    float radio;
};

struct Rectangulo {
    float base;
    float altura;
};

struct Cuadrado {
    float lado;
};

// Definición de la unión para almacenar cualquier tipo de figura
union Figura {
    struct Circulo circulo;
    struct Rectangulo rectangulo;
    struct Cuadrado cuadrado;
};

// Definición del tipo de dato para el tipo de figura
enum TipoFigura {
    CIRCULO,
    RECTANGULO,
    CUADRADO
};

int main() {
    union Figura figura;
    enum TipoFigura tipo;
    float area, perimetro, diametro;

    printf("Seleccione el tipo de figura:\n");
    printf("1. Círculo\n");
    printf("2. Rectángulo\n");
    printf("3. Cuadrado\n");
    printf("Ingrese su opción: ");
    scanf("%d", &tipo);

    switch (tipo) {
        case CIRCULO:
            printf("Ingrese el radio del círculo: ");
            scanf("%f", &figura.circulo.radio);
            area = M_PI * figura.circulo.radio * figura.circulo.radio;
            diametro = 2 * figura.circulo.radio;
            printf("El área del círculo es: %.2f\n", area);
            printf("El diámetro del círculo es: %.2f\n", diametro);
            break;
        case RECTANGULO:
            printf("Ingrese la base del rectángulo: ");
            scanf("%f", &figura.rectangulo.base);
            printf("Ingrese la altura del rectángulo: ");
            scanf("%f", &figura.rectangulo.altura);
            area = figura.rectangulo.base * figura.rectangulo.altura;
            perimetro = 2 * (figura.rectangulo.base + figura.rectangulo.altura);
            printf("El área del rectángulo es: %.2f\n", area);
            printf("El perímetro del rectángulo es: %.2f\n", perimetro);
            break;
        case CUADRADO:
            printf("Ingrese el lado del cuadrado: ");
            scanf("%f", &figura.cuadrado.lado);
            area = figura.cuadrado.lado * figura.cuadrado.lado;
            perimetro = 4 * figura.cuadrado.lado;
            printf("El área del cuadrado es: %.2f\n", area);
            printf("El perímetro del cuadrado es: %.2f\n", perimetro);
            break;
        default:
            printf("Opción no válida.\n");
            return 1; // Salir del programa con código de error
    }

    return 0;
}