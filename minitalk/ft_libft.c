/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_libft.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sejokim <sejokim@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/27 21:38:10 by sejokim           #+#    #+#             */
/*   Updated: 2023/03/28 19:20:08 by sejokim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	ft_putnbr_fd(int n)
{
	char		str[11];
	long long	nb;
	int			index;

	index = 0;
	nb = (long long)n;
	if (nb < 0)
	{
		write(1, "-", 1);
		nb *= -1;
	}
	else if (nb == 0)
		write(1, "0", 1);
	while (nb > 0)
	{
		str[index++] = nb % 10 + '0';
		nb /= 10;
	}
	while (--index >= 0)
		write(1, &str[index], 1);
	write(1, "\n", 1);
}

size_t	ft_strlen(char *str)
{
	size_t	index;

	index = 0;
	while (str[index] != '\0')
		index++;
	return (index);
}

static int	is_space(char c)
{
	if (c == '\n' || c == '\t' || c == '\r')
		return (1);
	else if (c == '\v' || c == '\f' || c == ' ')
		return (1);
	else
		return (0);
}

int	ft_atoi(const char *str)
{
	long long	num;
	int			neg;
	long long	tmp;

	neg = 1;
	num = 0;
	while (is_space(*str))
		str++;
	if (*str == '-' || *str == '+')
		if (*str++ == '-')
			neg = -1;
	while (*str >= '0' && *str <= '9')
	{
		tmp = num;
		num = num * 10 + *str++ - '0';
		if ((neg * num) < tmp && neg == 1)
			return (-1);
		if ((neg * num) > tmp && neg == -1)
			return (0);
	}
	return ((int)(num * neg));
}
