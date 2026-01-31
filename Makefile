.PHONY: all

CC = gcc
CFLAGS = -Wall -Wextra
INCLUDE = -I /opt/homebrew/Cellar/sdl2/2.32.10/include -I ./include
SRC = iv.c ppm_to_rgb.c
OBJ = iv.o ppm_to_rgb.o
BUILDDIR = $(CURDIR)/build
SRCDIR = $(CURDIR)/src
LINK = -L/opt/homebrew/Cellar/sdl2/2.32.10/lib -lSDL2-2.0.0
EXE = iv

all: main

run: main
	./$(EXE)

main: $(OBJ)
	$(CC) $(CFLAGS) $(INCLUDE) $(LINK) $(foreach var, $(OBJ), $(BUILDDIR)/$(var)) -o $(EXE)

iv.o: $(SRCDIR)/$(word 1, $(SRC))
	$(CC) -c $(SRCDIR)/$(word 1, $(SRC)) $(INCLUDE) -o $(BUILDDIR)/$(word 1, ${OBJ})

ppm_to_rgb.o: $(SRCDIR)/$(word 2, $(SRC))
	$(CC) -c $(SRCDIR)/$(word 2, $(SRC)) $(INCLUDE) -o $(BUILDDIR)/$(word 2, ${OBJ})

clean:
	rm -rf $(BUILDDIR)
	mkdir $(BUILDDIR)