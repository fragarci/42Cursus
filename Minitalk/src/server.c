/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fragarci <fragarci@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/22 20:14:21 by fragarci          #+#    #+#             */
/*   Updated: 2022/12/02 10:05:36 by fragarci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Libft/include/libft.h"
#include <signal.h>

void	put_pid(void)
{
	pid_t	pid;

	pid = getpid();
	if (!pid)
		return ;
	ft_printf("PID: %d\n", pid);
}

void	handler(int sig, siginfo_t *info, void *context)
{
	static int	bit_count = 0;
	static char	print = 0;

	if (context)
	{
	}
	if (sig == SIGUSR2)
		print |= 1 << bit_count;
	bit_count++;
	if (bit_count >= 8)
	{
		ft_putchar_fd(print, 1);
		if (print == '\0')
		{
			ft_printf("\n");
			kill(info->si_pid, SIGUSR1);
		}
		print = 0;
		bit_count = 0;
	}
}

int	main(void)
{
	struct sigaction	sig;

	put_pid();
	sigemptyset(&sig.sa_mask);
	sig.sa_flags = SA_SIGINFO;
	sig.sa_sigaction = handler;
	while (1)
	{
		sigaction(SIGUSR1, &sig, NULL);
		sigaction(SIGUSR2, &sig, NULL);
		pause();
	}
}
