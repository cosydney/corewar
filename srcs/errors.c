/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amarzial <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/10 15:22:06 by amarzial          #+#    #+#             */
/*   Updated: 2017/03/02 20:11:12 by amarzial         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "corewar.h"

static char	*g_errors[4] =
{
	[0] = "Unknown error",
	[GENERIC_ERROR] = "Error",
	[ARG_ERROR] = "Error: can't read the file",
	[MALLOC_ERROR] = "Error: cannot allocate memory"
};

void	error_exit(int code)
{
	t_vm	*vm;

	ft_printf_fd(2, "%s\n", g_errors[code]);
	if ((vm = vm_get()))
		clear_vm(vm);
	exit(code);
}
