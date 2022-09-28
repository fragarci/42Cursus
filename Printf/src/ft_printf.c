/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fragarci <fragarci@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/28 09:23:44 by fragarci          #+#    #+#             */
/*   Updated: 2022/09/28 11:11:01 by fragarci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/printf.h"

int	ft_putchar(int c)
{
	write(1, &c, 1);
	return (1);
}

int	ft_print_formats(va_list args, const char format)
{
	int	printed_length;

	printed_length = 0;
	if (format == 'c')
		printed_length += ft_putchar(va_arg(args, int));
	else if (format == 's')
		printed_length += ft_putstrn(va_arg(args, char *));

	return (printed_length);
}

int	ft_printf(char const *str, ...)
{
	int		i;
	int		final_size;
	va_list	args;

	i = 0;
	final_size = 0;
	va_start(args, str);
	while (str[i])
	{
		if (str[i] == '%')
		{
			final_size += ft_print_formats(args, str[i + 1]);
			i++;
		}
		else
			final_size += ft_putchar(str[i]);
		i++;
	}
	va_end(args);
	return (final_size);
}
