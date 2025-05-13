// Directivas que evitan la inclusion multiple en el proyecto
#ifndef TOKENIZER_H
#define TOKENIZER_H

// Lista de distintos tipos de tokens
// Valores numericos, operadores y fin de la cadena
typedef enum {
    TOKEN_NUMBER,
    TOKEN_ADD,
    TOKEN_SUBTRACT,
    TOKEN_MULTIPLY,
    TOKEN_DIVIDE,
    TOKEN_END
} TokenType;

// Definicion de la estructura Token
typedef struct {
    TokenType type; // Tipo de token
    int value;      // Valor del token (solo para TOKEN_NUMBER)
} Token;

// Prototipo de la funcion tokenize
// Recibe una cadena de caracteres y devuelve un puntero a un array de tokens
Token *tokenize(const char *input);

#endif