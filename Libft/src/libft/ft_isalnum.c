/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalnum.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fragarci <fragarci@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/06 10:59:39 by fragarci          #+#    #+#             */
/*   Updated: 2025/07/24 15:42:11 by fragarci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
DESCRIPTION
	isalnum() checks for an alphanumeric character; it is equivalent to
	(isalpha(c) || isdigit(c)).

RETURN VALUE
	The values returned are nonzero if the character c falls into the tested
	class, and a zero value if not.
*/

int	ft_isalnum(int c)
{
	return ((c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z')
		|| (c >= '0' && c <= '9'));
}
