#include "mathParser.h"

int parse(Token *tokens, int *result)
{
    int pos = 0; // Posicion actual en el array de tokens

    if (tokens[pos].type != TOKEN_NUMBER)
    { // Retorna 0 si el primer token no es un numero
        return 0;
    }

    *result = tokens[pos].value; // Asigna el valor del primer token al resultado
    pos++;                       // Avanza al siguiente token

    while (tokens[pos].type != TOKEN_END)
    {                                    // Loop de parseo
        int operator = tokens[pos].type; // Guarda el operador actual
        pos++;                           // Avanza al siguiente token

        if (tokens[pos].type != TOKEN_NUMBER)
        { // Retorna 0 si el siguiente token no es un numero
            return 0;
        }

        int operand = tokens[pos].value; // Guarda el operando actual
        pos++;                           // Avanza al siguiente token

        switch (operator)
        { // Realiza la operacion correspondiente
        case TOKEN_ADD:
            *result += operand;
            break;
        case TOKEN_SUBTRACT:
            *result -= operand;
            break;
        case TOKEN_MULTIPLY:
            *result *= operand;
            break;
        case TOKEN_DIVIDE:
            *result /= operand;
            break;
        default:
            return 0;
        }
    }
    return 1; // Retorna 1 si la expresion es valida
}