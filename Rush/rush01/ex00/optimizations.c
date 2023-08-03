/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   optimizations.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kiroussa <oss@xtrm.me>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/23 11:13:30 by kiroussa          #+#    #+#             */
/*   Updated: 2023/07/23 18:01:09 by kiroussa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "skyscraper.h"

void	ft_optimize_bounds(int *line, int size, int bounds[2])
{
	int	i;

	if (bounds[0] == 1)
		line[0] = size;
	if (bounds[1] == 1)
		line[size - 1] = size;
	i = 0;
	if (bounds[0] == size)
		while (i++ < size)
			line[i - 1] = i;
	i = 0;
	if (bounds[1] == size)
		while (i++ < size)
			line[size - i] = i;
}

void	ft_optimize_completion(int *line, int size, int bounds[2])
{
	int	i;
	int	last_index;
	int	remaining;

	(void) bounds;
	i = -1;
	last_index = -1;
	remaining = 0;
	while (++i < size)
	{
		remaining += size - i;
		if (line[i] == 0 && last_index != -1)
			return ;
		if (line[i] == 0)
			last_index = i;
		else
			remaining -= line[i];
	}
	if (last_index != -1 && remaining > 0)
		line[last_index] = remaining;
}

void	ft_optimize_max_two(int *line, int size, int bounds[2])
{
	if (bounds[0] == 1 && bounds[1] == 2)
		line[size - 1] = size - 1;
	if (bounds[0] == 2 && bounds[1] == 1)
		line[0] = size - 1;
}
