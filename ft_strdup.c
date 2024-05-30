/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmoura-p <cmoura-p@students.42porto.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/22 20:41:05 by cmoura-p          #+#    #+#             */
/*   Updated: 2024/05/22 20:47:35 by cmoura-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

char	*ft_strdup(const char *str)
{
	char	*ptr;
	size_t	size;

	size = ft_strlen(str) + 1;
	ptr = (char *) malloc(size * sizeof(char));
	if (!ptr)
		return (NULL);
	ft_memcpy(ptr, str, size);
	return ((char *) ptr);
}
