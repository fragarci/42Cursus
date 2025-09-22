/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalpha.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fragarci <fragarci@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/06 11:00:00 by fragarci          #+#    #+#             */
/*   Updated: 2025/07/24 15:42:21 by fragarci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
DESCRIPTION
	isalpha() checks for an alphabetic character; in the standard "C" locale,
	it is equivalent to (isupper(c) || islower(c)). In some locales, there may
	be additional characters for which isalpha() is true-letters which are
	neither upper case nor lower case.

RETURN VALUE
	The values returned are nonzero if the character c falls into the tested
	class, and a zero value if not.
*/

int	ft_isalpha(int c)
{
	return ((c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z'));
}
