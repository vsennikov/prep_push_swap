/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsenniko <vsenniko@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/14 13:08:36 by vsenniko          #+#    #+#             */
/*   Updated: 2024/10/15 14:46:58 by vsenniko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"

static int	ft_isspace(char ch)
{
	if ((ch >= '\t' && ch <= '\r') || ch == ' ')
		return (1);
	return (0);
}

long	ft_atoi(const char *str)
{
	int		i;
	int		minus;
	long	result;

	i = 0;
	minus = 0;
	result = 0;
	while (ft_isspace(str[i]))
		i++;
	if (str[i] == '-')
	{
		minus = 1;
		i++;
	}
	else if (str[i] == '+')
		i++;
	while (str[i] >= '0' && str[i] <= '9')
	{
		result = result * 10 + str[i] - '0';
		i++;
	}
	if (minus)
		result *= -1;
	return (result);
}
