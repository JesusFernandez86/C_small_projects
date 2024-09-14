/*
Necesitamos representar diferentes tipos de formas geométricas,
cada una con diferentes propiedades.

Además de calcular el área, queremos calcular otros atributos específicos para cada tipo
de forma (el perímetro para un cuadrado y el diámetro para un círculo).
*/

#include <stdio.h>
#include <stdlib.h>
#define PI 3.14

typedef struct circle_t
{
    int radius;
} Circle;

typedef struct square_t
{
    int side;
} Square;

typedef struct rectangle_t
{
    int small_side;
    int large_side;
} Rectangle;

union Figures
{
    Circle circle;
    Square square;
    Rectangle rectangle;
};

enum figure_kind
{
    CIRCLE = 1,
    SQUARE,
    RECTANGLE
};

int main()
{
    float area, perimeter, diameter;
    union Figures figures;
    enum figure_kind choice = 0;

    while (choice < 1 || choice > 4)
    {
        printf("Invalid value entered, please enter a valid value \n");
        printf("Enter the figure you want to calculate: \n");
        printf("1 = Circle \n");
        printf("2 = Square \n");
        printf("3 = Rectangle \n");
        scanf("%d", &choice);
        while (getchar() != '\n')
            ;
    }
    switch (choice)
    {
    case CIRCLE:
        printf("Enter the circle radius \n");
        scanf("%d", &figures.circle.radius);
        while (getchar() != '\n')
            ;
        area = PI * (figures.circle.radius * figures.circle.radius);
        perimeter = 2 * PI * figures.circle.radius;
        printf("The area is %f and the perimeter is %f \n", area, perimeter);
        break;
    case SQUARE:
        printf("Enter the square side \n");
        scanf("%d", &figures.square.side);
        while (getchar() != '\n')
            ;
        area = figures.square.side * figures.square.side;
        perimeter = 4 * figures.square.side;
        printf("The area is %f and the perimeter is %f \n", area, perimeter);
        break;
    case RECTANGLE:
        printf("Enter the large side \n");
        scanf("%d", &figures.rectangle.large_side);
        while (getchar() != '\n')
            ;
        printf("Enter the small side \n");
        scanf("%d", &figures.rectangle.small_side);
        while (getchar() != '\n')
            ;
        area = figures.rectangle.small_side * figures.rectangle.large_side;
        perimeter = (2 * figures.rectangle.small_side) + (2 * figures.rectangle.large_side);
        printf("The area is %f and the perimeter is %f \n", area, perimeter);
        break;
    default:
        break;
    }

    return 0;
}