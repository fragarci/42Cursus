/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fragarci <fragarci@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/15 17:25:06 by fragarci          #+#    #+#             */
/*   Updated: 2022/09/15 17:25:06 by fragarci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
DESCRIPTION
	Send the string 's' to the specified file descriptor.
*/

#include "libft.h"

void	ft_putstr_ft(char const *s, int fd)
{
	while (*s)
		write(fd, s++, 1);
}
