/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_arg.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sycohen <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/06 17:06:11 by sycohen           #+#    #+#             */
/*   Updated: 2017/03/06 17:54:18 by sycohen          ###   ########.fr       */
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
	return (0);
	//todo
}
