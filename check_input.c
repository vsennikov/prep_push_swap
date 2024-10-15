/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_input.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsenniko <vsenniko@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/14 12:47:40 by vsenniko          #+#    #+#             */
/*   Updated: 2024/10/15 14:55:27 by vsenniko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"

static void	exit_error(void)
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

static int	*put_numbers(int argc, char *input[])
{
	int		i;
	long	temp;
	int		*arr;

	arr = malloc((argc - 1) * sizeof(int));
	if (arr == NULL)
		exit_error();
	i = 1;
	while (i != argc)
	{
		temp = ft_atoi(input[i]);
		if (temp > 2147483647 || temp < -2147483648)
		{
			free(arr);
			exit_error();
		}
		arr[i - 1] = (int)temp;
		i++;
	}
	return (arr);
}

static void	check_duplicates(int *arr, int lenghts)
{
	int	i;
	int	j;

	i = 0;
	while (i != lenghts)
	{
		j = 0;
		while (j != lenghts)
		{
			if (arr[i] == arr[j] && i != j)
			{
				free(arr);
				exit_error();
			}
			j++;
		}
		i++;
	}
}

int	*check_input_and_transfer(int argc, char *argv[])
{
	int		i;
	int		*arr;

	i = 1;
	if (argc < 2)
		exit_error();
	while (i != argc)
		is_invalid(argv[i++]);

	arr = put_numbers(argc, argv);
	check_duplicates(arr, argc - i);
	return (arr);
}
