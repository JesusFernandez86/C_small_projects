
#include <stdio.h>

struct usuario
{
    char nombre[10];
    char apellido[10];
    char identif[9];
    int edad;
    float altura;
    char direccion[100];
};

int main()
{
    // inicializamos la estructura y asignamos valores !!!
    struct usuario user = {"Maxi", "Fernandez", "123456789", 44, 1.77, "Paseo de la Castellana 200, 28004, Madrid"};

    // imprimimos la estructura como si fuese un registro de una base de datos :)
    printf("[ %s , %s , %s , %d , %f , %s ] \n", user.nombre, user.apellido, user.identif, user.edad, user.altura, user.direccion);

    return 0;
}
