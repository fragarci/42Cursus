/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fragarci <fragarci@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/22 20:14:17 by fragarci          #+#    #+#             */
/*   Updated: 2022/11/23 18:24:54 by fragarci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Libft/include/libft.h"
#include <signal.h>

void	send_char(pid_t pid, char c)
{
	int	bit_count;

	bit_count = 0;
	while (bit_count < 8)
	{
		if (c & (1 << bit_count))
			kill(pid, SIGUSR2);
		else
			kill(pid, SIGUSR1);
		bit_count++;
		usleep(100);
	}
}

void	send_str(pid_t pid, const char *str)
{
	size_t	i;

	i = 0;
	while (str[i])
	{
		send_char(pid, str[i]);
		i++;
	}
}

int	main(int argc, char const *argv[])
{
	int	pid;

	if (argc == 3)
	{
		pid = ft_atoi(argv[1]);
		if (pid)
			send_str(pid, argv[2]);
		else
			return (1);
	}
	else
		return (1);
	return (0);
}
