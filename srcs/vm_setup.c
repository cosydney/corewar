/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vm_setup.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amarzial <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/02 16:05:31 by amarzial          #+#    #+#             */
/*   Updated: 2017/03/04 17:36:31 by amarzial         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

t_vm	*vm_get()
{
	static t_vm	*vm;

	if (!vm)
	{
		if (!(vm = (t_vm*)ft_memalloc(sizeof(t_vm))))
			return (0);
		vm->cycle_to_die = CYCLE_TO_DIE;
	}
	return (vm);
}

int		vm_init()
{
	if (vm_get())
		return (1);
	return (0);
}
