/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cylinder.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fragarci <fragarci@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/21 11:44:31 by fragarci          #+#    #+#             */
/*   Updated: 2023/11/02 10:30:22 by fragarci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minirt.h"

void	ft_intersect_cylinder(t_data *data, t_ray *ray, t_object *cy)
{
	t_vector	co;
	t_vector	v;
	double		*t;

	ft_vector_init(&co, data->cam.position.i - cy->params[0],
		data->cam.position.j - cy->params[1],
		data->cam.position.k - cy->params[2]);
	ft_vector_init(&v, cy->params[3], cy->params[4], cy->params[5]);
	t = ft_solve_equation(ft_dot(&ray->dir, &ray->dir)
			- pow(ft_dot(&ray->dir, &v), 2), 2 * (ft_dot(&ray->dir, &co)
				- ft_dot(&ray->dir, &v) * ft_dot(&co, &v)),
			ft_dot(&co, &co) - pow(ft_dot(&co, &v), 2)
			- pow(cy->params[6] / 2, 2));
	if (t && t[0] > data->t_min && t[0] < data->t_max && t[0] < ray->t)
	{
		ray->collision = cy;
		ray->t = t[0];
	}
	if (t && t[1] > data->t_min && t[1] < data->t_max && t[1] < ray->t)
	{
		ray->collision = cy;
		ray->t = t[1];
	}
	free(t);
}
