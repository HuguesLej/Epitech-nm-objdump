##
## EPITECH PROJECT, 2024
## B-PSU-400-REN-4-1-nmobjdump-hugues.lejeune
## File description:
## Makefile
##

NM_DIR	=	my_nm

OBJDUMP_DIR	=	my_objdump

NM_SRC	=	\
		$(NM_DIR)/main.c

OBJDUMP_SRC	=	\
		$(OBJDUMP_DIR)/main.c

BUILD	=	build

NM_OBJ	=	$(NM_SRC:%.c=$(BUILD)/%.o)

OBJDUMP_OBJ	=	$(OBJDUMP_SRC:%.c=$(BUILD)/%.o)

CC	=	gcc

CFLAGS	=	-I./include -W -Wall -Wextra -Werror -g

MAKEFLAGS	=	--no-print-directory

NM_BIN	=	nm

OBJDUMP_BIN	=	objdump

DIE	=	exit 1

%.c:
	@echo -e "\033[1;31mFile not found: $@\033[0m" && $(DIE)

$(BUILD)/%.o: %.c
	@mkdir -p $(@D)
	@$(CC) $(CFLAGS) -c $< -o $@ || $(DIE)

all:	$(NM_BIN) $(OBJDUMP_BIN)

$(NM_BIN):	$(NM_OBJ)
	@gcc -o $(NM_BIN) $(NM_OBJ) $(CFLAGS)
	@echo -e "\033[1;36m[$(NM_BIN)]: Successfully build\033[0m"
	@echo -e "\033[1;36mCompiled $(shell echo "$?" | wc -w) file(s)\033[0m"

$(OBJDUMP_BIN):	$(OBJDUMP_OBJ)
	@gcc -o $(OBJDUMP_BIN) $(OBJDUMP_OBJ) $(CFLAGS)
	@echo -e "\033[1;36m[$(OBJDUMP_BIN)]: Successfully build\033[0m"
	@echo -e "\033[1;36mCompiled $(shell echo "$?" | wc -w) file(s)\033[0m"

clean:
	@rm -f $(NM_OBJ)
	@rm -f $(OBJDUMP_OBJ)
	@echo -e "\033[1;33mObject files successfully cleaned\033[0m"

fclean:	clean
	@rm -f $(NM_BIN)
	@rm -f $(OBJDUMP_BIN)
	@echo -e "\033[1;33mBinary file successfully cleaned\033[0m"

re:	fclean all

.PHONY:	all clean fclean re
