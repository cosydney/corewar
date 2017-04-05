CC = gcc
CFLAGS = -Wall -Wextra -Werror
SOURCES = ./srcs/ft_abs.c \
		  ./srcs/ft_bzero.c \
		  ./srcs/ft_atoi.c \
		  ./srcs/ft_atoi2.c \
		  ./srcs/ft_isalnum.c \
		  ./srcs/ft_isalpha.c \
		  ./srcs/ft_isascii.c \
		  ./srcs/ft_isdigit.c \
		  ./srcs/ft_isprint.c \
		  ./srcs/ft_itoa.c \
		  ./srcs/ft_lstadd.c \
		  ./srcs/ft_lstdel.c \
		  ./srcs/ft_lstdelone.c \
		  ./srcs/ft_lstiter.c \
		  ./srcs/ft_lstlen.c \
		  ./srcs/ft_lstmap.c \
		  ./srcs/ft_lstnew.c \
		  ./srcs/ft_memalloc.c \
		  ./srcs/ft_memccpy.c \
		  ./srcs/ft_memchr.c \
		  ./srcs/ft_memcmp.c \
		  ./srcs/ft_memcpy.c \
		  ./srcs/ft_memdel.c \
		  ./srcs/ft_memmove.c \
		  ./srcs/ft_memset.c \
		  ./srcs/ft_putchar.c \
		  ./srcs/ft_putchar_fd.c \
		  ./srcs/ft_putendl.c \
		  ./srcs/ft_putendl_fd.c \
		  ./srcs/ft_putnbr.c \
		  ./srcs/ft_putnbr_fd.c \
		  ./srcs/ft_putstr.c \
		  ./srcs/ft_putstr_fd.c \
		  ./srcs/ft_strcat.c \
		  ./srcs/ft_strchr.c \
		  ./srcs/ft_strclr.c \
		  ./srcs/ft_strcmp.c \
		  ./srcs/ft_strcpy.c \
		  ./srcs/ft_strdel.c \
		  ./srcs/ft_strdup.c \
		  ./srcs/ft_strequ.c \
		  ./srcs/ft_striter.c \
		  ./srcs/ft_striteri.c \
		  ./srcs/ft_strjoin.c \
		  ./srcs/ft_strlcat.c \
		  ./srcs/ft_strlen.c \
		  ./srcs/ft_strmap.c \
		  ./srcs/ft_strmapi.c \
		  ./srcs/ft_strncat.c \
		  ./srcs/ft_strncmp.c \
		  ./srcs/ft_strncpy.c \
		  ./srcs/ft_strnequ.c \
		  ./srcs/ft_strnew.c \
		  ./srcs/ft_strnstr.c \
		  ./srcs/ft_strrchr.c \
		  ./srcs/ft_strsplit.c \
		  ./srcs/ft_strstr.c \
		  ./srcs/ft_strsub.c \
		  ./srcs/ft_strtoi.c \
		  ./srcs/ft_strtou.c \
		  ./srcs/ft_strtrim.c \
		  ./srcs/ft_tolower.c \
		  ./srcs/ft_toupper.c \
		  ./srcs/ft_putptr.c \
		  ./srcs/ft_itoa_base.c \
		  ./srcs/ft_putnbr_base.c \
		  ./srcs/ft_max.c \
		  ./srcs/ft_min.c \
		  ./srcs/ft_writeendl.c \
		  ./srcs/ft_get_line.c \
		  ./srcs/ft_strcnt.c \
		  ./srcs/ft_putwchar.c \
		  ./srcs/ft_putwstr.c \
		  ./srcs/ft_putwchar_fd.c \
		  ./srcs/ft_putwstr_fd.c \
		  ./srcs/ft_printf/srcs/ft_printf_core.c \
		  ./srcs/ft_printf/srcs/ft_printf_fd.c \
		  ./srcs/ft_printf/srcs/ft_printf.c \
		  ./srcs/ft_printf/srcs/ft_printf_char.c \
		  ./srcs/ft_printf/srcs/ft_printf_handlings.c \
		  ./srcs/ft_printf/srcs/ft_printf_noconv.c \
		  ./srcs/ft_printf/srcs/ft_printf_parser.c \
		  ./srcs/ft_printf/srcs/ft_printf_signed_decimal.c \
		  ./srcs/ft_printf/srcs/ft_printf_signedtostr.c \
		  ./srcs/ft_printf/srcs/ft_printf_string.c \
		  ./srcs/ft_printf/srcs/ft_printf_unsigned_decimal.c \
		  ./srcs/ft_printf/srcs/ft_printf_unsigned_hex.c \
		  ./srcs/ft_printf/srcs/ft_printf_unsigned_octal.c \
		  ./srcs/ft_printf/srcs/ft_printf_unsignedtostr_base.c \
		  ./srcs/ft_printf/srcs/ft_printf_utils.c \
		  ./srcs/ft_printf/srcs/ft_printf_wchar.c \
		  ./srcs/ft_printf/srcs/ft_printf_wstring.c \
		  ft_error.c\
		  ft_strclen.c\

INCLUDES = ./includes/libft.h \
		   ./includes/ft_printf_handler.h \
		   ./includes/ft_printf_internal.h

OBJECTS = $(notdir $(SOURCES:.c=.o))
NAME = libft.a

vpath %.c ./srcs ./srcs/ft_printf/srcs

all: $(NAME)
	@echo > /dev/null

$(NAME): $(OBJECTS)
	@ printf "\33[2K"
	@ printf "Creating library => "
	@ if ar rc $(NAME) $(OBJECTS) ; \
		then printf "✅\n"; \
		else printf "❌\n"; fi
	@ ranlib $(NAME)
	@ echo "Finished"

%.o: %.c $(INCLUDES)
	@ printf "\33[2K"
	@ printf "Compiling: $< ..."
	@ $(CC) -o $@ -c $(CFLAGS) $< $(addprefix -I ,$(sort $(dir $(INCLUDES))))
	@ printf "\r"

clean:
	@ echo "Deleting object files"
	@ rm -f $(OBJECTS)

fclean: clean
	@ echo "Deleting $(NAME)"
	@ rm -f $(NAME)

re: fclean all

