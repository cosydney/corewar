/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   corewar.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abonneca <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/02 13:39:59 by abonneca          #+#    #+#             */
/*   Updated: 2017/03/02 17:17:34 by amarzial         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef COREWAR_H
# define COREWAR_H

# include "libft.h"
# include "op.h"

typedef unsigned char byte;

typedef struct	s_op
{
	char		*mnemonic;
	char		arg_c;
	t_arg_type	ar[3];
	byte		opcode;
	size_t		cycles;
	char		*full_mess;
	char		reg:1;
	char		index:1;
}				t_op;

typedef	struct	s_vm
{
	byte	memory[MEM_SIZE];
	t_list	*players;
	int		cycle;
}				t_vm;

struct			s_champion
{
	char			*name;
	char			*comment;
	unsigned int	id;
	int				fd;
	t_list			*processes;
	size_t			process_n;
}				t_champion;

typedef struct	s_process
{
	byte	registers[REG_NUMBER][REG_SIZE];
	byte	pc[REG_SIZE];
	int		carry:1;
	t_op	*current;
	int		cycle_count;
}				t_process;

t_vm			*vm_get()
int				*vm_init()

#endif
