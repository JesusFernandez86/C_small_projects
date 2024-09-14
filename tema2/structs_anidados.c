#include <stdio.h>

struct direccion
{
    char calle[50];
    int numero;
    int cp;
    char provincia[25];
};

struct usuario
{
    char nombre[10];
    char apellido[10];
    char identif[9];
    int edad;
    float altura;
    struct direccion dire;
};

int main()
{

    // inicializamos la estructura y asignamos valores !!!
    struct usuario user = {"Maxi", "Fernandez", "123456789", 44, 1.77, {"Paseo de la Castellana", 200, 28004, "Madrid"}};

    // imprimimos la estructura como si fuese un registro de una base de datos (aunque los ultimos 4 valores derivan de una estructura de estructura) :)
    printf("[ %s , %s , %s , %d , %f , %s , %d , %d , %s ] \n", user.nombre, user.apellido, user.identif, user.edad, user.altura, user.dire.calle, user.dire.numero, user.dire.cp, user.dire.provincia);

    return 0;
}