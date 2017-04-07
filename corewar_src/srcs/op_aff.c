/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_aff.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abonneca <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/08 12:15:28 by abonneca          #+#    #+#             */
/*   Updated: 2017/04/05 16:55:13 by amarzial         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

void	op_aff(t_process *proc, t_vm *vm)
{
	unsigned int i[2];

	if (vm->opt.dump || vm->opt.gui)
		return ;
	i[1] = REG_SIZE;
	if (!par_to_val(0, i, proc, vm))
		return ;
	i[0] %= 256;
	write(1, i, 1);
}
