/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_three.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmatas-p <jmatas-p@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/25 18:24:46 by jmatas-p          #+#    #+#             */
/*   Updated: 2023/05/03 16:24:11 by jmatas-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_get_max_idx(t_stack *stack)
{
	int	max;

	max = stack->index;
	while (stack)
	{
		if (stack->index > max)
			max = stack->index;
		stack = stack->next;
	}
	return (max);
}

void	ft_sort_three(t_stack **stack)
{
	int	max;

	max = ft_get_max_idx(*stack);
	if ((*stack)->index == max)
		ft_rx(stack, 'a');
	else if ((*stack)->next->index == max)
		ft_rrx(stack, 'a');
	if ((*stack)->index > (*stack)->next->index)
		ft_sx(*stack, 'a');
}
