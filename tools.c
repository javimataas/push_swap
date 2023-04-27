/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmatas-p <jmatas-p@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/25 19:03:19 by jmatas-p          #+#    #+#             */
/*   Updated: 2023/04/27 16:58:35 by jmatas-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_stack_size(t_stack *stack)
{
	int	i;

	i = 0;
	if (stack)
	{
		while (stack)
		{
			stack = stack->next;
			i++;
		}
	}
	return (i);
}

t_stack	*ft_last_value(t_stack *stack)
{
	while (stack && stack->next != NULL)
		stack = stack->next;
	return (stack);
}

t_stack	*ft_before_last_value(t_stack *stack)
{
	while (stack && stack->next && stack->next->next != NULL)
		stack = stack->next;
	return (stack);
}

void	ft_add_stack(t_stack **stack, t_stack *new)
{
	t_stack	*end;

	if (!new)
		return ;
	if (!*stack)
	{
		*stack = new;
		return ;
	}
	end = ft_last_value(*stack);
	end->next = new;
}

t_stack	*ft_new_value(int value)
{
	t_stack	*new;

	new = malloc(sizeof * new);
	if (!new)
		return (NULL);
	new->value = value;
	new->index = 0;
	new->pos = -1;
	new->target_pos = -1;
	new->cost_a = -1;
	new->cost_b = -1;
	new->next = NULL;
	return (new);
}
