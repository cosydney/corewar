/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_label.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sycohen <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/04 15:35:07 by sycohen           #+#    #+#             */
/*   Updated: 2017/03/14 12:32:16 by sycohen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

static int		match_label(t_label *label, char *str)
{
	int i;

	i = 0;
	while (ft_strchr(LABEL_CHARS, str[i]))
		i++;
	while (label)
	{
		if (ft_strncmp(label->name, str, i) == 0)
		{
			if (!label->name[i])
				return (1);
		}
		label = label->next;
	}
	return (asm_error(LABEL_MATCH_ERROR));
}

int				check_label_exist(t_label *label, char *str)
{
	int len;

	len = 0;
	if (!str)
		return (0);
	while (str[len] && str[len] != DIRECT_CHAR)
	{
		len++;
		if (str[len] == DIRECT_CHAR)
		{
			len++;
			if (str[len] == LABEL_CHAR)
			{
				len++;
				match_label(label, &str[len]);
			}
		}
	}
	return (1);
}

int				check_label(char *str)
{
	int i;

	i = 0;
	while (str[i] == ' ' || str[i] == '\t')
		i++;
	while (str[i] && ft_strchr(LABEL_CHARS, str[i]))
		i++;
	if (str[i] == LABEL_CHAR && i > 0)
	{
		i++;
		while (str[i] == ' ' || str[i] == '\t')
			i++;
		if (str[i] == '\n' || str[i] == '\0' || str[i] == COMMENT_CHAR)
			return (1);
		return (2);
	}
	else if (str[i] && str[i] != ' ' && str[i] != '\0' && str[i] != ';' &&
	str[i] != '\n' && str[i] != '\t' &&
	str[i] != COMMENT_CHAR && str[i] != ',')
	{
		if (str[i + 1] == ' ' || str[i + 1] == '\n' || str[i + 1] == '\0')
			return (asm_error(LABEL_CHAR_ERROR));
		return (asm_error(LABELS_ERROR));
	}
	return (0);
}

int				check_double_label(t_label *label)
{
	t_label *start;

	start = label;
	if (!label)
		return (1);
	label = label->next;
	while (label)
	{
		if (ft_strcmp(start->name, label->name) == 0)
			return (asm_error(LABELS_DOUBLE_ERROR));
		label = label->next;
	}
	return (check_double_label(start->next));
}
