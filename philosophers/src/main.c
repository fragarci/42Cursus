/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fragarci <fragarci@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/10 20:30:15 by fragarci          #+#    #+#             */
/*   Updated: 2023/04/11 13:08:35 by fragarci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/philosophers.h"

int	ft_one_philo(t_simulation *sim)
{
	sim->start_time = ft_get_time();
	if (pthread_create(&sim->tid[0], NULL, &ft_philo, &sim->philos[0]))
		return (ft_error("ERROR WHILE CREATING THREADS", sim));
	pthread_detach(sim->tid[0]);
	while (!sim->dead)
		ft_usleep(0);
	ft_exit(sim);
	return (0);
}

int	main(int argc, char **argv)
{
	t_simulation	sim;

	if (argc < 5 || argc > 6)
		return (1);
	if (ft_input_checker(argv))
		return (1);
	if (ft_init(&sim, argv, argc))
		return (1);
	if (sim.n_philo == 1)
		return (ft_one_philo(&sim));
	if (ft_thread_init(&sim))
		return (1);
	ft_exit(&sim);
	return (0);
}
