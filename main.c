/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmatas-p <jmatas-p@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/19 16:34:48 by jmatas-p          #+#    #+#             */
/*   Updated: 2023/05/04 19:58:05 by jmatas-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_leaks(void)
{
	system("leaks -q push_swap");
}

void	ft_push_swap(char **argv, int is_parsed)
{
	t_stack	*stack_a;
	t_stack *stack_b;
	int		size;
	
	stack_b = NULL;
	stack_a = ft_fill_stack(argv, is_parsed);
	if (is_parsed == 0)
		ft_free_str_array(argv);
	size = ft_stack_size(stack_a);
	ft_set_idx(stack_a, size + 1);
	if (!ft_is_sorted(stack_a))
	{
		ft_sort(&stack_a, &stack_b, size);
	}
	ft_free_stack(&stack_a);
	ft_free_stack(&stack_b);
}

int	main(int argc, char **argv)
{
	//atexit(ft_leaks);
	char	**formatted;
	int		is_formatted;

	is_formatted = 1;
	formatted = NULL;
	if (argc < 2)
		return (0);
	if (argc == 2)
	{
		formatted = ft_format(argv);
		is_formatted = 0;
	}
	else
		formatted = argv;
	if (!ft_argv_check(formatted, is_formatted))
	{
		ft_printf("Exception: list of numbers received in a wrong format\n");
		if (is_formatted == 0)
			ft_free_str_array(formatted);
		return (0);
	}
	ft_push_swap(formatted, is_formatted);
	return (0);
}
