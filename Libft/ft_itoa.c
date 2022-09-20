/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fragarci <fragarci@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/20 12:59:14 by fragarci          #+#    #+#             */
/*   Updated: 2022/09/20 13:01:16 by fragarci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
DESCRIPTION
	Using malloc(3), it generates a string that represents the integer value
	received as argument. Negative numbers have to be handled.

RETURN VALUE
	The string representing the number. NULL if the memory reservation fails.
*/

char	*ft_itoa(int n);
