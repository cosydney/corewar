NAME 	=	corewar
CC		=	clang
CFLAGS 	=	-Wall -Werror -Wextra -fsanitize=address
INC		=	-I includes/ -I libft/
SRCS 	=	main.c \
OBJ		=	$(SRCS:.c=.o)
HDRS	=	lem_in.h
SDIR	=	$(addprefix srcs/, $(SRCS))
ODIR	=	$(addprefix objs/, $(OBJ))
HDIR	=	$(addprefix includes/, $(HDRS))
LIBPATH =	-C ./libft

all: $(NAME)

$(NAME): $(ODIR)
	@make $(LIBPATH)
	@$(CC) $(CFLAGS) $(ODIR) -L./libft -lft -o $(NAME) $(INC)
	@echo "\033[32;1m$(NAME) created successfully!\033[0m"

objs/%.o: srcs/%.c $(HDIR)
	@mkdir -p objs
	@$(CC) $(CFLAGS) -c $< -o $@ $(INC)

clean:
	@/bin/rm -rf objs
	@make clean $(LIBPATH)

fclean: clean
	@/bin/rm -f $(NAME)
	@make fclean $(LIBPATH)
	@echo "\033[31;1m$(NAME) removed!\033[0m"

relib:
	@make clean $(LIBPATH)
	@rm -f libft/libft.a

re: fclean all

.PHONY: re all clean fclean
