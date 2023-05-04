/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmatas-p <jmatas-p@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/04 20:26:17 by jmatas-p          #+#    #+#             */
/*   Updated: 2023/05/04 20:51:18 by jmatas-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_rot_error(t_stack **stack_a, t_stack **stack_b)
{
	ft_printf("Exception: NaR\n");
	ft_free_stack(stack_a);
	ft_free_stack(stack_b);
	exit(1);
}

void	ft_do_op(char *op, t_stack **stack_a, t_stack **stack_b)
{
	if (ft_strcmp(op, "sa\n") == 0)
		ft_sx(*stack_a, ' ');
	else if (ft_strcmp(op, "sb\n") == 0)
		ft_sx(*stack_b, ' ');
	else if (ft_strcmp(op, "ss\n") == 0)
		ft_ss(stack_a, stack_b, ' ');
	else if (ft_strcmp(op, "ra\n") == 0)
		ft_rx(stack_a, ' ');
	else if (ft_strcmp(op, "rb\n") == 0)
		ft_rx(stack_b, ' ');
	else if (ft_strcmp(op, "rr\n") == 0)
		ft_rr(stack_a, stack_b, ' ');
	else if (ft_strcmp(op, "pa\n") == 0)
		ft_px(stack_b, stack_a, ' ');
	else if (ft_strcmp(op, "pb\n") == 0)
		ft_px(stack_a, stack_b, ' ');
	else if (ft_strcmp(op, "rra\n") == 0)
		ft_rrx(stack_a, ' ');
	else if (ft_strcmp(op, "rrb\n") == 0)
		ft_rrx(stack_b, ' ');
	else if (ft_strcmp(op, "rrr\n") == 0)
		ft_rrr(stack_a, stack_b, ' ');
	else
		ft_rot_error(stack_a, stack_b);
}

int	ft_checker(char **argv, int is_formatted)
{
	t_stack	*stack_a;
	t_stack	*stack_b;
	char	*op;

	stack_b = NULL;
	stack_a = ft_fill_stack(argv, is_formatted);
	op = get_next_line(0);
	while (op)
	{
		ft_do_op(op, &stack_a, &stack_b);
		free(op);
		op = get_next_line(0);
	}
	if (ft_is_sorted(stack_a))
		ft_printf("OK\n");
	else
		ft_printf("KO\n");
	ft_free_stack(&stack_a);
	ft_free_stack(&stack_b);
	return (0);
}

int	main(int argc, char **argv)
{
	char	**formatted;
	int		is_formatted;

	is_formatted = 1;
	formatted = NULL;
	if (argc == 2)
	{
		formatted = ft_format(argv);
		is_formatted = 0;
	}
	else
		formatted = argv;
	if (argc < 2)
		return (0);
	if (!ft_argv_check(formatted, is_formatted))
	{
		ft_printf("Error, nonvalid argument\n");
		return (0);
	}
	ft_checker(formatted, is_formatted);
	return (0);
}
