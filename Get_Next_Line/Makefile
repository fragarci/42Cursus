CFILES = get_next_line_utils.c\
get_next_line.c

CBONUS = get_next_line_utils_bonus.c\
get_next_line_bonus.c

OFILES = $(CFILES:.c=.o)
OBONUS = $(CBONUS:.c=.o)

NAME = get_next_line.a

CC = gcc
CFLAGS = -Wall -Wextra -Werror
ARCHIVER = ar rcs
REMOVE = rm -f

all: $(NAME)

$(NAME): $(OFILES)
	$(ARCHIVER) $(NAME) $(OFILES)

bonus: $(OBONUS)
	$(ARCHIVER) $(NAME) $(OBONUS)

$(OFILES): $(CFILES)
	$(CC) $(CFLAGS) -c $(CFILES)

$(OBONUS): $(CBONUS)
	$(CC) $(CFLAGS) -c $(CBONUS)

clean:
	$(REMOVE) $(OFILES)

fclean:
	$(REMOVE) $(OFILES) $(NAME)

re: fclean all

.PHONY : all bonus clean fclean re