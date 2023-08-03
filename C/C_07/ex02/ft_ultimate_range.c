/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ultimate_range.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmoussou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/24 13:05:10 by mmoussou          #+#    #+#             */
/*   Updated: 2023/08/02 11:46:59 by mmoussou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	ft_ultimate_range(int **range, int min, int max)
{
	int	i;
	int	*arr;

	if (min >= max)
	{
		*range = 0;
		return (0);
	}
	arr = malloc(sizeof(int) * (max - min));
	if (arr == NULL)
	{
		*range = 0;
		return (-1);
	}
	i = 0;
	while (min + i < max)
	{
		arr[i] = min + i;
		i++;
	}
	*range = arr;
	return (max - min);
}
