NAME = fractol

CC = gcc
CFLAGS = -Wall -Wextra -Werror
#MLXFLAGS = -ldl -lglfw -pthread -lm -framework Cocoa -framework OpenGL -framework IOKit -L"/Users/fragarci/.brew/opt/glfw/lib/"
MLXFLAGS = -Iinclude -ldl -lglfw -pthread -lm

SRC = src
OBJ = obj
SRCS = $(wildcard $(SRC)/*.c)
OBJS = $(patsubst $(SRC)/%.c, $(OBJ)/%.o, $(SRCS))

BINDIR = bin
BIN = $(BINDIR)/$(NAME)

LIBFT = Libft/libft.a

MLX = MLX42/build/libmlx42.a

all: $(BIN)

$(BIN): $(OBJS) $(LIBFT) $(MLX) bin
	$(CC) $(CFLAGS) $(OBJS) $(LIBFT) $(MLX) $(MLXFLAGS) -o $@

$(OBJ)/%.o: $(SRC)/%.c obj
	$(CC) $(CFLAGS) -c $< -o $@

$(LIBFT):
	make -C Libft

$(MLX):
	make -C MLX42/build

clean:
	rm $(BINDIR)/* $(OBJ)/*

fclean:
	rm -rf $(BINDIR) $(OBJ)
	make fclean -C Libft
	make clean -C MLX42/build

re: fclean all

bin:
	mkdir bin

obj:
	mkdir obj