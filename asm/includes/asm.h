/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   asm.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sycohen <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/03 18:22:17 by sycohen           #+#    #+#             */
/*   Updated: 2017/03/03 21:18:24 by sycohen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ASM_H
# define ASM_H

# include <unistd.h>
# include "libft.h"

# define PROG_NAME_LENGTH			(128)
# define COMMENT_LENGTH				(2048)
# define COREWARE_EXEC_MAGIC		0xea83f3

# define NAME_CMD_STRING			".name"
# define COMMENT_CMD_STRING			".comment"

# define COMMENT_CHAR				'#'
# define LABEL_CHAR					':'
# define DIRECT_CHAR				'%'
# define SEPARATOR_CHAR				','


int					g_line;
int					g_pos;
int					g_temp;

typedef struct		s_header
{
	unsigned int	magic;
	char			prog_name[PROG_NAME_LENGTH + 1];
	unsigned int	prog_size;
	char			comment[COMMENT_LENGTH + 1];
}					t_header;

typedef struct		s_label
{
	char			*name;
	unsigned int	pos;
	struct s_label	*next;
}					t_label;

int			parsing(char *champion, t_header *head, int check);

#endif
