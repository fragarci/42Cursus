/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fragarci <fragarci@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/20 12:55:27 by fragarci          #+#    #+#             */
/*   Updated: 2022/09/23 16:17:11 by fragarci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
DESCRIPTION
	Reserves (using malloc(3)) an array of strings resulting from separating
	the string 's' in substrings using the character 'c' as delimiter. The
	array must end with a NULL pointer.

RETURN VALUE
	The array of new strings resulting from the separation. NULL if the
	memory reservation fails.
*/

char	**ft_split(char const *s, char c)
{
	if (s && c)
		return (0);
	return (0);
}
