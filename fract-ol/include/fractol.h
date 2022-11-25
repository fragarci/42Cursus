/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fragarci <fragarci@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/23 18:44:27 by fragarci          #+#    #+#             */
/*   Updated: 2022/11/25 11:48:06 by fragarci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include "../Libft/include/libft.h"
# include "../MLX42/include/MLX42/MLX42.h"
# include <math.h>

// COMPLEX NUMBERS

typedef struct s_complex
{
	double	real;
	double	imag;
}t_complex;

/**
 * Initializes a complex number
 * @param real Real part
 * @param imag Imaginary part
*/
t_complex		*ft_create_complex(double real, double imag);

/**
 * Add 2 complex numbers and stores the result in the first one
*/
void			ft_add_complex(t_complex *c1, t_complex *c2);

/**
 * Multiplies 2 complex numbers and stores the result in the first one
*/
void			ft_mul_complex(t_complex *c1, t_complex *c2);

/**
 * Returns the module of a complex number
*/
float			ft_complex_module(t_complex *complex);

// COLORS

/**
 * "Encode" rgba values into a int
*/
int				get_rgba(int r, int g, int b, int a);

// MANDELBROT SET

/**
 * Stores data about the mandelbrot set
 * @param scale_factor Zoom of the image
 * @param movement_x Movement on the X axis
 * @param movement_y Movement on the Y axis
 * @param img Image where the fractal will be rendered
 * 
*/
typedef struct s_mandelbrot
{
	double		scale_factor;
	double		movement_x;
	double		movement_y;
	mlx_image_t	*img;
}t_mandelbrot;

/**
 * Mandelbrot zoom hook function
 * @param xdelta Movement on te X axis
 * @param ydelta Movement on te Y axis
*/
void			mandelbrot_zoom_hook(double xdelta, double ydelta, void *param);

/**
 * Mandelbrot movement hook function
 * @param keydata Info about the key pressed
*/
void			mandelbrot_movement_hook(mlx_key_data_t keydata, void *param);

/**
 * If no arguments are present int the CLI, show the avaible arguments
 * to the user
*/
void			ft_no_args(void);

/**
 * Sets up key hooks and renders the Mandelbrot set
*/
void			ft_initialize_mandelbrot(mlx_t *mlx, mlx_image_t *img);

/**
 * Creates the struct that stores the data of the mandelbrot set
*/
t_mandelbrot	*ft_struct_mandelbrot(mlx_image_t *img);
double			ft_mandelbrot(t_complex *complex);

/**
 * Renders the mandelbrot set on screen
*/
void			ft_draw_mandelbrot(t_mandelbrot *data);

// JULIA SET

/**
 * Stores data about the julia set
 * @param scale_factor Zoom of the image
 * @param movement_x Movement on the X axis
 * @param movement_y Movement on the Y axis
 * @param constant Complex number that defines the shape of the fractal
 * @param img Image where the fractal will be rendered
 * 
*/
typedef struct s_julia
{
	double		scale_factor;
	double		movement_x;
	double		movement_y;
	t_complex	*constant;
	mlx_image_t	*img;
}t_julia;

/**
 * Julia zoom hook function
 * @param xdelta Movement on te X axis
 * @param ydelta Movement on te Y axis
*/
void			julia_zoom_hook(double xdelta, double ydelta, void *param);

/**
 * Mandelbrot movement hook function
 * @param keydata Info about the key pressed
*/
void			julia_movement_hook(mlx_key_data_t keydata, void *param);

/**
 * Sets up key hooks and renders the Julia set
*/
void			ft_initialize_julia(mlx_t *mlx, mlx_image_t *img,
					double real, double imag);

/**
 * Creates the struct that stores the data of the Julia set
*/
t_julia			*ft_struct_julia(mlx_image_t *img, double real, double imag);
double			ft_julia(t_complex *c, t_complex *z0);

/**
 * Renders the Julia set on screen
*/
void			ft_draw_julia(t_julia *data);

#endif