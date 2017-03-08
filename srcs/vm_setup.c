/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vm_setup.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amarzial <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/02 16:05:31 by amarzial          #+#    #+#             */
/*   Updated: 2017/03/08 11:40:27 by abonneca         ###   ########.fr       */
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
	}
	return (vm);
}

int		vm_init(void)
{
	if (vm_get())
		return (1);
	return (0);
}
