
CFILES = src/fdf.c\
include/ft_draw_line.c

CC = gcc
CFLAGS = -Wall -Wextra -Werror

MLX = MLX42/libmlx42.a
BREW = /Users/fragarci/.brew/opt/glfw/lib


NAME = fdf

all: $(NAME)

$(NAME): $(MLX)
	$(CC) $(CFLAGS) $(CFILES) $(MLX) -lglfw -L $(BREW) -o $(NAME)

$(MLX):
	make -C MLX42

# gcc -Wall -Wextra -Werror src/fdf.c MLX42/libmlx42.a -lglfw -L /Users/fragarci/.brew/opt/glfw/lib -o fdf
