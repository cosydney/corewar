/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amarzial <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/26 20:10:49 by amarzial          #+#    #+#             */
/*   Updated: 2017/02/06 14:34:22 by amarzial         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>
#include "libft.h"

static void		resetbuff(t_reader *rdr)
{
	int		chunksize;
	int		fd;

	if (rdr->r_size == 0 && rdr->stop == 1)
	{
		fd = rdr->fd;
		if (rdr->buffer)
			free(rdr->buffer);
		ft_memset((void*)rdr, 0, sizeof(t_reader));
		rdr->fd = fd;
		return ;
	}
	if (!rdr->buffer)
		return ;
	if (rdr->el < rdr->buffer || rdr->el > rdr->buffer + rdr->r_size)
	{
		rdr->el = 0;
		return ;
	}
	chunksize = (rdr->buffer + rdr->r_size) - (rdr->el);
	chunksize -= (rdr->stop) ? 0 : 1;
	ft_memmove(rdr->buffer, rdr->el + 1, chunksize);
	rdr->r_size = chunksize;
}

static int		buffalloc(t_reader *rdr)
{
	char	*tmp;

	if (!(tmp = (char*)malloc(rdr->r_size + GET_LINE_BUFF_SIZE)))
		return (0);
	ft_memcpy(tmp, rdr->buffer, rdr->r_size);
	rdr->b_size = rdr->r_size + GET_LINE_BUFF_SIZE;
	ft_memdel((void**)&rdr->buffer);
	rdr->buffer = tmp;
	return (1);
}

static int		reading(const int fd, t_reader *rdr)
{
	int		cnt;

	if ((rdr->b_size - rdr->r_size) < GET_LINE_BUFF_SIZE)
		if (!buffalloc(rdr))
			return (-1);
	cnt = read(fd, rdr->buffer + rdr->r_size, GET_LINE_BUFF_SIZE);
	if (cnt == 0)
		rdr->stop = 1;
	else if (cnt < 0)
		return (-1);
	rdr->r_size += cnt;
	return (1);
}

static t_reader	*get_file_handler(int fd, t_list **multilist)
{
	t_reader		*tmp;
	t_list			*cur;

	cur = *multilist;
	while (cur)
	{
		tmp = (t_reader*)cur->content;
		if (tmp->fd == fd)
			return (tmp);
		cur = cur->next;
	}
	if (!(tmp = (t_reader*)ft_memalloc(sizeof(t_reader))))
		return (0);
	tmp->fd = fd;
	if (!(cur = ft_lstnew(tmp, sizeof(t_reader))))
		return (0);
	free(tmp);
	ft_lstadd(multilist, cur);
	return ((t_reader*)cur->content);
}

int				ft_getline(const int fd, char **line)
{
	static t_list	*multilist;
	t_reader		*rdr;
	int				res;

	if (fd < 0 || !line || !(rdr = get_file_handler(fd, &multilist)))
		return (-1);
	resetbuff(rdr);
	while (!(rdr->el = ft_memchr(rdr->buffer, '\n', rdr->r_size)) && !rdr->stop)
	{
		if ((res = reading(fd, rdr)) != 1)
			return (res);
	}
	if (rdr->stop)
	{
		if (rdr->r_size)
			rdr->el = rdr->buffer + rdr->r_size;
		else
			return (0);
	}
	if (!(*line = ft_strnew(rdr->el - rdr->buffer)))
		return (-1);
	ft_memcpy(*line, rdr->buffer, rdr->el - rdr->buffer);
	return (1);
}
