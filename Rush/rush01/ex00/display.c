/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brguicho <brguicho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/22 18:08:24 by kiroussa          #+#    #+#             */
/*   Updated: 2023/07/23 15:40:12 by brguicho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "skyscraper.h"

void	ft_print_board(int **board, int size)
{
	int	i;
	int	j;

	i = -1;
	while (++i < size)
	{
		j = -1;
		while (++j < size)
		{
			ft_putchar(board[i][j] + '0');
			if (j != size - 1)
				ft_putchar(' ');
		}
		ft_putchar('\n');
	}
}
