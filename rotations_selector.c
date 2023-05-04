/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotations_selector.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmatas-p <jmatas-p@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/27 17:32:55 by jmatas-p          #+#    #+#             */
/*   Updated: 2023/05/03 17:16:36 by jmatas-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_execute_rr(t_stack **a, t_stack **b, int *c_a, int *c_b)
{
	while (*c_a > 0 && *c_b > 0)
	{
		(*c_a)--;
		(*c_b)--;
		ft_rr(a, b, 'x');
	}
}

void	ft_execute_rrr(t_stack **a, t_stack **b, int *c_a, int *c_b)
{
	while (*c_a < 0 && *c_b < 0)
	{
		(*c_a)++;
		(*c_b)++;
		ft_rrr(a, b, 'x');
	}
}

void	ft_execute_rr_or_rrr(char c_stack, t_stack **stack, int *cost)
{
	while (*cost)
	{
		if (*cost > 0)
		{
			ft_rx(stack, c_stack);
			(*cost)--;
		}
		else if (*cost < 0)
		{
			ft_rrx(stack, c_stack);
			(*cost)++;
		}
	}
}

void	ft_execute_rotation(t_stack **a, t_stack **b, int c_a, int c_b)
{
	if (c_a < 0 && c_b < 0)
		ft_execute_rrr(a, b, &c_a, &c_b);
	if (c_a > 0 && c_b > 0)
		ft_execute_rr(a, b, &c_a, &c_b);
	ft_execute_rr_or_rrr('a', a, &c_a);
	ft_execute_rr_or_rrr('b', b, &c_b);
	ft_px(b, a, 'a');
}
