/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_champions.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abonneca <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/03 13:52:38 by abonneca          #+#    #+#             */
/*   Updated: 2017/03/03 18:02:00 by abonneca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

static int		ft_power(int nb, int power)
{
	if (power < 0)
		return (0);
	if (power == 0)
		return (1);
	nb *= ft_power(nb, power - 1);
	return (nb);
}

static void		ft_parse_header(char *str, int fd, int length)
{
	int		i;
	char	buf;

	i = 0;
	while (i < length)
	{
		if (read(fd, &buf, 1) == -1)
			error_exit(READ_ERROR);
		str[i] = buf;
		++i;
	}
}

static void		ft_get_prog_size(t_champion *player, int fd)
{
	int		i;
	char	buf;

	i = 0;
	while (i < 8)
	{
		if (read(fd, &buf, 1) == -1)
			error_exit(READ_ERROR);
		player->header.prog_size += buf * ft_power(16, 14 - i * 2);
		++i;
	}
}

void			ft_parse_chmp(t_vm vm)
{
	t_list	*players;
	int		fd;
	int		i;

	players = vm.players;
	while (players)
	{
		i = 0;
		fd = open(((t_champion *)(players->content))->filename, O_RDONLY);
		if (fd == -1)
			error_exit(OPEN_ERROR);
		if (lseek(fd, 4, SEEK_SET) != 4)
			error_exit(LSEEK_ERROR);
		ft_parse_header(((t_champion *)(players->content))->header.prog_name\
				, fd, PROG_NAME_LENGTH);
		ft_get_prog_size(((t_champion *)(players->content)), fd);
		ft_parse_header(((t_champion *)(players->content))->header.comment\
				, fd, COMMENT_LENGTH);
		fd = close(fd);
		if (fd == -1)
			error_exit(CLOSE_ERROR);
		players = players->next;
	}
}

/*
**		ft_printf("%s\n", ((t_champion *)(players->content))->header.prog_name);
**		ft_printf("%i\n", ((t_champion *)(players->content))->header.prog_size);
**		ft_printf("%s\n", ((t_champion *)(players->content))->header.comment);
*/
