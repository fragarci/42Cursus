/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isdigit.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fragarci <fragarci@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/06 11:31:22 by fragarci          #+#    #+#             */
/*   Updated: 2025/07/06 11:31:25 by fragarci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
DESCRIPTION
	isdigit() checks for a digit (0 through 9).

RETURN VALUE
	The values returned are nonzero if the character c falls into the tested
	class, and a zero value if not.
*/

int	ft_isdigit(int c)
{
	return (c >= '0' && c <= '9');
}
