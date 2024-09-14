/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_errors.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmoura-p <cmoura-p@students.42porto.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/09 19:37:42 by cmoura-p          #+#    #+#             */
/*   Updated: 2024/09/14 15:44:04 by cmoura-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	syntax_error(char *str)
{
	while (*str)
	{
		if (!(*str == '+' || *str == '-'
				|| (*str >= '0' && *str <= '9')))
			return (1);
		if ((*str == '+' || *str == '-')
			&& !(str[1] >= '0' && str[1] <= '9'))
			return (1);
		if ((*str >= '0' && *str <= '9')
			&& (str[1] == '+' || str[1] == '-'))
			return (1);
		str++;
	}
	return (0);
}

int	dupli_error(char **nbrs, int n, int pos)
{
	int	i;

	i = 0;
	while (i < pos)
	{
		if (ft_atol(nbrs[i]) == n)
			return (1);
		i++;
	}
	return (0);
}

void	free_argv(char **a, int ac)
{
	int	i;

	i = 0;
	if (ac == 2)
	{
		while (a[i])
		{
			free(a[i]);
			i++;
		}
		free(a);
	}
}
