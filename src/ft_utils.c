/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmoura-p <cmoura-p@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/10 19:19:13 by cmoura-p          #+#    #+#             */
/*   Updated: 2024/09/12 19:08:35 by cmoura-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_node	*find_last(t_node *stack)
{
	t_node	*current;

	current = stack;
	while (current->next != NULL)
		current = current->next;
	return (current);
}

t_node	*find_biggest(t_node *stack)
{
	t_node	*biggest;

	biggest = stack;
	if (biggest->num < stack->next->num)
		biggest = stack->next;
	if (biggest->num < stack->next->next->num)
		biggest = stack->next->next;
	return (biggest);
}

t_node	*find_smallest(t_node *stack)
{
	t_node	*smallest;
	long	min;

	min = LONG_MAX;
	smallest = stack;
	while (stack)
	{
		if (stack->num < min)
		{
			min = stack->num;
			smallest = stack;
		}
		stack = stack->next;
	}
	return (smallest);
}

t_node	*get_cheapest(t_node *stack)
{
	t_node	*chea_node;

	if (stack == NULL)
		return (NULL);
	chea_node = stack;
	while (chea_node)
	{
		if (chea_node->cheapest)
			return (chea_node);
		chea_node = chea_node->next;
	}
	return (NULL);
}
