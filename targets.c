/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   targets.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmatas-p <jmatas-p@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/27 17:51:59 by jmatas-p          #+#    #+#             */
/*   Updated: 2023/04/27 19:01:35 by jmatas-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_set_pos(t_stack **stack)
{
	t_stack	*aux;
	int		i;

	aux = *stack;
	i = 0;
	while (aux)
	{
		aux->pos = i;
		aux = aux->next;
		i++;
	}
}

int	ft_get_lowest_idx_pos(t_stack **stack)
{
	t_stack	*aux;
	int		lowest_idx;
	int		lowest_pos;

	aux = *stack;
	lowest_idx = INT_MAX;
	ft_set_pos(stack);
	lowest_pos = aux->pos;
	while (aux)
	{
		if (aux->index < lowest_idx)
		{
			lowest_idx = aux->index;
			lowest_pos = aux->pos;
		}
		aux = aux->next;
	}
	return (lowest_pos);
}

int	ft_get_target(t_stack **a, int b_idx, int t_idx, int t_pos)
{
	t_stack	*aux;

	aux = *a;
	while (aux)
	{
		if (aux->index > b_idx && aux->index < t_idx)
		{
			t_idx = aux->index;
			t_pos = aux->pos;
		}
		aux = aux->next;
	}
	if (t_idx != INT_MAX)
		return (t_pos);
	aux = *a;
	while (aux)
	{
		if (aux->index < t_idx)
		{
			t_idx = aux->index;
			t_pos = aux->pos;
		}
		aux = aux->next;
	}
	return (t_pos);
}

void	ft_set_target_pos(t_stack **stack_a, t_stack **stack_b)
{
	t_stack	*aux_b;
	int		target_pos;

	aux_b = *stack_b;
	ft_set_pos(stack_a);
	ft_set_pos(stack_b);
	target_pos = 0;
	while (aux_b)
	{
		target_pos = ft_get_target(stack_a, aux_b->index, INT_MAX, target_pos);
		aux_b->target_pos = target_pos;
		aux_b = aux_b->next;
	}
}
