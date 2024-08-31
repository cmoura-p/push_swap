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

t_node    add_node(t_node *a, int nbr)
{
    t_node  *node;

    node = malloc(sizeof(t_node));
    if (node == NULL)
        return;
    node->num = nbr;
    node->next = NULL;
    node->prev = NULL;

}
t_node find_last(t_node **a)
{
    if (a == NULL)
        return(NULL);

    t_node *current = a;
    while (current->next != NULL)
    {
        current = current->next;
    }
    return *current;
}

