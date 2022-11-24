/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fragarci <fragarci@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/23 18:44:27 by fragarci          #+#    #+#             */
/*   Updated: 2022/11/24 12:42:42 by fragarci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include <stdlib.h>
# include <math.h>
# include "../MLX42/include/MLX42/MLX42.h"

// COMPLEX NUMBERS

typedef struct s_complex
{
	double	real;
	double	imag;
}t_complex;

t_complex		*ft_create_complex(double real, double imag);
void			ft_add_complex(t_complex *c1, t_complex *c2);
void			ft_mul_complex(t_complex *c1, t_complex *c2);
float			ft_complex_module(t_complex *complex);

// COLORS

int				get_rgba(int r, int g, int b, int a);

// MANDELBROT SET

typedef struct s_mandelbrot
{
	double		scale_factor;
	double		movement_x;
	double		movement_y;
	mlx_image_t	*img;
}t_mandelbrot;

t_mandelbrot	*ft_struct_mandelbrot(mlx_image_t *img, double sclale_factor,
					double movement_x, double movement_y);
int				ft_mandelbrot(t_complex *complex);
void			ft_draw_mandelbrot(mlx_image_t *img, t_mandelbrot *data);

#endif