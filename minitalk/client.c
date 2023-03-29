/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sejokim <sejokim@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/27 21:38:03 by sejokim           #+#    #+#             */
/*   Updated: 2023/03/28 19:18:16 by sejokim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"
#include <stdio.h>

void	send_char(int server_pid, char ch)
{
	int	bit;

	bit = 8;
	while (bit-- != 0)
	{
		if ((ch >> bit) & 1)
			kill(server_pid, SIGUSR1);
		else
			kill(server_pid, SIGUSR2);
		usleep(50);
	}
}

int	main(int argc, char **argv)
{
	int	server_pid;

	if (argc != 3)
		exit(1);
	server_pid = ft_atoi(argv[1]);
	write(1, "Client PID : ", 13);
	ft_putnbr_fd(getpid());
	while (*argv[2] != '\0')
	{
		send_char(server_pid, *argv[2]);
		argv[2]++;
	}
	return (0);
}
