#include <stdio.h>
#include <stdlib.h>
#include <windows.h>

typedef struct
{
    int speed_move;
    int window_size;
    int num_iterations;
} animation_config_t;

char *get_message()
{
    char *message = NULL;
    size_t size = 0;
    printf("Enter the message to display: ");
    getline(&message, &size, stdin);
    if (!message)
    {
        printf("Memory allocation error.\n");
        exit(EXIT_FAILURE); // si no se puede reservar memoria para el mensaje, la ejecucion del programa se termina
    }
    message[strcspn(message, "\n")] = 0;
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
    char *display_window = (char *)malloc(config.window_size); // reserva memoria para el display_window y se le asigna el tamaño de la ventana antes calculado
    if (!display_window)
    {
        printf("Memory allocation error.\n");
        return;
    }

    for (int iteration = 0; iteration < config.num_iterations; iteration++)
    {
        memset(display_window, ' ', config.window_size); // rellena el display_window (pantalla led) con espacios
        display_window[config.window_size] = '\0';       // agrega un caracter nulo al final del display_window

        for (int i = 0; i < message_length + config.window_size; i++)
        {
            memmove(display_window, display_window + 1, config.window_size - 1); // mueve el display_window una posición a la izquierda en cada iteracion
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
    char *message = get_message();
    animation_config_t config = configure_animation(message);
    animate_text(message, config);
    free(message);
    return 0;
}