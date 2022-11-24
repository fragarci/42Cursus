/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_complex.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fragarci <fragarci@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/23 19:06:04 by fragarci          #+#    #+#             */
/*   Updated: 2022/11/24 10:56:20 by fragarci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fractol.h"

t_complex	*ft_create_complex(double real, double imag)
{
	t_complex	*complex;

	complex = malloc(sizeof(t_complex));
	complex -> real = real;
	complex -> imag = imag;
	return (complex);
}

void	ft_add_complex(t_complex *c1, t_complex *c2)
{
	double	real_result;
	double	imag_result;

	real_result = (c1 -> real) + (c2 -> real);
	imag_result = (c1 -> imag) + (c2 -> imag);
	c1 -> real = real_result;
	c1 -> imag = imag_result;
}

void	ft_mul_complex(t_complex *c1, t_complex *c2)
{
	double	real_result;
	double	imag_result;

	real_result = c1 -> real * c2 -> real - c1 -> imag * c2 -> imag;
	imag_result = c1 -> real * c2 -> imag + c2 -> real * c1 -> imag;
	c1 -> real = real_result;
	c1 -> imag = imag_result;
}

float	ft_complex_module(t_complex *complex)
{
	return (sqrt(pow(complex -> real, 2) + pow(complex -> imag, 2)));
}
