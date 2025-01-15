CC = gcc
CFLAGS = -ansi -pedantic -Wall # Define compilation flags

SRCS = complex.c mycomp.c utils.c
OBJS = $(SRCS:.c=.o)
EXEC = mycomp

all: $(EXEC)

$(EXEC): $(OBJS)
	$(CC) $(CFLAGS) -o $@ $(OBJS) -lm # Add -lm to support <math.h>

# Create output files
%.o: %.c complex.h
	$(CC) $(CFLAGS) -c $< -o $@

# Clean executables post run
clean:
	rm -f $(OBJS) $(EXEC)
	
run: all
	./$(EXEC)
