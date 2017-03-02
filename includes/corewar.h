/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   corewar.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abonneca <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/02 13:39:59 by abonneca          #+#    #+#             */
/*   Updated: 2017/03/02 19:00:01 by abonneca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef COREWAR_H
# define COREWAR_H

#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
# include <libft.h>
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
	char	*name;
	char	*comment;
	int		id;
	t_list	*procs;
	size_t	procs_n;
}				t_champion;

typedef struct	s_process
{
	byte	registers[REG_NUMBER][REG_SIZE];
	byte	pc[REG_SIZE];
	int		carry:1;
	t_op	*current;
	int		cycle_count;

}				t_process;

typedef struct	s_player
{
	t_process		*process;
	struct s_player	*next;

}				t_player;

t_vm			*vm_get();
int				vm_init();

void		ft_print_mem(byte *memory, size_t size);
#endif
