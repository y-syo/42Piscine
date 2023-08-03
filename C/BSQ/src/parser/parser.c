/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmoussou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/01 13:10:23 by mmoussou          #+#    #+#             */
/*   Updated: 2023/08/02 15:58:35 by kiroussa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bsq.h"

char	*ft_first_line_data(char *file_contents)
{
	int		i;
	char	*nb_str;

	i = 0;
	while (file_contents[i] && ft_isdigit(file_contents[i]))
		i++;
	if (i == 0)
		return (NULL);
	nb_str = ft_strdup_range(file_contents, 0, i);
	return (nb_str);
}

t_error	ft_update_contents(t_board *board, char *file, int offset, int nline)
{
	return (OK);
}

t_error	ft_board_parse(t_board *board, char *file_contents)
{
	int		i;
	int		j;
	char	*data_line;
	int		err;

	data_line = ft_first_line_data(file_contents);
	err = ft_ratoi_ull(data_line, &board->data->height);
	free(data_line);
	if (err > 0)
		return (ERR);
	i = 0;
	while (file_contents[i] != '\n')
		i++;
	board->data->occupied = file_contents[i - 1];
	board->data->filled = file_contents[i - 2];
	board->data->empty = file_contents[i++ - 3];
	j = i;
	while (file_contents[j] != '\n')
		j++;
	board->data->width = j - i;
	if (!ft_update_contents(board, file_contents, i + 2))
		return (ERR);
	return (OK);
}
