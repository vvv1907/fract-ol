/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hcolumbu <hcolumbu@student.21-school.ru>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/06 20:41:44 by hcolumbu          #+#    #+#             */
/*   Updated: 2021/10/25 10:13:14 by hcolumbu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	len1;
	size_t	len2;

	len1 = ft_strlen(dst);
	len2 = ft_strlen(src);
	if (dstsize <= len1)
		return (dstsize + len2);
	if (len2 < dstsize - len1)
		ft_memcpy(dst + len1, src, len2 + 1);
	else
	{
		ft_memcpy(dst + len1, src, dstsize - 1 - len1);
		dst[dstsize - 1] = '\0';
	}
	return (len1 + len2);
}
