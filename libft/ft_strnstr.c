/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hcolumbu <hcolumbu@student.21-school.ru>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/06 20:41:44 by hcolumbu          #+#    #+#             */
/*   Updated: 2021/10/22 10:25:02 by hcolumbu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	size_needle;
	char	*tmp;

	tmp = (char *)haystack;
	size_needle = ft_strlen(needle);
	if (haystack == needle)
		return (tmp);
	if (!needle)
		return (tmp);
	while (*tmp && size_needle <= len)
	{
		if (!ft_strncmp(tmp, needle, size_needle))
			return (tmp);
		len--;
		tmp++;
	}
	return (NULL);
}
