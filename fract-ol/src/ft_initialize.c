/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_initialize.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fragarci <fragarci@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/24 17:05:11 by fragarci          #+#    #+#             */
/*   Updated: 2022/11/25 13:14:38 by fragarci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fractol.h"

void	ft_no_args(void)
{
	ft_printf("Avaible arguments:\n");
	ft_printf("\t- mandelbrot\n");
	ft_printf("\t- julia-1\n");
	ft_printf("\t- julia-2\n");
	ft_printf("\t- julia-3\n");
	ft_printf("\t- julia-4\n");
}

void	ft_initialize_mandelbrot(mlx_t *mlx, mlx_image_t *img)
{
	t_mandelbrot	*data;

	data = ft_struct_mandelbrot(img);
	ft_draw_mandelbrot(data);
	mlx_image_to_window(mlx, img, 0, 0);
	mlx_scroll_hook(mlx, &mandelbrot_zoom_hook, data);
	mlx_key_hook(mlx, &mandelbrot_movement_hook, data);
}

void	ft_initialize_julia(mlx_t *mlx, mlx_image_t *img,
			double real, double imag)
{
	t_julia	*data;

	data = ft_struct_julia(img, real, imag);
	ft_draw_julia(data);
	mlx_image_to_window(mlx, img, 0, 0);
	mlx_scroll_hook(mlx, &julia_zoom_hook, data);
	mlx_key_hook(mlx, &julia_movement_hook, data);
}
