#ifndef CODEGEN_H
#define CODEGEN_H

#include "ast.h"
#include <stdio.h>

// Emite instrucciones en assembly para evaluar la expresión representada por el AST
// El resultado se deja en el stack
void generate_code(const Node *node, FILE *out);

#endif