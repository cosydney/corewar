/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_or.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abonneca <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/08 11:33:29 by abonneca          #+#    #+#             */
/*   Updated: 2017/03/08 11:37:09 by abonneca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

void	op_or(t_process *proc)
{
	unsigned int i;

	i = 0;
	while (i < REG_SIZE)
	{
		proc->act.params[2].value[i] = proc->act.params[0].value[i] \
	| proc->act.params[1].value[i];
		i++;
	}
}
