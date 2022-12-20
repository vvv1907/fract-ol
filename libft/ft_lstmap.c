/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hcolumbu <hcolumbu@student.21-school.ru>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/06 20:41:44 by hcolumbu          #+#    #+#             */
/*   Updated: 2021/10/27 10:33:15 by hcolumbu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*tmp;
	t_list	*element;

	if (lst)
	{
		tmp = NULL;
		while (lst && f)
		{
			element = ft_lstnew(f(lst->content));
			if (!element)
			{
				ft_lstclear(&tmp, del);
				return (NULL);
			}
			ft_lstadd_back(&tmp, element);
			lst = lst->next;
		}
		return (tmp);
	}
	return (NULL);
}
