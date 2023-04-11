/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fragarci <fragarci@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/10 20:31:51 by fragarci          #+#    #+#             */
/*   Updated: 2023/04/11 12:19:24 by fragarci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/philosophers.h"

static void	ft_init_philos(t_simulation *sim)
{
	int	i;

	i = -1;
	while (++i < sim->n_philo)
	{
		sim->philos[i].sim = sim;
		sim->philos[i].id = i + 1;
		sim->philos[i].t_die = sim->t_death;
		sim->philos[i].eat_cont = 0;
		sim->philos[i].eating = 0;
		sim->philos[i].status = 0;
		pthread_mutex_init(&sim->philos[i].lock, NULL);
	}
}

static int	ft_init_forks(t_simulation *sim)
{
	int	i;

	i = -1;
	while (++i < sim->n_philo)
		pthread_mutex_init(&sim->forks[i], NULL);
	sim->philos[0].l_fork = &sim->forks[0];
	sim->philos[0].r_fork = &sim->forks[sim->n_philo - 1];
	i = 0;
	while (++i < sim->n_philo)
	{
		sim->philos[i].l_fork = &sim->forks[i];
		sim->philos[i].r_fork = &sim->forks[i - 1];
	}
	return (0);
}

static int	ft_alloc(t_simulation *sim)
{
	sim->tid = malloc(sizeof(pthread_t) * sim->n_philo);
	if (!sim->tid)
		return (ft_error("ERROR WHILE ALLOCATING THREADS IDs", sim));
	sim->forks = malloc(sizeof(pthread_mutex_t) * sim->n_philo);
	if (!sim->forks)
		return (ft_error("ERROR WHILE ALLOCATING FORKS", sim));
	sim->philos = malloc(sizeof(t_philo) * sim->n_philo);
	if (!sim->philos)
		return (ft_error("ERROR WHILE ALLOCATING PHILOS", sim));
	return (0);
}

static int	init_data(t_simulation *sim, char **argv, int argc)
{
	sim->n_philo = (int) ft_atoi(argv[1]);
	sim->t_death = (__uint64_t) ft_atoi(argv[2]);
	sim->t_eat = (__uint64_t) ft_atoi(argv[3]);
	sim->t_sleep = (__uint64_t) ft_atoi(argv[4]);
	if (argc == 6)
		sim->meals_nb = (int) ft_atoi(argv[5]);
	else
		sim->meals_nb = -1;
	if (sim->n_philo <= 0 || sim->n_philo > 200 || ft_atoi(argv[2]) < 0
		|| ft_atoi(argv[3]) < 0 || ft_atoi(argv[4]) < 0)
		return (ft_error("INVALID INPUT VALUES", NULL));
	sim->dead = 0;
	sim->finished = 0;
	pthread_mutex_init(&sim->write, NULL);
	pthread_mutex_init(&sim->lock, NULL);
	return (0);
}

int	ft_init(t_simulation *sim, char **argv, int argc)
{
	if (init_data(sim, argv, argc))
		return (1);
	if (ft_alloc(sim))
		return (1);
	if (ft_init_forks(sim))
		return (1);
	ft_init_philos(sim);
	return (0);
}
