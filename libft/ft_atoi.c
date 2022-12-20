/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hcolumbu <hcolumbu@student.21-school.ru>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/06 20:41:44 by hcolumbu          #+#    #+#             */
/*   Updated: 2021/10/22 10:57:16 by hcolumbu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_atoi(const char	*str)
{
	unsigned long long int	result;
	long long int			sign;
	int						i;

	i = 0;
	sign = 1;
	result = 0;
	while (str[i] == ' ' || str[i] == '\n' || str[i] == '\t' \
		|| str[i] == '\r' || str[i] == '\v' || str[i] == '\f')
		i++;
	if (str[i] == '-')
		sign = -1;
	if (str[i] == '+' || str[i] == '-')
		i++;
	while (str[i] >= '0' && str[i] <= '9')
	{
		if (result > 9223372036854775807 && sign != -1)
			return (-1);
		if (result > 9223372036854775807 && sign == -1)
			return (0);
		result = result * 10 + (str[i] - '0');
		i++;
	}
	return (result * sign);
}
