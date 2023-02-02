CFILES = src/main.c\
src/fractals.c\
src/ft_mandelbrot.c\
src/complex.c\
src/colors.c\
src/mouse.c\
src/hooks.c\
src/ft_julia.c\
src/error.c\
src/numbers.c

MLX = MLX42/libmlx42.a
LIBFT = Libft/libft.a

NAME = fractol

# COLORS

RED = \e[38;5;9m
GREEN = \e[38;5;10m
DEFAULT=\033[0m

# COMPILATION

all: $(NAME)

$(NAME): $(MLX) $(LIBFT)
	@gcc -Wall -Wextra -Werror $(CFILES) $(MLX) $(LIBFT) -ldl -lglfw -pthread -lm -o $(NAME)
	@echo "$(GREEN)✅ - FRACTOL compiled $(DEFAULT)"

$(MLX):
	@make -C MLX42

$(LIBFT):
	@make -C Libft

clean:
	@rm -rf $(NAME)

fclean: clean
	@make fclean -C Libft
	@make fclean -C MLX42

re: fclean all

.PHONY: all clean fclean re