/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   verifier.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brguicho <brguicho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/23 11:26:26 by kiroussa          #+#    #+#             */
/*   Updated: 2023/07/23 22:41:24 by kiroussa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "skyscraper.h"

int	ft_check_views_colup(int **board, int **inputs, int size)
{
	int	index;
	int	index2;
	int	j;
	int	count;
	int	max;

	max = board[0][0];
	j = 0;
	count = 1;
	index2 = 0;
	while (inputs[0][j])
	{
		index = 0;
		while (board[index][index2])
		{
			if (board[index][index2] < board[index + 1][index2])
			{
				max = board[index + 1][index2];
				count++;
			}
			index++;
			if (count == inputs[0][j])
				return (1);
		}
		j++;
		index2++;
	}
	return (0);
}

int	ft_check_views_coldown(int **board, int **inputs, int size)
{
	int	index;
	int	index2;
	int	j;
	int	count;
	int	max;

	max = board[0][size - 1];
	j = size - 1;
	count = 1;
	index2 = size - 1;
	while (inputs[1][j])
	{
		index = size - 1;
		while (board[index][index2])
		{
			if (board[index][index2] < board[index - 1][index2])
			{
				max = board[index - 1][index2];
				count++;
			}
			index--;
			if (count == inputs[0][j])
				return (1);
		}
		j--;
		index2--;
	}
	return (0);
}
