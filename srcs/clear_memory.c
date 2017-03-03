/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clear_memory.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amarzial <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/02 20:02:48 by amarzial          #+#    #+#             */
/*   Updated: 2017/03/03 19:34:17 by amarzial         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "corewar.h"

static void	delete_process(void *content, size_t content_size)
{
	(void)content_size;
	free(content);
}

static void	delete_champion(void *content, size_t content_size)
{
	t_champion	*champ;

	(void)content_size;
	champ = (t_champion*)content;
	ft_lstdel(&(champ->processes), delete_process);
	free(content);
}

void		clear_vm(t_vm *vm)
{
	ft_lstdel(&(vm->players), delete_champion);
	free(vm);
}
