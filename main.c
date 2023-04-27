/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmatas-p <jmatas-p@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/19 16:34:48 by jmatas-p          #+#    #+#             */
/*   Updated: 2023/04/27 16:48:27 by jmatas-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

//void	ft_push_swap(char **argv, int is_formatted);

int	main(int argc, char **argv)
{
	char	**formatted;
	int		is_formatted;

	is_formatted = 1;
	formatted = NULL;
	if (argc < 2)
		return (0);
	if (argc == 2)
	{
		formatted = ft_format(argv);
		is_formatted = 0;
	}
	else
		formatted = argv;
	if (!ft_argv_check(formatted, is_formatted))
	{
		if (is_formatted == 0)
			ft_free_str_array(formatted);
		ft_printf("Exception: list of numbers received in a wrong format\n");
		return (0);
	}
	ft_push_swap(formatted, is_formatted);
	return (0);
}
