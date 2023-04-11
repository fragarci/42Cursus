/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   threads.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fragarci <fragarci@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/10 20:32:14 by fragarci          #+#    #+#             */
/*   Updated: 2023/04/11 12:24:13 by fragarci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/philosophers.h"

void	*ft_philo_monitor(void *philo_ptr)
{
	t_philo	*philo;

	philo = (t_philo *) philo_ptr;
	while (!philo->sim->dead)
	{
		pthread_mutex_lock(&philo->lock);
		if (philo->sim->finished >= philo->sim->n_philo)
			philo->sim->dead = 1;
		pthread_mutex_unlock(&philo->lock);
	}
	return ((void *)0);
}

void	*ft_philo_supervisor(void *philo_ptr)
{
	t_philo	*philo;

	philo = (t_philo *) philo_ptr;
	while (philo->sim->dead == 0)
	{
		pthread_mutex_lock(&philo->lock);
		if (ft_get_time() >= philo->t_die && !philo->eating)
			ft_messages("died", philo);
		if (philo->eat_cont == philo->sim->meals_nb)
		{
			pthread_mutex_lock(&philo->sim->lock);
			philo->sim->finished++;
			philo->eat_cont++;
			pthread_mutex_unlock(&philo->sim->lock);
		}
		pthread_mutex_unlock(&philo->lock);
	}
	return ((void *)0);
}

void	*ft_philo(void *philo_ptr)
{
	t_philo	*philo;

	philo = (t_philo *) philo_ptr;
	philo->t_die = philo->sim->t_death + ft_get_time();
	if (pthread_create(&philo->t1, NULL, &ft_philo_supervisor, (void *)philo))
		return ((void *)1);
	while (!philo->sim->dead)
	{
		ft_eat(philo);
		ft_messages("is thinking", philo);
	}
	if (pthread_join(philo->t1, NULL))
		return ((void *)1);
	return ((void *)0);
}

int	ft_thread_init(t_simulation *sim)
{
	int			i;
	pthread_t	t0;

	i = -1;
	sim->start_time = ft_get_time();
	if (sim->meals_nb > 0)
	{
		if (pthread_create(&t0, NULL, &ft_philo_monitor, &sim->philos[0]))
			return (ft_error("ERROR WHILE CREATING THREADS", sim));
	}
	while (++i < sim->n_philo)
	{
		if (pthread_create(&sim->tid[i], NULL, &ft_philo, &sim->philos[i]))
			return (ft_error("ERROR WHILE CREATING THREADS", sim));
		ft_usleep(1);
	}
	i = -1;
	while (++i < sim->n_philo)
	{
		if (pthread_join(sim->tid[i], NULL))
			return (ft_error("ERROR WHILE JOINING THREADS", sim));
	}
	return (0);
}
