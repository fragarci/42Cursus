CFILES = get_next_line_utils.c\
get_next_line.c

OFILES = $(CFILES:.c=.o)

NAME = get_next_line.a

CC = gcc
CFLAGS = -Wall -Wextra -Werror
ARCHIVER = ar rcs
REMOVE = rm -f

all: $(NAME)

$(NAME): $(OFILES)
	$(ARCHIVER) $(NAME) $(OFILES)

$(OFILES): $(CFILES)
	$(CC) $(CFLAGS) -c $(CFILES)

clean:
	$(REMOVE) $(OFILES)

fclean:
	$(REMOVE) $(OFILES) $(NAME)

re: fclean all

.PHONY : all clean fclean re