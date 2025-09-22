/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isascii.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fragarci <fragarci@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/06 11:00:21 by fragarci          #+#    #+#             */
/*   Updated: 2025/07/24 15:42:35 by fragarci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
DESCRIPTION
	isascii() checks whether c is a 7-bit unsigned char value that fits into
	the ASCII character set.

RETURN VALUE
	The values returned are nonzero if the character c falls into the tested
	class, and a zero value if not.
*/

int	ft_isascii(int c)
{
	return (c >= 0 && c <= 127);
}
