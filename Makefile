# Compiler
CC = gcc

# Compiler flags
CFLAGS = -Wall -g -Wno-implicit-function-declaration
CFLAGS_1 = -Wall -g

# Find all .c files in the current directory (for compiling)
SRCS := $(wildcard *.c)

# The executable's name (used if you don't specify a target)
EXE = main

# Default target
.PHONY: all clean run

# Rule to compile the main executable (all .c files)
all: $(EXE)

# Rule to compile any individual .c file into its own executable
%: %.c
	@$(CC) $(CFLAGS_1) -o $@ $< -lm  # Compile and link each .c file into a corresponding executable

# Rule to compile the main executable from all .c files
$(EXE): $(SRCS)
	@$(CC) $(CFLAGS) -o $(EXE) $(SRCS) -lm  # Compile and link all .c files into main

# Run the program (if there is only one executable)
run: all
	@./$(EXE)

# Clean target
clean:
	@rm -f $(EXE) $(SRCS:.c=)




