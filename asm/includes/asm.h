/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   asm.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sycohen <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/03 18:22:17 by sycohen           #+#    #+#             */
/*   Updated: 2017/03/28 11:04:17 by sycohen          ###   ########.fr       */
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

# define REG_NUMBER					16
# define LABEL_CHARS				"abcdefghijklmnopqrstuvwxyz_0123456789"

# define T_REG						1
# define T_DIR						2
# define T_IND						2

# define FORMAT_ERROR				1
# define COMMENT_ERROR				2
# define LABELS_ERROR				3
# define LABEL_CHAR_ERROR			4
# define INSTRUCT_ERROR				5
# define MALLOC_ERROR				6
# define INDIRECT_ERROR				7
# define ARGS_ERROR					8
# define LABELS_DOUBLE_ERROR		9
# define LABEL_MATCH_ERROR			10
# define NAME_ERROR					11
# define ARG_ERROR					12
# define LINES_ERROR				13
# define FILE_ERROR					14
# define LABEL_ERROR				15
# define REG_ERROR					16
# define CHAMPION_ERROR				17

# define LIVE						1
# define LD							2
# define ST							3
# define ADD						4
# define SUB						5
# define AND						6
# define OR							7
# define XOR						8
# define ZJMP						9
# define LDI						10
# define STI						11
# define FORK						12
# define LLD						13
# define LLDI						14
# define LFORK						15
# define AFF						16

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

int					parsing(char *champion, t_header *head, int check);
int					name_comment_handler(int fd, t_header *head);
int					check_header(t_header *head, char *line);
int					check_label(char *str);
t_label				*label_init(t_label *label, char *line);
int					check_valid_line(char *line);
int					asm_instruct_name(char *line);
char				*asm_free_join(char *line, char *file);
int					asm_error(int error);
int					check_arg(char **line, int op);
int					check_direct(char **line, int op, int check);
int					check_register(char **line, int check);
int					check_indirect(char **line, int check);
int					check_double_label(t_label *label);
int					check_label_exist(t_label *label, char *str);
int					reader(t_label *label,
	t_header *header, char *champ, char *file);
int					free_label(t_label *label);
int					binary_creator(int fd, t_label *label, char *file);
int					write_register(int fd, char **file);
int					write_direct(int fd, int size, t_label *label, char **file);
int					write_indirect(int fd, t_label *label, char **file);
int					move_separator(char **file);
int					calculate_i(char *file, t_label *label);
int					cw_invert_endian(int x);
int					cw_invert_endian2(int x);
int					move_i(int i, char *file);
int					opcode(int fd, int arg, int i, char *file);

#endif
