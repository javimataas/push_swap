/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sortings.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmatas-p <jmatas-p@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/03 16:16:00 by jmatas-p          #+#    #+#             */
/*   Updated: 2023/05/09 16:30:52 by jmatas-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_push_all_minus_three(t_stack **stack_a, t_stack **stack_b)
{
	int	s_size;
	int	pushed_count;
	int	i;

	s_size = ft_stack_size(*stack_a);
	pushed_count = 0;
	i = 0;
	while (pushed_count < (s_size / 2) && (s_size / 2) > 3 && i < s_size)
	{
		if ((*stack_a)->index <= s_size / 2)
		{
			ft_px(stack_a, stack_b, 'b');
			pushed_count++;
		}
		else
			ft_rx(stack_a, 'a');
		i++;
	}
	while (s_size - pushed_count > 3)
	{
		ft_px(stack_a, stack_b, 'b');
		pushed_count++;
	}
}

void	ft_rev_stack(t_stack **stack_a)
{
	int	lowest_pos;
	int	s_size;

	s_size = ft_stack_size(*stack_a);
	lowest_pos = ft_get_lowest_idx_pos(stack_a);
	if (lowest_pos > s_size / 2)
	{
		while (lowest_pos < s_size)
		{
			ft_rrx(stack_a, 'a');
			lowest_pos++;
		}
	}
	else
	{
		while (lowest_pos > 0)
		{
			ft_rx(stack_a, 'a');
			lowest_pos--;
		}
	}
}

int	ft_is_sorted(t_stack *stack)
{
	while (stack->next != NULL)
	{
		if (stack->value > stack->next->value)
			return (0);
		stack = stack->next;
	}
	return (1);
}

void	ft_sort_left(t_stack **stack_a, t_stack **stack_b)
{
	ft_push_all_minus_three(stack_a, stack_b);
	ft_sort_three(stack_a);
	while (*stack_b)
	{
		ft_set_target_pos(stack_a, stack_b);
		ft_set_cost(stack_a, stack_b);
		ft_set_cheapest(stack_a, stack_b);
	}
	if (!ft_is_sorted(*stack_a))
		ft_rev_stack(stack_a);
}

void	ft_sort(t_stack **stack_a, t_stack **stack_b, int s_size)
{
	if (s_size == 2)
		ft_sx(*stack_a, 'a');
	else if (s_size == 3)
		ft_sort_three(stack_a);
	else if (s_size > 3)
		ft_sort_left(stack_a, stack_b);
}
