# Compiler
CC = gcc

# Compiler flags
CFLAGS = -Wall -g

# Source files
SRCS = main.c window.c grid.c

# Executable name
EXE = snake

# Default target
.PHONY: all clean run

all: $(EXE)

$(EXE): $(SRCS)
	$(CC) $(CFLAGS) -o $(EXE) $(SRCS) `sdl2-config --cflags --libs`

run: all
	./$(EXE)

clean:
	rm -f $(EXE)

