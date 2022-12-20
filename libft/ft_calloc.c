/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hcolumbu <hcolumbu@student.21-school.ru>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/06 20:41:44 by hcolumbu          #+#    #+#             */
/*   Updated: 2021/10/25 10:20:45 by hcolumbu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t count, size_t size)
{
	void	*mem;

	if (count == 0 && size == 0)
	{
		mem = malloc(1);
		if (mem == NULL)
			return (NULL);
		ft_memset(mem, 0, 1);
	}
	else
	{
		mem = malloc(count * size);
		if (mem == NULL)
			return (NULL);
		ft_memset(mem, 0, count * size);
	}
	return (mem);
}
