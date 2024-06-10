/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmoura-p <cmoura-p@students.42porto.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/10 19:19:13 by cmoura-p          #+#    #+#             */
/*   Updated: 2024/06/10 19:20:42 by cmoura-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void    add_node(t_stack_node *a, int nbr)
{

}
t_stack_node *find_last(t_stack_node *a)
{
    if (a == NULL)
        return NULL;

    t_stack_node *current = a;
    while (current->next != NULL) {
        current = current->next;
    }
    return current;
}

