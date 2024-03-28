# CC specifies the compiler to be used
CC = gcc

# SRC specifies the .c files
SRC = src/main.c src/exit_window.c src/raycast.c src/generate_map.c \
      src/render_walls.c src/angles.c src/rgb.c src/rgb_ops.c \
      src/rgb_physics.c src/SDL.c src/SDL_window.c \
      src/walls.c

# OBJ specifies the .o files
OBJ = $(SRC:.c=.o)

# NAME specifies the name of our exectuable
NAME = 'Raycaster_Maze'

# SDL2 runs the sdl2-config program with the necessary flags
SDL2 := $`sdl2-config --cflags` `sdl2-config --libs`

# CFLAGS specifies your favorite compiler flags
CFLAGS = -Wall -Werror -Wextra -pedantic

# LFLAGS specifies the linker flags
# LFLAGS =

# Makefile should work even if there is a file in the folder
# that has the same name as rule
.PHONY: all clean oclean fclean re

# This rule builds our executable
# Makefile should not compile if the header file main.h is missing
all: include/main.h $(OBJ)
	$(CC) $(OBJ) $(CFLAGS) $(SDL2) -o $(NAME)

# This rule forces recompilation of all source files
re: fclean all
