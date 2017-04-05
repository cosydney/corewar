/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   label_init.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sycohen <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/04 16:10:30 by sycohen           #+#    #+#             */
/*   Updated: 2017/03/14 13:24:58 by sycohen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

t_label		*label_init(t_label *label, char *line)
{
	t_label		*new;
	int			len;

	len = 0;
	if (!(new = malloc(sizeof(t_label))))
		return (NULL);
	while (line[len] != LABEL_CHAR)
		len++;
	new->name = NULL;
	new->next = NULL;
	new->pos = 0;
	new->name = ft_strsub(line, 0, len);
	new->pos = g_pos;
	new->next = label;
	return (new);
}
