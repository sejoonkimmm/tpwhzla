/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sejokim <sejokim@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/27 21:38:23 by sejokim           #+#    #+#             */
/*   Updated: 2023/03/28 19:18:20 by sejokim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_H
# define MINITALK_H

# include <unistd.h>
# include <stdlib.h>
# include <signal.h>

void	send_char(int server_pid, char ch);
size_t	ft_strlen(char *str);
int		ft_atoi(const char *str);
void	ft_putnbr_fd(int n);
void	get_signal(int signum);

#endif
