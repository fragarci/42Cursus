NAME = libasm.a
TEST = test_asm
AUX = read_test.txt

SRC_DIR = .
OBJ_DIR = obj

SFILES = $(shell find $(SRC_DIR) -type f -name '*.s')
OFILES = $(patsubst $(SRC_DIR)/%.s,$(OBJ_DIR)/%.o,$(SFILES))

all: $(NAME) $(TEST) $(AUX)

$(NAME): $(OFILES)
	@ar rcs $(NAME) $(OFILES)
	@clear

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.s
	@mkdir -p $(dir $@)
	@nasm -f elf64 -g $< -o $@

$(TEST): main.c
	@gcc -Wall -Wextra -Werror main.c -lc $(NAME) -o $(TEST)

$(AUX):
	@echo "0123456789ABCDEF" > read_test.txt

clean:
	@rm -rf $(OBJ_DIR)

fclean: clean
	@rm -f $(NAME)
	@rm -f $(TEST)
	@rm -f $(AUX)

re: fclean all