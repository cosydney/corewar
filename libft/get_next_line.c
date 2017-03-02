/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abonneca <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/13 11:34:54 by abonneca          #+#    #+#             */
/*   Updated: 2016/12/20 17:29:26 by abonneca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static t_list		*ft_find_file(const int fd, t_list **files)
{
	t_list	*file;

	file = *files;
	if (files)
	{
		while (file)
		{
			if (file->content_size == (size_t)fd)
				return (file);
			file = file->next;
		}
	}
	file = ft_lstnew("\0", 1);
	file->content_size = fd;
	ft_lstadd(files, file);
	return (file);
}

static	char		*ft_join_buff_content(char *prev, char *buff, int r)
{
	char *new;

	new = ft_strnew(ft_strlen(prev) + r + 1);
	new = ft_memcpy(new, prev, ft_strlen(prev) + r + 1);
	ft_strlcat(new, buff, r + ft_strlen(new) + 1);
	free(prev);
	return (new);
}

int					get_next_line(const int fd, char **line)
{
	static t_list	*files = NULL;
	t_list			*first_file;
	int				r;
	char			*remaining;
	char			buff[BUFF_SIZE + 1];

	ft_bzero(buff, BUFF_SIZE + 1);
	if (fd < 0 || !line || read(fd, buff, 0) < 0)
		return (-1);
	first_file = files;
	files = ft_find_file(fd, &first_file);
	while (!(ft_strchr(files->content, '\n')) &&
			(r = read(fd, buff, BUFF_SIZE)))
		files->content = ft_join_buff_content(files->content, buff, r);
	r = 0;
	while (((char *)files->content)[r] && ((char *)files->content)[r] != '\n')
		++r;
	*line = ft_strnew(r);
	*line = ft_memcpy(*line, files->content, r);
	remaining = files->content;
	(((char *)files->content)[r] == '\n' ? ++r : 0);
	files->content = ft_strdup(remaining + r);
	free(remaining);
	files = first_file;
	return (r ? 1 : 0);
}
