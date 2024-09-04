/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmoura-p <cmoura-p@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/09 17:40:29 by cmoura-p          #+#    #+#             */
/*   Updated: 2024/09/04 19:13:31 by cmoura-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push_swap(t_node **stack_a)
{
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
			printf("REAL SORT\n");
	}
	return ;
}
