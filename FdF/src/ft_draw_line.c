/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_draw_line.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fragarci <fragarci@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/17 18:00:03 by fragarci          #+#    #+#             */
/*   Updated: 2022/10/17 18:15:30 by fragarci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_fdf.h"

void	ft_draw_line(t_pont *a, t_pont *b)
{
	float	steps;

	if (fabs((b -> x_screen) - (a ->x_screen))
		> fabs((b -> y_screen) - (a -> y_screen)))
		steps = fabs((b -> x_screen) - (a ->x_screen));
	else
		steps = fabs((b -> y_screen) - (a -> y_screen));
}
