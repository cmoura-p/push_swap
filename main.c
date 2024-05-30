/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmoura-p <cmoura-p@students.42porto.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/09 17:06:04 by cmoura-p          #+#    #+#             */
/*   Updated: 2024/05/22 20:21:04 by cmoura-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int main(int argc, char **argv)
{
    t_stack_nodes   *a;
    t_stack_nodes   *b;

    a = NULL;
    b = NULL;

    if (argc == 1 || (argc == 2 && !argv[1][0]))
        return (1);
    else if (argc == 2)
            argv = ft_split(argv[1], ' ');
    init_stack(&a, *argv[1]);
    if (!stack_ordered(a))
    {
        if (stack_len(a) == 2)
            sa(&a, false);
        else if(stack_len(a) == 3)
        	quick_sort(&a, &b);
        else
            	push_swap(&a, &b);
    }
    free_stack(&a); // verificar o pq nao faco free direto
}
