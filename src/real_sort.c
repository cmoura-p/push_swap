/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   real_sort.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmoura-p <cmoura-p@students.42porto.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/03 19:43:47 by cmoura-p          #+#    #+#             */
/*   Updated: 2024/09/12 20:01:13 by cmoura-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void		setting_nodes(t_node **a, t_node **b);
static void	moving_up(t_node **a, t_node **b);

void	real_sort(t_node **a, t_node **b)
{
	int		size;
	t_node	*smallest;

	size = stack_len(*a);
	while (size > 3)
	{
		pb(b, a);
		size--;
	}
	three_nodes(a);
	while (*b)
	{
		setting_nodes(a, b);
		moving_up(a, b);
	}
	set_position(*a);
	smallest = find_smallest(*a);
	finish_rotation(a, smallest, 'a');
}

void	setting_nodes(t_node **a, t_node **b)
{
	set_position(*b);
	set_position(*a);
	set_target(*a, *b);
	set_price(*a, *b);
	find_cheapest(*b);
}

static void	moving_up(t_node **a, t_node **b)
{
	t_node	*cheapest_node;
	t_node	*target_node;

	cheapest_node = get_cheapest(*b);
	target_node = cheapest_node->target;
	if (cheapest_node->first_half && target_node->first_half)
		rotate_ab(a, b, cheapest_node);
	else if (!(cheapest_node->first_half)
		&& !(target_node->first_half))
		reverse_ab(a, b, cheapest_node);
	finish_rotation(a, target_node, 'a');
	finish_rotation(b, cheapest_node, 'b');
	pa(a, b);
	return ;
}
