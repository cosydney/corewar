/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   write_octal.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sycohen <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/08 18:40:57 by sycohen           #+#    #+#             */
/*   Updated: 2017/03/08 19:10:28 by sycohen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

int		write_indirect(int fd, t_label *label, char **file)
{
	int i;
	int len;

	len = 0;
	i = 0;
	if (**file == LABEL_CHAR && (*file)++)
		i = calculate_i(*file, label);
	else
		i = ft_atoi(*file);
	i = cw_invert_endian2(i);//todo
	write(fd, &i, T_IND);
	move_separator(file);
	return (1);
}

int		write_direct(int fd, int size, t_label *label, char **file)
{
	int i;
	int len;

	len = 0;
	if (!(i = 0) && **file != DIRECT_CHAR)
		return (0);
	if (++(*file) && **file == LABEL_CHAR && (*file)++)
		i = calculate_i(*file, label);
	else
		i = ft_atoi(*file);
	if (size == 4)
		i = cw_invert_endian(i);
	//todo else
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
