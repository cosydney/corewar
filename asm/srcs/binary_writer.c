/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   binary_writer.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sycohen <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/08 17:49:57 by sycohen           #+#    #+#             */
/*   Updated: 2017/03/08 19:10:30 by sycohen          ###   ########.fr       */
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

int			function_call(int fct, int fd, t_label *label, char **file)
{
	if ((fct == AND || fct == OR || fct == XOR) && opcode(fd, 3, 0, *file)//todo opcode
			&& ((write_register(fd, file) || write_direct(fd, 4, label, file) ||
					write_indirect(fd, label, file)) &&
				((write_register(fd, file) || write_direct(fd, 4, label, file) ||
				  write_indirect(fd, label, file)))))
		return (write_register(fd, file));
	//tofinish
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
