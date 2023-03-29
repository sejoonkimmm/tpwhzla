/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_swap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sejokim <sejokim@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/27 16:38:45 by sejokim           #+#    #+#             */
/*   Updated: 2023/03/27 16:39:56 by sejokim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	swap(t_stack **st, char *msg)
{
	int	tmp;

	if ((*st)->len < 2)
		return (0);
	tmp = (*st)->lst->data;
	(*st)->lst->data = (*st)->lst->next->data;
	(*st)->lst->next->data = tmp;
	write(1, msg, ft_strlen(msg));
	return (1);
}

int	ss(t_stack **a, t_stack **b)
{
	if (swap(a, "") == 0)
		return (0);
	if (swap(b, "") == 0)
		return (0);
	write(1, "ss\n", 3);
	return (1);
}
