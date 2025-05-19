// AST: Arbol de Sintaxis Abstracta
// Define la representacion en memoria de la expresion analizada gramaticalmente
#include "ast.h"
#include <stdlib.h>
#include <stdio.h>

// Crear un nodo hoja de número
Node *create_number_node(int value)
{
    Node *node = (Node *)malloc(sizeof(Node));
    if (!node)
    {
        perror("Fallo al asignar memoria para el nodo de número");
        exit(EXIT_FAILURE);
    }
    node->type = NODE_NUMBER;
    node->value = value;
    node->left = node->right = NULL;
    return node;
}

// Crear un nodo que enlaza dos nodos hijos con el operador correspondiente
Node *create_binary_op_node(NodeType type, Node *left, Node *right)
{
    Node *node = (Node *)malloc(sizeof(Node));
    if (!node)
    {
        perror("Fallo al asignar memoria para el nodo de operación binaria");
        exit(EXIT_FAILURE);
    }
    node->type = type;
    node->value = 0;
    node->left = left;
    node->right = right;
    return node;
}

// Borra el AST recursivamente para liberar memoria
void free_ast(Node *node)
{
    if (!node)
        return;
    free_ast(node->left);
    free_ast(node->right);
    free(node);
}
