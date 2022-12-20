/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hcolumbu <hcolumbu@student.21-school.ru>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/06 20:41:44 by hcolumbu          #+#    #+#             */
/*   Updated: 2021/10/25 10:24:59 by hcolumbu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	size_t	i;
	size_t	len;
	char	*ptr;

	i = 0;
	len = ft_strlen(s);
	ptr = (char *)s;
	if (c == 0)
		return (&ptr[len]);
	while (ptr[i])
	{
		if (ptr[i] == (unsigned char)c)
			return (&ptr[i]);
		i++;
	}
	return (NULL);
}
