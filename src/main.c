/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmoura-p <cmoura-p@students.42porto.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/09 17:40:29 by cmoura-p          #+#    #+#             */
/*   Updated: 2024/09/12 19:35:47 by cmoura-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static bool	check_input(int ac, char **av);

int	main(int argc, char **argv)
{
	t_node	*stack_a;

	stack_a = NULL;
	if (argc == 1)
		return (0);
	if (argc == 2)
		argv = ft_split(argv[1], ' ');
	else
		argv = argv + 1;
	if (!argv[0])
	{
		write(2, "Error\n", 6);
		if (argc == 2)
			free_argv(argv);
		return (0);
	}
	if (!check_input(argc, argv))
		return (0);
	stack_init(&stack_a, argv);
	push_swap(&stack_a);
	if (argc == 2)
		free_argv(argv);
	stack_freed(&stack_a);
	return (0);
}

static bool	check_input(int ac, char **av)
{
	long	nbr;
	int		i;

	nbr = 0;
	i = 0;
	while (av[i])
	{
		if (syntax_error(av[i]))
		{
			if (ac == 2)
				free_argv(av);
			write(2, "Error\n", 6);
			return (false);
		}
		nbr = ft_atol(av[i]);
		if ((nbr > INT_MAX || nbr < INT_MIN)
			|| (dupli_error(av, nbr, i)))
		{
			if (ac == 2)
				free_argv(av);
			write(2, "Error\n", 6);
			return (false);
		}
		i++;
	}
	return (true);
}
