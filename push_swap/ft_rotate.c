/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rotate.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sejokim <sejokim@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/27 16:38:39 by sejokim           #+#    #+#             */
/*   Updated: 2023/03/27 16:39:59 by sejokim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	rotate(t_stack **st, char *msg)
{
	t_list	*tmp;

	if ((*st)->lst == NULL)
		return (0);
	tmp = ft_lstnew((*st)->lst->data);
	ft_lstadd_back((*st), tmp);
	ft_lstdel_front(st);
	write(1, msg, ft_strlen(msg));
	return (1);
}

int	rr(t_stack **a, t_stack **b)
{
	if (rotate(a, "") == 0)
		return (0);
	if (rotate(b, "") == 0)
		return (0);
	write(1, "rr\n", 4);
	return (1);
}

int	r_rotate(t_stack **st, char *msg)
{
	t_list	*tmp;

	if ((*st)->len == 0)
		return (0);
	tmp = ft_lstnew(ft_lstlast((*st)->lst)->data);
	ft_lstadd_front(st, tmp);
	ft_lstdel_back((*st));
	write(1, msg, ft_strlen(msg));
	return (1);
}

int	rrr(t_stack **a, t_stack **b)
{
	if (r_rotate(a, "") == 0)
		return (0);
	if (r_rotate(b, "") == 0)
		return (0);
	write(1, "rrr\n", 3);
	return (1);
}
