/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_swap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmoura-p <cmoura-p@students.42porto.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/09 17:13:48 by cmoura-p          #+#    #+#             */
/*   Updated: 2024/08/31 20:37:05 by cmoura-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sa(t_node **a, bool print);
void	sb(t_node **b, bool print);
void	ss(t_node **a, t_node **b, bool print);
/*
static void	swap(t_node **head)
{
    int len;

    len = stack_len(*head);
    if (len == 1 || *head == NULL || (*head)->next == NULL)
		return ;
	*head = (*head)->next;
	(*head)->prev->prev = *head;
	(*head)->prev->next = (*head)->next;
	if ((*head)->next)
		(*head)->next->prev = (*head)->prev;
	(*head)->next = (*head)->prev;
	(*head)->prev = NULL;
} */

static void	swap(t_node **head)
{
    if (*head == NULL || (*head)->next == NULL)
		return ;
	*head = (*head)->next;
	(*head)->prev->prev = *head;  // AQUI EH O MEU CALCANHAR DE AQUILES
	(*head)->prev->next = (*head)->next;
	if ((*head)->next)
		(*head)->next->prev = (*head)->prev;
	(*head)->next = (*head)->prev;
	(*head)->prev = NULL;
}

void	sa(t_node	**a, bool print)
{
	swap(a);
	if (print)
		write(1, "sa\n", 3);
}

void	sb(t_node **b, bool print)
{
	swap(b);
	if (print)
		write(1, "sb\n", 3);
}

void	ss(t_node **a, t_node **b, bool print)
{
	swap(a);
	swap(b);
	if (print)
		write(1, "ss\n", 3);
}
