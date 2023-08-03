/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kiroussa <oss@xtrm.me>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/01 12:54:31 by kiroussa          #+#    #+#             */
/*   Updated: 2023/08/02 15:48:51 by kiroussa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bsq.h"

t_error	ft_bsq(int fd)
{
	t_board	board;
	char	*contents;
	size_t	size;

	contents = NULL;
	size = 0;
	if (!ft_read_file(fd, &contents, &size))
		return (ERR);
	ft_board_init(&board);
	if (!ft_board_parse(&board, contents))
	{
		free(contents);
		ft_board_free(&board);
		return (ERR);
	}
	free(contents);
	ft_board_display(&board);
	ft_board_free(&board);
	return (OK);
}

t_error	ft_bsq_file(char *file_name)
{
	int		fd;
	t_error	ret;

	fd = open(file_name, O_RDONLY);
	if (fd < 0)
		return (ERR);
	ret = ft_bsq(fd);
	close(fd);
	return (ret);
}

int	main(int argc, char *argv[])
{
	int	i;

	i = 0;
	if (argc == 1)
		if (!ft_bsq(0))
			ft_putstr_fd(2, MAP_ERROR);
	if (argc != 1)
	{
		while (++i < argc)
		{
			if (i != 1)
				ft_putstr("\n");
			if (!ft_bsq_file(argv[i]))
				ft_putstr_fd(2, MAP_ERROR);
		}
	}
	return (0);
}
