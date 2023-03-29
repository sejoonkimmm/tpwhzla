/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_over_five.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sejokim <sejokim@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/27 16:38:30 by sejokim           #+#    #+#             */
/*   Updated: 2023/03/28 20:04:40 by sejokim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	b_from_a(t_stack *a, t_stack *b)
{
	int	max;
	int	mid;
	int	max_index;

	max = b->len;
	while (max > 0)
	{
		max_index = get_index(b, b->len);
		mid = max / 2;
		if (max_index <= mid)
			while ((max_index--) > 0)
				rotate(&b, "rb\n");
		else
			while ((max_index++) < max)
				r_rotate(&b, "rrb\n");
		push(&b, &a, "pa\n");
		max--;
	}
}

void	if_case_over_five(t_stack *a, t_stack *b)
{
	int	index;
	int	chunk;

	chunk = 0.000000053 * a->len * a->len + 0.03 * a->len + 14.5;
	index = 0;
	while (a->len > 0)
	{
		if (a->lst->data <= index)
		{
			push(&a, &b, "pb\n");
			index++;
		}
		else if (a->lst->data <= index + chunk)
		{
			push(&a, &b, "pb\n");
			rotate(&b, "rb\n");
			index++;
		}
		else
			rotate(&a, "ra\n");
	}
	b_from_a(a, b);
}
