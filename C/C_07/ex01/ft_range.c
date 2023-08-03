/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_range.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmoussou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/24 10:40:37 by mmoussou          #+#    #+#             */
/*   Updated: 2023/07/27 10:45:15 by mmoussou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	*ft_range(int min, int max)
{
	int	*arr;
	int	i;

	i = 0;
	if (max <= min)
	{
		return (NULL);
	}
	arr = malloc(sizeof(int) * (max - min));
	if (arr == NULL)
		return (NULL);
	while (min + i < max)
	{
		arr[i] = min + i;
		i++;
	}
	return (arr);
}
