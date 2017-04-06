/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sycohen <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/03 19:50:25 by sycohen           #+#    #+#             */
/*   Updated: 2017/04/06 13:56:03 by sycohen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

static int		check_champ_name(char *champ)
{
	int i;

	i = 0;
	while (champ[i])
		i++;
	if (i >= 3 && champ[i - 1] == 's' && champ[i - 2] == '.')
		return (1);
	else
		return (asm_error(FILE_ERROR));
}

static void		display_champ_name(t_header *head)
{
	ft_printf("%-15s : %s\n", "Nom du Champion", head->prog_name);
	ft_printf("%-15s : %s\n", "Commentaire", head->comment);
}

char			*put_line_in_file(char *line, int i, char *file)
{
	while (line[i] == '\t' || line[i] == ' ')
		i++;
	if (line[i] && line[i] != COMMENT_CHAR && line[i] != ';' &&
			check_valid_line(&line[i]))
		file = asm_free_join(&line[i], file);
	free(line);
	line = NULL;
	return (file);
}

t_label			*parse_line(int fd, char **file)
{
	t_label *label;
	char	*line;
	int		i;

	label = NULL;
	line = NULL;
	while (!(i = 0) && ft_getline(fd, &line) > 0)
	{
		g_line++;
		while (line[i] == '\t' || line[i] == ' ')
			i++;
		if (line[i] && line[i] != COMMENT_CHAR && line[i] != ';' &&
				check_label(line) >= 1)
		{
			label = label_init(label, line);
			while (line[i] != LABEL_CHAR)
				i++;
			i++;
		}
		*file = put_line_in_file(line, i, *file);
	}
	return (label);
}

int				parsing(char *champion, t_header *head, int check)
{
	int		fd;
	char	*file;
	t_label	*label;

	label = NULL;
	file = NULL;
	check_champ_name(champion);
	if ((fd = open(champion, O_RDONLY, 0555)) == -1)
		return (-1);
	name_comment_handler(fd, head);
	if (check == 1)
		display_champ_name(head);
	label = parse_line(fd, &file);
	check_double_label(label);
	if (check_label_exist(label, file) == 0)
		return (asm_error(ARG_ERROR));
	reader(label, head, champion, file);
	if (file && file[0])
		free(file);
	if (label)
		free_label(label);
	return (0);
}
