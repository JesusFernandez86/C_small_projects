# Text Animation Program

This program animates a user-inputted text message by moving it across the console window. The user can configure the speed of the animation and the number of iterations.

## Program Structure

The program is divided into several functions:

- `get_message`: Prompts the user to enter the message to be animated.
- `configure_animation`: Asks the user to specify the animation speed and the number of iterations.
- `animate_text`: Performs the text animation based on the user's input and configuration.

## Compilation

To compile the program, you need to have the GCC compiler installed on your system. If you don't have GCC installed, you can download it from the [GCC official website](https://gcc.gnu.org/).

Once you have GCC installed, you can compile the program using the following command:

```bash
gcc -o text_animation practica.c
```
This command tells GCC to compile the source code in practica.c and output the executable to a file named text_animation.

## Execution

After compiling the program, you can run it using the following command:
```bash
./text_animation
```
Follow the prompts to enter your message and configure the animation parameters