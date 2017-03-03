/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   champion.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amarzial <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/02 18:26:32 by amarzial          #+#    #+#             */
/*   Updated: 2017/03/03 12:16:09 by amarzial         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "corewar.h"

static int		check_id(t_list *champions, unsigned int id)
{
	while (champions)
	{
		if (((t_champion*)champions->content)->id == id)
			return (0);
		champions = champions->next;
	}
	return (1);
}

int				create_champion(t_vm *vm, char *str, unsigned int *custom_nbr, \
		unsigned int *player_n)
{
	t_champion		champ;
	t_list			*tmp;
	unsigned int	next_id;

	if (vm->player_count >= MAX_PLAYERS)
		error_exit(TOO_MANY_PLAYERS);
	vm->player_count++;
	ft_bzero(&champ, sizeof(t_champion));
	champ.filename = str;
	if (custom_nbr[1] == 0)
		next_id = (*player_n)--;
	else
		next_id = custom_nbr[0];
	while (!check_id(vm->players, next_id))
		next_id = (*player_n)--;
	champ.id = next_id;
	if (!(tmp = ft_lstnew(&champ, sizeof(t_champion))))
		return (0);
	ft_lstadd(&(vm->players), tmp);
	return (1);
}
