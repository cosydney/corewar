/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_arg.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sycohen <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/06 17:06:11 by sycohen           #+#    #+#             */
/*   Updated: 2017/03/06 18:18:39 by sycohen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

int		check_arg(char **line, int op)
{
	while (**line == ' ' || **line == '\t')
		(*line)++;
	if ((op == LIVE || op == ZJMP || op == FORK || op == LFORK) &&
			check_direct(line, op, 0))
		return (1);
	if ((op == LD || op == LLD) && (check_direct(line, op, 1) ||
				check_indirect(line, 1)) && check_register(line, 0))
	   return (1);	//todo check_ind && check_reg
	return (0);
	//todo
}
