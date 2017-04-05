NAME 	=	corewar
CC		=	gcc
CFLAGS 	=	-Wall -Werror -Wextra
INC		=	-I includes/ -I ../libft/includes/
SRCS 	=	main.c \
			op.c \
			helpers.c \
			vm_setup.c \
			arg_parser.c \
			champion.c \
			errors.c \
			parse_champions.c \
			clear_memory.c \
			parse_instruction.c \
			loading.c \
			initializer.c \
			process_loop.c \
			op_funcs.c \
			op_live.c \
			op_ld.c \
			op_st.c \
			op_add.c \
			op_sub.c \
			op_and.c \
			op_or.c \
			op_xor.c \
			op_zjump.c \
			op_ldi.c \
			op_sti.c \
			op_fork.c \
			op_lld.c \
			op_lldi.c \
			op_lfork.c \
			op_aff.c \
			killer.c \
			gui.c \
			gui_extra.c

OBJ		=	$(SRCS:.c=.o)
HDRS	=	corewar.h\
			op.h
SDIR	=	$(addprefix srcs/, $(SRCS))
ODIR	=	$(addprefix objs/, $(OBJ))
HDIR	=	$(addprefix includes/, $(HDRS))
LIBPATH =	../libft
RED = \033[31;1m
GRN = \033[32;1m
YEL = \033[33;1m
BLU = \033[34;1m
MAG = \033[35;1m
CYN = \033[36;1m
WHT = \033[37;1m
EOC = \033[0m
BEER = \xF0\x9F\x8D\xBA

asan: CFLAGS += -fsanitize=address

all: $(NAME)

$(NAME): $(ODIR)
	@make -C $(LIBPATH)
	@$(CC) $(CFLAGS) $(ODIR) -L$(LIBPATH) -lft -lncurses -o $(NAME) $(INC)
	@echo "$(GRN)$(BEER) $(NAME) created successfully!$(EOC)"

objs/%.o: srcs/%.c $(HDIR)
	@mkdir -p objs
	@$(CC) $(CFLAGS) -c $< -o $@ $(INC)
	@echo "$(GRN)$< =>$(EOC) $(YEL)$@$(EOC) $(GRN)✓$(EOC)"

clean:
	@/bin/rm -rf objs

fclean: clean
	@/bin/rm -f $(NAME)
	@echo "$(RED)$(NAME) removed!$(EOC)"

reli:
	@make -C $(LIBPATH) re

re: fclean all

asan: all


.PHONY: re all clean fclean
