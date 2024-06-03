/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stack.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmoura-p <cmoura-p@students.42porto.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/09 19:34:54 by cmoura-p          #+#    #+#             */
/*   Updated: 2024/06/03 19:52:49 by cmoura-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

bool    stack_ordered(t_stack_node *a);
int     stack_len(t_stack_node *a);
bool    add_node(t_stack_node *a, int nbr)
{

}
void    init_stack(t_stack_node *a, char **argv)
{
    long    nbr;

    while (*argv)
    {
        nbr = atol(*argv);
        if (nbr > INT_MAX || nbr < INT_MIN)
            error_free(a, argv);
        if (repeat_error(a, (int)nbr))
            error_free(a, argv);
        add_node(a, (int)nbr);
        ++argv;
    }
}

