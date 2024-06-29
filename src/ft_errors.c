/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_errors.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmoura-p <cmoura-p@students.42porto.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/09 19:37:42 by cmoura-p          #+#    #+#             */
/*   Updated: 2024/06/29 19:36:17 by cmoura-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

bool	syntax_error(char *str)
{
	if (!(*str == '+' || *str == '-'
		|| (*str >= '0' && *str <= '9')))
		return (0);
	if ((*str == '+' || *str == '-')
		&& !(str[1] >= '0' && str[1] <= '9'))
        return (0);
	return (1);
}

bool	dup_error(char **nbrs, int n, int pos)
{
    int i = 0;

	while (i < pos)
	{
		if (ft_atol(nbrs[i]) == n)
			return (1);
		i++;
	}
	return (0);
}

void	free_argv(char **a)
{
    int i = 0;
	while (a[i])
	{
		free(a[i]);
		i++;
	}
	free(a); // tenho que colocar exit?
}


