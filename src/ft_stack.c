/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stack.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmoura-p <cmoura-p@students.42porto.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/09 19:34:54 by cmoura-p          #+#    #+#             */
/*   Updated: 2024/09/01 20:09:29 by cmoura-p         ###   ########.fr       */
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
    while (a->next != NULL)
    {
        if (a->num > a->next->num)
            return(0);
        a = a->next;
    }
    return(1);
}
void    stack_init(t_node **a, char **argv)
{
    long    nbr;
    t_node *aux;
    t_node *new_node;

    while (*argv)
    {
        nbr = ft_atol(*argv);
        new_node = ft_calloc(sizeof(*new_node), 1);
        if (!new_node)
            return;
        new_node->num = (int)nbr;
        new_node->next = NULL;
        new_node->prev = NULL;
        if (!*a)
        {
            *a = new_node;
            aux = new_node;
        }
        else
        {
            aux->next = new_node;
            new_node->prev = aux;
            aux = new_node;
        }
        ++argv;
    }
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


