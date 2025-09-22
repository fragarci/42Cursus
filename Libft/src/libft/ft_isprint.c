/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isprint.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fragarci <fragarci@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/06 11:31:43 by fragarci          #+#    #+#             */
/*   Updated: 2025/07/24 15:42:47 by fragarci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
DESCRIPTION
	isprint() checks for any printable character including space.

RETURN VALUE
	The values returned are nonzero if the character c falls into the tested
	class, and a zero value if not.
*/

int	ft_isprint(int c)
{
	return (c >= 32 && c <= 126);
}
