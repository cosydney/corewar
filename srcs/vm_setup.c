/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vm_setup.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amarzial <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/02 16:05:31 by amarzial          #+#    #+#             */
/*   Updated: 2017/04/05 16:27:18 by amarzial         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

t_vm	*vm_get(void)
{
	static t_vm	*vm;

	if (!vm)
	{
		if (!(vm = (t_vm*)ft_memalloc(sizeof(t_vm))))
			return (0);
		vm->cycle_to_die = CYCLE_TO_DIE;
		vm->gui.speed = UI_SPEED;
		vm->gui.curbuf[0] = vm->gui.cursors[0];
		vm->gui.curbuf[1] = vm->gui.cursors[1];
	}
	return (vm);
}
