/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   champion.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amarzial <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/02 18:26:32 by amarzial          #+#    #+#             */
/*   Updated: 2017/03/10 13:42:25 by amarzial         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "corewar.h"

t_champion		*id_to_champion(t_list *champions, unsigned int id)
{
	while (champions)
	{
		if (((t_champion*)champions->content)->id == id)
			return ((t_champion*)champions->content);
		champions = champions->next;
	}
	return (0);
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
	while (id_to_champion(vm->players, next_id))
		next_id = (*player_n)--;
	champ.id = next_id;
	vm->last_live_id = next_id;
	if (!(tmp = ft_lstnew(&champ, sizeof(t_champion))))
		return (0);
	ft_lstadd(&(vm->players), tmp);
	return (1);
}
