/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fragarci <fragarci@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/23 18:38:17 by fragarci          #+#    #+#             */
/*   Updated: 2022/11/24 17:59:23 by fragarci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fractol.h"

void	ft_choose_fractal(char **argv, mlx_t *mlx, mlx_image_t *img)
{
	if (!ft_strncmp(argv[1], "mandelbrot", 10))
		ft_initialize_mandelbrot(mlx, img);
}

int	main(int argc, char **argv)
{
	mlx_t			*mlx;
	mlx_image_t		*img;

	if (argc <= 1)
	{
		ft_no_args();
		exit(EXIT_FAILURE);
	}
	mlx = mlx_init(600, 400, "fractol", true);
	mlx_set_setting(MLX_STRETCH_IMAGE, 1);
	if (!mlx)
		exit(EXIT_FAILURE);
	img = mlx_new_image(mlx, 600, 400);
	ft_choose_fractal(argv, mlx, img);
	mlx_loop(mlx);
	mlx_terminate(mlx);
	exit(MLX_SUCCESS);
}
