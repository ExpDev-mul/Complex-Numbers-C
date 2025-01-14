# Compiler and flags
CC = gcc
CFLAGS = -ansi -pedantic -Wall

# Source files and targets
SRCS = complex.c mycomp.c
OBJS = $(SRCS:.c=.o)
EXEC = mycomp

# Default target
all: $(EXEC)

# Build the main executable
$(EXEC): $(OBJS)
	$(CC) $(CFLAGS) -o $@ $(OBJS) -lm

# Compile object files
%.o: %.c complex.h
	$(CC) $(CFLAGS) -c $< -o $@

# Clean up generated files
clean:
	rm -f $(OBJS) $(EXEC)

# Run the program
run: all
	./$(EXEC)
