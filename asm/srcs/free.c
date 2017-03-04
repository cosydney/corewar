/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sycohen <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/04 13:53:44 by sycohen           #+#    #+#             */
/*   Updated: 2017/03/04 16:29:03 by sycohen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

int		check_header(t_header *head, char *line)
{
	if (head->comment[0] && head->prog_name[0])
	{
		if (ft_strrchr(line, '"') != ft_strchr(line, '"'))
		{
			free(line);
			line = NULL;
			return (1);
		}
		ft_printf_fd(2, "Multiples lines on name or comment");
	}
	return (0);
}
