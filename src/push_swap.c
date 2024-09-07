/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmoura-p <cmoura-p@students.42porto.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/09 17:40:29 by cmoura-p          #+#    #+#             */
/*   Updated: 2024/09/07 19:29:49 by cmoura-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push_swap(t_node **stack_a)
{
    t_node  *stack_b;

    stack_b = NULL;
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
            real_sort(stack_a, &stack_b);
	}
	return ;
}
