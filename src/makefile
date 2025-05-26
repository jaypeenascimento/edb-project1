# Nome do executável
TARGET = main

# Compilador
CC = gcc

# Opções de compilação
CFLAGS = -Wall -std=c11

# Arquivos de objeto
OBJS = main.o utils.o queue.o list.o screen.o

# Regra padrão para compilar o projeto
all: $(TARGET)

# Regra para gerar o executável
$(TARGET): $(OBJS)
	$(CC) $(OBJS) -o $(TARGET) -lm

# Regra para compilar o main.c
main.o: main.c utils.h structures/queue.h structures/list.h screen/screen.h
	$(CC) $(CFLAGS) -c main.c

# Regra para compilar o utils.c
utils.o: utils.c utils.h
	$(CC) $(CFLAGS) -c utils.c

# Regra para compilar queue.c
queue.o: structures/queue.c structures/queue.h
	$(CC) $(CFLAGS) -c structures/queue.c -o queue.o

# Regra para compilar list.c
list.o: structures/list.c structures/list.h
	$(CC) $(CFLAGS) -c structures/list.c -o list.o

# Regra para compilar screen.c
screen.o: screen/screen.c screen/screen.h structures/list.h structures/queue.h
	$(CC) $(CFLAGS) -c screen/screen.c -o screen.o

# Regra para limpar os arquivos gerados
clean:
	rm -f $(OBJS) $(TARGET)
