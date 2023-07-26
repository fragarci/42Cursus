# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: fragarci <fragarci@student.42malaga.com    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/07/24 13:17:09 by fragarci          #+#    #+#              #
#    Updated: 2023/07/25 12:45:08 by fragarci         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = ex02

CC = c++
CFLAGS = -Wall -Wextra -Werror -std=c++98

SRCS = $(wildcard *.cpp)
OBJS = $(patsubst %.cpp, %.o, $(SRCS))
RM = rm -rf

UNAME = $(shell uname -s)
ifeq ($(UNAME), Linux)
CFLAGS = -Wall -Wextra -Werror
$(warning Linux detected! Disabling -std=c++98...)
endif

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $@

%.o: %.cpp
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean $(NAME)

.PHONY: all clean fclean re
