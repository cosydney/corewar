# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: abonneca <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/11/03 09:59:58 by abonneca          #+#    #+#              #
#    Updated: 2017/03/02 11:16:51 by abonneca         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC=clang

FLAGS=-Wall -Wextra -Werror

NAME=libft.a

SRC=	ft_memset.c\
		ft_bzero.c\
		ft_memcpy.c\
		ft_memccpy.c\
		ft_memmove.c\
		ft_memchr.c\
		ft_memcmp.c\
		ft_strlen.c\
		ft_strdup.c\
		ft_strcpy.c\
		ft_strncpy.c\
		ft_strcat.c\
		ft_strncat.c\
		ft_strlcat.c\
		ft_strchr.c\
		ft_strrchr.c\
		ft_strstr.c\
		ft_strnstr.c\
		ft_strcmp.c\
		ft_strncmp.c\
		ft_atoi.c\
		ft_isalpha.c\
		ft_isdigit.c\
		ft_isalnum.c\
		ft_isascii.c\
		ft_isprint.c\
		ft_toupper.c\
		ft_tolower.c\
		ft_memalloc.c\
		ft_memdel.c\
		ft_strnew.c\
		ft_strdel.c\
		ft_strclr.c\
		ft_striter.c\
		ft_striteri.c\
		ft_strmap.c\
		ft_strmapi.c\
		ft_strequ.c\
		ft_strnequ.c\
		ft_strsub.c\
		ft_strjoin.c\
		ft_strtrim.c\
		ft_strsplit.c\
		ft_itoa.c\
		ft_putchar.c\
		ft_putstr.c\
		ft_putendl.c\
		ft_putnbr.c\
		ft_putchar_fd.c\
		ft_putstr_fd.c\
		ft_putendl_fd.c\
		ft_putnbr_fd.c\
		ft_lstnew.c\
		ft_lstdelone.c\
		ft_lstdel.c\
		ft_lstadd.c\
		ft_lstiter.c\
		ft_lstmap.c\
		ft_count_words.c\
		ft_print_words_tables.c\
		ft_is_prime.c\
		ft_swap.c\
		ft_strrev.c\
		ft_sort_int_tab.c\
		ft_pgcd.c\
		ft_list_size.c\
		get_next_line.c\

RED = \033[31;1m
GRN = \033[32;1m
YEL = \033[33;1m
BLU = \033[34;1m
MAG = \033[35;1m
CYN = \033[36;1m
WHT = \033[37;1m
EOC = \033[0m
BEER = \xF0\x9F\x8D\xBA

OBJ=$(SRC:.c=.o)

$(NAME): $(OBJ)
	@ar rc $(NAME) $(OBJ)
	@ranlib $(NAME)
	@echo "$(GRN)$(BEER) $(NAME) created successfully!$(EOC)"

all: $(NAME)

%.o: %.c
	@$(CC) -c $^ -o $@
	@echo "$(GRN)$< =>$(EOC) $(YEL)$@$(EOC) $(GRN)✓$(EOC)"

clean:
	@rm -rf $(OBJ)

fclean: clean
	@rm -rf $(NAME)
	@echo "$(RED)$(NAME) removed!$(EOC)"

re: fclean all

.PHONY: clean
	clean:
	rm -rf $(OBJ)
