/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmoura-p <cmoura-p@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/09 17:40:29 by cmoura-p          #+#    #+#             */
/*   Updated: 2024/09/12 18:57:07 by cmoura-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push_swap(t_node **stack_a)
{
	t_node	*stack_b;
	int		size_a;

	stack_b = NULL;
	size_a = (stack_len(*stack_a));
	if (!stack_ordered(*stack_a))
	{
		if (size_a == 2)
		{
			sa(stack_a);
		}
		else if (size_a == 3)
		{
			three_nodes(stack_a);
		}
		else if (size_a == 5)
		{
			five_nodes(stack_a, &stack_b);
		}
		else
			real_sort(stack_a, &stack_b);
	}
	return ;
}
