/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   killer.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amarzial <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/04 17:55:11 by amarzial          #+#    #+#             */
/*   Updated: 2017/03/04 19:54:55 by amarzial         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "corewar.h"

static t_list	*delete_node(t_list **prev, t_list *node)
{
	t_list	*tmp;

	tmp = node;
	node = node->next;
	ft_lstdelone(&tmp, delete_process);
	if (prev && *prev)
		*prev = node;
	return (node);
}

static void		remove_if_dead(t_list **procs, t_vm *vm)
{
	t_process	*process;
	t_list		*tmp;

	while (*procs)
	{
		process = (t_process*)(*procs)->content;
		if (!process->live_count && (vm->process_count--))
			*procs = delete_node(0, *procs);
		else if (!(process->live_count = 0))
			break ;
	}
	tmp = *procs;
	while (tmp && tmp->next)
	{
		process = (t_process*)tmp->next->content;
		if (!process->live_count && (vm->process_count--))
			delete_node(&tmp, tmp->next);
		else if (!(process->live_count = 0))
			tmp = tmp->next;
	}
}

void	kill_processes(t_vm *vm)
{
	t_champion	*champ;
	t_list		*players;

	players = vm->players;
	while (players)
	{
		champ = (t_champion*)players->content;
		remove_if_dead(&(champ->processes), vm);
		players = players->next;
	}
}
