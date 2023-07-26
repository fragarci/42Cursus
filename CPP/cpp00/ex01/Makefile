# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: fragarci <fragarci@student.42malaga.com    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/07/24 13:32:04 by fragarci          #+#    #+#              #
#    Updated: 2023/07/24 13:33:19 by fragarci         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = PhoneBook

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

.PHONY: all clean fclean re
