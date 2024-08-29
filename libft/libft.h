/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmoura-p <cmoura-p@students.42porto.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/03 18:04:20 by cmoura-p          #+#    #+#             */
/*   Updated: 2024/08/29 18:24:34 by cmoura-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <string.h>
# include <unistd.h>
# include <stdlib.h>
# include <stdarg.h>

# define DEC    "0123456789"
# define HEXL   "0123456789abcdef"
# define HEXU   "0123456789ABCDEF"

long	ft_atol(const char *s);
void	ft_bzero(void *buff, size_t n);
void	*ft_calloc(size_t n, size_t size);
void	*ft_memset(void *ptr, int value, size_t num);
size_t	ft_strlen(const char *s);

// printf
int		ft_printf(const char *format, ...);
int		ft_check_format(char datatype, va_list ap);
int		ft_print_char(int c);
int		ft_print_str(char *str);
int		ft_print_num(long n, char *base, char datatype);
int		ft_print_ptr(size_t n, char *base);

#endif
