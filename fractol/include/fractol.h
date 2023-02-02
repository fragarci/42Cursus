/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fragarci <fragarci@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/26 16:26:06 by fragarci          #+#    #+#             */
/*   Updated: 2023/02/02 18:01:43 by fragarci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include "../MLX42/include/MLX42/MLX42.h"
# include "../Libft/include/libft.h"
# include <math.h>
# include <memory.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# define WIDTH 600
# define HEIGHT 400

typedef struct s_rgb
{
	double		r;
	double		g;
	double		b;
}				t_rgb;

typedef struct s_hsv
{
	double		h;
	double		s;
	double		v;
}				t_hsv;

typedef struct s_pqt
{
	double		p;
	double		q;
	double		t;
}				t_pqt;

typedef struct s_complex
{
	double		imagine;
	double		real;
}				t_complex;

typedef struct s_data
{
	int			fractal;
	int			max_iter;
	int			rainbow;
	double		x_mov;
	double		y_mov;
	double		scale;
	double		real;
	double		imag;
	double		hue_off;
	t_complex	*complex;
	mlx_image_t	*img;
	mlx_t		*mlx;
}				t_data;

void			ft_choose_fractal(char **argv, int argc, t_data *data);
double			ft_mandelbrot(t_complex *complex, t_data *data);
void			ft_draw_fractal(t_data *data);
int				ft_fractal_color(double n, t_data *data);
t_complex		*ft_create_complex(double real, double imagine);
void			ft_complex_addnum(t_complex *n1, t_complex *n2);
void			ft_complex_mul(t_complex *n1, t_complex *n2);
float			ft_complex_module(t_complex *complex);
void			ft_mouse(double x, double y, void *vdata);
uint32_t		hsv2rgb(t_hsv hsv);
t_data			ft_init_fractal(void);
void			ft_julia_move_hook(struct mlx_key_data keydata, t_data *data);
void			ft_main_hook(struct mlx_key_data keydata, void *param);
double			ft_julia(t_complex *c, t_complex *z0, t_data *data);
double			ft_atof(char *str);
void			ft_init_julia(t_data *data, char **argv);
void			ft_exit(t_data *data, int status);
void			ft_render_pixel(t_data *data, t_complex *complex, int x, int y);
void			ft_init_mandelbrot(t_data *data, int argc);
int				ft_is_double(char *str);
void			ft_color_shift(void *param);
void			ft_color_hook(struct mlx_key_data keydata, t_data *data);
#endif