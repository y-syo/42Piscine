/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   verify.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmoussou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/02 10:04:11 by mmoussou          #+#    #+#             */
/*   Updated: 2023/08/02 11:17:01 by mmoussou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bsq.h"

t_error	ft_board_check_lines(t_board *board, char *file_contents)
{
	int	i;
	int	c;

	i = 0;
	while (i++ != '\n')
		NULL;
	c = 0;
	while (file_contents[i])
	{
		if (file_contents[i] == '\n')
			c++;
		i++;
	}
	if (c != board->data->height)
		return (ERR);
	return (OK);
}

t_error	is_charset(t_board *board, int i)
{
	if (board->contents[i] != board->data->empty
		&& board->contents[i] != board->data->filled
		&& board->contents[i] != board->data->occupied)
		return (ERR);
	return (OK);
}

t_error	ft_board_check(t_board *board, char *file_contents)
{
	int	i;

	if (!ft_board_check_lines(board, file_contents))
		return (ERR);
	if (ft_strlen(board->contents) / board->data->height != board->data->width)
		return (ERR);
	i = -1;
	if (!(board->data->empty != board->data->filled
			&& board->data->filled != board->data->occupied
			&& board->data->occupied != board->data->empty))
		return (ERR);
	while (board->contents[++i])
		if (is_charset(board, i))
			return (ERR);
	return (OK);
}
