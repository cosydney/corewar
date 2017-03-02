NAME 	=	corewar
CC		=	clang
CFLAGS 	=	-Wall -Werror -Wextra -fsanitize=address
INC		=	-I includes/ -I libft/
SRCS 	=	main.c
OBJ		=	$(SRCS:.c=.o)
HDRS	=	corewar.h
SDIR	=	$(addprefix srcs/, $(SRCS))
ODIR	=	$(addprefix objs/, $(OBJ))
HDIR	=	$(addprefix includes/, $(HDRS))
LIBPATH =	-C ./libft
RED = \033[31;1m
GRN = \033[32;1m
YEL = \033[33;1m
BLU = \033[34;1m
MAG = \033[35;1m
CYN = \033[36;1m
WHT = \033[37;1m
EOC = \033[0m
BEER = \xF0\x9F\x8D\xBA

all: $(NAME)

$(NAME): $(ODIR)
	@make $(LIBPATH)
	@$(CC) $(CFLAGS) $(ODIR) -L./libft -lft -o $(NAME) $(INC)
	@echo "$(GRN)$(BEER) $(NAME) created successfully!$(EOC)"

objs/%.o: srcs/%.c $(HDIR)
	@mkdir -p objs
	@$(CC) $(CFLAGS) -c $< -o $@ $(INC)
	@echo "$(GRN)$< =>$(EOC) $(YEL)$@$(EOC) $(GRN)✓$(EOC)"

clean:
	@/bin/rm -rf objs
	@make clean $(LIBPATH)

fclean: clean
	@/bin/rm -f $(NAME)
	@make fclean $(LIBPATH)
	@echo "$(RED)$(NAME) removed!$(EOC)"

reli:
	@make clean $(LIBPATH)
	@rm -f libft/libft.a

re: fclean all

.PHONY: re all clean fclean
