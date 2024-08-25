/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stack.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmoura-p <cmoura-p@students.42porto.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/09 19:34:54 by cmoura-p          #+#    #+#             */
/*   Updated: 2024/08/24 18:07:09 by cmoura-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int     stack_len(t_node *a)
{
    int i;

    i = 1;
    while(a->next != NULL)
    {
        i++;
        a = a->next;
    }
    return (i);
}

bool    stack_ordered(t_node *a)
{
    return(0);
}
void	stack_freed(t_node **stack)
{
	t_node	*tmp;
	t_node	*current;

	if (!stack)
		return;
	current = *stack;
	while (current)
	{
		tmp = current->next;
		current->num = 0;
		free(current);
		current = tmp;
	}
	*stack = NULL;
}


