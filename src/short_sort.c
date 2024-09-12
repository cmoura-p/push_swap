/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   short_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmoura-p <cmoura-p@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/09 18:14:07 by cmoura-p          #+#    #+#             */
/*   Updated: 2024/09/12 18:42:01 by cmoura-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	short_sort(t_node **a)
{
	t_node	*biggest_node;

	biggest_node = find_biggest(*a);
	if (biggest_node == *a)
		ra(a);
	else if (biggest_node == (*a)->next)
		rra(a);
	if ((*a)->num > (*a)->next->num)
		sa(a);
}

void	three_nodes(t_node **a)
{
	t_node	*biggest_node;

	biggest_node = find_biggest(*a);
	if (biggest_node == *a)
		ra(a);
	else if (biggest_node == (*a)->next)
		rra(a);
	if ((*a)->num > (*a)->next->num)
		sa(a);
}

void	five_nodes(t_node **a, t_node **b)
{
	t_node	*smallest_node;

	while (stack_len(*a) > 3)
	{
		setting_nodes(a, b);
		smallest_node = find_smallest(*a);
		finish_rotation(a, smallest_node, 'a');
		pb(b, a);
	}
	three_nodes(a);
	pa(a, b);
	pa(a, b);
}
