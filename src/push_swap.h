/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmoura-p <cmoura-p@students.42porto.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/09 17:10:45 by cmoura-p          #+#    #+#             */
/*   Updated: 2024/06/29 19:40:28 by cmoura-p         ###   ########.fr       */
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
    int                 cost;
    bool                first_half;
    bool                cheapest;
    struct s_stack_node *next;
    struct s_stack_node *prev;
    struct s_stack_node *target;
}                       t_node;

/*
    Handle errors
*/
bool    syntax_error(char *str);
bool    dup_error(char **argv, int n, int pos);
void    free_argv(char **a);

/*
    Operations
*/
void	sa(t_node **a, bool print);
void	sb(t_node **b, bool print);
void	ss(t_node **a, t_node **b, bool print);
void	ra(t_node **a, bool print);
void	rb(t_node **b, bool print);
void	rr(t_node **a, t_node **b, bool print);
void	rra(t_node **a, bool print);
void	rrb(t_node **b, bool print);
void	rrr(t_node **a, t_node **b, bool print);
void	pa(t_node **a, t_node **b, bool print);
void	pb(t_node **b, t_node **a, bool print);
/*
    Stack functions
*/
bool    stack_ordered(t_node *a);
int     stack_len(t_node *a);
void    stack_init(t_node **a, char **argv);
void	stack_freed(t_node **stack);

/*
    Sorting functions
*/
void    short_sort(t_node *a, t_node *b);
void    real_sort(t_node *a, t_node *b);

/*
    Utils
*/
t_node  find_last(t_node **a);
bool    add_node(t_node *a, int nbr);

#endif
