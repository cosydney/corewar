/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amarzial <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/06 11:59:55 by amarzial          #+#    #+#             */
/*   Updated: 2017/03/04 11:04:52 by sycohen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>
# include <string.h>
# include <stdarg.h>
# include <stdint.h>
# include <unistd.h>
# include <stdlib.h>
# define GET_LINE_BUFF_SIZE 32
# include "libft.h"
# define FT_COL(x) "\x1B[" x "m"

typedef struct			s_reader
{
	int		fd;
	char	*buffer;
	char	*el;
	int		stop;
	size_t	r_size;
	size_t	b_size;
}						t_reader;

typedef struct			s_list
{
	void			*content;
	size_t			content_size;
	struct s_list	*next;
}						t_list;

typedef long long int	t_putnbr;
typedef unsigned char	t_uc;

void					*ft_memset(void *s, int c, size_t n);
void					ft_bzero(void *s, size_t n);
void					*ft_memcpy(void *dest, const void *src, size_t n);
void					*ft_memccpy(void *dest, const void *src, int c, \
		size_t n);
void					*ft_memmove(void *dest, const void *src, size_t n);
void					*ft_memchr(const void *s, int c, size_t n);
int						ft_memcmp(const void *s1, const void *s2, size_t n);
size_t					ft_strlen(const char *s);
char					*ft_strdup(const char *s);
char					*ft_strcpy(char *dest, const char *src);
char					*ft_strncpy(char *dest, const char *src, size_t n);
char					*ft_strcat(char *dest, const char *src);
char					*ft_strncat(char *dest, const char *src, size_t n);
size_t					ft_strlcat(char *dst, const char *src, size_t size);
char					*ft_strchr(char *s, int c);
char					*ft_strrchr(char *s, int c);
char					*ft_strstr(char *src, char *to_find);
char					*ft_strnstr(char *src, char *to_find, size_t len);
int						ft_strcmp(const char *s1, const char *s2);
int						ft_strncmp(const char *s1, const char *s2, size_t len);
int						ft_atoi(const char *nbr);
int						ft_isalpha(int c);
int						ft_isdigit(int c);
int						ft_isalnum(int c);
int						ft_isascii(int c);
int						ft_isprint(int c);
int						ft_toupper(int c);
int						ft_tolower(int c);
void					*ft_memalloc(size_t size);
void					ft_memdel(void **ap);
char					*ft_strnew(size_t size);
void					ft_strdel(char **as);
void					ft_strclr(char *s);
void					ft_striter(char *s, void (*f)(char*));
void					ft_striteri(char *s, void (*f)(unsigned int, char*));
char					*ft_strmap(char const *s, char (*f)(char));
char					*ft_strmapi(char const *s, \
		char(*f)(unsigned int, char));
int						ft_strequ(char const *s1, char const *s2);
int						ft_strnequ(char const *s1, char const *s2, size_t n);
char					*ft_strsub(char const *s, unsigned int start, \
		size_t len);
char					*ft_strjoin(char const *s1, char const *s2);
char					*ft_strtrim(char const *s);
char					**ft_strsplit(char const *s, char c);
char					*ft_itoa(int n);
void					ft_putchar(char c);
void					ft_putstr(char const *s);
void					ft_putendl(char const *s);
void					ft_putnbr(t_putnbr n);
void					ft_putchar_fd(char c, int fd);
void					ft_putstr_fd(char const *s, int fd);
void					ft_putendl_fd(char const *s, int fd);
void					ft_putnbr_fd(t_putnbr n, int fd);
t_list					*ft_lstnew(void const *content, size_t content_size);
void					ft_lstdelone(t_list **alst, void (*del)(void*, size_t));
void					ft_lstdel(t_list **alst, void (*del)(void *, size_t));
void					ft_lstadd(t_list **alst, t_list *new);
void					ft_lstiter(t_list *lst, void (*f)(t_list *elem));
t_list					*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem));
size_t					ft_lstlen(t_list *lst);
int						ft_error(char *str);
int						ft_strclen(char *str, char c);

/*
** My extra functions
*/
int						ft_abs(int nb);
void					ft_putptr(void *ptr);
char					*ft_itoa_base(t_putnbr n, int base);
intmax_t				ft_atoi2(const char *nbr);
void					ft_putnbr_base(t_putnbr n, int base);
int						ft_max(int a, int b);
int						ft_min(int a, int b);
void					ft_writeendl(int fd, char *buffer, size_t size);
int						ft_getline(const int fd, char **line);
size_t					ft_strcnt(const char *str, int c);
void					ft_putwchar_fd(wchar_t c, int fd);
void					ft_putwstr_fd(wchar_t *str, int fd);
void					ft_putwchar(wchar_t c);
void					ft_putwstr(wchar_t *str);
int						ft_printf_core(int fd, const char *format, \
										va_list *lst);
int						ft_printf_fd(int fd, const char *format, ...);
int						ft_printf(const char *format, ...);
int						ft_strtoi(int *dest, const char *nbr);
unsigned int			ft_strtou(unsigned int *dest, const char *nbr);

#endif
