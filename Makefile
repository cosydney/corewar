COREWAR_DIR = ./corewar_src/
ASM_DIR = ./asm_src/
LIBFT_DIR = ./libft/

COREWAR = corewar
ASM = asm

all: asm_only corewar_only
	@if ! [ -s $(ASM) ] ; \
		then ln -s $(addprefix $(ASM_DIR), $(ASM)); fi
	@if ! [ -s $(COREWAR) ] ; \
		then ln -s $(addprefix $(COREWAR_DIR), $(COREWAR)); fi

asm_only:
	@echo "Building asm"
	@make -C $(ASM_DIR)

corewar_only:
	@echo "Building corewar"
	@make -C $(COREWAR_DIR)

clean:
	@make -C $(LIBFT_DIR) clean
	@make -C $(ASM_DIR) clean
	@make -C $(COREWAR_DIR) clean

fclean:
	@make -C $(LIBFT_DIR) fclean
	@make -C $(ASM_DIR) fclean
	@make -C $(COREWAR_DIR) fclean
	@rm -f $(ASM)
	@rm -f $(COREWAR)

re: fclean all
