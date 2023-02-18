/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utils1.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fragarci <fragarci@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/09 10:55:18 by fragarci          #+#    #+#             */
/*   Updated: 2023/02/09 12:19:38 by fragarci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

t_stack	*ft_stknew(int content)
{
	t_stack	*ret;

	ret = (t_stack *)malloc(sizeof(t_stack));
	if (!ret)
		return ((void *)0);
	ret -> data = content;
	ret -> next = (void *)0;
	return (ret);
}

t_stack	*ft_stklast(t_stack *stk)
{
	if (!stk)
		return ((void *)0);
	while (stk -> next)
		stk = stk -> next;
	return (stk);
}

void	ft_stkadd_back(t_stack **stk, t_stack *new)
{
	t_stack	*tmp;

	if (stk)
	{
		if (*stk == NULL)
			*stk = new;
		else
		{
			tmp = ft_stklast(*(stk));
			tmp->next = new;
		}
	}
}

void	ft_stkprint(t_stack *stk)
{
	while (stk)
	{
		ft_printf("%d\n", stk->data);
		stk = stk->next;
	}
}
