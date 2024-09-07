/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stack.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmoura-p <cmoura-p@students.42porto.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/09 19:34:54 by cmoura-p          #+#    #+#             */
/*   Updated: 2024/09/07 20:32:30 by cmoura-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	stack_len(t_node *stack)
{
	int	i;

	i = 1;
	while (stack->next != NULL)
	{
		i++;
		stack = stack->next;
	}
	return (i);
}

bool	stack_ordered(t_node *stack)
{
	while (stack->next != NULL)
	{
		if (stack->num > stack->next->num)
			return (0);
		stack = stack->next;
	}
	return (1);
}

void	stack_init(t_node **a, char **argv)
{
	long	nbr;
	t_node	*aux;
	t_node	*new_node;

	while (*argv)
	{
		nbr = ft_atol(*argv);
		new_node = ft_calloc(sizeof(*new_node), 1);
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
		return ;
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
