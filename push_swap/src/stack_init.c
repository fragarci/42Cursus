/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_init.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fragarci <fragarci@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/13 16:45:31 by fragarci          #+#    #+#             */
/*   Updated: 2023/02/13 17:37:02 by fragarci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

static void	ft_set_index(t_stack *stack, long *l_nbrs, size_t size)
{
	unsigned int	i;

	while (stack)
	{
		i = 0;
		while (i < size)
		{
			if (l_nbrs[i] == stack->data)
				stack->index = i;
			i++;
		}
		stack = stack->next;
	}
}

static void	ft_bubble_sort(long *l_nbrs, size_t size)
{
	unsigned int	i;
	unsigned int	j;
	long			aux;

	i = 0;
	while (i < size - 1)
	{
		j = 0;
		while (j < size - i - 1)
		{
			if (l_nbrs[j] > l_nbrs[j + 1])
			{
				aux = l_nbrs[j];
				l_nbrs[j] = l_nbrs[j + 1];
				l_nbrs[j + 1] = aux;
			}
			j++;
		}
		i++;
	}
}

static void	ft_fill_stack(t_stack **stack, long *l_nbrs, size_t size)
{
	unsigned int	i;

	i = 0;
	while (i < size)
		ft_stkadd_back(stack, ft_stknew((int)l_nbrs[i++]));
}

void	ft_initialize_stack(t_stack **stack, int argc, char **argv)
{
	long	*l_nbrs;
	size_t	size;

	l_nbrs = ft_argstol(argc, argv);
	size = ft_argvlen(argc, argv[1]);
	ft_fill_stack(stack, l_nbrs, size);
	ft_bubble_sort(l_nbrs, size);
	ft_set_index(*stack, l_nbrs, size);
	free(l_nbrs);
}
