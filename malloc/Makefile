ifeq ($(HOSTTYPE),)
	HOSTTYPE := $(shell uname -m)_$(shell uname -s)
endif

# Files Setup
NAME = libft_malloc_$(HOSTTYPE).so
SYMLINK_NAME = libft_malloc.so

SRC_DIR = .
OBJ_DIR = obj

CFILES = $(shell find $(SRC_DIR) -type f -name '*.c')
OBJ_FILES = $(patsubst $(SRC_DIR)/%.c,$(OBJ_DIR)/%.o,$(CFILES))

# Compiler Commands
CC = gcc
CFLAGS = -Wall -Wextra -Werror #-g -fsanitize=address

SYMLINK = ln -sf

all: $(NAME)

$(NAME): $(OBJ_FILES)
	@$(CC) $(CFLAGS) -shared $(OBJ_FILES) -o $(NAME)
	@$(SYMLINK) $(NAME) $(SYMLINK_NAME)
	@clear

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	@mkdir -p $(dir $@)
	@$(CC) $(CFLAGS) -c -fPIC -o $@ $<

clean:
	@rm -rf $(OBJ_DIR)
	@clear

fclean: clean
	@rm -f $(NAME)
	@rm -f $(SYMLINK_NAME)
	@clear

re: fclean all

.PHONY : all clean fclean re
