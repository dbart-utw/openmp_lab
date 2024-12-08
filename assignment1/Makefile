# Compiler and flags
CC = gcc
CFLAGS = -Wall -Wextra -O2

# Target executable
TARGET = matmul

# Source files
SRCS = matmul.c

# Object files
OBJS = $(SRCS:.c=.o)

# Build the target executable
$(TARGET): $(OBJS)
	$(CC) $(CFLAGS) -o $(TARGET) $(OBJS)

# Compile the source files into object files
%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

# Clean up build files
clean:
	rm -f $(OBJS) $(TARGET)

# Phony targets
.PHONY: clean
