/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hcolumbu <hcolumbu@student.21-school.ru>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/06 20:41:44 by hcolumbu          #+#    #+#             */
/*   Updated: 2021/10/26 11:37:23 by hcolumbu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	ft_free_array(char **array, int count)
{
	int	i;

	i = 0;
	while (i <= count)
	{
		free(array[i]);
		i++;
	}
	free(array);
}

static int	ft_word_count(char const *s, char c)
{
	int	count;
	int	i;

	i = 0;
	count = 0;
	while (s[i])
	{
		while (s[i] == c)
			i++;
		if (s[i] != c && s[i])
			count++;
		while (s[i] != c && s[i])
			i++;
	}
	return (count);
}

static size_t	ft_word_len(char const *s, char c)
{
	size_t	len;
	int		i;

	i = 0;
	len = 0;
	while (s[i] == c)
		i++;
	while (s[i] != c && s[i])
	{
		i++;
		len++;
	}
	return (len);
}

static char	**ft_create_array(char const *s, char c, int count)
{
	char	**array;
	int		i;

	if (!s)
		return (NULL);
	i = 0;
	array = (char **)malloc(sizeof(char *) * (count + 1));
	if (array == NULL)
		return (NULL);
	while (i < count)
	{
		while (*s == c)
			s++;
		array[i] = ft_substr(s, 0, ft_word_len(s, c));
		if (array[i++] == NULL)
		{
			ft_free_array(array, count);
			return (NULL);
		}
		s = s + ft_word_len(s, c);
	}
	array[i] = NULL;
	return (array);
}

char	**ft_split(char const *s, char c)
{
	char	**split;
	int		count;

	if (!s)
		return (NULL);
	count = ft_word_count(s, c);
	split = ft_create_array(s, c, count);
	if (!split)
		return (NULL);
	return (split);
}
