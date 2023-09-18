NAME = ex02

CC = c++
CFLAGS = -Wall -Wextra -Werror -std=c++98

SRC = src
OBJ = obj
SRCS = $(wildcard $(SRC)/*.cpp)
OBJS = $(patsubst $(SRC)/%.cpp, $(OBJ)/%.o, $(SRCS))

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $@

$(OBJ)/%.o: $(SRC)/%.cpp | obj
	$(CC) $(CFLAGS) -c $< -o $@

obj:
	mkdir obj

clean:
	rm -rf $(OBJ)

fclean:
	rm  -rf $(NAME) $(OBJ)

re: fclean all

.PHONY: all clean fclean re debug
