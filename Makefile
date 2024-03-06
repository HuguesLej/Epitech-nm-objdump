##
## EPITECH PROJECT, 2024
## B-PSU-400-REN-4-1-nmobjdump-hugues.lejeune
## File description:
## Makefile
##

NM_DIR	=	nm

OBJDUMP_DIR	=	objdump

NM_SRC	=	\
		$(NM_DIR)/src/main.c			\
		$(NM_DIR)/src/process_file.c	\
		$(NM_DIR)/src/print_symbols.c	\
		\
		$(NM_DIR)/src/utils/print_error.c		\
		$(NM_DIR)/src/utils/char_uppercase.c 	\
		\
		$(NM_DIR)/src/handle_file/open_file.c			\
		$(NM_DIR)/src/handle_file/close_file.c			\
		$(NM_DIR)/src/handle_file/get_file_content.c	\
		\
		$(NM_DIR)/src/symbols/get_symbols.c		\
		$(NM_DIR)/src/symbols/get_type.c		\
		\
		$(NM_DIR)/src/list/add_element.c	\
		$(NM_DIR)/src/list/free_list.c		\
		$(NM_DIR)/src/list/sort_list.c

OBJDUMP_SRC	=	\
		$(OBJDUMP_DIR)/src/main.c

BUILD	=	build

NM_OBJ	=	$(NM_SRC:%.c=$(BUILD)/%.o)

OBJDUMP_OBJ	=	$(OBJDUMP_SRC:%.c=$(BUILD)/%.o)

CC	=	gcc

COMMON_INCLUDE	=	-I./commons/include

NM_INC	=	-I./$(NM_DIR)/include

OBJDUMP_INC	=	-I./$(OBJDUMP_DIR)/include

CFLAGS	=	-W -Wall -Wextra -Werror -g

MAKEFLAGS	=	--no-print-directory

NM_BIN	=	my_nm

OBJDUMP_BIN	=	my_objdump

DIE	=	exit 1

%.c:
	@echo -e "\033[1;31mFile not found: $@\033[0m" && $(DIE)

$(BUILD)/$(NM_DIR)/%.o: $(NM_DIR)/%.c
	@mkdir -p $(@D)
	@$(CC) $(CFLAGS) $(NM_INC) $(COMMON_INCLUDE) -c $< -o $@ || $(DIE)

$(BUILD)/$(OBJDUMP_DIR)/%.o: $(OBJDUMP_DIR)/%.c
	@mkdir -p $(@D)
	@$(CC) $(CFLAGS) $(OBJDUMP_INC) $(COMMON_INCLUDE) -c $< -o $@ || $(DIE)

all:	$(NM_BIN) $(OBJDUMP_BIN)

nm:	$(NM_BIN)

objdump:	$(OBJDUMP_BIN)

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

.PHONY:	all clean fclean re nm objdump
