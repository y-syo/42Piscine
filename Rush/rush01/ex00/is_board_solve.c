/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_board_solve.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brguicho <brguicho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/23 11:47:04 by brguicho          #+#    #+#             */
/*   Updated: 2023/07/23 19:40:14 by kiroussa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "skyscraper.h"

int	ft_check_board_line(int **board, int **inputs, int size)
{
	int i;
	int	j;
	int index;
	int	index2;

	i = 0;
	j = 0;
	index = 0;
	while (board[i][j] && i < size)
	{
		index2 = 0;
		while (board[index][index2])
		{
			if (board[i][j] == board[index][index2 + 1])
				return (0);
			if (j == size)
			{
				j = 0;
				index++;
				i++;
			}
			index2++;
		}
		j++;
	}
	return (1);
}

int	ft_check_board_column(int **board, int **inputs, int size)
{
	int i;
	int	j;
	int index;
	int	index2;

	i = 0;
	j = 0;
	index2 = 0;
	while (board[i][j] && i < size)
	{
		index = 0;
		while (board[index][index2])
		{
			if (board[i][j] == board[index + 1][index2])
				return (0);
			if (i == size)
			{
				i = 0;
				index2++;
				j++;
			}
			index++;
		}
		i++;
	}
	return (1);	
}

int	ft_is_board_is_solved(int **board, int **inputs, int size)
{
	if (ft_check_board_line == 1 && ft_check_board_line == 1)
		return (1);
	return (0);
}

