LIBFT = Libft/libft.a

#COLORS

RED = \e[38;5;9m
GREEN = \e[38;5;10m
DEFAULT = \e[39m

all: $(LIBFT) client server

$(LIBFT):
	@make -C Libft/

client:
	@gcc -Wall -Wextra -Werror src/client.c Libft/libft.a -o client
	@echo "$(GREEN)✅ - CLIENT compiled$(DEFAULT)"

server:
	@gcc -Wall -Wextra -Werror src/server.c Libft/libft.a -o server
	@echo "$(GREEN)✅ - SERVER compiled$(DEFAULT)"

clean:
	@rm -rf client server
	@rm -rf client_bonus server_bonus
	@echo "$(GREEN)✅ - CLIENT and SERVER deleted successfully$(DEFAULT)"

bonus: $(LIBFT)
	@gcc -Wall -Wextra -Werror src/client_bonus.c Libft/libft.a -o client_bonus
	@echo "$(GREEN)✅ - CLIENT compiled$(DEFAULT)"
	@gcc -Wall -Wextra -Werror src/server_bonus.c Libft/libft.a -o server_bonus
	@echo "$(GREEN)✅ - SERVER compiled$(DEFAULT)"

fclean: clean
	@make fclean -C Libft/

re: fclean all

PHONY: all clean fclean re