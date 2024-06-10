/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stack.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmoura-p <cmoura-p@students.42porto.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/09 19:34:54 by cmoura-p          #+#    #+#             */
/*   Updated: 2024/06/10 19:19:32 by cmoura-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void    stack_init(t_stack_node *a, char **argv)
{
    long    nbr;

    while (*argv)
    {
        nbr = ft_atol(*argv);
        if (nbr > INT_MAX || nbr < INT_MIN)
            error_free(a, argv);
        if (repeat_error(a, (int)nbr))
            error_free(a, argv);
        add_node(a, (int)nbr);
        ++argv;
    }
}
int     stack_len(t_stack_node *a)
{

}

bool    stack_ordered(t_stack_node *a)
{

}
void	stack_freed(t_stack_node **stack) //Define a function to free a stack if there are errors
{
	t_stack_node	*tmp; //To store the next node in the stack before the current node is freed, because once a node is freed, you can't access its next pointer
	t_stack_node	*current;

	if (!stack) //Check for an empty stack
		return ;
	current = *stack;
	while (current) //As long as a node exist in the stack
	{
		tmp = current->next; //Assign to `tmp` the pointer to the next node
		current->num = 0; //Assigning the node to `0` before freeing is not strictly necessary but it can help catch potential bugs such as memory-leaks and improve debugging
		free(current); //Free the current node, deallocating the memory occupied by that node
		current = tmp; //Assign `tmp` as the current first node
	}
	*stack = NULL;

}


