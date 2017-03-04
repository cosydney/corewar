/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initializer.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amarzial <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/04 15:00:49 by amarzial          #+#    #+#             */
/*   Updated: 2017/03/04 19:34:34 by amarzial         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "corewar.h"

void	init_processes(t_vm *vm)
{
	t_process	proc;
	t_champion	*champ;
	t_list		*players;
	t_list		*tmp;

	players = vm->players;
	while (players)
	{
		ft_bzero(&proc, sizeof(t_process));
		champ = (t_champion*)players->content;
		utoreg(champ->offset % MEM_SIZE, proc.pc);
		utoreg(champ->id, proc.registers[0]);
		if (!(tmp = ft_lstnew(&proc, sizeof(t_process))))
			error_exit(MALLOC_ERROR);
		ft_lstadd(&(champ->processes), tmp);
		vm->process_count++;
		players = players->next;
	}
}
