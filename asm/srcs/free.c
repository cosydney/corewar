/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sycohen <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/04 13:53:44 by sycohen           #+#    #+#             */
/*   Updated: 2017/03/09 14:49:50 by sycohen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

char	*asm_realloc(char *line, char *file, int i)
{
	int		len;
	char	*tmp;
	char	*sub;

	len = 0;
	tmp = NULL;
	sub = NULL;
	sub = ft_strsub(line, i, ft_strlen(line) - i);
	if (!(tmp = malloc(sizeof(char) * (ft_strlen(file) + ft_strlen(sub) + 2))))
		return (NULL);
	tmp = ft_strcpy(tmp, file);
	tmp = ft_strcat(tmp, sub);
	free(file);
	free(sub);
	file = NULL;
	sub = NULL;
	while (tmp[len])
		len++;
	tmp[len] = '\n';
	tmp[len + 1] = '\0';
	file = ft_strdup(tmp);
	free(tmp);
	return (file);
}

int		free_label(t_label *label)
{
	t_label *nxt;

	nxt = label->next;
	while (nxt)
	{
		label->next = NULL;
		free(label->name);
		free(label);
		label = nxt;
		nxt = label->next;
	}
	free(label->name);
	free(label);
	return (1);
}

char	*asm_free_join(char *line, char *file)
{
	int		i;
	int		len;
	char	*sub;

	i = 0;
	sub = NULL;
	if (line[i])
	{
		if (!(len = 0) && !file)
		{
			sub = ft_strsub(line, i, ft_strlen(line) - i);
			if (!(file = malloc(sizeof(char) * (ft_strlen(sub) + 2))))
				return (NULL);
			file = ft_strcpy(file, sub);
			while (file[len])
				len++;
			file[len] = '\n';
			file[len + 1] = '\0';
			free(sub);
			sub = NULL;
		}
		else
			file = asm_realloc(line, file, i);
	}
	return (file);
}

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
		return (asm_error(LINES_ERROR));
	}
	return (0);
}
