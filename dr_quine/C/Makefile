# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: fragarci <fragarci@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/02/05 19:10:12 by fragarci          #+#    #+#              #
#    Updated: 2023/02/05 19:10:13 by fragarci         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# SOURCES

SRC_COLLEN = Colleen/Colleen.c
SRC_GRACE = Grace/Grace.c
SRC_SULLY = Sully/Sully.c

# VARIABLES

NAME = dr_quine_c

NAME_COLLEEN = Colleen/Colleen
NAME_GRACE = Grace/Grace
NAME_SULLY = Sully/Sully

CC = gcc
CFLAGS = -Wall -Wextra -Werror

# COMPILATION

all: $(NAME)

$(NAME): $(NAME_COLLEEN) $(NAME_GRACE) $(NAME_SULLY)

$(NAME_COLLEEN): $(SRC_COLLEN)
	$(CC) $(CFLAGS) $(SRC_COLLEN) -o $(NAME_COLLEEN)

$(NAME_GRACE): $(SRC_GRACE)
	$(CC) $(CFLAGS) $(SRC_GRACE) -o $(NAME_GRACE)

$(NAME_SULLY): $(SRC_SULLY)
	$(CC) $(CFLAGS) $(SRC_SULLY) -o $(NAME_SULLY)

clean:
	@rm $(NAME_COLLEEN) $(NAME_GRACE) $(NAME_SULLY)

fclean:
	@rm $(NAME_COLLEEN) $(NAME_GRACE) $(NAME_SULLY)

re: fclean all