// Parser: Analizador sintáctico
// Se asegura que se cumpla la gramatica, y construye un árbol de sintaxis abstracta (AST)
#include <stdio.h>
#include <stdlib.h>
#include "lexer.h"
#include "ast.h"

// Declaraciones de nodos no terminales de la gramática
static Node *parse_expression(void);
static Node *parse_term(void);
static Node *parse_factor(void);
static void eat(TokenType expected);

// Token actual
static Token current_token;

// Inicializa el analizador sintáctico
void init_parser(const char *text)
{
    init_lexer(text);
    current_token = get_next_token();
}

// Consume el token esperado y obtiene el siguiente token
// Si el token actual no es el esperado, imprime un mensaje de error y termina el programa
static void eat(TokenType expected)
{
    if (current_token.type == expected)
    {
        current_token = get_next_token();
    }
    else
    {
        fprintf(stderr, "Error de sintaxis: se esperaba token %d, se obtuvo %d\n", expected, current_token.type);
        exit(EXIT_FAILURE);
    }
}

// Punto de entrada
// Inicializa el estado del lexer y el parser, comienza el análisis sintáctico, verifica si se ha llegado al final de la cadena
// Devuelve la raíz del árbol de sintaxis abstracta (AST)
Node *parse(const char *text)
{
    init_parser(text);
    Node *root = parse_expression();
    if (current_token.type != TOKEN_EOF)
    {
        fprintf(stderr, "Error de sintaxis: token inesperado al final\n");
        exit(EXIT_FAILURE);
    }
    return root;
}

// expression -> term ((PLUS | MINUS) term)*
static Node *parse_expression(void)
{
    Node *node = parse_term();
    while (current_token.type == TOKEN_PLUS || current_token.type == TOKEN_MINUS)
    {
        TokenType op = current_token.type;
        eat(op);
        Node *right = parse_term();
        if (op == TOKEN_PLUS)
            node = create_binary_op_node(NODE_ADD, node, right);
        else
            node = create_binary_op_node(NODE_SUB, node, right);
    }
    return node;
}

// term -> factor ((MUL | DIV) factor)*
static Node *parse_term(void)
{
    Node *node = parse_factor();
    while (current_token.type == TOKEN_MUL || current_token.type == TOKEN_DIV)
    {
        TokenType op = current_token.type;
        eat(op);
        Node *right = parse_factor();
        if (op == TOKEN_MUL)
            node = create_binary_op_node(NODE_MUL, node, right);
        else
            node = create_binary_op_node(NODE_DIV, node, right);
    }
    return node;
}

// factor -> NUMBER | LPAREN expression RPAREN
static Node *parse_factor(void)
{
    if (current_token.type == TOKEN_NUMBER)
    {
        int value = current_token.value;
        eat(TOKEN_NUMBER);
        return create_number_node(value);
    }
    else if (current_token.type == TOKEN_LPAREN)
    {
        eat(TOKEN_LPAREN);
        Node *node = parse_expression();
        eat(TOKEN_RPAREN);
        return node;
    }
    else
    {
        fprintf(stderr, "Error de sintaxis: token inesperado en el factor: %d\n", current_token.type);
        exit(EXIT_FAILURE);
    }
}
