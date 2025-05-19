#ifndef AST_H
#define AST_H

#include <stdlib.h>

// Tipos de nodos
typedef enum
{
    NODE_NUMBER,
    NODE_ADD,
    NODE_SUB,
    NODE_MUL,
    NODE_DIV
} NodeType;

// Definicion de un nodo
typedef struct Node
{
    NodeType type;
    int value; // para nodos de tipo NUMBER
    struct Node *left;
    struct Node *right;
} Node;

// Crear un nodo hoja de número
Node *create_number_node(int value);

// Crear un nodo de operación binaria
Node *create_binary_op_node(NodeType type, Node *left, Node *right);

// Borra el AST recursivamente
void free_ast(Node *node);

#endif