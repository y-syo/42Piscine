/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   optimizer.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kiroussa <oss@xtrm.me>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/22 19:14:52 by kiroussa          #+#    #+#             */
/*   Updated: 2023/07/23 11:28:16 by kiroussa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "skyscraper.h"

void	ft_optimize_line(int *line, int size, int bounds[2])
{
	ft_optimize_bounds(line, size, bounds);
	ft_optimize_completion(line, size, bounds);
	ft_optimize_max_two(line, size, bounds);
}

void	ft_optimize_lines(int **board, int **inputs, int size, int *col_buffer)
{
	int	i;
	int	bounds[2];
	int	j;

	i = -1;
	while (++i < size)
	{
		bounds[0] = inputs[2][i];
		bounds[1] = inputs[3][i];
		ft_optimize_bounds(board[i], size, bounds);
	}
	i = -1;
	while (++i < size)
	{
		j = -1;
		while (++j < size)
			col_buffer[j] = board[j][i];
		bounds[0] = inputs[0][i];
		bounds[1] = inputs[1][i];
		ft_optimize_line(col_buffer, size, bounds);
		j = -1;
		while (++j < size)
			board[j][i] = col_buffer[j];
	}
	free(col_buffer);
}

//TODO(kiroussa): add 2x2 intersection
//TODO(kiroussa): add n-1 occur on board
void	ft_optimize(int **board, int **inputs, int size)
{
	ft_optimize_lines(board, inputs, size, malloc(sizeof(int) * size));
}
