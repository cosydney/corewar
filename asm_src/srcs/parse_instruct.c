/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_instruct.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sycohen <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/06 11:17:14 by sycohen           #+#    #+#             */
/*   Updated: 2017/04/05 17:15:10 by amarzial         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

/*
** Check if instructions is correct et return corresponding int
*/

static int	instruct_name_sec(char *line)
{
	if (ft_strncmp("ldi", line, 3) == 0)
		return (LDI);
	if (ft_strncmp("ld", line, 2) == 0)
		return (LD);
	if (ft_strncmp("fork", line, 4) == 0)
		return (FORK);
	if (ft_strncmp("st", line, 2) == 0)
		return (ST);
	if (ft_strncmp("lldi", line, 4) == 0)
		return (LLDI);
	if (ft_strncmp("lld", line, 3) == 0)
		return (LLD);
	if (ft_strncmp("lfork", line, 5) == 0)
		return (LFORK);
	if (ft_strncmp("aff", line, 3) == 0)
		return (AFF);
	return (0);
}

int			asm_instruct_name(char *line)
{
	if (ft_strncmp("live", line, 4) == 0)
		return (LIVE);
	if (ft_strncmp("add", line, 3) == 0)
		return (ADD);
	if (ft_strncmp("sub", line, 3) == 0)
		return (SUB);
	if (ft_strncmp("and", line, 3) == 0)
		return (AND);
	if (ft_strncmp("or", line, 2) == 0)
		return (OR);
	if (ft_strncmp("xor", line, 3) == 0)
		return (XOR);
	if (ft_strncmp("zjmp", line, 4) == 0)
		return (ZJMP);
	if (ft_strncmp("sti", line, 3) == 0)
		return (STI);
	return (instruct_name_sec(line));
}

int			move_i(int i, char *file)
{
	while (file[i] != ',')
		i++;
	i++;
	while (file[i] == '\t' || file[i] == ' ')
		i++;
	return (i);
}

int			calculate_i(char *file, t_label *label)
{
	size_t	len;

	len = 0;
	while (ft_strchr(LABEL_CHARS, file[len]))
		len++;
	while (label)
	{
		if (len >= ft_strlen(label->name))
		{
			if (!ft_strncmp(file, label->name, len))
				return (label->pos - g_pos);
		}
		else if (!ft_strncmp(file, label->name, ft_strlen(label->name)))
			return (label->pos - g_pos);
		label = label->next;
	}
	return (asm_error(ARG_ERROR));
}
