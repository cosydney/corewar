/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_internal.h                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amarzial <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/08 17:49:26 by amarzial          #+#    #+#             */
/*   Updated: 2017/01/28 18:24:08 by amarzial         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_INTERNAL_H
# define FT_PRINTF_INTERNAL_H
# include <stdarg.h>
# include <stdint.h>

typedef struct	s_arg
{
	int		flag_alt;
	int		flag_zero;
	int		flag_left;
	int		flag_space;
	int		flag_sign;
	int		field_width;
	int		precision;
	int		prec_set;
	enum
	{
		none,
		hh,
		h,
		l,
		ll,
		j,
		z
	}		length_mod;
	char	conversion;
	int		size;
	int		fd;
}				t_arg;

int				ft_printf_core(int fd, const char *format, va_list *lst);
int				ft_printf_parse_arg(char *str, t_arg *arg, va_list *lst);
int				ft_printf_handler(t_arg *arg, va_list *lst);

/*
** handlers
*/
int				ft_printf_signed_decimal(t_arg *arg, va_list *lst);
int				ft_printf_unsigned_decimal(t_arg *arg, va_list *lst);
int				ft_printf_unsigned_octal(t_arg *arg, va_list *lst);
int				ft_printf_unsigned_hex(t_arg *arg, va_list *lst);
int				ft_printf_string(t_arg *arg, va_list *lst);
int				ft_printf_wstring(t_arg *arg, va_list *lst);
int				ft_printf_char(t_arg *arg, va_list *lst);
int				ft_printf_wchar(t_arg *arg, va_list *lst);
int				ft_printf_noconv(t_arg *arg, va_list *lst);

/*
** conversion
*/
void			ft_printf_signedtostr(char *out, intmax_t num, t_arg *arg);
void			ft_printf_unsignedtostr_base(char *out, uintmax_t num, \
t_arg *arg, char *base);

/*
** utilities
*/
void			ft_printf_putnchar(char c, int times, int fd);
int				idigits(intmax_t n, int base);
int				udigits(uintmax_t n, int base);
int				get_int_arg(va_list *lst);

#endif
