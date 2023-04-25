/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free_str_array.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmatas-p <jmatas-p@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/25 17:21:43 by jmatas-p          #+#    #+#             */
/*   Updated: 2023/04/25 17:22:59 by jmatas-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_free_str_array(char **array)
{
	char	**aux;

	if (array == NULL)
		return ;
	aux = array;
	while (*aux)
	{
		free(*aux);
		aux++;
	}
	free(aux);
}
