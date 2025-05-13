// Librerias estandar
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

// Headers del proyecto
#include "tokenizer.h"
#include "mathParser.h"

int main(int argCount, char *argVector[])
{
    char input[256]; // Array de caracteres para almacenar la entrada

    if (argCount > 1)
    {                                          // Si se pasa un argumento, se asume que es el nombre de un archivo
        FILE *file = fopen(argVector[1], "r"); // Se abre el archivo en modo lectura
        if (!file)
        { // Verifica si el archivo se abre correctamente
            perror("Error al abrir el archivo");
            return EXIT_FAILURE;
        }
        if (!fgets(input, sizeof(input), file))
        { // Verifica si se lee correctamente la cadena
            fprintf(stderr, "Error al leer el archivo\n");
            fclose(file);
            return EXIT_FAILURE;
        }
        fclose(file); // Se cierra el archivo
    }
    else
    { // Si no se pasa un argumento, se pide al usuario que ingrese una expresión
        printf("Ingrese una expresión matemática: ");
        fgets(input, sizeof(input), stdin);
    }

    // Se elimina el salto de línea al final de la cadena
    size_t len = strlen(input);
    if (len > 0 && input[len - 1] == '\n')
    {
        input[len - 1] = '\0';
    }

    // Se guarda el array de tokens que devuelve la funcion tokenize
    Token *tokens = tokenize(input);

    int result;
    // parse procesa el array de tokens y devuelve el resultado
    if (parse(tokens, &result))
    { // Si la expresión es válida, se imprime el resultado
        printf("Resultado: %d\n", result);
    }
    else
    { // Si la expresión no es válida, se imprime un mensaje de error
        printf("Expresion invalida\n");
    }

    // Se libera la memoria asignada para los tokens, se termina el programa
    free(tokens);
    return 0;
}
