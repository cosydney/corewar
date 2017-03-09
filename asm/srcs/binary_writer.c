/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   binary_writer.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sycohen <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/08 17:49:57 by sycohen           #+#    #+#             */
/*   Updated: 2017/03/09 14:33:37 by sycohen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

int			move_separator(char **file)
{
	while (**file && **file != SEPARATOR_CHAR && **file != '\n')
		(*file)++;
	if (**file == '\n')
		return (1);
	(*file)++;
	while (**file && (**file == ' ' || **file =='\t'))
		(*file)++;
	return (1);
}

char		*move_file(int fct, char *file)
{
	if (fct == LIVE || fct == ZJMP || fct == FORK || fct == LLDI)
		file = file + 4;
	else if (fct == LD || fct == ST || fct == OR)
		file = file + 2;
	else if (fct == LFORK)
		file = file + 5;
	else
		file = file + 3;
	while (*file && (*file == ' ' || *file == '\t'))
		file++;
	return (file);
}

int			function_call2(int fct, int fd, t_label *label, char **file)
{
	if ((fct == AND || fct == OR || fct == XOR) && opcode(fd, 3, 0, *file)
			&& ((write_register(fd, file) || write_direct(fd, 4, label, file) ||
					write_indirect(fd, label, file)) &&
				((write_register(fd, file) || write_direct(fd, 4, label, file) ||
				  write_indirect(fd, label, file)))))
		return (write_register(fd, file));
	else if (fct == ZJMP || fct == FORK ||fct == LFORK)
		return (write_direct(fd, 2, label, file));
	else if ((fct == LDI || fct == LLDI) && opcode(fd, 3, 0, *file) &&
		(((write_register(fd, file) || write_direct(fd, 2, label, file) ||
		   write_indirect(fd, label, file)) &&
		  (write_register(fd, file) || write_direct(fd, 2, label, file)))))
			return (write_register(fd, file));
	else if (fct == STI && opcode(fd, 3, 0, *file) &&
			((write_register(fd, file) && (write_register(fd, file) ||
			write_direct(fd, 2, label, file) || write_indirect(fd, label, file)) &&
			  (write_register(fd, file) || write_direct(fd, 2, label, file)))))
		return (1);
	else if (fct == AFF && write (fd, "@", 1) && ++g_temp)
		return (write_register(fd, file));
	return (1);
}

int			function_call(int fct, int fd, t_label *label, char **file)
{
	*file = move_file(fct, *file);
	write(fd, &fct, 1);
	if (fct == LIVE)
		return (write_direct(fd, 4, label, file));
	else if ((fct == LD || fct == LLD) && opcode(fd, 2, 0, *file) &&
			((write_direct(fd, 4, label, file) || write_indirect(fd, label, file))))
		return (write_register(fd, file));
	else if (fct == ST && opcode(fd, 2, 0, *file) && write_register(fd, file)
			&& (write_register(fd, file) || write_indirect(fd, label, file)))
		return (1);
	else if ((fct == ADD || fct == SUB) && write(fd, "T", 1) && ++g_temp &&
			write_register(fd, file) && write_register(fd, file) &&
			write_register(fd, file))
		return (1);
	return (function_call2(fct, fd, label, file));
}

int			binary_creator(int fd, t_label *label, char *file)
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
