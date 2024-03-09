CC=gcc
CFLAGS=
DEPS = main.c
OBJ = build/optimizer.o build/main.o 

%.o: %.c $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS)
all: src/optimizer.c main.c 
	gcc -c main.c -o build/main.o
	gcc -c src/optimizer.c -o build/optimizer.o
	gcc -o build/main.exe build/optimizer.o build/main.o
	.\build\main.exe flux/main.fx
hellomake: $(OBJ) $(DEPS)
	$(CC) -o $@ $^ $(CFLAGS)
clean:
	del /Q /F .\build\main.exe .\build\*.o
