/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reader.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sycohen <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/07 16:05:37 by sycohen           #+#    #+#             */
/*   Updated: 2017/03/14 14:53:42 by sycohen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

int		cw_invert_endian(int x)
{
	x = ((x >> 24) & 0xff) | ((x >> 8) & 0xff00) | ((x << 8) & 0xff0000) |
	((x << 24) & 0xff000000);
	return (x);
}

int		cw_invert_endian2(int x)
{
	x = ((x >> 8) & 0xff) | ((x << 8) & 0xff00);
	return (x);
}

int		header_creator(int fd, t_header *header)
{
	int	i;

	i = 0;
	header->magic = cw_invert_endian(header->magic);
	write(fd, &header->magic, 4);
	while (header->prog_name[i])
		write(fd, &header->prog_name[i++], 1);
	while (i++ < PROG_NAME_LENGTH)
		write(fd, "\0", 1);
	g_pos = cw_invert_endian(g_pos);
	write(fd, "\0\0\0\0", 4);
	write(fd, &g_pos, 4);
	i = 0;
	while (header->comment[i])
		write(fd, &header->comment[i++], 1);
	while (i++ < COMMENT_LENGTH + 4)
		write(fd, "\0", 1);
	return (1);
}

char	*morph_cor(char *champ)
{
	char	*str;
	int		i;

	i = 0;
	if (!(str = malloc(sizeof(char*) * (ft_strlen(champ) + 3))))
		return (NULL);
	while (champ[i])
	{
		str[i] = champ[i];
		i++;
	}
	str[i - 1] = 'c';
	str[i] = 'o';
	str[++i] = 'r';
	str[++i] = '\0';
	return (str);
}

int		reader(t_label *label, t_header *header, char *champ, char *file)
{
	int		fd;
	char	*file_name;

	fd = 0;
	file_name = morph_cor(champ);
	if ((fd = open(file_name, O_RDWR | O_CREAT | O_TRUNC |
		O_APPEND, 0777)) > -1)
	{
		header_creator(fd, header);
		g_pos = 0;
		binary_creator(fd, label, file);
	}
	ft_printf("Writing output program OK\n");
	free(file_name);
	close(fd);
	return (1);
}
