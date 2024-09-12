/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rotation.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmoura-p <cmoura-p@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/09 19:37:42 by cmoura-p          #+#    #+#             */
/*   Updated: 2024/09/12 18:58:26 by cmoura-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rotate_ab(t_node **a, t_node **b, t_node *cheapest_node)
{
	while (*a != cheapest_node->target
		&& *b != cheapest_node)
		rr(a, b);
	set_position(*a);
	set_position(*b);
}

void	reverse_ab(t_node **a, t_node **b, t_node *cheapest_node)
{
	while (*a != cheapest_node->target
		&& *b != cheapest_node)
		rrr(a, b);
	set_position(*a);
	set_position(*b);
}

void	finish_rotation(t_node **stack, t_node *top_node, char stack_name)
{
	if (stack_name == 'a')
	{
		while (*stack != top_node)
		{
			if (top_node->first_half)
				ra(stack);
			else
				rra(stack);
		}
	}
	else if (stack_name == 'b')
	{
		while (*stack != top_node)
		{
			if (top_node->first_half)
				rb(stack);
			else
				rrb(stack);
		}
	}
}
