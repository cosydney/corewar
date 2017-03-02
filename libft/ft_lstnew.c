/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abonneca <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/05 11:49:17 by abonneca          #+#    #+#             */
/*   Updated: 2016/11/06 15:46:10 by abonneca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew(void const *content, size_t content_size)
{
	t_list *my_list;

	if (!(my_list = ft_memalloc(sizeof(t_list))))
		return (NULL);
	if (!(my_list->content = (void *)malloc(sizeof(content_size))))
		my_list->content = NULL;
	if (!content)
		my_list->content = NULL;
	if (content)
	{
		ft_memcpy(my_list->content, content, content_size);
		my_list->content_size = content_size;
	}
	return (my_list);
}
