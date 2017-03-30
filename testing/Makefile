CC		=	clang
CFLAGS =
INC		=	-I includes/ -I libft/includes/
SRCS 	=	op.c \
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
			op_live.c \
			op_ld.c \
			op_st.c \
			op_add.c \
			op_sub.c \
			op_and.c \
			op_or.c \
			op_xor.c \
			op_lld.c \
			op_zjump.c \
			killer.c

OBJ		=	$(SRCS:.c=.o)
HDRS	=	corewar.h\
			op.h
SDIR	=	$(addprefix srcs/, $(SRCS))
ODIR	=	$(addprefix objs/, $(OBJ))
HDIR	=	$(addprefix includes/, $(HDRS))
LIBPATH =	./libft
RED = \033[31;1m
GRN = \033[32;1m
YEL = \033[33;1m
BLU = \033[34;1m
MAG = \033[35;1m
CYN = \033[36;1m
WHT = \033[37;1m
EOC = \033[0m
BEER = \xF0\x9F\x8D\xBA

vpath %.o ../objs/

all:
	gcc test.c $(addprefix ../objs/, $(OBJ)) -lrt -lm -o test -I ../includes -I ../libft/includes/ -L ../libft/ -lft

.PHONY: re all clean fclean
