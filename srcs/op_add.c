/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_add.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abonneca <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/07 16:36:12 by abonneca          #+#    #+#             */
/*   Updated: 2017/03/07 17:04:58 by abonneca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

void	op_add(t_process *proc)
{
	unsigned int reg_a;
	unsigned int reg_b;
	unsigned int reg_res;

	reg_a = regtou(proc->act.params[0].value);
	reg_b = regtou(proc->act.params[1].value);
	reg_res = reg_a + reg_b;
	utoreg(reg_res, proc->act.params[2].value);
	proc->carry = 1;
}
