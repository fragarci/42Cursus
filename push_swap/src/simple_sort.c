/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simple_sort.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fragarci <fragarci@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/15 19:24:34 by fragarci          #+#    #+#             */
/*   Updated: 2023/02/18 12:07:28 by fragarci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

static void	ft_ra_pb(t_stack **a, t_stack **b)
{
	ft_ra(a);
	ft_pb(a, b);
}

static void	ft_rra_pb(t_stack **a, t_stack **b)
{
	ft_rra(a);
	ft_pb(a, b);
}

void	ft_sort_three(t_stack **a)
{
	if ((*a)->index == 0 && (*a)->next->index == 2
		&& (*a)->next->next->index == 1)
	{
		ft_rra(a);
		ft_sa(a);
	}
	if ((*a)->index == 1)
	{
		if ((*a)->next->index == 0)
			ft_sa(a);
		else
			ft_rra(a);
	}
	if ((*a)->index == 2)
	{
		if ((*a)->next->index == 0 || (*a)->next->index == 1)
			ft_ra(a);
		if ((*a)->next->index == 0)
			ft_sa(a);
	}
}

void	ft_sort_four(t_stack **a, t_stack **b)
{
	if ((*a)->next->index == 3)
		ft_ra(a);
	else if ((*a)->next->next->index == 3)
	{
		ft_ra(a);
		ft_ra(a);
	}
	else if ((*a)->next->next->next->index == 3)
		ft_rra(a);
	ft_pb(a, b);
	ft_sort_three(a);
	ft_pa(a, b);
	ft_ra(a);
}

void	ft_sort_five(t_stack **a, t_stack **b)
{
	if ((*a)->index == 4)
		ft_pb(a, b);
	else if ((*a)->next->index == 4)
		ft_ra_pb(a, b);
	else if ((*a)->next->next->index == 4)
	{
		ft_ra(a);
		ft_ra_pb(a, b);
	}
	else if ((*a)->next->next->next->index == 4)
	{
		ft_rra(a);
		ft_rra_pb(a, b);
	}
	else if ((*a)->next->next->next->next->index == 4)
		ft_rra_pb(a, b);
	ft_sort_four(a, b);
	ft_pa(a, b);
	ft_ra(a);
}
