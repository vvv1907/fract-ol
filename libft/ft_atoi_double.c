/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_double.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hcolumbu <hcolumbu@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/06 20:41:44 by hcolumbu          #+#    #+#             */
/*   Updated: 2022/03/09 09:18:28 by hcolumbu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static double	part_of_double(const char *str, int *i, int *divider)
{
	double	number;

	number = 0;
	while (str[*i] >= '0' && str[*i] <= '9')
	{
		number = number * 10 + (str[*i] - '0');
		(*i)++;
		*divider *= 10;
	}
	return (number);
}

double	ft_atoi_double(const char *str)
{
	double	result;
	int		divider;
	int		sign;
	int		i;

	i = 0;
	sign = 1;
	divider = 1;
	result = 0;
	while (str[i] == ' ' || str[i] == '\n' || str[i] == '\t' \
		|| str[i] == '\r' || str[i] == '\v' || str[i] == '\f')
		i++;
	if (str[i] == '-')
		sign = -1;
	if (str[i] == '+' || str[i] == '-')
		i++;
	result = part_of_double(str, &i, &divider);
	divider = 1;
	if (str[i] == '.')
		i++;
	else
		return (sign * result);
	return (sign * (result + part_of_double(str, &i, &divider) / divider));
}
