/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   argv_formatters.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmatas-p <jmatas-p@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/25 17:29:40 by jmatas-p          #+#    #+#             */
/*   Updated: 2023/04/25 17:34:00 by jmatas-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_count_strings(char **strs)
{
	int	i;

	i = 0;
	while (strs != NULL)
	{
		strs++;
		i++;
	}
	return (i);
}

char	**ft_format(char **argv)
{
	char	**strs;

	if (!argv[1] || ft_strcmp(argv[1], "") == 0)
	{
		ft_printf("InvalidArgumentsException: list of numbers received in a wrong format\n");
		exit(1);
	}
	strs = ft_split(argv[1], ' ');
	if (!*strs)
		exit (1);
	return (strs);
}
