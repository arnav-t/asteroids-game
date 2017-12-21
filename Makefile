# Makefile for SDL2 projects
# define target
TARGET = main

# compiler 
CC = g++

# flags
CFLAGS = -Wall

# includes
INCLUDES = # -I/usr/include/SDL2

# libraries 
LIBS = -lSDL2

$(TARGET): $(TARGET).cpp
	$(CC) $(CFLAGS) $(INCLUDES) -o ./$(TARGET) ./$(TARGET).cpp $(LIBS)
