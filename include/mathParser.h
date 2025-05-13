// Directivas que evitan la inclusion multiple en el proyecto
#ifndef PARSER_H
#define PARSER_H

// Se incluye porque se necesita la definicion de la estructura Token
#include "tokenizer.h"

// Declaracion de la funcion parse
// Se encarga de procesar el array de tokens y devolver el resultado
// Recibe un puntero a un array de tokens y un puntero a un entero donde se almacenara el resultado
int parse(Token *tokens, int *result);

#endif