# ASM
NASM = nasm
SFLAGS = -f elf64
CFLAGS = -Wall -Wextra -Werror -nostartfiles
INCLUDES = -lc

SNAMES = Colleen Grace Sully
S_OBJ_DIR = obj
SFILES = Colleen.s Grace.s Sully.s
S_OBJ_FILES = $(patsubst %.s,$(S_OBJ_DIR)/%.o,$(SFILES))

all: $(SNAMES)

$(SNAMES): $(S_OBJ_FILES)
	$(CC) $(CFLAGS) $(S_OBJ_DIR)/Colleen.o -o Colleen
	$(CC) $(CFLAGS) $(S_OBJ_DIR)/Grace.o -o Grace
	$(CC) $(CFLAGS) $(S_OBJ_DIR)/Sully.o -o Sully

$(S_OBJ_DIR)/%.o: %.s
	@mkdir -p $(dir $@)
	$(NASM) $(SFLAGS) $< -o $@

clean:
	@rm -rf $(S_OBJ_DIR)
	@rm -f Grace_kid.s
	@rm -f Sully_*
	@clear

fclean: clean
	@rm -f $(SNAMES)
	@clear

re: fclean all

.PHONY: all clean fclean re