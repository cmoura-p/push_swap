/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmoura-p <cmoura-p@students.42porto.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/09 17:40:29 by cmoura-p          #+#    #+#             */
/*   Updated: 2024/09/05 21:00:59 by cmoura-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push_swap(t_node **stack_a)
{
    //t_node  *stack_b;

    //stack_b = NULL;
	if (!stack_ordered(*stack_a))
	{
		if (stack_len(*stack_a) == 2)
		{
			sa(stack_a, true);
		}
		else if (stack_len(*stack_a) == 3)
		{
			short_sort(stack_a);
		}
		else
            //real_sort(stack_a, stack_b);
            set_position(*stack_a);
	}
	return ;
}

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
		if (i <= half_way)
			stack->up_half = true;
		else
			stack->up_half = false;
		stack = stack->next;
		++i;
	}
}
