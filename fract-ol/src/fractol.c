/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fragarci <fragarci@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/23 18:38:17 by fragarci          #+#    #+#             */
/*   Updated: 2022/12/01 09:00:25 by fragarci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fractol.h"

// (0.285, 0.01)
// (-0.7269, 0.1889)
// (-0.8, 0.156)
// (-0.4, 0.6)

void	close_program(void *param)
{
	mlx_t	*mlx;

	mlx = param;
	if (mlx_is_key_down(mlx, MLX_KEY_ESCAPE))
		mlx_close_window(mlx);
}

int	ft_choose_fractal(char **argv, mlx_t *mlx, mlx_image_t *img)
{
	if (!ft_strncmp(argv[1], "mandelbrot", 10))
		ft_initialize_mandelbrot(mlx, img);
	else if (!ft_strncmp(argv[1], "julia-1", 7))
		ft_initialize_julia(mlx, img, 0.285, 0.01);
	else if (!ft_strncmp(argv[1], "julia-2", 7))
		ft_initialize_julia(mlx, img, -0.7269, 0.1889);
	else if (!ft_strncmp(argv[1], "julia-3", 7))
		ft_initialize_julia(mlx, img, -0.8, 0.156);
	else if (!ft_strncmp(argv[1], "julia-4", 7))
		ft_initialize_julia(mlx, img, -0.4, 0.6);
	else
	{
		ft_no_args();
		return (1);
	}
	return (0);
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
	if (ft_choose_fractal(argv, mlx, img))
	{
		mlx_terminate(mlx);
		exit(EXIT_FAILURE);
	}
	mlx_loop_hook(mlx, &close_program, mlx);
	mlx_loop(mlx);
	mlx_terminate(mlx);
	exit(EXIT_SUCCESS);
}
