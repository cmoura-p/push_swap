/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmoura-p <cmoura-p@students.42porto.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/09 17:10:45 by cmoura-p          #+#    #+#             */
/*   Updated: 2024/05/30 20:24:09 by cmoura-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

#include <stdbool.h>
#include <limits.h>
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>

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
}   t_stack_nodes;

/*
    Handle errors
*/
bool    repeat_error(t_stack_nodes *a, int nbr);
void    error_free(t_stack_nodes *a, char **argv);

/*
    LIBFT functions
*/
char    *ft_split(char *str, char s);
char	*ft_strdup(const char *str);
char	*ft_substr(char const *s, unsigned int start, size_t len);
void	ft_bzero(void *b, size_t len);
void	*ft_calloc(size_t nmemb, size_t size);
void	*ft_memcpy(void *dest, const void *src, size_t size);
void	*ft_memset(void *dest, int p, size_t size);
int	    ft_atol(const char *str);
size_t	ft_strlen(const char *str);
/*
    Operations
*/

/*
    Stack functions
*/
bool    stack_ordered(t_stack_nodes *a);
int     stack_len(t_stack_nodes *a);
void    init_stack(t_stack_nodes *a, char **argv);
void    quick_sort(t_stack_nodes *a, t_stack_nodes *b);

/*
    Sorting functions
*/

#endif

/*
#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdbool.h> //To use bool flags, e.g, to print or not to print
# include <limits.h> //To define MIN and MAX macros
# include "../libft/inc/libft.h"
# include "../libft/inc/ft_printf.h"

typedef struct s_stack_node //A container of data enclosed in {} braces. `s_` for struct
{
	int					nbr; //The number to sort
	int					index; //The number's position in the stack
	int					push_cost; //How many commands in total
	bool				above_median; //Used to calculate `push_cost`
	bool				cheapest; //The node that is the cheapest to do commands
	struct s_stack_node	*target_node; //The target node of a node in the opposite stack
	struct s_stack_node	*next; //A pointer to the next node
	struct s_stack_node	*prev; //A pointer to the previous node
}	t_stack_node; //The "shortened name", "t_stack_node". `t_` for type

//***Handle errors
int				error_syntax(char *str_n);
int				error_duplicate(t_stack_node *a, int n);
void			free_stack(t_stack_node **stack);
void			free_errors(t_stack_node **a);

//***Stack initiation
void			init_stack_a(t_stack_node **a, char **argv); //Initiate stack `a` before processing
char			**split(char *s, char c); //To handle input of numbers as a string argument, e.g. enclosed in " "

//***Nodes initiation
void			init_nodes_a(t_stack_node *a, t_stack_node *b); //To prep all nodes for pushing `a` to `b`
void			init_nodes_b(t_stack_node *a, t_stack_node *b); //To prep all nodes for pushing `b` back to `a`
void			current_index(t_stack_node *stack); //Set the node's current index
void			set_cheapest(t_stack_node *stack); //Set the stack's cheapest node
t_stack_node	*get_cheapest(t_stack_node *stack); //Get the cheapest node of a stack
void			prep_for_push(t_stack_node **s, t_stack_node *n, char c); //Prep the required nodes on top for pushing

//***Stack utils
int				stack_len(t_stack_node *stack); //Calculate the length of a stack
t_stack_node	*find_last(t_stack_node *stack); //Find the last node of a stack
bool			stack_sorted(t_stack_node *stack); //To check whether a stack is sorted
t_stack_node	*find_min(t_stack_node *stack); //Find the smallest number
t_stack_node	*find_max(t_stack_node *stack); //Find the biggest number

//***Commands
void			sa(t_stack_node **a, bool print);
void			sb(t_stack_node **b, bool print);
void			ss(t_stack_node **a, t_stack_node **b, bool print);
void			ra(t_stack_node **a, bool print);
void			rb(t_stack_node **b, bool print);
void			rr(t_stack_node **a, t_stack_node **b, bool print);
void			rra(t_stack_node **a, bool print);
void			rrb(t_stack_node **b, bool print);
void			rrr(t_stack_node **a, t_stack_node **b, bool print);
void			pa(t_stack_node **a, t_stack_node **b, bool print);
void			pb(t_stack_node **b, t_stack_node **a, bool print);

//***Algorithm
void			sort_three(t_stack_node **a);
void			sort_stacks(t_stack_node **a, t_stack_node **b); //Turk algorithm

#endif
*/
