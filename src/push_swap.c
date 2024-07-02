/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmoura-p <cmoura-p@students.42porto.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/09 17:40:29 by cmoura-p          #+#    #+#             */
/*   Updated: 2024/07/02 18:07:25 by cmoura-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void check_input(int ac, char **av)
{
    long nbr;
    int i;

    nbr = 0;
    i = 0;
    while (av[i])
    {
        if (syntax_error(av[i]))
        {
            if (ac == 2)
                free_argv(av);
            ft_printf("ERROR \n");
            return;
        }
        nbr = ft_atol(av[i]);
        if ((nbr > INT_MAX || nbr < INT_MIN)
            || (dupli_error(av, nbr, i)))
        {
            if (ac == 2)
                free_argv(av);
            ft_printf("ERROR \n");
            return;
        }
        i++;
    }
}

/* void    stack_init(t_node **a, char **argv)
{
    long    nbr;
    t_node *aux;
    t_node *new_node;

    while (*argv)
    {
        nbr = ft_atol(*argv);
        new_node = (t_node *) malloc(sizeof(t_node));
        if (!new_node)
        {
            ft_printf("Malloc error \n");
            return;
        }
        new_node->num = (int)nbr;
        new_node->next = NULL;
        if (!a)
        {
            *a = new_node;
            aux = new_node;
        }
        else
        {
            aux->next = new_node;
            aux = aux->next;
        }
        ++argv;
    }
}
 */
int main(int argc, char **argv)
{
/*     t_node   *stack_a;
    t_node   *stack_b;

    stack_a = NULL;
    stack_b = NULL;
 */
    if (argc == 1)
        return (0);
    if (argc == 2 && !argv[1][0])
    {
        ft_printf("ERROR \n");
        return(0);
    }
    if (argc == 2)
        argv = ft_split(argv[1], ' ');
    else
        argv = argv + 1;
    check_input(argc, argv);
    /* stack_init(&stack_a, argv);

    if (!stack_ordered(stack_a))
    {
        if (stack_len(stack_a) == 2)
            sa(&stack_a, false);
        else if(stack_len(stack_a) == 3)
        	short_sort(stack_a, stack_b);
        else
            real_sort(stack_a, stack_b);
    }
    stack_freed(&stack_a);
 */
    return(0);
}

