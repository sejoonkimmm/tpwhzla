/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sejokim <sejokim@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/27 21:38:15 by sejokim           #+#    #+#             */
/*   Updated: 2023/03/28 19:18:15 by sejokim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	get_signal(int signum)
{
	static char	ch;
	static int	bit;

	if (signum == SIGUSR1)
		ch = ch | 1;
	if (bit == 7)
	{
		bit = 0;
		write(1, &ch, 1);
		ch = 0;
	}
	else
		bit++;
	ch <<= 1;
}

int	main(void)
{
	write(1, "Server PID : ", 13);
	ft_putnbr_fd(getpid());
	while (1)
	{
		signal(SIGUSR1, get_signal);
		signal(SIGUSR2, get_signal);
		pause();
	}
	return (0);
}
