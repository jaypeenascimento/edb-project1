# Nome do executável
TARGET = main

# Compilador
CC = gcc

# Opções de compilação
CFLAGS = -Wall -std=c11

# Arquivos de objeto
OBJS = main.o utils.o

# Regra padrão para compilar o projeto
all: $(TARGET)

# Regra para gerar o executável
$(TARGET): $(OBJS)
	$(CC) $(OBJS) -o $(TARGET) -lm

# Regra para compilar o main.c
main.o: main.c utils.h
	$(CC) $(CFLAGS) -c main.c

# Regra para compilar o utils.c
utils.o: utils.c utils.h
	$(CC) $(CFLAGS) -c utils.c

# Regra para limpar os arquivos gerados
clean:
	rm -f $(OBJS) $(TARGET)

