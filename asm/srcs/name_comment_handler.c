/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   name_comment_handler.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sycohen <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/03 20:10:01 by sycohen           #+#    #+#             */
/*   Updated: 2017/03/03 21:09:33 by sycohen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

static int			header_pass(char *line, int name, int com, int check)
{
	int i;

	if (check)
		i = name;
	else
		i = com;
	while (line[i] == ' ' || line[i] == '\t')
		i++;
	if (line[i] != '"')
		return (0);
	i++;
	return (i);
}

static t_header		save_header(char *line, t_header *head, int check)
{
	char *tmp;

	tmp = NULL;
	if (check == 0)
	{
		tmp = ft_strsub(line, 0, ft_strclen(line, '"'));
		ft_strncat(head->prog_name, tmp, PROG_NAME_LENGTH);
	}
	if (check == 1)
	{
		if (line[0] == '"')
			ft_strcpy(head->comment, "I am commentless.");
		else
		{
			tmp = ft_strsub(line, 0, ft_strclen(line, '"'));
			ft_strncat(head->comment, tmp, COMMENT_LENGTH);
		}
	}
	if (tmp != NULL)
		free (tmp);
	tmp = NULL;
	return (head);
}

static int			header_pass_end(char *line, int i)
{
	while (line[i] && line[i] != '"')
		i++;
	if (line[i] == '"')
		i++;
	while (line[i] && line[i] != '\n' && i++)
		if (line[i] && line[i] != ' ' && line[i] != '\t')
			return (ft_error("Wrong format name -> line: "));// todo line with ft_error with line number
	return (0);
}

static int			save_name_comment(char *line, t_header *head, int name, int com)
{
	int		i;
	char	*tmp;

	i = 0;
	tmp = NULL;
	if (!head->prog_name[0] && ft_strcmp(NAME_CMD_STRING, line, name) == 0)
	{
		if ((i = header_pass(line, name, com, 1)) == 0)
			return (ft_error("Wrong format name -> line: "));//todo line with ft_error line number
		else
			save_header(&line[i], head, 0);
	}
	else if (!head->comment[0] && ft_strncmp(COMMENT_CMD_STRING, line, cmd) == 0)
	{
		if ((i = header_pass(line, name, com, 0)) == 0)
			return (ft_error("No name or comment."));
		else
			head = save_header(&line[i], head, 1);
	}
	else
		return (ft_error("No name or comment."));
	return (header_pass_end(line, i));
}

int			name_comment_handler(int fd, t_header *head)
{
	int		i;
	char	*line;

	i = 0;
	line = 0;
	while (get_next_line(fd, &line) > 0)
	{
		g_line++;
		if (line[0] != COMMENT_CHAR && line[0] != ';' && line[0] != '\0')
		{
			while ((line[i] == ' ' || line[i] == '\t') && line[i] != '\0')
				i++;
			save_name_comment(&line[i], head, ft_strlen(NAME_CMD_STRING), ft_strlen(COMMENT_CMD_STRING));
			ft_strlen(COMMENT_CMD_STRING);
		//	if (free_ret_header(head, line) == 1)
		//		return (1);
		//todo
		}
		free (line);
		line = NULL;
	}
	return (ft_error("Missing name or comment."));
}
