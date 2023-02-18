NAME = push_swap

CC = gcc
CFLAGS = -Wall -Wextra -Werror

SRC = src
OBJ = obj
SRCS = $(wildcard $(SRC)/*.c)
OBJS = $(patsubst $(SRC)/%.c, $(OBJ)/%.o, $(SRCS))

BINDIR = bin
BIN = $(BINDIR)/$(NAME)

LIBFT = Libft/libft.a

all: $(BIN)

$(BIN): $(OBJS) $(LIBFT)
	$(CC) $(CFLAGS) $(OBJS) $(LIBFT) -o $@

$(OBJ)/%.o: $(SRC)/%.c
	$(CC) $(CFLAGS) -c $< -o $@

$(LIBFT):
	make -C Libft

debug:
	make -C debug

clean:
	rm $(BINDIR)/* $(OBJ)/*

fclean:
	rm $(BINDIR)/* $(OBJ)/*
	make fclean -C Libft

re: fclean all

.PHONY: all clean fclean re debug