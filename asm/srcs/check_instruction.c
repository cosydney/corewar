/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_instruction.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sycohen <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/06 10:59:34 by sycohen           #+#    #+#             */
/*   Updated: 2017/03/06 17:58:21 by sycohen          ###   ########.fr       */
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
	if (fct != LIVE && fct != ZJMP && fct != FORK & fct != LFORK)
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
			asm_error(15);
		if (**line == LABEL_CHAR)
			(*line)++;
		else if (**line == '+' || **line =='-')
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
