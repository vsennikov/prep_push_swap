/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_input.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsenniko <vsenniko@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/14 12:47:40 by vsenniko          #+#    #+#             */
/*   Updated: 2024/10/14 16:50:37 by vsenniko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"

void	exit_error(void)
{
	write(2, "Error\n", 6);
	exit(1);
}

static void	is_invalid(char *str)
{
	int		i;

	i = 0;
	if (str[i] == '\0')
		exit_error();
	while (str[i])
	{
		if (str[i] >= 'A' && str[i] <= 'Z')
			exit_error();
		else if (str[i] >= 'a' && str[i] <= 'z')
			exit_error();
		else if ((str[i] >= '\t' && str[i] <= '\r') || str[i] == ' ')
			exit_error();
		i++;
	}
}

void	check_input_and_transfer(int argc, char *argv[])
{
	int		i;

	i = 1;
	if (argc < 2)
		exit_error();
	while (i != argc)
		is_invalid(argv[i++]);
	
}
