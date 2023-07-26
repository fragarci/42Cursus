NAME = ex02

CC = c++
CFLAGS = -Wall -Wextra -Werror -std=c++98

MAIN = main.cpp

all:$(NAME)

$(NAME): $(MAIN)
	$(CC) $(CFLAGS) $(MAIN) -o $@

clean:
	rm $(NAME)

fclean: clean

re: fclean all

.PHONY = all clean fclean re
