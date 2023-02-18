/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mov_push.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fragarci <fragarci@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/14 10:40:45 by fragarci          #+#    #+#             */
/*   Updated: 2023/02/14 13:12:28 by fragarci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

static int	ft_push(t_stack **stack_dest, t_stack **stack_src)
{
	t_stack	*tmp;
	t_stack	*head_dest;
	t_stack	*head_src;

	if (ft_stksize(*stack_src) == 0)
		return (-1);
	head_dest = *stack_dest;
	head_src = *stack_src;
	tmp = head_src;
	head_src = head_src->next;
	*stack_src = head_src;
	if (!head_dest)
	{
		head_dest = tmp;
		head_dest->next = NULL;
		*stack_dest = head_dest;
	}
	else
	{
		tmp->next = head_dest;
		*stack_dest = tmp;
	}
	return (0);
}

int	ft_pa(t_stack **stack_a, t_stack **stack_b)
{
	if (ft_push(stack_a, stack_b) == -1)
		return (-1);
	ft_putendl_fd("pa", 1);
	return (0);
}

int	ft_pb(t_stack **stack_a, t_stack **stack_b)
{
	if (ft_push(stack_b, stack_a) == -1)
		return (-1);
	ft_putendl_fd("pb", 1);
	return (0);
}
