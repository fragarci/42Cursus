/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fragarci <fragarci@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/02 10:21:15 by fragarci          #+#    #+#             */
/*   Updated: 2022/12/06 12:25:04 by fragarci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "../Libft/include/libft.h"

// INSTRUCTIONS
int			ft_pa(t_list **a, t_list **b);
int			ft_pb(t_list **a, t_list **b);
int			ft_ra(t_list **a);
int			ft_rb(t_list **b);

void		ft_check_args(int argc, char **argv);

void		ft_print_stack(t_list *stack);

#endif