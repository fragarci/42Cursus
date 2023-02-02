/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fragarci <fragarci@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/27 13:29:13 by fragarci          #+#    #+#             */
/*   Updated: 2023/02/02 18:00:51 by fragarci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fractol.h"

void	ft_mouse(double x, double y, void *vdata)
{
	t_data			*data;
	static double	scale;

	(void)x;
	if (scale == 0)
		scale = 1;
	data = (t_data *)vdata;
	if (y > 0)
		scale -= 0.01;
	else if (y < 0)
		scale += 0.01;
	data->scale = scale;
	ft_draw_fractal(data);
}
