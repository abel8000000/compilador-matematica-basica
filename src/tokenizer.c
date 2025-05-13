#include <stdlib.h>
#include <ctype.h>
#include "tokenizer.h"

Token *tokenize(const char *input)
{// Convierte cadena de caracteres a array de tokens
    Token *tokens = malloc(256 * sizeof(Token)); // Reserva memoria para 256 tokens
    int pos = 0;                                 // Posicion actual en el array de tokens

    while (*input)
    {
        if (isdigit(*input))
        { // Si el caracter es un digito, se convierte a entero y se guarda en el token
            tokens[pos].type = TOKEN_NUMBER;
            tokens[pos].value = strtol(input, (char **)&input, 10); // Convierte la cadena a entero
            pos++;
        }
        else
        {
            switch (*input)
            { // Si el caracter es un operador, se agrega el token correspondiente
            case '+':
                tokens[pos].type = TOKEN_ADD;
                pos++;
                input++;
                break;
            case '-':
                tokens[pos].type = TOKEN_SUBTRACT;
                pos++;
                input++;
                break;
            case '*':
                tokens[pos].type = TOKEN_MULTIPLY;
                pos++;
                input++;
                break;
            case '/':
                tokens[pos].type = TOKEN_DIVIDE;
                pos++;
                input++;
                break;
            default:
                // Omite cualquier otro caracter (ej. espacios)
                input++;
                break;
            }
        }
    }

    // Marca el final del array de tokens, retorna el array
    tokens[pos].type = TOKEN_END;
    return tokens;
}