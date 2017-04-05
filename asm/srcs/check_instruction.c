/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_instruction.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sycohen <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/06 10:59:34 by sycohen           #+#    #+#             */
/*   Updated: 2017/03/14 13:08:27 by sycohen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

/*
** Increment upon instruction's length
*/

int			check_valid_line(char *line)
{
	int fct;

	fct = asm_instruct_name(line);
	if (fct)
		g_pos++;
	if (fct == LIVE || fct == ZJMP || fct == FORK || fct == LLDI)
		line = line + 4;
	else if (fct == LD || fct == ST || fct == OR)
		line = line + 2;
	else if (fct == LFORK)
		line = line + 5;
	else
		line = line + 3;
	if (fct != LIVE && fct != ZJMP && fct != FORK && fct != LFORK)
		g_pos++;
	check_arg(&line, fct);
	while (*line && *line != '\n' && *line != COMMENT_CHAR && *line != ';')
		if (*line && *line != ' ' && *line != '\t' && *line != '\n')
			return (asm_error(ARG_ERROR));
		else
			line++;
	return (1);
}

static int	check_comma(char **line)
{
	while (**line == '\t' || **line == ' ')
		(*line)++;
	if (**line != SEPARATOR_CHAR)
		return (asm_error(ARGS_ERROR));
	(*line)++;
	while (**line == '\t' || **line == ' ')
		(*line)++;
	return (1);
}

int			check_register(char **line, int check)
{
	int reg;

	reg = 0;
	if (**line == 'r')
	{
		(*line)++;
		reg = ft_atoi(*line);
		if (reg > REG_NUMBER || reg <= 0)
			return (asm_error(REG_ERROR));
		(*line)++;
		if (reg > 9)
			(*line)++;
		if (reg > 99)
			(*line)++;
		g_pos++;
		if (check == 1)
			return (check_comma(line));
		return (1);
	}
	return (0);
}

int			check_direct(char **line, int op, int check)
{
	if (**line == DIRECT_CHAR)
	{
		if (op > 8 && op != 13)
			g_pos = g_pos + 2;
		else
			g_pos = g_pos + 4;
		(*line)++;
		if (**line != LABEL_CHAR && !(**line >= '0' && **line <= '9') &&
				**line != '-' && **line != '+')
			asm_error(LABEL_ERROR);
		if (**line == LABEL_CHAR)
			(*line)++;
		else if (**line == '+' || **line == '-')
			(*line)++;
		while (**line && ft_strchr(LABEL_CHARS, **line))
			(*line)++;
		while (**line == ' ' || **line == '\t')
			(*line)++;
		if (check == 1)
			return (check_comma(line));
		return (1);
	}
	return (0);
}

int			check_indirect(char **line, int check)
{
	if (**line == LABEL_CHAR)
	{
		(*line)++;
		while (**line && ft_strchr(LABEL_CHARS, **line))
			(*line)++;
	}
	else if (((**line == '+' || **line == '-') && (*line)++) ||
			ft_isdigit(**line))
	{
		while (ft_isdigit(**line))
			(*line)++;
	}
	else
		return (0);
	if (**line != '\0' && **line != '\n'
			&& **line != SEPARATOR_CHAR && **line != ' ' && **line != '\t')
		return (asm_error(INDIRECT_ERROR));
	g_pos = g_pos + 2;
	if (check == 1)
		return (check_comma(line));
	return (1);
}
