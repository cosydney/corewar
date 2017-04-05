/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sycohen <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/03 18:19:45 by sycohen           #+#    #+#             */
/*   Updated: 2017/03/14 12:33:12 by sycohen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

t_header	*header_init(void)
{
	t_header *new;

	if (!(new = (t_header*)malloc(sizeof(t_header))))
		return (NULL);
	if (new != NULL)
	{
		new->magic = COREWARE_EXEC_MAGIC;
		new->prog_size = 0;
		ft_bzero(new->prog_name, PROG_NAME_LENGTH);
		ft_bzero(new->comment, COMMENT_LENGTH);
	}
	return (new);
}

static void	init_global(void)
{
	g_line = 0;
	g_pos = 0;
	g_temp = 0;
}

static int	ac_check(int ac)
{
	if (ac == 2)
		asm_error(CHAMPION_ERROR);
	return (1);
}

int			main(int ac, char **av)
{
	t_header	*head;
	int			index;
	int			check;

	index = 1;
	check = 0;
	head = NULL;
	init_global();
	if (ac > 1)
	{
		if (av[index][0] == '-' && av[index][1] == 'n' && ++index)
			check = ac_check(ac);
		while (index < ac)
		{
			if ((head = header_init()) == NULL)
				return (asm_error(MALLOC_ERROR));
			if (parsing(av[index++], head, check) == -1)
				return (asm_error(CHAMPION_ERROR));
			free(head);
			head = NULL;
			init_global();
		}
	}
	else
		return (asm_error(CHAMPION_ERROR));
}
