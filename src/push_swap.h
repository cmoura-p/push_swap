/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmoura-p <cmoura-p@students.42porto.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/09 17:10:45 by cmoura-p          #+#    #+#             */
/*   Updated: 2024/09/01 20:09:44 by cmoura-p         ###   ########.fr       */
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
    int                 pos;
//    int                 cost;
//    int                 final_index: (eh uma opcao do oceano)
//    bool                first_half;
//    bool                cheapest;
    struct s_stack_node *next;
    struct s_stack_node *prev;
//    struct s_stack_node *target;
}                       t_node;

void    push_swap(t_node **stack_a);
/*
    Handle errors
*/
int     syntax_error(char *str);
int     dupli_error(char **argv, int n, int pos);
void    free_argv(char **a);

/*
    Operations
*/
void	sa(t_node **a, bool print);
/*
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
*/
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
//void    short_sort(t_node *a, t_node *b);
//void    real_sort(t_node *a, t_node *b);

/*
    Utils
*/
char    **ft_split(char const *s, char c);
//t_node  add_node(t_node **node, int nbr);
// t_node  find_last(t_node **a);

#endif
