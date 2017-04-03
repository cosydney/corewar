/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   write_octal.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sycohen <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/08 18:40:57 by sycohen           #+#    #+#             */
/*   Updated: 2017/03/14 12:50:28 by sycohen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

void	opcode_assign(int *octout, int i, int check, char *file)
{
	if (check == 1 && file[i] == 'r')
		*octout = 0x40;
	else if (check == 1 && file[i] == '%')
		*octout = 0x80;
	else if (check == 1)
		*octout = 0xC0;
	if (check == 2 && file[i] == 'r')
		*octout = 0x10;
	else if (check == 2 && file[i] == '%')
		*octout = 0x20;
	else if (check == 2)
		*octout = 0x30;
	if (check == 3 && file[i] == 'r')
		*octout = 0x4;
	else if (check == 3 && file[i] == '%')
		*octout = 0x8;
	else if (check == 3)
		*octout = 0xC;
}

int		write_indirect(int fd, t_label *label, char **file)
{
	int i;

	i = 0;
	if (**file == LABEL_CHAR && (*file)++)
		i = calculate_i(*file, label);
	else
		i = ft_atoi(*file);
	i = cw_invert_endian2(i);
	write(fd, &i, T_IND);
	g_temp = g_temp + T_IND;
	move_separator(file);
	return (1);
}

int		opcode(int fd, int arg, int i, char *file)
{
	int octout;
	int octin;

	octin = 0;
	octout = 0;
	opcode_assign(&octout, i, 1, file);
	octin = (octin | octout);
	if (arg > 1)
	{
		i = move_i(i, file);
		opcode_assign(&octout, i, 2, file);
		octin = (octin | octout);
	}
	if (arg > 2)
	{
		i = move_i(i, file);
		opcode_assign(&octout, i, 3, file);
		octin = (octin | octout);
	}
	g_temp++;
	write(fd, &octin, 1);
	return (1);
}

int		write_direct(int fd, int size, t_label *label, char **file)
{
	int i;

	if (!(i = 0) && **file != DIRECT_CHAR)
		return (0);
	if (++(*file) && **file == LABEL_CHAR && (*file)++)
		i = calculate_i(*file, label);
	else
		i = ft_atoi(*file);
	if (size == 4)
		i = cw_invert_endian(i);
	else
		i = cw_invert_endian2(i);
	write(fd, &i, size);
	g_temp = g_temp + size;
	move_separator(file);
	return (1);
}

int		write_register(int fd, char **file)
{
	int i;

	i = 0;
	if (**file != 'r')
		return (0);
	i = ft_atoi(++(*file));
	write(fd, &i, T_REG);
	g_temp = g_temp + T_REG;
	move_separator(file);
	return (1);
}
