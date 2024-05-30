/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmoura-p <cmoura-p@students.42porto.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/09 17:10:45 by cmoura-p          #+#    #+#             */
/*   Updated: 2024/05/22 20:53:17 by cmoura-p         ###   ########.fr       */
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
