// Evaluator: Analisis Semantico
// Recorre el arbol de sintaxis abstracta (AST) y evalua la expresion
#include "evaluator.h"
#include <stdio.h>
#include <stdlib.h>

int evaluate_ast(const Node *node)
{
    if (!node)
    {
        fprintf(stderr, "Error: nodo nulo en evaluate_ast()\n");
        exit(EXIT_FAILURE);
    }
    switch (node->type)
    {
    case NODE_NUMBER:
        return node->value;
    case NODE_ADD:
        return evaluate_ast(node->left) + evaluate_ast(node->right);
    case NODE_SUB:
        return evaluate_ast(node->left) - evaluate_ast(node->right);
    case NODE_MUL:
        return evaluate_ast(node->left) * evaluate_ast(node->right);
    case NODE_DIV:
    {
        int rhs = evaluate_ast(node->right);
        if (rhs == 0)
        {
            fprintf(stderr, "Error: division por cero\n");
            exit(EXIT_FAILURE);
        }
        return evaluate_ast(node->left) / rhs;
    }
    default:
        fprintf(stderr, "Error: tipo de nodo desconocido %d en evaluate_ast()\n", node->type);
        exit(EXIT_FAILURE);
    }
}
