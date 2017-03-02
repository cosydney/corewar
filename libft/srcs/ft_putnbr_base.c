/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amarzial <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/18 19:40:21 by amarzial          #+#    #+#             */
/*   Updated: 2016/12/07 14:09:13 by amarzial         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr_base(t_putnbr n, int base)
{
	char	*out;

	if ((out = ft_itoa_base(n, base)))
	{
		ft_putstr(out);
		free(out);
	}
}
