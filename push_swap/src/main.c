/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fragarci <fragarci@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/09 08:38:44 by fragarci          #+#    #+#             */
/*   Updated: 2023/02/18 14:50:13 by fragarci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

void	ft_simple_sort(t_stack **stack_a, t_stack **stack_b)
{
	if (ft_stksize(*stack_a) == 2)
		ft_sa((stack_a));
	if (ft_stksize(*stack_a) == 3)
		ft_sort_three(stack_a);
	if (ft_stksize(*stack_a) == 4)
		ft_sort_four(stack_a, stack_b);
	if (ft_stksize(*stack_a) == 5)
		ft_sort_five(stack_a, stack_b);
}

int	main(int argc, char **argv)
{
	t_stack	*stack_a;
	t_stack	*stack_b;

	stack_a = NULL;
	stack_b = NULL;
	if (stack_b != NULL)
		return (0);
	ft_check_arg_error(argc, argv);
	ft_initialize_stack(&stack_a, argc, argv);
	if (ft_stksorted(&stack_a))
		return (ft_stkclear(stack_a), 0);
	if (ft_stksize(stack_a) <= 5)
		ft_simple_sort(&stack_a, &stack_b);
	else
		ft_radix_sort(&stack_a, &stack_b);
	ft_stkclear(stack_a);
	return (0);
}
