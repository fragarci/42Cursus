NAME = philo

CC = gcc
CFLAGS = -Wall -Wextra -Werror -g

SRC = src
OBJ = obj
SRCS = $(wildcard $(SRC)/*.c)
OBJS = $(patsubst $(SRC)/%.c, $(OBJ)/%.o, $(SRCS))

BINDIR = bin
BIN = $(BINDIR)/$(NAME)

GRE = \033[;32m
B_GRE = \033[1;32m
B_RED = \033[1;31m
DEF = \033[;0m

all: $(BIN)

$(BIN): $(OBJS) | $(BINDIR)
	@echo "$(GRE)Linking object files and creating binary($(BIN))...$(DEF)"
	@$(CC) $(CFLAGS) $(OBJS) -o $@ -lpthread
	@echo "$(B_GRE)Done!$(DEF)"

$(OBJ)/%.o: $(SRC)/%.c | $(OBJ)
	@echo "$(GRE)Compiling $<\t>> $@$(DEF)"
	@$(CC) $(CFLAGS) -c $< -o $@

$(BINDIR):
	@mkdir bin

$(OBJ):
	@mkdir obj


clean:
	@echo "$(B_RED)Cleaning...$(DEF)"
	@rm -rf $(BIN) $(OBJS)

fclean:
	@echo "$(B_RED)Cleaning...$(DEF)"
	@rm -rf $(BINDIR) $(OBJ)

re: fclean all

.PHONY: all clean fclean re
