/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fragarci <fragarci@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/10 20:31:23 by fragarci          #+#    #+#             */
/*   Updated: 2023/04/11 12:11:19 by fragarci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/philosophers.h"

__uint64_t	ft_get_time(void)
{
	struct timeval	tv;

	if (gettimeofday(&tv, NULL))
		return (ft_error("gettimeofday() ERROR\n", NULL));
	return ((tv.tv_sec * (__uint64_t)1000) + (tv.tv_usec / 1000));
}

void	ft_messages(char *str, t_philo *philo)
{
	__uint64_t	time;

	pthread_mutex_lock(&philo->sim->write);
	time = ft_get_time() - philo->sim->start_time;
	if (ft_strcmp("died", str) == 0 && !philo->sim->dead)
	{
		printf("%lu %d %s\n", time, philo->id, str);
		philo->sim->dead = 1;
	}
	if (!philo->sim->dead)
		printf("%lu %d %s\n", time, philo->id, str);
	pthread_mutex_unlock(&philo->sim->write);
}

static void	ft_drop_forks(t_philo *philo)
{
	pthread_mutex_unlock(philo->l_fork);
	pthread_mutex_unlock(philo->r_fork);
	ft_messages("is sleeping", philo);
	ft_usleep(philo->sim->t_sleep);
}

static void	ft_take_forks(t_philo *philo)
{
	pthread_mutex_lock(philo->r_fork);
	ft_messages("has taken a fork", philo);
	pthread_mutex_lock(philo->l_fork);
	ft_messages("has taken a fork", philo);
}

void	ft_eat(t_philo *philo)
{
	ft_take_forks(philo);
	pthread_mutex_lock(&philo->lock);
	philo->eating = 1;
	philo->t_die = ft_get_time() + philo->sim->t_death;
	ft_messages("is eating", philo);
	philo->eat_cont++;
	ft_usleep(philo->sim->t_eat);
	philo->eating = 0;
	pthread_mutex_unlock(&philo->lock);
	ft_drop_forks(philo);
}
