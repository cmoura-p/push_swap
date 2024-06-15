/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmoura-p <cmoura-p@students.42porto.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/03 18:04:20 by cmoura-p          #+#    #+#             */
/*   Updated: 2024/06/03 19:15:50 by cmoura-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <string.h>
# include <unistd.h>
# include <stdlib.h>

int		ft_atol(const char *s);
void	ft_bzero(void *buff, size_t n);
void	*ft_calloc(size_t n, size_t size);
void	*ft_memset(void *ptr, int value, size_t num);
char	**ft_split(char const *s, char c);
size_t	ft_strlen(const char *s);

#endif
