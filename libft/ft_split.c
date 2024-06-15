/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmoura-p <cmoura-p@students.42porto.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/09 17:13:09 by cmoura-p          #+#    #+#             */
/*   Updated: 2024/06/15 19:06:49 by cmoura-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t ft_segm_count(char const *s, char c)
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

static char *ft_get_segm(const char *s, char c, size_t j)
{
	char 	*substr;
	int		i;

	i = 0;
    substr = (char *) ft_calloc((ft_segm_size(&s[j], c) + 1), sizeof(char));
	if (!substr)
		return (NULL);
    while(s[j] && s[j] != c)
	{
		substr[i] = s[j];
		i++;
		j++;
	}
	return(substr);
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
			lista[j] = ft_get_segm(s, c, i);
            if (!lista[j])
            {
                freelist(lista, j-1);
                return (NULL);
            }
            j++;
			i += ft_segm_size(&s[i], c);
		}
		else
			i++;
	}
	lista[j] = 0;
	return (lista);
}

int main(int argc, char **argv)
{
    char **lista;

	if (argc > 1)
        lista = ft_split(argv[1], ' ');
	return (0);
}
