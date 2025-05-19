
# Compilador Matemática Básica
Un compilador simple que procesa operaciones aritméticas básicas, las evalúa, y genera el código en lenguaje ensamblador correspondiente.

Trabajo final de Teoría de la Computación, 2025-01

## Resumen
El proyecto consiste de un compilador que evalua las siguientes operaciones matemáticas:
- Suma ( + )
- Resta ( - )
- Multiplicación ( * )
- División ( / )
- Agrupación con paréntesis

El compilador procesa una o más expresiones de entrada, genera un AST (Árbol de sintaxis abstracta), evalúa las expresiones, y devuelve el resultado junto a las instrucciones necesarias para realizar la operación en lenguaje ensamblador.

## Requisitos

- Compilador GCC
- Utilidad Make (CMake)

## Construir el proyecto

Clona el repositorio y construyelo usando Make

```bash
# Clonar el repositorio
git clone https://github.com/abel8000000/compilador-matematica-basica.git
cd compilador-matematica-basica

# Construir el proyecto
make
```

## Ejecutar el compilador

1. En el archivo `i-o/input.txt` escribe las expresiones que quieras, una por línea:
   ```
   2 + 3 * 4
   (5 + 3) * 2
   10 / 2 - 1
   ```

2. Ejecuta el compilador:
   ```bash
   ./compilador
   ```

3. Los resultados se escribirán en el archivo `i-o/output.txt`

## Formato de la entrada

Escribe una expresión matemática por línea en `i-o/input.txt`. El compilador soporta:
- Números enteros
- Operadores básicos: +, -, *, /
- Paréntesis para agrupar expresiones

## Output Format

Para cada expresión, el archivo de salida contiene:
- La expresión original
- El resultado evaluado
- El código ensamblador generado

## Ejemplo

Entrada (`i-o/input.txt`):
```
2 + 3 * 4
```

Salida (`i-o/output.txt`):
```
; 2 + 3 * 4
Resultado = 14

; 2 + 3 * 4
    push 2
    push 3
    push 4
    pop rbx
    pop rax
    imul rax, rbx
    push rax
    pop rbx
    pop rax
    add rax, rbx
    push rax
; fin de la expresión
```
