/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fragarci <fragarci@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/02 10:21:15 by fragarci          #+#    #+#             */
/*   Updated: 2023/02/18 12:08:11 by fragarci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "../Libft/include/libft.h"
# include <limits.h>

typedef struct s_stack
{
	unsigned int	index;
	int				data;
	struct s_stack	*next;
}	t_stack;

// STACK
t_stack	*ft_stknew(int content);
t_stack	*ft_stklast(t_stack *stk);
void	ft_stkadd_back(t_stack **stk, t_stack *new);
void	ft_stkprint(t_stack *stk);
void	ft_stkprint_all(t_stack *a, t_stack *b);
void	ft_stkclear(t_stack *stk);
int		ft_stksize(t_stack *lst);
int		ft_stksorted(t_stack **stack);

// STRING
void	ft_split_free(char **split);
int		ft_str_isdigit(char *str);
long	ft_atol(const char *nptr);
size_t	ft_argvlen(int argc, char *argv);

// PARSER
long	*ft_argstol(int argc, char **argv);

// ERRORS
void	ft_check_arg_error(int argc, char **argv);

// STACK INIT
void	ft_initialize_stack(t_stack **stack, int argc, char **argv);

// MOVEMENTS
int		ft_sa(t_stack **stack_a);
int		ft_sb(t_stack **stack_b);
int		ft_ss(t_stack **stack_a, t_stack **stack_b);

int		ft_pa(t_stack **stack_a, t_stack **stack_b);
int		ft_pb(t_stack **stack_a, t_stack **stack_b);

int		ft_ra(t_stack **stack_a);
int		ft_rb(t_stack **stack_b);
int		ft_rr(t_stack **stack_a, t_stack **stack_b);

int		ft_rra(t_stack **stack_a);
int		ft_rrb(t_stack **stack_b);
int		ft_rrr(t_stack **stack_a, t_stack **stack_b);

// SORT
void	ft_sort_three(t_stack **a);
void	ft_sort_four(t_stack **a, t_stack **b);
void	ft_sort_five(t_stack **a, t_stack **b);
void	ft_radix_sort(t_stack **stack_a, t_stack **stack_b);

#endif