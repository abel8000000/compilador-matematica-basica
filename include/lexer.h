#ifndef LEXER_H
#define LEXER_H

#include <stddef.h>
#include <ctype.h>

// Tipos de tokens
typedef enum
{
    TOKEN_NUMBER,
    TOKEN_PLUS,
    TOKEN_MINUS,
    TOKEN_MUL,
    TOKEN_DIV,
    TOKEN_LPAREN,
    TOKEN_RPAREN,
    TOKEN_EOF,
    TOKEN_INVALID
} TokenType;

// Estructura de un token
typedef struct
{
    TokenType type;
    int value; // Importante solo para TOKEN_NUMBER
} Token;

// Inicializa el lexer con la cadena de entrada
void init_lexer(const char *text);

// Obtiene el siguiente token de la cadena de entrada
Token get_next_token(void);

#endif