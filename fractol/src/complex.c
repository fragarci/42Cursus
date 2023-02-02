/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   complex.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fragarci <fragarci@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/26 17:42:24 by fragarci          #+#    #+#             */
/*   Updated: 2023/02/02 18:01:09 by fragarci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fractol.h"

t_complex	*ft_create_complex(double real, double imagine)
{
	t_complex	*data;

	data = (t_complex *)malloc(sizeof(t_complex));
	if (!data)
		return (NULL);
	data->real = real;
	data->imagine = imagine;
	return (data);
}

void	ft_complex_addnum(t_complex *n1, t_complex *n2)
{
	double	result_real;
	double	result_imagine;

	result_real = (n1->real) + (n2->real);
	result_imagine = (n1->imagine) + (n2->imagine);
	n1->real = result_real;
	n1->imagine = result_imagine;
}

void	ft_complex_mul(t_complex *n1, t_complex *n2)
{
	double	result_real;
	double	result_imagine;

	result_real = (n1->real * n2->real) - (n1->imagine * n2->imagine);
	result_imagine = (n1->real * n2->imagine) + (n1->real * n2->imagine);
	n1->real = result_real;
	n1->imagine = result_imagine;
}

float	ft_complex_module(t_complex *complex)
{
	return ((complex->real * complex->real)
		+ (complex->imagine * complex->imagine));
}
