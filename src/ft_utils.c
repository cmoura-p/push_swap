/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmoura-p <cmoura-p@students.42porto.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/10 19:19:13 by cmoura-p          #+#    #+#             */
/*   Updated: 2024/09/08 14:25:29 by cmoura-p         ###   ########.fr       */
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

	smallest = stack;
	if (smallest->num > stack->next->num)
		smallest = stack->next;
	if (smallest->num > stack->next->next->num)
		smallest = stack->next->next;
	return (smallest);
}
