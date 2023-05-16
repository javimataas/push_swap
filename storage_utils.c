/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   storage_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmatas-p <jmatas-p@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/03 16:39:16 by jmatas-p          #+#    #+#             */
/*   Updated: 2023/05/11 18:18:55 by jmatas-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_free_stack(t_stack **stack)
{
	t_stack	*tmp;

	if (!stack && !(*stack))
		return ;
	while (*stack)
	{
		tmp = (*stack)->next;
		free(*stack);
		*stack = tmp;
	}
	*stack = NULL;
}

t_stack	*ft_fill_stack(char **argv, int parsed)
{
	t_stack		*stack;
	long int	num;
	int			i;
	int			len;

	len = ft_count_strings(argv);
	stack = NULL;
	num = 0;
	i = parsed;
	while (i < len)
	{
		num = ft_atoi(argv[i]);
		ft_add_stack(&stack, ft_new_value((int)num));
		i++;
	}
	return (stack);
}

void	ft_set_idx(t_stack *stack, int size)
{
	t_stack	*current;
	t_stack	*highest;

	while (size > 0)
	{
		current = stack;
		highest = NULL;
		while (current)
		{
			if (current->value != INT_MIN && current->index == 0)
				if (!highest || current->value > highest->value)
					highest = current;
			current = current->next;
		}
		if (highest)
			highest->index = size;
		size--;
	}
}
