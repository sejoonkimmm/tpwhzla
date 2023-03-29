/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_push.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sejokim <sejokim@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/27 16:38:35 by sejokim           #+#    #+#             */
/*   Updated: 2023/03/27 16:40:00 by sejokim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	push(t_stack **from, t_stack **to, char *msg)
{
	if ((*from)->len == 0)
		return (0);
	ft_lstadd_front(to, ft_lstnew((*from)->lst->data));
	ft_lstdel_front(from);
	write(1, msg, ft_strlen(msg));
	return (1);
}
