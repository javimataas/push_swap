/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   costs.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmatas-p <jmatas-p@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/27 17:18:15 by jmatas-p          #+#    #+#             */
/*   Updated: 2023/05/03 17:08:15 by jmatas-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_set_cost(t_stack **stack_a, t_stack **stack_b)
{
	t_stack	*aux_a;
	t_stack	*aux_b;
	int		size_a;
	int		size_b;

	aux_a = *stack_a;
	aux_b = *stack_b;
	size_a = ft_stack_size(aux_a);
	size_b = ft_stack_size(aux_b);
	while (aux_b)
	{
		aux_b->cost_b = aux_b->pos;
		if (aux_b->pos > size_b / 2)
			aux_b->cost_b = (size_b - aux_b->pos) * -1;
		aux_b->cost_a = aux_b->target_pos;
		if (aux_b->target_pos > size_a / 2)
			aux_b->cost_a = (size_a - aux_b->target_pos) * -1;
		aux_b = aux_b->next;
	}
}

void	ft_set_cheapest(t_stack **stack_a, t_stack **stack_b)
{
	t_stack	*aux;
	int		cheapest;
	int		cost_a;
	int		cost_b;

	aux = *stack_b;
	cheapest = INT_MAX;
	while (aux)
	{
		if (ft_abs(aux->cost_a) + ft_abs(aux->cost_b) < cheapest)
		{
			cheapest = ft_abs(aux->cost_a) + ft_abs(aux->cost_b);
			cost_a = aux->cost_a;
			cost_b = aux->cost_b;
		}
		aux = aux->next;
	}
	ft_execute_rotation(stack_a, stack_b, cost_a, cost_b);
}
