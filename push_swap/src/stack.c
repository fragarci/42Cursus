/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fragarci <fragarci@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/02 11:20:52 by fragarci          #+#    #+#             */
/*   Updated: 2022/12/06 11:58:54 by fragarci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	ft_print_stack(t_list *stack)
{
	while (stack->next)
	{
		ft_printf("%d\n", stack->content);
		stack = stack->next;
		if (!stack->next)
			ft_printf("%d\n", stack->content);
	}
}
