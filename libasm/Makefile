NAME = libasm.a
TEST = test_asm

SRC_DIR = .
OBJ_DIR = obj

SFILES = $(shell find $(SRC_DIR) -type f -name '*.s')
OFILES = $(patsubst $(SRC_DIR)/%.s,$(OBJ_DIR)/%.o,$(SFILES))

all: $(NAME) $(TEST)

$(NAME): $(OFILES)
	ar rcs $(NAME) $(OFILES)

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.s
	@mkdir -p $(dir $@)
	nasm -f elf64 $< -o $@

$(TEST): main.c
	gcc -Wall -Wextra -Werror main.c -lc $(NAME) -o $(TEST)

clean:
	rm -rf $(OBJ_DIR)

fclean: clean
	rm $(NAME)
	rm $(TEST)

re: fclean all