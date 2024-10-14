/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_push_swap.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsenniko <vsenniko@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/14 12:30:07 by vsenniko          #+#    #+#             */
/*   Updated: 2024/10/14 16:51:12 by vsenniko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PUSH_SWAP_H
# define FT_PUSH_SWAP_H

# include <unistd.h>
# include <stdarg.h>
# include <stdlib.h>

//ft_printf declaration
int		ft_printf(const char *format, ...);
int		write_str(char *str);
int		ft_putnbr_decimal(int nbr, char *base);
int		ft_putnbr_base(unsigned int nbr, char *base);
int		ft_putnbr_add(unsigned long add, char *base);

//push_swap declaration
void	check_input_and_transfer(int argc, char *argv[]);
void	exit_error(void);
int		ft_atoi(const char *str);

#endif
