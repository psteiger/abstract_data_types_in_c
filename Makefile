CC = gcc-6
CFLAGS = -Wall -Wextra -Werror -Wpedantic 
LDFLAGS = 
OBJFILES = Fila.o PilhaCaixa.o main.o
TARGET = simulacao

all: $(TARGET)

$(TARGET): $(OBJFILES)
	$(CC) $(CFLAGS) -o $(TARGET) $(OBJFILES) $(LDFLAGS) -g
clean:
	rm -f $(OBJFILES) $(TARGET) *~
