/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_arg.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sycohen <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/06 17:06:11 by sycohen           #+#    #+#             */
/*   Updated: 2017/03/14 13:25:25 by sycohen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

static int	check_arg_sec(char **line, int op)
{
	if (op == ST && check_register(line, 1) && (check_indirect(line, 0) ||
				check_register(line, 0)))
		return (1);
	if ((op == ADD || op == SUB) && check_register(line, 1) &&
			check_register(line, 1) && check_register(line, 0))
		return (1);
	if ((op == LDI || op == LLDI) && (check_direct(line, op, 1) ||
				check_register(line, 1) || check_indirect(line, 1)) &&
			(check_direct(line, op, 1) || check_register(line, 1)) &&
			check_register(line, 0))
		return (1);
	return (asm_error(ARGS_ERROR));
}

int			check_arg(char **line, int op)
{
	while (**line == ' ' || **line == '\t')
		(*line)++;
	if ((op == LIVE || op == ZJMP || op == FORK || op == LFORK) &&
			check_direct(line, op, 0))
		return (1);
	if ((op == LD || op == LLD) && (check_direct(line, op, 1) ||
				check_indirect(line, 1)) && check_register(line, 0))
		return (1);
	if ((op == AND || op == OR || op == XOR) && ((check_direct(line, op, 1) ||
					check_register(line, 1) || check_indirect(line, 1))
				&& (check_direct(line, op, 1) || check_register(line, 1) ||
					check_indirect(line, 1)) && check_register(line, 0)))
		return (1);
	if (op == STI && check_register(line, 1) && (check_direct(line, op, 1) ||
				check_register(line, 1) || check_indirect(line, 1)) &&
			(check_direct(line, op, 0) || check_register(line, 0)))
		return (1);
	if (op == AFF && check_register(line, 0))
		return (1);
	return (check_arg_sec(line, op));
}
