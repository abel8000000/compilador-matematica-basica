#ifndef EVALUATOR_H
#define EVALUATOR_H

#include "ast.h"

// Evalua recursivamente el AST y devuelve el resultado numerico
int evaluate_ast(const Node *node);

#endif