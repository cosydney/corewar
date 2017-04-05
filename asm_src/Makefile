NAME 	=	asm
DOBJ 	=	objs
DSRC 	=	srcs
INC 	=	-I includes/ -I ../libft/includes
CC	 	=	gcc
CFLAGS 	=	-Wall -Werror -Wextra
SRC 	=	$(shell find $(DSRC) -name '*.c' -type f)
SDIR	=	$(shell find $(DSRC) -type d)
ODIR	=	$(addprefix $(DOBJ)/, $(SDIR))
OBJ 	=	$(patsubst %.c, $(DOBJ)/%.o, $(SRC))
LIBPATH =	../libft/

all: $(NAME)

$(NAME): $(OBJ)
	@make -C $(LIBPATH)
	@$(CC) $(OBJ) $(CFLAGS) $(INC) -L$(LIBPATH) -lft -o $(NAME)
	@echo "\033[32;1m$(NAME) created successfully!\033[0m"

$(DOBJ)/%.o:%.c
	@mkdir -p $(ODIR)
	@$(CC) -c -o $@ $< -I../libft $(INC) $(CFLAGS)

clean:
	@/bin/rm -rf $(DOBJ)

fclean: clean
	@/bin/rm -f $(NAME)
	@echo "\033[31;1m$(NAME) removes!\033[0m"

relib:
	@make -C $(LIBPATH) re

re: fclean all

.PHONY: re all clean fclean
