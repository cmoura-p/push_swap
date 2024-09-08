/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_settings.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmoura-p <cmoura-p@students.42porto.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/09 19:37:42 by cmoura-p          #+#    #+#             */
/*   Updated: 2024/09/08 20:50:29 by cmoura-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	set_position(t_node *stack)
{
	int	i;
	int	half_way;

	i = 0;
	if (!stack)
		return ;
	half_way = stack_len(stack) / 2;
	while (stack)
	{
		stack->pos = i;
		if (i < half_way)
			stack->first_half = true;
		else
			stack->first_half = false;
		stack = stack->next;
		i++;
	}
}

void	set_target(t_node *stack_a, t_node *stack_b)
{
	t_node	*current_a;
	t_node	*target_node;
	long			best_match;

	while (stack_b)
	{
		best_match = LONG_MAX;
		current_a = stack_a;
		while (current_a)
		{
			if (stack_b->num < current_a->num
				&& current_a->num < best_match)
			{
				best_match = current_a->num;
				target_node = current_a;
			}
			current_a = current_a->next;
		}
		if (best_match == LONG_MAX)
			stack_b->target = find_smallest(stack_a);
		else
			stack_b->target = target_node;
		stack_b = stack_b->next;
	}

}
void    set_price(t_node *stack_a, t_node *stack_b)
{
	int	size_a;
	int	size_b;

	size_a = stack_len(stack_a);
	size_b = stack_len(stack_b);
	while (stack_b)
	{
		stack_b->price = stack_b->pos;
		if (!(stack_b->first_half))
			stack_b->price = size_b - (stack_b->pos);
		if (stack_b->target->first_half)
			stack_b->price = stack_b->price + stack_b->target->pos;
		else
			stack_b->price = stack_b->price + (size_a - (stack_b->target->pos));
		stack_b = stack_b->next;
	}
}
void find_cheapest(t_node *stack)
{
	long    best_value;
	t_node  *best_match;

	if (stack == NULL)
		return ;
	best_value = LONG_MAX;
	while (stack)
	{
		if (stack->price < best_value)
		{
			best_value = stack->price;
			best_match = stack;
		}
		stack = stack->next;
	}
	best_match->cheapest = true;

}

/*

display **a
display *a->next
display *a->next->next
display **b
display *b->next
display *b->next->next
display *b->next->next->next
display *b->next->next->next->next
display *b->next->next->next->next->next

*/
