/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sycohen <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/03 19:50:25 by sycohen           #+#    #+#             */
/*   Updated: 2017/03/03 21:08:28 by sycohen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

static int		asm_check_champ(char *champ)
{
	int i;

	i = ft_strlen(champ[i]);
	if (i > 3 && champ[i - 1] == 's' && champ[i - 2] == '.')
		return (1);
	else
		(ft_error("Wrong file extension."));
}

int				parsing(char *champion, t_header *head, int check)
{
	int		fd;
	int		pos;
	char	*file;
	t_label	*label;

	pos = 0;
	label = NULL;
	file = NULL;
	check_champ_name(champion);
	if ((fd = open(champion, O_RDONLY, 0555)) == -1)
		return (-1);
	name_comment_handler(fd, head);
	//todo rest of the parsing 
}
