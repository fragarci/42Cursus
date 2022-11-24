/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_initialize.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fragarci <fragarci@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/24 17:05:11 by fragarci          #+#    #+#             */
/*   Updated: 2022/11/24 17:30:45 by fragarci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fractol.h"

void	ft_no_args(void)
{
	ft_printf("Avaible arguments:\n\t- mandelbrot\n\t- julie\n");
}

void	ft_initialize_mandelbrot(mlx_t *mlx, mlx_image_t *img)
{
	t_mandelbrot	*data;

	data = ft_struct_mandelbrot(img, 1, 0, 0);
	ft_draw_mandelbrot(img, data);
	mlx_image_to_window(mlx, img, 0, 0);
	mlx_scroll_hook(mlx, &mandelbrot_zoom_hook, data);
	mlx_key_hook(mlx, &mandelbrot_movement_hook, data);
}
