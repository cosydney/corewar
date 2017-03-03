/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clear_memory.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amarzial <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/02 20:02:48 by amarzial          #+#    #+#             */
/*   Updated: 2017/03/03 15:19:50 by abonneca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "corewar.h"

void		clear_processes(t_list *proc_lst)
{
	(void) proc_lst;
}

static void	delete_node(void *content, size_t content_size)
{
	t_champion	*champ;

	(void)content_size;
	champ = (t_champion*)content;
	free(champ->header.prog_name);
	free(champ->header.comment);
	clear_processes(champ->processes);
	free(content);
}

void		clear_vm(t_vm *vm)
{
	ft_lstdel(&(vm->players), delete_node);
}
