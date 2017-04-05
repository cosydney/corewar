/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   binary_writer.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sycohen <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/08 17:49:57 by sycohen           #+#    #+#             */
/*   Updated: 2017/04/05 18:09:52 by amarzial         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

char	*move_file(int fct, char *file)
{
	if (fct == 1 || fct == 9 || fct == 12 || fct == 14)
		file = file + 4;
	else if (fct == 2 || fct == 3 || fct == 7)
		file = file + 2;
	else if (fct == 15)
		file = file + 5;
	else
		file = file + 3;
	while (*file && (*file == ' ' || *file == '\t'))
		file++;
	return (file);
}

int		move_separator(char **file)
{
	while (**file && **file != SEPARATOR_CHAR && **file != '\n')
		(*file)++;
	if (**file == '\n')
		return (1);
	(*file)++;
	while (**file && (**file == ' ' || **file == '\t'))
		(*file)++;
	return (1);
}

int		function_call2(int fct, int fd, t_label *label, char **file)
{
	if ((fct == 6 || fct == 7 || fct == 8) && opcode(fd, 3, 0, *file)
		&& ((write_register(fd, file) || write_direct(fd, 4, label, file) ||
		write_indirect(fd, label, file)) &&
		((write_register(fd, file) || write_direct(fd, 4, label, file) ||
		write_indirect(fd, label, file)))))
		return (write_register(fd, file));
	else if (fct == 9 || fct == 12 || fct == 15)
		return (write_direct(fd, 2, label, file));
	else if ((fct == 10 || fct == 14) && opcode(fd, 3, 0, *file) &&
		(((write_register(fd, file) || write_direct(fd, 2, label, file) ||
		write_indirect(fd, label, file)) &&
		(write_register(fd, file) || write_direct(fd, 2, label, file)))))
		return (write_register(fd, file));
	else if (fct == 11 && opcode(fd, 3, 0, *file) &&
		((write_register(fd, file) && (write_register(fd, file) ||
		write_direct(fd, 2, label, file) || write_indirect(fd, label, file)) &&
		(write_register(fd, file) || write_direct(fd, 2, label, file)))))
		return (1);
	else if (fct == 16 && write(fd, "@", 1) && ++g_temp)
		return (write_register(fd, file));
	return (1);
}

int		function_call(int fct, int fd, t_label *label, char **file)
{
	*file = move_file(fct, *file);
	write(fd, &fct, 1);
	if (fct == 1)
		return (write_direct(fd, 4, label, file));
	else if ((fct == 2 || fct == 13) && opcode(fd, 2, 0, *file) &&
		((write_direct(fd, 4, label, file) || write_indirect(fd, label, file))))
		return (write_register(fd, file));
	else if (fct == 3 && opcode(fd, 2, 0, *file) && write_register(fd, file)
		&& (write_register(fd, file) || write_indirect(fd, label, file)))
		return (1);
	else if ((fct == 4 || fct == 5) && write(fd, "T", 1) && ++g_temp &&
		write_register(fd, file) && write_register(fd, file) &&
		write_register(fd, file))
		return (1);
	return (function_call2(fct, fd, label, file));
}

int		binary_creator(int fd, t_label *label, char *file)
{
	int fct;

	fct = 0;
	while (*file)
	{
		fct = asm_instruct_name(file);
		if (fct)
			g_temp++;
		function_call(fct, fd, label, &file);
		while (*file && *file != '\n')
			file++;
		file++;
		g_pos = g_pos + g_temp;
		g_temp = 0;
	}
	return (1);
}
