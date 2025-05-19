// Lexer: Analizador lexico
// Divide el texto de entrada en tokens

#include "lexer.h"
#include <stdio.h>

// Estado del lexer: cadena de entrada y posición actual
static const char *input;
static size_t pos;

// Función para inicializar el lexer con la cadena de entrada
void init_lexer(const char *text)
{
    input = text;
    pos = 0;
}

// Función para obtener el siguiente token de la cadena de entrada
Token get_next_token(void)
{
    Token token;
    char current = input[pos];

    // Saltar espacios en blanco
    while (current && isspace((unsigned char)current))
    {
        pos++;
        current = input[pos];
    }

    // Verifica si se ha llegado al final de la cadena
    if (current == '\0')
    {
        token.type = TOKEN_EOF;
        token.value = 0;
        return token;
    }

    // Verifica si el carácter actual es un dígito
    if (isdigit((unsigned char)current))
    {
        int value = 0;
        // Combina los digitos consecutivos en un mismo número
        while (isdigit((unsigned char)current))
        {
            value = value * 10 + (current - '0');
            pos++;
            current = input[pos];
        }
        token.type = TOKEN_NUMBER;
        token.value = value;
        return token;
    }

    pos++;

    // Verifica si el carácter actual es un operador o un paréntesis
    switch (current)
    {
    case '+':
        token.type = TOKEN_PLUS;
        break;
    case '-':
        token.type = TOKEN_MINUS;
        break;
    case '*':
        token.type = TOKEN_MUL;
        break;
    case '/':
        token.type = TOKEN_DIV;
        break;
    case '(':
        token.type = TOKEN_LPAREN;
        break;
    case ')':
        token.type = TOKEN_RPAREN;
        break;
    default:
        token.type = TOKEN_INVALID;
        break;
    }
    token.value = 0;
    return token;
}