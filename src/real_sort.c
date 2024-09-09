/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   real_sort.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmoura-p <cmoura-p@students.42porto.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/03 19:43:47 by cmoura-p          #+#    #+#             */
/*   Updated: 2024/06/29 18:48:57 by cmoura-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void    change_positions(t_node **a, t_node **b);
void    move_a(t_node **a, t_node *a_target);
void    move_b(t_node **b, t_node *cheapest_b);

void    real_sort(t_node **a, t_node **b)
{
    int size;

    size = stack_len(*a);
	while (size > 3)
    {
		pb(b, a);
        size--;
    }
	short_sort(a);
    while (*b)
    {
        set_position(*b);
        set_position(*a);
        set_target(*a, *b);
        set_price(*a, *b);
        find_cheapest(*b);
        change_positions(a, b);
    }
}
void    change_positions(t_node **a, t_node **b)
{
    t_node  *cheapest_b;
    t_node  *a_target;

    cheapest_b = get_cheapest(*b);
    a_target = get_target(*a, cheapest_b->target);
    if (!a_target->first_half)
        move_a(a, a_target);
    else if (a_target->pos == 1)
            sa(a);
        else if(a_target->pos != 0)
                move_a(a, a_target);
    if (!cheapest_b->first_half)
        move_b(b, cheapest_b);
    else if (cheapest_b->pos == 1)
            sb(b);
        else if(cheapest_b->pos != 0)
                move_b(b, cheapest_b);
    pb(a, b);
    return ;
}
/* void    move_a(t_node **a, t_node *a_target)
{
    return ;
}
void    move_b(t_node **b, t_node *cheapest_b)
{
    return ;
} */
