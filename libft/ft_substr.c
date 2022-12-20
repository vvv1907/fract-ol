/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hcolumbu <hcolumbu@student.21-school.ru>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/06 20:41:44 by hcolumbu          #+#    #+#             */
/*   Updated: 2021/10/25 12:00:25 by hcolumbu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*tmp;
	size_t	size;

	if (s)
	{
		size = ft_strlen(s);
		if (start > size)
			return (ft_calloc(1, sizeof(char)));
		if (len <= (size - start))
		{
			tmp = ft_calloc(len + 1, sizeof(char));
			if (tmp)
				return (ft_memcpy(tmp, s + start, len));
		}
		else
		{	
			tmp = ft_calloc(size - start + 1, sizeof(char));
			if (tmp)
				return (ft_memcpy(tmp, s + start, size - start));
		}
	}
	return (NULL);
}
