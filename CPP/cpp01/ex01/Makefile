NAME = ex01

CC = c++
CFLAGS = -Wall -Wextra -Werror -std=c++98

SRC = src
OBJ = obj
SRCS = $(wildcard $(SRC)/*.cpp)
OBJS = $(patsubst $(SRC)/%.cpp, $(OBJ)/%.o, $(SRCS))

BINDIR = bin
BIN = $(BINDIR)/$(NAME)

all: $(BIN)

$(BIN): $(OBJS) bin
	$(CC) $(CFLAGS) $(OBJS) -o $@

$(OBJ)/%.o: $(SRC)/%.cpp obj
	$(CC) $(CFLAGS) -c $< -o $@

obj:
	mkdir obj

bin:
	mkdir bin

clean:
	rm $(BINDIR)/* $(OBJ)/*

fclean:
	rm  -rf $(BINDIR) $(OBJ)

re: fclean all

.PHONY: all clean fclean re debug
