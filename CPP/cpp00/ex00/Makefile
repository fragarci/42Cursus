NAME=megaphone

CFILES=megaphone.cpp

CC=c++
CFLAGS=-Wall -Wextra -Werror -std=c++98

all: $(NAME)

$(NAME): $(CFILES)
	$(CC) $(CFLAGS) $^ -o $@

clean:
	rm $(NAME)

fclean: clean

re: fclean all

.PHONY=all clean fclean re
