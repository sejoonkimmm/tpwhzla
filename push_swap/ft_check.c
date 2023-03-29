/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sejokim <sejokim@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/27 16:37:50 by sejokim           #+#    #+#             */
/*   Updated: 2023/03/28 19:22:47 by sejokim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	check_if_valid(char *str)
{
	int	index;

	index = 0;
	while (str[index] != '\0')
	{
		if ((str[index] >= '0' && str[index] <= '9') || str[index] == ' ' \
			|| str[index] == '-' || str[index] == '+')
		{
			if (str[index] == '-' || str[index] == '+')
				if (str[index + 1] != '\0' && (str[index + 1] < '0' \
					|| str[index + 1] > '9'))
					exit(write(1, "Error\n", 6) || 1);
			index++;
			continue ;
		}
		else
			exit(write(1, "Error\n", 6) || 1);
	}
	return (1);
}

int	check_if_sorted(t_stack st)
{
	while (st.lst->next != NULL)
	{
		if ((st.lst->data) >= (st.lst->next->data))
			return (1);
		st.lst = st.lst->next;
	}
	return (0);
}

int	check_if_double(t_stack st)
{
	t_list	*tmp;

	while (st.lst != NULL)
	{
		tmp = st.lst->next;
		while (tmp != NULL)
		{
			if (st.lst->data == tmp->data)
			{
				write(1, "Error\n", 6);
				return (0);
			}
			tmp = tmp->next;
		}
		st.lst = st.lst->next;
	}
	return (1);
}
