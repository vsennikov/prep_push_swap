/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsenniko <vsenniko@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/18 12:58:57 by vsenniko          #+#    #+#             */
/*   Updated: 2024/10/14 12:32:42 by vsenniko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"

static int	write_char(int c)
{
	return (write(1, &c, 1));
}

int	write_str(char *str)
{
	int	i;

	i = 0;
	if (str == NULL)
		return (write(1, "(null)", 6));
	while (str[i] != '\0')
	{
		write_char((int)str[i]);
		i++;
	}
	return (i);
}

static int	choose_func(char c, va_list ap)
{
	int	j;

	j = 0;
	if (c == 'c')
		j += write_char(va_arg(ap, int));
	else if (c == 's')
		j += write_str(va_arg(ap, char *));
	else if (c == '%')
		j += write_char('%');
	else if (c == 'd' || c == 'i')
		j += ft_putnbr_decimal(va_arg(ap, int), "0123456789");
	else if (c == 'u')
		j += ft_putnbr_base(va_arg(ap, unsigned int), "0123456789");
	else if (c == 'x')
		j += ft_putnbr_base(va_arg(ap, unsigned int), "0123456789abcdef");
	else if (c == 'X')
		j += ft_putnbr_base(va_arg(ap, unsigned int), "0123456789ABCDEF");
	else if (c == 'p')
		j += ft_putnbr_add(va_arg(ap, unsigned long), "0123456789abcdef");
	else
	{
		j += write_char('%');
		j += write_char(c);
	}
	return (j);
}

int	ft_printf(const char *format, ...)
{
	va_list	ap;
	int		i;
	int		counter;

	va_start(ap, format);
	i = 0;
	counter = 0;
	if (format == NULL)
		return (-1);
	while (format[i] != '\0')
	{
		if (format[i] == '%')
			counter += choose_func(format[++i], ap);
		else
			counter += write(1, &format[i], 1);
		i++;
	}
	va_end(ap);
	return (counter);
}
