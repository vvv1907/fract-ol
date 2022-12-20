/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hcolumbu <hcolumbu@student.21-school.ru>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/06 20:41:44 by hcolumbu          #+#    #+#             */
/*   Updated: 2021/10/25 12:25:38 by hcolumbu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_begin(char const *a, char const *b, int i)
{
	int	index;
	int	flag;

	flag = 0;
	index = 0;
	while (b[i])
	{
		while (a[index])
		{
			if (b[i] == a[index])
				flag = 1;
			index++;
		}
		if (flag == 1)
		{
			i++;
			index = 0;
			flag = 0;
		}
		else
			break ;
	}
	return (i);
}

static int	ft_end(char const *a, char const *b, int i, int j)
{
	int	index;
	int	flag;

	flag = 0;
	index = 0;
	while (i > j)
	{
		while (a[index])
		{
			if (b[i] == a[index])
				flag = 1;
			index++;
		}
		if (flag == 1)
		{
			i--;
			index = 0;
			flag = 0;
		}
		else
			break ;
	}
	return (i);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	int		i;
	int		end;
	int		begin;
	char	*s2;

	i = 0;
	if (!s1)
		return (NULL);
	begin = ft_begin(set, s1, i);
	end = ft_end(set, s1, ft_strlen(s1) - 1, begin) + 1;
	if (end < begin)
		s2 = ft_calloc(1, sizeof(char));
	else
	{
		s2 = (char *)malloc(sizeof(char) * (end - begin + 1));
		if (s2 == NULL)
			return (NULL);
		while (begin < end)
			s2[i++] = s1[begin++];
	}
	s2[i] = '\0';
	return (s2);
}
