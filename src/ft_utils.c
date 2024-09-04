/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmoura-p <cmoura-p@students.42porto.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/10 19:19:13 by cmoura-p          #+#    #+#             */
/*   Updated: 2024/09/04 19:27:17 by cmoura-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_node	*find_last(t_node *a)
{
	t_node	*current;

	current = a;
	while (current->next != NULL)
		current = current->next;
	return (current);
}

t_node	*find_biggest(t_node *a)
{
	t_node	*biggest;

	biggest = a;
	if (biggest->num < a->next->num)
		biggest = a->next;
	if (biggest->num < a->next->next->num)
		biggest = a->next->next;
	return (biggest);
}
