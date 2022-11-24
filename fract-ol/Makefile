
CFILES = src/fractol.c\
src/ft_complex.c\
src/ft_colors.c\
src/ft_mandelbrot.c

CC = gcc
CFLAGS = -Wall -Wextra -Werror

MLX = MLX42/libmlx42.a

NAME = fractol

all: $(NAME)

$(NAME): $(MLX)
	$(CC) $(CFLAGS) $(CFILES) $(MLX) -ldl -lglfw -pthread -lm -o $(NAME)

$(MLX):
	make -C MLX42

clean:
	rm -rf $(NAME)

fclean: clean

re: fclean all

.PHONY: all clean fclean re

# gcc -Wall -Wextra -Werror src/fdf.c MLX42/libmlx42.a -lglfw -L /Users/fragarci/.brew/opt/glfw/lib -o fdf
