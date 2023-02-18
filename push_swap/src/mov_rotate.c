/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mov_rotate.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fragarci <fragarci@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/14 10:49:20 by fragarci          #+#    #+#             */
/*   Updated: 2023/02/14 13:13:13 by fragarci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

static int	ft_rotate(t_stack **stack)
{
	t_stack	*head;
	t_stack	*tail;

	if (ft_stksize(*stack) < 2)
		return (-1);
	head = *stack;
	tail = ft_stklast(head);
	*stack = head->next;
	head->next = NULL;
	tail->next = head;
	return (0);
}

int	ft_ra(t_stack **stack_a)
{
	if (ft_rotate(stack_a) == -1)
		return (-1);
	ft_putendl_fd("ra", 1);
	return (0);
}

int	ft_rb(t_stack **stack_b)
{
	if (ft_rotate(stack_b) == -1)
		return (-1);
	ft_putendl_fd("rb", 1);
	return (0);
}

int	ft_rr(t_stack **stack_a, t_stack **stack_b)
{
	if ((ft_stksize(*stack_a) < 2) || (ft_stksize(*stack_b) < 2))
		return (-1);
	ft_rotate(stack_a);
	ft_rotate(stack_b);
	ft_putendl_fd("rr", 1);
	return (0);
}
