/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   asm_error.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sycohen <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/06 15:24:30 by sycohen           #+#    #+#             */
/*   Updated: 2017/03/08 14:15:39 by sycohen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

int		asm_error_sec(int error)
{
	if (error == NAME_ERROR)
		ft_printf_fd(2, "Impossible to find name or comment\n");
	if (error == ARG_ERROR)
		ft_printf_fd(2, "Argument error for instruction -> line %d\n", g_line);
	if (error == LINES_ERROR)
		ft_printf_fd(2, "Error multiple lines on name or comment\n");
	if (error == FILE_ERROR)
		ft_printf_fd(2, "Wrong file extension\n");
	if (error == LABEL_ERROR)
		ft_printf_fd(2, "Label Char error\n");
	if (error == MALLOC_ERROR)
		ft_printf_fd(2, "Malloc probs");
	if (error == REG_ERROR)
		ft_printf_fd(2, "Register troubles -> line: %d\n", g_line);
	if (error == CHAMPION_ERROR)
		ft_printf_fd(2, "Usage: champion.s\n");
	exit(0);
	return (0);
}

int		asm_error(int error)
{
	if (error == FORMAT_ERROR)
		ft_printf_fd(2, "wrong format name -> line: %d\n", g_line);
	if (error == COMMENT_ERROR)
		ft_printf_fd(2, "wrong format comment -> line: %d\n", g_line);
	if (error == LABELS_ERROR)
		ft_printf_fd(2, "wrong labels_char -> line: %d\n", g_line);
	if (error == LABEL_CHAR_ERROR)
		ft_printf_fd(2, "wrong format name -> line: %d\n", g_line);
	if (error == INSTRUCT_ERROR)
		ft_printf_fd(2, "Wrong name of instruct -> line: %d\n", g_line);
	if (error == INDIRECT_ERROR)
		ft_printf_fd(2, "not an indirect -> line: %d\n", g_line);
	if (error == ARGS_ERROR)
		ft_printf_fd(2, "Arguments problems -> line: %d\n", g_line);
	if (error == LABELS_DOUBLE_ERROR)
		ft_printf_fd(2, "Label double -> line: %d\n", g_line);
	if (error == LABEL_MATCH_ERROR)
		ft_printf_fd(2, "Label doesn't match -> line: %d\n", g_line);
	return (asm_error_sec(error));
}
