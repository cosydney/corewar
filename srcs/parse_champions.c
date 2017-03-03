/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_champions.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abonneca <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/03 13:52:38 by abonneca          #+#    #+#             */
/*   Updated: 2017/03/03 19:33:28 by amarzial         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

static int		ft_parse_header(char *str, int fd, int length)
{
	int		i;
	char	buf;

	i = 0;
	while (i < length)
	{
		if (read(fd, &buf, 1) == -1)
			return (0);
		str[i] = buf;
		++i;
	}
	return (1);
}

static int		ft_get_prog_size(t_champion *player, int fd)
{
	int				i;
	unsigned char	buf;

	i = 0;
	while (i < sizeof(player->header.prog_size))
	{
		if (read(fd, &buf, 1) == -1)
			return (0);
		player->header.prog_size = player->header.prog_size << 8;
		player->header.prog_size += buf;
		++i;
	}
	return (1);
}

static int		check_magic(int fd, unsigned int magic_n)
{
	unsigned char	buff;
	unsigned int	nbr;
	int				i;

	nbr = 0;
	while (i < sizeof(nbr))
	{
		if (read(fd, &buff, 1) != 1)
			return (0);
		nbr == nbr << 8;
		nbr += buff;
		++i;
	}
	if (nbr != magic_n)
		return (0);
	return (1);
}

void			ft_parse_champion(t_vm *vm)
{
	t_list		*players;
	t_champion	*champ;
	int			fd;
	int			i;

	players = vm->players;
	while (players)
	{
		champ = (t_champion*)players->content;
		if ((fd = open(champ->filename, O_RDONLY)) == -1)
			error_exit(OPEN_ERROR);
		if (!check_magic(fd, COREWAR_EXEC_MAGIC))
			error_exit(INVALID_FILE);
		if (!ft_parse_header(champ->header.prog_name, fd, PROG_NAME_LENGTH) || \
		!ft_get_prog_size(champ, fd) || \
		!ft_parse_header(champ->header.comment, fd, COMMENT_LENGTH))
			error_exit(INVALID_FILE);
		if ((fd = close(fd)) == -1)
			error_exit(CLOSE_ERROR);
		players = players->next;
	}
}
