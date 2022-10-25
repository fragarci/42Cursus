/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fragarci <fragarci@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/14 13:21:08 by fragarci          #+#    #+#             */
/*   Updated: 2022/10/20 09:58:26 by fragarci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../MLX42/include/MLX42/MLX42.h"
#include "../include/ft_fdf.h"

int	main(void)
{
	mlx_t		*mlx;
	mlx_image_t	*img;

	mlx = mlx_init(500, 500, "MLX", false);
	if (!mlx)
		return (0);
	img = mlx_new_image(mlx, 500, 500);
	if (!img || (mlx_image_to_window(mlx, img, 0, 0) < 0))
		return (0);
	mlx_put_pixel(img, 0, 0, 0xFF0000FF);

	ft_draw_line();

	mlx_loop(mlx);
	mlx_terminate(mlx);
	return (0);
}

/*
ISOMETRIC CALCULATIONS

|	1		0			  0		|		|	cos(b)		0	-sin(b)	|		|	px	|
|	0	  cos(a)		sin(a)	|	x	|	  0			1	  0		|	x 	|	py	|
|	0	 -sin(a)		cos(a)	|		|	sin(b)		0	 cos(b)	|		|	pz	|

| 	   cos(b)			0			-sin(b)		|		|	px	|
| sin(a) * sin(b)	  cos(a)	sin(a) * cos(b)	|	x	|	py	|
| cos(a) * sin(b)	 -sin(a)	cos(a) * cos(b)	|		|	pz	|

| 				  px * cos(b) - pz * sin(b)						|
| px * (sin(a) * sin(b)) + py * cos(a) + pz * (sin(a) * cos(b))	|
| px * (cos(a) * sin(b)) - py * sin(a) + pz * (cos(a) * cos(b))	|

ORTHOGRAPHIC PROJECTION

|	1	0	0	|		| 				  px * cos(b) - pz * sin(b)						|
|	0	1	0	|	x	| px * (sin(a) * sin(b)) + py * cos(a) + pz * (sin(a) * cos(b))	|
|	0	0	0	|		| px * (cos(a) * sin(b)) - py * sin(a) + pz * (cos(a) * cos(b))	|

| 					px * cos(b) - pz * sin(b)					|
| px * (sin(a) * sin(b)) + py * cos(a) + pz * (sin(a) * cos(b)) |
| 							   0								|

x_screen = px * cos(b) - pz * sin(b)
y_screen = px * (sin(a) * sin(b)) + py * cos(a) + pz * (sin(a) * cos(b))
*/