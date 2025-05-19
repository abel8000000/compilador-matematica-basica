CC = gcc
CFLAGS = -Wall -Wextra -std=c99 -Iinclude

SRCDIR = src
OBJ = $(SRCDIR)/ast.o $(SRCDIR)/codegen.o $(SRCDIR)/evaluator.o $(SRCDIR)/lexer.o $(SRCDIR)/main.o $(SRCDIR)/parser.o
TARGET = compilador

all: $(TARGET)

$(TARGET): $(OBJ)
	$(CC) $(OBJ) -o $(TARGET)

$(SRCDIR)/%.o: $(SRCDIR)/%.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(SRCDIR)/*.o $(TARGET)