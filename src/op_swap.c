/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_swap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmoura-p <cmoura-p@students.42porto.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/09 17:13:48 by cmoura-p          #+#    #+#             */
/*   Updated: 2024/09/12 19:05:04 by cmoura-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sa(t_node **a);
void	sb(t_node **b);
void	ss(t_node **a, t_node **b);

static void	swap(t_node **top_node)
{
	if (*top_node == NULL || (*top_node)->next == NULL)
		return ;
	*top_node = (*top_node)->next;
	(*top_node)->prev->prev = *top_node;
	(*top_node)->prev->next = (*top_node)->next;
	if ((*top_node)->next)
		(*top_node)->next->prev = (*top_node)->prev;
	(*top_node)->next = (*top_node)->prev;
	(*top_node)->prev = NULL;
}

void	sa(t_node **a)
{
	swap(a);
	write(1, "sa\n", 3);
}

void	sb(t_node **b)
{
	swap(b);
	write(1, "sb\n", 3);
}

void	ss(t_node **a, t_node **b)
{
	swap(a);
	swap(b);
	write(1, "ss\n", 3);
}
