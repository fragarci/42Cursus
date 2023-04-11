/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fragarci <fragarci@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/11 10:41:28 by fragarci          #+#    #+#             */
/*   Updated: 2023/04/11 12:05:08 by fragarci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/philosophers.h"

static void	clear_data(t_simulation	*sim)
{
	if (sim->tid)
		free(sim->tid);
	if (sim->forks)
		free(sim->forks);
	if (sim->philos)
		free(sim->philos);
}

void	ft_exit(t_simulation *sim)
{
	int	i;

	i = -1;
	while (++i < sim->n_philo)
	{
		pthread_mutex_destroy(&sim->forks[i]);
		pthread_mutex_destroy(&sim->philos[i].lock);
	}
	pthread_mutex_destroy(&sim->write);
	pthread_mutex_destroy(&sim->lock);
	clear_data(sim);
}

int	ft_error(char *str, t_simulation *sim)
{
	printf("\033[1;31m%s\n\033[0m", str);
	if (sim)
		ft_exit(sim);
	return (1);
}
