CC=gcc
CFLAGS=-I.
DEPS=parser.h
OBJ=parser.o MiPrompt.o
# mycd mycp myecho mykill myls mypause mypwd proceso # Otos archivos a compilar
%.o: %.c $(DEPS)
	$(CC) -Wall -c -o $@ $< $(CFLAGS)

# Makefile example
cli: $(OBJ)
	$(CC) -o $@ $^ $(CFLAGS)
clean:
	rm -f cli $(OBJ) *~ 
