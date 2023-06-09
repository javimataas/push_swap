/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swappers.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmatas-p <jmatas-p@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/25 18:35:16 by jmatas-p          #+#    #+#             */
/*   Updated: 2023/05/03 17:09:05 by jmatas-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_sx(t_stack *stack, char x)
{
	if (stack == NULL || stack->next == NULL)
		return ;
	ft_swap(&stack->value, &stack->next->value);
	ft_swap(&stack->index, &stack->next->index);
	if (x == 'a')
		ft_putstr("sa\n");
	if (x == 'b')
		ft_putstr("sb\n");
}

void	ft_ss(t_stack **stack_a, t_stack **stack_b, char should_write)
{
	ft_sx(*stack_a, ' ');
	ft_sx(*stack_b, ' ');
	if (should_write != ' ')
		ft_putstr("ss\n");
}
