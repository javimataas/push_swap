/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   argv_checkers.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmatas-p <jmatas-p@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/19 16:52:40 by jmatas-p          #+#    #+#             */
/*   Updated: 2023/05/04 20:10:07 by jmatas-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_same_args(char *s1, char *s2)
{
	while (*s1 == '+' || *s1 == '0')
		s1++;
	while (*s2 == '+' || *s2 == '0')
		s2++;
	return (ft_strcmp(s1, s2));
}

int	ft_is_number(char *s)
{
	int	i;

	i = 0;
	if (s[i] && (s[i] == '+' || s[i] == '-'))
		i++;
	while (s[i])
	{
		if (!ft_isdigit(s[i]))
			return (0);
		i++;
	}
	return (1);
}

int	ft_args_dup(char **argv, int is_formatted)
{
	int	i;
	int	j;
	int	zeros;

	zeros = 0;
	i = is_formatted;
	while (argv[i])
	{
		j = is_formatted;
		if (ft_atol(argv[i]) == 0)
			zeros++;
		while (argv[j])
		{
			if ((j != i && !ft_same_args(argv[i], argv[j])) || zeros > 1)
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}

int	ft_argv_check(char **argv, int is_formatted)
{
	int			i;
	long int	num;

	i = is_formatted;
	while (argv[i])
	{
		if (ft_strcmp(argv[i], "") == 0)
			return (0);
		if (!ft_is_number(argv[i]))
			return (0);
		num = ft_atol(argv[i]);
		if (num > INT_MAX || num < INT_MIN)
			return (0);
		i++;
	}
	if (ft_args_dup(argv, is_formatted))
		return (0);
	return (1);
}
