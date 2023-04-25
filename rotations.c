/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotations.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmatas-p <jmatas-p@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/25 17:45:14 by jmatas-p          #+#    #+#             */
/*   Updated: 2023/04/25 18:24:01 by jmatas-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_rx(char x, t_stack **stack)
{
	t_stack	*aux;
	t_stack	*last;

	aux = *stack;
	*stack = (*stack)->next;
	last = ft_last_value(*stack);
	aux->next = NULL;
	last->next = aux;
	if (x == 'a')
		ft_putstr("ra\n");
	if (x == 'b')
		ft_putstr("rb\n");
}

void	ft_rr(char should_write, t_stack **stack_a, t_stack **stack_b)
{
	ft_rx(' ', stack_a);
	ft_rx(' ', stack_b);
	if (mute != ' ')
		ft_putstr("rr\n");
}

void	ft_rrx(char x, t_stack **stack)
{
	t_stack *aux;
	t_stack *last;
	t_stack *before_last;

	last = ft_get_last(*stack);
	before_last = ft_get_before_last(*stack);
	before_last->next = NULL;
	aux = *stack;
	*stack = last;
	(*stack)->next = aux;
	if (x == 'a')
		ft_putstr("rra\n");
	if (x == 'b')
		ft_putstr("rrb\n");
}

void	ft_rrr(char should_write, t_stack **stack_a, t_stack **stack_b)
{
	ft_rrx(' ', stack_a);
	ft_rrx(' ', stack_b);
	if (should_write != ' ')
		ft_putstr("rrr\n");
}

void	ft_push_dx(char dx, t_stack **src, t_stack **dest)
{
	t_stack	*aux;

	if (*src == NULL)
		return ;
	aux = (*src)->next;
	(*src)-next = *dest;
	*dest = *src;
	*src = aux;
	if (dx == 'a')
		ft_putstr("pa\n");
	if (dx == 'b')
		ft_putstr("pb\n");
}
