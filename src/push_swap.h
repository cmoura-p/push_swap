/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmoura-p <cmoura-p@students.42porto.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/09 17:10:45 by cmoura-p          #+#    #+#             */
/*   Updated: 2024/06/07 17:33:21 by cmoura-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

#include <stdbool.h>
#include <limits.h>
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include "../libft/libft.h"

typedef struct s_stack_node
{
    int                 num;
    int                 index;
    int                 push_cost;
    bool                on_first_half;
    bool                cheapest;
    struct s_stack_node *target_node;
    struct s_stack_node *next;
    struct s_stack_node *prev;
}                       t_stack_node;

/*
    Handle errors
*/
bool    repeat_error(t_stack_node *a, int nbr);
void    error_free(t_stack_node *a, char **argv);

/*
    Operations
*/
void	sa(t_stack_node **a, bool print);
void	sb(t_stack_node **b, bool print);
void	ss(t_stack_node **a, t_stack_node **b, bool print);
void	ra(t_stack_node **a, bool print);
void	rb(t_stack_node **b, bool print);
void	rr(t_stack_node **a, t_stack_node **b, bool print);
void	rra(t_stack_node **a, bool print);
void	rrb(t_stack_node **b, bool print);
void	rrr(t_stack_node **a, t_stack_node **b, bool print);
void	pa(t_stack_node **a, t_stack_node **b, bool print);
void	pb(t_stack_node **b, t_stack_node **a, bool print);
/*
    Stack functions
*/
bool    stack_ordered(t_stack_node *a);
int     stack_len(t_stack_node *a);
void    stack_init(t_stack_node *a, char **argv);
bool    add_node(t_stack_node *a, int nbr);

/*
    Sorting functions
*/
void    short_sort(t_stack_node *a, t_stack_node *b);
void    big_sort(t_stack_node *a, t_stack_node *b);

#endif

