/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_aff.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abonneca <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/08 12:15:28 by abonneca          #+#    #+#             */
/*   Updated: 2017/03/08 18:36:13 by abonneca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

void	op_aff(t_process *proc, t_vm *vm)
{
		unsigned int i;

		(void)vm;
		i = regtou(proc->act.params[0].value);
		i %= 256;
		write(1, &i, 1);
}
