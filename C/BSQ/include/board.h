/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   board.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kiroussa <oss@xtrm.me>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/01 13:12:48 by kiroussa          #+#    #+#             */
/*   Updated: 2023/08/01 19:51:54 by kiroussa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BOARD_H
# define BOARD_H

# include "error.h"
# include <stdint.h>

typedef struct s_board_data
{
	uint64_t		width;
	uint64_t		height;
	char			empty;
	char			filled;
	char			occupied;
}	t_board_data;

typedef struct s_board
{
	t_board_data	*data;
	char			*contents;
}	t_board;

void	ft_board_init(t_board *board);
char	ft_board_get(t_board *board, int x, int y);
t_error	ft_board_parse(t_board *board, char *file_contents);
t_error	ft_board_verify(t_board *board);
void	ft_board_display(t_board *board);
void	ft_board_free(t_board *board);

#endif 
