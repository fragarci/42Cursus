/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fragarci <fragarci@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/25 17:48:03 by fragarci          #+#    #+#             */
/*   Updated: 2023/04/11 11:54:41 by fragarci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILOSOPHERS_H
# define PHILOSOPHERS_H

# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>
# include <pthread.h>
# include <sys/time.h>

struct	s_simulation;

typedef struct s_philo
{
	struct s_simulation	*sim;
	pthread_t			t1;
	int					id;
	int					eat_cont;
	int					status;
	int					eating;
	__uint64_t			t_die;
	pthread_mutex_t		lock;
	pthread_mutex_t		*r_fork;
	pthread_mutex_t		*l_fork;
}	t_philo;

typedef struct s_simulation
{
	pthread_t			*tid;
	int					n_philo;
	int					meals_nb;
	int					dead;
	int					finished;
	t_philo				*philos;
	__uint64_t			t_death;
	__uint64_t			t_eat;
	__uint64_t			t_sleep;
	__uint64_t			start_time;
	pthread_mutex_t		*forks;
	pthread_mutex_t		lock;
	pthread_mutex_t		write;
}	t_simulation;

long		ft_atoi(const char *str);
int			ft_error(char *str, t_simulation *sim);
int			ft_strcmp(char *s1, char *s2);
void		ft_messages(char *str, t_philo *philo);
void		ft_exit(t_simulation *sim);
__uint64_t	ft_get_time(void);
int			ft_usleep(__useconds_t time);
int			ft_init(t_simulation *sim, char **argv, int argc);
int			ft_thread_init(t_simulation *sim);
int			ft_input_checker(char **argv);
void		ft_eat(t_philo *philo);
void		*ft_philo(void *philo_pointer);

#endif
