CFILES = src/push_swap.c\
src/args.c\
src/instructions1.c\
src/instructions2.c\
src/stack.c

LIBFT = Libft/libft.a

NAME = push_swap

all: $(NAME)

$(NAME): $(LIBFT) $(CFILES)
	gcc -Wall -Wextra -Werror $(CFILES) $(LIBFT) -o $(NAME)

$(LIBFT):
	make -C Libft/

clean:
	rm -rf $(NAME)

fclean: clean

re: fclean all

.PHONY: all clean fclean re