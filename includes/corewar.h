/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem_in.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abonneca <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/05 14:43:26 by abonneca          #+#    #+#             */
/*   Updated: 2017/03/02 11:40:50 by abonneca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef COREWAR_H
# define COREWAR_H

# include <libft.h>
# include <op.h>

typedef unsigned char byte;

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

#endif
