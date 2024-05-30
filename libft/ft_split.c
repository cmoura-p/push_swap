/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmoura-p <cmoura-p@students.42porto.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/09 17:13:09 by cmoura-p          #+#    #+#             */
/*   Updated: 2024/05/22 19:50:04 by cmoura-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static size_t	ft_segm_count(char const *s, char c)
{
	int	count;

	count = 0;
	while (*s)
	{
		if (*s != c)
		{
			count++;
			while (*s && *s != c)
				s++;
		}
		else
			s++;
	}
	return (count);
}

static size_t	ft_segm_size(char const *s, char c)
{
	size_t	size;

	size = 0;
	while (s[size] && s[size] != c)
		size++;
	return (size);
}

static char	**freelist(char **str, int i)
{
	while (i >= 0)
	{
		free(str[i]);
		i--;
	}
	free(str);
	return (NULL);
}

char	**ft_split(char const *s, char c)
{
	char		**lista;
	size_t		i;
	size_t		j;

	lista = (char **) ft_calloc((ft_segm_count(s, c) + 1), sizeof(char *));
	if (!lista || !s)
		return (NULL);
	i = 0;
	j = 0;
	while (s[i])
	{
		if (s[i] != c)
		{
			lista[j] = ft_substr(s, i, ft_segm_size(&s[i], c));
			if (!lista[j])
				return (freelist(lista, j));
			j++;
			i += ft_segm_size(&s[i], c);
		}
		else
			i++;
	}
	lista[j] = 0;
	return (lista);
}

