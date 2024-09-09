/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmoura-p <cmoura-p@students.42porto.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/09 17:10:45 by cmoura-p          #+#    #+#             */
/*   Updated: 2024/09/09 21:03:38 by cmoura-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdbool.h>
# include <limits.h>
# include <stdlib.h>
# include <stdio.h>
# include <unistd.h>
# include "../libft/libft.h"

typedef struct s_stack_node
{
	int			num;
	int			pos;
    int         price;
    bool        first_half;
    bool        cheapest;
    struct s_stack_node *target;
	struct s_stack_node	*next;
	struct s_stack_node	*prev;
}				t_node;

void	push_swap(t_node **stack_a);

//	Handle errors
int     syntax_error(char *str);
int     dupli_error(char **argv, int n, int pos);
void	free_argv(char **a);

//	Operations
void	sa(t_node **a);
void	sb(t_node **b);
void	ss(t_node **a, t_node **b);
void	ra(t_node **a);
void	rb(t_node **b);
void	rr(t_node **a, t_node **b);
void	rra(t_node **a);
void	rrb(t_node **b);
void	rrr(t_node **a, t_node **b);
void	pa(t_node **a, t_node **b);
void	pb(t_node **b, t_node **a);

//	Stack functions
bool	stack_ordered(t_node *a);
int     stack_len(t_node *a);
void	stack_init(t_node **a, char **argv);
void	stack_freed(t_node **stack);

//	Sorting functions
void	short_sort(t_node **a);
void    real_sort(t_node **a, t_node **b);
void    change_positions(t_node **a, t_node **b);
void    move_a(t_node **a, t_node *a_target);
void    move_b(t_node **b, t_node *cheapest_b);

//	Utils
char	**ft_split(char const *s, char c);
t_node	*find_last(t_node *stack);
t_node	*find_biggest(t_node *stack);
t_node  *find_smallest(t_node *stack);
t_node  *get_cheapest(t_node *stack);
t_node  *get_target(t_node *stack, t_node *a_target);

// Settings
void    find_cheapest(t_node *stack);
void	set_position(t_node *stack);
void	set_target(t_node *stack_a, t_node *stack_b);
void    set_price(t_node *stack_a, t_node *stack_b);

#endif
