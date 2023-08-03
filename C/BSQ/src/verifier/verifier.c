/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   verifier.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kiroussa <oss@xtrm.me>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/01 13:12:07 by kiroussa          #+#    #+#             */
/*   Updated: 2023/08/01 19:19:05 by kiroussa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bsq.h"

t_error	ft_check_meta(t_board_data *data)
{
	if (data->width < 1 || data->height < 1)
		return (ERR);
	if (data->empty == data->filled || data->empty == data->occupied)
		return (ERR);
	if (data->filled == data->empty || data->filled == data->occupied)
		return (ERR);
	if (data->occupied == data->empty || data->occupied == data->filled)
		return (ERR);
	if (data->occupied == '\n' || data->empty == '\n' || data->filled == '\n')
		return (ERR);
	return (OK);
}

t_error	ft_board_verify(t_board *board)
{
	if (!ft_check_meta(board->data))
		return (ERR);
	return (OK);
}
