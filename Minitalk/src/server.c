/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fragarci <fragarci@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/22 20:14:21 by fragarci          #+#    #+#             */
/*   Updated: 2022/11/23 10:11:29 by fragarci         ###   ########.fr       */
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

void	connection_handler(int sig)
{
	static int	bit_count = 0;
	static char	print = 0;

	if (sig == SIGUSR2)
		print |= 1 << bit_count;
	bit_count++;
	if (bit_count >= 8)
	{
		ft_putchar_fd(print, 1);
		print = 0;
		bit_count = 0;
	}
}

int	main(void)
{
	put_pid();
	signal(SIGUSR1, connection_handler);
	signal(SIGUSR2, connection_handler);
	while (1)
		pause();
}
