COREWAR_DIR = ./corewar_src/
ASM_DIR = ./asm_src/
LIBFT_DIR = ./libft/

COREWAR = corewar
ASM = asm

all: $(ASM) $(COREWAR)

$(ASM):
	@echo "Building asm"
	@make -C $(ASM_DIR)

$(COREWAR):
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

re: fclean all
