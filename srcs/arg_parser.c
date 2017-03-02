/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arg_parser.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amarzial <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/02 17:03:24 by amarzial          #+#    #+#             */
/*   Updated: 2017/03/02 19:28:51 by amarzial         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "corewar.h"
#include <limits.h>

static int	get_opts(int argc, char **argv, t_options *opt)
{
	int		i;
	int		count;

	i = 1;
	count = 0;
	while (i < argc)
	{
		if (ft_strequ(argv[i], "-dump"))
		{
			if (opt->dump || !((i + 1) < argc) || \
					!ft_strtoi(&(opt->dump_cycles), argv[i + 1]))
				exit (ARG_ERROR);
			opt->dump = 1;
			i++;
			count += 2;
		}
		else
			break ;
		i++;
	}
	return (count);
}

int			parse_args(int argc, char **argv, t_vm *vm, t_options *opt)
{
	int				i;
	unsigned int	player_n;
	unsigned int	custom_nbr[2];

	i = get_opts(argc, argv, opt) + 1;
	player_n = UINT_MAX;
	while (i < argc)
	{
		custom_nbr[1] = 0;
		if (ft_strequ(argv[i], "-n"))
		{
			if (!((i + 2) < argc) || !ft_strtou(custom_nbr, argv[i + 1]))
				exit(ARG_ERROR);
			custom_nbr[1] = 1;
			i+=2;
		}
		if (!create_champion(vm, argv[i], custom_nbr, &player_n))
			exit(MALLOC_ERROR);
		i++;
	}
	return (1);
}
