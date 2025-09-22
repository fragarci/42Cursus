/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fragarci <fragarci@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/24 15:49:13 by fragarci          #+#    #+#             */
/*   Updated: 2025/07/24 16:32:05 by fragarci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
DESCRIPTION
	Create a new node using malloc(3). The variable 'content' is initialized
	with the content of the 'content' parameter. The variable variable 'next'
	is initialized with NULL.

RETURN VALUE
	The new node
*/

#include "libft.h"

t_list	*ft_lstnew(void *content)
{
	t_list	*ret;

	ret = (t_list *)malloc(sizeof(t_list));
	if (!ret)
		return ((void *)0);
	ret -> content = content;
	ret -> next = (void *)0;
	return (ret);
}
