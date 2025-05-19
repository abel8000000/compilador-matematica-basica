// Codegen: Generador de código en ensamblador
// Genera el código en ensamblador para evaluar la expresión representada por el AST
#include "codegen.h"
#include <stdio.h>

void generate_code(const Node *node, FILE *out)
{
    if (!node)
        return;

    switch (node->type)
    {
    case NODE_NUMBER:
        // Push el valor del nodo al stack
        fprintf(out, "    push %d\n", node->value);
        break;

    case NODE_ADD:
    case NODE_SUB:
    case NODE_MUL:
    case NODE_DIV:
        // Traversa el sub-arbol izquierdo y derecho, aplica el operador
        generate_code(node->left, out);
        generate_code(node->right, out);

        // Pop a los operandos: derecho al RBX, izquierdo al RAX
        fprintf(out, "    pop rbx\n");
        fprintf(out, "    pop rax\n");

        // Genera la operacion correspondiente
        if (node->type == NODE_ADD)
        {
            fprintf(out, "    add rax, rbx\n");
        }
        else if (node->type == NODE_SUB)
        {
            fprintf(out, "    sub rax, rbx\n");
        }
        else if (node->type == NODE_MUL)
        {
            fprintf(out, "    imul rax, rbx\n");
        }
        else
        {
            // Proceso de division
            fprintf(out, "    cqo\n");
            fprintf(out, "    idiv rbx\n");
        }

        // Push el resultado al stack
        fprintf(out, "    push rax\n");
        break;

    default:
        // Tipo de nodo desconocido
        break;
    }
}
