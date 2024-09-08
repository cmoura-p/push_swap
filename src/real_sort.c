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
        set_position(*b);
        set_position(*a);
        set_target(*a, *b);
        set_price(*a, *b);
        find_cheapest(*b);
}
