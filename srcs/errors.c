/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amarzial <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/10 15:22:06 by amarzial          #+#    #+#             */
/*   Updated: 2017/03/03 19:02:12 by amarzial         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "corewar.h"

static char	*g_errors[10] =
{
	[0] = "Program stopped by user",
	[GENERIC_ERROR] = "Error",
	[ARG_ERROR] = "Error: invalid argument",
	[MALLOC_ERROR] = "Error: cannot allocate memory",
	[TOO_MANY_PLAYERS] = "Error: too many players specified",
	[OPEN_ERROR] = "Error: Open() failed",
	[CLOSE_ERROR] = "Error: Close() failed",
	[READ_ERROR] = "Error: Read() failed",
	[LSEEK_ERROR] = "Error: Lseek() failed",
	[INVALID_FILE] = "Error: the file is not valid"
};

void	error_exit(int code)
{
	t_vm	*vm;

	if ((vm = vm_get()))
		clear_vm(vm);
	ft_printf_fd(2, "%s\n", g_errors[code]);
	exit(code);
}
