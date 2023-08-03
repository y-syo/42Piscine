/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   board_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmoussou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/01 17:47:17 by mmoussou          #+#    #+#             */
/*   Updated: 2023/08/01 20:08:01 by kiroussa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bsq.h"

void	ft_board_init(t_board *board)
{
	board->contents = NULL;
	board->data = malloc(sizeof(t_board_data));
}

char	ft_board_get(t_board *board, int x, int y)
{
	return (board->contents[y * board->data->width + x]);
}

void	ft_board_display(t_board *board)
{
	int	i;

	i = 0;
	while ((uint64_t)i < (board->data->width * board->data->height))
	{
		if (i % board->data->width == 0 && i != 0)
			write(1, "\n", 1);
		write(1, &board->contents[i], 1);
		i++;
	}
	write(1, "\n", 1);
}

void	ft_board_free(t_board *board)
{
	if (board->contents)
		free(board->contents);
	if (board->data)
		free(board->data);
}
