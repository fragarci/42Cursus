OBJ_PATH = obj/
CFILES = src/ft_printf.c src/ft_putstrn.c
OFILES = $(CFILES:.c=.o)
NAME = libftprintf.a

CC = gcc
CFALGS = -Wall -Wextra -Werror
ARCHIVER = ar rcs
REMOVE = rm -f

all: $(NAME)

$(NAME): $(OFILES)
	$(ARCHIVER) $(NAME) $(OFILES)

$(OFILES): $(CFILES)
	mkdir obj
	$(CC) $(CFLAGS) -c -o $(OBJ_PATH) $(OFILES)