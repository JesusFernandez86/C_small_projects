#include <stdio.h>
#include <stdlib.h>

enum menu
{
    alta = 1,
    baja,
    modificacion,
    salir
};

int main()
{
    int opcion = 0;
    enum menu user;
    printf(" 1- Alta de registro \n 2- Baja de registro \n 3- Modificación de registro \n 4- Salir\n");

    opcion = getchar();
    /*
    The variable opcion is presumably a character that represents a digit. 
    By subtracting the ASCII value of '0' from opcion, we get the integer representation of that digit.
    For instance, if opcion is the character '2', then opcion - '0' would be 50 - 48, which equals 2. 
    The result is then assigned to the variable user.
    */
    user = opcion - '0'; 

    switch (user)
    {
    case alta:
        printf("Se va a dar de alta un registro \n");
        break;
    case baja:
        printf("Se va a dar de baja un registro \n");
        break;
    case modificacion:
        printf("Se va a modificar un registro \n");
        break;
    case salir:
        printf("Fin Programa \n");
        break;
    default:
        printf("Error! Valor no permitido \n");
        break;
    }

    return 0;
};