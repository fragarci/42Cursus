/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fragarci <fragarci@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/05 12:20:14 by fragarci          #+#    #+#             */
/*   Updated: 2025/07/05 12:20:54 by fragarci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
DESCRIPTION
	Send the number 'n' to the given file descriptor.
*/

#include "libft.h"

static void	ft_printnbr_fd(int n, int fd)
{
	int		mod;
	char	c;

	if (n != 0)
	{
		mod = n % 10;
		if (mod < 0)
			mod = -mod;
		n = n / 10;
		ft_printnbr_fd(n, fd);
		c = mod + '0';
		ft_putchar_fd(c, fd);
	}
}

void	ft_putnbr_fd(int n, int fd)
{
	if (n == 0)
		ft_putchar_fd('0', fd);
	else if (n < 0)
		ft_putchar_fd('-', fd);
	ft_printnbr_fd(n, fd);
}
