/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brguicho <brguicho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/22 09:47:42 by brguicho          #+#    #+#             */
/*   Updated: 2023/07/23 22:41:52 by kiroussa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "skyscraper.h"

int	main(int argc, char **argv)
{
	int	**board;
	int	**inputs;
	int	size;
	int	i;

	size = ft_parser(argc, argv, &inputs);
	if (size == -1)
		return (0);
	board = malloc(size * sizeof(int *));
	i = -1;
	while (++i < size)
		board[i] = malloc(size * sizeof(int));
	printf("???\n");
	char **bordel = malloc(2 * sizeof(char *));
	bordel[0] = "./a.out";
	bordel[1] = "1 2 3 4 2 3 4 1 3 4 1 2 4 1 2 3";
	ft_parser(2, bordel, &board);
	ft_print_board(board, size);
	printf("%d\n", ft_check_views_colup(board, inputs, size));
	printf("%d\n", ft_check_views_coldown(board, inputs, size));
	/*
	if (ft_solve(board, inputs, size))
		ft_print_board(board, size);
	else
		ft_error("Solution not found :(");
	ft_free_skyscraper(board, inputs, size);
	*/
	return (0);
}
