/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_push.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmoura-p <cmoura-p@students.42porto.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/09 17:13:23 by cmoura-p          #+#    #+#             */
/*   Updated: 2024/07/01 19:52:53 by cmoura-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	push(t_node **d, t_node **s)
{
	t_node	*push_node;

	if (!*s)
		return ;
	push_node = *s;
	*s = (*s)->next;
	if (*s)
		(*s)->prev = NULL;
	push_node->prev = NULL;
	if (!*d)
	{
		*d = push_node;
		push_node->next = NULL;
	}
	else
	{
		push_node->next = *d;
		push_node->next->prev = push_node;
		*d = push_node;
	}
}

void	pa(t_node **a, t_node **b, bool print)
{
	push(a, b);
	if (!print)
		write(1, "pa\n", 3);
}

void	pb(t_node **b, t_node **a, bool print)
{
	push(b, a);
	if (!print)
		write(1, "pb\n", 3);
}
