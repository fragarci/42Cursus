# Files Setup
NAME = libft.a
SHARED = libft.so
OBJ_DIR = obj

CFILES = ft_atoi.c ft_isalnum.c ft_isdigit.c ft_itoa.c ft_lstclear.c ft_lstlast.c ft_lstsize.c ft_memcpy.c ft_putchar_fd.c ft_putstr_fd.c ft_strdup.c ft_strlcat.c ft_strmapi.c ft_strrchr.c ft_tolower.c ft_bzero.c ft_isalpha.c ft_isprint.c ft_lstadd_back.c ft_lstdelone.c ft_lstmap.c ft_memchr.c ft_memmove.c ft_putendl_fd.c ft_split.c ft_striteri.c ft_strlcpy.c ft_strncmp.c ft_strtrim.c ft_toupper.c ft_calloc.c ft_isascii.c ft_isspace.c ft_lstadd_front.c ft_lstiter.c ft_lstnew.c ft_memcmp.c ft_memset.c ft_putnbr_fd.c ft_strchr.c ft_strjoin.c ft_strlen.c ft_strnstr.c ft_substr.c

OBJ_FILES = $(patsubst %.c,$(OBJ_DIR)/%.o,$(CFILES))

# Compiler Commands
CC = gcc
CFLAGS = -Wall -Wextra -Werror -O1 -funroll-loops

ARCHIVER = ar rcs

all: $(NAME)
bonus: $(NAME)
so: $(SHARED)
obj: $(OBJ_FILES)

$(NAME): $(OBJ_FILES)
	$(ARCHIVER) $(NAME) $(OBJ_FILES)

$(SHARED): $(OBJ_FILES)
	$(CC) $(CFLAGS) -shared -o $(SHARED) $(OBJ_FILES)

$(OBJ_DIR)/%.o: %.c libft.h
	@mkdir -p $(dir $@)
	$(CC) $(CFLAGS) -c -o $@ $<

clean:
	@rm -rf $(OBJ_DIR)

fclean: clean
	@rm -f $(NAME)
	@rm -f $(SHARED)

re: fclean all

.PHONY : all bonus so obj clean fclean re
