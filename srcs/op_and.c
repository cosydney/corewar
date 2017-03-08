/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_and.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abonneca <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/08 11:17:53 by abonneca          #+#    #+#             */
/*   Updated: 2017/03/08 15:35:07 by amarzial         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

void	op_and(t_process *proc, t_vm *vm)
{
	unsigned int i;

	(void)vm;
	i = 0;
	while (i < REG_SIZE)
	{
		proc->act.params[2].value[i] = proc->act.params[0].value[i] \
	& proc->act.params[1].value[i];
		i++;
	}
}
