// Main: Driver para el compilador de aritmética simple
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "parser.h"
#include "evaluator.h"
#include "codegen.h"
#include "ast.h"

// Constantes
#define LINE_MAX 256
#define IO_DIR "i-o"
#define INPUT_FILE IO_DIR "/input.txt"
#define OUTPUT_FILE IO_DIR "/output.txt"

int main(void)
{
    // Manejo de archivos de entrada y salida
    FILE *fin = fopen(INPUT_FILE, "r");
    FILE *fout = fopen(OUTPUT_FILE, "w");
    char line[LINE_MAX];

    if (!fin)
    {
        perror("Error al abrir el archivo de entrada");
        return EXIT_FAILURE;
    }
    if (!fout)
    {
        perror("Error al abrir el archivo de salida");
        fclose(fin);
        return EXIT_FAILURE;
    }

    // Procesar cada línea del archivo de entrada
    while (fgets(line, sizeof(line), fin))
    {
        // Borra el salto de línea al final de la cadena
        size_t len = strlen(line);
        if (len > 0 && line[len - 1] == '\n')
        {
            line[len - 1] = '\0';
        }

        // Recortar espacios en blanco
        char *start = line;
        while (*start && isspace((unsigned char)*start))
        {
            start++;
        }

        // Se ignoran las líneas vacías o comentarios
        if (line[0] == '\0' || line[0] == '#')
            continue;

        // Se hace el analisis sintáctico y se construye el AST
        Node *root = parse(line);
        if (!root)
        {
            fprintf(stderr, "Parsing falló en la linea: %s\n", line);
            continue;
        }

        // Evaluar el AST
        int result = evaluate_ast(root);
        fprintf(fout, "; %s\n", line);
        fprintf(fout, "Resultado = %d\n\n", result);

        // Se genera el código ensamblador
        fprintf(fout, "; %s\n", line);
        generate_code(root, fout);
        fprintf(fout, "; fin de la expresión\n\n");

        // Limpiar el AST
        free_ast(root);
    }

    fclose(fin);
    fclose(fout);
    return EXIT_SUCCESS;
}