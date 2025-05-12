# C
CC = gcc
CFLAGS = -Wall -Wextra -Werror

CNAMES = C/Colleen C/Grace C/Sully
C_SRC_DIR = C
C_OBJ_DIR = C/obj
CFILES = C/Colleen.c C/Grace.c C/Sully.c
C_OBJ_FILES = $(patsubst $(C_SRC_DIR)/%.c,$(C_OBJ_DIR)/%.o,$(CFILES))

# ASM
NASM = nasm
SFLAGS = -f elf64
CFLAGS2 = $(CFLAGS) -nostartfiles
INCLUDES = -lc

SNAMES = ASM/Colleen ASM/Grace
S_SRC_DIR = ASM
S_OBJ_DIR = ASM/obj
SFILES = ASM/Colleen.s ASM/Grace.s
S_OBJ_FILES = $(patsubst $(S_SRC_DIR)/%.s,$(S_OBJ_DIR)/%.o,$(SFILES))


# COMPILATION

all: $(CNAMES) $(SNAMES)

$(CNAMES): $(C_OBJ_FILES)
	@$(CC) $(CFLAGS) $(C_OBJ_DIR)/Colleen.o -o $(C_SRC_DIR)/Colleen
	@$(CC) $(CFLAGS) $(C_OBJ_DIR)/Grace.o -o $(C_SRC_DIR)/Grace
	@$(CC) $(CFLAGS) $(C_OBJ_DIR)/Sully.o -o $(C_SRC_DIR)/Sully
	@clear

$(C_OBJ_DIR)/%.o: $(C_SRC_DIR)/%.c
	@mkdir -p $(dir $@)
	@$(CC) $(CFLAGS) -c -o $@ $<
	@clear

$(SNAMES): $(S_OBJ_FILES)
	@$(CC) $(CFLAGS2) $(S_OBJ_DIR)/Colleen.o -o $(S_SRC_DIR)/Colleen
	@$(CC) $(CFLAGS2) $(S_OBJ_DIR)/Grace.o -o $(S_SRC_DIR)/Grace

$(S_OBJ_DIR)/%.o: $(S_SRC_DIR)/%.s
	@mkdir -p $(dir $@)
	@$(NASM) $(SFLAGS) $< -o $@
	@clear


clean:
	@rm -rf $(C_OBJ_DIR)
	@rm -rf $(S_OBJ_DIR)
	@clear

fclean: clean
	@rm -f $(CNAMES)
	@rm -f $(SNAMES)
	@clear

re: fclean all