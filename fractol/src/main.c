/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fragarci <fragarci@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/26 16:17:34 by fragarci          #+#    #+#             */
/*   Updated: 2023/03/23 10:19:56 by fragarci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fractol.h"

int	main(int argc, char **argv)
{
	t_data	data;

	if (argc <= 1 || argc > 4)
		ft_exit(NULL, EXIT_FAILURE);
	data = ft_init_fractal();
	ft_choose_fractal(argv, argc, &data);
	ft_draw_fractal(&data);
	mlx_scroll_hook(data.mlx, &ft_mouse, &data);
	mlx_key_hook(data.mlx, &ft_main_hook, &data);
	mlx_loop_hook(data.mlx, &ft_color_shift, &data);
	mlx_loop(data.mlx);
	ft_exit(&data, EXIT_SUCCESS);
	mlx_terminate(data.mlx);
	return (EXIT_SUCCESS);
}
