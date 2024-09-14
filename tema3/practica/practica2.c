#include <stdio.h>
#include <stdlib.h>
#include <windows.h>

#define TAM_BLOQUE 10

typedef struct
{
    int speed_move;
    int window_size;
    int num_iterations;
} animation_config_t;

char *get_message()
{
    int buffer_size = TAM_BLOQUE;
    char *message = (char *)malloc(TAM_BLOQUE);
    if (message == NULL)
    {
        fprintf(stderr, "Error: Unable to allocate memory.\n");
        return NULL;
    }

    int number_of_characters = 0;
    char c = 0;
    c = getchar();

    while (c != '\n')
    {
        message[number_of_characters] = c;
        number_of_characters++;
        if (number_of_characters == buffer_size)
        {
            buffer_size += TAM_BLOQUE;
            char *newmessage = (char *)realloc(message, buffer_size);
            if (newmessage == NULL)
            {
                fprintf(stderr, "Error: Unable to reallocate memory.\n");
                return NULL;
            }
            message = newmessage;
        }
        c = getchar();
    }
    message[number_of_characters] = '\0';
    return message;
}

animation_config_t configure_animation(char *message)
{
    animation_config_t config;
    printf("Enter movement speed (1-10): ");
    while (scanf("%d", &config.speed_move) != 1 || config.speed_move < 1 || config.speed_move > 10)
    {
        printf("Invalid speed value. Enter a number between 1 and 10: ");
        while (getchar() != '\n');
    }

    printf("Enter number of iterations: ");
    while (scanf("%d", &config.num_iterations) != 1)
    {
        printf("Invalid iteration value, please enter a number: ");
        while (getchar() != '\n');
    }
    // he preferido directamente coger el tamaño del mensaje y sumarle 10 caracteres en vez de pedirle al usuario que meta manualmente el tamaño de la ventana para evitar posibles errores en los que se introduzca un tamaño de ventana menor al tamaño del mensaje
    config.window_size = strlen(message) + 5;

    return config;
}

void animate_text(char *message, animation_config_t config)
{
    int message_length = strlen(message);
    char *display_window = (char *)malloc(config.window_size); // reserva memoria para el display_window y se le asigna el tamaño de la ventana
    if (!display_window)
    {
        fprintf(stderr, "Error: Unable to allocate memory.\n");
        return;
    }

    for (int iteration = 0; iteration < config.num_iterations; iteration++)
    {
        memset(display_window, ' ', config.window_size); // rellena el display_window (pantalla led) con espacios en todas las posiciones
        display_window[config.window_size] = '\0';       // agrega un caracter nulo al final del display_window

        for (int i = 0; i < message_length + config.window_size; i++)
        {
            for (int j = 0; j < config.window_size - 1; j++)
            {
                display_window[j] = display_window[j + 1];
            }
            display_window[config.window_size - 1] = (i < message_length) ? message[i] : ' ';

            printf("\r%s", display_window);
            fflush(stdout);
            Sleep(1000 / config.speed_move);
        }
    }
    free(display_window);
}

int main()
{
    printf("Enter the message to display: ");
    char *message = get_message();
    animation_config_t config = configure_animation(message);
    animate_text(message, config);
    free(message);
    return 0;
}