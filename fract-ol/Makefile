CFILES = src/fractol.c\
src/ft_complex.c\
src/ft_colors.c\
src/ft_mandelbrot.c\
src/ft_mandelbrot_hooks.c\
src/ft_julia.c\
src/ft_julia_hooks.c\
src/ft_initialize.c

CC = gcc
CFLAGS = -Wall -Wextra -Werror

MLX = MLX42/libmlx42.a
LIBFT = Libft/libft.a
BREW = /Users/fragarci/.brew/opt/glfw/lib


NAME = fractol

all: $(NAME)

$(NAME): $(MLX) $(LIBFT)
	$(CC) $(CFLAGS) $(CFILES) $(MLX) $(LIBFT) -lglfw -L $(BREW) -o $(NAME)

$(MLX):
	make -C MLX42

$(LIBFT):
	make -C Libft

clean: 
	rm $(NAME)

fclean: clean

re: fclean re

.PHONY: all clean fclean re