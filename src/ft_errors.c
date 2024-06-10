/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_errors.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmoura-p <cmoura-p@students.42porto.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/09 19:37:42 by cmoura-p          #+#    #+#             */
/*   Updated: 2024/06/10 18:20:35 by cmoura-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	syntax_error(char *str_n) //Define a funtion to handle syntax errors, and returns `1` for `error` should any of the following conditions are met
{
	if (!(*str_n == '+'
			|| *str_n == '-'
			|| (*str_n >= '0' && *str_n <= '9'))) //Check if the first character of the input string does not contain a sign or a digit
		return (1);
	if ((*str_n == '+'
			|| *str_n == '-')
		&& !(str_n[1] >= '0' && str_n[1] <= '9')) //Check if the first character of the input string contains a sign, but the second character does not contain a digit
		return (1);
	while (*++str_n) //If the error conditions above are passed, pre-increment to point to the next character in the string, and loop until the end of the string is reached
	{
		if (!(*str_n >= '0' && *str_n <= '9')) //Check if the next character in the string is not a digit
			return (1);
	}
	return (0);
}

int	dup_error(t_stack_node *a, int n) //Define a function that checks for duplicate input numbers in stack `a`
{
	if (!a) //Check for an empty stack
		return (0);
	while (a) //Loop until the end of stack `a` is reached
	{
		if (a->num == n) //Check if the current node's value is equal to `n`. Refer to `init_stack_a()`
			return (1);
		a = a->next; //Move to the next node to check for duplicates
	}
	return (0);
}

void	free_errors(t_stack_node *a) //Define a function that, upon encountering a unique error, to free the stack and print an error message
{
	stack_freed(a);
	ft_printf("Error\n");
	exit(1);
}

