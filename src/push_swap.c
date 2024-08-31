/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmoura-p <cmoura-p@students.42porto.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/09 17:40:29 by cmoura-p          #+#    #+#             */
/*   Updated: 2024/08/31 20:27:15 by cmoura-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

//      TÔ PARADA AQUI      PRIMEIRO TENHO QUE FAZER OS STACK COM 2
//                          DEPOIS TENHO QUE FAZER O SHORT_SORT
//                          DEPOIS TENHO QUE FAZER O REAL_SORT

void    push_swap(t_node **stack_a)
{
 /*    t_node   *stack_b;

    stack_b = NULL; */
    if (!stack_ordered(*stack_a))
    {
        if (stack_len(*stack_a) == 2)
            sa(stack_a, false);
        else if(stack_len(*stack_a) == 3)
        	//short_sort(stack_a, stack_b);
            printf("Tem 3 \n");
        else
            //real_sort(stack_a, stack_b);
            printf("Tem mais de 3 \n");
    }
    return;
}
