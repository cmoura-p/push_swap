/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmoura-p <cmoura-p@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/09 17:40:29 by cmoura-p          #+#    #+#             */
/*   Updated: 2024/09/13 23:09:58 by cmoura-p         ###   ########.fr       */
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
		free_argv(argv, argc);
		return (0);
	}
	if (!check_input(argc, argv))
		return (0);
	stack_init(&stack_a, argv);
	push_swap(&stack_a);
	free_argv(argv, argc);
	stack_freed(&stack_a);
	return (0);
}

static bool	check_input(int ac, char **av)
{
	int		i;

	i = 0;
	while (av[i])
	{
		if (syntax_error(av[i]))
		{
			free_argv(av, ac);
			write(2, "Error\n", 6);
			return (false);
		}
		if (((ft_atol(av[i])) > INT_MAX || (ft_atol(av[i])) < INT_MIN)
			|| (dupli_error(av, ft_atol(av[i]), i)))
		{
			free_argv(av, ac);
			write(2, "Error\n", 6);
			return (false);
		}
		i++;
	}
	return (true);
}
