/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fdf.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fragarci <fragarci@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/17 17:58:48 by fragarci          #+#    #+#             */
/*   Updated: 2022/10/17 18:19:23 by fragarci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_FDF_H
# define FT_FDF_H

# include <math.h>

typedef struct s_point
{
	int	x_screen;
	int	y_screen;

	int	x_wolrd;
	int	y_world;
	int	x_world;
}	t_pont;

void	ft_draw_line(t_pont *a, t_pont *b);

#endif