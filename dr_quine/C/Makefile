CC = gcc
CFLAGS = -Wall -Wextra -Werror

CNAMES = Colleen Grace Sully
C_OBJ_DIR = obj
CFILES = Colleen.c Grace.c Sully.c
C_OBJ_FILES = $(patsubst %.c,$(C_OBJ_DIR)/%.o,$(CFILES))

all: $(CNAMES)

$(CNAMES): $(C_OBJ_FILES)
	$(CC) $(CFLAGS) $(C_OBJ_DIR)/Colleen.o -o Colleen
	$(CC) $(CFLAGS) $(C_OBJ_DIR)/Grace.o -o Grace
	$(CC) $(CFLAGS) $(C_OBJ_DIR)/Sully.o -o Sully

$(C_OBJ_DIR)/%.o: %.c
	@mkdir -p $(dir $@)
	$(CC) $(CFLAGS) -c -o $@ $<

clean:
	@rm -rf $(C_OBJ_DIR)
	@rm -f Grace_kid.c
	@rm -f Sully_*
	@clear

fclean: clean
	@rm -f $(CNAMES)
	@clear

re: fclean all

.PHONY: all clean fclean re