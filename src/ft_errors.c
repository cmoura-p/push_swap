/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_errors.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmoura-p <cmoura-p@students.42porto.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/09 19:37:42 by cmoura-p          #+#    #+#             */
/*   Updated: 2024/08/26 18:54:12 by cmoura-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	syntax_error(char *str) // ta' funcionando
{
	if (!(*str == '+' || *str == '-'
		|| (*str >= '0' && *str <= '9')))
		return (1);
	if ((*str == '+' || *str == '-')
		&& !(str[1] >= '0' && str[1] <= '9'))
        return (1);
	return (0);
}

int	dupli_error(char **nbrs, int n, int pos) // ta' funcionando
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
	free(a);
}


